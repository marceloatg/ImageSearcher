#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "ColorEngine.h"
#include "FormEngine.h"
#include "TextureEngine.h"

using namespace cv;

namespace ImageSearcher 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ImageSearcher
	/// </summary>
	public ref class ImageSearcher : public System::Windows::Forms::Form
	{
	public:
		ImageSearcher(ColorEngine* colorEngine,
					  FormEngine* formEngine,
					  TextureEngine* textureEngine);
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ImageSearcher();

	private:
		/// <summary>
		/// String pointer to current database path.
		/// </summary>
		LPCWSTR databasePath;

		/// <summary>
		/// Pointer to receive the color engine object.
		/// </summary>
		ColorEngine* colorEngine;

		/// <summary>
		/// Pointer to receive the form engine object.
		/// </summary>
		FormEngine* formEngine;

		/// <summary>
		/// Pointer to receive the texture engine object.
		/// </summary>
		TextureEngine* textureEngine;

#pragma region "Windows Form Designer generated atriattributesbutes"
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::Container ^components;
#pragma endregion
	
#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 //
				 // textBox1
				 //
				 this->textBox1->Location = System::Drawing::Point(12, 12);
				 this->textBox1->Multiline = true;
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(260, 191);
				 this->textBox1->TabIndex = 0;
				 //
				 // button1
				 //
				 this->button1->Location = System::Drawing::Point(105, 227);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 23);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"search";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &ImageSearcher::button1_Click);
				 //
				 // ImageSearcher
				 //
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(284, 262);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->textBox1);
				 this->Name = L"ImageSearcher";
				 this->Text = L"ImageSearcher";
				 this->ResumeLayout(false);
				 this->PerformLayout();
			 }
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		string imgPath = "C:/Users/Marcelo/Documents/Programming/C++/ImageSearcher/ImageSearcher/img.jpg";
		color_distance *result;
		int quantity = 5;

		result = colorEngine->searchImage(imgPath, quantity);
	}
	};
}