#pragma once
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <cstdio>


std::string adminsFile = "C:\\Attendance\\admins.txt";
std::string employeesFile = "C:\\Attendance\\Employees.txt";
std::string logsFile = "C:\\Attendance\\logs.txt";
std::string settingsFile = "C:\\Attendance\\settings.txt";

namespace AttendanceV2 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AttendanceV2 : public System::Windows::Forms::Form
	{
	public:
		AttendanceV2(void){
			InitializeComponent();
		}

	protected:
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
		System::Windows::Forms::Panel^ adminPanel;
		System::Windows::Forms::Panel^ settingsPanel;
		System::Windows::Forms::Label^ addEmployeeButton;
		System::Windows::Forms::Label^ editEmployeeButton;
		System::Windows::Forms::Panel^ addEmployeeWorkPanel;
		System::Windows::Forms::Panel^ editEmployeeWorkPanel;
	protected: System::Windows::Forms::Label^ addEmployeeWorkText3;

	protected: System::Windows::Forms::Label^ addEmployeeWorkText2;

	protected: System::Windows::Forms::Label^ addEmployeeWorkText1;
	protected: System::Windows::Forms::TextBox^ addEmployeeWorkEmployeeID;



	protected: System::Windows::Forms::TextBox^ addEmployeeWorkLastName;

	protected: System::Windows::Forms::TextBox^ addEmployeeWorkFirstName;
	private: System::Windows::Forms::Button^ addEmployeeWorkSaveButton;
	private: System::Windows::Forms::Label^ editEmployeeWorkText1;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ editEmployeeWorkRemoveEmployee;

	private: System::Windows::Forms::Button^ editEmployeeWorkSaveButton;

	private: System::Windows::Forms::Label^ editEmployeeWorkText4;

	private: System::Windows::Forms::Label^ editEmployeeWorkText3;

	private: System::Windows::Forms::Label^ editEmployeeWorkText2;
	private: System::Windows::Forms::TextBox^ editEmployeeWorkCurrentPoints;

	private: System::Windows::Forms::TextBox^ editEmployeeWorkEmployeeID;

	private: System::Windows::Forms::TextBox^ editEmployeeWorkLastName;

	private: System::Windows::Forms::TextBox^ editEmployeeWorkFirstName;

	private: System::Windows::Forms::Label^ editEmployeeWorkText5;



	protected:


	protected:
	private: System::ComponentModel::IContainer^ components;
	protected:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->components = (gcnew System::ComponentModel::Container());
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
			this->editAddEmployeePanel = (gcnew System::Windows::Forms::Panel());
			this->addEmployeeWorkPanel = (gcnew System::Windows::Forms::Panel());
			this->addEmployeeWorkSaveButton = (gcnew System::Windows::Forms::Button());
			this->addEmployeeWorkEmployeeID = (gcnew System::Windows::Forms::TextBox());
			this->addEmployeeWorkLastName = (gcnew System::Windows::Forms::TextBox());
			this->addEmployeeWorkFirstName = (gcnew System::Windows::Forms::TextBox());
			this->addEmployeeWorkText3 = (gcnew System::Windows::Forms::Label());
			this->addEmployeeWorkText2 = (gcnew System::Windows::Forms::Label());
			this->addEmployeeWorkText1 = (gcnew System::Windows::Forms::Label());
			this->editEmployeeButton = (gcnew System::Windows::Forms::Label());
			this->addEmployeeButton = (gcnew System::Windows::Forms::Label());
			this->editEmployeeWorkPanel = (gcnew System::Windows::Forms::Panel());
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->editEmployeeWorkText1 = (gcnew System::Windows::Forms::Label());
			this->adminPanel = (gcnew System::Windows::Forms::Panel());
			this->settingsPanel = (gcnew System::Windows::Forms::Panel());
			this->login_panel->SuspendLayout();
			this->sidePanel->SuspendLayout();
			this->mainMenuSidePanel->SuspendLayout();
			this->settingsLogsButton->SuspendLayout();
			this->adminButton->SuspendLayout();
			this->editAddEmployeeButton->SuspendLayout();
			this->markEmployeeButton->SuspendLayout();
			this->editAddEmployeePanel->SuspendLayout();
			this->addEmployeeWorkPanel->SuspendLayout();
			this->editEmployeeWorkPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// login_username
			// 
			this->login_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_username->Location = System::Drawing::Point(218, 35);
			this->login_username->Margin = System::Windows::Forms::Padding(6);
			this->login_username->Name = L"login_username";
			this->login_username->Size = System::Drawing::Size(330, 38);
			this->login_username->TabIndex = 0;
			this->login_username->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// login_password
			// 
			this->login_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_password->Location = System::Drawing::Point(218, 96);
			this->login_password->Margin = System::Windows::Forms::Padding(6);
			this->login_password->Name = L"login_password";
			this->login_password->Size = System::Drawing::Size(330, 38);
			this->login_password->TabIndex = 1;
			this->login_password->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->login_password->UseSystemPasswordChar = true;
			// 
			// login_text1
			// 
			this->login_text1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_text1->Location = System::Drawing::Point(50, 35);
			this->login_text1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->login_text1->Name = L"login_text1";
			this->login_text1->Size = System::Drawing::Size(156, 44);
			this->login_text1->TabIndex = 2;
			this->login_text1->Text = L"Username:";
			// 
			// login_text2
			// 
			this->login_text2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_text2->Location = System::Drawing::Point(50, 96);
			this->login_text2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->login_text2->Name = L"login_text2";
			this->login_text2->Size = System::Drawing::Size(156, 44);
			this->login_text2->TabIndex = 3;
			this->login_text2->Text = L"Password:";
			// 
			// login_button
			// 
			this->login_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_button->Location = System::Drawing::Point(46, 152);
			this->login_button->Margin = System::Windows::Forms::Padding(6);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(506, 77);
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
			this->login_panel->Location = System::Drawing::Point(77, 720);
			this->login_panel->Margin = System::Windows::Forms::Padding(6);
			this->login_panel->Name = L"login_panel";
			this->login_panel->Size = System::Drawing::Size(574, 258);
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
			this->sidePanel->Margin = System::Windows::Forms::Padding(6);
			this->sidePanel->Name = L"sidePanel";
			this->sidePanel->Size = System::Drawing::Size(68, 710);
			this->sidePanel->TabIndex = 6;
			this->sidePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::openMenu);
			// 
			// mainMenuSidePanel
			// 
			this->mainMenuSidePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->mainMenuSidePanel->BackColor = System::Drawing::Color::Tan;
			this->mainMenuSidePanel->Controls->Add(this->mainMenuSideLabel);
			this->mainMenuSidePanel->Location = System::Drawing::Point(8, -2);
			this->mainMenuSidePanel->Margin = System::Windows::Forms::Padding(6);
			this->mainMenuSidePanel->Name = L"mainMenuSidePanel";
			this->mainMenuSidePanel->Size = System::Drawing::Size(59, 712);
			this->mainMenuSidePanel->TabIndex = 4;
			this->mainMenuSidePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::openMenu);
			// 
			// mainMenuSideLabel
			// 
			this->mainMenuSideLabel->BackColor = System::Drawing::Color::Tan;
			this->mainMenuSideLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->mainMenuSideLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->mainMenuSideLabel->Location = System::Drawing::Point(14, 83);
			this->mainMenuSideLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->mainMenuSideLabel->Name = L"mainMenuSideLabel";
			this->mainMenuSideLabel->Size = System::Drawing::Size(34, 504);
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
			this->settingsLogsButton->Location = System::Drawing::Point(10, 538);
			this->settingsLogsButton->Margin = System::Windows::Forms::Padding(6);
			this->settingsLogsButton->Name = L"settingsLogsButton";
			this->settingsLogsButton->Size = System::Drawing::Size(232, 141);
			this->settingsLogsButton->TabIndex = 1;
			// 
			// settingsLogsLabel
			// 
			this->settingsLogsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->settingsLogsLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->settingsLogsLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->settingsLogsLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->settingsLogsLabel->Location = System::Drawing::Point(-4, -4);
			this->settingsLogsLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->settingsLogsLabel->Name = L"settingsLogsLabel";
			this->settingsLogsLabel->Size = System::Drawing::Size(236, 144);
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
			this->adminButton->Location = System::Drawing::Point(10, 363);
			this->adminButton->Margin = System::Windows::Forms::Padding(6);
			this->adminButton->Name = L"adminButton";
			this->adminButton->Size = System::Drawing::Size(232, 141);
			this->adminButton->TabIndex = 2;
			// 
			// adminLabel
			// 
			this->adminLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->adminLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->adminLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->adminLabel->Location = System::Drawing::Point(-4, -4);
			this->adminLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->adminLabel->Name = L"adminLabel";
			this->adminLabel->Size = System::Drawing::Size(236, 144);
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
			this->editAddEmployeeButton->Location = System::Drawing::Point(10, 190);
			this->editAddEmployeeButton->Margin = System::Windows::Forms::Padding(6);
			this->editAddEmployeeButton->Name = L"editAddEmployeeButton";
			this->editAddEmployeeButton->Size = System::Drawing::Size(232, 141);
			this->editAddEmployeeButton->TabIndex = 1;
			// 
			// editAddEmployeeLabel
			// 
			this->editAddEmployeeLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->editAddEmployeeLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editAddEmployeeLabel->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editAddEmployeeLabel->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->editAddEmployeeLabel->Location = System::Drawing::Point(-4, -4);
			this->editAddEmployeeLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->editAddEmployeeLabel->Name = L"editAddEmployeeLabel";
			this->editAddEmployeeLabel->Size = System::Drawing::Size(236, 144);
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
			this->markEmployeeButton->Location = System::Drawing::Point(10, 19);
			this->markEmployeeButton->Margin = System::Windows::Forms::Padding(6);
			this->markEmployeeButton->Name = L"markEmployeeButton";
			this->markEmployeeButton->Size = System::Drawing::Size(232, 141);
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
			this->markEmployeeLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->markEmployeeLabel->Name = L"markEmployeeLabel";
			this->markEmployeeLabel->Size = System::Drawing::Size(236, 144);
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
			this->markEmployeePanel->BackColor = System::Drawing::Color::Maroon;
			this->markEmployeePanel->Location = System::Drawing::Point(701, 590);
			this->markEmployeePanel->Name = L"markEmployeePanel";
			this->markEmployeePanel->Size = System::Drawing::Size(992, 711);
			this->markEmployeePanel->TabIndex = 7;
			this->markEmployeePanel->Visible = false;
			this->markEmployeePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// editAddEmployeePanel
			// 
			this->editAddEmployeePanel->BackColor = System::Drawing::Color::Sienna;
			this->editAddEmployeePanel->Controls->Add(this->addEmployeeWorkPanel);
			this->editAddEmployeePanel->Controls->Add(this->editEmployeeButton);
			this->editAddEmployeePanel->Controls->Add(this->addEmployeeButton);
			this->editAddEmployeePanel->Controls->Add(this->editEmployeeWorkPanel);
			this->editAddEmployeePanel->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->editAddEmployeePanel->Location = System::Drawing::Point(59, 0);
			this->editAddEmployeePanel->Name = L"editAddEmployeePanel";
			this->editAddEmployeePanel->Size = System::Drawing::Size(992, 711);
			this->editAddEmployeePanel->TabIndex = 8;
			this->editAddEmployeePanel->Visible = false;
			this->editAddEmployeePanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// addEmployeeWorkPanel
			// 
			this->addEmployeeWorkPanel->BackColor = System::Drawing::Color::Tan;
			this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkSaveButton);
			this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkEmployeeID);
			this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkLastName);
			this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkFirstName);
			this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkText3);
			this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkText2);
			this->addEmployeeWorkPanel->Controls->Add(this->addEmployeeWorkText1);
			this->addEmployeeWorkPanel->Location = System::Drawing::Point(931, 528);
			this->addEmployeeWorkPanel->Name = L"addEmployeeWorkPanel";
			this->addEmployeeWorkPanel->Size = System::Drawing::Size(954, 581);
			this->addEmployeeWorkPanel->TabIndex = 2;
			this->addEmployeeWorkPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// addEmployeeWorkSaveButton
			// 
			this->addEmployeeWorkSaveButton->BackColor = System::Drawing::Color::Moccasin;
			this->addEmployeeWorkSaveButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->addEmployeeWorkSaveButton->Location = System::Drawing::Point(69, 422);
			this->addEmployeeWorkSaveButton->Name = L"addEmployeeWorkSaveButton";
			this->addEmployeeWorkSaveButton->Size = System::Drawing::Size(821, 92);
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
			this->addEmployeeWorkEmployeeID->Location = System::Drawing::Point(392, 291);
			this->addEmployeeWorkEmployeeID->Name = L"addEmployeeWorkEmployeeID";
			this->addEmployeeWorkEmployeeID->Size = System::Drawing::Size(490, 51);
			this->addEmployeeWorkEmployeeID->TabIndex = 6;
			this->addEmployeeWorkEmployeeID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// addEmployeeWorkLastName
			// 
			this->addEmployeeWorkLastName->BackColor = System::Drawing::Color::Moccasin;
			this->addEmployeeWorkLastName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
			this->addEmployeeWorkLastName->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->addEmployeeWorkLastName->Location = System::Drawing::Point(392, 190);
			this->addEmployeeWorkLastName->Name = L"addEmployeeWorkLastName";
			this->addEmployeeWorkLastName->Size = System::Drawing::Size(490, 51);
			this->addEmployeeWorkLastName->TabIndex = 5;
			this->addEmployeeWorkLastName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// addEmployeeWorkFirstName
			// 
			this->addEmployeeWorkFirstName->BackColor = System::Drawing::Color::Moccasin;
			this->addEmployeeWorkFirstName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 14, System::Drawing::FontStyle::Bold));
			this->addEmployeeWorkFirstName->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->addEmployeeWorkFirstName->Location = System::Drawing::Point(392, 85);
			this->addEmployeeWorkFirstName->Name = L"addEmployeeWorkFirstName";
			this->addEmployeeWorkFirstName->Size = System::Drawing::Size(490, 51);
			this->addEmployeeWorkFirstName->TabIndex = 4;
			this->addEmployeeWorkFirstName->Text = L"testing";
			this->addEmployeeWorkFirstName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// addEmployeeWorkText3
			// 
			this->addEmployeeWorkText3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->addEmployeeWorkText3->Location = System::Drawing::Point(72, 291);
			this->addEmployeeWorkText3->Name = L"addEmployeeWorkText3";
			this->addEmployeeWorkText3->Size = System::Drawing::Size(241, 51);
			this->addEmployeeWorkText3->TabIndex = 2;
			this->addEmployeeWorkText3->Text = L"Employee ID:";
			this->addEmployeeWorkText3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// addEmployeeWorkText2
			// 
			this->addEmployeeWorkText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->addEmployeeWorkText2->Location = System::Drawing::Point(87, 190);
			this->addEmployeeWorkText2->Name = L"addEmployeeWorkText2";
			this->addEmployeeWorkText2->Size = System::Drawing::Size(226, 51);
			this->addEmployeeWorkText2->TabIndex = 1;
			this->addEmployeeWorkText2->Text = L"Last Name:";
			this->addEmployeeWorkText2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// addEmployeeWorkText1
			// 
			this->addEmployeeWorkText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->addEmployeeWorkText1->Location = System::Drawing::Point(87, 85);
			this->addEmployeeWorkText1->Name = L"addEmployeeWorkText1";
			this->addEmployeeWorkText1->Size = System::Drawing::Size(226, 51);
			this->addEmployeeWorkText1->TabIndex = 0;
			this->addEmployeeWorkText1->Text = L"First Name:";
			this->addEmployeeWorkText1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// editEmployeeButton
			// 
			this->editEmployeeButton->BackColor = System::Drawing::Color::Tan;
			this->editEmployeeButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->editEmployeeButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editEmployeeButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeButton->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->editEmployeeButton->Location = System::Drawing::Point(501, 12);
			this->editEmployeeButton->Name = L"editEmployeeButton";
			this->editEmployeeButton->Size = System::Drawing::Size(471, 91);
			this->editEmployeeButton->TabIndex = 1;
			this->editEmployeeButton->Text = L"Edit Employee";
			this->editEmployeeButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->editEmployeeButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeButton_Click);
			this->editEmployeeButton->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// addEmployeeButton
			// 
			this->addEmployeeButton->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->addEmployeeButton->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->addEmployeeButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addEmployeeButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->addEmployeeButton->ForeColor = System::Drawing::Color::White;
			this->addEmployeeButton->Location = System::Drawing::Point(18, 12);
			this->addEmployeeButton->Name = L"addEmployeeButton";
			this->addEmployeeButton->Size = System::Drawing::Size(471, 91);
			this->addEmployeeButton->TabIndex = 0;
			this->addEmployeeButton->Text = L"Add Employee";
			this->addEmployeeButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->addEmployeeButton->Click += gcnew System::EventHandler(this, &AttendanceV2::addEmployeeButton_Click);
			this->addEmployeeButton->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// editEmployeeWorkPanel
			// 
			this->editEmployeeWorkPanel->BackColor = System::Drawing::Color::Tan;
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
			this->editEmployeeWorkPanel->Controls->Add(this->comboBox1);
			this->editEmployeeWorkPanel->Controls->Add(this->editEmployeeWorkText1);
			this->editEmployeeWorkPanel->Location = System::Drawing::Point(18, 118);
			this->editEmployeeWorkPanel->Name = L"editEmployeeWorkPanel";
			this->editEmployeeWorkPanel->Size = System::Drawing::Size(954, 581);
			this->editEmployeeWorkPanel->TabIndex = 3;
			this->editEmployeeWorkPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// editEmployeeWorkCurrentPoints
			// 
			this->editEmployeeWorkCurrentPoints->BackColor = System::Drawing::Color::Moccasin;
			this->editEmployeeWorkCurrentPoints->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkCurrentPoints->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->editEmployeeWorkCurrentPoints->Location = System::Drawing::Point(425, 357);
			this->editEmployeeWorkCurrentPoints->Name = L"editEmployeeWorkCurrentPoints";
			this->editEmployeeWorkCurrentPoints->Size = System::Drawing::Size(458, 45);
			this->editEmployeeWorkCurrentPoints->TabIndex = 6;
			this->editEmployeeWorkCurrentPoints->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// editEmployeeWorkEmployeeID
			// 
			this->editEmployeeWorkEmployeeID->BackColor = System::Drawing::Color::Moccasin;
			this->editEmployeeWorkEmployeeID->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkEmployeeID->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->editEmployeeWorkEmployeeID->Location = System::Drawing::Point(425, 285);
			this->editEmployeeWorkEmployeeID->Name = L"editEmployeeWorkEmployeeID";
			this->editEmployeeWorkEmployeeID->Size = System::Drawing::Size(458, 45);
			this->editEmployeeWorkEmployeeID->TabIndex = 5;
			this->editEmployeeWorkEmployeeID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// editEmployeeWorkLastName
			// 
			this->editEmployeeWorkLastName->BackColor = System::Drawing::Color::Moccasin;
			this->editEmployeeWorkLastName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkLastName->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->editEmployeeWorkLastName->Location = System::Drawing::Point(425, 214);
			this->editEmployeeWorkLastName->Name = L"editEmployeeWorkLastName";
			this->editEmployeeWorkLastName->Size = System::Drawing::Size(458, 45);
			this->editEmployeeWorkLastName->TabIndex = 4;
			this->editEmployeeWorkLastName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// editEmployeeWorkFirstName
			// 
			this->editEmployeeWorkFirstName->BackColor = System::Drawing::Color::Moccasin;
			this->editEmployeeWorkFirstName->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkFirstName->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->editEmployeeWorkFirstName->Location = System::Drawing::Point(425, 144);
			this->editEmployeeWorkFirstName->Name = L"editEmployeeWorkFirstName";
			this->editEmployeeWorkFirstName->Size = System::Drawing::Size(458, 45);
			this->editEmployeeWorkFirstName->TabIndex = 3;
			this->editEmployeeWorkFirstName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// editEmployeeWorkText5
			// 
			this->editEmployeeWorkText5->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkText5->Location = System::Drawing::Point(58, 355);
			this->editEmployeeWorkText5->Name = L"editEmployeeWorkText5";
			this->editEmployeeWorkText5->Size = System::Drawing::Size(270, 46);
			this->editEmployeeWorkText5->TabIndex = 8;
			this->editEmployeeWorkText5->Text = L"Current Points:";
			this->editEmployeeWorkText5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// editEmployeeWorkRemoveEmployee
			// 
			this->editEmployeeWorkRemoveEmployee->BackColor = System::Drawing::Color::Red;
			this->editEmployeeWorkRemoveEmployee->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 9, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkRemoveEmployee->ForeColor = System::Drawing::Color::White;
			this->editEmployeeWorkRemoveEmployee->Location = System::Drawing::Point(64, 434);
			this->editEmployeeWorkRemoveEmployee->Name = L"editEmployeeWorkRemoveEmployee";
			this->editEmployeeWorkRemoveEmployee->Size = System::Drawing::Size(248, 80);
			this->editEmployeeWorkRemoveEmployee->TabIndex = 8;
			this->editEmployeeWorkRemoveEmployee->Text = L"Remove Employee";
			this->editEmployeeWorkRemoveEmployee->UseVisualStyleBackColor = false;
			this->editEmployeeWorkRemoveEmployee->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeWorkRemoveEmployee_Click);
			// 
			// editEmployeeWorkSaveButton
			// 
			this->editEmployeeWorkSaveButton->BackColor = System::Drawing::Color::Moccasin;
			this->editEmployeeWorkSaveButton->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkSaveButton->Location = System::Drawing::Point(324, 434);
			this->editEmployeeWorkSaveButton->Name = L"editEmployeeWorkSaveButton";
			this->editEmployeeWorkSaveButton->Size = System::Drawing::Size(599, 80);
			this->editEmployeeWorkSaveButton->TabIndex = 7;
			this->editEmployeeWorkSaveButton->Text = L"Save Employee";
			this->editEmployeeWorkSaveButton->UseVisualStyleBackColor = false;
			this->editEmployeeWorkSaveButton->Click += gcnew System::EventHandler(this, &AttendanceV2::editEmployeeWorkSaveButton_Click);
			// 
			// editEmployeeWorkText4
			// 
			this->editEmployeeWorkText4->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkText4->Location = System::Drawing::Point(72, 283);
			this->editEmployeeWorkText4->Name = L"editEmployeeWorkText4";
			this->editEmployeeWorkText4->Size = System::Drawing::Size(256, 46);
			this->editEmployeeWorkText4->TabIndex = 5;
			this->editEmployeeWorkText4->Text = L"Employee ID:";
			this->editEmployeeWorkText4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// editEmployeeWorkText3
			// 
			this->editEmployeeWorkText3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkText3->Location = System::Drawing::Point(100, 212);
			this->editEmployeeWorkText3->Name = L"editEmployeeWorkText3";
			this->editEmployeeWorkText3->Size = System::Drawing::Size(228, 46);
			this->editEmployeeWorkText3->TabIndex = 4;
			this->editEmployeeWorkText3->Text = L"Last Name:";
			this->editEmployeeWorkText3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// editEmployeeWorkText2
			// 
			this->editEmployeeWorkText2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkText2->Location = System::Drawing::Point(100, 142);
			this->editEmployeeWorkText2->Name = L"editEmployeeWorkText2";
			this->editEmployeeWorkText2->Size = System::Drawing::Size(228, 46);
			this->editEmployeeWorkText2->TabIndex = 3;
			this->editEmployeeWorkText2->Text = L"First Name:";
			this->editEmployeeWorkText2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->BackColor = System::Drawing::Color::Moccasin;
			this->comboBox1->DropDownHeight = 160;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 13, System::Drawing::FontStyle::Bold));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->IntegralHeight = false;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"test", L"testing" });
			this->comboBox1->Location = System::Drawing::Point(83, 63);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(800, 48);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &AttendanceV2::comboBox1_SelectedIndexChanged);
			// 
			// editEmployeeWorkText1
			// 
			this->editEmployeeWorkText1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12, System::Drawing::FontStyle::Bold));
			this->editEmployeeWorkText1->Location = System::Drawing::Point(296, 0);
			this->editEmployeeWorkText1->Name = L"editEmployeeWorkText1";
			this->editEmployeeWorkText1->Size = System::Drawing::Size(375, 60);
			this->editEmployeeWorkText1->TabIndex = 1;
			this->editEmployeeWorkText1->Text = L"Choose an Employee:";
			this->editEmployeeWorkText1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// adminPanel
			// 
			this->adminPanel->BackColor = System::Drawing::Color::MediumPurple;
			this->adminPanel->Location = System::Drawing::Point(831, 510);
			this->adminPanel->Name = L"adminPanel";
			this->adminPanel->Size = System::Drawing::Size(992, 711);
			this->adminPanel->TabIndex = 9;
			this->adminPanel->Visible = false;
			this->adminPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// settingsPanel
			// 
			this->settingsPanel->BackColor = System::Drawing::Color::CornflowerBlue;
			this->settingsPanel->Location = System::Drawing::Point(901, 483);
			this->settingsPanel->Name = L"settingsPanel";
			this->settingsPanel->Size = System::Drawing::Size(992, 711);
			this->settingsPanel->TabIndex = 10;
			this->settingsPanel->Visible = false;
			this->settingsPanel->MouseEnter += gcnew System::EventHandler(this, &AttendanceV2::closeMenu);
			// 
			// AttendanceV2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Sienna;
			this->ClientSize = System::Drawing::Size(1041, 733);
			this->Controls->Add(this->sidePanel);
			this->Controls->Add(this->editAddEmployeePanel);
			this->Controls->Add(this->settingsPanel);
			this->Controls->Add(this->login_panel);
			this->Controls->Add(this->adminPanel);
			this->Controls->Add(this->markEmployeePanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"AttendanceV2";
			this->ShowIcon = false;
			this->Text = L"Attendance";
			this->Load += gcnew System::EventHandler(this, &AttendanceV2::AttendanceV2_Load);
			this->login_panel->ResumeLayout(false);
			this->login_panel->PerformLayout();
			this->sidePanel->ResumeLayout(false);
			this->mainMenuSidePanel->ResumeLayout(false);
			this->settingsLogsButton->ResumeLayout(false);
			this->adminButton->ResumeLayout(false);
			this->editAddEmployeeButton->ResumeLayout(false);
			this->markEmployeeButton->ResumeLayout(false);
			this->editAddEmployeePanel->ResumeLayout(false);
			this->addEmployeeWorkPanel->ResumeLayout(false);
			this->addEmployeeWorkPanel->PerformLayout();
			this->editEmployeeWorkPanel->ResumeLayout(false);
			this->editEmployeeWorkPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

// Helper Functions:
	string toString(String^ str) {
		return msclr::interop::marshal_as<std::string>(str);
	}

		System::Void AttendanceV2_Load(System::Object^ sender, System::EventArgs^ e) {
			//  Resetting the login text and panel location/vis.
			login_username->Text = "";
			login_password->Text = "";
			login_panel->Location = Point(12, 12);
			login_panel->Visible = true;

			// Changing size of client back to small
			this->ClientSize = Drawing::Size(316, 162);

			// Making everything else invisible
			sidePanel->Visible = false;
			markEmployeePanel->Visible = false;

		}
	

		System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e) {
			// Hiding panel and resizing client
			login_panel->Visible = false;
			this->ClientSize = Drawing::Size(530, 370);
			
			// Making side panel visible and "opening" it
			sidePanel->Visible = true;
			sidePanel->Width = 160;

			
			// Repositionioning panels AND repainting all panels
			repositionMainPanels(); 
			rePaintAllPanels();

		}


// Animation of opening/closing main menu
		bool animationIsOpening = false;

	// Opening and closing menu functions using MOUSE MOVEMENTS
	System::Void openMenu(System::Object^ sender, System::EventArgs^ e) {
		sideMenuTimer->Start();
		animationIsOpening = true; // using this to say that we are OPENING
	}

	System::Void closeMenu(System::Object^ sender, System::EventArgs^ e) {
		sideMenuTimer->Start();
		animationIsOpening = false; // using this to say that we are CLOSING
	}

	// ANIMATION FOR SIDE MENU
	System::Void sideMenuTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (animationIsOpening) {
			// If menu is opening, do this animation
			if (sidePanel->Width <= 150) {
				sidePanel->Width += 10;
			}
			else {
				sideMenuTimer->Stop();
				animationIsOpening = true;
			}
		}
		else {
			// If menu is closing, do this animation
			if (sidePanel->Width >= 40) {
				sidePanel->Width -= 10;
			}
			else {
				sideMenuTimer->Stop();
				animationIsOpening = false;
			}
		}
	}


// Repositioning panels function
	void repositionMainPanels() {
		// Repositoning the panels
		markEmployeePanel->Location    = Point(32, 2);
		editAddEmployeePanel->Location = Point(32, 2);
		adminPanel->Location           = Point(32, 2);
		settingsPanel->Location        = Point(32, 2);
	}

	void rePaintAllPanels() {
		// Main panels
		markEmployeePanel->BackColor    = backColor;
		editAddEmployeePanel->BackColor = backColor;
		adminPanel->BackColor           = backColor;
		settingsPanel->BackColor        = backColor;

		// Side menu 
		sidePanel->BackColor             = thirdBackColor;
		markEmployeeButton->BackColor    = secondBackColor;
		editAddEmployeeButton->BackColor = secondBackColor;
		adminButton->BackColor           = secondBackColor;
		settingsLogsButton->BackColor    = secondBackColor;
		mainMenuSidePanel->BackColor     = secondBackColor;
		mainMenuSideLabel->ForeColor     = textColor;
		markEmployeeLabel->ForeColor     = textColor;
		editAddEmployeeLabel->ForeColor  = textColor;
		adminLabel->ForeColor            = textColor;
		settingsLogsLabel->ForeColor     = textColor;
		mainMenuSideLabel->BackColor     = secondBackColor;

		// Edit/Add Employee Panel
		  // Top Selection Buttons
		addEmployeeButton->BackColor = secondBackColor;
		addEmployeeButton->ForeColor = textColor;
		editEmployeeButton->BackColor = secondBackColor;
		editEmployeeButton->ForeColor = textColor;
		  // Add Employee Work Panel
		addEmployeeWorkPanel->Location = Point(9, 60);
		addEmployeeWorkPanel->BackColor = secondBackColor;
		addEmployeeWorkText1->ForeColor = textColor;
		addEmployeeWorkText2->ForeColor = textColor;
		addEmployeeWorkText3->ForeColor = textColor;
		addEmployeeWorkFirstName->ForeColor = textColor;
		addEmployeeWorkLastName->ForeColor = textColor;
		addEmployeeWorkEmployeeID->ForeColor = textColor;
		addEmployeeWorkSaveButton->ForeColor = textColor;
		addEmployeeWorkFirstName->BackColor = thirdBackColor;
		addEmployeeWorkLastName->BackColor = thirdBackColor;
		addEmployeeWorkEmployeeID->BackColor = thirdBackColor;
		addEmployeeWorkSaveButton->BackColor = thirdBackColor;
		  // Edit Employee Work Panel
		editEmployeeWorkPanel->Location = Point(9, 60);
		editEmployeeWorkPanel->BackColor = secondBackColor;
		comboBox1->ForeColor = textColor;
		comboBox1->BackColor = thirdBackColor;
		editEmployeeWorkText1->ForeColor = textColor;
		editEmployeeWorkText1->BackColor = secondBackColor;
		editEmployeeWorkText2->ForeColor = textColor;
		editEmployeeWorkText2->BackColor = secondBackColor;
		editEmployeeWorkText3->ForeColor = textColor;
		editEmployeeWorkText3->BackColor = secondBackColor;
		editEmployeeWorkText4->ForeColor = textColor;
		editEmployeeWorkText4->BackColor = secondBackColor;
		editEmployeeWorkText5->ForeColor = textColor;
		editEmployeeWorkText5->BackColor = secondBackColor;
		editEmployeeWorkCurrentPoints->ForeColor = textColor;
		editEmployeeWorkCurrentPoints->BackColor = thirdBackColor;
		editEmployeeWorkFirstName->ForeColor = textColor;
		editEmployeeWorkFirstName->BackColor = thirdBackColor;
		editEmployeeWorkLastName->ForeColor = textColor;
		editEmployeeWorkLastName->BackColor = thirdBackColor;
		editEmployeeWorkEmployeeID->ForeColor = textColor;
		editEmployeeWorkEmployeeID->BackColor = thirdBackColor;
		editEmployeeWorkCurrentPoints->ForeColor = textColor;
		editEmployeeWorkCurrentPoints->BackColor = thirdBackColor;


		



	}

// Hiding all panels funtion
	void hidePanels() {
		markEmployeePanel->Visible    = false;
		editAddEmployeePanel->Visible = false;
		adminPanel->Visible           = false;
		settingsPanel->Visible        = false;
	}

// Clicking on side menu buttons
	System::Void editAddEmployeeLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		// Hiding other panels and showing this one
		hidePanels();
		editAddEmployeePanel->Visible = true;	

		// Hiding the two working panels
		addEmployeeWorkPanel->Visible = false;
		editEmployeeWorkPanel->Visible = false;
	}

	System::Void markEmployeeLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		// -- red panel -- 
		// Hiding other panels and showing this one
		hidePanels();
		markEmployeePanel->Visible = true;
	}

	System::Void adminLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		// -- purple panel --
		hidePanels();
		adminPanel->Visible = true;
	}

	System::Void settingsLogsLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		// -- Blue panel --
		hidePanels();
		settingsPanel->Visible = true;
	}







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
			if (addEmployeeWorkFirstName->Text[i] == '_') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		for (int i = 0; i < addEmployeeWorkLastName->Text->Length; i++) {
			if (addEmployeeWorkLastName->Text[i] == '_') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
			if (!Char::IsDigit(addEmployeeWorkEmployeeID->Text[i])) {
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
		writingEmployee << "_0" << endl;
		writingEmployee.close();

		
		MessageBox::Show("Employee added successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		
		// Resetting the textboxes
		addEmployeeWorkFirstName->Text = "";
		addEmployeeWorkLastName->Text = "";
		addEmployeeWorkEmployeeID->Text = "";
	}





 // EDIT EMPLOYEE:
	// Entering the Edit Employee panel
	System::Void editEmployeeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Setting this button to be active
		editEmployeeButton->BackColor = buttonPushedBackColor;
		editEmployeeButton->ForeColor = buttonPushedForeColor;
		// Setting the other button to be inactive
		addEmployeeButton->BackColor = secondBackColor;
		addEmployeeButton->ForeColor = textColor;

		// Making add employee working panel invisible
		addEmployeeWorkPanel->Visible = false;

		// Resetting the combobox and text boxes
		comboBox1->Items->Clear();
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
			comboBox1->Items->Add(employee);
		}
		file.close();
		
		// Making visible once everything is finished loading
		editEmployeeWorkPanel->Visible = true;

	}

	// User selected an employee
	int savedEmployeeID = -1;
	System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Returning if no employee is selected
		if (comboBox1->SelectedIndex == -1) {
			return;
		}	


		// Getting the selected employee
		string employee = toString(comboBox1->SelectedItem->ToString());
		string employeeFirstName = employee.substr(0, employee.find(' '));

		employee = employee.substr(employee.find(' ') + 1);
		string employeeLastName = employee.substr(0, employee.find(' '));

		employee = employee.substr(employee.find(':') + 2);
		string employeeID = employee.substr(0, employee.find(':') - 1);

		string employeePoints = employee.substr(employee.find(':') + 2);
		
		// Saving the employee ID
		savedEmployeeID = stoi(employeeID);
			
		// Setting the text boxes
		editEmployeeWorkFirstName->Text = gcnew String(employeeFirstName.c_str());
		editEmployeeWorkLastName->Text = gcnew String(employeeLastName.c_str());
		editEmployeeWorkEmployeeID->Text = gcnew String(employeeID.c_str());
		editEmployeeWorkCurrentPoints->Text = gcnew String(employeePoints.c_str());
	}

	// Save employee button is clicked
	void editEmployeeWorkSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// CHECKING IF EMPLOYEE IS SELECTED
		if (comboBox1->SelectedIndex == -1) {
			MessageBox::Show("Please select an employee.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

	// CHECKING VALID INPUTS:
		// Cleaning spaces from text boxes
		editEmployeeWorkFirstName->Text     = editEmployeeWorkFirstName->Text->Trim();
		editEmployeeWorkLastName->Text      = editEmployeeWorkLastName->Text->Trim();
		editEmployeeWorkEmployeeID->Text    = editEmployeeWorkEmployeeID->Text->Trim();
		editEmployeeWorkCurrentPoints->Text = editEmployeeWorkCurrentPoints->Text->Trim();

		

		// Checking if first and last name are inputted
		if (editEmployeeWorkFirstName->Text == "" || editEmployeeWorkLastName->Text == "") {
			MessageBox::Show("Please fill in employee's name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Checking if first and last name doesn't contain '_'
		for (int i = 0; i < editEmployeeWorkFirstName->Text->Length; i++) {
			if (editEmployeeWorkFirstName->Text[i] == '_') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		for (int i = 0; i < editEmployeeWorkLastName->Text->Length; i++) {
			if (editEmployeeWorkLastName->Text[i] == '_') {
				MessageBox::Show("First/Last Names can not have an UNDERSCORE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
			if (!Char::IsDigit(editEmployeeWorkEmployeeID->Text[i])) {
				MessageBox::Show("Please enter only digits for Employee ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		// Checking if points is only digits (will not allow for decimals [no need])
		for (int i = 0; i < editEmployeeWorkCurrentPoints->Text->Length; i++) {
			if (!Char::IsDigit(editEmployeeWorkCurrentPoints->Text[i])) {
				MessageBox::Show("Please enter only digits for Points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		// Checking if Employee ID is unique (AGAINST: the list we have in the combobox)
		for (int i = 0; i < comboBox1->Items->Count; i++) {
			string comparingEmployee = toString(comboBox1->Items[i]->ToString());
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
		string employeeInfo = toString(editEmployeeWorkEmployeeID->Text) + "_" + toString(editEmployeeWorkFirstName->Text) + "_" + toString(editEmployeeWorkLastName->Text) + "_" + toString(editEmployeeWorkCurrentPoints->Text);
		
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
		
		// Resetting the textboxes
		editEmployeeWorkFirstName->Text = "";
		editEmployeeWorkLastName->Text = "";
		editEmployeeWorkEmployeeID->Text = "";
		editEmployeeWorkCurrentPoints->Text = "";
		comboBox1->Items->Clear();
		comboBox1->SelectedIndex = -1;
		comboBox1->Text = "";
		savedEmployeeID = -1;


		// Resetting the combobox
		editEmployeeButton_Click(nullptr, nullptr);
	}

	// Remove Employee button is clicked
	void editEmployeeWorkRemoveEmployee_Click(System::Object^ sender, System::EventArgs^ e) {

	}

// -----------------------------------------------------------------------------------





};
}
