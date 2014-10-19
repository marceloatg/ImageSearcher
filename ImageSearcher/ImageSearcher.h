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
		/// String pointer to current image base directory.
		/// </summary>
		LPCWSTR imageBasePath;

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
	private: System::Windows::Forms::Panel^  rightPanel;
	private: System::Windows::Forms::Panel^  bottomPanel;
	private: System::Windows::Forms::Panel^  topPanel;
	private: System::Windows::Forms::Panel^  centralPanel;
	private: System::Windows::Forms::Button^  btn_database;
	private: System::Windows::Forms::Button^  btn_search;
	private: System::Windows::Forms::PictureBox^  img_original;
	private: System::Windows::Forms::Button^  btn_choose;
	private: System::Windows::Forms::TextBox^  txtbox_imagePath;
	private: System::Windows::Forms::Label^  label_originalImageInfo;
	private: System::Windows::Forms::CheckBox^  chkBox_texture;
	private: System::Windows::Forms::CheckBox^  chkBox_form;
	private: System::Windows::Forms::CheckBox^  chkBox_color;
	private: System::Windows::Forms::NumericUpDown^  num_quantity;






	private: System::ComponentModel::IContainer^  components;




#pragma endregion
	
#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ImageSearcher::typeid));
				 this->rightPanel = (gcnew System::Windows::Forms::Panel());
				 this->bottomPanel = (gcnew System::Windows::Forms::Panel());
				 this->topPanel = (gcnew System::Windows::Forms::Panel());
				 this->centralPanel = (gcnew System::Windows::Forms::Panel());
				 this->btn_database = (gcnew System::Windows::Forms::Button());
				 this->btn_search = (gcnew System::Windows::Forms::Button());
				 this->img_original = (gcnew System::Windows::Forms::PictureBox());
				 this->btn_choose = (gcnew System::Windows::Forms::Button());
				 this->txtbox_imagePath = (gcnew System::Windows::Forms::TextBox());
				 this->label_originalImageInfo = (gcnew System::Windows::Forms::Label());
				 this->chkBox_color = (gcnew System::Windows::Forms::CheckBox());
				 this->chkBox_form = (gcnew System::Windows::Forms::CheckBox());
				 this->chkBox_texture = (gcnew System::Windows::Forms::CheckBox());
				 this->num_quantity = (gcnew System::Windows::Forms::NumericUpDown());
				 this->rightPanel->SuspendLayout();
				 this->bottomPanel->SuspendLayout();
				 this->topPanel->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_original))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_quantity))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // rightPanel
				 // 
				 this->rightPanel->BackColor = System::Drawing::SystemColors::ControlLight;
				 this->rightPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->rightPanel->Controls->Add(this->num_quantity);
				 this->rightPanel->Controls->Add(this->chkBox_texture);
				 this->rightPanel->Controls->Add(this->chkBox_form);
				 this->rightPanel->Controls->Add(this->chkBox_color);
				 this->rightPanel->Controls->Add(this->btn_database);
				 this->rightPanel->Dock = System::Windows::Forms::DockStyle::Right;
				 this->rightPanel->Location = System::Drawing::Point(694, 0);
				 this->rightPanel->Name = L"rightPanel";
				 this->rightPanel->Size = System::Drawing::Size(250, 562);
				 this->rightPanel->TabIndex = 0;
				 // 
				 // bottomPanel
				 // 
				 this->bottomPanel->BackColor = System::Drawing::SystemColors::Control;
				 this->bottomPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->bottomPanel->Controls->Add(this->btn_search);
				 this->bottomPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->bottomPanel->Location = System::Drawing::Point(0, 512);
				 this->bottomPanel->Name = L"bottomPanel";
				 this->bottomPanel->Size = System::Drawing::Size(694, 50);
				 this->bottomPanel->TabIndex = 1;
				 // 
				 // topPanel
				 // 
				 this->topPanel->BackColor = System::Drawing::SystemColors::Control;
				 this->topPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->topPanel->Controls->Add(this->label_originalImageInfo);
				 this->topPanel->Controls->Add(this->txtbox_imagePath);
				 this->topPanel->Controls->Add(this->btn_choose);
				 this->topPanel->Controls->Add(this->img_original);
				 this->topPanel->Dock = System::Windows::Forms::DockStyle::Top;
				 this->topPanel->Location = System::Drawing::Point(0, 0);
				 this->topPanel->Name = L"topPanel";
				 this->topPanel->Size = System::Drawing::Size(694, 120);
				 this->topPanel->TabIndex = 2;
				 // 
				 // centralPanel
				 // 
				 this->centralPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
				 this->centralPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->centralPanel->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->centralPanel->Location = System::Drawing::Point(0, 120);
				 this->centralPanel->Name = L"centralPanel";
				 this->centralPanel->Size = System::Drawing::Size(694, 392);
				 this->centralPanel->TabIndex = 3;
				 // 
				 // btn_database
				 // 
				 this->btn_database->Location = System::Drawing::Point(6, 22);
				 this->btn_database->Name = L"btn_database";
				 this->btn_database->Size = System::Drawing::Size(75, 23);
				 this->btn_database->TabIndex = 0;
				 this->btn_database->Text = L"database";
				 this->btn_database->UseVisualStyleBackColor = true;
				 // 
				 // btn_search
				 // 
				 this->btn_search->Location = System::Drawing::Point(323, 15);
				 this->btn_search->Name = L"btn_search";
				 this->btn_search->Size = System::Drawing::Size(75, 23);
				 this->btn_search->TabIndex = 0;
				 this->btn_search->Text = L"search";
				 this->btn_search->UseVisualStyleBackColor = true;
				 // 
				 // img_original
				 // 
				 this->img_original->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->img_original->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"img_original.Image")));
				 this->img_original->Location = System::Drawing::Point(10, 10);
				 this->img_original->Name = L"img_original";
				 this->img_original->Size = System::Drawing::Size(100, 100);
				 this->img_original->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->img_original->TabIndex = 0;
				 this->img_original->TabStop = false;
				 // 
				 // btn_choose
				 // 
				 this->btn_choose->Location = System::Drawing::Point(125, 87);
				 this->btn_choose->Name = L"btn_choose";
				 this->btn_choose->Size = System::Drawing::Size(90, 23);
				 this->btn_choose->TabIndex = 1;
				 this->btn_choose->Text = L"choose image";
				 this->btn_choose->UseVisualStyleBackColor = true;
				 // 
				 // txtbox_imagePath
				 // 
				 this->txtbox_imagePath->Location = System::Drawing::Point(228, 88);
				 this->txtbox_imagePath->Name = L"txtbox_imagePath";
				 this->txtbox_imagePath->Size = System::Drawing::Size(451, 20);
				 this->txtbox_imagePath->TabIndex = 2;
				 // 
				 // label_originalImageInfo
				 // 
				 this->label_originalImageInfo->AutoSize = true;
				 this->label_originalImageInfo->Location = System::Drawing::Point(125, 10);
				 this->label_originalImageInfo->Name = L"label_originalImageInfo";
				 this->label_originalImageInfo->Size = System::Drawing::Size(39, 65);
				 this->label_originalImageInfo->TabIndex = 3;
				 this->label_originalImageInfo->Text = L"Name:\r\nSize:\r\nWidth:\r\nHight:\r\nDepth:";
				 // 
				 // chkBox_color
				 // 
				 this->chkBox_color->AutoSize = true;
				 this->chkBox_color->Checked = true;
				 this->chkBox_color->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->chkBox_color->Location = System::Drawing::Point(15, 119);
				 this->chkBox_color->Name = L"chkBox_color";
				 this->chkBox_color->Size = System::Drawing::Size(100, 17);
				 this->chkBox_color->TabIndex = 4;
				 this->chkBox_color->Text = L"Search by color";
				 this->chkBox_color->UseVisualStyleBackColor = true;
				 // 
				 // chkBox_form
				 // 
				 this->chkBox_form->AutoSize = true;
				 this->chkBox_form->Checked = true;
				 this->chkBox_form->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->chkBox_form->Location = System::Drawing::Point(15, 163);
				 this->chkBox_form->Name = L"chkBox_form";
				 this->chkBox_form->Size = System::Drawing::Size(97, 17);
				 this->chkBox_form->TabIndex = 5;
				 this->chkBox_form->Text = L"Search by form";
				 this->chkBox_form->UseVisualStyleBackColor = true;
				 // 
				 // chkBox_texture
				 // 
				 this->chkBox_texture->AutoSize = true;
				 this->chkBox_texture->Checked = true;
				 this->chkBox_texture->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->chkBox_texture->Location = System::Drawing::Point(15, 207);
				 this->chkBox_texture->Name = L"chkBox_texture";
				 this->chkBox_texture->Size = System::Drawing::Size(109, 17);
				 this->chkBox_texture->TabIndex = 6;
				 this->chkBox_texture->Text = L"Seacrh by texture";
				 this->chkBox_texture->UseVisualStyleBackColor = true;
				 // 
				 // num_quantity
				 // 
				 this->num_quantity->Location = System::Drawing::Point(25, 324);
				 this->num_quantity->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
				 this->num_quantity->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 this->num_quantity->Name = L"num_quantity";
				 this->num_quantity->Size = System::Drawing::Size(120, 20);
				 this->num_quantity->TabIndex = 7;
				 this->num_quantity->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->num_quantity->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 // 
				 // ImageSearcher
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(944, 562);
				 this->Controls->Add(this->centralPanel);
				 this->Controls->Add(this->topPanel);
				 this->Controls->Add(this->bottomPanel);
				 this->Controls->Add(this->rightPanel);
				 this->MinimumSize = System::Drawing::Size(960, 600);
				 this->Name = L"ImageSearcher";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"ImageSearcher";
				 this->rightPanel->ResumeLayout(false);
				 this->rightPanel->PerformLayout();
				 this->bottomPanel->ResumeLayout(false);
				 this->topPanel->ResumeLayout(false);
				 this->topPanel->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_original))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_quantity))->EndInit();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	};
}