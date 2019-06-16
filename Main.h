#pragma once
#include "Tabla.h"
#include "ArbolAVL.h"

namespace TF {
	using namespace System;
	using namespace Threading;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ bmpTabla = gcnew Bitmap("Tabla_2.jpg");
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
	private: System::Windows::Forms::Button^  btnImportar;
	private: System::Windows::Forms::Button^  btnExportar;
	private: System::Windows::Forms::Button^  btnSeleccionar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  btnIndexar;

		Tabla *objtabla = new Tabla();


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnImportar = (gcnew System::Windows::Forms::Button());
			this->btnExportar = (gcnew System::Windows::Forms::Button());
			this->btnSeleccionar = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnIndexar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnImportar
			// 
			this->btnImportar->Location = System::Drawing::Point(1262, 68);
			this->btnImportar->Name = L"btnImportar";
			this->btnImportar->Size = System::Drawing::Size(131, 37);
			this->btnImportar->TabIndex = 2;
			this->btnImportar->Text = L"Importar";
			this->btnImportar->UseVisualStyleBackColor = true;
			this->btnImportar->Click += gcnew System::EventHandler(this, &Main::btnImportar_Click);
			// 
			// btnExportar
			// 
			this->btnExportar->Location = System::Drawing::Point(1262, 111);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(131, 37);
			this->btnExportar->TabIndex = 3;
			this->btnExportar->Text = L"Exportar";
			this->btnExportar->UseVisualStyleBackColor = true;
			// 
			// btnSeleccionar
			// 
			this->btnSeleccionar->Location = System::Drawing::Point(1262, 154);
			this->btnSeleccionar->Name = L"btnSeleccionar";
			this->btnSeleccionar->Size = System::Drawing::Size(131, 37);
			this->btnSeleccionar->TabIndex = 4;
			this->btnSeleccionar->Text = L"Seleccionar";
			this->btnSeleccionar->UseVisualStyleBackColor = true;
			// 
			// btnIndexar
			// 
			this->btnIndexar->Location = System::Drawing::Point(1262, 197);
			this->btnIndexar->Name = L"btnIndexar";
			this->btnIndexar->Size = System::Drawing::Size(131, 37);
			this->btnIndexar->TabIndex = 5;
			this->btnIndexar->Text = L"Indexar";
			this->btnIndexar->UseVisualStyleBackColor = true;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1484, 681);
			this->Controls->Add(this->btnIndexar);
			this->Controls->Add(this->btnSeleccionar);
			this->Controls->Add(this->btnExportar);
			this->Controls->Add(this->btnImportar);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DataFrame";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	void imprimir(int e) {}

	private: System::Void Main_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btnImportar_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();

		objtabla->DibujarTabla(g, bmpTabla, 9, 5); // F - C



	}
};
}
