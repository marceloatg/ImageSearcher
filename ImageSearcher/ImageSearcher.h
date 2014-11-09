#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <msclr\marshal_cppstd.h>

#include "ColorEngine.h"
#include "FormEngine.h"
#include "TextureEngine.h"
#include "ResultComponent.h"
#include "Shlwapi.h"

using namespace cv;
using namespace System;

namespace ImageSearcher 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct total_distance
	{
		float distance;
		color_distance* color;
		form_distance* form;
		texture_distance* texture;
	};


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

#pragma region "Windows Form Designer generated attributes"
	private: System::Windows::Forms::Panel^  rightPanel;
	private: System::Windows::Forms::Panel^  bottomPanel;
	private: System::Windows::Forms::Panel^  topPanel;
	private: System::Windows::Forms::Button^  btn_database;
	private: System::Windows::Forms::Button^  btn_search;
	private: System::Windows::Forms::PictureBox^  img_original;
	private: System::Windows::Forms::Button^  btn_choose;
	private: System::Windows::Forms::TextBox^  txtbox_imagePath;
	private: System::Windows::Forms::Label^  label_originalImageInfo1;
	private: System::Windows::Forms::CheckBox^  chkBox_texture;
	private: System::Windows::Forms::CheckBox^  chkBox_form;
	private: System::Windows::Forms::CheckBox^  chkBox_color;
	private: System::Windows::Forms::NumericUpDown^  num_quantity;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Label^  label_depth;
	private: System::Windows::Forms::Label^  label_height;
	private: System::Windows::Forms::Label^  label_width;
	private: System::Windows::Forms::Label^  label_size;
	private: System::Windows::Forms::Label^  label_name;
	private: System::Windows::Forms::Label^  label_originalImageInfo2;
	private: System::Windows::Forms::Label^  label_writeTime;
	private: System::Windows::Forms::Label^  label_accessTime;
	private: System::Windows::Forms::Label^  label_creationTime;
	private: System::Windows::Forms::Label^  label_verResolution;
	private: System::Windows::Forms::Label^  label_horResolution;
	private: System::ComponentModel::BackgroundWorker^  backWorkerColorEngine;
	private: System::Windows::Forms::FlowLayoutPanel^  centralPanel;
	private: System::ComponentModel::BackgroundWorker^  backWorkerFormEngine;
	private: System::ComponentModel::BackgroundWorker^  backWorkerTextureEngine;


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
				 this->num_quantity = (gcnew System::Windows::Forms::NumericUpDown());
				 this->chkBox_texture = (gcnew System::Windows::Forms::CheckBox());
				 this->chkBox_form = (gcnew System::Windows::Forms::CheckBox());
				 this->chkBox_color = (gcnew System::Windows::Forms::CheckBox());
				 this->btn_database = (gcnew System::Windows::Forms::Button());
				 this->bottomPanel = (gcnew System::Windows::Forms::Panel());
				 this->btn_search = (gcnew System::Windows::Forms::Button());
				 this->topPanel = (gcnew System::Windows::Forms::Panel());
				 this->label_writeTime = (gcnew System::Windows::Forms::Label());
				 this->label_accessTime = (gcnew System::Windows::Forms::Label());
				 this->label_creationTime = (gcnew System::Windows::Forms::Label());
				 this->label_verResolution = (gcnew System::Windows::Forms::Label());
				 this->label_horResolution = (gcnew System::Windows::Forms::Label());
				 this->label_originalImageInfo2 = (gcnew System::Windows::Forms::Label());
				 this->label_depth = (gcnew System::Windows::Forms::Label());
				 this->label_height = (gcnew System::Windows::Forms::Label());
				 this->label_width = (gcnew System::Windows::Forms::Label());
				 this->label_size = (gcnew System::Windows::Forms::Label());
				 this->label_name = (gcnew System::Windows::Forms::Label());
				 this->label_originalImageInfo1 = (gcnew System::Windows::Forms::Label());
				 this->txtbox_imagePath = (gcnew System::Windows::Forms::TextBox());
				 this->btn_choose = (gcnew System::Windows::Forms::Button());
				 this->img_original = (gcnew System::Windows::Forms::PictureBox());
				 this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->backWorkerColorEngine = (gcnew System::ComponentModel::BackgroundWorker());
				 this->centralPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
				 this->backWorkerFormEngine = (gcnew System::ComponentModel::BackgroundWorker());
				 this->backWorkerTextureEngine = (gcnew System::ComponentModel::BackgroundWorker());
				 this->rightPanel->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_quantity))->BeginInit();
				 this->bottomPanel->SuspendLayout();
				 this->topPanel->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_original))->BeginInit();
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
				 this->rightPanel->Size = System::Drawing::Size(250, 572);
				 this->rightPanel->TabIndex = 0;
				 // 
				 // num_quantity
				 // 
				 this->num_quantity->Location = System::Drawing::Point(25, 324);
				 this->num_quantity->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 this->num_quantity->Name = L"num_quantity";
				 this->num_quantity->Size = System::Drawing::Size(120, 20);
				 this->num_quantity->TabIndex = 7;
				 this->num_quantity->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->num_quantity->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
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
				 // btn_database
				 // 
				 this->btn_database->Location = System::Drawing::Point(6, 22);
				 this->btn_database->Name = L"btn_database";
				 this->btn_database->Size = System::Drawing::Size(75, 23);
				 this->btn_database->TabIndex = 0;
				 this->btn_database->Text = L"database";
				 this->btn_database->UseVisualStyleBackColor = true;
				 this->btn_database->Click += gcnew System::EventHandler(this, &ImageSearcher::btn_database_Click);
				 // 
				 // bottomPanel
				 // 
				 this->bottomPanel->BackColor = System::Drawing::SystemColors::Control;
				 this->bottomPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->bottomPanel->Controls->Add(this->btn_search);
				 this->bottomPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->bottomPanel->Location = System::Drawing::Point(0, 522);
				 this->bottomPanel->Name = L"bottomPanel";
				 this->bottomPanel->Size = System::Drawing::Size(694, 50);
				 this->bottomPanel->TabIndex = 1;
				 // 
				 // btn_search
				 // 
				 this->btn_search->Location = System::Drawing::Point(326, 15);
				 this->btn_search->Name = L"btn_search";
				 this->btn_search->Size = System::Drawing::Size(75, 23);
				 this->btn_search->TabIndex = 0;
				 this->btn_search->Text = L"search";
				 this->btn_search->UseVisualStyleBackColor = true;
				 this->btn_search->Click += gcnew System::EventHandler(this, &ImageSearcher::btn_search_Click);
				 // 
				 // topPanel
				 // 
				 this->topPanel->BackColor = System::Drawing::SystemColors::Control;
				 this->topPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->topPanel->Controls->Add(this->label_writeTime);
				 this->topPanel->Controls->Add(this->label_accessTime);
				 this->topPanel->Controls->Add(this->label_creationTime);
				 this->topPanel->Controls->Add(this->label_verResolution);
				 this->topPanel->Controls->Add(this->label_horResolution);
				 this->topPanel->Controls->Add(this->label_originalImageInfo2);
				 this->topPanel->Controls->Add(this->label_depth);
				 this->topPanel->Controls->Add(this->label_height);
				 this->topPanel->Controls->Add(this->label_width);
				 this->topPanel->Controls->Add(this->label_size);
				 this->topPanel->Controls->Add(this->label_name);
				 this->topPanel->Controls->Add(this->label_originalImageInfo1);
				 this->topPanel->Controls->Add(this->txtbox_imagePath);
				 this->topPanel->Controls->Add(this->btn_choose);
				 this->topPanel->Controls->Add(this->img_original);
				 this->topPanel->Dock = System::Windows::Forms::DockStyle::Top;
				 this->topPanel->Location = System::Drawing::Point(0, 0);
				 this->topPanel->Name = L"topPanel";
				 this->topPanel->Size = System::Drawing::Size(694, 120);
				 this->topPanel->TabIndex = 2;
				 // 
				 // label_writeTime
				 // 
				 this->label_writeTime->AutoSize = true;
				 this->label_writeTime->Location = System::Drawing::Point(491, 62);
				 this->label_writeTime->Name = L"label_writeTime";
				 this->label_writeTime->Size = System::Drawing::Size(10, 13);
				 this->label_writeTime->TabIndex = 14;
				 this->label_writeTime->Text = L"-";
				 // 
				 // label_accessTime
				 // 
				 this->label_accessTime->AutoSize = true;
				 this->label_accessTime->Location = System::Drawing::Point(491, 49);
				 this->label_accessTime->Name = L"label_accessTime";
				 this->label_accessTime->Size = System::Drawing::Size(10, 13);
				 this->label_accessTime->TabIndex = 13;
				 this->label_accessTime->Text = L"-";
				 // 
				 // label_creationTime
				 // 
				 this->label_creationTime->AutoSize = true;
				 this->label_creationTime->Location = System::Drawing::Point(491, 36);
				 this->label_creationTime->Name = L"label_creationTime";
				 this->label_creationTime->Size = System::Drawing::Size(10, 13);
				 this->label_creationTime->TabIndex = 12;
				 this->label_creationTime->Text = L"-";
				 // 
				 // label_verResolution
				 // 
				 this->label_verResolution->AutoSize = true;
				 this->label_verResolution->Location = System::Drawing::Point(491, 23);
				 this->label_verResolution->Name = L"label_verResolution";
				 this->label_verResolution->Size = System::Drawing::Size(10, 13);
				 this->label_verResolution->TabIndex = 11;
				 this->label_verResolution->Text = L"-";
				 // 
				 // label_horResolution
				 // 
				 this->label_horResolution->AutoSize = true;
				 this->label_horResolution->Location = System::Drawing::Point(491, 10);
				 this->label_horResolution->Name = L"label_horResolution";
				 this->label_horResolution->Size = System::Drawing::Size(10, 13);
				 this->label_horResolution->TabIndex = 10;
				 this->label_horResolution->Text = L"-";
				 // 
				 // label_originalImageInfo2
				 // 
				 this->label_originalImageInfo2->AutoSize = true;
				 this->label_originalImageInfo2->Location = System::Drawing::Point(380, 10);
				 this->label_originalImageInfo2->Name = L"label_originalImageInfo2";
				 this->label_originalImageInfo2->Size = System::Drawing::Size(105, 65);
				 this->label_originalImageInfo2->TabIndex = 9;
				 this->label_originalImageInfo2->Text = L"Horizontal resolution:\r\nVertical Resolution:\r\nCreation time:\r\nLast access time:\r\n"
					 L"Last write time:";
				 // 
				 // label_depth
				 // 
				 this->label_depth->AutoSize = true;
				 this->label_depth->Location = System::Drawing::Point(174, 62);
				 this->label_depth->Name = L"label_depth";
				 this->label_depth->Size = System::Drawing::Size(10, 13);
				 this->label_depth->TabIndex = 8;
				 this->label_depth->Text = L"-";
				 // 
				 // label_height
				 // 
				 this->label_height->AutoSize = true;
				 this->label_height->Location = System::Drawing::Point(174, 49);
				 this->label_height->Name = L"label_height";
				 this->label_height->Size = System::Drawing::Size(10, 13);
				 this->label_height->TabIndex = 7;
				 this->label_height->Text = L"-";
				 // 
				 // label_width
				 // 
				 this->label_width->AutoSize = true;
				 this->label_width->Location = System::Drawing::Point(174, 36);
				 this->label_width->Name = L"label_width";
				 this->label_width->Size = System::Drawing::Size(10, 13);
				 this->label_width->TabIndex = 6;
				 this->label_width->Text = L"-";
				 // 
				 // label_size
				 // 
				 this->label_size->AutoSize = true;
				 this->label_size->Location = System::Drawing::Point(174, 23);
				 this->label_size->Name = L"label_size";
				 this->label_size->Size = System::Drawing::Size(10, 13);
				 this->label_size->TabIndex = 5;
				 this->label_size->Text = L"-";
				 // 
				 // label_name
				 // 
				 this->label_name->AutoSize = true;
				 this->label_name->Location = System::Drawing::Point(174, 10);
				 this->label_name->Name = L"label_name";
				 this->label_name->Size = System::Drawing::Size(10, 13);
				 this->label_name->TabIndex = 4;
				 this->label_name->Text = L"-";
				 // 
				 // label_originalImageInfo1
				 // 
				 this->label_originalImageInfo1->AutoSize = true;
				 this->label_originalImageInfo1->Location = System::Drawing::Point(126, 10);
				 this->label_originalImageInfo1->Name = L"label_originalImageInfo1";
				 this->label_originalImageInfo1->Size = System::Drawing::Size(41, 65);
				 this->label_originalImageInfo1->TabIndex = 3;
				 this->label_originalImageInfo1->Text = L"Name:\r\nSize:\r\nWidth:\r\nHeight:\r\nDepth:";
				 // 
				 // txtbox_imagePath
				 // 
				 this->txtbox_imagePath->Location = System::Drawing::Point(228, 89);
				 this->txtbox_imagePath->Name = L"txtbox_imagePath";
				 this->txtbox_imagePath->Size = System::Drawing::Size(451, 20);
				 this->txtbox_imagePath->TabIndex = 2;
				 // 
				 // btn_choose
				 // 
				 this->btn_choose->Location = System::Drawing::Point(125, 87);
				 this->btn_choose->Name = L"btn_choose";
				 this->btn_choose->Size = System::Drawing::Size(90, 24);
				 this->btn_choose->TabIndex = 1;
				 this->btn_choose->Text = L"choose image";
				 this->btn_choose->UseVisualStyleBackColor = true;
				 this->btn_choose->Click += gcnew System::EventHandler(this, &ImageSearcher::btn_choose_Click);
				 // 
				 // img_original
				 // 
				 this->img_original->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->img_original->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"img_original.Image")));
				 this->img_original->Location = System::Drawing::Point(10, 10);
				 this->img_original->Name = L"img_original";
				 this->img_original->Size = System::Drawing::Size(100, 100);
				 this->img_original->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->img_original->TabIndex = 0;
				 this->img_original->TabStop = false;
				 this->img_original->Click += gcnew System::EventHandler(this, &ImageSearcher::img_original_Click);
				 // 
				 // openFileDialog
				 // 
				 this->openFileDialog->FileName = L"openFileDialog";
				 this->openFileDialog->Filter = L"JPG files|*.jpg";
				 this->openFileDialog->Title = L"Select image";
				 // 
				 // backWorkerColorEngine
				 // 
				 this->backWorkerColorEngine->WorkerSupportsCancellation = true;
				 this->backWorkerColorEngine->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ImageSearcher::backWorkerColorEngine_DoWork);
				 this->backWorkerColorEngine->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &ImageSearcher::backWorkerColorEngine_RunWorkerCompleted);
				 // 
				 // centralPanel
				 // 
				 this->centralPanel->AutoScroll = true;
				 this->centralPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
				 this->centralPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->centralPanel->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->centralPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
				 this->centralPanel->Location = System::Drawing::Point(0, 120);
				 this->centralPanel->Name = L"centralPanel";
				 this->centralPanel->Size = System::Drawing::Size(694, 402);
				 this->centralPanel->TabIndex = 3;
				 // 
				 // backWorkerFormEngine
				 // 
				 this->backWorkerFormEngine->WorkerSupportsCancellation = true;
				 this->backWorkerFormEngine->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ImageSearcher::backWorkerFormEngine_DoWork);
				 this->backWorkerFormEngine->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &ImageSearcher::backWorkerFormEngine_RunWorkerCompleted);
				 // 
				 // backWorkerTextureEngine
				 // 
				 this->backWorkerTextureEngine->WorkerSupportsCancellation = true;
				 this->backWorkerTextureEngine->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ImageSearcher::backWorkerTextureEngine_DoWork);
				 this->backWorkerTextureEngine->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &ImageSearcher::backWorkerTextureEngine_RunWorkerCompleted);
				 // 
				 // ImageSearcher
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(944, 572);
				 this->Controls->Add(this->centralPanel);
				 this->Controls->Add(this->topPanel);
				 this->Controls->Add(this->bottomPanel);
				 this->Controls->Add(this->rightPanel);
				 this->DoubleBuffered = true;
				 this->MinimumSize = System::Drawing::Size(960, 600);
				 this->Name = L"ImageSearcher";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"ImageSearcher";
				 this->rightPanel->ResumeLayout(false);
				 this->rightPanel->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_quantity))->EndInit();
				 this->bottomPanel->ResumeLayout(false);
				 this->topPanel->ResumeLayout(false);
				 this->topPanel->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_original))->EndInit();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	
private: System::Void btn_choose_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->img_original->Load(this->openFileDialog->FileName);
			this->txtbox_imagePath->Text = this->openFileDialog->FileName;
			this->label_name->Text = "" + get_file_name(this->openFileDialog->FileName);
			this->label_size->Text = "" + get_file_size(this->openFileDialog->FileName) + " KB";
			this->label_width->Text = "" + this->img_original->Image->Width + " pixels";
			this->label_height->Text = "" + this->img_original->Image->Height + " pixels";
			this->label_depth->Text = "" + this->img_original->Image->GetPixelFormatSize(this->img_original->Image->PixelFormat) + " bits";
			this->label_horResolution->Text = "" + this->img_original->Image->HorizontalResolution + " dpi";
			this->label_verResolution->Text = "" + this->img_original->Image->VerticalResolution + " dpi";
			this->label_creationTime->Text = "" + get_creation_time(this->openFileDialog->FileName);
			this->label_accessTime->Text = "" + get_access_time(this->openFileDialog->FileName);
			this->label_writeTime->Text = "" + get_write_time(this->openFileDialog->FileName);
		}
	}

private: System::Void img_original_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->txtbox_imagePath->Text != "")
		{
			pin_ptr<const wchar_t> fileName = PtrToStringChars(this->txtbox_imagePath->Text);
			ShellExecute(0, 0, fileName, 0, 0, SW_SHOW);
		}
		return;
	}

private: System::Void btn_search_Click(System::Object^  sender, System::EventArgs^  e)
{
	total_distance distance[1001];
	for (size_t i = 0; i < 1001; i++)
	{
		distance[i].distance = 0.0f;
		distance[i].color = NULL;
		distance[i].form = NULL;
		distance[i].texture = NULL;
	}
	int aux = 0;

	// Cleanning central panel in order to show new results.
	this->centralPanel->Controls->Clear();

	// Defining image path 
	msclr::interop::marshal_context context;
	string imgPath = context.marshal_as<std::string>(this->txtbox_imagePath->Text);

	// Defining quantity
	int quantity = (int)this->num_quantity->Value;

	// Searching image
	if (this->chkBox_color->Checked == true)
	{
		color_distance* color_results = colorEngine->searchImage(imgPath);

		for (size_t i = 0; i < 1001; i++)
		{
			distance[i].color = &color_results[i];
		}

		aux++;
	} 

	if (this->chkBox_form->Checked == true)
	{
		form_distance* form_results = formEngine->searchImage(imgPath);

		for (size_t i = 0; i < 1001; i++)
		{
			distance[i].form = &form_results[i];
		}

		aux++;
	}

	if (this->chkBox_texture->Checked == true)
	{
		texture_distance* texture_results = textureEngine->searchImage(imgPath);

		for (size_t i = 0; i < 1001; i++)
		{
			distance[i].texture = &texture_results[i];
		}

		aux++;
	}

	for (size_t i = 0; i < 1001; i++)
	{
		if (distance[i].color != NULL) distance[i].distance += distance[i].color->distance;
		if (distance[i].form != NULL) distance[i].distance += distance[i].form->distance;
		if (distance[i].texture != NULL) distance[i].distance += distance[i].texture->distance;
		distance[i].distance /= aux;
	}

	for (size_t index = 0; index < quantity; index++)
	{
		// Preparing image path.
		System::String^ fileName;
		size_t   i;
		char *strChar = new char[MAX_PATH];
		wcstombs_s(&i, strChar, (size_t)MAX_PATH, imageBasePath, (size_t)MAX_PATH);
		System::String^ imagePath = gcnew System::String(strChar);

		if (distance[i].color != NULL)
		{
			imagePath += "\\" + gcnew System::String(distance[index].color->image.name);
			fileName = gcnew System::String(distance[index].color->image.name);
		}
		else if (distance[i].form != NULL)
		{
			imagePath += "\\" + gcnew System::String(distance[index].form->image.name);
			fileName = gcnew System::String(distance[index].form->image.name);
		}
		else if (distance[i].texture != NULL)
		{
			imagePath += "\\" + gcnew System::String(distance[index].texture->image.name);
			fileName = gcnew System::String(distance[index].texture->image.name);
		}
		
		// Displaying results.
		this->centralPanel->Controls->Add(gcnew ResultComponent(imagePath,
			                                                    gcnew System::String(fileName),
																gcnew System::String(get_file_size(imagePath) + " KB"),
																gcnew System::String("" + (distance[index].distance * 100))));
	}

	return;
}

private: System::Void backWorkerColorEngine_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	// Block search buttons since there's no search engine started yet.
	this->chkBox_color->Enabled = false;
	
	// start color engine.
	e->Result = this->colorEngine->start(imageBasePath);
}

private: System::Void backWorkerColorEngine_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
{
	this->chkBox_color->Enabled = true;
}

private: System::Void backWorkerFormEngine_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		// Block search buttons since there's no search engine started yet.
		this->chkBox_form->Enabled = false;

		// start form engine.
		e->Result = this->formEngine->start(imageBasePath);
	}

private: System::Void backWorkerFormEngine_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
{
	this->chkBox_form->Enabled = true;
}

private: System::Void backWorkerTextureEngine_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	// Block search buttons since there's no search engine started yet.
	this->chkBox_texture->Enabled = false;

	// start form engine.
	e->Result = this->textureEngine->start(imageBasePath);
}

private: System::Void backWorkerTextureEngine_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
{
	this->chkBox_texture->Enabled = true;
}

private: System::Void btn_database_Click(System::Object^  sender, System::EventArgs^  e)
{
	
}

#pragma region "Get file information functions"

	int get_file_size(System::String^ filename)
	{
		// syntax cleaner 
		msclr::interop::marshal_context context;
		string std_filename = context.marshal_as<std::string>(filename);

		FILE *p_file = NULL;
		p_file = fopen(std_filename.c_str(), "rb");
		fseek(p_file, 0, SEEK_END);
		int size = ftell(p_file);
		fclose(p_file);
		return (size / 1024);
	}

	System::String^ get_file_name(System::String^ filename)
	{
		System::String^ aux = "";

		for (size_t i = (filename->Length - 1); i >= 0; i--)
		{
			if (filename[i] == '\\')
			{
				for (size_t j = i + 1; j < filename->Length; j++)
				{
					aux += filename[j];
				}
				return aux;
			}
		}
	}

	System::String^ get_creation_time(System::String^ filename)
	{
		WIN32_FIND_DATA FindFileData;
		HANDLE hFind;

		pin_ptr<const wchar_t> wstr = PtrToStringChars(filename);

		hFind = FindFirstFile(wstr, &FindFileData);

		FILETIME ftCreationTime = FindFileData.ftCreationTime;
		FindClose(hFind);

		SYSTEMTIME st;
		LPWSTR local;
		FileTimeToLocalFileTime(&ftCreationTime, &ftCreationTime);
		FileTimeToSystemTime(&ftCreationTime, &st);
		GetDateFormat(LOCALE_USER_DEFAULT, DATE_LONGDATE, &st, NULL, local, 255);
		System::String^ aux = st.wDay + "/" + st.wMonth + "/" + st.wYear + " " + st.wHour + ":" + st.wMinute + ":" + st.wSecond;
		return aux;
	}

	System::String^ get_access_time(System::String^ filename)
	{
		WIN32_FIND_DATA FindFileData;
		HANDLE hFind;

		pin_ptr<const wchar_t> wstr = PtrToStringChars(filename);

		hFind = FindFirstFile(wstr, &FindFileData);

		FILETIME ftCreationTime = FindFileData.ftLastAccessTime;
		FindClose(hFind);

		SYSTEMTIME st;
		LPWSTR local;
		FileTimeToLocalFileTime(&ftCreationTime, &ftCreationTime);
		FileTimeToSystemTime(&ftCreationTime, &st);
		GetDateFormat(LOCALE_USER_DEFAULT, DATE_LONGDATE, &st, NULL, local, 255);
		System::String^ aux = st.wDay + "/" + st.wMonth + "/" + st.wYear + " " + st.wHour + ":" + st.wMinute + ":" + st.wSecond;
		return aux;
	}

	System::String^ get_write_time(System::String^ filename)
	{
		WIN32_FIND_DATA FindFileData;
		HANDLE hFind;

		pin_ptr<const wchar_t> wstr = PtrToStringChars(filename);

		hFind = FindFirstFile(wstr, &FindFileData);

		FILETIME ftCreationTime = FindFileData.ftLastWriteTime;
		FindClose(hFind);

		SYSTEMTIME st;
		LPWSTR local;
		FileTimeToLocalFileTime(&ftCreationTime, &ftCreationTime);
		FileTimeToSystemTime(&ftCreationTime, &st);
		GetDateFormat(LOCALE_USER_DEFAULT, DATE_LONGDATE, &st, NULL, local, 255);
		System::String^ aux = st.wDay + "/" + st.wMonth + "/" + st.wYear + " " + st.wHour + ":" + st.wMinute + ":" + st.wSecond;
		return aux;
	}
#pragma endregion
};
}