#include "ImageSearcher.h"

using namespace System;
using namespace System::Windows::Forms;

#pragma region "Main"
[STAThread]
void main(array<System::String^>^ args)
{
	// Initiating application.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Initiating search engines.
	ColorEngine* colorEngine = new ColorEngine();
	FormEngine* formEngine = new FormEngine();
	TextureEngine* textureEngine = new TextureEngine();;

	// Initiating main form.
	ImageSearcher::ImageSearcher form(colorEngine, formEngine, textureEngine);
	Application::Run(%form);
}
#pragma endregion

ImageSearcher::ImageSearcher::ImageSearcher(ColorEngine* colorEngine,
											FormEngine* formEngine,
											TextureEngine* textureEngine)
{
	InitializeComponent();

	// Set default database path.
	databasePath = L"C:/Users/Marcelo/OneDrive/UEPG/4° Ano/Processamento de Imagens/images";

	this->colorEngine = colorEngine;
	this->colorEngine->start(databasePath);

	this->formEngine = formEngine;
	this->textureEngine = textureEngine;
}


ImageSearcher::ImageSearcher::~ImageSearcher()
{
	if (components)
	{
		delete components;
	}
}