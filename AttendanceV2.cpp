#include "AttendanceV2.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {

	// Making the files needed if not already made
	using namespace std;
	system("mkdir C:\\Attendance");

	ifstream checkingLocation;
	ofstream makingLocation;
	
	byte const filesAmount = 4;
	string fileNames[filesAmount] = { "admins", "employees", "properties", "log"};

	// Checking for .txt files
	for (byte i = 0; i < filesAmount; i++) {
		checkingLocation.open("C:\\Attendance\\" + fileNames[i] + ".txt");
		if (!checkingLocation) {
			ofstream makingLocation("C:\\Attendance\\" + fileNames[i] + ".txt");
			makingLocation.close();
		}
		else {
			checkingLocation.close();
		}
	}
	
	// Starting GUI
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AttendanceV2::AttendanceV2 form;                 
	Application::Run(% form);
}