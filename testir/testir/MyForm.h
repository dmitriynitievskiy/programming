
#pragma once

namespace testir {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(216, 77);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(303, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"¬ведите число";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(216, 237);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(259, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(216, 292);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(259, 20);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(216, 352);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(259, 20);
			this->textBox4->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(264, 276);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"„исло в восьмеричной системе";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(274, 221);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(144, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"„исло в двоичной системе";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(247, 336);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(198, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"„исло в шестнадцатиричной системе";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(289, 137);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 41);
			this->button1->TabIndex = 8;
			this->button1->Text = L"перевести";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 533);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//двоична€ система
	__int64 number = Convert::ToInt64(textBox1->Text);
	int temp = 0;
	char dvoich[40];
	int index = 0;

	while (number != 0) {
		temp = number % 2;
		number = number / 2;
		dvoich[index] = temp + '0';
		index++;
	}
	char itog[40];
	int j = 0;

	for (int i = (index - 1); i >= 0; i--) {
		itog[j] = dvoich[i];
		j++;
	}
	
	String^ str2;
	for (int i = 0; i < j; i++) {
		str2 = str2->Format(str2 + Convert::ToChar(itog[i]));
	}

	//восьмерична€ система
	__int64 number_8 = Convert::ToInt64(textBox1->Text);
	int temp_8 = 0;
	char dvoich_8[40];
	int index_8 = 0;

	while (number_8 != 0) {
		temp_8 = number_8 % 8;
		number_8 = number_8 / 8;
		dvoich_8[index_8] = temp_8 + '0';
		index_8++;
	}
	char itog_8[40];
	j = 0;

	for (int i = (index_8 - 1); i >= 0; i--) {
		itog_8[j] = dvoich_8[i];
		j++;
	}

	
	String^ str8;
	for (int i = 0; i < j; i++) {
		str8 = str8->Format(str8 + Convert::ToChar(itog_8[i]));
	}


	//шестнадцатирична€ система
	__int64 number_16 = Convert::ToInt64(textBox1->Text);
	int temp_16 = 0;
	char dvoich_16[40];
	int index_16 = 0;

	while (number_16 != 0) {
		temp_16 = number_16 % 16;
		number_16 = number_16 / 16;
		dvoich_16[index_16] = temp_16 + '0';
		if (temp_16 == 10) dvoich_16[index_16] = 'A';
		if (temp_16 == 11) dvoich_16[index_16] = 'B';
		if (temp_16 == 12) dvoich_16[index_16] = 'C';
		if (temp_16 == 13) dvoich_16[index_16] = 'D';
		if (temp_16 == 14) dvoich_16[index_16] = 'E';
		if (temp_16 == 15) dvoich_16[index_16] = 'F';

		index_16++;
	}
	char itog_16[40];
	j = 0;

	for (int i = (index_16 - 1); i >= 0; i--) {
		itog_16[j] = dvoich_16[i];
		j++;
	}

	String^ str16;
	for (int i = 0; i < j; i++) {
		str16 = str16->Format(str16 + Convert::ToChar(itog_16[i]));
	}

    
	textBox2->Text = str2;
	textBox3->Text = str8;
	textBox4->Text = str16;

}
};
}
