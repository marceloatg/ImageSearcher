#include "ImageSearcher.h"

using namespace System;
using namespace System::Windows::Forms;

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
