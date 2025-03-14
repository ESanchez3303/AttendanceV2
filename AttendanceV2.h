#pragma once
#include <fstream>
#include <iostream>
#include <Windows.h>

namespace AttendanceV2 {

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
	private: System::Windows::Forms::TextBox^ login_username;
	protected:
	private: System::Windows::Forms::TextBox^ login_password;
	private: System::Windows::Forms::Label^ login_text1;
	private: System::Windows::Forms::Label^ login_text2;


	private: System::Windows::Forms::Button^ login_button;

	private: System::Windows::Forms::Panel^ login_panel;
	private: System::Windows::Forms::Panel^ sidePanel;
	private: System::Windows::Forms::Panel^ markEmployeePanel;
	private: System::Windows::Forms::Panel^ settingsLogsPanel;


	private: System::Windows::Forms::Panel^ adminPanel;

	private: System::Windows::Forms::Panel^ editAddEmployeePanel;

	private: System::Windows::Forms::Label^ settingsLogsLabel;
	private: System::Windows::Forms::Label^ adminLabel;
	private: System::Windows::Forms::Label^ editAddEmployeeLabel;





	private: System::Windows::Forms::Label^ markEmployeeLabel;
	private: System::Windows::Forms::Label^ mainMenuSideLabel;


	private: System::Windows::Forms::Panel^ mainMenuSidePanel;







	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->login_username = (gcnew System::Windows::Forms::TextBox());
			this->login_password = (gcnew System::Windows::Forms::TextBox());
			this->login_text1 = (gcnew System::Windows::Forms::Label());
			this->login_text2 = (gcnew System::Windows::Forms::Label());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->login_panel = (gcnew System::Windows::Forms::Panel());
			this->sidePanel = (gcnew System::Windows::Forms::Panel());
			this->markEmployeePanel = (gcnew System::Windows::Forms::Panel());
			this->editAddEmployeePanel = (gcnew System::Windows::Forms::Panel());
			this->adminPanel = (gcnew System::Windows::Forms::Panel());
			this->settingsLogsPanel = (gcnew System::Windows::Forms::Panel());
			this->markEmployeeLabel = (gcnew System::Windows::Forms::Label());
			this->editAddEmployeeLabel = (gcnew System::Windows::Forms::Label());
			this->adminLabel = (gcnew System::Windows::Forms::Label());
			this->settingsLogsLabel = (gcnew System::Windows::Forms::Label());
			this->mainMenuSideLabel = (gcnew System::Windows::Forms::Label());
			this->mainMenuSidePanel = (gcnew System::Windows::Forms::Panel());
			this->login_panel->SuspendLayout();
			this->sidePanel->SuspendLayout();
			this->markEmployeePanel->SuspendLayout();
			this->editAddEmployeePanel->SuspendLayout();
			this->adminPanel->SuspendLayout();
			this->settingsLogsPanel->SuspendLayout();
			this->mainMenuSidePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// login_username
			// 
			this->login_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_username->Location = System::Drawing::Point(109, 18);
			this->login_username->Name = L"login_username";
			this->login_username->Size = System::Drawing::Size(167, 23);
			this->login_username->TabIndex = 0;
			this->login_username->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// login_password
			// 
			this->login_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_password->Location = System::Drawing::Point(109, 50);
			this->login_password->Name = L"login_password";
			this->login_password->Size = System::Drawing::Size(167, 23);
			this->login_password->TabIndex = 1;
			this->login_password->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->login_password->UseSystemPasswordChar = true;
			// 
			// login_text1
			// 
			this->login_text1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_text1->Location = System::Drawing::Point(25, 18);
			this->login_text1->Name = L"login_text1";
			this->login_text1->Size = System::Drawing::Size(78, 23);
			this->login_text1->TabIndex = 2;
			this->login_text1->Text = L"Username:";
			// 
			// login_text2
			// 
			this->login_text2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_text2->Location = System::Drawing::Point(25, 50);
			this->login_text2->Name = L"login_text2";
			this->login_text2->Size = System::Drawing::Size(78, 23);
			this->login_text2->TabIndex = 3;
			this->login_text2->Text = L"Password:";
			// 
			// login_button
			// 
			this->login_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_button->Location = System::Drawing::Point(23, 79);
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
			this->login_panel->Location = System::Drawing::Point(437, 307);
			this->login_panel->Name = L"login_panel";
			this->login_panel->Size = System::Drawing::Size(289, 136);
			this->login_panel->TabIndex = 5;
			// 
			// sidePanel
			// 
			this->sidePanel->BackColor = System::Drawing::Color::Moccasin;
			this->sidePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->sidePanel->Controls->Add(this->mainMenuSidePanel);
			this->sidePanel->Controls->Add(this->settingsLogsPanel);
			this->sidePanel->Controls->Add(this->adminPanel);
			this->sidePanel->Controls->Add(this->editAddEmployeePanel);
			this->sidePanel->Controls->Add(this->markEmployeePanel);
			this->sidePanel->Location = System::Drawing::Point(0, 0);
			this->sidePanel->Name = L"sidePanel";
			this->sidePanel->Size = System::Drawing::Size(162, 370);
			this->sidePanel->TabIndex = 6;
			// 
			// markEmployeePanel
			// 
			this->markEmployeePanel->BackColor = System::Drawing::Color::Tan;
			this->markEmployeePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->markEmployeePanel->Controls->Add(this->markEmployeeLabel);
			this->markEmployeePanel->Location = System::Drawing::Point(5, 10);
			this->markEmployeePanel->Name = L"markEmployeePanel";
			this->markEmployeePanel->Size = System::Drawing::Size(118, 75);
			this->markEmployeePanel->TabIndex = 0;
			// 
			// editAddEmployeePanel
			// 
			this->editAddEmployeePanel->BackColor = System::Drawing::Color::Tan;
			this->editAddEmployeePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->editAddEmployeePanel->Controls->Add(this->editAddEmployeeLabel);
			this->editAddEmployeePanel->Location = System::Drawing::Point(5, 99);
			this->editAddEmployeePanel->Name = L"editAddEmployeePanel";
			this->editAddEmployeePanel->Size = System::Drawing::Size(118, 75);
			this->editAddEmployeePanel->TabIndex = 1;
			// 
			// adminPanel
			// 
			this->adminPanel->BackColor = System::Drawing::Color::Tan;
			this->adminPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->adminPanel->Controls->Add(this->adminLabel);
			this->adminPanel->Location = System::Drawing::Point(5, 189);
			this->adminPanel->Name = L"adminPanel";
			this->adminPanel->Size = System::Drawing::Size(118, 75);
			this->adminPanel->TabIndex = 2;
			// 
			// settingsLogsPanel
			// 
			this->settingsLogsPanel->BackColor = System::Drawing::Color::Tan;
			this->settingsLogsPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->settingsLogsPanel->Controls->Add(this->settingsLogsLabel);
			this->settingsLogsPanel->Location = System::Drawing::Point(5, 280);
			this->settingsLogsPanel->Name = L"settingsLogsPanel";
			this->settingsLogsPanel->Size = System::Drawing::Size(118, 75);
			this->settingsLogsPanel->TabIndex = 1;
			// 
			// markEmployeeLabel
			// 
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
			// 
			// editAddEmployeeLabel
			// 
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
			// 
			// adminLabel
			// 
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
			// 
			// settingsLogsLabel
			// 
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
			// 
			// mainMenuSidePanel
			// 
			this->mainMenuSidePanel->BackColor = System::Drawing::Color::Tan;
			this->mainMenuSidePanel->Controls->Add(this->mainMenuSideLabel);
			this->mainMenuSidePanel->Location = System::Drawing::Point(131, -1);
			this->mainMenuSidePanel->Name = L"mainMenuSidePanel";
			this->mainMenuSidePanel->Size = System::Drawing::Size(30, 370);
			this->mainMenuSidePanel->TabIndex = 4;
			// 
			// AttendanceV2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Sienna;
			this->ClientSize = System::Drawing::Size(514, 331);
			this->Controls->Add(this->sidePanel);
			this->Controls->Add(this->login_panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"AttendanceV2";
			this->ShowIcon = false;
			this->Text = L"Attendance";
			this->Load += gcnew System::EventHandler(this, &AttendanceV2::AttendanceV2_Load);
			this->login_panel->ResumeLayout(false);
			this->login_panel->PerformLayout();
			this->sidePanel->ResumeLayout(false);
			this->markEmployeePanel->ResumeLayout(false);
			this->editAddEmployeePanel->ResumeLayout(false);
			this->adminPanel->ResumeLayout(false);
			this->settingsLogsPanel->ResumeLayout(false);
			this->mainMenuSidePanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

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

		}
	

		void hideMain() {
			// FIX : make this function to hide the main menu
		}



		System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e) {
			// Hiding panel and resizing client
			login_panel->Visible = false;
			this->ClientSize = Drawing::Size(530, 370);
			
			// Making side panel visible and "hiding" it
			sidePanel->Visible = true;
			hideMain(); // FIX: make this function

			
			// Sending to mark employee screen


		}
};
}
