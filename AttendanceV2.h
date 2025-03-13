#pragma once

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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(108, 79);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(301, 206);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(66, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"testing pushing into git";
			// 
			// AttendanceV2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 379);
			this->Controls->Add(this->panel1);
			this->Name = L"AttendanceV2";
			this->Text = L"Attendance";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
