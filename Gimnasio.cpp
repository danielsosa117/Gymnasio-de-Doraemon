/*
Nombre del Proyecto: Gimnasio De Doraemon.
Dia De Inicio: 08-09-2018.
Version 1.0.

Integrantes:

- Juan Sebastian Reyes Leyton.
- Carlos Andres Angel Calderon.
- Daniel Fernando Sosa.

Docente: Simena Dinas.

Curso: Tecnicas y Practicas De Programacion.
Semestre II

Pontificia Universidad Javeriana Cali
2018

*/
#include "BasesDatos.h"
#include "Gimnasio.h"
#include "Recepcion.h"
#include "Zona_Pesas.h"
#include "Zona_Cardio.h"
#include "Zona_Humeda.h"
#include "Cliente.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;
using std::cout;
using std::ostream;

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

//_______Metodos SET__________________

void Gimnasio::setEstadoGym(int estado){
	if(estado == 0)
		estadoGym = "Cerrado";
	else if(estado == 1)
		estadoGym = "Abierto";
	else if(estado == 2)
		estadoGym = "Mantenimiento";
}
void Gimnasio::setEstadoZonas(string zona, int estado){
	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->set_est_Rec(estado);
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
 		zonaPesas->set_est_Pes(estado);
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		zonaCardio->set_est_Car(estado);
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		zonaHumeda->set_est_Hum(estado);
	}
}

void Gimnasio::setCapacidadMaximaGym(int num){
	capMaxGym = num;
}

void Gimnasio::setCapacidadMaxima(string zona, int capMax){

	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->set_CapMaximaRec(capMax);
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
 		zonaPesas->set_CapMaximaPes(capMax);
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		zonaCardio->set_CapMaximaCar(capMax);
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		zonaHumeda->set_CapMaximaHum(capMax);
	}
}

//_______Metodos GET__________________

string Gimnasio::getEstadoGym(){
	return estadoGym;
}

int Gimnasio::getCapacidadMaximaGym(){
	return capMaxGym;
}

string Gimnasio::getEstadoZonas(string zona){

	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
		return  recepcion->get_est_Rec();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
		return  zonaPesas->get_est_Pes();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		return  zonaHumeda->get_est_Hum();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		return  zonaCardio->get_est_Car();
	}

}

int Gimnasio::getCapacidadMaxima(string zona){

	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
		return  recepcion->get_CapMaximaRec();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
		return  zonaPesas->get_CapMaximaPes();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		return  zonaHumeda->get_CapMaximaHum();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		return  zonaCardio->get_CapMaximaCar();
	}
}

void Gimnasio::registrarClientes(){
	int membresia, capital, codigo, codigoM, edad, identi;
	string nombre, genero;
	cout<<"Porfavor ingresa los siguientes datos:"<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Edad: ";
	cin>>edad;
	cin.ignore();
	cout<<"Genero: ";
	getline(cin, genero);
	cout<<"Cedula/Tarjeta Identidad: ";
	cin>>identi;
	cin.ignore();
	cout<<"numero Membresia: ";
	cin>>membresia;
	cout<<"Codigo Cliente: ";
	cin>>codigo;
	cout<<"Codigo Membresia: ";
	cin>>codigoM;
	cout<<"Capital: ";
	cin>>capital;
	system("cls");
	Cliente clientetemp(membresia, codigoM, capital, codigo, nombre, edad, genero, identi);
	Registrados.push_back(clientetemp);
	cout<<"gola";
}

void Gimnasio::mostrarPerRegistradas(){
	Registrados[0].mostrardatos();
}

//METODOS APARTE

void Gimnasio::mostrarEstadoGeneral(){
	cout<<"..::.. Bienvenido al modulo de Muestra de datos del Gimnasio en General"<<endl<<endl;
	cout<<"__Gimnasio__"<<endl;
	cout<<"El estado del Gimnasio es "<< estadoGym << endl;
	cout<<"La capacidad maxima del Gimnasio es " << capMaxGym << endl;
	cout<<"El numero de personas dentro del Gimnasio es "<<numPersonasGym<<endl<<endl;
	cout<<"__Recepcion__"<<endl;
	cout<<"El estado de la recepcion es "<<recepcion->get_est_Rec()<<endl;
	cout<<"La capacidad maxima de la recepcion es "<<recepcion->get_CapMaximaRec()<<endl;
	cout<<"El numero de personas dentro de la recepcion es "<<recepcion->get_PersonasRec()<<endl<<endl;
	cout<<"__Zona Pesas__"<<endl;
	cout<<"El estado de la Zona Pesas es "<<zonaPesas->get_est_Pes()<<endl;
	cout<<"La capacidad maxima de la Zona Pesas es "<<zonaPesas->get_CapMaximaPes()<<endl;
	cout<<"El numero de personas dentro de la Zona Pesas es "<<zonaPesas->get_PersonasPes()<<endl<<endl;
	cout<<"__Zona Humeda__"<<endl;
	cout<<"El estado de la Zona Humeda es "<<zonaHumeda->get_est_Hum()<<endl;
	cout<<"La capacidad maxima de la Zona Humeda es "<<zonaHumeda->get_CapMaximaHum()<<endl;
	cout<<"El numero de personas dentro de la Zona Humeda es "<<zonaHumeda->get_PersonasHum()<<endl<<endl;
	cout<<"__Zona Cardio__"<<endl;
	cout<<"El estado de la Zona Cardio es "<<zonaCardio->get_est_Car()<<endl;
	cout<<"La capacidad maxima de la Zona Cardio es "<<zonaCardio->get_CapMaximaCar()<<endl;
	cout<<"El numero de personas dentro de la Zona Cardio es "<<zonaCardio->get_PersonasCar()<<endl<<endl;
	system("PAUSE");
}

void Gimnasio::contratarEmpleadoZona(string zona){

	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->contratar_empleado();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
 		zonaPesas->contratar_empleado();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		zonaCardio->contratar_empleado();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		zonaHumeda->contratar_empleado();
	}
}

void Gimnasio::despedirEmpleadoZona(string zona){

	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->despedir_empleado();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
 		zonaPesas->despedir_empleado();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		zonaCardio->despedir_empleado();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		zonaHumeda->despedir_empleado();
	}
}

void Gimnasio::mostrarDatosEmpleadosZona(string zona){
	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->mostrar_datos_empleado();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
 		zonaPesas->mostrar_datos_empleado();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		zonaCardio->mostrar_datos_empleado();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		zonaHumeda->mostrar_datos_empleado();
	}
}

//_______CONSTRUCTORES Y DESTRUCTORES__________________

Gimnasio::Gimnasio(){
	cout<<"Se ha creado el Gimnasio de Doraemon(sin Administrador)"<<endl;
	vector< vector<string> > datos;
	Archivos archivo;
	archivo.setArchivo("Zonas.txt");
	archivo.setDatos();
	datos = archivo.getDatos();
	setEstadoGym(atoi(datos[0][1].c_str()));
	numPersonasGym = 0;
	capMaxGym = atoi(datos[0][1].c_str());
	recepcion = new Recepcion(atoi(datos[1][2].c_str()),atoi(datos[1][1].c_str()));
	zonaPesas = new ZonaPesas(atoi(datos[2][2].c_str()),atoi(datos[2][1].c_str()));
	zonaCardio = new ZonaCardio(atoi(datos[3][2].c_str()),atoi(datos[3][1].c_str()));
	zonaHumeda = new ZonaHumeda(atoi(datos[4][2].c_str()),atoi(datos[4][1].c_str()));
}

Gimnasio::Gimnasio(int rec,int pes,int car, int hum, int gym){

	cout<<"Se ha creado el Gimnasio de Doraemon(con Administrador)"<<endl;
	estadoGym = "Cerrado";
	numPersonasGym = 0;
	capMaxGym = gym;
	recepcion = new Recepcion(0,rec);
	zonaPesas = new ZonaPesas(0,pes);
	zonaCardio = new ZonaCardio(0,car);
	zonaHumeda = new ZonaHumeda(0,hum);

}

Gimnasio::~Gimnasio(){
	cout<<"Se ha demolido el Gimnasio de Doraemon por inesperada bancarrota"<<endl;
	delete recepcion;
	delete zonaPesas;
	delete zonaCardio;
	delete zonaHumeda;
}
