#pragma once
#include "Number.h"
#include "Calculator.h"
#include <msclr\marshal_cppstd.h>

namespace Project1GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;

	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button26;





	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(504, 399);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(43, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 38);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Input";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(504, 338);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(58, 55);
			this->button2->TabIndex = 2;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(504, 460);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(58, 55);
			this->button3->TabIndex = 3;
			this->button3->Text = L"=";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button4->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(504, 216);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(58, 55);
			this->button4->TabIndex = 4;
			this->button4->Text = L"/";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(504, 277);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(58, 55);
			this->button5->TabIndex = 5;
			this->button5->Text = L"*";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(440, 216);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(58, 55);
			this->button6->TabIndex = 6;
			this->button6->Text = L"!";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(376, 216);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(58, 55);
			this->button7->TabIndex = 7;
			this->button7->Text = L")";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(312, 216);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(58, 55);
			this->button8->TabIndex = 8;
			this->button8->Text = L"(";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(312, 277);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(58, 55);
			this->button9->TabIndex = 9;
			this->button9->Text = L"7";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(376, 277);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(58, 55);
			this->button10->TabIndex = 10;
			this->button10->Text = L"8";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(376, 338);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(58, 55);
			this->button11->TabIndex = 11;
			this->button11->Text = L"5";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(376, 399);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(58, 55);
			this->button12->TabIndex = 12;
			this->button12->Text = L"2";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(376, 460);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(58, 55);
			this->button13->TabIndex = 13;
			this->button13->Text = L"0";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(440, 277);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(58, 55);
			this->button14->TabIndex = 14;
			this->button14->Text = L"9";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(440, 338);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(58, 55);
			this->button15->TabIndex = 15;
			this->button15->Text = L"6";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(440, 399);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(58, 55);
			this->button16->TabIndex = 16;
			this->button16->Text = L"3";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(440, 460);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(58, 55);
			this->button17->TabIndex = 17;
			this->button17->Text = L".";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(312, 338);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(58, 55);
			this->button18->TabIndex = 18;
			this->button18->Text = L"4";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(312, 399);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(58, 55);
			this->button19->TabIndex = 19;
			this->button19->Text = L"1";
			this->button19->UseCompatibleTextRendering = true;
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->Location = System::Drawing::Point(50, 216);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(256, 55);
			this->button22->TabIndex = 22;
			this->button22->Text = L"Set Integer";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// button23
			// 
			this->button23->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->Location = System::Drawing::Point(50, 277);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(256, 55);
			this->button23->TabIndex = 23;
			this->button23->Text = L"Set Decimal";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button21
			// 
			this->button21->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(50, 338);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(192, 55);
			this->button21->TabIndex = 24;
			this->button21->Text = L"Power";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(50, 91);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(512, 46);
			this->textBox1->TabIndex = 25;
			this->textBox1->WordWrap = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(586, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 23);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Exist Variables:";
			// 
			// button24
			// 
			this->button24->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button24->Location = System::Drawing::Point(248, 338);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(58, 55);
			this->button24->TabIndex = 27;
			this->button24->Text = L"^";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// button25
			// 
			this->button25->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button25->Location = System::Drawing::Point(312, 460);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(58, 55);
			this->button25->TabIndex = 28;
			this->button25->Text = L" ";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(65, 403);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(167, 45);
			this->label3->TabIndex = 29;
			this->label3->Text = L"Result:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(65, 464);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(230, 45);
			this->label4->TabIndex = 30;
			this->label4->Text = L"__________";
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button20->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(312, 155);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(186, 55);
			this->button20->TabIndex = 31;
			this->button20->Text = L"Enter!";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button26
			// 
			this->button26->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button26->Font = (gcnew System::Drawing::Font(L"Consolas", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->Location = System::Drawing::Point(504, 155);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(58, 55);
			this->button26->TabIndex = 32;
			this->button26->Text = L"C";
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(902, 553);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Bignum Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button19->Text;
		}
		private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button12->Text;
		}
		private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button16->Text;
		}
		private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button18->Text;
		}
		private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button11->Text;
		}
		private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button15->Text;
		}
		private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button9->Text;
		}
		private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button10->Text;
		}
		private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button14->Text;
		}
		private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button25->Text;
		}
		private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button13->Text;
		}
		private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button17->Text;
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button1->Text + " ";
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button2->Text + " ";
		}
		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button5->Text + " ";
		}
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button4->Text + " ";
		}
		private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button6->Text + " ";
		}
		private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button7->Text + " ";
		}
		private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button8->Text + " ";
		}
		private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button24->Text + " ";
		}
		private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button22->Text + " ";
		}
		private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button23->Text + " ";
		}
		private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button21->Text + " ";
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text += button3->Text + " ";
		}
		private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
			//enter
			try {
				bool equal = false;
				string str = msclr::interop::marshal_as<string>(textBox1->Text);
				Number ans = Calculator::Input(equal, str);
				if (equal) label4->Text = "Assign!!";
				else {
					Console::WriteLine();
					label4->Text = msclr::interop::marshal_as<String^>(Calculator::Output(ans));
				}
			}
			catch (const char* error) {
				MessageBox::Show(msclr::interop::marshal_as<String^>(error));
			}
		}
		private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text = "";
		}

};
}
