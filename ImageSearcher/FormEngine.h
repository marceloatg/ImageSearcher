#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <math.h>
#include <string>
#include <tchar.h>
#include <fstream>
#include <iostream>
#include <strsafe.h>
#include <windows.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#define CHANNELS 3
#define SECTIONS 4
#define LEVELS 8

using namespace cv;
using namespace std;

struct form_data_structure
{
	char name[MAX_PATH];
	float chainCode[LEVELS];
};

struct form_distance
{
	float distance;
	form_data_structure image;
};

/// <summary>
/// Performs a search based on form
/// </summary>
class FormEngine
{
public:
	/// Class constructor.
	FormEngine();

	/// Class destructor.
	virtual ~FormEngine();

	/// <summary> 
	/// Start  the engine checking for the database and  initializng  necessary  variables  such  as 
	/// the  form_distance. If  the  database  was  not found a  routine  will be  called  in  order
	/// to create the database. If any errors occur, the program will not be able to use the engine.
	/// </summary>
	/// <returns> Returns if started successfully or false in case of error. </returns>
	bool start(LPCWSTR directory);

	/// <summary> 
	/// Compares  a given image  agaisnt all  images within  the database. For each image  is assiged
	/// a value that represents the Euclidean distance between that particular image and the original
	/// one.
	/// </summary>
	/// <param name="imgPath"> imgPath contains the image path for the image. </param>
	/// <param name="quantity"> Integer that sets the number of most similar files to be shown. </param>
	/// <returns> Returns a struct when override containing the distance data generated. </returns>
	form_distance* searchImage(string imgPath);

private:
	/// <summary>
	/// The color database path.
	/// </summary>
	string databasePath;

	/// <summary>
	/// Create a database containg the histogram information based on the given images.
	/// </summary>
	/// <param name="directory"> directory contains the folder path of the image database. </param>
	bool createDatabase(LPCWSTR directory);

	/// <summary> Extracts form histogram from a given image. </summary>
	/// <param name="imgPath"> Contains the image path for the image. </param>
	/// <returns> Returns a data_structure containing the gathered data. </returns>
	form_data_structure extractForm(string imgPath);

	/// <summary>
	/// 
	/// </summary>
	IplImage* morphologyOperations(IplImage* image);

	/// <summary>
	/// This function calculates the Euclidean distance between two given variables.
	/// </summary>
	/// <param name="value1"> Value number one, which will be reduced by value number two. </param>
	/// <param name="value2"> Value number two, which will be reduced from value number one. </param>
	/// <returns> Returns a float containing the calculated distance. </returns>
	float euclideanDistance(float value1, float value2);
};
