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

//Vector con los datos de los usuarios
vector< vector<string> > Usuarios;
vector<string> datos;

void llenarVectorUsuarios(){

	ifstream archivo("usuarios.txt");
	string linea, dato;

	while(getline(archivo,linea)){

		for (int i = 0; i < linea.size(); i++){

			if(linea[i] != '-'){
				dato.push_back(linea[i]);
			}
			else{
				datos.push_back(dato);
				dato.clear();
			}

			if(i == linea.size() - 1){
				datos.push_back(dato);
				dato.clear();
			}
		}
		Usuarios.push_back(datos);
		datos.clear();
	}
	archivo.close();
}

bool buscarPersona(string nombre){

	for(int i = 0; i < Usuarios.size();i++){
		if(Usuarios[i][1].compare(nombre) == 0)
			return true;
	}
	return false;
}

void motrarUsuarios(){

	cout << "Cargo" << '\t'<< right << "Nombre" << '\t' << "Edad" << '\t' << "G" << (char)e << "nero" << '\t' << endl;
	for(int i = 0; i < Usuarios.size(); i++){
		cout << Usuarios[i][0] << '\t' << Usuarios[i][1] << '\t' << Usuarios[i][2] << '\t' << Usuarios[i][3] << '\t' << endl;
	}
}


/*---------------------------------------------------------------//
| Funcion para la comprobacion de entradas numericas en los std::cin |	
//---------------------------------------------------------------*/

bool comprobacion( string entrada){
	if(atoi(entrada.c_str())>60)
		return false; 
	for (int i = 0; i < entrada.size(); i++){
		if (isalpha(entrada[i]))
			return false;

		if (i == entrada.size() - 1)
			return true;
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
	int edad, contador;
	Archivos archivos;
	llenarVectorUsuarios();


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

		try{
			if(opcionesEntrada.compare("1")!=0 and opcionesEntrada.compare("2")!=0 and opcionesEntrada.compare("3")!=0) throw 1;
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
				try{
					if(opcionIngreso.compare("1")!=0 and opcionIngreso.compare("2")!=0) throw 1;
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
					motrarUsuarios();
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
				cout<<"7) Mostrar datos empleados."<<endl;
				cout<<"8) Mostrar datos del Gimnasio"<<endl;
				cout<<"0) Salir."<<endl;
				cout<<endl;
				cout<<"Opci"<<(char)o<<"n: ";
				cin>>opcionIngreso;

				//Algunas exepciones agregadas

				try{
					if(opcionIngreso.compare("1")!=0 and opcionIngreso.compare("2")!=0 and opcionIngreso.compare("3")!=0 and 
						opcionIngreso.compare("4")!=0 and opcionIngreso.compare("5")!=0 and opcionIngreso.compare("6")!=0 and
						opcionIngreso.compare("7")!=0 and opcionIngreso.compare("8")!=0 and opcionIngreso.compare("0")!=0) throw 1;
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
					cout<<"..::..Por favor ingresa los datos..::.."<<endl<<endl;
					while(aceptado == false){
						cout<<"Capacidad total de personas de la Recepcion: ";
						cin>>Recepcion;
						aceptado = comprobacion(Recepcion);
						system("cls");
					}
					gym->set_CapMaxima( "recepcion", atoi(Recepcion.c_str()));
					Gym += atoi(Recepcion.c_str());
					aceptado = false;
					while(aceptado == false){
						cout<<"Capacidad total de personas de la Zona Pesas: ";
						cin>>Zona_Pesas;
						aceptado = comprobacion(Zona_Pesas);
						system("cls");
					}
					gym->set_CapMaxima( "zona_pesas", atoi(Zona_Pesas.c_str()));
					Gym += atoi(Zona_Pesas.c_str());
					aceptado = false;
					while(aceptado == false){
						cout<<"Capacidad total de personas de la Zona Cardio: ";
						cin>>Zona_Cardio;
						aceptado = comprobacion(Zona_Cardio);
						system("cls");
					}
					gym->set_CapMaxima( "zona_cardio", atoi(Zona_Cardio.c_str()));
					Gym += atoi(Zona_Cardio.c_str());
					aceptado = false;
					while(aceptado == false){
						cout<<"Capacidad total de personas de la Zona Humeda: ";
						cin>>Zona_Humeda;
						aceptado = comprobacion(Zona_Humeda);
						system("cls");
					}
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
					try{
						if(estado!=1 and estado!=2 and estado!=0) throw 1;
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
					gym->set_estGym(estado);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(1);
				}

				/*---------------------------------------------------------------//
				| Cambio del estado general del Gimnasio de doraemon				 |	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("3") == 0){
					int estado;
					string zona = "";
					bool aceptado = false;

					do{
						aceptado = true;
						cout<<"..::.. Bienvenido al modulo de modificacion del estado de las Zonas ..::.."<<endl;
						cout<<"   Favor escoge un estado y una zona "<<endl;
						cout<<"1) Abierto."<<endl;
						cout<<"2) En mantenimiento."<<endl;
						cout<<"0) Cerrado."<<endl<<endl;
						cout<<"Zona: ";
						cin.ignore();
						getline(cin, zona);
						try{
							if(zona.compare("Recepcion") != 0 and zona.compare("recepcion") != 0 and (zona[0] == 'R' or zona[0] == 'r') and zona[6]!= 'a') throw 1;
							if(zona.compare("Zona Pesas") != 0 and zona.compare("zona pesas") != 0 and (zona[5] == 'P'  or zona[5] == 'p') ) throw 2;
							if(zona.compare("Zona Cardio") != 0 and zona.compare("zona cardio") != 0 and (zona[5]== 'C' or zona[5] == 'c') and zona[6]== 'a' ) throw 3;
							if(zona.compare("Zona Humeda") != 0 and zona.compare("zona humeda") != 0 and (zona[5]== 'H' or zona[5] == 'h') ) throw 4;
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
					}while(aceptado == false);
					aceptado = true;
					do{
						cout<< endl<<"Estado: ";
						cin>>estado;
						try{
							if(estado!=1 and estado!=2 and estado!=0) throw 1;
						}
						catch(int error){
							system("cls");
							cout<< "Valor ingresado invalido. "<< endl;
							if(error == 1){
								cout<<"entrada incorrecta.... intentalo nuevamente y lee atentamente"<<endl;
								delay(2);
								aceptado = false;
								system("PAUSE");
							}
						}

						cin.ignore();
						system("cls");
					}while(aceptado == false);
					gym->set_estZonas(zona,estado);
					system("cls");
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(1);	
				}
				/*---------------------------------------------------------------//
				| Cambio de capacidad por zonas unitariamente, es nesesario que escribas
				| Zona Humeda por ejemplo para que el programa te saque un resultado satisfactorio				 |	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("4") == 0){
					int capacidad;
					bool aceptado = false;
					string zona = "";
					do{
						aceptado = true;
						system("cls");
						cout<<"..::.. Bienvenido al modulo de modificacion de capacidad maxima de Zonas ..::.."<<endl;
						cout<<"Favor escoge una cantidad y una zona "<<endl<<endl;
						cout <<"Zonas" << endl;
						cout << "Zona Pesas" << endl;
						cout << "Zona Cardio" << endl;
						cout << "Zona Humeda" << endl;
						cout << "Recepci"<<(char)o<<"n" << endl<<endl;
						
						cout<<"Zona: ";
						cin.ignore();
						getline(cin, zona);
						try{
							if(zona.compare("Recepcion") != 0 and zona.compare("recepcion") != 0 and (zona[0] == 'R' or zona[0] == 'r') and zona[6]!= 'a') throw 1;
							if(zona.compare("Zona Pesas") != 0 and zona.compare("zona pesas") != 0 and (zona[5] == 'P'  or zona[5] == 'p') ) throw 2;
							if(zona.compare("Zona Cardio") != 0 and zona.compare("zona cardio") != 0 and (zona[5]== 'C' or zona[5] == 'c') and zona[6]== 'a' ) throw 3;
							if(zona.compare("Zona Humeda") != 0 and zona.compare("zona humeda") != 0 and (zona[5]== 'H' or zona[5] == 'h') ) throw 4;
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
					aceptado = true;
					do{		
						aceptado = true;
						cout<<"Capacidad: ";
						cin>>capacidad;
						try{
							if(capacidad<0 or capacidad>60) throw 1;
						}
						catch(int error){
							system("cls");
							cout<< "Valor ingresado invalido. "<< endl;
							if(error == 1){
								cout<<"entrada incorrecta.... las cantidades son menores a 60"<<endl;
								delay(2);
								aceptado = false;
								system("PAUSE");
							}
						}
						system("cls");
					} while(aceptado == false);
					gym->set_CapMaxima(zona,capacidad);
					system("cls");
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(1);
				}
				/*---------------------------------------------------------------//
				| Contratacion de empleados por zona es nesesario introducir los 
				| los nombres determinados por la zona (recepcionista, empleado_servico)	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("5") == 0){
					bool aceptado = false;
					string zona = "";
					do{
						aceptado = true;
						system("cls");
						cout<<"..::.. Bienvenido al modulo de contrataciones ..::.."<<endl;
						cout<<"Por favor ingresa la siguiente informacion"<<endl<<endl;
						
						cout<<"Zona: ";
						cin.ignore();
						getline(cin, zona);
						try{
							if(zona.compare("Recepcion") != 0 and zona.compare("recepcion") != 0 and (zona[0] == 'R' or zona[0] == 'r') and zona[6]!= 'a') throw 1;
							if(zona.compare("Zona Pesas") != 0 and zona.compare("zona pesas") != 0 and (zona[5] == 'P'  or zona[5] == 'p') ) throw 2;
							if(zona.compare("Zona Cardio") != 0 and zona.compare("zona cardio") != 0 and (zona[5]== 'C' or zona[5] == 'c') and zona[6]== 'a' ) throw 3;
							if(zona.compare("Zona Humeda") != 0 and zona.compare("zona humeda") != 0 and (zona[5]== 'H' or zona[5] == 'h') ) throw 4;
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
					gym->contratar_empleado_zona(zona);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(1);
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
							if(zona.compare("Recepcion") != 0 and zona.compare("recepcion") != 0 and (zona[0] == 'R' or zona[0] == 'r') and zona[6]!= 'a') throw 1;
							if(zona.compare("Zona Pesas") != 0 and zona.compare("zona pesas") != 0 and (zona[5] == 'P'  or zona[5] == 'p') ) throw 2;
							if(zona.compare("Zona Cardio") != 0 and zona.compare("zona cardio") != 0 and (zona[5]== 'C' or zona[5] == 'c') and zona[6]== 'a' ) throw 3;
							if(zona.compare("Zona Humeda") != 0 and zona.compare("zona humeda") != 0 and (zona[5]== 'H' or zona[5] == 'h') ) throw 4;
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
					gym->despedir_empleado_zona(zona);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(1);
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
							if(zona.compare("Recepcion") != 0 and zona.compare("recepcion") != 0 and (zona[0] == 'R' or zona[0] == 'r') and zona[6]!= 'a') throw 1;
							if(zona.compare("Zona Pesas") != 0 and zona.compare("zona pesas") != 0 and (zona[5] == 'P'  or zona[5] == 'p') ) throw 2;
							if(zona.compare("Zona Cardio") != 0 and zona.compare("zona cardio") != 0 and (zona[5]== 'C' or zona[5] == 'c') and zona[6]== 'a' ) throw 3;
							if(zona.compare("Zona Humeda") != 0 and zona.compare("zona humeda") != 0 and (zona[5]== 'H' or zona[5] == 'h') ) throw 4;
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
					gym->mostrar_datos_empleados_zona(zona);
					cout<<"..::..Gracias por su colaboraci"<< (char)o << "n..::.."<<endl;
					delay(1);
				}
				/*---------------------------------------------------------------//
				| Muestra datos generales del gimnasio y sus zonas				 |	
				//---------------------------------------------------------------*/

				else if(opcionIngreso.compare("8") == 0){
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
