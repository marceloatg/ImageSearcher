#include "ResultComponent.h"


ResultComponent::ResultComponent(System::String^ imagePath,
								 System::String^ name,
								 System::String^ size,
								 System::String^ distance)
{
	this->imagePath = imagePath;

	this->label_distance = (gcnew System::Windows::Forms::Label());
	this->label_depth = (gcnew System::Windows::Forms::Label());
	this->label_height = (gcnew System::Windows::Forms::Label());
	this->labe_width = (gcnew System::Windows::Forms::Label());
	this->label_size = (gcnew System::Windows::Forms::Label());
	this->label_name = (gcnew System::Windows::Forms::Label());
	this->label_info = (gcnew System::Windows::Forms::Label());
	this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
	this->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();

	// 
	// resultComponentPanel
	// 
	this->BackColor = System::Drawing::SystemColors::ControlLightLight;
	this->BorderStyle = System::Windows::Forms::BorderStyle::None;
	this->Controls->Add(this->label_distance);
	this->Controls->Add(this->label_depth);
	this->Controls->Add(this->label_height);
	this->Controls->Add(this->labe_width);
	this->Controls->Add(this->label_size);
	this->Controls->Add(this->label_name);
	this->Controls->Add(this->label_info);
	this->Controls->Add(this->pictureBox);
	this->Location = System::Drawing::Point(3, 3);
	this->Name = L"resultComponentPanel";
	this->Size = System::Drawing::Size(347, 120);
	this->TabIndex = 3;
	// 
	// pictureBox
	// 
	this->pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	this->pictureBox->Location = System::Drawing::Point(10, 10);
	this->pictureBox->Name = L"pictureBox1";
	this->pictureBox->Size = System::Drawing::Size(100, 100);
	this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->pictureBox->TabIndex = 0;
	this->pictureBox->TabStop = false;
	this->pictureBox->Load(imagePath);
	this->pictureBox->Click += gcnew System::EventHandler(this, &ResultComponent::pictureBox_Click);
	// 
	// label_distance
	// 
	this->label_distance->AutoSize = true;
	this->label_distance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->label_distance->Location = System::Drawing::Point(230, 87);
	this->label_distance->Name = L"label_distance";
	this->label_distance->Size = System::Drawing::Size(10, 13);
	this->label_distance->TabIndex = 8;
	this->label_distance->Text = distance + " %";
	// 
	// label_depth
	// 
	this->label_depth->AutoSize = true;
	this->label_depth->Location = System::Drawing::Point(174, 62);
	this->label_depth->Name = L"label_depth";
	this->label_depth->Size = System::Drawing::Size(10, 13);
	this->label_depth->TabIndex = 8;
	this->label_depth->Text = this->pictureBox->Image->GetPixelFormatSize(this->pictureBox->Image->PixelFormat) + " bits";
	// 
	// label_height
	// 
	this->label_height->AutoSize = true;
	this->label_height->Location = System::Drawing::Point(174, 49);
	this->label_height->Name = L"label_height";
	this->label_height->Size = System::Drawing::Size(10, 13);
	this->label_height->TabIndex = 7;
	this->label_height->Text = "" + this->pictureBox->Image->Height;
	// 
	// labe_width
	// 
	this->labe_width->AutoSize = true;
	this->labe_width->Location = System::Drawing::Point(174, 36);
	this->labe_width->Name = L"labe_width";
	this->labe_width->Size = System::Drawing::Size(10, 13);
	this->labe_width->TabIndex = 6;
	this->labe_width->Text = "" + this->pictureBox->Image->Width;
	// 
	// label_size
	// 
	this->label_size->AutoSize = true;
	this->label_size->Location = System::Drawing::Point(174, 23);
	this->label_size->Name = L"label_size";
	this->label_size->Size = System::Drawing::Size(10, 13);
	this->label_size->TabIndex = 5;
	this->label_size->Text = size;
	// 
	// label_name
	// 
	this->label_name->AutoSize = true;
	this->label_name->Location = System::Drawing::Point(174, 10);
	this->label_name->Name = L"label_name";
	this->label_name->Size = System::Drawing::Size(10, 13);
	this->label_name->TabIndex = 4;
	this->label_name->Text = name;
	// 
	// label_info
	// 
	this->label_info->AutoSize = true;
	this->label_info->Location = System::Drawing::Point(126, 10);
	this->label_info->Name = L"label_info";
	this->label_info->Size = System::Drawing::Size(41, 65);
	this->label_info->TabIndex = 3;
	this->label_info->Text = L"Name:\r\nSize:\r\nWidth:\r\nHeight:\r\nDepth:\r\n\r\nEuclidean Distance:";
	

	this->ResumeLayout(false);
	this->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
}

ResultComponent::~ResultComponent()
{
	this->Controls->Clear();
}

System::Void ResultComponent::pictureBox_Click(System::Object^  sender, System::EventArgs^  e)
{
	pin_ptr<const wchar_t> fileName = PtrToStringChars(this->imagePath);
	ShellExecute(0, 0, fileName, 0, 0, SW_SHOW);
	
	return;
}