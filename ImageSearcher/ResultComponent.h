#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System;

ref class ResultComponent : System::Windows::Forms::Panel
{
public:
	ResultComponent(System::String^ imagePath,
					System::String^ name,
					System::String^ size,
					System::String^ distance);
	~ResultComponent();

private: 

	System::String^ imagePath;
	System::Windows::Forms::Label^  label_distance;
	System::Windows::Forms::Label^  label_depth;
	System::Windows::Forms::Label^  label_height;
	System::Windows::Forms::Label^  labe_width;
	System::Windows::Forms::Label^  label_size;
	System::Windows::Forms::Label^  label_name;
	System::Windows::Forms::Label^  label_info;
	System::Windows::Forms::PictureBox^  pictureBox;
	System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e);
};

