#include "FormEngine.h"

FormEngine::FormEngine()
{
	databasePath = "form.db";
}

FormEngine::~FormEngine()
{
}

bool FormEngine::start(LPCWSTR directory)
{
	// Creating variables.
	ifstream database;						// input file stream.

	// Open file.
	database.open(this->databasePath, ios::in | ios::binary);

	if (!database.is_open())
	{
		cout << "Error: Form database could not be opened. Wait, creating form database..." << endl;
		return createDatabase(directory);
	}

	return true;
}

form_distance* FormEngine::searchImage(string imgPath)
{
	int index = 0;
	int quantity = 1002;

	// Creating variables.
	ifstream database;						// input file stream.
	form_data_structure imageData;			// data from requested image.
	form_data_structure imageFromDatabase;	// data from database image.
	form_distance *result = NULL;			// the vector of results.

	// Extract color information from original image.
	imageData = extractForm(imgPath);

	// Open file.
	database.open(this->databasePath, ios::in | ios::binary);

	if (!database.is_open())
	{
		cout << "Error: Form database could not be opened." << endl;
		return result;
	}

	//Initializing variables
	result = new form_distance[quantity];
	for (size_t i = 0; i < quantity; i++) { result[i].distance = LEVELS; }

	// Generate Euclidean distance for all images within the database.
	while (!database.eof())
	{
		float chain_distance[LEVELS];
		for (size_t i = 0; i < LEVELS; i++) chain_distance[i] = 0;

		database.read((char *)&imageFromDatabase, sizeof(form_data_structure));
		
		for (size_t i = 0; i < LEVELS; i++)
		{
			chain_distance[i] += euclideanDistance(imageData.chainCode[i], imageFromDatabase.chainCode[i]);
		}

		// Normalizing distances
		result[index].distance = 0;
		for (size_t i = 0; i < LEVELS; i++) result[index].distance += chain_distance[i];
		result[index].distance /= LEVELS;
		result[index].image = imageFromDatabase;
		index++;
	}

	database.close();
	return result;
}

bool FormEngine::createDatabase(LPCWSTR directory)
{
	// Creating variables.
	ofstream ofs;								// output file stream.
	WIN32_FIND_DATA file;						// The file to be verified.
	LARGE_INTEGER filesize;						// The file size.
	TCHAR szDir[MAX_PATH];						// ?
	size_t pathLength;							// The root's path length .
	HANDLE handleFind = INVALID_HANDLE_VALUE;	// The file search handle.
	DWORD dwError = 0;							// Windows error control.
	LPCWSTR nextDirectory;						// Path to next directory in recursion.
	int counter = 0;							// Counts the number of added files.

	/// Open file
	ofs.open(this->databasePath, ios::out | ios::binary | ofstream::trunc);

	// Check that the input path.
	StringCchLength(directory, MAX_PATH, &pathLength);

	if (pathLength > (MAX_PATH - 3))
	{
		cout << "Directory path is too long." << endl;
		return false;
	}

	// Prepare string for use with FindFile functions.
	StringCchCopy(szDir, MAX_PATH, directory);
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	// Find the first file in the directory.
	handleFind = FindFirstFile(szDir, &file);

	// List all the files in the directory with some info about them.
	do
	{
		// convert from wide char to narrow char array
		char ch[260];
		WideCharToMultiByte(CP_ACP, 0, file.cFileName, -1, ch, 260, NULL, NULL);
		string auxName(ch);

		if (auxName.substr(auxName.find_last_of(".") + 1) == "jpg")
		{
			counter++;

			WideCharToMultiByte(CP_ACP, 0, directory, -1, ch, 260, NULL, NULL);
			string auxDirectory(ch);

			form_data_structure aux = extractForm(string(auxDirectory + "\\" + auxName));
			ofs.write((char*)&aux, sizeof(form_data_structure));
		}

	} while (FindNextFile(handleFind, &file) != 0);

	FindClose(handleFind);

	/// close file
	ofs.close();

	cout << counter << " images found." << endl;
	cout << "Database successfully created." << endl;
	return true;
}

form_data_structure FormEngine::extractForm(string imgPath)
{
	// Creating variables.
	IplImage* img;					// original image.
	IplImage* imgBin;				// binary image.
	CvChain* chain;					// chain structure.
	CvMemStorage* storage;			// memory storage.	
	form_data_structure data;		// struct where the information will be stored.
	int elementCounter;				// counter number of elements in order to apply normalization.
	int minSize;					// minimum size to consider a object when reading the chain.
	int maxSize;					// maximum size to consider a object when reading the chain.

	//Initializing variables
	elementCounter = 0;
	minSize = 3;
	chain = NULL;
	storage = cvCreateMemStorage(0);
	for (size_t i = 0; i < LEVELS; i++)data.chainCode[i] = 0;
	string aux = imgPath.substr(imgPath.find_last_of("\\") + 1);
	for (size_t i = 0; i < MAX_PATH; i++) data.name[i] = '\0';
	for (size_t i = 0; i < aux.length(); i++) data.name[i] = aux[i];
	
	// Loading image
	if ((img = cvLoadImage(imgPath.c_str(), CV_LOAD_IMAGE_UNCHANGED)) == NULL)
	{
		cout << endl << "Erro: Imagem nao pode ser carregada." << endl << endl;
		return data;
	}

	maxSize = (img->width + img->height) * 2;

	// Turning imagem into a binary one using Otsu threshold
	imgBin = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	cvCvtColor(img, imgBin, CV_BGR2GRAY);
	cvThreshold(imgBin, imgBin, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

	// Applying morphology operations
	imgBin = morphologyOperations(imgBin);

	// Creating histogram based on chain code
	cvFindContours(imgBin, storage, (CvSeq**)(&chain), sizeof(*chain), CV_RETR_EXTERNAL, CV_CHAIN_CODE);

	for (; chain != NULL; chain = (CvChain*)chain->h_next)
	{
		CvSeqReader reader;
		cvStartReadSeq((CvSeq*)chain, &reader, 0);

		if ((chain->total > minSize) && (chain->total < maxSize))
		{
			elementCounter += chain->total;

			for (size_t k = 0; k < chain->total; k++)
			{
				char code;
				CV_READ_SEQ_ELEM(code, reader);
				data.chainCode[code]++;
			}
		}
	}

	// Normalizing form data
	if (elementCounter != 0)
	{
		for (size_t i = 0; i < 8; i++) data.chainCode[i] /= elementCounter;
	}
	else
	{
		for (size_t i = 0; i < 8; i++) data.chainCode[i] = 0;
	}
	
	cvReleaseImage(&img);
	cvReleaseImage(&imgBin);
	return data;
}

IplImage* FormEngine::morphologyOperations(IplImage* image)
{
	Mat src(image);
	Mat dst;

	int morph_size = 2;
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));

	// Apply the specified morphology operation
	morphologyEx(src, dst, MORPH_CLOSE, element);

	return cvCloneImage(&(IplImage)dst);
}
 
float FormEngine::euclideanDistance(float value1, float value2)
{
	float value = value1 - value2;
	float distance;

	distance = pow(value, 2);           // calculating distance by euclidean formula
	distance = sqrt(distance);          // sqrt is function in math.h

	return distance;
}