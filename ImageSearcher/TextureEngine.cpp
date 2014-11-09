#include "TextureEngine.h"


TextureEngine::TextureEngine()
{
	databasePath = "texture.db";
}

TextureEngine::~TextureEngine()
{
}

bool TextureEngine::start(LPCWSTR directory)
{
	// Creating variables.
	ifstream database;						// input file stream.

	// Open file.
	database.open(this->databasePath, ios::in | ios::binary);

	if (!database.is_open())
	{
		cout << "Error: Texture database could not be opened. Wait, creating texture database..." << endl;
		return createDatabase(directory);
	}

	return true;
}

texture_distance* TextureEngine::searchImage(string imgPath)
{
	int index = 0;
	int quantity = 1002;
	 
	// Creating variables.
	ifstream database;						// input file stream.
	texture_data_structure imageData;			// data from requested image.
	texture_data_structure imageFromDatabase;	// data from database image.
	texture_distance *result = NULL;			// the vector of results.

	// Extract color information from original image.
	imageData = extractTexture(imgPath);

	// Open file.
	database.open(this->databasePath, ios::in | ios::binary);

	if (!database.is_open())
	{
		cout << "Error: Texture database could not be opened." << endl;
		return result;
	}

	//Initializing variables
	result = new texture_distance[quantity];
	for (size_t i = 0; i < quantity; i++) { result[i].distance = LEVELS * SECTIONS; }

	// Generate Euclidean distance for all images within the database.
	while (!database.eof())
	{
		float distance = 0;

		database.read((char *)&imageFromDatabase, sizeof(texture_data_structure));
		
		for (size_t i = 0; i < SECTIONS; i++)
		{
			// Calculating the Euclidean distances.
			for (size_t j = 0; j < LEVELS; j++)
			{
				distance += euclideanDistance(imageData.LBP[i][j], imageFromDatabase.LBP[i][j]);
			}
		}

		// Normalizing distances
		result[index].distance = distance / SECTIONS;
		result[index].image = imageFromDatabase;
		index++;
	}

	database.close();
	return result;
}

bool TextureEngine::createDatabase(LPCWSTR directory)
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

			texture_data_structure aux = extractTexture(string(auxDirectory + "\\" + auxName));
			ofs.write((char*)&aux, sizeof(texture_data_structure));
		}

	} while (FindNextFile(handleFind, &file) != 0);

	FindClose(handleFind);

	/// close file
	ofs.close();

	cout << counter << " images found." << endl;
	cout << "Database successfully created." << endl;
	return true;
}

texture_data_structure TextureEngine::extractTexture(string imgPath)
{
	// Creating variables.
	Mat img;					        // original image.
	Mat imgLBP;                         // image containing LBP data.
	unsigned short pixel;				// Current pixel.
	texture_data_structure data;		// struct where the information will be stored.

	//Initializing variables
	string aux = imgPath.substr(imgPath.find_last_of("\\") + 1);
	
	for (size_t i = 0; i < MAX_PATH; i++) data.name[i] = '\0';
	
	for (size_t i = 0; i < aux.length(); i++) data.name[i] = aux[i];
	
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 256; j++)
		{
			data.LBP[i][j] = 0.0f;
		}
	}

	for (size_t i = 0; i < 4; i++)
	{
		data.pixelCounter[i] = 0;
	}

	// Loading image
	img = imread(imgPath, CV_LOAD_IMAGE_GRAYSCALE);
	
	if (!img.data)
	{
		cout << endl << "Erro Tx: Imagem nao pode ser carregada." << endl << endl;
		return data;
	}

	imgLBP = Mat::zeros(img.rows - 2, img.cols - 2, CV_8UC1);

	// Applying LBP algorithm into the original image.
	for (int i = 1; i<img.rows - 1; i++)
	{
		for (int j = 1; j<img.cols - 1; j++)
		{
			unsigned char center = img.at<unsigned char>(i, j);
			unsigned char code = 0;
			code |= (img.at<unsigned char>(i - 1, j - 1) > center) << 7;
			code |= (img.at<unsigned char>(i - 1, j) > center) << 6;
			code |= (img.at<unsigned char>(i - 1, j + 1) > center) << 5;
			code |= (img.at<unsigned char>(i, j + 1) > center) << 4;
			code |= (img.at<unsigned char>(i + 1, j + 1) > center) << 3;
			code |= (img.at<unsigned char>(i + 1, j) > center) << 2;
			code |= (img.at<unsigned char>(i + 1, j - 1) > center) << 1;
			code |= (img.at<unsigned char>(i, j - 1) > center) << 0;
			imgLBP.at<unsigned char>(i - 1, j - 1) = code;
		}
	}

	// Creating histogram
	int halfHeight = imgLBP.rows / 2;
	int halfWidth = imgLBP.cols / 2;
	int quadrant;

	for (int height = 0; height < imgLBP.rows; height++)
	{
		for (int width = 0; width < imgLBP.cols; width++)
		{
			pixel = imgLBP.at<unsigned char>(height, width);

			if (height < halfHeight && width < halfWidth) { quadrant = 0; }
			else if (height < halfHeight && width >= halfWidth) { quadrant = 1; }
			else if (height >= halfHeight && width < halfWidth) { quadrant = 2; }
			else if (height >= halfHeight && width >= halfWidth) { quadrant = 3; }
			else { cout << "Error: Invalide pixel coordinate." << endl; }

			data.LBP[quadrant][(int)pixel]++;
			data.pixelCounter[quadrant]++;
		}
	}

	// Normalizing HSV data
	for (size_t i = 0; i < SECTIONS; i++)
	{
		for (size_t j = 0; j < LEVELS; j++)
		{
			data.LBP[i][j] /= data.pixelCounter[i];
		}
	}

	return data;
}

float TextureEngine::euclideanDistance(float value1, float value2)
{
	float value = value1 - value2;
	float distance;

	distance = pow(value, 2);           // calculating distance by euclidean formula
	distance = sqrt(distance);          // sqrt is function in math.h

	return distance;
}