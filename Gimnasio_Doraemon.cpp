/*---------------------------------------------------------------//
| Nombre del Proyecto: Gimnasio De Doraemon.
| Dia De Inicio: 08-09-2018.
| Version 4.0.
|
| Integrantes:
|
| - Juan Sebastian Reyes Leyton.
| - Carlos Andres Angel Calderon.
| - Daniel Fernando Sosa.
|
| Docente: Simena Dinas.
|
| Curso: Tecnicas y Practicas De Programacion.
| Semestre II 
|
| Pontificia Universidad Javeriana Cali
| 2018	
//---------------------------------------------------------------*/

#include "Gimnasio.h"
#include "Recepcion.h"
#include "Zona_Pesas.h"
#include "Zona_Cardio.h"
#include "Zona_Humeda.h"
#include "BasesDatos.h"
 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
using namespace std;
using std::ostream;
using std::cout;


ostream &operator<<(ostream &salida,const Gimnasio *gym){
	salida << "..::.. Bienvenido al modulo de Muestra de datos del Gimnasio en General";
	salida << "__Gimnasio__ \n";
	salida << "El estado del Gimnasio es " << gym->estadoGym << "\n";
	salida << "La capacidad maxima del Gimnasio es " << gym->capMaxGym << "\n";
	salida << "El numero de personas dentro del Gimnasio es " << gym->numPersonasGym << "\n\n";
	salida << "__Recepcion__\n";
	salida << "El estado de la recepcion es " << gym->recepcion->get_est_Rec() << "\n";
	salida << "La capacidad maxima de la recepcion es " << gym->recepcion->get_CapMaximaRec() << "\n";
	salida << "El numero de personas dentro de la recepcion es " << gym->recepcion->get_PersonasRec() << "\n\n";
	salida << "__Zona Pesas__\n";
	salida << "El estado de la Zona Pesas es " << gym->zonaPesas->get_est_Pes() << "\n";
	salida << "La capacidad maxima de la Zona Pesas es " << gym->zonaPesas->get_CapMaximaPes() << "\n";
	salida << "El numero de personas dentro de la Zona Pesas es " << gym->zonaPesas->get_PersonasPes() << "\n\n";
	salida << "__Zona Humeda__\n";
	salida << "El estado de la Zona Humeda es " << gym->zonaHumeda->get_est_Hum() << "\n";
	salida << "La capacidad maxima de la Zona Humeda es " << gym->zonaHumeda->get_CapMaximaHum() << "\n";
	salida << "El numero de personas dentro de la Zona Humeda es " << gym->zonaHumeda->get_PersonasHum() << "\n\n";
	salida << "__Zona Cardio__\n";
	salida << "El estado de la Zona Cardio es " << gym->zonaCardio->get_est_Car() << "\n";
	salida << "La capacidad maxima de la Zona Cardio es " << gym->zonaCardio->get_CapMaximaCar() << "\n";
	salida << "El numero de personas dentro de la Zona Cardio es " << gym->zonaCardio->get_PersonasCar() << "\n\n";

	return salida;
}

/*

Esta funcion se encarga de convertir un digito de un numero a su
representacion en caracteres y retorna dicha representacion.
*/

char numeroChar(int numero){

	switch(numero){

		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		default: return '9';
	}
}

/*
Convierte un numero a un string por medio de un vector el cual 
se encarga de almacenar los digitos empezando desde el ultimo
numero y terminando con el primer numero, luego los almacena en
la variable tipo string la cual se debe retornar.
*/
string convertirNumeroString(int numero){
	int valor;
	string numeroString;
	vector<char> digitos;
	while(numero != 0){
		valor = numero % 10;
		digitos.push_back(numeroChar(valor));
		numero /= 10;
	}

	for(int i = digitos.size() - 1; i >= 0; i--){
		numeroString.push_back(digitos[i]);
	}

	return numeroString;
}


/*

Esta sobrecarga permite actualizar la base de datos o 
Archivo Plano Zonas.txt

*/

void operator+(Archivos &archivo, Gimnasio *gym){

	ofstream baseDatos;
	baseDatos.open("Zonas.txt",ios::out);
	
	string dato;
	dato += "Gimansio";
	dato.push_back('-');
	dato += convertirNumeroString(gym->getCapacidadMaximaGym());
	dato.push_back('-');

	if (gym->getEstadoGym() == "Abierto")
		dato.push_back('1');
	if(gym->getEstadoGym() == "Cerrado")
		dato.push_back('0');
	if(gym->getEstadoGym() == "Mantenimiento")
		dato.push_back('2');

	dato.push_back('\n');

	dato += "Recepcion";
	dato.push_back('-');
	dato += convertirNumeroString(gym->getCapacidadMaxima("Recepcion"));
	dato.push_back('-');

	if (gym->getEstadoZonas("Recepcion") == "Abierto")
		dato.push_back('1');
	if(gym->getEstadoZonas("Recepcion") == "Cerrado")
		dato.push_back('0');
	if(gym->getEstadoZonas("Recepcion") == "Mantenimiento")
		dato.push_back('2');

	dato.push_back('\n');

	dato += "Zona Pesas";
	dato.push_back('-');
	dato += convertirNumeroString(gym->getCapacidadMaxima("Zona Pesas"));
	dato.push_back('-');

	if (gym->getEstadoZonas("Zona Pesas") == "Abierto")
		dato.push_back('1');
	if(gym->getEstadoZonas("Zona Pesas") == "Cerrado")
		dato.push_back('0');
	if(gym->getEstadoZonas("Zona Pesas") == "Mantenimiento")
		dato.push_back('2');

	dato.push_back('\n');

	dato += "Zona Cardio";
	dato.push_back('-');
	dato += convertirNumeroString(gym->getCapacidadMaxima("Zona Cardio"));
	dato.push_back('-');

	if (gym->getEstadoZonas("Zona Cardio") == "Abierto")
		dato.push_back('1');
	if(gym->getEstadoZonas("Zona Cardio") == "Cerrado")
		dato.push_back('0');
	if(gym->getEstadoZonas("Zona Cardio") == "Mantenimiento")
		dato.push_back('2');

	dato.push_back('\n');

	dato += "Zona Humeda";
	dato.push_back('-');
	dato += convertirNumeroString(gym->getCapacidadMaxima("Zona Humeda"));
	dato.push_back('-');

	if (gym->getEstadoZonas("Zona Humeda") == "Abierto")
		dato.push_back('1');
	if(gym->getEstadoZonas("Zona Humeda") == "Cerrado")
		dato.push_back('0');
	if(gym->getEstadoZonas("Zona Humeda") == "Mantenimiento")
		dato.push_back('2');

	baseDatos << (dato.c_str());

	baseDatos.close();
	return;
}



bool esError(string entrada){
	for (int i = 0; i < entrada.size(); i++){

		if ((int)entrada[i] < 48 || (int)entrada[i] > 57)
			return true;
	}
	return false;
}

/*---------------------------------------------------------------//
| Nombre y contraseña del administrador, estas van a ser tomadas durante el funcionamiento |	
//---------------------------------------------------------------*/

const string admin = "rey"; string contrasena = "gimnasio01";

/*---------------------------------------------------------------//
| Variables constantes para la introduccion de vocales con tilde |	
//---------------------------------------------------------------*/

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

/*---------------------------------------------------------------//
| Funcion para la comprobacion de entradas numericas en los std::cin |	
//---------------------------------------------------------------*/

bool comprobacion(string entrada){
	
	for (int i = 0; i < entrada.size(); i++){

		if ((int)(entrada[i]) < 48)
			return false;

		if ((int)(entrada[i]) > 57)
			return false;

		if (i == entrada.size() - 1)

			if ((int)entrada[i] >= 48 && (int)entrada[i] <= 57)
				return true;
			else
				return false;
	}
}

/*---------------------------------------------------------------//
| Funcion de conteo de tiempo de espera
| 
| Entrada: cantidad determinada de segundos
| Salida: ninguna 
|	
//---------------------------------------------------------------*/

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

/*---------------------------------------------------------------//
| Describcion: Implementacion de las clases y parte interactiva
| con el usuario
| 
| Entrada: pide la intervencion del usuarioen muchas ocaciones
| por lo que puede tener una cantidad indeterminada de entradas
|
| Salida: la salida depende totalmente de los dtos introducidos 
| el usuario
|	
//---------------------------------------------------------------*/

int main(){

	string nombre, maquina, opcionesEntrada, opcionIngreso, opcionRegistrado;
	vector< vector<string > > usuarios;
	int edad, contador;
	Archivos archivo;
 
	archivo.setDatos();

	/*---------------------------------------------------------------//
	| Creacion del Gimnacio desde cero
	//---------------------------------------------------------------*/
	Gimnasio *gym = new Gimnasio;

	do{
		system("cls");

		/*---------------------------------------------------------------//
		|Menu de inicio
		//---------------------------------------------------------------*/

		cout<<"::--:: Bienvenidos Al Gimnasio de Doraemon .:::."<<endl;
		cout<<"   Favor escoge una opci"<<(char)o<<"n para la simulaci"<<(char)o<<"n"<<endl;
		cout<<"1) Usuario."<<endl;
		cout<<"2) Administrador."<<endl;
		cout<<"3) Salir."<<endl;
		cout<<endl;

		cout<<"Opci"<<(char)o<<"n: ";
		cin>>opcionesEntrada;

		try{
			if(opcionesEntrada.compare("1")!=0 && opcionesEntrada.compare("2")!=0 && opcionesEntrada.compare("3")!=0) throw 1;
		}
		catch(int error){
			system("cls");
			cout<< "Valor ingresado invalido. "<< endl;
			if(error == 1){
				cout<<"entrada incorrecta.... intentalo nuevamente y lee atentamente"<<endl;
				delay(2);
				system("PAUSE");
			}
		}

		system("cls");
		//Termina menu de entrada

		//Efecto de espera
		system("cls");
		cout << "Un momento por favor." << endl;
		delay(1);
		system("cls");
		cout << "Un momento por favor.." << endl;
		delay(1);
		system("cls");
		cout << "Un momento por favor..." << endl;
		delay(1);
		system("cls");
		//Termina Efecto de espera

		/*---------------------------------------------------------------//
		| Seccion de opciones de usuario, esta contiene todas las posibles
		| interaccion, dentro de esta seccion se encuentran el recepcionista,
		| portero y contador cada uno con sus respecivas opciones
		//---------------------------------------------------------------*/

		if(opcionesEntrada.compare("1") == 0){
			
			//Bienvenida
			cout<<"Bienvenido a la opci"<<(char)o<<"n de Usuario"<<endl;
			delay(2);
			system("cls");
			cout<<"Comencemos"<<endl;
			delay(1);
			//Termina bienvenida

			do{
				system("cls");

				//Menu ingreso
				cout<<"1) Entrar."<<endl;
				cout<<"2) Salir."<<endl;
				cout<<endl;
				cout<<"Opci"<<(char)o<<"n: ";
				cin>>opcionIngreso;
				try{
					if(opcionIngreso.compare("1")!=0 && opcionIngreso.compare("2")!=0) throw 1;
				}
				catch(int error){
					
					cout << endl << endl << "Valor ingresado invalido. "<< endl;
					if(error == 1){
						cout<<"Entrada incorrecta.... intentalo nuevamente y lee atentamente"<<endl;
						delay(2);
						system("PAUSE");
					}
				}
				system("cls");
				//Termina menu ingreso

				//Efecto de espera
				cout<<"Un momento por favor."<<endl;
				delay(1);
				system("cls");
				cout<<"Un momento por favor.."<<endl;
				delay(1);
				system("cls");
				cout<<"Un momento por favor..."<<endl;
				delay(1);
				system("cls");
				//Termina efecto de espera

				/*---------------------------------------------------------------//
				| Por el momento no tenemos la implementacion de los usuarios ya
				| ya que esta requiere una gran cantidad de tipos y la estamos planteando
				| en un documento diferente
				//---------------------------------------------------------------*/
	
				if(opcionIngreso.compare("1") == 0){

					system("cls");
					archivo.setArchivo("Personas.txt");
					archivo.setDatos();
					usuarios = archivo.getDatos();
					cout << endl << " Usuarios Inscritos" << endl;
					for (int i = 0; i < usuarios.size(); i++){

						if ("Cliente" == usuarios[i][0]){
							cout << "Nombre: " << usuarios[i][1] << endl;
							cout << "Cargo: " << usuarios[i][0] << endl;
							cout << "Edad: " << usuarios[i][2] << endl;
							cout << "Tarjeta Identidad: " << usuarios[i][3] << endl;
							cout << "Genero: " << usuarios[i][4] << endl << endl;
						}
					}
					
					system("PAUSE");
				}

			}while(opcionIngreso.compare("2") != 0);
		}
		//Termina opcion entrada 1


		/*---------------------------------------------------------------//
		| Seccion de opciones de Administrador, esta contiene todas las posibles
		| interacciones, dentro de esta seccion se encuentran todos los cambios
		| de capacidad la contratacion y despido de clientes, cambios de capacidad,
		| inicializacion total del gymnasion o cerrar totalmente el gym
		//---------------------------------------------------------------*/
		
		if(opcionesEntrada.compare("2") == 0){ 

			//Bienvenida
			cout<<"Bienvenido a la opci"<<(char)o<<"n de Administrador"<<endl;
			delay(2);
			system("cls");
			cout<<"Comencemos"<<endl;
			delay(1);
			//Termina bienvenida

			do{
				system("cls");
				//Menu ingreso
				bool aceptado = false;
				do {
					cout<<"..::.. Opci"<<(char)o<<"n del Administrador..::.."<<endl<<endl;
					cout<<"1) Inagurar El Gimnasio de Doraemon."<<endl;
					cout<<"2) Cambiar el Estado del Gimnasio."<<endl;
					cout<<"3) Cambiar el Estado de las Zonas."<<endl; 
					cout<<"4) Cambiar la capacidad de las Zonas."<<endl;
					cout<<"5) Realizar contrataciones."<<endl;
					cout<<"6) Despedir a clientes."<<endl;
					cout<<"7) Mostrar datos empleados."<<endl;
					cout<<"8) Mostrar datos del Gimnasio"<<endl;
					cout<<"9) Salir."<<endl;
					cout<<endl;
					cout<<"Opci"<<(char)o<<"n: ";
					cin>>opcionIngreso;
					cin.ignore();
					try{
						if(opcionIngreso.compare("1")!=0 && opcionIngreso.compare("2")!=0 && opcionIngreso.compare("3")!=0 && 
							opcionIngreso.compare("4")!=0 && opcionIngreso.compare("5")!=0 && opcionIngreso.compare("6")!=0 &&
							opcionIngreso.compare("7")!=0 && opcionIngreso.compare("8")!=0 && opcionIngreso.compare("9")!=0) throw 1;
					}
					catch(int error){
						system("cls");
						cout<< "Valor ingresado invalido. "<< endl;
						if(error == 1){
							cout<<"entrada incorrecta.... intentalo nuevamente y lee atentamente"<<endl;
							delay(2);
							system("PAUSE");
						}
					}

					if (opcionIngreso == "1" || opcionIngreso == "2" || opcionIngreso == "3" || opcionIngreso == "4" || opcionIngreso == "5" || opcionIngreso == "6" || opcionIngreso == "7" || opcionIngreso == "8" || opcionIngreso == "9")
						aceptado = true;

					system("cls");
				}while(!aceptado);
				//Termina menu ingreso

				//Efecto de espera
				
				cout<<"Un momento por favor."<<endl;
				delay(1);
				system("cls");
				cout<<"Un momento por favor.."<<endl;
				delay(1);
				system("cls");
				cout<<"Un momento por favor..."<<endl;
				delay(1);
				system("cls");
				//Termina efecto de espera


				/*---------------------------------------------------------------//
				| Inicializacion del Gymnasio desde cero 						 |	
				//---------------------------------------------------------------*/


				if(opcionIngreso.compare("1") == 0){

					//Variables para esta opcion
					string zonaPesas, zonaHumeda, zonaCardio, recepcion; //Almacena las capacidades totales de cada una de las zonas del gimnasio

					int capacidadTotalGym = 0; //Almacena la suma de las capacidades de cada zona y la establece como la capacidad total del gimnasio
					bool aceptado = false; //Dictamina si el dato que fue ingresado es aceptado o no
					cout<<"Bienvenido a la inaguracion del Gimnasio de Doraemon"<<endl;
					delay(2);
					system("cls");

					// Peticion de la informacion de la capacidad maxima que va a tener
					// la Recepcion

					while(!aceptado){
						cout << "..::..Por favor ingresa los datos..::.." << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl << endl;
						cout << "Capacidad total de personas de la Recepci" << (char)o << "n (min 1 - max 60): ";
						cin >> recepcion;

						try {
							if (!comprobacion(recepcion)) throw 1;
							if (atoi(recepcion.c_str()) > 60) throw 2;
							if (atoi(recepcion.c_str()) < 1) throw 3;
						}
						catch(int error){
							if (error == 1){
								cout << endl << endl;
								cout << "Entrada invalida debido a que esta ingresando letra(s) y/o caracter(es) especial(es)." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 2){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)a << "ximo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 3){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)i <<"nimo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}
						}

						if(comprobacion(recepcion) && atoi(recepcion.c_str()) <= 60 && atoi(recepcion.c_str()) > 0)
							aceptado = true;

						system("cls");
					}

					gym->setCapacidadMaxima( "Recepcion", atoi(recepcion.c_str()));
					capacidadTotalGym += atoi(recepcion.c_str());
					aceptado = false;


					// Peticion de la informacion de la capacidad maxima que va a tener
					// la Zona Pesas

					while(!aceptado){
						cout << "..::.. Por favor ingresa los datos ..::.." << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl << endl;
						cout << "Capacidad total de personas de la Recepci" << (char)o <<"n: " << recepcion << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl;
						cout << "Capacidad total de personas de la Zona Pesas (min 1 - max 60): ";
						cin >> zonaPesas;

						try {
							if (!comprobacion(zonaPesas)) throw 1;
							if (atoi(zonaPesas.c_str()) > 60) throw 2;
							if (atoi(zonaPesas.c_str()) < 1) throw 3;
						}
						catch(int error){
							if (error == 1){
								cout << endl << endl;
								cout << "Entrada invalida debido a que esta ingresando letra(s) y/o caracter(es) especial(es)." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 2){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)a << "ximo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 3){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)i <<"nimo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}
						}

						if(comprobacion(zonaPesas) && atoi(zonaPesas.c_str()) <= 60 && atoi(zonaPesas.c_str()) > 0)
							aceptado = true;
						system("cls");
					}

					gym->setCapacidadMaxima( "Zona Pesas", atoi(zonaPesas.c_str()));
					capacidadTotalGym += atoi(zonaPesas.c_str());
					aceptado = false;

					// Peticion de la informacion de la capacidad maxima que va a tener
					// la Zona Cardio

					while(!aceptado){
						cout << "..::.. Por favor ingresa los datos ..::.." << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl << endl;
						cout << "Capacidad total de personas de la Recepci" << (char)o <<"n: " << recepcion << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl;
						cout << "Capacidad total de personas de la Zona Pesas: " << zonaPesas << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl;
						cout << "Capacidad total de personas de la Zona Cardio (min 1 - max 60): ";
						cin >> zonaCardio;

						try {
							if (!comprobacion(zonaCardio)) throw 1;
							if (atoi(zonaCardio.c_str()) > 60) throw 2;
							if (atoi(zonaCardio.c_str()) < 1) throw 3;
						}
						catch(int error){
							if (error == 1){
								cout << endl << endl;
								cout << "Entrada invalida debido a que esta ingresando letra(s) y/o caracter(es) especial(es)." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 2){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)a << "ximo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 3){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)i <<"nimo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}
						}

						if(comprobacion(zonaCardio) && atoi(zonaCardio.c_str()) <= 60 && atoi(zonaCardio.c_str()) > 0)
							aceptado = true;
						system("cls");
					}
					
					gym->setCapacidadMaxima( "Zona Cardio", atoi(zonaCardio.c_str()));
					capacidadTotalGym += atoi(zonaCardio.c_str());
					aceptado = false;

					// Peticion de la informacion de la capacidad maxima que va a tener
					// la Zona Humeda

					while(!aceptado){
						cout << "..::.. Por favor ingresa los datos ..::.." << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl << endl;
						cout << "Capacidad total de personas de la Recepci" << (char)o << "n: " << recepcion << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl;
						cout << "Capacidad total de personas de la Zona Pesas: " << zonaPesas << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl;
						cout << "Capacidad total de personas de la Zona Cardio: " << zonaCardio << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl;
						cout << "Capacidad total de personas de la Zona Humeda (min 1 - max 60): ";
						cin >> zonaHumeda;

						try {
							if (!comprobacion(zonaHumeda)) throw 1;
							if (atoi(zonaHumeda.c_str()) > 60) throw 2;
							if (atoi(zonaHumeda.c_str()) < 1) throw 3;
						}
						catch(int error){
							if (error == 1){
								cout << endl << endl;
								cout << "Entrada invalida debido a que esta ingresando letra(s) y/o caracter(es) especial(es)." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 2){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)a << "ximo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}

							if (error == 3){
								cout << endl << endl;
								cout << "El valor ingresado excede el valor m" << (char)i <<"nimo." << endl;
								cout << "    Favor volver a intentarlo." << endl << endl;
								delay(1);
								system("pause");
							}
						}

						if(comprobacion(zonaHumeda) && atoi(zonaHumeda.c_str()) <= 60 && atoi(zonaHumeda.c_str()) > 0)
							aceptado = true;
						system("cls");
					}

					gym->setCapacidadMaxima( "Zona Humeda", atoi(zonaHumeda.c_str()));
					capacidadTotalGym += atoi(zonaHumeda.c_str());
					aceptado = false;

					system("cls");

					gym->setCapacidadMaximaGym(capacidadTotalGym);
					cout << endl << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << endl << "..::..Gracias por su colaboraci"<< (char)o << "n..::.."<< endl;
					delay(2);

					archivo + gym;		
				}


				/*---------------------------------------------------------------//
				| Cambio del estado del Gimnasio de doraemon				 |	
				//---------------------------------------------------------------*/


				else if(opcionIngreso.compare("2") == 0){
					
					string estado;
					bool aceptado = false;

					do{
						cout << "..::.. Bienvenido al modulo de cambio de estado de Gimnasio ..::.."<<endl;
						cout << "   Favor escoge un estado " << endl;
						cout << "0) Cerrado." << endl;
						cout << "1) Abierto." << endl;
						cout << "2) Mantenimiento." << endl << endl;
						cout << "Estado: ";
						cin >> estado;
						try {

							if (estado.size() != 0){
								if (estado[0] == 'e' || estado[0] == 'E') throw 2;

								if (estado[0] == 'c' || estado[0] == 'C') throw 3;
								if (estado.compare("0") != 0 && estado[0] == '0') throw 3;
								
								if (estado[0] == 'a' || estado[0] == 'A') throw 4;
								if (estado.compare("1") != 0 && estado[0] == '1') throw 4;

								if (estado[0] == 'm' || estado[0] == 'M') throw 5;
								if (estado.compare("2") != 0 && estado[0] == '2') throw 5;

								if (!comprobacion(estado)) throw 6;
								if (atoi(estado.c_str()) < 0) throw 7;
								if (atoi(estado.c_str()) > 2) throw 8;
							}
							else throw 1;
							
						}
						catch(int error) {
							
							aceptado = false;
							if (error == 1){

								cout << endl << endl << "Favor Ingresar un valor num"<< (char)e <<"rico." << endl;
								delay(2);
								system("pause");
							}

							else if (error == 2){

								cout << endl << endl << "Recuerde que las opciones de estados son:" << endl << endl;
								cout << "Estados" << endl;
								cout << "0) Cerrado." << endl;
								cout << "1) Abierto." << endl;
								cout << "2) Mantenimiento." << endl << endl;

								delay(2);
								system("pause");
							}

							else if (error == 3){
								
								cout << endl << endl << "Quiz"<< (char)a <<"s quisiste escoger la opci" << (char)o << "n de estado <Cerrado>." << endl;
								cout << "   Si es as" << (char)i << ", favor ingresar el valor 0" << endl << endl;
								delay(2);
								system("pause");
							}

							else if (error == 4){
								
								cout << endl << endl << "Quiz"<< (char)a <<"s quisiste escoger la opci" << (char)o << "n de estado <Abierto>." << endl;
								cout << "   Si es as" << (char)i << ", favor ingresar el valor 1" << endl << endl;
								delay(2);
								system("pause");
							} 

							else if (error == 5){

								cout << endl << endl << "Quiz"<< (char)a <<"s quisiste escoger la opci" << (char)o << "n de estado <Mantenimiento>." << endl;
								cout << "   Si es as" << (char)i << ", favor ingresar el valor 2" << endl << endl;
								delay(2);
								system("pause");
							} 

							else if (error == 6){

								cout << endl << endl << "Entrada no valida debido a que ingreso letra(s) y/o caracter(es) especiales." << endl;
								cout << "   Favor ingresar valores num" << (char)e << "ricos." << endl << endl;
								delay(2);
								system("pause");
							}

							else if (error == 7){
 
								cout << endl << endl << "Entrada no valida debido a que ingreso un n" << (char)u << "mero menor que la opci" << (char)o << "n con menor valor."  << endl;
								cout << "   Favor ingresar un n" << (char)u << "mero que se encuentre dentro del rango (0 hasta 2)." << endl << endl;
								delay(2);
								system("pause");
							}

							else if (error == 8){
 
								cout << endl << endl << "Entrada no valida debido a que ingreso un n" << (char)u << "mero mayor que la opci" << (char)o << "n con mayor valor."  << endl;
								cout << "   Favor ingresar un n" << (char)u << "mero que se encuentre dentro del rango (0 hasta 2)." << endl << endl;
								delay(2);
								system("pause");
							}

						}

						if (estado == "1" || estado == "2" || estado == "0")
							aceptado = true;

						system("cls");

					}while (!aceptado);

					gym->setEstadoGym(atoi(estado.c_str()));
					
					if (estado != "1"){
							
						if (gym->getEstadoZonas("Recepcion") != "Mantenimiento")
							gym->setEstadoZonas("Recepcion",atoi(estado.c_str()));
						
						if (gym->getEstadoZonas("Zona Pesas") != "Mantenimiento")
							gym->setEstadoZonas("Zona Pesas",atoi(estado.c_str()));

						if (gym->getEstadoZonas("Zona Cardio") != "Mantenimiento")
							gym->setEstadoZonas("Zona Cardio",atoi(estado.c_str()));

						if (gym->getEstadoZonas("Zona Humeda") != "Mantenimiento")
							gym->setEstadoZonas("Zona Humeda",atoi(estado.c_str()));
					}

					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(2);

					archivo + gym;
				}


				/*---------------------------------------------------------------//
				| Cambio del estado general del Gimnasio de doraemon				 |	
				//---------------------------------------------------------------*/


				else if(opcionIngreso.compare("3") == 0){
					string estado;
					string zona = "";
					bool aceptado = false;
					
					do{
						
						cout << "..::.. Bienvenido al modulo de modificacion del estado de las Zonas ..::.."<<endl;
						cout << "   Favor escoge una zona " << endl;

						cout << endl << "Zonas: " << endl;
						cout << "1) Recepcion" << endl;
						cout << "2) Zona Pesas" << endl;
						cout << "3) Zona Cardio" << endl;
						cout << "4) Zona Humeda" << endl << endl;


						cout<<"Zona: "; 
						
						getline(cin, zona);
						try{
							if (zona.size() != 0){
								if (zona[0] == '1' && zona.size() > 1) throw 1;
								if (zona.compare("Recepcion") == 0) throw 1;
								if (zona.compare("recepcion") == 0) throw 1;
								if (zona.compare("RECEPCION") == 0) throw 1;
								if (zona[0] == 'R' || zona[0] == 'r') throw 1;

								if (zona[0] == '2' && zona.size() > 1) throw 2;
								if (zona.compare("Zona Pesas") == 0) throw 2;
								if (zona.compare("zona pesas") == 0) throw 2;
								if (zona.compare("ZonaPesas") == 0) throw 2;
								if (zona.compare("zonapesas") == 0) throw 2;
								if (zona.compare("ZONA PESAS") == 0) throw 2;
								if (zona.compare("ZONAPESAS") == 0) throw 2;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 2;

								if (zona[0] == '3' && zona.size() > 1) throw 3;
								if (zona.compare("Zona Cardio") == 0) throw 3;
								if (zona.compare("zona cardio") == 0) throw 3;
								if (zona.compare("ZonaCardio") == 0) throw 3;
								if (zona.compare("zonacardio") == 0) throw 3;
								if (zona.compare("ZONA CARDIO") == 0) throw 3;
								if (zona.compare("ZONACARDIO") == 0) throw 3;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 3;


								if (zona[0] == '4' && zona.size() > 1) throw 4;
								if (zona.compare("Zona Humeda") == 0) throw 4;
								if (zona.compare("zona humeda") == 0) throw 4;
								if (zona.compare("ZonaHumeda") == 0) throw 4;
								if (zona.compare("zonahumeda") == 0) throw 4;
								if (zona.compare("ZONA HUMEDA") == 0) throw 4;
								if (zona.compare("ZONAHUMEDA") == 0) throw 4;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 4;

								if (zona[0] == 'z' || zona[0] == 'Z') throw 6;
								if (zona != "1" && zona != "2" && zona != "3" && zona != "4") throw 5;
							}
							else
								throw 5;
						}

						catch(int error){
							
							if(error == 1){
								cout << endl << endl << "Entrada incorrecta...." << endl << " Ayuda: puede que la entrada que quieras sea Recepci" << (char)o << "n, en ese caso digite el n" << (char)u << "mero 1"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 2){
								cout << endl << endl <<"Entrada incorrecta...." << endl << " Ayuda: puede que la entrada que quieras sea Zona Pesas, en ese caso digite el n"<< (char)u << "mero 2"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 3){
								cout << endl << endl << "Entrada incorrecta...." << endl << " Ayuda: puede que la entrada que quieras sea Zona Cardio, en ese caso digite el n"<< (char)u << "mero 3"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 4){
								cout << endl << endl << "Entrada incorrecta...." << endl << " Ayuda: puede que la entrada que quieras sea Zona Humeda, en ese caso digite el n"<< (char)u << "mero 4"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 5){
								cout<<"Entrada incorrecta...."<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 6){
								cout<<"Entrada incorrecta...."<<endl<<" Ayuda: las zonas propuestas son:" << endl;
								cout << endl << "Zonas " << endl;
								cout << "1) Recepcion" << endl;
								cout << "2) Zona Pesas" << endl;
								cout << "3) Zona Humeda" << endl;
								cout << "4) Zona Cardio" << endl << endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}

						}

						if (zona == "1" || zona == "2" || zona == "3" || zona == "4")
							aceptado = true;
						
						system("cls");

					}while(!aceptado);

					aceptado = false;
					
					do{

						cout << "..::.. Bienvenido al m" << (char)o << "dulo de modificaci" << (char)o << "n del estado de las Zonas ..::.." << endl ;
						cout << "   Favor escoge un estado " << endl;

						cout << endl << "Zonas " << endl;
						cout << "1) Recepcion" << endl;
						cout << "2) Zona Pesas" << endl;
						cout << "3) Zona Cardio" << endl;
						cout << "4) Zona Humeda" << endl << endl;
						
						cout << "Zona: " << zona << endl << endl;

						cout << "Estados" << endl;
						cout << "0) Cerrado." << endl;
						cout << "1) Abierto." << endl;
						cout << "2) Mantenimiento." << endl;


						cout << endl <<"Estado: ";
						getline(cin,estado);
						
						try {

							if (estado.size() != 0){
								if (estado[0] == 'e' || estado[0] == 'E') throw 2;

								if (estado[0] == 'c' || estado[0] == 'C') throw 3;
								if (estado.compare("0") != 0 && estado[0] == '0') throw 3;
								
								if (estado[0] == 'a' || estado[0] == 'A') throw 4;
								if (estado.compare("1") != 0 && estado[0] == '1') throw 4;

								if (estado[0] == 'm' || estado[0] == 'M') throw 5;
								if (estado.compare("2") != 0 && estado[0] == '2') throw 5;

								if (!comprobacion(estado)) throw 6;
								if (atoi(estado.c_str()) < 0) throw 7;
								if (atoi(estado.c_str()) > 2) throw 8;
							}
							else throw 1;
							
						}
						catch(int error) {
							
							aceptado = false;
							if (error == 1){

								cout << endl << endl << "Favor Ingresar un valor num"<< (char)e <<"rico." << endl;
								delay(2);
								system("pause");
							}

							else if (error == 2){

								cout << endl << endl << "Recuerde que las opciones de estados son:" << endl << endl;
								cout << "Estados" << endl;
								cout << "0) Cerrado." << endl;
								cout << "1) Abierto." << endl;
								cout << "2) Mantenimiento." << endl << endl;
								delay(2);
								system("pause");
							}

							else if (error == 3){
								
								cout << endl << endl << "Quiz"<< (char)a <<"s quisiste escoger la opci" << (char)o << "n de estado <Cerrado>." << endl;
								cout << "   Si es as" << (char)i << ", favor ingresar el valor 0" << endl << endl;
								delay(2);
								system("pause");
							}

							else if (error == 4){
								
								cout << endl << endl << "Quiz"<< (char)a <<"s quisiste escoger la opci" << (char)o << "n de estado <Abierto>." << endl;
								cout << "   Si es as" << (char)i << ", favor ingresar el valor 1" << endl << endl;
								delay(2);
								system("pause");
							} 

							else if (error == 5){

								cout << endl << endl << "Quiz"<< (char)a <<"s quisiste escoger la opci" << (char)o << "n de estado <Mantenimiento>." << endl;
								cout << "   Si es as" << (char)i << ", favor ingresar el valor 2" << endl << endl;
								delay(2);
								system("pause");
							} 

							else if (error == 6){

								cout << endl << endl << "Entrada no valida debido a que ingreso letra(s) y/o caracter(es) especiales." << endl;
								cout << "   Favor ingresar valores num" << (char)e << "ricos." << endl << endl;
								aceptado = false;
								delay(2);
								system("pause");
							}

							else if (error == 7){
 
								cout << endl << endl << "Entrada no valida debido a que ingreso un n" << (char)u << "mero menor que la opci" << (char)o << "n con menor valor."  << endl;
								cout << "   Favor ingresar un n" << (char)u << "mero que se encuentre dentro del rango (0 hasta 2)." << endl << endl;
								delay(2);
								system("pause");
							}

							else if (error == 8){
 
								cout << endl << endl << "Entrada no valida debido a que ingreso un n" << (char)u << "mero mayor que la opci" << (char)o << "n con mayor valor."  << endl;
								cout << "   Favor ingresar un n" << (char)u << "mero que se encuentre dentro del rango (0 hasta 2)." << endl << endl;
								delay(2);
								system("pause");
							}

						}

						if (estado == "1" || estado == "2" || estado == "0")
							aceptado = true;
						
						system("cls");

					} while(!aceptado);

					if (zona == "1")
						zona = "Recepcion";
					else if (zona == "2")
						zona = "Zona Pesas";
					else if (zona == "3")
						zona = "Zona Cardio";
					else
						zona = "Zona Humeda";

					gym->setEstadoZonas(zona,atoi(estado.c_str()));
					system("cls");
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(2);

					archivo + gym;
				}


				/*---------------------------------------------------------------//
				| Cambio de capacidad por zonas unitariamente, es nesesario que escribas
				| Zona Humeda por ejemplo para que el programa te saque un resultado satisfactorio				 |	
				//---------------------------------------------------------------*/


				else if(opcionIngreso.compare("4") == 0){

					string capacidad;
					bool aceptado = false;
					string zona;
					
					do{
						aceptado = true;
						system("cls");
						cout << "..::.. Bienvenido al modulo de modificaci" << (char)o << "n de capacidad maxima de Zonas ..::.." << endl;
						cout << "Favor escoge una cantidad y una zona " << endl << endl;
						cout << " Zonas" << endl;
						cout << "   1) Recepcion" << endl;
						cout << "   2) Zona Pesas" << endl;
						cout << "   3) Zona Cardio" << endl;
						cout << "   4) Zona Humeda" << endl << endl;
						
						cout<<"Zona: ";
						getline(cin, zona);

						try{
							if (zona.size() != 0){
								if (zona[0] == '1' && zona.size() > 1) throw 1;
								if (zona.compare("Recepcion") == 0) throw 1;
								if (zona.compare("recepcion") == 0) throw 1;
								if (zona[0] == 'R' || zona[0] == 'r') throw 1;

								if (zona[0] == '2' && zona.size() > 1) throw 2;
								if (zona.compare("Zona Pesas") == 0) throw 2;
								if (zona.compare("zona pesas") == 0) throw 2;
								if (zona.compare("ZonaPesas") == 0) throw 2;
								if (zona.compare("zonapesas") == 0) throw 2;
								if (zona.compare("ZONA PESAS") == 0) throw 2;
								if (zona.compare("ZONAPESAS") == 0) throw 2;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 2;

								if (zona[0] == '3' && zona.size() > 1) throw 3;
								if (zona.compare("Zona Cardio") == 0) throw 3;
								if (zona.compare("zona cardio") == 0) throw 3;
								if (zona.compare("ZonaCardio") == 0) throw 3;
								if (zona.compare("zonacardio") == 0) throw 3;
								if (zona.compare("ZONA CARDIO") == 0) throw 3;
								if (zona.compare("ZONACARDIO") == 0) throw 3;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 3;


								if (zona[0] == '4' && zona.size() > 1) throw 4;
								if (zona.compare("Zona Humeda") == 0) throw 4;
								if (zona.compare("zona humeda") == 0) throw 4;
								if (zona.compare("ZonaHumeda") == 0) throw 4;
								if (zona.compare("zonahumeda") == 0) throw 4;
								if (zona.compare("ZONA HUMEDA") == 0) throw 4;
								if (zona.compare("ZONAHUMEDA") == 0) throw 4;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 4;

								if (zona[0] == 'z' || zona[0] == 'Z') throw 6;
								if (zona != "1" && zona != "2" && zona != "3" && zona != "4") throw 5;
							}
							else
								throw 5;
						}

						catch(int error){
							
							if(error == 1){
								cout << endl << endl <<"Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Recepci" << (char)o << "n, en ese caso digite el n" << (char)u << "mero 1"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 2){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Zona Pesas, en ese caso digite el n"<< (char)u << "mero 2"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 3){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Zona Cardio, en ese caso digite el n"<< (char)u << "mero 3"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 4){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Zona Humeda, en ese caso digite el n"<< (char)u << "mero 4"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 5){
								cout << endl << endl << "Entrada incorrecta...." << endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 6){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: las zonas propuestas son:" << endl;
								cout << endl << "Zonas " << endl;
								cout << "1) Recepcion" << endl;
								cout << "2) Zona Pesas" << endl;
								cout << "3) Zona Humeda" << endl;
								cout << "4) Zona Cardio" << endl << endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}

						}
						
						system("cls");
					} while(aceptado == false);

					do{

						aceptado = true;
						cout << "..::.. Bienvenido al modulo de modificacion de capacidad maxima de Zonas ..::.."<<endl;
						cout << "Favor escoge una cantidad y una zona " << endl << endl;
						cout << " Zonas" << endl;
						cout << "   1) Recepcion" << endl;
						cout << "   2) Zona Pesas" << endl;
						cout << "   3) Zona Cardio" << endl;
						cout << "   4) Zona Humeda" << endl << endl;
						
						cout<<"Zona: " << zona << endl;
						cout << "Capacidad: ";
						cin >> capacidad;

						try {
							if (!comprobacion(capacidad)) throw 2;
							if (atoi(capacidad.c_str()) < 0 || atoi(capacidad.c_str()) > 60) throw 1;
						}
						catch(int error) {
							
							if(error == 1){
								cout << endl << endl <<"entrada incorrecta.... las cantidades son menores a 60"<<endl;
								delay(1);
								aceptado = false;
								system("PAUSE");
							}

							if (error == 2){
								cout << endl << endl << "Entrada invalida solo se aceptan numeros. Favor volver a ingresar la capacidad." << endl;
								delay(1);
								aceptado = false;
								system("pause");
							}

						}
						system("cls");

					} while(!aceptado);

					if (zona == "1")
						zona = "Recepcion";
					else if (zona == "2")
						zona = "Zona Pesas";
					else if (zona == "3")
						zona = "Zona Cardio";
					else
						zona = "Zona Humeda"; 

					gym->setCapacidadMaximaGym(gym->getCapacidadMaximaGym() - gym->getCapacidadMaxima(zona) + atoi(capacidad.c_str()));
					gym->setCapacidadMaxima(zona,atoi(capacidad.c_str()));
					system("cls");
					cout<<"..::.. Gracias por su colaboraci"<< (char)o << "n ..::.."<<endl;
					delay(2);

					archivo + gym;
				
				}
				/*---------------------------------------------------------------//
				| Contratacion de empleados por zona es nesesario introducir los 
				| los nombres determinados por la zona (recepcionista, empleado_servico)	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("5") == 0){
					
					bool aceptado;
					string zona;
					do{
						aceptado = true;
						system("cls");
						cout << "..::.. Bienvenido al modulo de modificaci" << (char)o << "n de capacidad maxima de Zonas ..::.." << endl;
						cout << "Favor escoge una cantidad y una zona " << endl << endl;
						cout << " Zonas" << endl;
						cout << "   1) Recepcion" << endl;
						cout << "   2) Zona Pesas" << endl;
						cout << "   3) Zona Cardio" << endl;
						cout << "   4) Zona Humeda" << endl << endl;
						
						cout<<"Zona: ";
						getline(cin, zona);

						try{
							if (zona.size() != 0){
								if (zona[0] == '1' && zona.size() > 1) throw 1;
								if (zona.compare("Recepcion") == 0) throw 1;
								if (zona.compare("recepcion") == 0) throw 1;
								if (zona[0] == 'R' || zona[0] == 'r') throw 1;

								if (zona[0] == '2' && zona.size() > 1) throw 2;
								if (zona.compare("Zona Pesas") == 0) throw 2;
								if (zona.compare("zona pesas") == 0) throw 2;
								if (zona.compare("ZonaPesas") == 0) throw 2;
								if (zona.compare("zonapesas") == 0) throw 2;
								if (zona.compare("ZONA PESAS") == 0) throw 2;
								if (zona.compare("ZONAPESAS") == 0) throw 2;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 2;

								if (zona[0] == '3' && zona.size() > 1) throw 3;
								if (zona.compare("Zona Cardio") == 0) throw 3;
								if (zona.compare("zona cardio") == 0) throw 3;
								if (zona.compare("ZonaCardio") == 0) throw 3;
								if (zona.compare("zonacardio") == 0) throw 3;
								if (zona.compare("ZONA CARDIO") == 0) throw 3;
								if (zona.compare("ZONACARDIO") == 0) throw 3;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 3;


								if (zona[0] == '4' && zona.size() > 1) throw 4;
								if (zona.compare("Zona Humeda") == 0) throw 4;
								if (zona.compare("zona humeda") == 0) throw 4;
								if (zona.compare("ZonaHumeda") == 0) throw 4;
								if (zona.compare("zonahumeda") == 0) throw 4;
								if (zona.compare("ZONA HUMEDA") == 0) throw 4;
								if (zona.compare("ZONAHUMEDA") == 0) throw 4;
								if (zona.size() > 5)
									if(zona[5] == 'p' || zona[5] == 'P' || zona[4] == 'p' || zona[4] == 'P') throw 4;

								if (zona[0] == 'z' || zona[0] == 'Z') throw 6;
								if (zona != "1" && zona != "2" && zona != "3" && zona != "4") throw 5;
							}
							else
								throw 5;
						}

						catch(int error){
							
							if(error == 1){
								cout << endl << endl <<"Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Recepci" << (char)o << "n, en ese caso digite el n" << (char)u << "mero 1"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 2){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Zona Pesas, en ese caso digite el n"<< (char)u << "mero 2"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 3){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Zona Cardio, en ese caso digite el n"<< (char)u << "mero 3"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 4){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: puede que la entrada que quieras sea Zona Humeda, en ese caso digite el n"<< (char)u << "mero 4"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 5){
								cout << endl << endl << "Entrada incorrecta...." << endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 6){
								cout << endl << endl << "Entrada incorrecta...." << endl << "  Ayuda: las zonas propuestas son:" << endl;
								cout << endl << "Zonas " << endl;
								cout << "1) Recepcion" << endl;
								cout << "2) Zona Pesas" << endl;
								cout << "3) Zona Humeda" << endl;
								cout << "4) Zona Cardio" << endl << endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}

						}
						
						system("cls");
					} while(!aceptado);

					if (zona == "1")
						zona = "Recepcion";
					else if (zona == "2")
						zona = "Zona Pesas";
					else if (zona == "3")
						zona = "Zona Cardio";
					else
						zona = "Zona Humeda";

					gym->contratarEmpleadoZona(zona);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(2);
				}

				else if(opcionIngreso.compare("6") == 0){
					bool aceptado = false;
					string zona = "";
					do{
						aceptado = true;
						system("cls");
						cout<<"..::.. Bienvenido al modulo para el Despido de empleados ..::.."<<endl;
						cout<<"Por favor ingresa la siguiente informacion"<<endl<<endl;
						
						cout<<"Zona: ";
						cin.ignore();
						getline(cin, zona);
						try{
							if(zona.compare("Recepcion") != 0 && zona.compare("recepcion") != 0 && (zona[0] == 'R' or zona[0] == 'r') && zona[6]!= 'a') throw 1;
							if(zona.compare("Zona Pesas") != 0 && zona.compare("zona pesas") != 0 && (zona[5] == 'P'  or zona[5] == 'p') ) throw 2;
							if(zona.compare("Zona Cardio") != 0 && zona.compare("zona cardio") != 0 && (zona[5]== 'C' or zona[5] == 'c') && zona[6]== 'a' ) throw 3;
							if(zona.compare("Zona Humeda") != 0 && zona.compare("zona humeda") != 0 && (zona[5]== 'H' or zona[5] == 'h') ) throw 4;
						}
						catch(int error){
							system("cls");
							cout<< "Valor ingresado invalido. "<< endl;
							if(error == 1){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Recepcion"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 2){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Zona Pesas"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 3){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Zona Cardio"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 4){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Zona Humeda"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
						}
						system("cls");
					} while(aceptado == false);
					system("cls");
					gym->despedirEmpleadoZona(zona);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(2);
				}

				else if(opcionIngreso.compare("7") == 0){
					bool aceptado = false;
					string zona = "";
					do{
						aceptado = true;
						system("cls");
						cout<<"..::.. Bienvenido al modulo de Informacion de Empleados ..::.."<<endl;
						cout<<"Por favor ingresa la siguiente informacion"<<endl<<endl;
						
						cout<<"Zona: ";
						cin.ignore();
						getline(cin, zona);
						try{
							if(zona.compare("Recepcion") != 0 && zona.compare("recepcion") != 0 && (zona[0] == 'R' or zona[0] == 'r') && zona[6]!= 'a') throw 1;
							if(zona.compare("Zona Pesas") != 0 && zona.compare("zona pesas") != 0 && (zona[5] == 'P'  or zona[5] == 'p') ) throw 2;
							if(zona.compare("Zona Cardio") != 0 && zona.compare("zona cardio") != 0 && (zona[5]== 'C' or zona[5] == 'c') && zona[6]== 'a' ) throw 3;
							if(zona.compare("Zona Humeda") != 0 && zona.compare("zona humeda") != 0 && (zona[5]== 'H' or zona[5] == 'h') ) throw 4;
						}
						catch(int error){
							system("cls");
							cout<< "Valor ingresado invalido. "<< endl;
							if(error == 1){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Recepcion"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 2){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Zona Pesas"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 3){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Zona Cardio"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
							if(error == 4){
								cout<<"entrada incorrecta...."<<endl<< " Ayuda: puede que la entrada que quieras sea Zona Humeda"<<endl;
								delay(2);
								system("PAUSE");
								aceptado = false;
							}
						}
						system("cls");
					} while(aceptado == false);
					system("cls");
					gym->mostrarDatosEmpleadosZona(zona);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(2);
				}
				/*---------------------------------------------------------------//
				| Muestra datos generales del gimnasio y sus zonas				 |	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("8") == 0){
					//gym->mostrarEstadoGeneral();
					cout << gym;
					system("pause");
				}

			}while(opcionIngreso.compare("9") != 0);

		}
		//Termina op
		//terminacion entrada 2
		if(opcionesEntrada.compare("3")){
			//Despedida
			cout<<"Bienvenido al men"<<(char)u<<" principal."<<endl;
			delay(2);
			system("cls");
			//Termina Despedida
		}
	
		
	}while(opcionesEntrada.compare("3") != 0);
	
	//Despedida
	system("cls");
	cout<<"Hasta luego que vuelva pronto"<<endl;
	delay(2);
	system("cls");
	//Termina Despedida

	return 0;
}
