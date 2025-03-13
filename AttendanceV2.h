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


	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->SuspendLayout();
			// 
			// AttendanceV2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 379);
			this->Name = L"AttendanceV2";
			this->Text = L"Attendance";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
