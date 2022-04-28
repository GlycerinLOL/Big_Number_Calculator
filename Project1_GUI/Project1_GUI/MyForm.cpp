#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)

{
	Calculator Cal;

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    Project1GUI::MyForm form;

    Application::Run(% form);

	


	/*
	try {
		Cal.test();
		//Cal.RUN()
	}
	catch (char const* error) {
		cout << error << '\n';
	}
	
	std::cout << "Stop running!";
	*/

}
    