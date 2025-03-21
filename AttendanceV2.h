#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <cstdio>
#include <iomanip>
#include <ctime>
using namespace msclr::interop;


std::string adminsFile    = "C:\\Attendance_v2\\admins.txt";
std::string employeesFile = "C:\\Attendance_v2\\employees.txt";
std::string logsFile      = "C:\\Attendance_v2\\logs.txt";
std::string settingsFile  = "C:\\Attendance_v2\\settings.txt";

std::string loggedInAdminPassword = "-1-";
std::string loggedInAdmin         = "NO_USER";
bool firstTimeSetUp = false;

namespace AttendanceV2 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AttendanceV2 : public System::Windows::Forms::Form{
	public: 
		AttendanceV2(void) {InitializeComponent();}
		~AttendanceV2(){
			if (components)
				delete components;
		}

	// Personal variables: DarkSlateGray
	Color backColor = Color::Sienna;
	Color secondBackColor = Color::Tan;
	Color thirdBackColor = Color::Moccasin;
	Color textColor = Color::DarkSlateGray;
	Color buttonPushedBackColor = Color::DarkGoldenrod;
	Color buttonPushedForeColor = Color::White;
	double settings_PointsLimit = 5;
	double settings_latePoints = 0.5;
	double settings_absentPoints = 2;
	String^ settings_theme = "default";
		

#pragma region windowFormObjects
		System::Windows::Forms::TextBox^ login_username;
		System::Windows::Forms::TextBox^ login_password;
		System::Windows::Forms::Label^ login_text1;
		System::Windows::Forms::Label^ login_text2;
		System::Windows::Forms::Button^ login_button;
		System::Windows::Forms::Panel^ login_panel;
		System::Windows::Forms::Panel^ sidePanel;
		System::Windows::Forms::Panel^ markEmployeeButton;
		System::Windows::Forms::Panel^ settingsLogsButton;
		System::Windows::Forms::Panel^ adminButton;
		System::Windows::Forms::Panel^ editAddEmployeeButton;
		System::Windows::Forms::Label^ settingsLogsLabel;
		System::Windows::Forms::Label^ adminLabel;
		System::Windows::Forms::Label^ editAddEmployeeLabel;
		System::Windows::Forms::Label^ markEmployeeLabel;
		System::Windows::Forms::Label^ mainMenuSideLabel;
		System::Windows::Forms::Panel^ mainMenuSidePanel;
		System::Windows::Forms::Timer^ sideMenuTimer;
		System::Windows::Forms::Panel^ markEmployeePanel;
		System::Windows::Forms::Panel^ editAddEmployeePanel;
		System::Windows::Forms::Panel^ settingsPanel;
		System::Windows::Forms::Label^ addEmployeeButton;
		System::Windows::Forms::Label^ editEmployeeButton;
		System::Windows::Forms::Panel^ addEmployeeWorkPanel;
		System::Windows::Forms::Panel^ editEmployeeWorkPanel;
		System::Windows::Forms::Label^ addEmployeeWorkText3;
		System::Windows::Forms::Label^ addEmployeeWorkText2;
		System::Windows::Forms::Label^ addEmployeeWorkText1;
		System::Windows::Forms::TextBox^ addEmployeeWorkEmployeeID;
		System::Windows::Forms::TextBox^ addEmployeeWorkLastName;
		System::Windows::Forms::TextBox^ addEmployeeWorkFirstName;
		System::Windows::Forms::Button^ addEmployeeWorkSaveButton;
		System::Windows::Forms::Label^ editEmployeeWorkText1;
		System::Windows::Forms::ComboBox^ editEmployeeComboBox;
		System::Windows::Forms::Button^ editEmployeeWorkRemoveEmployee;
		System::Windows::Forms::Button^ editEmployeeWorkSaveButton;
		System::Windows::Forms::Label^ editEmployeeWorkText4;
		System::Windows::Forms::Label^ editEmployeeWorkText3;
		System::Windows::Forms::Label^ editEmployeeWorkText2;
		System::Windows::Forms::TextBox^ editEmployeeWorkCurrentPoints;
		System::Windows::Forms::TextBox^ editEmployeeWorkEmployeeID;
		System::Windows::Forms::TextBox^ editEmployeeWorkLastName;
		System::Windows::Forms::TextBox^ editEmployeeWorkFirstName;
		System::Windows::Forms::Label^ editEmployeeWorkText5;
		System::Windows::Forms::Panel^ editEmployeeRemoveConfirmPanel;
		System::Windows::Forms::Label^ editEmployeeRemoveCancelButton;
		System::Windows::Forms::Label^ editEmployeeRemoveConfirmButton;
		System::Windows::Forms::Panel^ adminPanel;
		System::Windows::Forms::Label^ editAdminButton;
		System::Windows::Forms::Panel^ addAdminWorkPanel;
		System::Windows::Forms::Button^ addAdminSaveButton;
		System::Windows::Forms::TextBox^ addAdminWorkPassword;
		System::Windows::Forms::TextBox^ addAdminWorkUsername;
		System::Windows::Forms::Label^ addAdminWorkText2;
		System::Windows::Forms::Label^ addAdminWorkText1;
		System::Windows::Forms::Label^ addAdminButton;
		System::Windows::Forms::Panel^ editAdminWorkPanel;
		System::Windows::Forms::Panel^ editAdminRemoveConfirmPanel;
		System::Windows::Forms::Label^ editAdminRemoveCancelButton;
		System::Windows::Forms::Label^ editAdminRemoveConfirmButton;
		System::Windows::Forms::TextBox^ editAdminWorkConfirmedPassword;
		System::Windows::Forms::TextBox^ editAdminWorkPassword;
		System::Windows::Forms::TextBox^ editAdminWorkUsername;
		System::Windows::Forms::Button^ editAdminRemoveButton;
		System::Windows::Forms::Button^ editAdminSaveButton;
		System::Windows::Forms::Label^ editAdminText4;
		System::Windows::Forms::Label^ editAdminText3;
		System::Windows::Forms::Label^ editAdminText2;
		System::Windows::Forms::ComboBox^ editAdminComboBox;
		System::Windows::Forms::Label^ editAdminText1;
		System::Windows::Forms::TextBox^ addAdminWorkConfirmedPassword;
		System::Windows::Forms::Label^ addAdminWorkText3;
		System::Windows::Forms::Panel^ markEmployeeBackgroundPanel;
		System::Windows::Forms::Label^ markEmployeeAttendanceLimit;
		System::Windows::Forms::Panel^ markEmployeeActionConfrimPanel;
		System::Windows::Forms::Label^ markEmployeeActionCancelButton;
		System::Windows::Forms::Label^ markEmployeeActionConfirmButton;
		System::Windows::Forms::Label^ markEmployeeText2;
		System::Windows::Forms::ListView^ markEmployeeListView;
		System::Windows::Forms::ColumnHeader^ employeeName;
		System::Windows::Forms::ColumnHeader^ employeeID;
		System::Windows::Forms::ColumnHeader^ attendanceCount;
		System::Windows::Forms::Label^ ignore_2;
		System::Windows::Forms::Label^ ignore_1;
		System::Windows::Forms::Label^ markEmployeeText1;
		System::Windows::Forms::ComboBox^ markEmployeeComboBox;
		System::Windows::Forms::Panel^ settingsAttendancePanel;
		System::Windows::Forms::TextBox^ settingsAttendanceLimit;
		System::Windows::Forms::Label^ settingsText2;
		System::Windows::Forms::Button^ markEmployeeMarkLateButton;
		System::Windows::Forms::Button^ settingsSaveAttendanceButton;
		System::Windows::Forms::Label^ settingsText5;
		System::Windows::Forms::TextBox^ settingsAbsentPoints;
		System::Windows::Forms::Label^ settingsText4;
		System::Windows::Forms::TextBox^ settingsLatePoints;
		System::Windows::Forms::Label^ settingsText3;
		System::Windows::Forms::Button^ markEmployeeMarkAbsentButton;
		System::Windows::Forms::Panel^ settingsLogsPanel;
		System::Windows::Forms::Panel^ settingsThemePanel;
		System::Windows::Forms::Label^ settingsText1;
		System::Windows::Forms::Label^ settingsText6;
		System::Windows::Forms::RichTextBox^ settingsLogsListView;
		System::Windows::Forms::Button^ settingsExpandLogsButton;
		System::Windows::Forms::Timer^ settingsLogsTimer;
		System::Windows::Forms::RadioButton^ settingsThemeDefaultButton;
		System::Windows::Forms::RadioButton^ settingsThemeGrayButton;
		System::Windows::Forms::RadioButton^ settingsThemeRedButton;
		System::Windows::Forms::RadioButton^ settingsThemeGreenButton;
		System::Windows::Forms::Panel^ settingsResetAllPanel;
		System::Windows::Forms::Button^ settingsResetAllButton;
		System::Windows::Forms::Label^ settingsText7;
		System::Windows::Forms::Panel^ settingsResetAllConfrimPanel;
		System::Windows::Forms::Button^ settingsResetAllCancelButton;
		System::Windows::Forms::Button^ settingsResetAllConfirmButton;
		System::Windows::Forms::Label^ settingsText8;
		System::Windows::Forms::TextBox^ settingsResetAllPasswordInput;
private: System::ComponentModel::IContainer^ components;
public:

#pragma endregion



#pragma region Windows Form Designer generated code
	void InitializeComponent(void){
		this->components = (gcnew System::ComponentModel::Container());
		System::Windows::Forms::ListViewItem^ listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L"employee1"));
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AttendanceV2::typeid));
		this->login_username = (gcnew System::Windows::Forms::TextBox());
		this->login_password = (gcnew System::Windows::Forms::TextBox());
		this->login_text1 = (gcnew System::Windows::Forms::Label());
		this->login_text2 = (gcnew System::Windows::Forms::Label());
		this->login_button = (gcnew System::Windows::Forms::Button());
		this->login_panel = (gcnew System::Windows::Forms::Panel());
		this->sidePanel = (gcnew System::Windows::Forms::Panel());
		this->mainMenuSidePanel = (gcnew System::Windows::Forms::Panel());
		this->mainMenuSideLabel = (gcnew System::Windows::Forms::Label());
		this->settingsLogsButton = (gcnew System::Windows::Forms::Panel());
		this->settingsLogsLabel = (gcnew System::Windows::Forms::Label());
		this->adminButton = (gcnew System::Windows::Forms::Panel());
		this->adminLabel = (gcnew System::Windows::Forms::Label());
		this->editAddEmployeeButton = (gcnew System::Windows::Forms::Panel());
		this->editAddEmployeeLabel = (gcnew System::Windows::Forms::Label());
		this->markEmployeeButton = (gcnew System::Windows::Forms::Panel());
		this->markEmployeeLabel = (gcnew System::Windows::Forms::Label());
		this->sideMenuTimer = (gcnew System::Windows::Forms::Timer(this->components));
		this->markEmployeePanel = (gcnew System::Windows::Forms::Panel());
		this->markEmployeeBackgroundPanel = (gcnew System::Windows::Forms::Panel());
		this->markEmployeeActionConfrimPanel = (gcnew System::Windows::Forms::Panel());
		this->markEmployeeActionCancelButton = (gcnew System::Windows::Forms::Label());
		this->markEmployeeActionConfirmButton = (gcnew System::Windows::Forms::Label());
		this->markEmployeeMarkAbsentButton = (gcnew System::Windows::Forms::Button());
		this->markEmployeeMarkLateButton = (gcnew System::Windows::Forms::Button());
		this->markEmployeeAttendanceLimit = (gcnew System::Windows::Forms::Label());
		this->markEmployeeText2 = (gcnew System::Windows::Forms::Label());
		this->markEmployeeListView = (gcnew System::Windows::Forms::ListView());
		this->employeeName = (gcnew System::Windows::Forms::ColumnHeader());
		this->employeeID = (gcnew System::Windows::Forms::ColumnHeader());
		this->attendanceCount = (gcnew System::Windows::Forms::ColumnHeader());
		this->markEmployeeText1 = (gcnew System::Windows::Forms::Label());
		this->markEmployeeComboBox = (gcnew System::Windows::Forms::ComboBox());
		this->ignore_2 = (gcnew System::Windows::Forms::Label());
		this->ignore_1 = (gcnew System::Windows::Forms::Label());
		this->editAddEmployeePanel = (gcnew System::Windows::Forms::Panel());
		this->editEmployeeButton = (gcnew System::Windows::Forms::Label());
		this->addEmployeeWorkPanel = (gcnew System::Windows::Forms::Panel());
		this->addEmployeeWorkSaveButton = (gcnew System::Windows::Forms::Button());
		this->addEmployeeWorkEmployeeID = (gcnew System::Windows::Forms::TextBox());
		this->addEmployeeWorkLastName = (gcnew System::Windows::Forms::TextBox());
		this->addEmployeeWorkFirstName = (gcnew System::Windows::Forms::TextBox());
		this->addEmployeeWorkText3 = (gcnew System::Windows::Forms::Label());
		this->addEmployeeWorkText2 = (gcnew System::Windows::Forms::Label());
		this->addEmployeeWorkText1 = (gcnew System::Windows::Forms::Label());
		this->addEmployeeButton = (gcnew System::Windows::Forms::Label());
		this->editEmployeeWorkPanel = (gcnew System::Windows::Forms::Panel());
		this->editEmployeeRemoveConfirmPanel = (gcnew System::Windows::Forms::Panel());
		this->editEmployeeRemoveCancelButton = (gcnew System::Windows::Forms::Label());
		this->editEmployeeRemoveConfirmButton = (gcnew System::Windows::Forms::Label());
		this->editEmployeeWorkCurrentPoints = (gcnew System::Windows::Forms::TextBox());
		this->editEmployeeWorkEmployeeID = (gcnew System::Windows::Forms::TextBox());
		this->editEmployeeWorkLastName = (gcnew System::Windows::Forms::TextBox());
		this->editEmployeeWorkFirstName = (gcnew System::Windows::Forms::TextBox());
		this->editEmployeeWorkText5 = (gcnew System::Windows::Forms::Label());
		this->editEmployeeWorkRemoveEmployee = (gcnew System::Windows::Forms::Button());
		this->editEmployeeWorkSaveButton = (gcnew System::Windows::Forms::Button());
		this->editEmployeeWorkText4 = (gcnew System::Windows::Forms::Label());
		this->editEmployeeWorkText3 = (gcnew System::Windows::Forms::Label());
		this->editEmployeeWorkText2 = (gcnew System::Windows::Forms::Label());
		this->editEmployeeComboBox = (gcnew System::Windows::Forms::ComboBox());
		this->editEmployeeWorkText1 = (gcnew System::Windows::Forms::Label());
		this->settingsPanel = (gcnew System::Windows::Forms::Panel());
		this->settingsLogsPanel = (gcnew System::Windows::Forms::Panel());
		this->settingsExpandLogsButton = (gcnew System::Windows::Forms::Button());
		this->settingsLogsListView = (gcnew System::Windows::Forms::RichTextBox());
		this->settingsText1 = (gcnew System::Windows::Forms::Label());
		this->settingsResetAllPanel = (gcnew System::Windows::Forms::Panel());
		this->settingsResetAllConfrimPanel = (gcnew System::Windows::Forms::Panel());
		this->settingsResetAllCancelButton = (gcnew System::Windows::Forms::Button());
		this->settingsResetAllConfirmButton = (gcnew System::Windows::Forms::Button());
		this->settingsText8 = (gcnew System::Windows::Forms::Label());
		this->settingsResetAllPasswordInput = (gcnew System::Windows::Forms::TextBox());
		this->settingsResetAllButton = (gcnew System::Windows::Forms::Button());
		this->settingsText7 = (gcnew System::Windows::Forms::Label());
		this->settingsThemePanel = (gcnew System::Windows::Forms::Panel());
		this->settingsThemeGrayButton = (gcnew System::Windows::Forms::RadioButton());
		this->settingsThemeRedButton = (gcnew System::Windows::Forms::RadioButton());
		this->settingsThemeGreenButton = (gcnew System::Windows::Forms::RadioButton());
		this->settingsThemeDefaultButton = (gcnew System::Windows::Forms::RadioButton());
		this->settingsText6 = (gcnew System::Windows::Forms::Label());
		this->settingsAttendancePanel = (gcnew System::Windows::Forms::Panel());
		this->settingsSaveAttendanceButton = (gcnew System::Windows::Forms::Button());
		this->settingsText5 = (gcnew System::Windows::Forms::Label());
		this->settingsAbsentPoints = (gcnew System::Windows::Forms::TextBox());
		this->settingsText4 = (gcnew System::Windows::Forms::Label());
		this->settingsLatePoints = (gcnew System::Windows::Forms::TextBox());
		this->settingsText3 = (gcnew System::Windows::Forms::Label());
		this->settingsAttendanceLimit = (gcnew System::Windows::Forms::TextBox());
		this->settingsText2 = (gcnew System::Windows::Forms::Label());
		this->adminPanel = (gcnew System::Windows::Forms::Panel());
		this->editAdminButton = (gcnew System::Windows::Forms::Label());
		this->addAdminWorkPanel = (gcnew System::Windows::Forms::Panel());
		this->addAdminWorkConfirmedPassword = (gcnew System::Windows::Forms::TextBox());
		this->addAdminWorkText3 = (gcnew System::Windows::Forms::Label());
		this->addAdminSaveButton = (gcnew System::Windows::Forms::Button());
		this->addAdminWorkPassword = (gcnew System::Windows::Forms::TextBox());
		this->addAdminWorkUsername = (gcnew System::Windows::Forms::TextBox());
		this->addAdminWorkText2 = (gcnew System::Windows::Forms::Label());
		this->addAdminWorkText1 = (gcnew System::Windows::Forms::Label());
		this->addAdminButton = (gcnew System::Windows::Forms::Label());
		this->editAdminWorkPanel = (gcnew System::Windows::Forms::Panel());
		this->editAdminRemoveConfirmPanel = (gcnew System::Windows::Forms::Panel());
		this->editAdminRemoveCancelButton = (gcnew System::Windows::Forms::Label());
		this->editAdminRemoveConfirmButton = (gcnew System::Windows::Forms::Label());
		this->editAdminWorkConfirmedPassword = (gcnew System::Windows::Forms::TextBox());
		this->editAdminWorkPassword = (gcnew System::Windows::Forms::TextBox());
		this->editAdminWorkUsername = (gcnew System::Windows::Forms::TextBox());
		this->editAdminRemoveButton = (gcnew System::Windows::Forms::Button());
		this->editAdminSaveButton = (gcnew System::Windows::Forms::Button());
		this->editAdminText4 = (gcnew System::Windows::Forms::Label());
		this->editAdminText3 = (gcnew System::Windows::Forms::Label());
		this->editAdminText2 = (gcnew System::Windows::Forms::Label());
		this->editAdminComboBox = (gcnew System::Windows::Forms::ComboBox());
		this->editAdminText1 = (gcnew System::Windows::Forms::Label());
		this->settingsLogsTimer = (gcnew System::Windows::Forms::Timer(this->components));
		this->login_panel->SuspendLayout();
		this->sidePanel->SuspendLayout();
		this->mainMenuSidePanel->SuspendLayout();
		this->settingsLogsButton->SuspendLayout();
		this->adminButton->SuspendLayout();
		this->editAddEmployeeButton->SuspendLayout();
		this->markEmployeeButton->SuspendLayout();
		this->markEmployeePanel->SuspendLayout();
		this->markEmployeeBackgroundPanel->SuspendLayout();
		this->markEmployeeActionConfrimPanel->SuspendLayout();
		this->editAddEmployeePanel->SuspendLayout();
		this->addEmployeeWorkPanel->SuspendLayout();
		this->editEmployeeWorkPanel->SuspendLayout();
		this->editEmployeeRemoveConfirmPanel->SuspendLayout();
		this->settingsPanel->SuspendLayout();
		this->settingsLogsPanel->SuspendLayout();
		this->settingsResetAllPanel->SuspendLayout();
		this->settingsResetAllConfrimPanel->SuspendLayout();
		this->settingsThemePanel->SuspendLayout();
		this->settingsAttendancePanel->SuspendLayout();
		this->adminPanel->SuspendLayout();
		this->addAdminWorkPanel->SuspendLayout();
		this->editAdminWorkPanel->SuspendLayout();
		this->editAdminRemoveConfirmPanel->SuspendLayout();
		this->SuspendLayout();
		// 
		// login_username
		// 
		this->login_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->login_username->Location = System::Drawing::Point(103, 18);
		this->login_username->Name = L"login_username";
		this->login_username->Size = System::Drawing::Size(167, 23);
		this->login_username->TabIndex = 0;
		this->login_username->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// login_password
		// 
		this->login_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->login_password->Location = System::Drawing::Point(103, 50);
		this->login_password->Name = L"login_password";
		this->login_password->Size = System::Drawing::Size(167, 23);
		this->login_password->TabIndex = 1;
		this->login_password->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->login_password->UseSystemPasswordChar = true;
		// 
		// login_text1
		// 
		this->login_text1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10));
		this->login_text1->Location = System::Drawing::Point(19, 18);
		this->login_text1->Name = L"login_text1";
		this->login_text1->Size = System::Drawing::Size(78, 23);
		this->login_text1->TabIndex = 2;
		this->login_text1->Text = L"Username:";
		// 
		// login_text2
		// 
		this->login_text2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10));
		this->login_text2->Location = System::Drawing::Point(19, 50);
		this->login_text2->Name = L"login_text2";
		this->login_text2->Size = System::Drawing::Size(78, 23);
		this->login_text2->TabIndex = 3;
		this->login_text2->Text = L"Password:";
		// 
		// login_button
		// 
		this->login_button->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12));
		this->login_button->Location = System::Drawing::Point(17, 79);
		this->login_button->Name = L"login_button";
		this->login_button->Size = System::Drawing::Size(253, 40);
		this->login_button->TabIndex = 4;
		this->login_button->Text = L"Log in";
		this->login_button->UseVisualStyleBackColor = true;
		this->login_button->Click += gcnew System::EventHandler(this, &AttendanceV2::login_button_Click);
		// 
		// login_panel
		// 
		this->login_panel->BackColor = System::Drawing::Color::Tan;
		this->login_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->login_panel->Controls->Add(this->login_password);
		this->login_panel->Controls->Add(this->login_button);
		this->login_panel->Controls->Add(this->login_username);
		this->login_panel->Controls->Add(this->login_text2);
		this->login_panel->Controls->Add(this->login_text1);
		this->login_panel->ForeColor = System::Drawing::SystemColors::ControlText;
		this->login_panel->Location = System::Drawing::Point(61, 404);
		this->login_panel->Name = L"login_panel";
		this->login_panel->Size = System::Drawing::Size(289, 136);
		this->login_panel->TabIndex = 5;
		// 
		// sidePanel
		// 
		this->sidePanel->BackColor = System::Drawing::Color::Moccasin;
		this->sidePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->sidePanel->Controls->Add(this->mainMenuSidePanel);
		this->sidePanel->Controls->Add(this->settingsLogsButton);
		this->sidePanel->Controls->Add(this->adminButton);
		this->sidePanel->Controls->Add(this->editAddEmployeeButton);
		this->sidePanel->Controls->Add(this->markEmployeeButton);
		this->sidePanel->Location = System::Drawing::Point(0, 0);
		this->sidePanel->Name = L"sidePanel";
		this->sidePanel->Size = System::Drawing::Size(31, 370);
		this->sidePanel->TabIndex = 6;
		this->sidePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::openMenu);
		// 
		// mainMenuSidePanel
		// 
		this->mainMenuSidePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->mainMenuSidePanel->BackColor = System::Drawing::Color::Tan;
		this->mainMenuSidePanel->Controls->Add(this->mainMenuSideLabel);
		this->mainMenuSidePanel->Location = System::Drawing::Point(0, -1);
		this->mainMenuSidePanel->Name = L"mainMenuSidePanel";
		this->mainMenuSidePanel->Size = System::Drawing::Size(30, 370);
		this->mainMenuSidePanel->TabIndex = 4;
		this->mainMenuSidePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::openMenu);
		// 
		// mainMenuSideLabel
		// 
		this->mainMenuSideLabel->BackColor = System::Drawing::Color::Tan;
		this->mainMenuSideLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->mainMenuSideLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->mainMenuSideLabel->Location = System::Drawing::Point(7, 43);
		this->mainMenuSideLabel->Name = L"mainMenuSideLabel";
		this->mainMenuSideLabel->Size = System::Drawing::Size(17, 262);
		this->mainMenuSideLabel->TabIndex = 3;
		this->mainMenuSideLabel->Text = L"MAIN & MENU";
		this->mainMenuSideLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->mainMenuSideLabel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::openMenu);
		// 
		// settingsLogsButton
		// 
		this->settingsLogsButton->BackColor = System::Drawing::Color::Tan;
		this->settingsLogsButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->settingsLogsButton->Controls->Add(this->settingsLogsLabel);
		this->settingsLogsButton->Location = System::Drawing::Point(5, 280);
		this->settingsLogsButton->Name = L"settingsLogsButton";
		this->settingsLogsButton->Size = System::Drawing::Size(118, 75);
		this->settingsLogsButton->TabIndex = 1;
		// 
		// settingsLogsLabel
		// 
		this->settingsLogsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->settingsLogsLabel->Cursor = System::Windows::Forms::Cursors::Hand;
		this->settingsLogsLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->settingsLogsLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsLogsLabel->Location = System::Drawing::Point(-2, -2);
		this->settingsLogsLabel->Name = L"settingsLogsLabel";
		this->settingsLogsLabel->Size = System::Drawing::Size(118, 75);
		this->settingsLogsLabel->TabIndex = 1;
		this->settingsLogsLabel->Text = L"Settings - Logs";
		this->settingsLogsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->settingsLogsLabel->Click += gcnew System::EventHandler(this, &AttendanceV2::settingsLogsLabel_Click);
		// 
		// adminButton
		// 
		this->adminButton->BackColor = System::Drawing::Color::Tan;
		this->adminButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->adminButton->Controls->Add(this->adminLabel);
		this->adminButton->Location = System::Drawing::Point(5, 189);
		this->adminButton->Name = L"adminButton";
		this->adminButton->Size = System::Drawing::Size(118, 75);
		this->adminButton->TabIndex = 2;
		// 
		// adminLabel
		// 
		this->adminLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->adminLabel->Cursor = System::Windows::Forms::Cursors::Hand;
		this->adminLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->adminLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->adminLabel->Location = System::Drawing::Point(-2, -2);
		this->adminLabel->Name = L"adminLabel";
		this->adminLabel->Size = System::Drawing::Size(118, 75);
		this->adminLabel->TabIndex = 1;
		this->adminLabel->Text = L"Admins";
		this->adminLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->adminLabel->Click += gcnew System::EventHandler(this, &AttendanceV2::adminLabel_Click);
		// 
		// editAddEmployeeButton
		// 
		this->editAddEmployeeButton->BackColor = System::Drawing::Color::Tan;
		this->editAddEmployeeButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->editAddEmployeeButton->Controls->Add(this->editAddEmployeeLabel);
		this->editAddEmployeeButton->Location = System::Drawing::Point(5, 99);
		this->editAddEmployeeButton->Name = L"editAddEmployeeButton";
		this->editAddEmployeeButton->Size = System::Drawing::Size(118, 75);
		this->editAddEmployeeButton->TabIndex = 1;
		// 
		// editAddEmployeeLabel
		// 
		this->editAddEmployeeLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->editAddEmployeeLabel->Cursor = System::Windows::Forms::Cursors::Hand;
		this->editAddEmployeeLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->editAddEmployeeLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editAddEmployeeLabel->Location = System::Drawing::Point(-2, -2);
		this->editAddEmployeeLabel->Name = L"editAddEmployeeLabel";
		this->editAddEmployeeLabel->Size = System::Drawing::Size(118, 75);
		this->editAddEmployeeLabel->TabIndex = 1;
		this->editAddEmployeeLabel->Text = L"Edit / Add Employee";
		this->editAddEmployeeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->editAddEmployeeLabel->Click += gcnew System::EventHandler(this, &AttendanceV2::editAddEmployeeLabel_Click);
		// 
		// markEmployeeButton
		// 
		this->markEmployeeButton->BackColor = System::Drawing::Color::Tan;
		this->markEmployeeButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->markEmployeeButton->Controls->Add(this->markEmployeeLabel);
		this->markEmployeeButton->Location = System::Drawing::Point(5, 10);
		this->markEmployeeButton->Name = L"markEmployeeButton";
		this->markEmployeeButton->Size = System::Drawing::Size(118, 75);
		this->markEmployeeButton->TabIndex = 0;
		// 
		// markEmployeeLabel
		// 
		this->markEmployeeLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->markEmployeeLabel->Cursor = System::Windows::Forms::Cursors::Hand;
		this->markEmployeeLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->markEmployeeLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->markEmployeeLabel->Location = System::Drawing::Point(0, 0);
		this->markEmployeeLabel->Name = L"markEmployeeLabel";
		this->markEmployeeLabel->Size = System::Drawing::Size(118, 75);
		this->markEmployeeLabel->TabIndex = 0;
		this->markEmployeeLabel->Text = L"Mark Employee";
		this->markEmployeeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->markEmployeeLabel->Click += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeLabel_Click);
		// 
		// sideMenuTimer
		// 
		this->sideMenuTimer->Interval = 15;
		this->sideMenuTimer->Tick += gcnew System::EventHandler(this, &AttendanceV2::sideMenuTimer_Tick);
		// 
		// markEmployeePanel
		// 
		this->markEmployeePanel->BackColor = System::Drawing::Color::Sienna;
		this->markEmployeePanel->Controls->Add(this->markEmployeeBackgroundPanel);
		this->markEmployeePanel->Location = System::Drawing::Point(553, 316);
		this->markEmployeePanel->Margin = System::Windows::Forms::Padding(2);
		this->markEmployeePanel->Name = L"markEmployeePanel";
		this->markEmployeePanel->Size = System::Drawing::Size(496, 370);
		this->markEmployeePanel->TabIndex = 7;
		this->markEmployeePanel->Visible = false;
		this->markEmployeePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// markEmployeeBackgroundPanel
		// 
		this->markEmployeeBackgroundPanel->BackColor = System::Drawing::Color::Tan;
		this->markEmployeeBackgroundPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeActionConfrimPanel);
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeMarkAbsentButton);
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeMarkLateButton);
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeAttendanceLimit);
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeText2);
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeListView);
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeText1);
		this->markEmployeeBackgroundPanel->Controls->Add(this->markEmployeeComboBox);
		this->markEmployeeBackgroundPanel->Location = System::Drawing::Point(12, 8);
		this->markEmployeeBackgroundPanel->Margin = System::Windows::Forms::Padding(2);
		this->markEmployeeBackgroundPanel->Name = L"markEmployeeBackgroundPanel";
		this->markEmployeeBackgroundPanel->Size = System::Drawing::Size(475, 349);
		this->markEmployeeBackgroundPanel->TabIndex = 1;
		this->markEmployeeBackgroundPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// markEmployeeActionConfrimPanel
		// 
		this->markEmployeeActionConfrimPanel->BackColor = System::Drawing::Color::Moccasin;
		this->markEmployeeActionConfrimPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->markEmployeeActionConfrimPanel->Controls->Add(this->markEmployeeActionCancelButton);
		this->markEmployeeActionConfrimPanel->Controls->Add(this->markEmployeeActionConfirmButton);
		this->markEmployeeActionConfrimPanel->Location = System::Drawing::Point(22, 83);
		this->markEmployeeActionConfrimPanel->Margin = System::Windows::Forms::Padding(2);
		this->markEmployeeActionConfrimPanel->Name = L"markEmployeeActionConfrimPanel";
		this->markEmployeeActionConfrimPanel->Size = System::Drawing::Size(430, 68);
		this->markEmployeeActionConfrimPanel->TabIndex = 6;
		// 
		// markEmployeeActionCancelButton
		// 
		this->markEmployeeActionCancelButton->BackColor = System::Drawing::Color::Red;
		this->markEmployeeActionCancelButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->markEmployeeActionCancelButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->markEmployeeActionCancelButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->markEmployeeActionCancelButton->ForeColor = System::Drawing::Color::White;
		this->markEmployeeActionCancelButton->Location = System::Drawing::Point(221, 6);
		this->markEmployeeActionCancelButton->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->markEmployeeActionCancelButton->Name = L"markEmployeeActionCancelButton";
		this->markEmployeeActionCancelButton->Size = System::Drawing::Size(198, 54);
		this->markEmployeeActionCancelButton->TabIndex = 3;
		this->markEmployeeActionCancelButton->Text = L"Cancel";
		this->markEmployeeActionCancelButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->markEmployeeActionCancelButton->Click += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeActionCancelButton_Click);
		// 
		// markEmployeeActionConfirmButton
		// 
		this->markEmployeeActionConfirmButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		this->markEmployeeActionConfirmButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->markEmployeeActionConfirmButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->markEmployeeActionConfirmButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->markEmployeeActionConfirmButton->ForeColor = System::Drawing::Color::White;
		this->markEmployeeActionConfirmButton->Location = System::Drawing::Point(10, 6);
		this->markEmployeeActionConfirmButton->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->markEmployeeActionConfirmButton->Name = L"markEmployeeActionConfirmButton";
		this->markEmployeeActionConfirmButton->Size = System::Drawing::Size(199, 54);
		this->markEmployeeActionConfirmButton->TabIndex = 2;
		this->markEmployeeActionConfirmButton->Text = L"Confirm <action>";
		this->markEmployeeActionConfirmButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->markEmployeeActionConfirmButton->Click += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeActionConfirmButton_Click);
		// 
		// markEmployeeMarkAbsentButton
		// 
		this->markEmployeeMarkAbsentButton->BackColor = System::Drawing::Color::Moccasin;
		this->markEmployeeMarkAbsentButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->markEmployeeMarkAbsentButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->markEmployeeMarkAbsentButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->markEmployeeMarkAbsentButton->Location = System::Drawing::Point(243, 99);
		this->markEmployeeMarkAbsentButton->Margin = System::Windows::Forms::Padding(2);
		this->markEmployeeMarkAbsentButton->Name = L"markEmployeeMarkAbsentButton";
		this->markEmployeeMarkAbsentButton->Size = System::Drawing::Size(206, 47);
		this->markEmployeeMarkAbsentButton->TabIndex = 9;
		this->markEmployeeMarkAbsentButton->Text = L"Mark Absent";
		this->markEmployeeMarkAbsentButton->UseVisualStyleBackColor = false;
		this->markEmployeeMarkAbsentButton->Click += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeMarkAbsentButton_Click);
		// 
		// markEmployeeMarkLateButton
		// 
		this->markEmployeeMarkLateButton->BackColor = System::Drawing::Color::Moccasin;
		this->markEmployeeMarkLateButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->markEmployeeMarkLateButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->markEmployeeMarkLateButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->markEmployeeMarkLateButton->Location = System::Drawing::Point(24, 99);
		this->markEmployeeMarkLateButton->Margin = System::Windows::Forms::Padding(2);
		this->markEmployeeMarkLateButton->Name = L"markEmployeeMarkLateButton";
		this->markEmployeeMarkLateButton->Size = System::Drawing::Size(206, 47);
		this->markEmployeeMarkLateButton->TabIndex = 8;
		this->markEmployeeMarkLateButton->Text = L"Mark Late";
		this->markEmployeeMarkLateButton->UseVisualStyleBackColor = false;
		this->markEmployeeMarkLateButton->Click += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeMarkLateButton_Click);
		// 
		// markEmployeeAttendanceLimit
		// 
		this->markEmployeeAttendanceLimit->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->markEmployeeAttendanceLimit->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
		this->markEmployeeAttendanceLimit->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->markEmployeeAttendanceLimit->Location = System::Drawing::Point(355, 154);
		this->markEmployeeAttendanceLimit->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->markEmployeeAttendanceLimit->Name = L"markEmployeeAttendanceLimit";
		this->markEmployeeAttendanceLimit->Size = System::Drawing::Size(94, 31);
		this->markEmployeeAttendanceLimit->TabIndex = 7;
		this->markEmployeeAttendanceLimit->Text = L"0.00";
		this->markEmployeeAttendanceLimit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// markEmployeeText2
		// 
		this->markEmployeeText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
		this->markEmployeeText2->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->markEmployeeText2->Location = System::Drawing::Point(26, 156);
		this->markEmployeeText2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->markEmployeeText2->Name = L"markEmployeeText2";
		this->markEmployeeText2->Size = System::Drawing::Size(323, 31);
		this->markEmployeeText2->TabIndex = 5;
		this->markEmployeeText2->Text = L"Employees Over Attendance Limit of:";
		this->markEmployeeText2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->markEmployeeText2->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// markEmployeeListView
		// 
		this->markEmployeeListView->BackColor = System::Drawing::Color::Moccasin;
		this->markEmployeeListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
			this->employeeName,
				this->employeeID, this->attendanceCount
		});
		this->markEmployeeListView->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->markEmployeeListView->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->markEmployeeListView->FullRowSelect = true;
		this->markEmployeeListView->GridLines = true;
		this->markEmployeeListView->HideSelection = false;
		this->markEmployeeListView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem1 });
		this->markEmployeeListView->Location = System::Drawing::Point(24, 189);
		this->markEmployeeListView->Margin = System::Windows::Forms::Padding(2);
		this->markEmployeeListView->MultiSelect = false;
		this->markEmployeeListView->Name = L"markEmployeeListView";
		this->markEmployeeListView->Scrollable = false;
		this->markEmployeeListView->Size = System::Drawing::Size(428, 147);
		this->markEmployeeListView->TabIndex = 4;
		this->markEmployeeListView->UseCompatibleStateImageBehavior = false;
		this->markEmployeeListView->View = System::Windows::Forms::View::Details;
		this->markEmployeeListView->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// employeeName
		// 
		this->employeeName->Text = L"Employee Name";
		this->employeeName->Width = 260;
		// 
		// employeeID
		// 
		this->employeeID->Text = L"ID";
		this->employeeID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->employeeID->Width = 100;
		// 
		// attendanceCount
		// 
		this->attendanceCount->Text = L"Points";
		this->attendanceCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->attendanceCount->Width = 65;
		// 
		// markEmployeeText1
		// 
		this->markEmployeeText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
		this->markEmployeeText1->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->markEmployeeText1->Location = System::Drawing::Point(52, 19);
		this->markEmployeeText1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->markEmployeeText1->Name = L"markEmployeeText1";
		this->markEmployeeText1->Size = System::Drawing::Size(362, 31);
		this->markEmployeeText1->TabIndex = 1;
		this->markEmployeeText1->Text = L"Choose an Employee to Mark:";
		this->markEmployeeText1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->markEmployeeText1->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// markEmployeeComboBox
		// 
		this->markEmployeeComboBox->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 13, System::Drawing::FontStyle::Bold));
		this->markEmployeeComboBox->FormattingEnabled = true;
		this->markEmployeeComboBox->Location = System::Drawing::Point(55, 55);
		this->markEmployeeComboBox->Margin = System::Windows::Forms::Padding(2);
		this->markEmployeeComboBox->Name = L"markEmployeeComboBox";
		this->markEmployeeComboBox->Size = System::Drawing::Size(361, 27);
		this->markEmployeeComboBox->TabIndex = 0;
		this->markEmployeeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeComboBox_SelectedIndexChanged);
		this->markEmployeeComboBox->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// ignore_2
		// 
		this->ignore_2->BackColor = System::Drawing::Color::Moccasin;
		this->ignore_2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->ignore_2->Cursor = System::Windows::Forms::Cursors::Hand;
		this->ignore_2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->ignore_2->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->ignore_2->Location = System::Drawing::Point(10, 470);
		this->ignore_2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->ignore_2->Name = L"ignore_2";
		this->ignore_2->Size = System::Drawing::Size(32, 54);
		this->ignore_2->TabIndex = 3;
		this->ignore_2->Text = L"Mark Absent";
		this->ignore_2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->ignore_2->Click += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeMarkAbsentButton_Click);
		this->ignore_2->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// ignore_1
		// 
		this->ignore_1->BackColor = System::Drawing::Color::Moccasin;
		this->ignore_1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->ignore_1->Cursor = System::Windows::Forms::Cursors::Hand;
		this->ignore_1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->ignore_1->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->ignore_1->Location = System::Drawing::Point(10, 421);
		this->ignore_1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->ignore_1->Name = L"ignore_1";
		this->ignore_1->Size = System::Drawing::Size(32, 20);
		this->ignore_1->TabIndex = 2;
		this->ignore_1->Text = L"Mark Late";
		this->ignore_1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->ignore_1->Click += gcnew System::EventHandler(this, &AttendanceV2::markEmployeeMarkLateButton_Click);
		this->ignore_1->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// editAddEmployeePanel
		// 
		this->editAddEmployeePanel->BackColor = System::Drawing::Color::DarkSeaGreen;
		this->editAddEmployeePanel->Controls->Add(this->editEmployeeButton);
		this->editAddEmployeePanel->Controls->Add(this->addEmployeeWorkPanel);
		this->editAddEmployeePanel->Controls->Add(this->addEmployeeButton);
		this->editAddEmployeePanel->Controls->Add(this->editEmployeeWorkPanel);
		this->editAddEmployeePanel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editAddEmployeePanel->Location = System::Drawing::Point(394, 444);
		this->editAddEmployeePanel->Margin = System::Windows::Forms::Padding(2);
		this->editAddEmployeePanel->Name = L"editAddEmployeePanel";
		this->editAddEmployeePanel->Size = System::Drawing::Size(496, 370);
		this->editAddEmployeePanel->TabIndex = 8;
		this->editAddEmployeePanel->Visible = false;
		this->editAddEmployeePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// editEmployeeButton
		// 
		this->editEmployeeButton->BackColor = System::Drawing::Color::SeaGreen;
		this->editEmployeeButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->editEmployeeButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->editEmployeeButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeButton->ForeColor = System::Drawing::Color::White;
		this->editEmployeeButton->Location = System::Drawing::Point(250, 6);
		this->editEmployeeButton->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editEmployeeButton->Name = L"editEmployeeButton";
		this->editEmployeeButton->Size = System::Drawing::Size(236, 47);
		this->editEmployeeButton->TabIndex = 1;
		this->editEmployeeButton->Text = L"Edit Employee";
		this->editEmployeeButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->editEmployeeButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeButton_Click);
		this->editEmployeeButton->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// addEmployeeWorkPanel
		// 
		this->addEmployeeWorkPanel->BackColor = System::Drawing::Color::Tan;
		this->addEmployeeWorkPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkSaveButton);
		this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkEmployeeID);
		this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkLastName);
		this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkFirstName);
		this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkText3);
		this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkText2);
		this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkText1);
		this->addEmployeeWorkPanel->Location = System::Drawing::Point(492, 40);
		this->addEmployeeWorkPanel->Margin = System::Windows::Forms::Padding(2);
		this->addEmployeeWorkPanel->Name = L"addEmployeeWorkPanel";
		this->addEmployeeWorkPanel->Size = System::Drawing::Size(479, 304);
		this->addEmployeeWorkPanel->TabIndex = 2;
		this->addEmployeeWorkPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// addEmployeeWorkSaveButton
		// 
		this->addEmployeeWorkSaveButton->BackColor = System::Drawing::Color::Moccasin;
		this->addEmployeeWorkSaveButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addEmployeeWorkSaveButton->Location = System::Drawing::Point(34, 219);
		this->addEmployeeWorkSaveButton->Margin = System::Windows::Forms::Padding(2);
		this->addEmployeeWorkSaveButton->Name = L"addEmployeeWorkSaveButton";
		this->addEmployeeWorkSaveButton->Size = System::Drawing::Size(410, 48);
		this->addEmployeeWorkSaveButton->TabIndex = 7;
		this->addEmployeeWorkSaveButton->Text = L"Save Employee";
		this->addEmployeeWorkSaveButton->UseVisualStyleBackColor = false;
		this->addEmployeeWorkSaveButton->Click += gcnew System::EventHandler(this, &AttendanceV2::addEmployeeWorkSaveButton_Click);
		// 
		// addEmployeeWorkEmployeeID
		// 
		this->addEmployeeWorkEmployeeID->BackColor = System::Drawing::Color::Moccasin;
		this->addEmployeeWorkEmployeeID->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
		this->addEmployeeWorkEmployeeID->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->addEmployeeWorkEmployeeID->Location = System::Drawing::Point(196, 151);
		this->addEmployeeWorkEmployeeID->Margin = System::Windows::Forms::Padding(2);
		this->addEmployeeWorkEmployeeID->Name = L"addEmployeeWorkEmployeeID";
		this->addEmployeeWorkEmployeeID->Size = System::Drawing::Size(247, 29);
		this->addEmployeeWorkEmployeeID->TabIndex = 6;
		this->addEmployeeWorkEmployeeID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// addEmployeeWorkLastName
		// 
		this->addEmployeeWorkLastName->BackColor = System::Drawing::Color::Moccasin;
		this->addEmployeeWorkLastName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
		this->addEmployeeWorkLastName->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->addEmployeeWorkLastName->Location = System::Drawing::Point(196, 99);
		this->addEmployeeWorkLastName->Margin = System::Windows::Forms::Padding(2);
		this->addEmployeeWorkLastName->Name = L"addEmployeeWorkLastName";
		this->addEmployeeWorkLastName->Size = System::Drawing::Size(247, 29);
		this->addEmployeeWorkLastName->TabIndex = 5;
		this->addEmployeeWorkLastName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// addEmployeeWorkFirstName
		// 
		this->addEmployeeWorkFirstName->BackColor = System::Drawing::Color::Moccasin;
		this->addEmployeeWorkFirstName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
		this->addEmployeeWorkFirstName->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->addEmployeeWorkFirstName->Location = System::Drawing::Point(196, 44);
		this->addEmployeeWorkFirstName->Margin = System::Windows::Forms::Padding(2);
		this->addEmployeeWorkFirstName->Name = L"addEmployeeWorkFirstName";
		this->addEmployeeWorkFirstName->Size = System::Drawing::Size(247, 29);
		this->addEmployeeWorkFirstName->TabIndex = 4;
		this->addEmployeeWorkFirstName->Text = L"testing";
		this->addEmployeeWorkFirstName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// addEmployeeWorkText3
		// 
		this->addEmployeeWorkText3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addEmployeeWorkText3->Location = System::Drawing::Point(36, 151);
		this->addEmployeeWorkText3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addEmployeeWorkText3->Name = L"addEmployeeWorkText3";
		this->addEmployeeWorkText3->Size = System::Drawing::Size(120, 27);
		this->addEmployeeWorkText3->TabIndex = 2;
		this->addEmployeeWorkText3->Text = L"Employee ID:";
		this->addEmployeeWorkText3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// addEmployeeWorkText2
		// 
		this->addEmployeeWorkText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addEmployeeWorkText2->Location = System::Drawing::Point(44, 99);
		this->addEmployeeWorkText2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addEmployeeWorkText2->Name = L"addEmployeeWorkText2";
		this->addEmployeeWorkText2->Size = System::Drawing::Size(113, 27);
		this->addEmployeeWorkText2->TabIndex = 1;
		this->addEmployeeWorkText2->Text = L"Last Name:";
		this->addEmployeeWorkText2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// addEmployeeWorkText1
		// 
		this->addEmployeeWorkText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addEmployeeWorkText1->Location = System::Drawing::Point(44, 44);
		this->addEmployeeWorkText1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addEmployeeWorkText1->Name = L"addEmployeeWorkText1";
		this->addEmployeeWorkText1->Size = System::Drawing::Size(113, 27);
		this->addEmployeeWorkText1->TabIndex = 0;
		this->addEmployeeWorkText1->Text = L"First Name:";
		this->addEmployeeWorkText1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// addEmployeeButton
		// 
		this->addEmployeeButton->BackColor = System::Drawing::Color::DarkOliveGreen;
		this->addEmployeeButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->addEmployeeButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->addEmployeeButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addEmployeeButton->ForeColor = System::Drawing::Color::White;
		this->addEmployeeButton->Location = System::Drawing::Point(9, 6);
		this->addEmployeeButton->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addEmployeeButton->Name = L"addEmployeeButton";
		this->addEmployeeButton->Size = System::Drawing::Size(236, 47);
		this->addEmployeeButton->TabIndex = 0;
		this->addEmployeeButton->Text = L"Add Employee";
		this->addEmployeeButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->addEmployeeButton->Click += gcnew System::EventHandler(this, &AttendanceV2::addEmployeeButton_Click);
		this->addEmployeeButton->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// editEmployeeWorkPanel
		// 
		this->editEmployeeWorkPanel->BackColor = System::Drawing::Color::SeaGreen;
		this->editEmployeeWorkPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeRemoveConfirmPanel);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkCurrentPoints);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkEmployeeID);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkLastName);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkFirstName);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkText5);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkRemoveEmployee);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkSaveButton);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkText4);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkText3);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkText2);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeComboBox);
		this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkText1);
		this->editEmployeeWorkPanel->ForeColor = System::Drawing::Color::Black;
		this->editEmployeeWorkPanel->Location = System::Drawing::Point(9, 59);
		this->editEmployeeWorkPanel->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeWorkPanel->Name = L"editEmployeeWorkPanel";
		this->editEmployeeWorkPanel->Size = System::Drawing::Size(479, 304);
		this->editEmployeeWorkPanel->TabIndex = 3;
		this->editEmployeeWorkPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// editEmployeeRemoveConfirmPanel
		// 
		this->editEmployeeRemoveConfirmPanel->BackColor = System::Drawing::Color::Maroon;
		this->editEmployeeRemoveConfirmPanel->Controls->Add(this->editEmployeeRemoveCancelButton);
		this->editEmployeeRemoveConfirmPanel->Controls->Add(this->editEmployeeRemoveConfirmButton);
		this->editEmployeeRemoveConfirmPanel->Location = System::Drawing::Point(14, 226);
		this->editEmployeeRemoveConfirmPanel->Name = L"editEmployeeRemoveConfirmPanel";
		this->editEmployeeRemoveConfirmPanel->Size = System::Drawing::Size(448, 64);
		this->editEmployeeRemoveConfirmPanel->TabIndex = 9;
		// 
		// editEmployeeRemoveCancelButton
		// 
		this->editEmployeeRemoveCancelButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		this->editEmployeeRemoveCancelButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->editEmployeeRemoveCancelButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeRemoveCancelButton->ForeColor = System::Drawing::Color::White;
		this->editEmployeeRemoveCancelButton->Location = System::Drawing::Point(4, 3);
		this->editEmployeeRemoveCancelButton->Name = L"editEmployeeRemoveCancelButton";
		this->editEmployeeRemoveCancelButton->Size = System::Drawing::Size(218, 57);
		this->editEmployeeRemoveCancelButton->TabIndex = 1;
		this->editEmployeeRemoveCancelButton->Text = L"Cancel";
		this->editEmployeeRemoveCancelButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->editEmployeeRemoveCancelButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeRemoveCancelButton_Click);
		// 
		// editEmployeeRemoveConfirmButton
		// 
		this->editEmployeeRemoveConfirmButton->BackColor = System::Drawing::Color::Red;
		this->editEmployeeRemoveConfirmButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->editEmployeeRemoveConfirmButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeRemoveConfirmButton->ForeColor = System::Drawing::Color::White;
		this->editEmployeeRemoveConfirmButton->Location = System::Drawing::Point(227, 3);
		this->editEmployeeRemoveConfirmButton->Name = L"editEmployeeRemoveConfirmButton";
		this->editEmployeeRemoveConfirmButton->Size = System::Drawing::Size(218, 57);
		this->editEmployeeRemoveConfirmButton->TabIndex = 0;
		this->editEmployeeRemoveConfirmButton->Text = L"Remove Employee";
		this->editEmployeeRemoveConfirmButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->editEmployeeRemoveConfirmButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeRemoveConfirmButton_Click);
		// 
		// editEmployeeWorkCurrentPoints
		// 
		this->editEmployeeWorkCurrentPoints->BackColor = System::Drawing::Color::DarkSeaGreen;
		this->editEmployeeWorkCurrentPoints->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkCurrentPoints->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editEmployeeWorkCurrentPoints->Location = System::Drawing::Point(212, 186);
		this->editEmployeeWorkCurrentPoints->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeWorkCurrentPoints->Name = L"editEmployeeWorkCurrentPoints";
		this->editEmployeeWorkCurrentPoints->Size = System::Drawing::Size(231, 26);
		this->editEmployeeWorkCurrentPoints->TabIndex = 6;
		this->editEmployeeWorkCurrentPoints->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// editEmployeeWorkEmployeeID
		// 
		this->editEmployeeWorkEmployeeID->BackColor = System::Drawing::Color::DarkSeaGreen;
		this->editEmployeeWorkEmployeeID->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkEmployeeID->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editEmployeeWorkEmployeeID->Location = System::Drawing::Point(212, 148);
		this->editEmployeeWorkEmployeeID->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeWorkEmployeeID->Name = L"editEmployeeWorkEmployeeID";
		this->editEmployeeWorkEmployeeID->Size = System::Drawing::Size(231, 26);
		this->editEmployeeWorkEmployeeID->TabIndex = 5;
		this->editEmployeeWorkEmployeeID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// editEmployeeWorkLastName
		// 
		this->editEmployeeWorkLastName->BackColor = System::Drawing::Color::DarkSeaGreen;
		this->editEmployeeWorkLastName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkLastName->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editEmployeeWorkLastName->Location = System::Drawing::Point(212, 111);
		this->editEmployeeWorkLastName->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeWorkLastName->Name = L"editEmployeeWorkLastName";
		this->editEmployeeWorkLastName->Size = System::Drawing::Size(231, 26);
		this->editEmployeeWorkLastName->TabIndex = 4;
		this->editEmployeeWorkLastName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// editEmployeeWorkFirstName
		// 
		this->editEmployeeWorkFirstName->BackColor = System::Drawing::Color::DarkSeaGreen;
		this->editEmployeeWorkFirstName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkFirstName->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editEmployeeWorkFirstName->Location = System::Drawing::Point(212, 75);
		this->editEmployeeWorkFirstName->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeWorkFirstName->Name = L"editEmployeeWorkFirstName";
		this->editEmployeeWorkFirstName->Size = System::Drawing::Size(231, 26);
		this->editEmployeeWorkFirstName->TabIndex = 3;
		this->editEmployeeWorkFirstName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// editEmployeeWorkText5
		// 
		this->editEmployeeWorkText5->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkText5->ForeColor = System::Drawing::Color::MintCream;
		this->editEmployeeWorkText5->Location = System::Drawing::Point(29, 185);
		this->editEmployeeWorkText5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editEmployeeWorkText5->Name = L"editEmployeeWorkText5";
		this->editEmployeeWorkText5->Size = System::Drawing::Size(135, 24);
		this->editEmployeeWorkText5->TabIndex = 8;
		this->editEmployeeWorkText5->Text = L"Current Points:";
		this->editEmployeeWorkText5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// editEmployeeWorkRemoveEmployee
		// 
		this->editEmployeeWorkRemoveEmployee->BackColor = System::Drawing::Color::Red;
		this->editEmployeeWorkRemoveEmployee->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkRemoveEmployee->ForeColor = System::Drawing::Color::White;
		this->editEmployeeWorkRemoveEmployee->Location = System::Drawing::Point(32, 226);
		this->editEmployeeWorkRemoveEmployee->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeWorkRemoveEmployee->Name = L"editEmployeeWorkRemoveEmployee";
		this->editEmployeeWorkRemoveEmployee->Size = System::Drawing::Size(124, 42);
		this->editEmployeeWorkRemoveEmployee->TabIndex = 8;
		this->editEmployeeWorkRemoveEmployee->Text = L"Remove Employee";
		this->editEmployeeWorkRemoveEmployee->UseVisualStyleBackColor = false;
		this->editEmployeeWorkRemoveEmployee->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeWorkRemoveEmployee_Click);
		// 
		// editEmployeeWorkSaveButton
		// 
		this->editEmployeeWorkSaveButton->BackColor = System::Drawing::Color::Moccasin;
		this->editEmployeeWorkSaveButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkSaveButton->Location = System::Drawing::Point(162, 226);
		this->editEmployeeWorkSaveButton->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeWorkSaveButton->Name = L"editEmployeeWorkSaveButton";
		this->editEmployeeWorkSaveButton->Size = System::Drawing::Size(300, 42);
		this->editEmployeeWorkSaveButton->TabIndex = 7;
		this->editEmployeeWorkSaveButton->Text = L"Save Employee";
		this->editEmployeeWorkSaveButton->UseVisualStyleBackColor = false;
		this->editEmployeeWorkSaveButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeWorkSaveButton_Click);
		// 
		// editEmployeeWorkText4
		// 
		this->editEmployeeWorkText4->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkText4->ForeColor = System::Drawing::Color::MintCream;
		this->editEmployeeWorkText4->Location = System::Drawing::Point(36, 147);
		this->editEmployeeWorkText4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editEmployeeWorkText4->Name = L"editEmployeeWorkText4";
		this->editEmployeeWorkText4->Size = System::Drawing::Size(128, 24);
		this->editEmployeeWorkText4->TabIndex = 5;
		this->editEmployeeWorkText4->Text = L"Employee ID:";
		this->editEmployeeWorkText4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// editEmployeeWorkText3
		// 
		this->editEmployeeWorkText3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkText3->ForeColor = System::Drawing::Color::MintCream;
		this->editEmployeeWorkText3->Location = System::Drawing::Point(50, 110);
		this->editEmployeeWorkText3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editEmployeeWorkText3->Name = L"editEmployeeWorkText3";
		this->editEmployeeWorkText3->Size = System::Drawing::Size(114, 24);
		this->editEmployeeWorkText3->TabIndex = 4;
		this->editEmployeeWorkText3->Text = L"Last Name:";
		this->editEmployeeWorkText3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// editEmployeeWorkText2
		// 
		this->editEmployeeWorkText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkText2->ForeColor = System::Drawing::Color::MintCream;
		this->editEmployeeWorkText2->Location = System::Drawing::Point(50, 74);
		this->editEmployeeWorkText2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editEmployeeWorkText2->Name = L"editEmployeeWorkText2";
		this->editEmployeeWorkText2->Size = System::Drawing::Size(114, 24);
		this->editEmployeeWorkText2->TabIndex = 3;
		this->editEmployeeWorkText2->Text = L"First Name:";
		this->editEmployeeWorkText2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// editEmployeeComboBox
		// 
		this->editEmployeeComboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
		this->editEmployeeComboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
		this->editEmployeeComboBox->BackColor = System::Drawing::Color::DarkSeaGreen;
		this->editEmployeeComboBox->DropDownHeight = 160;
		this->editEmployeeComboBox->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 13, System::Drawing::FontStyle::Bold));
		this->editEmployeeComboBox->FormattingEnabled = true;
		this->editEmployeeComboBox->IntegralHeight = false;
		this->editEmployeeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"test", L"testing" });
		this->editEmployeeComboBox->Location = System::Drawing::Point(42, 33);
		this->editEmployeeComboBox->Margin = System::Windows::Forms::Padding(2);
		this->editEmployeeComboBox->Name = L"editEmployeeComboBox";
		this->editEmployeeComboBox->Size = System::Drawing::Size(402, 27);
		this->editEmployeeComboBox->Sorted = true;
		this->editEmployeeComboBox->TabIndex = 2;
		this->editEmployeeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AttendanceV2::comboBox1_SelectedIndexChanged);
		// 
		// editEmployeeWorkText1
		// 
		this->editEmployeeWorkText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editEmployeeWorkText1->ForeColor = System::Drawing::Color::MintCream;
		this->editEmployeeWorkText1->Location = System::Drawing::Point(148, 0);
		this->editEmployeeWorkText1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editEmployeeWorkText1->Name = L"editEmployeeWorkText1";
		this->editEmployeeWorkText1->Size = System::Drawing::Size(188, 31);
		this->editEmployeeWorkText1->TabIndex = 1;
		this->editEmployeeWorkText1->Text = L"Choose an Employee:";
		this->editEmployeeWorkText1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// settingsPanel
		// 
		this->settingsPanel->BackColor = System::Drawing::Color::Sienna;
		this->settingsPanel->Controls->Add(this->settingsLogsPanel);
		this->settingsPanel->Controls->Add(this->settingsResetAllPanel);
		this->settingsPanel->Controls->Add(this->settingsThemePanel);
		this->settingsPanel->Controls->Add(this->settingsAttendancePanel);
		this->settingsPanel->Location = System::Drawing::Point(91, 585);
		this->settingsPanel->Margin = System::Windows::Forms::Padding(2);
		this->settingsPanel->Name = L"settingsPanel";
		this->settingsPanel->Size = System::Drawing::Size(496, 370);
		this->settingsPanel->TabIndex = 10;
		this->settingsPanel->Visible = false;
		this->settingsPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// settingsLogsPanel
		// 
		this->settingsLogsPanel->BackColor = System::Drawing::Color::Tan;
		this->settingsLogsPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->settingsLogsPanel->Controls->Add(this->settingsExpandLogsButton);
		this->settingsLogsPanel->Controls->Add(this->settingsLogsListView);
		this->settingsLogsPanel->Controls->Add(this->settingsText1);
		this->settingsLogsPanel->Location = System::Drawing::Point(7, 6);
		this->settingsLogsPanel->Margin = System::Windows::Forms::Padding(2);
		this->settingsLogsPanel->Name = L"settingsLogsPanel";
		this->settingsLogsPanel->Size = System::Drawing::Size(480, 140);
		this->settingsLogsPanel->TabIndex = 2;
		this->settingsLogsPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// settingsExpandLogsButton
		// 
		this->settingsExpandLogsButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9));
		this->settingsExpandLogsButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsExpandLogsButton->Location = System::Drawing::Point(386, 2);
		this->settingsExpandLogsButton->Name = L"settingsExpandLogsButton";
		this->settingsExpandLogsButton->Size = System::Drawing::Size(75, 22);
		this->settingsExpandLogsButton->TabIndex = 6;
		this->settingsExpandLogsButton->Text = L"Expand";
		this->settingsExpandLogsButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		this->settingsExpandLogsButton->UseVisualStyleBackColor = true;
		this->settingsExpandLogsButton->Click += gcnew System::EventHandler(this, &AttendanceV2::settingsExpandLogButton_Click);
		// 
		// settingsLogsListView
		// 
		this->settingsLogsListView->BackColor = System::Drawing::Color::Moccasin;
		this->settingsLogsListView->Cursor = System::Windows::Forms::Cursors::Arrow;
		this->settingsLogsListView->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsLogsListView->Location = System::Drawing::Point(6, 25);
		this->settingsLogsListView->Margin = System::Windows::Forms::Padding(2);
		this->settingsLogsListView->Name = L"settingsLogsListView";
		this->settingsLogsListView->ReadOnly = true;
		this->settingsLogsListView->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
		this->settingsLogsListView->Size = System::Drawing::Size(464, 105);
		this->settingsLogsListView->TabIndex = 5;
		this->settingsLogsListView->Text = L"";
		this->settingsLogsListView->WordWrap = false;
		this->settingsLogsListView->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// settingsText1
		// 
		this->settingsText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
		this->settingsText1->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText1->Location = System::Drawing::Point(-1, 0);
		this->settingsText1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText1->Name = L"settingsText1";
		this->settingsText1->Size = System::Drawing::Size(465, 24);
		this->settingsText1->TabIndex = 4;
		this->settingsText1->Text = L"Logs:";
		this->settingsText1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// settingsResetAllPanel
		// 
		this->settingsResetAllPanel->BackColor = System::Drawing::Color::Tan;
		this->settingsResetAllPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->settingsResetAllPanel->Controls->Add(this->settingsResetAllConfrimPanel);
		this->settingsResetAllPanel->Controls->Add(this->settingsResetAllButton);
		this->settingsResetAllPanel->Controls->Add(this->settingsText7);
		this->settingsResetAllPanel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsResetAllPanel->Location = System::Drawing::Point(256, 264);
		this->settingsResetAllPanel->Margin = System::Windows::Forms::Padding(2);
		this->settingsResetAllPanel->Name = L"settingsResetAllPanel";
		this->settingsResetAllPanel->Size = System::Drawing::Size(231, 94);
		this->settingsResetAllPanel->TabIndex = 3;
		// 
		// settingsResetAllConfrimPanel
		// 
		this->settingsResetAllConfrimPanel->Controls->Add(this->settingsResetAllCancelButton);
		this->settingsResetAllConfrimPanel->Controls->Add(this->settingsResetAllConfirmButton);
		this->settingsResetAllConfrimPanel->Controls->Add(this->settingsText8);
		this->settingsResetAllConfrimPanel->Controls->Add(this->settingsResetAllPasswordInput);
		this->settingsResetAllConfrimPanel->Location = System::Drawing::Point(3, 2);
		this->settingsResetAllConfrimPanel->Name = L"settingsResetAllConfrimPanel";
		this->settingsResetAllConfrimPanel->Size = System::Drawing::Size(221, 85);
		this->settingsResetAllConfrimPanel->TabIndex = 8;
		// 
		// settingsResetAllCancelButton
		// 
		this->settingsResetAllCancelButton->BackColor = System::Drawing::Color::Moccasin;
		this->settingsResetAllCancelButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9, System::Drawing::FontStyle::Bold));
		this->settingsResetAllCancelButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsResetAllCancelButton->Location = System::Drawing::Point(115, 53);
		this->settingsResetAllCancelButton->Margin = System::Windows::Forms::Padding(2);
		this->settingsResetAllCancelButton->Name = L"settingsResetAllCancelButton";
		this->settingsResetAllCancelButton->Size = System::Drawing::Size(94, 22);
		this->settingsResetAllCancelButton->TabIndex = 11;
		this->settingsResetAllCancelButton->Text = L"Cancel";
		this->settingsResetAllCancelButton->UseVisualStyleBackColor = false;
		this->settingsResetAllCancelButton->Click += gcnew System::EventHandler(this, &AttendanceV2::settingsResetAllCancelButton_Click);
		// 
		// settingsResetAllConfirmButton
		// 
		this->settingsResetAllConfirmButton->BackColor = System::Drawing::Color::Moccasin;
		this->settingsResetAllConfirmButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9, System::Drawing::FontStyle::Bold));
		this->settingsResetAllConfirmButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsResetAllConfirmButton->Location = System::Drawing::Point(10, 53);
		this->settingsResetAllConfirmButton->Margin = System::Windows::Forms::Padding(2);
		this->settingsResetAllConfirmButton->Name = L"settingsResetAllConfirmButton";
		this->settingsResetAllConfirmButton->Size = System::Drawing::Size(94, 22);
		this->settingsResetAllConfirmButton->TabIndex = 10;
		this->settingsResetAllConfirmButton->Text = L"Uninstall";
		this->settingsResetAllConfirmButton->UseVisualStyleBackColor = false;
		this->settingsResetAllConfirmButton->Click += gcnew System::EventHandler(this, &AttendanceV2::settingsResetAllConfirmButton_Click);
		// 
		// settingsText8
		// 
		this->settingsText8->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
		this->settingsText8->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText8->Location = System::Drawing::Point(7, 4);
		this->settingsText8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText8->Name = L"settingsText8";
		this->settingsText8->Size = System::Drawing::Size(212, 20);
		this->settingsText8->TabIndex = 4;
		this->settingsText8->Text = L"Type in your password";
		this->settingsText8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// settingsResetAllPasswordInput
		// 
		this->settingsResetAllPasswordInput->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->settingsResetAllPasswordInput->Location = System::Drawing::Point(10, 26);
		this->settingsResetAllPasswordInput->Name = L"settingsResetAllPasswordInput";
		this->settingsResetAllPasswordInput->Size = System::Drawing::Size(199, 23);
		this->settingsResetAllPasswordInput->TabIndex = 0;
		this->settingsResetAllPasswordInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->settingsResetAllPasswordInput->UseSystemPasswordChar = true;
		// 
		// settingsResetAllButton
		// 
		this->settingsResetAllButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9));
		this->settingsResetAllButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsResetAllButton->Location = System::Drawing::Point(7, 42);
		this->settingsResetAllButton->Name = L"settingsResetAllButton";
		this->settingsResetAllButton->Size = System::Drawing::Size(214, 41);
		this->settingsResetAllButton->TabIndex = 7;
		this->settingsResetAllButton->Text = L"RESET PROGRAM";
		this->settingsResetAllButton->UseVisualStyleBackColor = true;
		this->settingsResetAllButton->Click += gcnew System::EventHandler(this, &AttendanceV2::settingsResetAllButton_Click);
		// 
		// settingsText7
		// 
		this->settingsText7->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9));
		this->settingsText7->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText7->Location = System::Drawing::Point(4, 8);
		this->settingsText7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText7->Name = L"settingsText7";
		this->settingsText7->Size = System::Drawing::Size(221, 31);
		this->settingsText7->TabIndex = 4;
		this->settingsText7->Text = L"Uninstall/Reset all files: Removes all files from computer";
		this->settingsText7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// settingsThemePanel
		// 
		this->settingsThemePanel->BackColor = System::Drawing::Color::Tan;
		this->settingsThemePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->settingsThemePanel->Controls->Add(this->settingsThemeGrayButton);
		this->settingsThemePanel->Controls->Add(this->settingsThemeRedButton);
		this->settingsThemePanel->Controls->Add(this->settingsThemeGreenButton);
		this->settingsThemePanel->Controls->Add(this->settingsThemeDefaultButton);
		this->settingsThemePanel->Controls->Add(this->settingsText6);
		this->settingsThemePanel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsThemePanel->Location = System::Drawing::Point(256, 157);
		this->settingsThemePanel->Margin = System::Windows::Forms::Padding(2);
		this->settingsThemePanel->Name = L"settingsThemePanel";
		this->settingsThemePanel->Size = System::Drawing::Size(231, 95);
		this->settingsThemePanel->TabIndex = 1;
		this->settingsThemePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// settingsThemeGrayButton
		// 
		this->settingsThemeGrayButton->AutoSize = true;
		this->settingsThemeGrayButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 8, System::Drawing::FontStyle::Bold));
		this->settingsThemeGrayButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsThemeGrayButton->Location = System::Drawing::Point(122, 64);
		this->settingsThemeGrayButton->Name = L"settingsThemeGrayButton";
		this->settingsThemeGrayButton->Size = System::Drawing::Size(53, 18);
		this->settingsThemeGrayButton->TabIndex = 7;
		this->settingsThemeGrayButton->Text = L"Gray";
		this->settingsThemeGrayButton->UseVisualStyleBackColor = true;
		this->settingsThemeGrayButton->CheckedChanged += gcnew System::EventHandler(this, &AttendanceV2::settingsThemeButtonChanged);
		// 
		// settingsThemeRedButton
		// 
		this->settingsThemeRedButton->AutoSize = true;
		this->settingsThemeRedButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 8, System::Drawing::FontStyle::Bold));
		this->settingsThemeRedButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsThemeRedButton->Location = System::Drawing::Point(60, 64);
		this->settingsThemeRedButton->Name = L"settingsThemeRedButton";
		this->settingsThemeRedButton->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		this->settingsThemeRedButton->Size = System::Drawing::Size(47, 18);
		this->settingsThemeRedButton->TabIndex = 6;
		this->settingsThemeRedButton->Text = L"Red";
		this->settingsThemeRedButton->UseVisualStyleBackColor = true;
		this->settingsThemeRedButton->CheckedChanged += gcnew System::EventHandler(this, &AttendanceV2::settingsThemeButtonChanged);
		// 
		// settingsThemeGreenButton
		// 
		this->settingsThemeGreenButton->AutoSize = true;
		this->settingsThemeGreenButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 8, System::Drawing::FontStyle::Bold));
		this->settingsThemeGreenButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsThemeGreenButton->Location = System::Drawing::Point(122, 40);
		this->settingsThemeGreenButton->Name = L"settingsThemeGreenButton";
		this->settingsThemeGreenButton->Size = System::Drawing::Size(60, 18);
		this->settingsThemeGreenButton->TabIndex = 5;
		this->settingsThemeGreenButton->Text = L"Green";
		this->settingsThemeGreenButton->UseVisualStyleBackColor = true;
		this->settingsThemeGreenButton->CheckedChanged += gcnew System::EventHandler(this, &AttendanceV2::settingsThemeButtonChanged);
		// 
		// settingsThemeDefaultButton
		// 
		this->settingsThemeDefaultButton->AutoSize = true;
		this->settingsThemeDefaultButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 8, System::Drawing::FontStyle::Bold));
		this->settingsThemeDefaultButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsThemeDefaultButton->Location = System::Drawing::Point(40, 40);
		this->settingsThemeDefaultButton->Name = L"settingsThemeDefaultButton";
		this->settingsThemeDefaultButton->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		this->settingsThemeDefaultButton->Size = System::Drawing::Size(67, 18);
		this->settingsThemeDefaultButton->TabIndex = 4;
		this->settingsThemeDefaultButton->Text = L"Default";
		this->settingsThemeDefaultButton->UseVisualStyleBackColor = true;
		this->settingsThemeDefaultButton->CheckedChanged += gcnew System::EventHandler(this, &AttendanceV2::settingsThemeButtonChanged);
		// 
		// settingsText6
		// 
		this->settingsText6->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
		this->settingsText6->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText6->Location = System::Drawing::Point(3, 3);
		this->settingsText6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText6->Name = L"settingsText6";
		this->settingsText6->Size = System::Drawing::Size(221, 31);
		this->settingsText6->TabIndex = 3;
		this->settingsText6->Text = L"Theme:";
		this->settingsText6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// settingsAttendancePanel
		// 
		this->settingsAttendancePanel->BackColor = System::Drawing::Color::Tan;
		this->settingsAttendancePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->settingsAttendancePanel->Controls->Add(this->settingsSaveAttendanceButton);
		this->settingsAttendancePanel->Controls->Add(this->settingsText5);
		this->settingsAttendancePanel->Controls->Add(this->settingsAbsentPoints);
		this->settingsAttendancePanel->Controls->Add(this->settingsText4);
		this->settingsAttendancePanel->Controls->Add(this->settingsLatePoints);
		this->settingsAttendancePanel->Controls->Add(this->settingsText3);
		this->settingsAttendancePanel->Controls->Add(this->settingsAttendanceLimit);
		this->settingsAttendancePanel->Controls->Add(this->settingsText2);
		this->settingsAttendancePanel->Location = System::Drawing::Point(7, 157);
		this->settingsAttendancePanel->Margin = System::Windows::Forms::Padding(2);
		this->settingsAttendancePanel->Name = L"settingsAttendancePanel";
		this->settingsAttendancePanel->Size = System::Drawing::Size(236, 201);
		this->settingsAttendancePanel->TabIndex = 0;
		this->settingsAttendancePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// settingsSaveAttendanceButton
		// 
		this->settingsSaveAttendanceButton->BackColor = System::Drawing::Color::Moccasin;
		this->settingsSaveAttendanceButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9, System::Drawing::FontStyle::Bold));
		this->settingsSaveAttendanceButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsSaveAttendanceButton->Location = System::Drawing::Point(15, 144);
		this->settingsSaveAttendanceButton->Margin = System::Windows::Forms::Padding(2);
		this->settingsSaveAttendanceButton->Name = L"settingsSaveAttendanceButton";
		this->settingsSaveAttendanceButton->Size = System::Drawing::Size(206, 40);
		this->settingsSaveAttendanceButton->TabIndex = 9;
		this->settingsSaveAttendanceButton->Text = L"Save Attendance Points Setings";
		this->settingsSaveAttendanceButton->UseVisualStyleBackColor = false;
		this->settingsSaveAttendanceButton->Click += gcnew System::EventHandler(this, &AttendanceV2::settingsSaveAttendanceButton_Click);
		// 
		// settingsText5
		// 
		this->settingsText5->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->settingsText5->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText5->Location = System::Drawing::Point(13, 99);
		this->settingsText5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText5->Name = L"settingsText5";
		this->settingsText5->Size = System::Drawing::Size(131, 40);
		this->settingsText5->TabIndex = 8;
		this->settingsText5->Text = L"Absent Points:";
		this->settingsText5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// settingsAbsentPoints
		// 
		this->settingsAbsentPoints->BackColor = System::Drawing::Color::Moccasin;
		this->settingsAbsentPoints->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->settingsAbsentPoints->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsAbsentPoints->Location = System::Drawing::Point(151, 109);
		this->settingsAbsentPoints->Margin = System::Windows::Forms::Padding(2);
		this->settingsAbsentPoints->Name = L"settingsAbsentPoints";
		this->settingsAbsentPoints->Size = System::Drawing::Size(70, 23);
		this->settingsAbsentPoints->TabIndex = 7;
		this->settingsAbsentPoints->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// settingsText4
		// 
		this->settingsText4->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->settingsText4->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText4->Location = System::Drawing::Point(13, 70);
		this->settingsText4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText4->Name = L"settingsText4";
		this->settingsText4->Size = System::Drawing::Size(131, 40);
		this->settingsText4->TabIndex = 6;
		this->settingsText4->Text = L"Late Points:";
		this->settingsText4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// settingsLatePoints
		// 
		this->settingsLatePoints->BackColor = System::Drawing::Color::Moccasin;
		this->settingsLatePoints->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->settingsLatePoints->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsLatePoints->Location = System::Drawing::Point(151, 81);
		this->settingsLatePoints->Margin = System::Windows::Forms::Padding(2);
		this->settingsLatePoints->Name = L"settingsLatePoints";
		this->settingsLatePoints->Size = System::Drawing::Size(70, 23);
		this->settingsLatePoints->TabIndex = 5;
		this->settingsLatePoints->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// settingsText3
		// 
		this->settingsText3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->settingsText3->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText3->Location = System::Drawing::Point(-3, 39);
		this->settingsText3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText3->Name = L"settingsText3";
		this->settingsText3->Size = System::Drawing::Size(147, 46);
		this->settingsText3->TabIndex = 4;
		this->settingsText3->Text = L"Attendance Limit:";
		this->settingsText3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// settingsAttendanceLimit
		// 
		this->settingsAttendanceLimit->BackColor = System::Drawing::Color::Moccasin;
		this->settingsAttendanceLimit->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10, System::Drawing::FontStyle::Bold));
		this->settingsAttendanceLimit->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsAttendanceLimit->Location = System::Drawing::Point(151, 52);
		this->settingsAttendanceLimit->Margin = System::Windows::Forms::Padding(2);
		this->settingsAttendanceLimit->Name = L"settingsAttendanceLimit";
		this->settingsAttendanceLimit->Size = System::Drawing::Size(70, 23);
		this->settingsAttendanceLimit->TabIndex = 3;
		this->settingsAttendanceLimit->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// settingsText2
		// 
		this->settingsText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
		this->settingsText2->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->settingsText2->Location = System::Drawing::Point(5, -2);
		this->settingsText2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->settingsText2->Name = L"settingsText2";
		this->settingsText2->Size = System::Drawing::Size(221, 49);
		this->settingsText2->TabIndex = 2;
		this->settingsText2->Text = L"Attendance Points Settings";
		this->settingsText2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// adminPanel
		// 
		this->adminPanel->BackColor = System::Drawing::Color::Sienna;
		this->adminPanel->Controls->Add(this->editAdminButton);
		this->adminPanel->Controls->Add(this->addAdminWorkPanel);
		this->adminPanel->Controls->Add(this->addAdminButton);
		this->adminPanel->Controls->Add(this->editAdminWorkPanel);
		this->adminPanel->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->adminPanel->Location = System::Drawing::Point(36, 6);
		this->adminPanel->Margin = System::Windows::Forms::Padding(2);
		this->adminPanel->Name = L"adminPanel";
		this->adminPanel->Size = System::Drawing::Size(496, 370);
		this->adminPanel->TabIndex = 11;
		this->adminPanel->Visible = false;
		this->adminPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// editAdminButton
		// 
		this->editAdminButton->BackColor = System::Drawing::Color::Tan;
		this->editAdminButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->editAdminButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->editAdminButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminButton->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editAdminButton->Location = System::Drawing::Point(250, 6);
		this->editAdminButton->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editAdminButton->Name = L"editAdminButton";
		this->editAdminButton->Size = System::Drawing::Size(236, 47);
		this->editAdminButton->TabIndex = 1;
		this->editAdminButton->Text = L"Edit Admin";
		this->editAdminButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->editAdminButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editAdminButton_Click);
		this->editAdminButton->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// addAdminWorkPanel
		// 
		this->addAdminWorkPanel->BackColor = System::Drawing::Color::Tan;
		this->addAdminWorkPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->addAdminWorkPanel->Controls->Add(this->addAdminWorkConfirmedPassword);
		this->addAdminWorkPanel->Controls->Add(this->addAdminWorkText3);
		this->addAdminWorkPanel->Controls->Add(this->addAdminSaveButton);
		this->addAdminWorkPanel->Controls->Add(this->addAdminWorkPassword);
		this->addAdminWorkPanel->Controls->Add(this->addAdminWorkUsername);
		this->addAdminWorkPanel->Controls->Add(this->addAdminWorkText2);
		this->addAdminWorkPanel->Controls->Add(this->addAdminWorkText1);
		this->addAdminWorkPanel->Location = System::Drawing::Point(400, 361);
		this->addAdminWorkPanel->Margin = System::Windows::Forms::Padding(2);
		this->addAdminWorkPanel->Name = L"addAdminWorkPanel";
		this->addAdminWorkPanel->Size = System::Drawing::Size(479, 304);
		this->addAdminWorkPanel->TabIndex = 2;
		this->addAdminWorkPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// addAdminWorkConfirmedPassword
		// 
		this->addAdminWorkConfirmedPassword->BackColor = System::Drawing::Color::Moccasin;
		this->addAdminWorkConfirmedPassword->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
		this->addAdminWorkConfirmedPassword->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->addAdminWorkConfirmedPassword->Location = System::Drawing::Point(196, 150);
		this->addAdminWorkConfirmedPassword->Margin = System::Windows::Forms::Padding(2);
		this->addAdminWorkConfirmedPassword->Name = L"addAdminWorkConfirmedPassword";
		this->addAdminWorkConfirmedPassword->Size = System::Drawing::Size(247, 29);
		this->addAdminWorkConfirmedPassword->TabIndex = 6;
		this->addAdminWorkConfirmedPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// addAdminWorkText3
		// 
		this->addAdminWorkText3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addAdminWorkText3->Location = System::Drawing::Point(2, 152);
		this->addAdminWorkText3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addAdminWorkText3->Name = L"addAdminWorkText3";
		this->addAdminWorkText3->Size = System::Drawing::Size(178, 27);
		this->addAdminWorkText3->TabIndex = 8;
		this->addAdminWorkText3->Text = L"Confrim Password:";
		this->addAdminWorkText3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// addAdminSaveButton
		// 
		this->addAdminSaveButton->BackColor = System::Drawing::Color::Moccasin;
		this->addAdminSaveButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addAdminSaveButton->Location = System::Drawing::Point(33, 216);
		this->addAdminSaveButton->Margin = System::Windows::Forms::Padding(2);
		this->addAdminSaveButton->Name = L"addAdminSaveButton";
		this->addAdminSaveButton->Size = System::Drawing::Size(410, 48);
		this->addAdminSaveButton->TabIndex = 7;
		this->addAdminSaveButton->Text = L"Save Admin";
		this->addAdminSaveButton->UseVisualStyleBackColor = false;
		this->addAdminSaveButton->Click += gcnew System::EventHandler(this, &AttendanceV2::addAdminSaveButton_Click);
		// 
		// addAdminWorkPassword
		// 
		this->addAdminWorkPassword->BackColor = System::Drawing::Color::Moccasin;
		this->addAdminWorkPassword->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
		this->addAdminWorkPassword->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->addAdminWorkPassword->Location = System::Drawing::Point(196, 100);
		this->addAdminWorkPassword->Margin = System::Windows::Forms::Padding(2);
		this->addAdminWorkPassword->Name = L"addAdminWorkPassword";
		this->addAdminWorkPassword->Size = System::Drawing::Size(247, 29);
		this->addAdminWorkPassword->TabIndex = 5;
		this->addAdminWorkPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// addAdminWorkUsername
		// 
		this->addAdminWorkUsername->BackColor = System::Drawing::Color::Moccasin;
		this->addAdminWorkUsername->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
		this->addAdminWorkUsername->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->addAdminWorkUsername->Location = System::Drawing::Point(196, 49);
		this->addAdminWorkUsername->Margin = System::Windows::Forms::Padding(2);
		this->addAdminWorkUsername->Name = L"addAdminWorkUsername";
		this->addAdminWorkUsername->Size = System::Drawing::Size(247, 29);
		this->addAdminWorkUsername->TabIndex = 4;
		this->addAdminWorkUsername->Text = L"testing";
		this->addAdminWorkUsername->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// addAdminWorkText2
		// 
		this->addAdminWorkText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addAdminWorkText2->Location = System::Drawing::Point(67, 102);
		this->addAdminWorkText2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addAdminWorkText2->Name = L"addAdminWorkText2";
		this->addAdminWorkText2->Size = System::Drawing::Size(113, 27);
		this->addAdminWorkText2->TabIndex = 1;
		this->addAdminWorkText2->Text = L"Password:";
		this->addAdminWorkText2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// addAdminWorkText1
		// 
		this->addAdminWorkText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addAdminWorkText1->Location = System::Drawing::Point(67, 51);
		this->addAdminWorkText1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addAdminWorkText1->Name = L"addAdminWorkText1";
		this->addAdminWorkText1->Size = System::Drawing::Size(113, 27);
		this->addAdminWorkText1->TabIndex = 0;
		this->addAdminWorkText1->Text = L"Username:";
		this->addAdminWorkText1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// addAdminButton
		// 
		this->addAdminButton->BackColor = System::Drawing::Color::DarkGoldenrod;
		this->addAdminButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->addAdminButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->addAdminButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->addAdminButton->ForeColor = System::Drawing::Color::White;
		this->addAdminButton->Location = System::Drawing::Point(9, 6);
		this->addAdminButton->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->addAdminButton->Name = L"addAdminButton";
		this->addAdminButton->Size = System::Drawing::Size(236, 47);
		this->addAdminButton->TabIndex = 0;
		this->addAdminButton->Text = L"Add Admin";
		this->addAdminButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->addAdminButton->Click += gcnew System::EventHandler(this, &AttendanceV2::addAdminButton_Click);
		this->addAdminButton->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
		// 
		// editAdminWorkPanel
		// 
		this->editAdminWorkPanel->BackColor = System::Drawing::Color::Tan;
		this->editAdminWorkPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->editAdminWorkPanel->Controls->Add(this->editAdminRemoveConfirmPanel);
		this->editAdminWorkPanel->Controls->Add(this->editAdminWorkConfirmedPassword);
		this->editAdminWorkPanel->Controls->Add(this->editAdminWorkPassword);
		this->editAdminWorkPanel->Controls->Add(this->editAdminWorkUsername);
		this->editAdminWorkPanel->Controls->Add(this->editAdminRemoveButton);
		this->editAdminWorkPanel->Controls->Add(this->editAdminSaveButton);
		this->editAdminWorkPanel->Controls->Add(this->editAdminText4);
		this->editAdminWorkPanel->Controls->Add(this->editAdminText3);
		this->editAdminWorkPanel->Controls->Add(this->editAdminText2);
		this->editAdminWorkPanel->Controls->Add(this->editAdminComboBox);
		this->editAdminWorkPanel->Controls->Add(this->editAdminText1);
		this->editAdminWorkPanel->Location = System::Drawing::Point(9, 55);
		this->editAdminWorkPanel->Margin = System::Windows::Forms::Padding(2);
		this->editAdminWorkPanel->Name = L"editAdminWorkPanel";
		this->editAdminWorkPanel->Size = System::Drawing::Size(479, 304);
		this->editAdminWorkPanel->TabIndex = 3;
		// 
		// editAdminRemoveConfirmPanel
		// 
		this->editAdminRemoveConfirmPanel->BackColor = System::Drawing::Color::Moccasin;
		this->editAdminRemoveConfirmPanel->Controls->Add(this->editAdminRemoveCancelButton);
		this->editAdminRemoveConfirmPanel->Controls->Add(this->editAdminRemoveConfirmButton);
		this->editAdminRemoveConfirmPanel->Location = System::Drawing::Point(14, 218);
		this->editAdminRemoveConfirmPanel->Name = L"editAdminRemoveConfirmPanel";
		this->editAdminRemoveConfirmPanel->Size = System::Drawing::Size(448, 64);
		this->editAdminRemoveConfirmPanel->TabIndex = 9;
		// 
		// editAdminRemoveCancelButton
		// 
		this->editAdminRemoveCancelButton->BackColor = System::Drawing::Color::Red;
		this->editAdminRemoveCancelButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->editAdminRemoveCancelButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminRemoveCancelButton->ForeColor = System::Drawing::Color::White;
		this->editAdminRemoveCancelButton->Location = System::Drawing::Point(4, 3);
		this->editAdminRemoveCancelButton->Name = L"editAdminRemoveCancelButton";
		this->editAdminRemoveCancelButton->Size = System::Drawing::Size(218, 57);
		this->editAdminRemoveCancelButton->TabIndex = 1;
		this->editAdminRemoveCancelButton->Text = L"Cancel";
		this->editAdminRemoveCancelButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->editAdminRemoveCancelButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editAdminRemoveCancelButton_Click);
		// 
		// editAdminRemoveConfirmButton
		// 
		this->editAdminRemoveConfirmButton->BackColor = System::Drawing::Color::MediumSeaGreen;
		this->editAdminRemoveConfirmButton->Cursor = System::Windows::Forms::Cursors::Hand;
		this->editAdminRemoveConfirmButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminRemoveConfirmButton->ForeColor = System::Drawing::Color::White;
		this->editAdminRemoveConfirmButton->Location = System::Drawing::Point(227, 3);
		this->editAdminRemoveConfirmButton->Name = L"editAdminRemoveConfirmButton";
		this->editAdminRemoveConfirmButton->Size = System::Drawing::Size(218, 57);
		this->editAdminRemoveConfirmButton->TabIndex = 0;
		this->editAdminRemoveConfirmButton->Text = L"Remove Employee";
		this->editAdminRemoveConfirmButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->editAdminRemoveConfirmButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editAdminRemoveConfirmButton_Click);
		// 
		// editAdminWorkConfirmedPassword
		// 
		this->editAdminWorkConfirmedPassword->BackColor = System::Drawing::Color::Moccasin;
		this->editAdminWorkConfirmedPassword->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminWorkConfirmedPassword->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editAdminWorkConfirmedPassword->Location = System::Drawing::Point(213, 172);
		this->editAdminWorkConfirmedPassword->Margin = System::Windows::Forms::Padding(2);
		this->editAdminWorkConfirmedPassword->Name = L"editAdminWorkConfirmedPassword";
		this->editAdminWorkConfirmedPassword->Size = System::Drawing::Size(231, 26);
		this->editAdminWorkConfirmedPassword->TabIndex = 5;
		this->editAdminWorkConfirmedPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// editAdminWorkPassword
		// 
		this->editAdminWorkPassword->BackColor = System::Drawing::Color::Moccasin;
		this->editAdminWorkPassword->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminWorkPassword->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editAdminWorkPassword->Location = System::Drawing::Point(213, 131);
		this->editAdminWorkPassword->Margin = System::Windows::Forms::Padding(2);
		this->editAdminWorkPassword->Name = L"editAdminWorkPassword";
		this->editAdminWorkPassword->Size = System::Drawing::Size(231, 26);
		this->editAdminWorkPassword->TabIndex = 4;
		this->editAdminWorkPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// editAdminWorkUsername
		// 
		this->editAdminWorkUsername->BackColor = System::Drawing::Color::Moccasin;
		this->editAdminWorkUsername->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminWorkUsername->ForeColor = System::Drawing::Color::DarkSlateGray;
		this->editAdminWorkUsername->Location = System::Drawing::Point(213, 89);
		this->editAdminWorkUsername->Margin = System::Windows::Forms::Padding(2);
		this->editAdminWorkUsername->Name = L"editAdminWorkUsername";
		this->editAdminWorkUsername->Size = System::Drawing::Size(231, 26);
		this->editAdminWorkUsername->TabIndex = 3;
		this->editAdminWorkUsername->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// editAdminRemoveButton
		// 
		this->editAdminRemoveButton->BackColor = System::Drawing::Color::Red;
		this->editAdminRemoveButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9, System::Drawing::FontStyle::Bold));
		this->editAdminRemoveButton->ForeColor = System::Drawing::Color::White;
		this->editAdminRemoveButton->Location = System::Drawing::Point(32, 226);
		this->editAdminRemoveButton->Margin = System::Windows::Forms::Padding(2);
		this->editAdminRemoveButton->Name = L"editAdminRemoveButton";
		this->editAdminRemoveButton->Size = System::Drawing::Size(124, 42);
		this->editAdminRemoveButton->TabIndex = 8;
		this->editAdminRemoveButton->Text = L"Remove Admin";
		this->editAdminRemoveButton->UseVisualStyleBackColor = false;
		this->editAdminRemoveButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editAdminRemoveButton_Click);
		// 
		// editAdminSaveButton
		// 
		this->editAdminSaveButton->BackColor = System::Drawing::Color::Moccasin;
		this->editAdminSaveButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminSaveButton->Location = System::Drawing::Point(162, 226);
		this->editAdminSaveButton->Margin = System::Windows::Forms::Padding(2);
		this->editAdminSaveButton->Name = L"editAdminSaveButton";
		this->editAdminSaveButton->Size = System::Drawing::Size(300, 42);
		this->editAdminSaveButton->TabIndex = 7;
		this->editAdminSaveButton->Text = L"Save Admin";
		this->editAdminSaveButton->UseVisualStyleBackColor = false;
		this->editAdminSaveButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editAdminSaveButton_Click);
		// 
		// editAdminText4
		// 
		this->editAdminText4->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminText4->Location = System::Drawing::Point(18, 171);
		this->editAdminText4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editAdminText4->Name = L"editAdminText4";
		this->editAdminText4->Size = System::Drawing::Size(173, 26);
		this->editAdminText4->TabIndex = 5;
		this->editAdminText4->Text = L"Confirm Password:";
		this->editAdminText4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// editAdminText3
		// 
		this->editAdminText3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminText3->Location = System::Drawing::Point(77, 131);
		this->editAdminText3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editAdminText3->Name = L"editAdminText3";
		this->editAdminText3->Size = System::Drawing::Size(114, 24);
		this->editAdminText3->TabIndex = 4;
		this->editAdminText3->Text = L"Password:";
		this->editAdminText3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// editAdminText2
		// 
		this->editAdminText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminText2->Location = System::Drawing::Point(77, 89);
		this->editAdminText2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editAdminText2->Name = L"editAdminText2";
		this->editAdminText2->Size = System::Drawing::Size(114, 24);
		this->editAdminText2->TabIndex = 3;
		this->editAdminText2->Text = L"Username:";
		this->editAdminText2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// editAdminComboBox
		// 
		this->editAdminComboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
		this->editAdminComboBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
		this->editAdminComboBox->BackColor = System::Drawing::Color::Moccasin;
		this->editAdminComboBox->DropDownHeight = 160;
		this->editAdminComboBox->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 13, System::Drawing::FontStyle::Bold));
		this->editAdminComboBox->FormattingEnabled = true;
		this->editAdminComboBox->IntegralHeight = false;
		this->editAdminComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"test", L"testing" });
		this->editAdminComboBox->Location = System::Drawing::Point(41, 40);
		this->editAdminComboBox->Margin = System::Windows::Forms::Padding(2);
		this->editAdminComboBox->Name = L"editAdminComboBox";
		this->editAdminComboBox->Size = System::Drawing::Size(402, 27);
		this->editAdminComboBox->Sorted = true;
		this->editAdminComboBox->TabIndex = 2;
		this->editAdminComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AttendanceV2::editAdminComboBox_SelectedIndexChanged);
		// 
		// editAdminText1
		// 
		this->editAdminText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
		this->editAdminText1->Location = System::Drawing::Point(145, 5);
		this->editAdminText1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->editAdminText1->Name = L"editAdminText1";
		this->editAdminText1->Size = System::Drawing::Size(188, 31);
		this->editAdminText1->TabIndex = 1;
		this->editAdminText1->Text = L"Choose an Admin";
		this->editAdminText1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// settingsLogsTimer
		// 
		this->settingsLogsTimer->Interval = 10;
		this->settingsLogsTimer->Tick += gcnew System::EventHandler(this, &AttendanceV2::settingsLogsTimer_Tick);
		// 
		// AttendanceV2
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Sienna;
		this->ClientSize = System::Drawing::Size(662, 687);
		this->Controls->Add(this->sidePanel);
		this->Controls->Add(this->markEmployeePanel);
		this->Controls->Add(this->adminPanel);
		this->Controls->Add(this->editAddEmployeePanel);
		this->Controls->Add(this->settingsPanel);
		this->Controls->Add(this->login_panel);
		this->Controls->Add(this->ignore_2);
		this->Controls->Add(this->ignore_1);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->MaximizeBox = false;
		this->Name = L"AttendanceV2";
		this->Text = L"Attendance V2";
		this->Load += gcnew System::EventHandler(this, &AttendanceV2::AttendanceV2_Load);
		this->login_panel->ResumeLayout(false);
		this->login_panel->PerformLayout();
		this->sidePanel->ResumeLayout(false);
		this->mainMenuSidePanel->ResumeLayout(false);
		this->settingsLogsButton->ResumeLayout(false);
		this->adminButton->ResumeLayout(false);
		this->editAddEmployeeButton->ResumeLayout(false);
		this->markEmployeeButton->ResumeLayout(false);
		this->markEmployeePanel->ResumeLayout(false);
		this->markEmployeeBackgroundPanel->ResumeLayout(false);
		this->markEmployeeActionConfrimPanel->ResumeLayout(false);
		this->editAddEmployeePanel->ResumeLayout(false);
		this->addEmployeeWorkPanel->ResumeLayout(false);
		this->addEmployeeWorkPanel->PerformLayout();
		this->editEmployeeWorkPanel->ResumeLayout(false);
		this->editEmployeeWorkPanel->PerformLayout();
		this->editEmployeeRemoveConfirmPanel->ResumeLayout(false);
		this->settingsPanel->ResumeLayout(false);
		this->settingsLogsPanel->ResumeLayout(false);
		this->settingsResetAllPanel->ResumeLayout(false);
		this->settingsResetAllConfrimPanel->ResumeLayout(false);
		this->settingsResetAllConfrimPanel->PerformLayout();
		this->settingsThemePanel->ResumeLayout(false);
		this->settingsThemePanel->PerformLayout();
		this->settingsAttendancePanel->ResumeLayout(false);
		this->settingsAttendancePanel->PerformLayout();
		this->adminPanel->ResumeLayout(false);
		this->addAdminWorkPanel->ResumeLayout(false);
		this->addAdminWorkPanel->PerformLayout();
		this->editAdminWorkPanel->ResumeLayout(false);
		this->editAdminWorkPanel->PerformLayout();
		this->editAdminRemoveConfirmPanel->ResumeLayout(false);
		this->ResumeLayout(false);

	}
#pragma endregion


// --------------------------,
// HELPER FUNCTIONS:          \
// -----------------------------------------------------------------------------------------------------------------------------------//
	// --------------------------------------------------//||																		  //
	// Transforming from string -> string^ and backwards //||																		  //
	string toString(String^ str) {						 //||																		  //
		return marshal_as<string>(str);					 //||																		  //
	}													 //||																		  //
														 //||																		  //
	String^ toHandle(string str) {						 //||																		  //
		return marshal_as<String^>(str);				 //||																		  //
	}													 //||																		  //
	//---------------------------------------------------//||																		  //
																																	  //
	// Changing a double to a string using precision 2																				  //
	string doubleToString(double input) {																							  //
		ostringstream stream;																										  //
		stream << fixed << setprecision(2) << input; // Set decimal places to 2														  //
		return stream.str();																										  //
	}																																  //																					  //
																																	  //
																																	  //
	// Getting the current date in format 																							  //
	string getCurrentDateTime() {																									  //
		time_t now = time(0);																										  //
		tm* ltm = localtime(&now);																									  //
																																	  //
		stringstream ss;																											  //
		ss << "[" << setfill('0') << setw(2) << (ltm->tm_mon + 1) << "/"                           // Month (01-12)					  //
			<< setfill('0') << setw(2) << ltm->tm_mday << "/"                                      // Day (01-31)					  //
			<< (1900 + ltm->tm_year) << " - "                                                      // Year (YYYY)					  //
			<< setfill('0') << setw(2) << (ltm->tm_hour % 12 == 0 ? 12 : ltm->tm_hour % 12) << ":" // Hour (12-hour format)			  //
			<< setfill('0') << setw(2) << ltm->tm_min                                              // Minutes (00-59)				  //
			<< (ltm->tm_hour >= 12 ? "PM" : "AM") << "]";                                          // AM/PM							  //
																																	  //
		return ss.str();																											  //
	}																																  //																							  //
																																	  //
																																	  //
	// Writing to log with format of <date><user>:<information>																		  //
	void writeToLog(string message) {																								  //
		string tempFile = "temp_log.txt";																							  //
																																	  //
		// Open temp file for writing																								  //
		ofstream outFile(tempFile);																									  //
		if (!outFile) {																												  //
			MessageBox::Show("CANNOT MAKE TEMP LOG FILE.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);					  //
			return;																													  //
		}																															  //
																																	  //
		// Write the new log entry first																							  //
		outFile << getCurrentDateTime() << " " << loggedInAdmin << ": " << message << endl;											  //
																																	  //
		// Open the original log file and append its contents																		  //
		ifstream inFile(logsFile);																									  //
		if (!inFile) {																												  //
			MessageBox::Show("CANNOT OPEN LOG FILE.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);						  //
			return;																													  //
		}																															  //
																																	  //
		// Puts contents into outfile WITHOUT touching memory since this file will get long eventually 								  //
		outFile << inFile.rdbuf();  																								  //
		inFile.close();																												  //
		outFile.close();																											  //
																																	  //
		// Replace original file with the temporary file																			  //
		remove(logsFile.c_str());																									  //
		if (rename(tempFile.c_str(), logsFile.c_str()) != 0) {																		  //
			MessageBox::Show("CANNOT RENAME FILE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);							  //
			return;																													  //
		}																															  //
	}																																  //																						  //
																																	  //
																																	  //
	// Set Theme according to saved theme names, then repaint panels 																  //
	void setTheme() {																												  //
		if (settings_theme == "default") {																							  //
			backColor = Color::Sienna;																								  //
			secondBackColor = Color::Tan;																							  //
			thirdBackColor = Color::Moccasin;																						  //
			textColor = Color::DarkSlateGray;																						  //
			buttonPushedBackColor = Color::DarkGoldenrod;																			  //
			buttonPushedForeColor = Color::White;																					  //
			rePaintAllPanels();																										  //
			return;																													  //
		}																															  //
		if (settings_theme == "red") {																								  //
			backColor = Color::DarkRed;																								  //
			secondBackColor = Color::LightSalmon;																					  //
			thirdBackColor = Color::White;																							  //
			textColor = Color::Black;																								  //
			buttonPushedBackColor = Color::IndianRed;																				  //
			buttonPushedForeColor = Color::White;																					  //
			rePaintAllPanels();																										  //
			return;																													  //
		}																															  //
		if (settings_theme == "green") {																							  //
			backColor = Color::DarkSeaGreen;																						  //
			secondBackColor = Color::SeaGreen;																						  //
			thirdBackColor = Color::DarkSeaGreen;																					  //
			textColor = Color::MintCream;																							  //
			buttonPushedBackColor = Color::DarkOliveGreen;																			  //
			buttonPushedForeColor = Color::MintCream;																				  //
			rePaintAllPanels();																										  //
			return;																													  //
		}																															  //
		if (settings_theme == "gray") {																								  //
			backColor = Color::DimGray;																								  //
			secondBackColor = Color::Silver;																						  //
			thirdBackColor = Color::Gainsboro;																						  //
			textColor = Color::Black;																								  //
			buttonPushedBackColor = Color::Gray;																					  //
			buttonPushedForeColor = Color::Black;																					  //
			rePaintAllPanels();																										  //
			return;																													  //
		}																															  //
		MessageBox::Show("ERROR: CANNOT FIND THEME.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);						  //
	}																																  //.                                                                                                          //																										  //
																																	  //
	void rePaintAllPanels() {																										  //
		// Main Background																											  //
		this->BackColor = backColor;																								  //
																																	  //
		// Log in panel																												  //
		login_panel->BackColor = secondBackColor;																					  //
		login_username->BackColor = thirdBackColor;																					  //
		login_password->BackColor = thirdBackColor;																					  //
		login_button->BackColor = thirdBackColor;																					  //
		login_button->ForeColor = textColor;																						  //
		login_username->ForeColor = textColor;																						  //
		login_password->ForeColor = textColor;																						  //
		login_text1->ForeColor = textColor;																							  //
		login_text2->ForeColor = textColor;																							  //
		login_text1->BackColor = secondBackColor;																					  //
		login_text2->BackColor = secondBackColor;																					  //
																																	  //
		// Main panels																												  //
		markEmployeePanel->BackColor = backColor;																					  //
		editAddEmployeePanel->BackColor = backColor;																				  //
		adminPanel->BackColor = backColor;																							  //
		settingsPanel->BackColor = backColor;																						  //
																																	  //
		// Side menu 																												  //
		sidePanel->BackColor = thirdBackColor;																						  //
		markEmployeeButton->BackColor = secondBackColor;																			  //
		editAddEmployeeButton->BackColor = secondBackColor;																			  //
		adminButton->BackColor = secondBackColor;																					  //
		settingsLogsButton->BackColor = secondBackColor;																			  //
		mainMenuSidePanel->BackColor = secondBackColor;																				  //
		mainMenuSideLabel->ForeColor = textColor;																					  //
		markEmployeeLabel->ForeColor = textColor;																					  //
		editAddEmployeeLabel->ForeColor = textColor;																				  //
		adminLabel->ForeColor = textColor;																							  //
		settingsLogsLabel->ForeColor = textColor;																					  //
		mainMenuSideLabel->BackColor = secondBackColor;																				  //
																																	  //
		// Edit/Add Employee Panel																									  //
		  // Top Selection Buttons																									  //
		addEmployeeButton->BackColor = secondBackColor;																				  //
		addEmployeeButton->ForeColor = textColor;																					  //
		editEmployeeButton->BackColor = secondBackColor;																			  //
		editEmployeeButton->ForeColor = textColor;																					  //
		// Add Employee Work Panel																									  //
		addEmployeeWorkPanel->BackColor = secondBackColor;																			  //
		addEmployeeWorkText1->ForeColor = textColor;																				  //
		addEmployeeWorkText2->ForeColor = textColor;																				  //
		addEmployeeWorkText3->ForeColor = textColor;																				  //
		addEmployeeWorkFirstName->ForeColor = textColor;																			  //
		addEmployeeWorkLastName->ForeColor = textColor;																				  //
		addEmployeeWorkEmployeeID->ForeColor = textColor;																			  //
		addEmployeeWorkSaveButton->ForeColor = textColor;																			  //
		addEmployeeWorkFirstName->BackColor = thirdBackColor;																		  //
		addEmployeeWorkLastName->BackColor = thirdBackColor;																		  //
		addEmployeeWorkEmployeeID->BackColor = thirdBackColor;																		  //
		addEmployeeWorkSaveButton->BackColor = thirdBackColor;																		  //
		// Edit Employee Work Panel																									  //
		editEmployeeWorkPanel->BackColor = secondBackColor;																			  //
		editEmployeeComboBox->ForeColor = textColor;																				  //
		editEmployeeComboBox->BackColor = thirdBackColor;																			  //
		editEmployeeWorkText1->ForeColor = textColor;																				  //
		editEmployeeWorkText1->BackColor = secondBackColor;																			  //
		editEmployeeWorkText2->ForeColor = textColor;																				  //
		editEmployeeWorkText2->BackColor = secondBackColor;																			  //
		editEmployeeWorkText3->ForeColor = textColor;																				  //
		editEmployeeWorkText3->BackColor = secondBackColor;																			  //
		editEmployeeWorkText4->ForeColor = textColor;																				  //
		editEmployeeWorkText4->BackColor = secondBackColor;																			  //
		editEmployeeWorkText5->ForeColor = textColor;																				  //
		editEmployeeWorkText5->BackColor = secondBackColor;																			  //
		editEmployeeWorkCurrentPoints->ForeColor = textColor;																		  //
		editEmployeeWorkCurrentPoints->BackColor = thirdBackColor;																	  //
		editEmployeeWorkFirstName->ForeColor = textColor;																			  //
		editEmployeeWorkFirstName->BackColor = thirdBackColor;																		  //
		editEmployeeWorkLastName->ForeColor = textColor;																			  //
		editEmployeeWorkLastName->BackColor = thirdBackColor;																		  //
		editEmployeeWorkEmployeeID->ForeColor = textColor;																			  //
		editEmployeeWorkEmployeeID->BackColor = thirdBackColor;																		  //
		editEmployeeWorkCurrentPoints->ForeColor = textColor;																		  //
		editEmployeeWorkCurrentPoints->BackColor = thirdBackColor;																	  //
		editEmployeeWorkSaveButton->BackColor = thirdBackColor;																		  //
		editEmployeeWorkSaveButton->ForeColor = textColor;																			  //
																																	  //
		// Admin Page																												  //
		 // Add admin Work Panel																									  //
		addAdminWorkText1->BackColor = secondBackColor;																				  //
		addAdminWorkText1->ForeColor = textColor;																					  //
		addAdminWorkText2->BackColor = secondBackColor;																				  //
		addAdminWorkText2->ForeColor = textColor;																					  //
		addAdminWorkText3->BackColor = secondBackColor;																				  //
		addAdminWorkText3->ForeColor = textColor;																					  //
		addAdminWorkUsername->BackColor = thirdBackColor;																			  //
		addAdminWorkUsername->ForeColor = textColor;																				  //
		addAdminWorkPassword->BackColor = thirdBackColor;																			  //
		addAdminWorkPassword->ForeColor = textColor;																				  //
		addAdminWorkConfirmedPassword->BackColor = thirdBackColor;																	  //
		addAdminWorkConfirmedPassword->ForeColor = textColor;																		  //
		addAdminSaveButton->BackColor = thirdBackColor;																				  //
		addAdminSaveButton->ForeColor = textColor;																					  //
		addAdminWorkPanel->BackColor = secondBackColor;																				  //
		editAdminWorkPanel->BackColor = secondBackColor;																			  //
																																	  //
																																	  //
		// Edit admin Work Panel																									  //
		editAdminText1->BackColor = secondBackColor;																				  //
		editAdminText1->ForeColor = textColor;																						  //
		editAdminText2->BackColor = secondBackColor;																				  //
		editAdminText2->ForeColor = textColor;																						  //
		editAdminText3->BackColor = secondBackColor;																				  //
		editAdminText3->ForeColor = textColor;																						  //
		editAdminText4->BackColor = secondBackColor;																				  //
		editAdminText4->ForeColor = textColor;																						  //
		editAdminComboBox->BackColor = thirdBackColor;																				  //
		editAdminComboBox->ForeColor = textColor;																					  //
		editAdminWorkUsername->BackColor = thirdBackColor;																			  //
		editAdminWorkUsername->ForeColor = textColor;																				  //
		editAdminWorkPassword->BackColor = thirdBackColor;																			  //
		editAdminWorkPassword->ForeColor = textColor;																				  //
		editAdminWorkConfirmedPassword->BackColor = thirdBackColor;																	  //
		editAdminWorkConfirmedPassword->ForeColor = textColor;																		  //
		editAdminSaveButton->BackColor = thirdBackColor;																			  //
		editAdminSaveButton->ForeColor = textColor;																					  //
		editAdminRemoveConfirmPanel->BackColor = thirdBackColor;																	  //
																																	  //
																																	  //
		// Mark Employee																											  //
		markEmployeeBackgroundPanel->BackColor = secondBackColor;																	  //
		markEmployeeText1->BackColor = secondBackColor;																				  //
		markEmployeeText1->ForeColor = textColor;																					  //
		markEmployeeText2->BackColor = secondBackColor;																				  //
		markEmployeeText2->ForeColor = textColor;																					  //
		markEmployeeMarkLateButton->BackColor = thirdBackColor;																		  //
		markEmployeeMarkLateButton->ForeColor = textColor;																			  //
		markEmployeeMarkAbsentButton->BackColor = thirdBackColor;																	  //
		markEmployeeMarkAbsentButton->ForeColor = textColor;																		  //
		markEmployeeComboBox->BackColor = thirdBackColor;																			  //
		markEmployeeComboBox->ForeColor = textColor;																				  //
		markEmployeeListView->BackColor = thirdBackColor;																			  //
		markEmployeeListView->ForeColor = textColor;																				  //
		markEmployeeActionConfrimPanel->BackColor = thirdBackColor;																	  //
		markEmployeeAttendanceLimit->BackColor = thirdBackColor;																	  //
		markEmployeeAttendanceLimit->ForeColor = textColor;																			  //
																																	  //
																																	  //
		// Settings																													  //
		 // Logs panel																												  //
		settingsLogsPanel->BackColor = secondBackColor;																				  //
		settingsExpandLogsButton->BackColor = thirdBackColor;																		  //
		settingsExpandLogsButton->ForeColor = textColor;																			  //
		settingsLogsListView->BackColor = thirdBackColor;																			  //
		settingsLogsListView->ForeColor = textColor;																				  //
																																	  //
		// Attendance points panel																									  //
		settingsAttendanceLimit->BackColor = thirdBackColor;																		  //
		settingsAttendanceLimit->ForeColor = textColor;																				  //
		settingsLatePoints->BackColor = thirdBackColor;																				  //
		settingsLatePoints->ForeColor = textColor;																					  //
		settingsAbsentPoints->BackColor = thirdBackColor;																			  //
		settingsAbsentPoints->ForeColor = textColor;																				  //
		settingsSaveAttendanceButton->BackColor = thirdBackColor;																	  //
		settingsSaveAttendanceButton->ForeColor = textColor;																		  //
		settingsAttendancePanel->BackColor = secondBackColor;																		  //
																																	  //
		// Theme panel																												  //
		settingsThemePanel->BackColor = secondBackColor;																			  //
		settingsThemeDefaultButton->ForeColor = textColor;																			  //
		settingsThemeGrayButton->ForeColor = textColor;																				  //
		settingsThemeGreenButton->ForeColor = textColor;																			  //
		settingsThemeRedButton->ForeColor = textColor;																				  //
																																	  //
		// Screen random texts																										  //
		settingsText1->BackColor = secondBackColor;																					  //
		settingsText1->ForeColor = textColor;																						  //
		settingsText2->BackColor = secondBackColor;																					  //
		settingsText2->ForeColor = textColor;																						  //
		settingsText3->BackColor = secondBackColor;																					  //
		settingsText3->ForeColor = textColor;																						  //
		settingsText4->BackColor = secondBackColor;																					  //
		settingsText4->ForeColor = textColor;																						  //
		settingsText5->BackColor = secondBackColor;																					  //
		settingsText5->ForeColor = textColor;																						  //
		settingsText6->BackColor = secondBackColor;																					  //
		settingsText6->ForeColor = textColor;																						  //
		settingsText7->BackColor = secondBackColor;																					  //
		settingsText7->ForeColor = textColor;																						  //
		settingsText8->BackColor = secondBackColor;																					  //
		settingsText8->ForeColor = textColor;																						  //
																																	  //
		// Reset everything panel																									  //
		settingsResetAllPanel->BackColor = secondBackColor;																			  //
		settingsResetAllButton->BackColor = thirdBackColor;																			  //
		settingsResetAllButton->ForeColor = textColor;																				  //
		settingsResetAllPasswordInput->BackColor = thirdBackColor;																	  //
		settingsResetAllPasswordInput->ForeColor = textColor;																		  //
		settingsResetAllConfirmButton->BackColor = thirdBackColor;																	  //
		settingsResetAllConfirmButton->ForeColor = textColor;																		  //
		settingsResetAllCancelButton->BackColor = thirdBackColor;																	  //
		settingsResetAllCancelButton->ForeColor = textColor;																		  //
																																	  //
	}																																  //                                                                                                  //																								  //
																																	  //
	// Hiding all panels funtion 																									  //
	void hidePanels() {																												  //
		// Main Panels																												  //
		markEmployeePanel->Visible = false;																							  //
		editAddEmployeePanel->Visible = false;																						  //
		adminPanel->Visible = false;																								  //
		settingsPanel->Visible = false;																								  //
																																	  //
		// Flash control																											  //
		addEmployeeWorkPanel->Visible = false;																						  //
		editEmployeeWorkPanel->Visible = false;																						  //
		addAdminWorkPanel->Visible = false;																							  //
		editAdminWorkPanel->Visible = false;																						  //
	}																																  //
																																	  //
// ------------------------------------------------------------------------------------------------------------------------------------'



// --------------------------,
// MAIN START UP FUNCTIONS    \
// -----------------------------------------------------------------------------------------------------------------------------------//
																																	  //
	System::Void AttendanceV2_Load(System::Object^ sender, System::EventArgs^ e) {													  //
	// Opening settings file																										  //
		ifstream grabbingSettingsFile(settingsFile);																				  //
		string currSetting = "";																									  //
																																	  //
	// Grabbing attendance points settings																							  //
		getline(grabbingSettingsFile, currSetting);																					  //
		settings_PointsLimit = stod(currSetting.substr(currSetting.find('=')+1));													  //
		getline(grabbingSettingsFile, currSetting);																					  //
		settings_latePoints = stod(currSetting.substr(currSetting.find('=')+1));													  //
		getline(grabbingSettingsFile, currSetting);																					  //
		settings_absentPoints = stod(currSetting.substr(currSetting.find('=')+1));													  //
																																	  //
																																	  //
	// Grabbing theme settings and setting theme																					  //
		getline(grabbingSettingsFile, currSetting);																					  //
		settings_theme = toHandle(currSetting.substr(currSetting.find('=') + 1));													  //
		setTheme();																													  //
																																	  //
	// Closing settings file																										  //
		grabbingSettingsFile.close();																								  //
																																	  //
																																	  //
	// Repainting the panels (in case custom theme)																					  //
		rePaintAllPanels();																											  //
																																	  //
		//  Checking if any admin is made yet 																						  //
		bool adminAvail = false;																									  //
		ifstream checkingAdmin(adminsFile);																							  //
		string line;																												  //
		while (getline(checkingAdmin, line)) {																						  //
			if (!line.empty()) {																									  //
				adminAvail = true;																									  //
				break;																												  //
			}																														  //
		}																															  //
		checkingAdmin.close();																										  //
	// If admin IS avail, set up and login 																							  //
		if (adminAvail) {																											  //
			//  Resetting the login text and panel location/vis.																	  //
			login_username->Text = "";																								  //
			login_password->Text = "";																								  //
			login_panel->Location = Point(12, 12);																					  //
			login_panel->Visible = true;																							  //
																																	  //
			// Changing size of client back to small																				  //
			this->ClientSize = Drawing::Size(316, 162);																				  //
																																	  //
			// Making everything else invisible																						  //
			sidePanel->Visible = false;																								  //
			markEmployeePanel->Visible = false;																						  //
			return;																													  //
		}																															  //
																																	  //
	// If not admin is available, send to make admin screen (make WARNING SIGN vis.)												  //
		// Hiding panel and resizing client																							  //
		login_panel->Visible = false;																								  //
		this->ClientSize = Drawing::Size(530, 370);																					  //
																																	  //
		// Making side panel visible and "closing" it																				  //
		sidePanel->Visible = true;																									  //
		sidePanel->Width = 30; 																										  //
																																	  //
																																	  //
		// Repositionioning panels 																									  //
		repositionMainPanels();																										  //
																			
		
		// Ticking first time set up so that it updates the admin afterSetUp
		firstTimeSetUp = true;
		
		// Clicking the admin page, then clicking the add admin button																  //
		adminLabel_Click(nullptr, nullptr);																							  //
		addAdminButton_Click(nullptr, nullptr);																						  //
																																	  //
	}																																  //
																																	  //
	// Repositioning panels function																								  //
	void repositionMainPanels() {																									  //
		// Repositoning the panels																									  //
		markEmployeePanel->Location = Point(32, 2);																					  //
		editAddEmployeePanel->Location = Point(32, 2);																				  //
		adminPanel->Location = Point(32, 2);																						  //
		settingsPanel->Location = Point(32, 2);																						  //
		addEmployeeWorkPanel->Location = Point(9, 60);																				  //
		editEmployeeWorkPanel->Location = Point(9, 60);																				  //
		addAdminWorkPanel->Location = Point(9, 60);																					  //
		editAdminWorkPanel->Location = Point(9, 60);																				  //
	}																																  //
// -----------------------------------------------------------------------------------------------------------------------------------//
	


// --------------------------,
// LOG IN FUNCTIONS:          \
// -----------------------------------------------------------------------------------------------------------------------------------//
																																	  //
	void login_button_Click(System::Object^ sender, System::EventArgs^ e) {															  //
																																	  //
		// Validating credentials																									  //
		ifstream validatingFile(adminsFile);																						  //
		string line;																												  //
		bool validCredentials = false;																								  //
		while (getline(validatingFile, line)) {																						  //
			string currUsername = line.substr(0, line.find(' '));																	  //
			string currPassword = line.substr(line.find(' ') + 1);																	  //
			if (currUsername == toString(login_username->Text)) {																	  //
				if (currPassword == toString(login_password->Text)) {																  //
					validCredentials = true;																						  //
					break;																											  //
				}																													  //
			}																														  //
		}																															  //
		validatingFile.close();																										  //
																																	  //
		// If credentials are not valid then let user know and clear for next attempt												  //
		if (!validCredentials) {																									  //
			MessageBox::Show("Credentials are not correct.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);				  //
			login_username->Text = "";																								  //
			login_password->Text = "";																								  //
			return;																													  //
		}																															  //
																																	  //
		// If passed through wall, then save logged in admin username																  //
		loggedInAdmin = toString(login_username->Text);																				  //
		loggedInAdminPassword = toString(login_password->Text);																		  //
																																	  //
		// Writting to log that admin logged in																						  //
		writeToLog("User logged in");																								  //
																																	  //
																																	  //
		// Hiding panel and resizing client																							  //
		login_panel->Visible = false;																								  //
		this->ClientSize = Drawing::Size(530, 370);																					  //
																																	  //
		// Making side panel visible and "opening" it																				  //
		sidePanel->Visible = true;																									  //
		sidePanel->Width = 160;																										  //
																																	  //
																																	  //
		// Repositionioning panels 																									  //
		repositionMainPanels(); 																									  //
																																	  //
	}																																  //
																																	  //
																																	  //
// -----------------------------------------------------------------------------------------------------------------------------------//																																	   
																																	   


																																	   
// --------------------------,
// SIDE MENU FUNCTIONS        \
// -----------------------------------------------------------------------------------------------------------------------------------//
																																	  //
	// Animation of opening/closing main menu																						  //
		bool animationIsOpening = false;																							  //
																																	  //
	// Opening and closing menu functions using MOUSE MOVEMENTS																		  //
	System::Void openMenu(System::Object^ sender, System::EventArgs^ e) {	
		// Does not open menu if its first time setup
		if (firstTimeSetUp)
			return;
		
		sideMenuTimer->Start();																										  //
		animationIsOpening = true; // using this to say that we are OPENING															  //
	}																																  //
																																	  //
	System::Void closeMenu(System::Object^ sender, System::EventArgs^ e) {															  //
		sideMenuTimer->Start();																										  //
		animationIsOpening = false; // using this to say that we are CLOSING														  //
	}																																  //
																																	  //
	// ANIMATION FOR SIDE MENU																										  //
	System::Void sideMenuTimer_Tick(System::Object^ sender, System::EventArgs^ e) {													  //
		if (animationIsOpening) {																									  //
			// If menu is opening, do this animation																				  //
			if (sidePanel->Width <= 150) {																							  //
				sidePanel->Width += 10;																								  //
			}																														  //
			else {																													  //
				sideMenuTimer->Stop();																								  //
				animationIsOpening = true;																							  //
			}																														  //
		}																															  //
		else {																														  //
			// If menu is closing, do this animation																				  //
			if (sidePanel->Width >= 40) {																							  //
				sidePanel->Width -= 10;																								  //
			}																														  //
			else {																													  //
				sideMenuTimer->Stop();																								  //
				animationIsOpening = false;																							  //
			}																														  //
		}																															  //
	}																																  //
																																	  //
// -----------------------------------------------------------------------------------------------------------------------------------//



	

// ------------------------------,
// CLICKING ON SIDE MENU BUTTONS  \
// -----------------------------------------------------------------------------------------------------------------------------------//
																																	  //
																																	  //
// Clicking on side menu buttons																									  //
	System::Void editAddEmployeeLabel_Click(System::Object^ sender, System::EventArgs^ e) {											  //
		// Hiding other panels and showing this one																					  //
		hidePanels();																												  //
		editAddEmployeePanel->Visible = true;																						  //
																																	  //
		// Hiding the two working panels																							  //
		addEmployeeWorkPanel->Visible = false;																						  //
		editEmployeeWorkPanel->Visible = false;																						  //
																																	  //
		// Setting both buttons to be inactive																						  //
		addEmployeeButton->BackColor = secondBackColor;																				  //
		addEmployeeButton->ForeColor = textColor;																					  //
		editEmployeeButton->BackColor = secondBackColor;																			  //
		editEmployeeButton->ForeColor = textColor;																					  //
																																	  //
	}																																  //
																																	  //
	System::Void adminLabel_Click(System::Object^ sender, System::EventArgs^ e) {													  //
		// Hiding other panels and showing this one																					  //
		hidePanels();																												  //
		adminPanel->Visible = true;																									  //
																																	  //
		// Hidding the two working panels																							  //
		addAdminWorkPanel->Visible = false;																							  //
		editAdminWorkPanel->Visible = false;																						  //
																																	  //
		// Setting both buttons to be inactive																						  //
		addAdminButton->BackColor = secondBackColor;																				  //
		addAdminButton->ForeColor = textColor;																						  //
		editAdminButton->BackColor = secondBackColor;																				  //
		editAdminButton->ForeColor = textColor;																						  //
	}																																  //
																																	  //
	System::Void markEmployeeLabel_Click(System::Object^ sender, System::EventArgs^ e) {											  //
		// used to prevent a flash when an absent/late action is made, no need to hide again										  //
		if (sender != nullptr) {																									  //
			// Hiding other panels and showing this one																				  //
			hidePanels();																											  //
		}																															  //
																																	  //
																																	  //
		// Resetting combo box																										  //
		markEmployeeComboBox->SelectedIndex = -1;																					  //
		markEmployeeComboBox->Text = "";																							  //
		markEmployeeComboBox->Items->Clear();																						  //
																																	  //
		// Reseting list view																										  //
		markEmployeeListView->Items->Clear();																						  //
																																	  //
		// Hiding the confirm panel																									  //
		markEmployeeActionConfrimPanel->Visible = false;																			  //
																																	  //
		// Setting the attendance limit text																						  //
		markEmployeeAttendanceLimit->Text = toHandle(doubleToString(settings_PointsLimit));											  //
																																	  //
		// Loading the employees over the limit AND employees to combo box at in same READ											  //
		ifstream file(employeesFile);																								  //
		string line;																												  //
		if (!file) {																												  //
			MessageBox::Show("Could not open file!.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);						  //
			return;																													  //
		}																															  //
																																	  //
		while (getline(file, line)) {																								  //
			if (line.empty())																										  //
				continue;																											  //
			// Getting all information on employee from line grabbed																  //
			string eID = line.substr(0, line.find('_'));																			  //
			line = line.substr(line.find('_') + 1);																					  //
			string eFirstName = line.substr(0, line.find('_'));																		  //
			line = line.substr(line.find('_') + 1);																					  //
			string eLastName = line.substr(0, line.find('_'));																		  //
			line = line.substr(line.find('_') + 1);																					  //
			string attenCount = line;																								  //
																																	  //
			// Adding employee to the combo box																						  //
			string adminInfoForCombo = eFirstName + " " + eLastName + " : " + eID + " : " + attenCount;								  //
			String^ adminInfoForCombo_ = gcnew String(adminInfoForCombo.c_str());													  //
			markEmployeeComboBox->Items->Add(adminInfoForCombo_);																	  //
																																	  //
			// Adding employee to the listview																						  //
			if (stod(attenCount) >= settings_PointsLimit) {																			  //
				ListViewItem^ item = gcnew ListViewItem(toHandle(eFirstName + " " + eLastName));									  //
				item->SubItems->Add(toHandle(eID));																					  //
				item->SubItems->Add(toHandle(attenCount));																			  //
				markEmployeeListView->Items->Add(item);																				  //
			}																														  //
		}																															  //
																																	  //
		file.close();																												  //
																																	  //
																																	  //
		// Making visible after everything loads up																					  //
		markEmployeePanel->Visible = true;																							  //
	}																																  //
																																	  //
	String^ readLimit = "";																											  //
	String^ readLate = "";																											  //
	String^ readAbsent = "";																										  //
	System::Void settingsLogsLabel_Click(System::Object^ sender, System::EventArgs^ e) {											  //
	// Hiding all other panels																										  //
		hidePanels();																												  //
																																	  //
	// Reading settings saved on file and storing them 																				  //
		ifstream readingFile(settingsFile);																							  //
		string line;																												  //
																																	  //
		// Storing the attedance points settings																					  //
		getline(readingFile, line);																									  //
		readLimit = toHandle(line.substr(line.find('=') + 1));																		  //
		getline(readingFile, line);																									  //
		readLate = toHandle(line.substr(line.find('=') + 1));																		  //
		getline(readingFile, line);																									  //
		readAbsent = toHandle(line.substr(line.find('=') + 1));																		  //
																																	  //
		// Using this to tell theme to NOT refresh when check status is changed														  //
		settingsAttendanceLimit->Text = "SKIP";																						  //
																																	  //
		// Reading and showing currently selected theme																				  //
		getline(readingFile, line);																									  //
		line = line.substr(line.find('=') + 1);																						  //
		if (line == "default") { settingsThemeDefaultButton->Checked = true; }														  //
		if (line == "red")     { settingsThemeRedButton->Checked     = true; }														  //
		if (line == "green")   { settingsThemeGreenButton->Checked   = true; }														  //
		if (line == "gray")    { settingsThemeGrayButton->Checked    = true; }														  //
																																	  //
		readingFile.close();																										  //
																																	  //
	// Setting text boxes to stored values																							  //
		settingsAttendanceLimit->Text = readLimit;																					  //
		settingsLatePoints->Text = readLate;																						  //
		settingsAbsentPoints->Text = readAbsent;																					  //
																																	  //
																																	  //
	// "closing" the log expand if not already closed																				  //
		logClosed = true;																											  //
		isAnimating = false;																										  //
		panelFinished = false;																										  //
		listViewFinished = false;																									  //
		settingsLogsPanel->Height = 140;																							  //
		settingsLogsListView->Height = 105;																							  //
		settingsExpandLogsButton->Text = "Expand";																					  //
																																	  //
	// Pulling the logs from the log file																							  //
		settingsLogsListView->LoadFile(toHandle(logsFile), RichTextBoxStreamType::PlainText);										  //
																																	  //
	// Making the reset confirmation panel invis in case it was left as visible														  //
		settingsResetAllConfrimPanel->Visible = false;																				  //
																																	  //
	// Making the panel visible after the everything loads																			  //
		settingsPanel->Visible = true;																								  //
	}																																  //
																																	  //
																																	  //
// -----------------------------------------------------------------------------------------------------------------------------------//




// CODE FOR EACH INDIVIDUAL PANEL (IN REGIONS):

#pragma region ADD_EDIT_EMPLOYEE
// PANEL: --------------------------- ADD/EDIT EMPLOYEE ---------------------------------                                               
 // ADD EMPLOYEE:
	// Entering the Add Employee panel
	void addEmployeeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Setting this button to be active
		addEmployeeButton->BackColor = buttonPushedBackColor;
		addEmployeeButton->ForeColor = buttonPushedForeColor;
		// Setting the other button to be inactive
		editEmployeeButton->BackColor = secondBackColor;
		editEmployeeButton->ForeColor = textColor;

		// Making edit employee working panel invisible
		editEmployeeWorkPanel->Visible = false;

		// Resetting the textboxes
		addEmployeeWorkFirstName->Text = "";
		addEmployeeWorkLastName->Text = "";
		addEmployeeWorkEmployeeID->Text = "";

		// Making work panel visible after everything is loaded
		addEmployeeWorkPanel->Visible = true;
	}

	// Saving the employee
	void addEmployeeWorkSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// CHECKING VALID INPUTS:
		
		// Cleaning spaces from text boxes
		addEmployeeWorkFirstName->Text = addEmployeeWorkFirstName->Text->Trim();
		addEmployeeWorkLastName->Text = addEmployeeWorkLastName->Text->Trim();
		addEmployeeWorkEmployeeID->Text = addEmployeeWorkEmployeeID->Text->Trim();

		
		// Checking if first and last name are inputted
		if (addEmployeeWorkFirstName->Text == "" || addEmployeeWorkLastName->Text == "") {
			MessageBox::Show("Please fill in employee's name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	
		// Checking if first and last name doesn't contain '_'
		for (int i = 0; i < addEmployeeWorkFirstName->Text->Length; i++){
			if (addEmployeeWorkFirstName->Text[i] == '_' || addEmployeeWorkFirstName->Text[i] == ' ') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE/SPACES", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		
		for (int i = 0; i < addEmployeeWorkLastName->Text->Length; i++) {
			if (addEmployeeWorkLastName->Text[i] == '_' || addEmployeeWorkLastName->Text[i] == ' ') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE/SPACES", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		
		// Checking if Employee ID is inputted
		if (addEmployeeWorkEmployeeID->Text == "") {
			MessageBox::Show("Please fill in Employee ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		
		// Checking if Employee ID is only digits
		for (int i = 0; i < addEmployeeWorkEmployeeID->Text->Length; i++) {
			if (!Char::IsDigit(addEmployeeWorkEmployeeID->Text[i]) || addEmployeeWorkEmployeeID->Text[i] == ' ') {
				MessageBox::Show("Please enter only digits for Employee ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		
	

		// Checking if Employee ID is unique
		ifstream file(employeesFile);
		string line;
		if (!file.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		while (getline(file, line)) {
			if (line.empty()) {
				continue;
			}
			line = line.substr(0, line.find('_'));
			if (line == toString(addEmployeeWorkEmployeeID->Text)) {
				MessageBox::Show("Employee ID already exists.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				file.close();
				return;
			}
		}
		file.close();

	// ADDING EMPLOYEE:
		ofstream writingEmployee(employeesFile, ios::app);
		if (!writingEmployee.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		writingEmployee << toString(addEmployeeWorkEmployeeID->Text) << "_" << toString(addEmployeeWorkFirstName->Text) << "_" << toString(addEmployeeWorkLastName->Text);
		writingEmployee << "_0.00" << endl;
		writingEmployee.close();

		// Letting user know aciton was successful
		MessageBox::Show("Employee added successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Adding action to log
		writeToLog("Added " + toString(addEmployeeWorkFirstName->Text) + "_" + toString(addEmployeeWorkLastName->Text) 
			+ "(" + toString(addEmployeeWorkEmployeeID->Text) + ")");


		// Resetting the textboxes
		addEmployeeWorkFirstName->Text = "";
		addEmployeeWorkLastName->Text = "";
		addEmployeeWorkEmployeeID->Text = "";
	}





 // EDIT EMPLOYEE:
	// Entering the Edit Employee panel
	System::Void editEmployeeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Reseting combo-box
		editEmployeeComboBox->Items->Clear();
		editEmployeeComboBox->SelectedIndex = -1;
		editEmployeeComboBox->Text = "";

		// Setting remove panel to invisible
		editEmployeeRemoveConfirmPanel->Visible = false;


		// Setting this button to be active
		editEmployeeButton->BackColor = buttonPushedBackColor;
		editEmployeeButton->ForeColor = buttonPushedForeColor;
		// Setting the other button to be inactive
		addEmployeeButton->BackColor = secondBackColor;
		addEmployeeButton->ForeColor = textColor;

		// Making add employee working panel invisible
		addEmployeeWorkPanel->Visible = false;

		// Resetting the combobox and text boxes
		editEmployeeComboBox->Items->Clear();
		editEmployeeWorkFirstName->Text = "";
		editEmployeeWorkLastName->Text = "";
		editEmployeeWorkEmployeeID->Text = "";
		editEmployeeWorkCurrentPoints->Text = "";

		


		// Load the names of the employees into the combobox
		ifstream file(employeesFile);
		string line;
		if (!file.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		while (getline(file, line)) {
			if (line.empty()) {
				continue;
			}
			string employeeID = line.substr(0, line.find('_'));
			line = line.substr(line.find('_')+1);
			string employeeFirstName = line.substr(0,line.find('_'));
			line = line.substr(line.find('_')+1);
			string employeeLastName = line.substr(0,line.find('_'));
			line = line.substr(line.find('_') + 1);
			string employeePoints = line;
			String^ employee = gcnew String((employeeFirstName + " " + employeeLastName + " : " + employeeID + " : " + employeePoints).c_str());
			editEmployeeComboBox->Items->Add(employee);
		}
		file.close();
		
		// Making visible once everything is finished loading
		editEmployeeWorkPanel->Visible = true;

	}



	// User selected an employee
	int savedEmployeeID = -1;
	String^ savedEmployeeFName = "";
	String^ savedEmployeeLName = "";
	String^ savedEmployeePoints = "";
	System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Returning if no employee is selected
		if (editEmployeeComboBox->SelectedIndex == -1) {
			return;
		}	

		// Making the remove panel invisible again in case the employee is changed
		editEmployeeRemoveConfirmPanel->Visible = false;

		// Getting the selected employee
		string employee = toString(editEmployeeComboBox->SelectedItem->ToString());
		string employeeFirstName = employee.substr(0, employee.find(' '));

		employee = employee.substr(employee.find(' ') + 1);
		string employeeLastName = employee.substr(0, employee.find(' '));

		employee = employee.substr(employee.find(':') + 2);
		string employeeID = employee.substr(0, employee.find(':') - 1);

		string employeePoints = employee.substr(employee.find(':') + 2);
		
		// Saving the employee information for log and finding when writting
		savedEmployeeID     = stoi(employeeID);
		savedEmployeeFName  = toHandle(employeeFirstName);
		savedEmployeeLName  = toHandle(employeeLastName);
		savedEmployeePoints = toHandle(employeePoints);
			
		// Setting the text boxes
		editEmployeeWorkFirstName->Text = gcnew String(employeeFirstName.c_str());
		editEmployeeWorkLastName->Text = gcnew String(employeeLastName.c_str());
		editEmployeeWorkEmployeeID->Text = gcnew String(employeeID.c_str());
		editEmployeeWorkCurrentPoints->Text = gcnew String(employeePoints.c_str());
	}



	// Save employee button is clicked
	void editEmployeeWorkSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// CHECKING IF EMPLOYEE IS SELECTED
		if (editEmployeeComboBox->SelectedIndex == -1) {
			MessageBox::Show("Please select an employee.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// CHECKING VALID INPUTS:
			// Cleaning spaces from text boxes
		editEmployeeWorkFirstName->Text = editEmployeeWorkFirstName->Text->Trim();
		editEmployeeWorkLastName->Text = editEmployeeWorkLastName->Text->Trim();
		editEmployeeWorkEmployeeID->Text = editEmployeeWorkEmployeeID->Text->Trim();
		editEmployeeWorkCurrentPoints->Text = editEmployeeWorkCurrentPoints->Text->Trim();



		// Checking if first and last name are inputted
		if (editEmployeeWorkFirstName->Text == "" || editEmployeeWorkLastName->Text == "") {
			MessageBox::Show("Please fill in employee's name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Checking if first and last name doesn't contain '_'
		for (int i = 0; i < editEmployeeWorkFirstName->Text->Length; i++) {
			if (editEmployeeWorkFirstName->Text[i] == '_' || editEmployeeWorkFirstName->Text[i] == ' ') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE/SPACES", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		for (int i = 0; i < editEmployeeWorkLastName->Text->Length; i++) {
			if (editEmployeeWorkLastName->Text[i] == '_' || editEmployeeWorkLastName->Text[i] == ' ') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE/SPACES", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		// Checking if Employee ID is inputted
		if (editEmployeeWorkEmployeeID->Text == "") {
			MessageBox::Show("Please fill in Employee ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Checking if Employee ID is only digits
		for (int i = 0; i < editEmployeeWorkEmployeeID->Text->Length; i++) {
			if (!Char::IsDigit(editEmployeeWorkEmployeeID->Text[i]) || editEmployeeWorkEmployeeID->Text[i] == ' ') {
				MessageBox::Show("Please enter only digits for Employee ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		// Checking if points is valid by catching error in conversion
		double pointsInDouble = 0;
		try {
			pointsInDouble = stod(toString(editEmployeeWorkCurrentPoints->Text));
		}
		catch (invalid_argument) {
			MessageBox::Show("Please fix points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Checking if points is valid by checking for alphabets
		for (int i = 0; i < editEmployeeWorkCurrentPoints->Text->Length; i++) {
			if (!Char::IsDigit(editEmployeeWorkCurrentPoints->Text[i]) && (editEmployeeWorkCurrentPoints->Text[i] != '.')) {
				MessageBox::Show("Please fix points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		// Changing "invalid" inputs into valid ones before sending to writting
		editEmployeeWorkCurrentPoints->Text = toHandle(doubleToString(pointsInDouble));

		// Checking if Employee ID is unique (AGAINST: the list we have in the combobox)
		for (int i = 0; i < editEmployeeComboBox->Items->Count; i++) {
			string comparingEmployee = toString(editEmployeeComboBox->Items[i]->ToString());
			comparingEmployee = comparingEmployee.substr(comparingEmployee.find(':') + 2);
			comparingEmployee = comparingEmployee.substr(0, comparingEmployee.find(':') - 1);
			if (comparingEmployee == toString(editEmployeeWorkEmployeeID->Text)) {
				// If the employee ID is the same as the one we are editing, then continue
				if (stoi(toString(editEmployeeWorkEmployeeID->Text)) == savedEmployeeID) {
					continue;
				}
				MessageBox::Show("Employee ID already exists.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		// SAVING THE EMPLOYEE
			// Getting the employee's info
		string employeeInfo = toString(editEmployeeWorkEmployeeID->Text) + "_" + toString(editEmployeeWorkFirstName->Text) + "_" + toString(editEmployeeWorkLastName->Text) + "_" + doubleToString(stod(toString(editEmployeeWorkCurrentPoints->Text)));

		// Reading the file and writing to a new file
		ifstream inputfile(employeesFile);
		ofstream writingFile("temp.txt");
		string line;
		if (!inputfile.is_open() || !writingFile.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		while (getline(inputfile, line)) {
			if (line.empty()) {
				continue;
			}
			string employeeID = line.substr(0, line.find('_'));
			if (stoi(employeeID) == savedEmployeeID) {
				// writting the new employee instead of the old one
				writingFile << employeeInfo << endl;
			}
			else {
				// writting any other employee
				writingFile << line << endl;
			}
		}
		inputfile.close();
		writingFile.close();

		// Deleting the old file and renaming the new file
		if (remove(employeesFile.c_str()) != 0) {
			MessageBox::Show("Error in removing file! Exit and remove file. ERROR: FILE_REMOVE_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (rename("temp.txt", employeesFile.c_str()) != 0) {
			MessageBox::Show("Error in renaming file! Exit and rename if reached. ERROR: RENAME_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}


		MessageBox::Show("Employee saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		writeToLog("Changed " + toString(savedEmployeeFName) + "_" + toString(savedEmployeeLName) + "(" + to_string(savedEmployeeID)
			       + "):[" + toString(savedEmployeePoints) + " pts]" + " -> " 
			       + toString(editEmployeeWorkFirstName->Text) + "_" + toString(editEmployeeWorkLastName->Text) + "(" + toString(editEmployeeWorkEmployeeID->Text)
			       + "):[" + doubleToString(stod(toString(editEmployeeWorkCurrentPoints->Text))) + " pts]");

		
		// Resetting the textboxes
		editEmployeeWorkFirstName->Text = "";
		editEmployeeWorkLastName->Text = "";
		editEmployeeWorkEmployeeID->Text = "";
		editEmployeeWorkCurrentPoints->Text = "";
		savedEmployeeID = -1;

		// Resetting the combobox
		editEmployeeButton_Click(nullptr, nullptr);
	}



	// Remove Employee button is clicked
	void editEmployeeWorkRemoveEmployee_Click(System::Object^ sender, System::EventArgs^ e) {
		// Checking if the employee is selected
		if (editEmployeeComboBox->SelectedIndex == -1) {
			MessageBox::Show("Please select an employee.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		editEmployeeRemoveConfirmPanel->Visible = true;
	}


	void editEmployeeRemoveConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Opening the files
		ifstream inputfile(employeesFile);
		ofstream writingFile("temp.txt");
		string line;

		// Checking if the files are open
		if (!inputfile.is_open() || !writingFile.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		string savedForLog = "ERROR:COULD_NOT_REMOVE";
		// Writing all employees except the one we want to remove
		while (getline(inputfile, line)) {
			if (line.empty()) {
				continue;
			}
			
			string employeeID = line.substr(0, line.find('_'));
			if (employeeID == to_string(savedEmployeeID)) {
				// Do not write this employee
				savedForLog = line;
				continue;
			}
			else {
				// writting any other employee
				writingFile << line << endl;
			}
		}
		inputfile.close();
		writingFile.close();

		// Deleting the old file and renaming the new file
		if (remove(employeesFile.c_str()) != 0) {
			MessageBox::Show("Error in removing file! Exit and remove file. ERROR: FILE_REMOVE_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (rename("temp.txt", employeesFile.c_str()) != 0) {
			MessageBox::Show("Error in renaming file! Exit and rename if reached. ERROR: RENAME_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		MessageBox::Show("Employee removed successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		writeToLog("Removed " + savedForLog);


		// Resetting the textboxes
		editEmployeeWorkFirstName->Text = "";
		editEmployeeWorkLastName->Text = "";
		editEmployeeWorkEmployeeID->Text = "";
		editEmployeeWorkCurrentPoints->Text = "";
		savedEmployeeID = -1;

		// Resetting the combobox
		editEmployeeButton_Click(nullptr, nullptr);
	}

	void editEmployeeRemoveCancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		editEmployeeRemoveConfirmPanel->Visible = false;
	}

// -----------------------------------------------------------------------------------

#pragma endregion


#pragma region ADMIN
// -- ADMIN MENU -- 

	// Adding admin button clicked
	void addAdminButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Setting this button to be active
		addAdminButton->BackColor = buttonPushedBackColor;
		addAdminButton->ForeColor = buttonPushedForeColor;
		// Setting the other button to be inactive
		editAdminButton->BackColor = secondBackColor;
		editAdminButton->ForeColor = textColor;

		// Making edit employee working panel invisible
		editAdminWorkPanel->Visible = false;

		// Resetting the textboxes
		addAdminWorkUsername->Text = "";
		addAdminWorkPassword->Text = "";
		addAdminWorkConfirmedPassword->Text = "";

		// Making work panel visible after everything is loaded
		addAdminWorkPanel->Visible = true;
	}


	String^ savedAdminUsername = "";
	void editAdminButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// does not allow to leave screen if no admin is set up yet
		if (firstTimeSetUp)
			return;

		// Setting saved admin username as null
		savedAdminUsername = "";

		// Setting remove confirmation panel to invisible
		editAdminRemoveConfirmPanel->Visible = false;

		// Setting this button to be active
		editAdminButton->BackColor = buttonPushedBackColor;
		editAdminButton->ForeColor = buttonPushedForeColor;
		// Setting the other button to be inactive
		addAdminButton->BackColor = secondBackColor;
		addAdminButton->ForeColor = textColor;

		// Making edit employee working panel invisible
		addAdminWorkPanel->Visible = false;

		// Resetting the textboxes
		editAdminWorkUsername->Text = "";
		editAdminWorkPassword->Text = "";
		editAdminWorkConfirmedPassword->Text = "";

		// Clearing the combo box
		editAdminComboBox->Text = "";
		editAdminComboBox->Items->Clear();
		editAdminComboBox->SelectedIndex = -1;

		// Loading the combo box
		ifstream file(adminsFile);
		string line;
		if (!file.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		while (getline(file, line)) {
			if (line.empty()) {
				continue;
			}
			string adminUsername = line.substr(0, line.find(' '));
			String^ adminUsername_ = gcnew String((adminUsername).c_str());
			editAdminComboBox->Items->Add(adminUsername_);
		}
		file.close();

		// Making visible once everything is finished loading
		editAdminWorkPanel->Visible = true;
	}




// ADDING ADMIN 
	// Adding admin save button clicked
	void addAdminSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// CHECKING VALID INPUTS:
		// Cleaning spaces from text boxes
		addAdminWorkUsername->Text = addAdminWorkUsername->Text->Trim();
		addAdminWorkPassword->Text = addAdminWorkPassword->Text->Trim();
		addAdminWorkConfirmedPassword->Text = addAdminWorkConfirmedPassword->Text->Trim();

		// Checking if username is inputted
		if (addAdminWorkUsername->Text == ""){
			MessageBox::Show("Please fill in username.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Checking if passwords are inputted
		if (addAdminWorkPassword->Text == "" || addAdminWorkConfirmedPassword->Text == "") {
			MessageBox::Show("Please fill in password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}


		// Checking if passwords match
		if (addAdminWorkPassword->Text != addAdminWorkConfirmedPassword->Text) {
			MessageBox::Show("Passwords do not match!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Checking if username and password does not contain spaces
		for (int i = 0; i < addAdminWorkUsername->Text->Length; i++){
			if (addAdminWorkUsername->Text[i] == ' ') {
				MessageBox::Show("Username cannot contain SPACES.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		for (int i = 0; i < addAdminWorkPassword->Text->Length; i++) {
			if (addAdminWorkPassword->Text[i] == ' ') {
				MessageBox::Show("Password cannot contain SPACES.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		
		
		// Checking if Admin Username is unique
		ifstream file(adminsFile);
		string line;
		if (!file.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		while (getline(file, line)) {
			if (line.empty()) {
				continue;
			}
			line = line.substr(0, line.find(' '));
			if (line == toString(addAdminWorkUsername->Text)) {
				MessageBox::Show("Admin Username is already used.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				file.close();
				return;
			}
		}
		file.close();
		


	// Adding Admin to file:
		ofstream writingAdmin(adminsFile, ios::app);
		if (!writingAdmin.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		writingAdmin << toString(addAdminWorkUsername->Text) << " " << toString(addAdminWorkPassword->Text) << endl;
		writingAdmin.close();
		
		
		MessageBox::Show("Admin added successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		writeToLog("Added ADMIN->" + toString(addAdminWorkUsername->Text));
		
		// Saving admin information to code variables
		if (firstTimeSetUp) {
			loggedInAdmin = toString(addAdminWorkUsername->Text);
			loggedInAdminPassword = toString(addAdminWorkPassword->Text);
			firstTimeSetUp = false;
		}

		// Reseting boxes 
		addAdminButton_Click(nullptr, nullptr);
	}

	
	void editAdminComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (editAdminComboBox->SelectedIndex == -1)
			return;

		// Making the remove panel invisible again in case the admin is changed
		editAdminRemoveConfirmPanel->Visible = false;

		// Getting the selected admin
		string admin = toString(editAdminComboBox->SelectedItem->ToString());

		// Saving the admin Username
		savedAdminUsername = toHandle(admin);

		// Setting the text boxes
		editAdminWorkUsername->Text = gcnew String(admin.c_str());
	}



	void editAdminSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
// CHECKING IF ADMIN IS SELECTED
		if (editAdminComboBox->SelectedIndex == -1) {
			MessageBox::Show("Please select an admin.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

// CHECKING VALID INPUTS:
		// Cleaning spaces from text boxes
		editAdminWorkUsername->Text = editAdminWorkUsername->Text->Trim();
		editAdminWorkPassword->Text = editAdminWorkPassword->Text->Trim();
		editAdminWorkConfirmedPassword->Text = editAdminWorkConfirmedPassword->Text->Trim();



		// Cehcking if admin username is changed 
		if (editAdminWorkUsername->Text == "") {
			MessageBox::Show("Please fill in admin's username.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// If user did not change anything
		if (editAdminWorkPassword->Text == "" && editAdminWorkConfirmedPassword->Text == "") {
			if (editAdminWorkUsername->Text == savedAdminUsername) {
				MessageBox::Show("There was no change in credentials", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		
		// STATE: USER WANTS TO CHANGE SOMETHING


		// Checking if username doesn't contain ' '
		for (int i = 0; i < editAdminWorkUsername->Text->Length; i++) {
			if (editAdminWorkUsername->Text[i] == ' ') {
				MessageBox::Show("Admin Username cannot contain SPACES.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		// If user wants to change password
		if (editAdminWorkPassword->Text != "" || editAdminWorkConfirmedPassword->Text != "") {
			// Checking that passwords match
			if (editAdminWorkPassword->Text != editAdminWorkConfirmedPassword->Text) {
				MessageBox::Show("Passwords do not match!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Checking that passwords do not contain spaces
			for (int i = 0; i < editAdminWorkPassword->Text->Length; i++) {
				if (editAdminWorkPassword->Text[i] == ' ') {
					MessageBox::Show("Admin Password cannot contain SPACES.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
			}

			for (int i = 0; i < editAdminWorkConfirmedPassword->Text->Length; i++) {
				if (editAdminWorkConfirmedPassword->Text[i] == ' ') {
					MessageBox::Show("Admin Password cannot contain SPACES.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
			}
		}

		
		// Checking if admin username is unique (AGAINST: the list we have in the combobox)
		for (int i = 0; i < editAdminComboBox->Items->Count; i++) {
			string comparingAdmin = toString(editAdminComboBox->Items[i]->ToString());
			if (comparingAdmin == toString(editAdminWorkUsername->Text)) {
				if (comparingAdmin == toString(savedAdminUsername))
					continue;
				MessageBox::Show("Admin Username already exists.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

// SAVING THE ADMIN
		// Getting the adminsInfo
		string newAdmin = toString(editAdminWorkUsername->Text);
		string line;
		string password;
		ifstream grabbingAdminPassFile(adminsFile);
		while (getline(grabbingAdminPassFile, line)) {
			if (line.empty())
				continue;
			// Save password and username
			password = line.substr(line.find(' ') + 2);
			line = line.substr(0, line.find(' '));

			// If username is found, save newadmin as newusername AND if password
			// changed then save password instead of password found
			if (line == toString(savedAdminUsername)) {
				if (editAdminWorkPassword->Text == "") {
					newAdmin = newAdmin + " " + password;
				}
				else {
					newAdmin = newAdmin + " " + toString(editAdminWorkPassword->Text);
				}
				break;
			}
		}
		grabbingAdminPassFile.close();


		// Reading the file and writing to a new file
		ifstream inputfile(adminsFile);
		ofstream writingFile("temp.txt");
		string line2;
		if (!inputfile.is_open() || !writingFile.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		string savedForLog = "";
		while (getline(inputfile, line2)) {
			if (line2.empty()) {
				continue;
			}
			string adminUsername_ = line2.substr(0, line2.find(' '));
			if (adminUsername_ == toString(savedAdminUsername)) {
				// writting the new admin instead of the old one
				savedForLog = line2;
				writingFile << newAdmin << endl;
			}
			else {
				// copying over any other admin
				writingFile << line2 << endl;
			}
		}
		inputfile.close();
		writingFile.close();
		
		// Deleting the old file and renaming the new file
		if (remove(adminsFile.c_str()) != 0) {
			MessageBox::Show("Error in removing file! Exit and remove file. ERROR: FILE_REMOVE_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (rename("temp.txt", adminsFile.c_str()) != 0) {
			MessageBox::Show("Error in renaming file! Exit and rename if reached. ERROR: RENAME_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		MessageBox::Show("Admin saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);


		// Write change of username
		writeToLog("Changed ADMIN->" + toString(savedAdminUsername) + " TO ADMIN->" + toString(editAdminWorkUsername->Text));
		// If changed password, write after writting the change of username
		if(editAdminWorkPassword->Text != "")
			writeToLog("Change ADMIN->" + toString(editAdminWorkUsername->Text) + "'s password");


		// Resetting the textboxes
		editAdminWorkUsername->Text = "";
		editAdminWorkPassword->Text = "";
		editAdminWorkConfirmedPassword->Text = "";
		savedAdminUsername = "";
		
		// Resetting the combobox
		editAdminButton_Click(nullptr, nullptr);
	}

	void editAdminRemoveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Checking if the admin is selected
		if (editAdminComboBox->SelectedIndex == -1) {
			MessageBox::Show("Please select an admin.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		editAdminRemoveConfirmPanel->Visible = true;
	}

	void editAdminRemoveCancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		editAdminRemoveConfirmPanel->Visible = false;
	}
	void editAdminRemoveConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Opening the files
		ifstream inputfile(adminsFile);
		ofstream writingFile("temp.txt");
		string line;

		// Checking if the files are open
		if (!inputfile.is_open() || !writingFile.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Writing all admins except the one we want to remove
		while (getline(inputfile, line)) {
			if (line.empty()) {
				continue;
			}
			string adminUsername = line.substr(0, line.find(' '));
			if (adminUsername == toString(savedAdminUsername)) {
				// Do not write this employee
				continue;
			}
			else {
				// writting any other employee
				writingFile << line << endl;
			}
		}
		inputfile.close();
		writingFile.close();


		// Deleting the old file and renaming the new file
		if (remove(adminsFile.c_str()) != 0) {
			MessageBox::Show("Error in removing file! Exit and remove file. ERROR: FILE_REMOVE_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (rename("temp.txt", adminsFile.c_str()) != 0) {
			MessageBox::Show("Error in renaming file! Exit and rename if reached. ERROR: RENAME_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		MessageBox::Show("Admin removed successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		writeToLog("Removed ADMIN->" + toString(savedAdminUsername));

		// Resetting the combobox and textBoxes
		editAdminButton_Click(nullptr, nullptr);
	}

#pragma endregion


#pragma region MARK_EMPLOYEE
// --- MARK EMPLOYEE ----
	void markEmployeeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Make action confirm panel insvisble if employee changes
		markEmployeeActionConfrimPanel->Visible = false;
	}

	void markEmployeeActionCancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		markEmployeeActionConfrimPanel->Visible = false;
	}

	void markEmployeeMarkLateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if an employee is chosen
		if (markEmployeeComboBox->SelectedIndex == -1) {
			MessageBox::Show("Please select an employee.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Change text in action confirm panel to "mark LATE"
		markEmployeeActionConfirmButton->Text = "Confirm Mark Late";

		// Make action confirm panel visible 
		markEmployeeActionConfrimPanel->Visible = true;
	}

	void markEmployeeMarkAbsentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if an employee is chosen
		if (markEmployeeComboBox->SelectedIndex == -1) {
			MessageBox::Show("Please select an employee.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Change text in action confirm panel to "mark ABSENT"
		markEmployeeActionConfirmButton->Text = "Confirm Mark Absent";

		// Make action confirm panel visible 
		markEmployeeActionConfrimPanel->Visible = true;
	}


	void markEmployeeActionConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		bool markedLate = true;
		if (markEmployeeActionConfirmButton->Text == "Confirm Mark Late") 
			markedLate = true;
		else
			markedLate = false;

		// Grabbing employee chosen info
		string employeeInfo = toString(markEmployeeComboBox->Text);
		string eFirstName = employeeInfo.substr(0, employeeInfo.find(' '));
		employeeInfo = employeeInfo.substr(employeeInfo.find(' ') + 1);
		string eLastName = employeeInfo.substr(0, employeeInfo.find(' '));
		employeeInfo = employeeInfo.substr(employeeInfo.find(':') + 2);
		string eID = employeeInfo.substr(0, employeeInfo.find(' '));
		double ePoints = stod(employeeInfo.substr(employeeInfo.find(':')+2));
		double savedEPoints = ePoints;
		// Adding the points needed (late or abesnt points)
		if (markedLate) 
			ePoints += settings_latePoints;
		else
			ePoints += settings_absentPoints;

		// Making new employee information string
		employeeInfo = eID + "_" + eFirstName + "_" + eLastName + "_" + doubleToString(ePoints);
		
		// Opening files and writting new file
		ifstream inputfile(employeesFile);
		ofstream writingFile("temp.txt");
		string line;
		if (!inputfile.is_open() || !writingFile.is_open()) {
			MessageBox::Show("Error opening file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		while (getline(inputfile, line)) {
			if (line.empty()) {
				continue;
			}
			string currEmployeeID = line.substr(0, line.find('_'));
			if (currEmployeeID == eID) {
				// writting the new employee info instead of the old one
				writingFile << employeeInfo << endl;
			}
			else {
				// copying over any other employee
				writingFile << line << endl;
			}
		}
		inputfile.close();
		writingFile.close();

		// Deleting the old file and renaming the new file
		if (remove(employeesFile.c_str()) != 0) {
			MessageBox::Show("Error in removing file! Exit and remove file. ERROR: FILE_REMOVE_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (rename("temp.txt", employeesFile.c_str()) != 0) {
			MessageBox::Show("Error in renaming file! Exit and rename if reached. ERROR: RENAME_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}


		// Messaging that everything went good
		MessageBox::Show("Employee's points have been updated.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		
		// Writting to log
		string action = "";
		if (markedLate)
			action = "LATE + " + doubleToString(settings_latePoints) + " pts";
		else
			action = "ABSENT + " + doubleToString(settings_absentPoints) + " pts";
		writeToLog("Marked " + eFirstName + "_" + eLastName + "(" + eID + ")[" + doubleToString(savedEPoints) + " pts] "
			       + action);


		// Resetting the combobox and the listview
		markEmployeeLabel_Click(nullptr, nullptr);

		// Hidding the panel
		markEmployeeActionConfrimPanel->Visible = false;
	}
#pragma endregion
	

#pragma region SETTINGS

// Animation for opening and closing the log panel
	bool logClosed = true;
	bool isAnimating = false;
	bool panelFinished = false;
	bool listViewFinished = false;
	void settingsExpandLogButton_Click(System::Object^ sender, System::EventArgs^ e) {
		isAnimating = true;
		panelFinished = false;
		listViewFinished = false;
		settingsLogsTimer->Start();
	}
	void settingsLogsTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Logs Panel:
		// - closed height = 140
		// - opened height = 360 
		// Logs List view:
		// - closed height = 105
		// - opened height = 320
		
		// If log is currently closed, OPEN IT
		if (logClosed) {
			if (settingsLogsPanel->Height < 355) {
				settingsLogsPanel->Height += 5;
			}
			else {
				panelFinished = true;
			}
			if (settingsLogsListView->Height < 320) {
				settingsLogsListView->Height += 5;
				listViewFinished = true;
			}
			if (panelFinished && listViewFinished) {
				isAnimating = false;
				logClosed = false;
				settingsExpandLogsButton->Text = "Collapse";
				settingsLogsTimer->Stop();
				return;
			}

		}
		// If log is currently opened, CLOSE IT
		else {
			if (settingsLogsPanel->Height > 140) {
				settingsLogsPanel->Height -= 5;
			}
			else {
				panelFinished = true;
			}
			if (settingsLogsListView->Height >  105) {
				settingsLogsListView->Height -= 5;
				listViewFinished = true;
			}
			if (panelFinished && listViewFinished) {
				isAnimating = false;
				logClosed = true;
				settingsExpandLogsButton->Text = "Expand";
				settingsLogsTimer->Stop();
				return;
			}
		}
	}

// Clicking the save attendance points settings button
	void settingsSaveAttendanceButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// Trimming to help prevent errors
		settingsAttendanceLimit->Text = settingsAttendanceLimit->Text->Trim();
		settingsLatePoints->Text = settingsLatePoints->Text->Trim();
		settingsAbsentPoints->Text = settingsAbsentPoints->Text->Trim();


	// Checking if any change was made
		if (settingsAttendanceLimit->Text == readLimit && settingsLatePoints->Text == readLate && settingsAbsentPoints->Text == readAbsent) {
			MessageBox::Show("No change was made.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	// Checking that no value is empty
		if (settingsAttendanceLimit->Text == "" || settingsLatePoints->Text == "" || settingsAbsentPoints->Text == "") {
			MessageBox::Show("Please fill all information.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	// Checking that all values have no letters
		for (int i = 0; i < settingsAttendanceLimit->Text->Length; i++) {
			if ((!isdigit(settingsAttendanceLimit->Text[i]) && settingsAttendanceLimit->Text[i] != '.') || settingsAttendanceLimit->Text[i] == ' ') {
				MessageBox::Show("Please fix attendance limit.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		for (int i = 0; i < settingsLatePoints->Text->Length; i++) {
			if ((!isdigit(settingsLatePoints->Text[i]) && settingsLatePoints->Text[i] != '.') || settingsLatePoints->Text[i] == ' ') {
				MessageBox::Show("Please fix late points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		for (int i = 0; i < settingsAbsentPoints->Text->Length; i++) {
			if ((!isdigit(settingsAbsentPoints->Text[i]) && settingsAbsentPoints->Text[i] != '.') || settingsAbsentPoints->Text[i] == ' ') {
				MessageBox::Show("Please fix absent points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

	// Checking that all values can be converted
		double newLimit = -1, newLate = -1, newAbsent = -1;
		try {
			settingsAttendanceLimit->Text = toHandle(doubleToString(stod(toString(settingsAttendanceLimit->Text))));
		}
		catch (out_of_range) {
			MessageBox::Show("Please fix attendance limit.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		try {
			settingsLatePoints->Text = toHandle(doubleToString(stod(toString(settingsLatePoints->Text))));
		}
		catch (out_of_range) {
			MessageBox::Show("Please fix late points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		try {
			settingsAbsentPoints->Text = toHandle(doubleToString(stod(toString(settingsAbsentPoints->Text))));
		}
		catch (out_of_range) {
			MessageBox::Show("Please fix absent points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

	// Saving new settings to file
		ifstream inputfile(settingsFile);
		ofstream writingFile("temp.txt");
		string line;

		// writing new attendance settings and skipping over those lines in inputFile
		getline(inputfile, line);
		getline(inputfile, line);
		getline(inputfile, line);
		writingFile << "limit=" << toString(settingsAttendanceLimit->Text) << endl;
		writingFile << "late="<< toString(settingsLatePoints->Text) << endl;
		writingFile << "absent=" << toString(settingsAbsentPoints->Text) << endl;

		// writting everything else in settings.txt into writtingFile
		while (getline(inputfile, line)) {
			if (line.empty()) {
				continue;
			}
			writingFile << line << endl;
		}
		inputfile.close();
		writingFile.close();

		// Deleting the old file and renaming the new file
		if (remove(settingsFile.c_str()) != 0) {
			MessageBox::Show("Error in removing file! Exit and remove file. ERROR: FILE_REMOVE_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (rename("temp.txt", settingsFile.c_str()) != 0) {
			MessageBox::Show("Error in renaming file! Exit and rename if reached. ERROR: RENAME_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		// Letting user know settings have been updated
		MessageBox::Show("Attendance Settings have been updated.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Writting into log
		writeToLog("Changed attendanceSettings: [Lim:" + toString(readLimit) + ",Lpts:" + toString(readLate) + ",Apts:" + toString(readAbsent) 
			       + "] -> [Lim:"
		           + toString(settingsAttendanceLimit->Text) + ",Lpts:" + toString(settingsLatePoints->Text) + ",Apts:" + toString(settingsAbsentPoints->Text)
		           + "]");

		// Setting values to saved variables
		settings_PointsLimit = stod(toString(settingsAttendanceLimit->Text));
		settings_latePoints = stod(toString(settingsLatePoints->Text));
		settings_absentPoints = stod(toString(settingsAbsentPoints->Text));


		// Resetting text boxes and updating logs
		settingsLogsLabel_Click(nullptr, nullptr);
		
	}

// Theme radials are changed to another theme
	void settingsThemeButtonChanged(System::Object^ sender, System::EventArgs^ e) {
		if (settingsAttendanceLimit->Text == "SKIP") 
			return;
	

	// Changing variable in code
		if (settingsThemeDefaultButton->Checked) 
			settings_theme = "default";
		
		if (settingsThemeRedButton->Checked) 
			settings_theme = "red";
		
		if (settingsThemeGreenButton->Checked) 
			settings_theme = "green";
		
		if (settingsThemeGrayButton->Checked) 
			settings_theme = "gray";
		

	// Updating the theme using setTheme()
		setTheme();

	// Updating the settings file
		ifstream inputfile(settingsFile);
		ofstream writingFile("temp.txt");
		string line;

		// writing attendance settings straight into new file
		getline(inputfile, line);
		writingFile << line << endl;
		getline(inputfile, line);
		writingFile << line << endl;
		getline(inputfile, line);
		writingFile << line << endl;
		
		// Writing new theme 
		writingFile << "theme=" << toString(settings_theme) << endl;
	
		inputfile.close();
		writingFile.close();

	// Deleting the old file and renaming the new file
		if (remove(settingsFile.c_str()) != 0) {
			MessageBox::Show("Error in removing file! Exit and remove file. ERROR: FILE_REMOVE_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (rename("temp.txt", settingsFile.c_str()) != 0) {
			MessageBox::Show("Error in renaming file! Exit and rename if reached. ERROR: RENAME_FAILED.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

// Pushing the reset all button from settings screen
	void settingsResetAllButton_Click(System::Object^ sender, System::EventArgs^ e) {
		settingsResetAllPasswordInput->Text = "";
		settingsResetAllConfrimPanel->Visible = true;
	}
	void settingsResetAllCancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		settingsResetAllConfrimPanel->Visible = false;
	}


	void settingsResetAllConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Checking password input against saved current users' password
		if (toString(settingsResetAllPasswordInput->Text) != loggedInAdminPassword) {
			MessageBox::Show("Password is not correct.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// If passes, then go ahead and delete all the files
		remove(adminsFile.c_str());
		remove(employeesFile.c_str());
		remove(settingsFile.c_str());
		remove(logsFile.c_str());
		system("rmdir C:\\attendance_v2");

		// Closing client and letting user know it was successfull
		MessageBox::Show("All files have been removed", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Application::Exit();
	}

#pragma endregion


};
}



