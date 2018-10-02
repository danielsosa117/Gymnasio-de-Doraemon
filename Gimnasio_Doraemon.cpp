/*---------------------------------------------------------------//
| Nombre del Proyecto: Gimnasio De Doraemon.
| Dia De Inicio: 08-09-2018.
| Version 1.0.
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

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

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

	//Manejo de Entradas
	string nombre, maquina, opcionesEntrada, opcionIngreso, opcionRegistrado;
	int edad, contador; 

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
		cout<<"1) Usuario"<<endl;
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

				if(opcionIngreso.compare("1") != 0 && opcionIngreso.compare("2") != 0){

					//Cuando el usuario mete una opcion que no esta dentro del rango

					cout<<"La opci"<<(char)o<<"n "<<opcionIngreso<<" no existe."<<endl;
					delay(1);
				}

				//Opcion ingreso 1
				if(opcionIngreso.compare("1") == 0){

					system("cls");
					motrarUsuarios();
					system("pause");
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

				

				//Opcion ingreso 1
				/*---------------------------------------------------------------//
				| Inicializacion del Gymnasio desde cero 						 |	
				//---------------------------------------------------------------*/

				if(opcionIngreso.compare("1") == 0){
					int Zona_Pesas, Zona_Humeda, Zona_Cardio, Recepcion, Gym;

					cout<<"Bienvenido a la inaguracion del Gimnasio de Doraemon"<<endl;
					delay(2);
					system("cls");
					cout<<"..::..Por favor ingresa los datos..::.."<<endl;
					cout<<"Capacidad total de personas de la Recepcion: ";
					cin>>Recepcion;
					gym->set_CapMaxima( "recepcion", Recepcion);
					Gym += Recepcion;
					system("cls");
					cout<<"Capacidad total de personas de la Zona Pesas"<<endl;
					cout<<"Capacidad total de personas de la Zona Pesas: ";
					cin>>Zona_Pesas;
					gym->set_CapMaxima( "zona_pesas", Zona_Pesas);
					Gym += Zona_Pesas;
					system("cls");
					cout<<"Capacidad total de personas de la Zona Cardio"<<endl;
					cout<<"Capacidad total de personas de la Zona Cardio: ";
					cin>>Zona_Cardio;
					gym->set_CapMaxima( "zona_cardio", Zona_Cardio);
					Gym += Zona_Cardio;
					system("cls");
					cout<<"Capacidad total de personas de la Zona Humeda: ";
					cin>>Zona_Humeda;
					gym->set_CapMaxima( "zona_humeda", Zona_Humeda);
					Gym += Zona_Humeda;
					system("cls");
					gym->set_CapMaximaGym(Gym);
					cout<<"..::..Gracias por su colaboracion..::.."<<endl;
					delay(1);					
				}

				/*---------------------------------------------------------------//
				| Cambio de 					 |	
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

				else if(opcionIngreso.compare("3") == 0){
					int estado;
					string zona;

					cout<<"..::.. Bienvenido al modulo de modificacion del estado de las Zonas ..::.."<<endl;
					cout<<"   Favor escoge un estado y una zona "<<endl;
					cout<<"1) Abierto."<<endl;
					cout<<"2) En mantenimiento."<<endl;
					cout<<"0) Cerrado."<<endl<<endl;
					cout<<"Zona: ";
					cin>>zona;
					cout<<"Estado: ";
					cin>>estado;
					gym->set_estZonas(zona, estado);
					system("cls");
					cout<<"Gracias por su colaboracion"<<endl;
					delay(1);
				}

				else if(opcionIngreso.compare("4") == 0){
					int capacidad;
					string zona;

					cout<<"..::.. Bienvenido al modulo de modificacion de capacidad maxima de Zonas ..::.."<<endl;
					cout<<"   Favor escoge una cantidad y una zona "<<endl;
					cout<<"Zona: ";
					cin>>zona;
					cout<<"Capacidad: ";
					cin>>capacidad;
					gym->set_CapMaxima(zona,capacidad);
					system("cls");
					cout<<"Gracias por su colaboracion"<<endl;
					delay(1);
				}

				else if(opcionIngreso.compare("5") == 0){
					string zona, cargo;
					system("cls");
					cout<<"..::.. Bienvenido al modulo de contrataciones ..::.."<<endl;
					cout<<"Por favor ingresa la siguiente informacion"<<endl;
					cout<<"Zona: ";
					cin>> zona;
					cout<<"Cargo: ";
					cin>>cargo;
					gym->contratar_empleado_zona(zona, cargo);
					cout<<"Gracias por su colaboracion"<<endl;
					delay(1);
				}



				else if(opcionIngreso.compare("7") == 0){
					gym->mostrar_estado_general();
				}

			}while(opcionIngreso.compare("0") != 0);

		}

		if(opcionesEntrada.compare("3") != 0){
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
