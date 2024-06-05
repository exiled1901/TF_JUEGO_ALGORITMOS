#pragma once
#include "GestorEntidades.h"
#include "Personaje.h"
#include "Perro.h"
#include "Aliado.h"
#include "Basura.h"
#include "Escenario1.h"
#include "Escenario3.h"
#include "Escenario2.h"
#include "Credits.h"
#include "NewGame.h"
#include "Instructions.h"
#include "NivelSecreto.h"
#include "Balas.h"
#include "Barrera.h"
#include <fstream>
#include <iostream>
#include <string>

#define ANCHO_PANTALLA 1920
#define ALTO_PANTALLA 1080

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de DRUGS
	/// </summary>
	public ref class DRUGS : public System::Windows::Forms::Form
	{
	private:
		GestorEntidades* ge = new GestorEntidades();
		bool obj1, obj2, obj3, obj4, obj5, obj6, obj7;
		bool nivelSecreto;
		Bitmap^ bm = gcnew Bitmap("imagenes/tilin.png");
		Bitmap^ be = gcnew Bitmap("imagenes/lobos.png");
		Bitmap^ bl = gcnew Bitmap("imagenes/aliado.png");
		Bitmap^ bb = gcnew Bitmap("imagenes/basura.png");
		Bitmap^ bf = gcnew Bitmap("imagenes/elefante.png");
		Bitmap^ bv = gcnew Bitmap("imagenes/vagabundo.png");
		Bitmap^ bc = gcnew Bitmap("imagenes/auto.png");
		Bitmap^ ba = gcnew Bitmap("imagenes/balas.png");
		Bitmap^ br = gcnew Bitmap("imagenes/barrera.png");
		bool mostrarFondo1;
		bool mostrarFondo2;
		bool mostrarFondo3;
		bool mostrarFondoSecreto;
		bool escenarioOne;
		bool escenarioTwo;
		bool escenarioTree;

	private: System::Windows::Forms::Timer^ timer1;
		   Personaje* jugador = new Personaje(230, 250);//LISTO
		   Barrera* barrera = new Barrera(600, 500);
		   Escenario2* es2 = new Escenario2();
		   Escenario3* es3 = new Escenario3();
		   Escenario1* es1 = new Escenario1();
		   NivelSecreto* ns = new NivelSecreto();

	private: System::Windows::Forms::Button^ btnNewGame;
	private: System::Windows::Forms::Button^ btnCredits;
	private: System::Windows::Forms::Button^ btnHelp;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer3;

	private: System::Windows::Forms::Button^ btnEmpezar;
		   Media::SoundPlayer^ playerFound;
		   Media::SoundPlayer^ player;
	private: System::Windows::Forms::Label^ lblImagenCarta;
	private: System::Windows::Forms::Label^ lblFotoFamiliar;
	private: System::Windows::Forms::Button^ btnNvl2;
	protected: System::Windows::Forms::Label^ lblPelota;
	private:
	private: System::Windows::Forms::Label^ lblAlmlohada3;
	protected:
	private: System::Windows::Forms::Label^ lblAlmohadas2;
	private: System::Windows::Forms::Label^ lblAlmohada1;
	private: System::Windows::Forms::Label^ lblVideojuego;
	private: System::Windows::Forms::Label^ lblAlbum;

	private: System::Windows::Forms::Label^ lblInicio1;
	private: System::Windows::Forms::Label^ lblCarta;
		   Media::SoundPlayer^ menuM;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Label^ lblInicioSueño;
	private: System::Windows::Forms::Label^ lblAliado1;
	private: System::Windows::Forms::Label^ lblPersonaje;
	private: System::Windows::Forms::Label^ lblElefante;
	private: System::Windows::Forms::Label^ lblCarro;
	private: System::Windows::Forms::Label^ lbFinalNVL1;
	private: System::Windows::Forms::Label^ lblInicio_LVL3;
	private: System::Windows::Forms::Label^ lblFinal3;

	private: System::Windows::Forms::Label^ lblCarroacer;


	private: System::Windows::Forms::Label^ lblLVLSecreto;
	private: System::Windows::Forms::Timer^ timer4;


		   Media::SoundPlayer^ escenario2;
		   Media::SoundPlayer^ nivelZekret;
		   Media::SoundPlayer^ escenario3;
	public:
		DRUGS(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			playerFound = gcnew Media::SoundPlayer("sonidos/escenario2f.wav");
			player = gcnew Media::SoundPlayer("sonidos/gameover.wav");
			menuM = gcnew Media::SoundPlayer("sonidos/menumusic.wav");
			escenario2 = gcnew Media::SoundPlayer("sonidos/escenario2.wav");
			nivelZekret = gcnew Media::SoundPlayer("sonidos/nvlZekret.wav");
			escenario3 = gcnew Media::SoundPlayer("sonidos/escenario3.wav");
			playerFound->Load();
			player->Load();
			menuM->Load();
			mostrarFondo1 = true;
			mostrarFondo2 = true;
			mostrarFondo3 = true;
			mostrarFondoSecreto = true;
			
			obj1 = false;
			obj2 = false;
			obj3 = false;
			obj4 = false;
			obj5 = false;
			obj6 = false;
			obj7 = false;
			escenarioOne = false;
			escenarioTwo = false;
			escenarioTree = false;

		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~DRUGS()
		{
			if (components)
			{

				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DRUGS::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnEmpezar = (gcnew System::Windows::Forms::Button());
			this->btnNewGame = (gcnew System::Windows::Forms::Button());
			this->btnCredits = (gcnew System::Windows::Forms::Button());
			this->btnHelp = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblImagenCarta = (gcnew System::Windows::Forms::Label());
			this->lblFotoFamiliar = (gcnew System::Windows::Forms::Label());
			this->btnNvl2 = (gcnew System::Windows::Forms::Button());
			this->lblPelota = (gcnew System::Windows::Forms::Label());
			this->lblAlmlohada3 = (gcnew System::Windows::Forms::Label());
			this->lblAlmohadas2 = (gcnew System::Windows::Forms::Label());
			this->lblAlmohada1 = (gcnew System::Windows::Forms::Label());
			this->lblVideojuego = (gcnew System::Windows::Forms::Label());
			this->lblAlbum = (gcnew System::Windows::Forms::Label());
			this->lblInicio1 = (gcnew System::Windows::Forms::Label());
			this->lblCarta = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->lblInicioSueño = (gcnew System::Windows::Forms::Label());
			this->lblAliado1 = (gcnew System::Windows::Forms::Label());
			this->lblPersonaje = (gcnew System::Windows::Forms::Label());
			this->lblElefante = (gcnew System::Windows::Forms::Label());
			this->lblCarro = (gcnew System::Windows::Forms::Label());
			this->lbFinalNVL1 = (gcnew System::Windows::Forms::Label());
			this->lblLVLSecreto = (gcnew System::Windows::Forms::Label());
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblInicio_LVL3 = (gcnew System::Windows::Forms::Label());
			this->lblFinal3 = (gcnew System::Windows::Forms::Label());
			this->lblCarroacer = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &DRUGS::timer1_Tick);
			// 
			// btnEmpezar
			// 
			this->btnEmpezar->BackColor = System::Drawing::Color::Transparent;
			this->btnEmpezar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEmpezar.BackgroundImage")));
			this->btnEmpezar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnEmpezar->FlatAppearance->BorderSize = 0;
			this->btnEmpezar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEmpezar->ForeColor = System::Drawing::Color::Transparent;
			this->btnEmpezar->Location = System::Drawing::Point(772, 372);
			this->btnEmpezar->Name = L"btnEmpezar";
			this->btnEmpezar->Size = System::Drawing::Size(338, 117);
			this->btnEmpezar->TabIndex = 0;
			this->btnEmpezar->UseVisualStyleBackColor = false;
			this->btnEmpezar->Click += gcnew System::EventHandler(this, &DRUGS::btnEmpezar_Click);
			// 
			// btnNewGame
			// 
			this->btnNewGame->BackColor = System::Drawing::Color::Transparent;
			this->btnNewGame->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNewGame.BackgroundImage")));
			this->btnNewGame->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNewGame->FlatAppearance->BorderSize = 0;
			this->btnNewGame->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNewGame->Location = System::Drawing::Point(725, 518);
			this->btnNewGame->Name = L"btnNewGame";
			this->btnNewGame->Size = System::Drawing::Size(435, 117);
			this->btnNewGame->TabIndex = 1;
			this->btnNewGame->UseVisualStyleBackColor = false;
			this->btnNewGame->Click += gcnew System::EventHandler(this, &DRUGS::btnNewGame_Click);
			// 
			// btnCredits
			// 
			this->btnCredits->BackColor = System::Drawing::Color::Transparent;
			this->btnCredits->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCredits.BackgroundImage")));
			this->btnCredits->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCredits->FlatAppearance->BorderSize = 0;
			this->btnCredits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCredits->Location = System::Drawing::Point(772, 677);
			this->btnCredits->Name = L"btnCredits";
			this->btnCredits->Size = System::Drawing::Size(338, 117);
			this->btnCredits->TabIndex = 2;
			this->btnCredits->UseVisualStyleBackColor = false;
			this->btnCredits->Click += gcnew System::EventHandler(this, &DRUGS::btnCredits_Click);
			// 
			// btnHelp
			// 
			this->btnHelp->BackColor = System::Drawing::Color::Transparent;
			this->btnHelp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnHelp.BackgroundImage")));
			this->btnHelp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnHelp->FlatAppearance->BorderSize = 0;
			this->btnHelp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHelp->Location = System::Drawing::Point(93, 850);
			this->btnHelp->Name = L"btnHelp";
			this->btnHelp->Size = System::Drawing::Size(100, 100);
			this->btnHelp->TabIndex = 3;
			this->btnHelp->UseVisualStyleBackColor = false;
			this->btnHelp->Click += gcnew System::EventHandler(this, &DRUGS::btnHelp_Click);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &DRUGS::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &DRUGS::timer3_Tick);
			// 
			// lblImagenCarta
			// 
			this->lblImagenCarta->Font = (gcnew System::Drawing::Font(L"Ink Free", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblImagenCarta->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblImagenCarta.Image")));
			this->lblImagenCarta->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->lblImagenCarta->Location = System::Drawing::Point(103, 125);
			this->lblImagenCarta->Name = L"lblImagenCarta";
			this->lblImagenCarta->Size = System::Drawing::Size(550, 605);
			this->lblImagenCarta->TabIndex = 8;
			this->lblImagenCarta->Text = resources->GetString(L"lblImagenCarta.Text");
			this->lblImagenCarta->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblImagenCarta->Visible = false;
			// 
			// lblFotoFamiliar
			// 
			this->lblFotoFamiliar->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblFotoFamiliar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblFotoFamiliar.Image")));
			this->lblFotoFamiliar->Location = System::Drawing::Point(103, 299);
			this->lblFotoFamiliar->Name = L"lblFotoFamiliar";
			this->lblFotoFamiliar->Size = System::Drawing::Size(510, 510);
			this->lblFotoFamiliar->TabIndex = 9;
			this->lblFotoFamiliar->Visible = false;
			// 
			// btnNvl2
			// 
			this->btnNvl2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNvl2.BackgroundImage")));
			this->btnNvl2->Location = System::Drawing::Point(991, 160);
			this->btnNvl2->Name = L"btnNvl2";
			this->btnNvl2->Size = System::Drawing::Size(103, 54);
			this->btnNvl2->TabIndex = 12;
			this->btnNvl2->UseVisualStyleBackColor = true;
			this->btnNvl2->Visible = false;
			this->btnNvl2->Click += gcnew System::EventHandler(this, &DRUGS::btnNvl2_Click);
			// 
			// lblPelota
			// 
			this->lblPelota->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblPelota->AutoEllipsis = true;
			this->lblPelota->AutoSize = true;
			this->lblPelota->BackColor = System::Drawing::Color::DimGray;
			this->lblPelota->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPelota->ForeColor = System::Drawing::Color::Black;
			this->lblPelota->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblPelota.Image")));
			this->lblPelota->Location = System::Drawing::Point(547, 112);
			this->lblPelota->Margin = System::Windows::Forms::Padding(20, 0, 20, 0);
			this->lblPelota->Name = L"lblPelota";
			this->lblPelota->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->lblPelota->Size = System::Drawing::Size(784, 138);
			this->lblPelota->TabIndex = 13;
			this->lblPelota->Text = L"Tilin: \r\n¿No habia botado esta pelota\? Debo recordar tirarlo...\r\nHum...¿eso es un"
				L" 9\?\r\n\r\n";
			this->lblPelota->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblPelota->UseCompatibleTextRendering = true;
			this->lblPelota->Visible = false;
			// 
			// lblAlmlohada3
			// 
			this->lblAlmlohada3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblAlmlohada3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblAlmlohada3.Image")));
			this->lblAlmlohada3->Location = System::Drawing::Point(471, 66);
			this->lblAlmlohada3->Name = L"lblAlmlohada3";
			this->lblAlmlohada3->Size = System::Drawing::Size(916, 184);
			this->lblAlmlohada3->TabIndex = 14;
			this->lblAlmlohada3->Text = L"Tilin:\r\n¿Las almohadas guiaran mi camino\? Caí muy bajo como para\r\ncreer al tipo d"
				L"e la carta.";
			this->lblAlmlohada3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblAlmlohada3->Visible = false;
			// 
			// lblAlmohadas2
			// 
			this->lblAlmohadas2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblAlmohadas2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblAlmohadas2.Image")));
			this->lblAlmohadas2->Location = System::Drawing::Point(462, 66);
			this->lblAlmohadas2->Name = L"lblAlmohadas2";
			this->lblAlmohadas2->Size = System::Drawing::Size(916, 184);
			this->lblAlmohadas2->TabIndex = 15;
			this->lblAlmohadas2->Text = L"Tilin:\r\n¿Las almohadas guiaran mi camino\? ";
			this->lblAlmohadas2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblAlmohadas2->Visible = false;
			// 
			// lblAlmohada1
			// 
			this->lblAlmohada1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAlmohada1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblAlmohada1.Image")));
			this->lblAlmohada1->Location = System::Drawing::Point(462, 48);
			this->lblAlmohada1->Name = L"lblAlmohada1";
			this->lblAlmohada1->Size = System::Drawing::Size(916, 184);
			this->lblAlmohada1->TabIndex = 16;
			this->lblAlmohada1->Text = L"Tilin:\r\nNo hay nada de especial en esta almohada. Tal vez, todo es una broma.\r\nAn"
				L"tes yo era muy respetado, después que me retiré comenzaron\r\na fastidiarme.";
			this->lblAlmohada1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblAlmohada1->Visible = false;
			// 
			// lblVideojuego
			// 
			this->lblVideojuego->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblVideojuego->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblVideojuego.Image")));
			this->lblVideojuego->Location = System::Drawing::Point(132, 20);
			this->lblVideojuego->Name = L"lblVideojuego";
			this->lblVideojuego->Size = System::Drawing::Size(1775, 240);
			this->lblVideojuego->TabIndex = 17;
			this->lblVideojuego->Text = L"Tilin:\r\nLa consola tiene marcado un numero 8.\r\n¿Hace cuanto tiempo que no juego u"
				L"n videojuego\?\r\n La ultima vez fue antes del accidente....\r\nTENGO TODA LA CULPA, "
				L"debi ser yo quien....";
			this->lblVideojuego->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblVideojuego->Visible = false;
			// 
			// lblAlbum
			// 
			this->lblAlbum->BackColor = System::Drawing::Color::DimGray;
			this->lblAlbum->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAlbum->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblAlbum->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblAlbum.Image")));
			this->lblAlbum->Location = System::Drawing::Point(68, 20);
			this->lblAlbum->Name = L"lblAlbum";
			this->lblAlbum->Size = System::Drawing::Size(1775, 240);
			this->lblAlbum->TabIndex = 18;
			this->lblAlbum->Text = resources->GetString(L"lblAlbum.Text");
			this->lblAlbum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblAlbum->Visible = false;
			// 
			// lblInicio1
			// 
			this->lblInicio1->BackColor = System::Drawing::Color::DimGray;
			this->lblInicio1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInicio1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblInicio1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblInicio1.Image")));
			this->lblInicio1->Location = System::Drawing::Point(87, 754);
			this->lblInicio1->Name = L"lblInicio1";
			this->lblInicio1->Size = System::Drawing::Size(1775, 240);
			this->lblInicio1->TabIndex = 20;
			this->lblInicio1->Text = L"Tilin:\r\n¿Qué es esa carta en la puerta\?\r\nNo me digas que son esos tipos otra vez."
				L"\r\nVoy a ir a recoger la carta.";
			this->lblInicio1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblInicio1->Visible = false;
			// 
			// lblCarta
			// 
			this->lblCarta->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCarta->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblCarta.Image")));
			this->lblCarta->Location = System::Drawing::Point(104, 790);
			this->lblCarta->Name = L"lblCarta";
			this->lblCarta->Size = System::Drawing::Size(1696, 204);
			this->lblCarta->TabIndex = 21;
			this->lblCarta->Text = resources->GetString(L"lblCarta.Text");
			this->lblCarta->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblCarta->Visible = false;
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBack.BackgroundImage")));
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBack->FlatAppearance->BorderSize = 0;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->ForeColor = System::Drawing::Color::Transparent;
			this->btnBack->Location = System::Drawing::Point(1627, 920);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(186, 74);
			this->btnBack->TabIndex = 22;
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Visible = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &DRUGS::btnBack_Click);
			// 
			// lblInicioSueño
			// 
			this->lblInicioSueño->BackColor = System::Drawing::Color::DimGray;
			this->lblInicioSueño->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic));
			this->lblInicioSueño->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblInicioSueño->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblInicioSueño.Image")));
			this->lblInicioSueño->Location = System::Drawing::Point(556, 28);
			this->lblInicioSueño->Name = L"lblInicioSueño";
			this->lblInicioSueño->Size = System::Drawing::Size(807, 230);
			this->lblInicioSueño->TabIndex = 18;
			this->lblInicioSueño->Text = L"Tilin: Me siento muy mareado... ¿qué es este lugar y porque está tan sucio\?(PRESS"
				L" Q)";
			this->lblInicioSueño->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblInicioSueño->Visible = false;
			// 
			// lblAliado1
			// 
			this->lblAliado1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic));
			this->lblAliado1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblAliado1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblAliado1.Image")));
			this->lblAliado1->Location = System::Drawing::Point(67, 20);
			this->lblAliado1->Name = L"lblAliado1";
			this->lblAliado1->Size = System::Drawing::Size(1784, 240);
			this->lblAliado1->TabIndex = 23;
			this->lblAliado1->Text = L"\?\?\?: Perdón amigo, veo que mis perros te molestan, ahora me los llevo... por cier"
				L"to, te\r\nves muy mal.(PRESS Q)";
			this->lblAliado1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblAliado1->Visible = false;
			// 
			// lblPersonaje
			// 
			this->lblPersonaje->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic));
			this->lblPersonaje->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblPersonaje->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblPersonaje.Image")));
			this->lblPersonaje->Location = System::Drawing::Point(750, 850);
			this->lblPersonaje->Name = L"lblPersonaje";
			this->lblPersonaje->Size = System::Drawing::Size(314, 134);
			this->lblPersonaje->TabIndex = 24;
			this->lblPersonaje->Text = L"Tilin: mmm..., ¿qué\?";
			this->lblPersonaje->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblPersonaje->Visible = false;
			// 
			// lblElefante
			// 
			this->lblElefante->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic));
			this->lblElefante->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblElefante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblElefante.Image")));
			this->lblElefante->Location = System::Drawing::Point(600, 74);
			this->lblElefante->Name = L"lblElefante";
			this->lblElefante->Size = System::Drawing::Size(778, 184);
			this->lblElefante->TabIndex = 25;
			this->lblElefante->Text = L"Tilin: ¿Qué hace un elefante en el bosque... \?";
			this->lblElefante->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblElefante->Visible = false;
			// 
			// lblCarro
			// 
			this->lblCarro->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic));
			this->lblCarro->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblCarro->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblCarro.Image")));
			this->lblCarro->Location = System::Drawing::Point(570, 66);
			this->lblCarro->Name = L"lblCarro";
			this->lblCarro->Size = System::Drawing::Size(892, 184);
			this->lblCarro->TabIndex = 26;
			this->lblCarro->Text = L"Tilín: Así que este es mi final... , porfin podre verlos de nuevo.";
			this->lblCarro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblCarro->Visible = false;
			// 
			// lbFinalNVL1
			// 
			this->lbFinalNVL1->AutoSize = true;
			this->lbFinalNVL1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbFinalNVL1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lbFinalNVL1.Image")));
			this->lbFinalNVL1->Location = System::Drawing::Point(600, 841);
			this->lbFinalNVL1->Name = L"lbFinalNVL1";
			this->lbFinalNVL1->Size = System::Drawing::Size(548, 102);
			this->lbFinalNVL1->TabIndex = 27;
			this->lbFinalNVL1->Text = L"Tilin:\r\n¿Qué es eso\? ¿Otra carta\?\r\nEsto debe ser una broma, veré que es.\r\n";
			this->lbFinalNVL1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbFinalNVL1->Visible = false;
			// 
			// lblLVLSecreto
			// 
			this->lblLVLSecreto->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblLVLSecreto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblLVLSecreto.Image")));
			this->lblLVLSecreto->Location = System::Drawing::Point(308, 50);
			this->lblLVLSecreto->Name = L"lblLVLSecreto";
			this->lblLVLSecreto->Size = System::Drawing::Size(600, 200);
			this->lblLVLSecreto->TabIndex = 28;
			this->lblLVLSecreto->Text = L"\?\?\?: \r\nCaíste redondo en su trampa. Pero puedes salvarte, puedes volver a escribi"
				L"r tu final \r\n(Pelota y.... ¿Consola\?).";
			this->lblLVLSecreto->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblLVLSecreto->Visible = false;
			// 
			// timer4
			// 
			this->timer4->Tick += gcnew System::EventHandler(this, &DRUGS::timer4_Tick);
			// 
			// lblInicio_LVL3
			// 
			this->lblInicio_LVL3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblInicio_LVL3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblInicio_LVL3.Image")));
			this->lblInicio_LVL3->Location = System::Drawing::Point(736, 60);
			this->lblInicio_LVL3->Name = L"lblInicio_LVL3";
			this->lblInicio_LVL3->Size = System::Drawing::Size(535, 166);
			this->lblInicio_LVL3->TabIndex = 29;
			this->lblInicio_LVL3->Text = L"Tilin:\r\n¿Eh\? ¿Ahora donde estoy\? ¿Por qué estoy amarrado\?\r\n(PRESS Q)";
			this->lblInicio_LVL3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblInicio_LVL3->Visible = false;
			// 
			// lblFinal3
			// 
			this->lblFinal3->AutoSize = true;
			this->lblFinal3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFinal3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblFinal3.Image")));
			this->lblFinal3->Location = System::Drawing::Point(619, 818);
			this->lblFinal3->Name = L"lblFinal3";
			this->lblFinal3->Size = System::Drawing::Size(428, 102);
			this->lblFinal3->TabIndex = 30;
			this->lblFinal3->Text = L"Tilin:\r\nConque así termina mi vida... \r\nAl menos los volveré a ver.";
			this->lblFinal3->Visible = false;
			// 
			// lblCarroacer
			// 
			this->lblCarroacer->AutoSize = true;
			this->lblCarroacer->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCarroacer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblCarroacer.Image")));
			this->lblCarroacer->Location = System::Drawing::Point(662, 807);
			this->lblCarroacer->Name = L"lblCarroacer";
			this->lblCarroacer->Size = System::Drawing::Size(558, 102);
			this->lblCarroacer->TabIndex = 31;
			this->lblCarroacer->Text = L"Tilin:\r\n¿Eso es un carro\?....\r\n¡¡¡¡Ayudenmeee!!! ¡¡¡Estoy amarrado!!!";
			this->lblCarroacer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblCarroacer->Visible = false;
			// 
			// DRUGS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1904, 1046);
			this->Controls->Add(this->lblCarroacer);
			this->Controls->Add(this->lblFinal3);
			this->Controls->Add(this->lblInicio_LVL3);
			this->Controls->Add(this->lblLVLSecreto);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnNvl2);
			this->Controls->Add(this->lblFotoFamiliar);
			this->Controls->Add(this->btnHelp);
			this->Controls->Add(this->btnCredits);
			this->Controls->Add(this->btnNewGame);
			this->Controls->Add(this->btnEmpezar);
			this->Controls->Add(this->lblImagenCarta);
			this->Controls->Add(this->lblAliado1);
			this->Controls->Add(this->lblInicioSueño);
			this->Controls->Add(this->lblAlmohada1);
			this->Controls->Add(this->lblVideojuego);
			this->Controls->Add(this->lblAlbum);
			this->Controls->Add(this->lblInicio1);
			this->Controls->Add(this->lbFinalNVL1);
			this->Controls->Add(this->lblPersonaje);
			this->Controls->Add(this->lblCarta);
			this->Controls->Add(this->lblAlmohadas2);
			this->Controls->Add(this->lblAlmlohada3);
			this->Controls->Add(this->lblPelota);
			this->Controls->Add(this->lblCarro);
			this->Controls->Add(this->lblElefante);
			this->DoubleBuffered = true;
			this->Name = L"DRUGS";
			this->Text = L"DRUGS";
			this->Load += gcnew System::EventHandler(this, &DRUGS::DRUGS_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DRUGS::DRUGS_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &DRUGS::DRUGS_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//////Escenario 2/////////////////
		// Creamos los graficos del q
		Graphics^ g = this->CreateGraphics();
		Image^ fondo = Image::FromFile("imagenes/escenario2.jpg");
		Image^ fondoLose = Image::FromFile("imagenes/gameover.jpg");
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		escenarioTree = false;
		escenarioTwo = true;
		escenarioOne = false;
		if (mostrarFondo2) {
			buffer->Graphics->DrawImage(fondo, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
		}
		//aqui inicia la logica de tu juego
		Rectangle ali = Rectangle(0, 0, 5, 5);
		jugador->mover(buffer, bm, 2);
		es2->iniciar(buffer, bl, be, bb, bm, bf, jugador);
		int n = jugador->getX() + jugador->getdx();
		jugador->setX(n);
		int m = jugador->getY() + jugador->getdy();
		jugador->setY(m);
		if ((es2->aliadoPosicion()) && (es2->getdesaparecerlobos() == false)) {
			lblAliado1->Visible = true;
			lblPersonaje->Visible = true;
		}
		if (es2->getterminarnivel() == true)
		{
			escenarioTwo = false;
			escenarioTree = true;
			playerFound->Stop();
			timer1->Stop();
			if (mostrarFondo3) {
				this->BackgroundImage = Image::FromFile("imagenes/escenario3.jpg");
			}
			jugador->setX(500); jugador->setY(535);
			timer3->Start();
			escenario2->Stop();
			escenario3->PlayLooping();
			lblInicio_LVL3->Visible = true;
	
			this->Focus();
		}
		//Aparece el elefante
		if (es2->elefanteAparece(buffer, bf) == 1) {
			lblElefante->Visible = true;
		}
		//Colision aliado persoanje, desbloqueo al nivel secreto
		if (es2->getRectangleAliadoXY().IntersectsWith(jugador->getRectangle())) {
			lblLVLSecreto->Visible = true;
		}
		//El choque entre el rectangulo
		if ((jugador->getRectangle().IntersectsWith(ali)) == true) {
			int h = es2->getContadorBasuras();
			es2->setContadorBasuras(h);
		}
		//
		if (es2->getmorirjugador() == true)
		{
			escenarioTwo = false;
			lblElefante->Visible = false;
			timer1->Stop();
			playerFound->Stop();
			player->PlayLooping();
			mostrarFondo2 = false;
			buffer->Graphics->Clear(Color::White);
			this->BackgroundImage = Image::FromFile("imagenes/gameover.jpg");
			btnBack->Visible = true;
		}
		buffer->Render(g);
		delete buffer;
		delete espacioBuffer;
		delete g;
	}

	private: System::Void DRUGS_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Archivo* a = new Archivo();
		vector<int>v_posiciones;
		vector<bool>v_booleanos;
		switch (e->KeyCode)
		{
		case Keys::W:
			jugador->setDireccion(Arriba);
			barrera->setDireccion(Arriba);
			//lobo->setDireccion(ArribaE);
			break;
		case Keys::A:
			jugador->setDireccion(Izquierda);
			//lobo->setDireccion(IzquierdaE);
			break;
		case Keys::S:
			jugador->setDireccion(Abajo);
			barrera->setDireccion(Abajo);
			//lobo->setDireccion(AbajoE);
			break;
		case Keys::D:
			jugador->setDireccion(Derecha);
			//lobo->setDireccion(DerechaE);
			break;
		case Keys::Q:
			lblInicioSueño->Visible = false;
			lblAliado1->Visible = false;
			lblPersonaje->Visible = false;

			if ((es2->aliadoPosicion()) && (es2->getContadorBasuras() == 3))
			{
				if ((obj5) && (obj6) && (obj7)) {
					es2->eliminarVector();
				}
				else {
					es2->setXYAliado(1921, 0);
				}
				es2->desaparecerLobos();
				es2->setdesaparecerlobos(true);
			}

			//Dialogos del 3 nivel

			lblInicio_LVL3->Visible = false;
			lblCarroacer->Visible = false;

			lblCarroacer->Visible = false;
			lblElefante->Visible = false;
			break;
		case Keys::B:
			if (es2->getRectangleAliadoXY().IntersectsWith(jugador->getRectangle())) {
				escenarioTwo = false;
				lblElefante->Visible = false;
				lblLVLSecreto->Visible = false;
				lblInicioSueño->Visible = false;
				//escenario2->Stop();
				nivelZekret->PlayLooping();
				mostrarFondoSecreto = true;
				if (mostrarFondoSecreto) {
					this->BackgroundImage = Image::FromFile("imagenes/nivelSecreto.png");
				}
				timer1->Stop();
				timer4->Start();
				this->Focus();
				nivelZekret->PlayLooping();
			}
			break;
		case Keys::G:
			/*a->guardarBooleanos(escenarioOne, escenarioTwo, escenarioTree);
			a->guardarPosiciones(jugador);*/
			break;
		}
	}
	private: System::Void DRUGS_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		jugador->setDireccion(Ninguna);
		//lobo->setDireccion(NingunaE);
	}
	private: System::Void btnEmpezar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (mostrarFondo1) {
			this->BackgroundImage = Image::FromFile("imagenes/escenario1.png");
		}
		timer2->Start();
		btnEmpezar->Visible = false;
		btnCredits->Visible = false;
		btnHelp->Visible = false;
		btnNewGame->Visible = false;
		lblInicio1->Visible = true;
		lblInicio1->Visible = true;
		playerFound->PlayLooping();
		this->Focus();

	}
	private: System::Void btnNewGame_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		this->BackgroundImage = Image::FromFile("imagenes/escenario1.png");
		Archivo* a = new Archivo();
		vector<int> v_posiciones;
		vector<int> v_indices;
		vector<bool> v_booleanos;
		vector<int> v_basuras;
		v_indices = a->leerIndices();
		v_posiciones = a->leerPosicionInicial();
		v_booleanos = a->leerBoleanos();
		v_basuras = a->leerPosicionBasuras();
		//Escenario1
		jugador->setX(v_posiciones[0]);
		jugador->setY(v_posiciones[1]);
		jugador->setIndiceX(v_indices[0]);
		jugador->setIndiceY(v_indices[1]);
		jugador->setAncho(v_posiciones[4]);
		jugador->setAlto(v_posiciones[5]);
		es2->setmorirjugador(false);
		obj1 = v_booleanos[3]; obj2 = v_booleanos[4]; obj3 = v_booleanos[5]; obj4 = v_booleanos[6]; obj5 = v_booleanos[7]; obj6 = v_booleanos[8]; obj7 = v_booleanos[9];
		mostrarFondo1 = v_booleanos[0]; mostrarFondo2 = v_booleanos[1]; mostrarFondo3 = v_booleanos[2]; mostrarFondoSecreto = v_booleanos[10];
		//Escenario2
		es2->setbasuraagregada(v_booleanos[12]); es2->setmorirjugador(v_booleanos[17]); es2->setterminarnivel(v_booleanos[13]); jugador->setvidaunica(v_booleanos[14]); es2->setdesaparecerlobos(v_booleanos[15]); es2->setmorirlobos(v_booleanos[16]);
		//Escenario1
		timer2->Start();
		timer1->Stop();
		timer3->Stop();
		btnEmpezar->Visible = false;
		btnCredits->Visible = false;
		btnHelp->Visible = false;
		btnNewGame->Visible = false;
		lblInicio1->Visible = v_booleanos[11];
		//Escenario2
		es2->setContadorBasuras(v_basuras[8]);
		es2->eliminarVector();
		es2->setreiniciarbasuras(v_booleanos[18]);
		es2->reiniciarAliado(buffer, bl);
		es2->reiniciarlobos();
		//Escenario3;
		es3->reiniciarBus();
		//NivelSecreto
		//ns->eliminarVector();
		//ns->newBalas();
		this->Focus();
		menuM->Stop();
		playerFound->PlayLooping();
	}
	private: System::Void btnCredits_Click(System::Object^ sender, System::EventArgs^ e) {
		Credits^ myForm = gcnew Credits();
		myForm->ActivarPantallaCompleta();
		myForm->Show();
	}
	private: System::Void btnHelp_Click(System::Object^ sender, System::EventArgs^ e) {
		Instructions^ myForm = gcnew Instructions();
		myForm->ActivarPantallaCompleta();
		myForm->Show();
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		/////////////Escenario 1//////////
		Graphics^ g = this->CreateGraphics();
		// Dibujar la imagen de fondo en el lienzo
		Image^ fondo = Image::FromFile("imagenes/escenario1.png");
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;

		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		escenarioTree = false;
		escenarioTwo = false;
		escenarioOne = true;
		if (mostrarFondo1) {
			buffer->Graphics->DrawImage(fondo, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
		}
		//aqui inicia la logica de tu juego
		jugador->mover(buffer, bm, 1);
		es1->iniciar(buffer, jugador);
		int n = jugador->getX() + jugador->getdx();
		jugador->setX(n);
		int m = jugador->getY() + jugador->getdy();
		jugador->setY(m);

		switch (es1->colisionRecuerdos(jugador)) {
		case 1:
			if (obj4 == true) {
				lblPelota->Visible = true;
				obj1 = true;
			}
			break;
		case 2:
			if (obj4) {
				lblFotoFamiliar->Visible = true;
				lblAlbum->Visible = true;
				obj2 = true;
			}

			break;
		case 3:
			if (obj4) {
				lblVideojuego->Visible = true;
				obj3 = true;
			}
			break;
		case 4:
			lblCarta->Visible = true;
			lblImagenCarta->Visible = true;
			obj4 = true;
			lblInicio1->Visible = false;
			break;
		case 5:
			if (obj4) {
				lblAlmohada1->Visible = true;
				obj5 = true;
			}
			break;
		case 6:
			if (obj4) {
				lblAlmohadas2->Visible = true;
				obj6 = true;
			}
			break;
		case 7:
			if (obj4) {
				lblAlmlohada3->Visible = true;
				obj7 = true;
			}
			break;
		default:
			lblAlbum->Visible = false;
			lblPelota->Visible = false;
			lblFotoFamiliar->Visible = false;
			lblVideojuego->Visible = false;
			lblCarta->Visible = false;
			lblImagenCarta->Visible = false;
			lblAlmohada1->Visible = false;
			lblAlmohadas2->Visible = false;
			lblAlmlohada3->Visible = false;
			break;
		}
		int contadornvl2 = 0;
		if (obj1)contadornvl2++;
		if (obj2)contadornvl2++;
		if (obj3)contadornvl2++;

		if (contadornvl2 == 3 && (es1->colisionRecuerdos(jugador) == 0)) {
			btnNvl2->Visible = true;
			lbFinalNVL1->Visible = true;
			obj4 = false;
		}
		//aqui termina la logica de tu juego
		buffer->Render(g);
		delete buffer;
		delete espacioBuffer;
		delete g;


	}
	private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
		//////Escenario 3///////
		Graphics^ g = this->CreateGraphics();
		// Dibujar la imagen de fondo en el lienzo
		Image^ fondo = Image::FromFile("imagenes/escenario3.jpg");
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		lblElefante->Visible = false;
		escenarioTree = true;
		escenarioTwo = false;
		escenarioOne = false;
		if (mostrarFondo3) {
			buffer->Graphics->DrawImage(fondo, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
		}
		//Si se acaba el dialogo
		if (!lblInicio_LVL3->Visible) {
			if (es3->colisionPersonajeEscenario(jugador, buffer) == false) {
				jugador->mover(buffer, bv, 3);
				jugador->setAncho(60); jugador->setAlto(50);
				jugador->dibujar_nivel_3(buffer, bv);
				int n = jugador->getX() + jugador->getdx();
				jugador->setX(n);
				int m = jugador->getY() + jugador->getdy();
				jugador->setY(m);
			}
			else {
				jugador->setIndiceY(1);
				jugador->setAncho(60); jugador->setAlto(50);
				jugador->dibujar_nivel_3(buffer, bv);
			}
			es3->iniciar(buffer, jugador, bc);
		}
		else {
			jugador->setAncho(60); jugador->setAlto(50);
			jugador->dibujar_nivel_3(buffer, bv);

		}
		if (es3->distanciaCarro(jugador)) {

			lblCarroacer->Visible = false;
			lblFinal3->Visible = true;
		}

		if (es3->colisionPersonajeCarro(jugador)) {
			lblFinal3->Visible = false;
			btnBack->Visible = true;
			escenarioTree = false;
			timer3->Stop();
			mostrarFondo2 = false;
			buffer->Graphics->Clear(Color::White);
			this->BackgroundImage = Image::FromFile("imagenes/gameover.jpg");
		}

		buffer->Render(g);
		delete buffer;
		delete espacioBuffer;
		delete g;

	}
	private: System::Void DRUGS_Load(System::Object^ sender, System::EventArgs^ e) {
		this->BackgroundImage = Image::FromFile("imagenes/MENU.png");
		menuM->PlayLooping();
	}
	private: System::Void btnNvl2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->BackgroundImage = Image::FromFile("imagenes/escenario2.jpg");
		btnNvl2->Visible = false;
		escenarioOne = false;
		timer2->Stop();
		timer1->Start();
		jugador->setX(200);
		jugador->setY(200);
		lbFinalNVL1->Visible = false;
		this->Focus();
		playerFound->Stop();
		escenario2->PlayLooping();
		mostrarFondo1 = false;
		lblInicioSueño->Visible = true;
	}
	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->BackgroundImage = Image::FromFile("imagenes/MENU.png");
		timer2->Stop();
		btnBack->Visible = false;
		btnEmpezar->Visible = true;
		btnCredits->Visible = true;
		btnHelp->Visible = true;
		btnNewGame->Visible = true;
		player->Stop();
		escenario3->Stop();
		menuM->PlayLooping();
		mostrarFondo1 = true;
		mostrarFondo2 = true;
		mostrarFondo3 = true;
	}
	private: System::Void timer4_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Nivel secreto///////////
		Graphics^ g = this->CreateGraphics();
		Image^ fondo = Image::FromFile("imagenes/nivelSecreto.png");
		Image^ fondoLose = Image::FromFile("imagenes/gameover.jpg");
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		if (mostrarFondoSecreto) {
			buffer->Graphics->DrawImage(fondo, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
		}
		//aqui inicia la logica de tu juego
		barrera->mover(buffer, br, 1);
		ns->iniciar(buffer, ba, br, barrera);
		int m = barrera->getY() + barrera->getdy();
		barrera->setY(m);
		//aqui termina la logica de tu juego y gana
		if (ns->getTerminarNivel() == true)
		{
			timer4->Stop();
			mostrarFondoSecreto = false;
			escenarioTwo = false;
			buffer->Graphics->Clear(Color::White);
			this->BackgroundImage = Image::FromFile("imagenes/youWin.png");
			btnBack->Visible = true;
		}
		//Muere el jugador
		if (ns->getMorirJugador() == true)
		{
			playerFound->Stop();
			timer4->Stop();
			mostrarFondoSecreto = false;
			escenarioTwo = false;
			escenarioTree = true;
			if (escenarioTree) {
				this->BackgroundImage = Image::FromFile("imagenes/escenario3.jpg");
			}
			timer3->Start();
			jugador->setX(500); jugador->setY(535);

			escenario2->Stop();
			escenario3->PlayLooping();
			lblInicio_LVL3->Visible = true;
			btnBack->Visible = false;
		}
		buffer->Render(g);
		delete buffer;
		delete espacioBuffer;
		delete g;
	}
	};
}
