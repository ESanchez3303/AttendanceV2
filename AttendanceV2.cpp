#include "AttendanceV2.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {

	// Making the files needed if not already made
	using namespace std;
	system("mkdir C:\\Attendance_v2");

	ifstream checkingLocation;
	ofstream makingLocation;
	
	byte const filesAmount = 4;
	string fileNames[filesAmount] = { "admins", "employees", "settings", "logs"};

	// Checking for .txt files
	for (byte i = 0; i < filesAmount; i++) {
		checkingLocation.open("C:\\Attendance_v2\\" + fileNames[i] + ".txt");
		if ((!checkingLocation) && (i == 2)) {
			ofstream propertiesFileMaking("C:\\Attendance_v2\\" + fileNames[i] + ".txt");
			propertiesFileMaking << "limit=10.00" << endl;
			propertiesFileMaking << "late=1.00" << endl;
			propertiesFileMaking << "absent=2.00" << endl;
			propertiesFileMaking << "theme=default" << endl;
			propertiesFileMaking.close();
		}
		else if (!checkingLocation) {
			ofstream makingLocation("C:\\Attendance_v2\\" + fileNames[i] + ".txt");
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