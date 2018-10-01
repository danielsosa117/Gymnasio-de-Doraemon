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

/*---------------------------------------------------------------//
| Nombre y contraseña del administrador, estas van a ser tomadas durante el funcionamiento |	
//---------------------------------------------------------------*/

const string admin = "rey"; string contrasena = "gimnasio01";

/*---------------------------------------------------------------//
| Variables constantes para la introduccion de vocales con tilde |	
//---------------------------------------------------------------*/

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

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
	int edad, contador;
	Archivos archivos;

	/*---------------------------------------------------------------//
	| Creacion del Gimnacio desde cero
	//---------------------------------------------------------------*/
	Gimnasio *gym = new Gimnasio(0,0,0,0,0);

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

		system("cls");
		//Termina menu de entrada

		//Efecto de espera
		system("cls");
		cout<<"Un momento por favor."<<endl;
		delay(2);
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
			delay(1);
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
				| Exepciones basicas de introduccion de texto
				//---------------------------------------------------------------*/
				if(opcionIngreso.compare("1") != 0 && opcionIngreso.compare("2") != 0){

					cout<<"La opci"<<(char)o<<"n "<<opcionIngreso<<" no existe."<<endl;
					delay(1);
				}

				/*---------------------------------------------------------------//
				| Por el momento no tenemos la implementacion de los usuarios ya
				| ya que esta requiere una gran cantidad de tipos y la estamos planteando
				| en un documento diferente
				//---------------------------------------------------------------*/
	
				if(opcionIngreso.compare("1") == 0){

					system("cls");
					cout<< "Esta funci" << (char)o << "n se llevara a cabo en la siguiente entrega." << endl;
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
			delay(1);
			system("cls");
			cout<<"Comencemos"<<endl;
			delay(1);
			//Termina bienvenida

			do{
				system("cls");

				//Menu ingreso

				cout<<"..::.. Opci"<<(char)o<<"n del Administrador..::.."<<endl<<endl;
				cout<<"1) Inagurar El Gimnasio de Doraemon."<<endl;
				cout<<"2) Cambiar el Estado del Gimnasio."<<endl;
				cout<<"3) Cambiar el Estado de las Zonas."<<endl; 
				cout<<"4) Cambiar la capacidad de las Zonas."<<endl;
				cout<<"5) Realizar contrataciones."<<endl;
				cout<<"6) Despedir a clientes."<<endl;
				cout<<"7) Mostrar datos del Gimnasio"<<endl;
				cout<<"0) Salir."<<endl;
				cout<<endl;
				cout<<"Opci"<<(char)o<<"n: ";
				cin>>opcionIngreso;
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
				| Inicializacion del Gymnasio desde cero 						 |	
				//---------------------------------------------------------------*/

				if(opcionIngreso.compare("1") == 0){
					string Zona_Pesas, Zona_Humeda, Zona_Cardio, Recepcion;
					int Gym;
					bool aceptado = false;
					cout<<"Bienvenido a la inaguracion del Gimnasio de Doraemon"<<endl;
					delay(2);
					system("cls");
					cout<<"..::..Por favor ingresa los datos..::.."<<endl;
					do{
						cout<<"Capacidad total de personas de la Recepcion: ";
						cin>>Recepcion;
						for (int i = 0; i < Recepcion.size(); i++){
							if (isalpha(Recepcion[i])){
								aceptado = false;
								break;
							}

							if (i == Recepcion.size() - 1)
								aceptado = true;
						}
						system("cls");
					} while(aceptado == false);
					gym->set_CapMaxima( "recepcion", atoi(Recepcion.c_str()));
					Gym += atoi(Recepcion.c_str());
					aceptado = false;
					do{
						system("cls");
						cout<<"Capacidad total de personas de la Zona Pesas: ";
						cin>>Zona_Pesas;
						for (int i = 0; i < Zona_Pesas.size(); i++){
							if (isalpha(Zona_Pesas[i])){
								aceptado = false;
								break;
							}

							if (i == Zona_Pesas.size() - 1)
								aceptado = true;
						}
					} while(aceptado == false);
					gym->set_CapMaxima( "zona_pesas", atoi(Zona_Pesas.c_str()));
					Gym += atoi(Zona_Pesas.c_str());
					aceptado = false;
					do{
						system("cls");
						cout<<"Capacidad total de personas de la Zona Cardio: ";
						cin>>Zona_Cardio;
						for (int i = 0; i < Zona_Cardio.size(); i++){
							if (isalpha(Zona_Cardio[i])){
								aceptado = false;
								break;
							}

							if (i == Zona_Cardio.size() - 1)
								aceptado = true;
						}
					} while(aceptado == false);
					gym->set_CapMaxima( "zona_cardio", atoi(Zona_Cardio.c_str()));
					Gym += atoi(Zona_Cardio.c_str());
					aceptado = false;
					do{
						system("cls");
						cout<<"Capacidad total de personas de la Zona Humeda: ";
						cin>>Zona_Humeda;
						for (int i = 0; i < Zona_Humeda.size(); i++){
							if (isalpha(Zona_Humeda[i])){
								aceptado = false;
								break;
							}

							if (i == Zona_Humeda.size() - 1)
								aceptado = true;
						}
					} while(aceptado == false);
					gym->set_CapMaxima( "zona_humeda", atoi(Zona_Humeda.c_str()));
					Gym += atoi(Zona_Humeda.c_str());
					aceptado = false;
					system("cls");
					gym->set_CapMaximaGym(Gym);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(1);				
				}

				/*---------------------------------------------------------------//
				| Cambio del estado general del Gimnasio de doraemon				 |	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("2") == 0){
					int estado;

					cout<<"..::.. Bienvenido al modulo de cambio de estado de Gimnasio ..::.."<<endl;
					cout<<"   Favor escoge un estado "<<endl;
					cout<<"1) Abierto."<<endl;
					cout<<"2) En mantenimiento."<<endl;
					cout<<"0) Cerrado."<<endl<<endl;
					cout<<"Estado: ";
					cin>>estado;
					gym->set_estGym(estado);
					cout<<"Gracias por su colaboracion"<<endl;
					delay(1);
				}

				/*---------------------------------------------------------------//
				| Cambio del estado general del Gimnasio de doraemon				 |	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("3") == 0){
					int estado;
					string zona;

					cout<<"..::.. Bienvenido al modulo de modificacion del estado de las Zonas ..::.."<<endl;
					cout<<"   Favor escoge un estado y una zona "<<endl;
					cout<<"1) Abierto."<<endl;
					cout<<"2) En mantenimiento."<<endl;
					cout<<"0) Cerrado."<<endl<<endl;
					cout<<"Zona: ";
					getline(cin, zona);
					cout<<"Estado: ";
					cin>>estado;
					cin.ignore();
					system("cls");
					cout<<"Gracias por su colaboracion"<<endl;
					delay(1);
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
						system("cls");
						cout<<"..::.. Bienvenido al modulo de modificacion de capacidad maxima de Zonas ..::.."<<endl;
						cout<<"Favor escoge una cantidad y una zona "<<endl;
						cout << left << "C" << (char)o << setw(9) <<"digo" << "Zonas" << endl << endl;
						cout << left << setw(11) << "1" << "Pesas" << endl;
						cout << left << setw(11) << "2" << "Cardio" << endl;
						cout << left << setw(11) << "3" << "Humeda" << endl;
						cout << left << setw(11) << "4" << "Recepci" << (char)o << "n" << endl;
					

						cout<<"Zona: ";
						cin >> zona;
						if (zona.size() != 1)
							aceptado = false;
						else if(isalpha(zona[0]))
							aceptado = false;
						else if(atoi(zona.c_str()) < 1 || atoi(zona.c_str()) > 4)
								aceptado = false;
						else
							aceptado = true;

					} while(aceptado == false);
					aceptado = false;
					if (zona.compare("1") == 0)
						zona = "Zona Pesas";
					else if (zona.compare("2") == 0)
						zona = "Zona Cardio";
					else if (zona.compare("3") == 0)
						zona = "Zona Humeda";
					else
						zona = "Recepcion";

					do{		

						cout<<"Capacidad: ";
						cin.ignore();
						cin>>capacidad;
						for (int i = 0; i < capacidad.size(); i++){
							if (isalpha(capacidad[i])){
								aceptado = false;
								break;
							}

							if (i == capacidad.size() - 1)
								aceptado = true;
						}
					} while(aceptado == false);
					aceptado = false;
					gym->set_CapMaxima(zona,atoi(capacidad.c_str()));
					system("cls");
					cout<<"Gracias por su colaboracion"<<endl;
					delay(1);
				}
				/*---------------------------------------------------------------//
				| Contratacion de empleados por zona es nesesario introducir los 
				| los nombres determinados por la zona (recepcionista, empleado_servico)	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("5") == 0){
					cout << "En una proxima vesi" << (char)o <<"n se hara funcionar esta opci" << (char)o <<"n." << endl;
				}
				/*---------------------------------------------------------------//
				| Muestra datos generales del gimnasio y sus zonas				 |	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("7") == 0){
					gym->mostrar_estado_general();
				}

			}while(opcionIngreso.compare("0") != 0);

		}
		//Termina op
		//terminacion entrada 2
		if(opcionesEntrada.compare("3")){
			//Despedida
			cout<<"Bienvenido al men"<<(char)u<<" principal."<<endl;
			delay(1);
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
