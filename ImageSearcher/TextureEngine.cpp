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
		cout << "Error: Database could not be opened. Wait, creating database..." << endl;
		return createDatabase(directory);
	}

	return true;
}

texture_distance* TextureEngine::searchImage(string imgPath, int quantity)
{
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
		cout << "Error: Database could not be opened." << endl;
		return result;
	}

	//Initializing variables
	result = (texture_distance*)malloc(sizeof(texture_distance) * quantity);
	for (size_t i = 0; i < quantity; i++)
	{
		// NEEDS CORRECTION
		result[i].distance = 1 * 256 * 4 * 3;
	}

	// Generate Euclidean distance for all images within the database.
	while (!database.eof())
	{
		database.read((char *)&imageFromDatabase, sizeof(texture_data_structure));
		/*float H_distance = 0;
		float S_distance = 0;
		float V_distance = 0;*/

		for (size_t i = 0; i < 4; i++)
		{
			// Calculating the Euclidean distances.
			for (size_t j = 0; j < 256; j++)
			{
				/*H_distance += euclideanDistance(imageData.H[i][j], imageFromDatabase.H[i][j]);
				S_distance += euclideanDistance(imageData.S[i][j], imageFromDatabase.S[i][j]);
				V_distance += euclideanDistance(imageData.V[i][j], imageFromDatabase.V[i][j]);*/
			}
		}

		// Sorting ont he fly
		texture_distance aux;
		/*aux.distance = H_distance + S_distance + V_distance;*/
		aux.image = imageFromDatabase;

		for (size_t i = 0; i < quantity; i++)
		{
			if (aux.distance < result[i].distance)
			{
				for (size_t j = (quantity - 1); j > i; j--)
				{
					result[j] = result[j - 1];
				}
				result[i] = aux;
				break;
			}
		}
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
	IplImage* img;					// original image.
	texture_data_structure data;		// struct where the information will be stored.

	//Initializing variables
	string aux = imgPath.substr(imgPath.find_last_of("\\") + 1);
	for (size_t i = 0; i < MAX_PATH; i++) data.name[i] = '\0';
	for (size_t i = 0; i < aux.length(); i++) data.name[i] = aux[i];

	// Loading image
	if ((img = cvLoadImage(imgPath.c_str(), CV_LOAD_IMAGE_UNCHANGED)) == NULL)
	{
		cout << endl << "Erro: Imagem nao pode ser carregada." << endl << endl;
		return data;
	}



	// Normalizing form data
	for (size_t i = 0; i < SECTIONS; i++)
	{
		for (size_t j = 0; j < LEVELS; j++)
		{
			/*data.H[i][j] /= data.pixelCounter[i];
			data.S[i][j] /= data.pixelCounter[i];
			data.V[i][j] /= data.pixelCounter[i];*/
		}
	}

	cvReleaseImage(&img);
	return data;
}

float TextureEngine::euclideanDistance(float value1, float value2)
{
	double value = value1 - value2;
	double distance;

	distance = pow(value, 2);           // calculating distance by euclidean formula
	distance = sqrt(distance);          // sqrt is function in math.h

	return distance;
}