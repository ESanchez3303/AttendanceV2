#include "AttendanceV2.h"

using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AttendanceV2::AttendanceV2 form;                   // ProjectCPP1::MainForm form;
	Application::Run(% form);
}