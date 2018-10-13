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
using namespace std;

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

//_______Metodos SET__________________

void Gimnasio::set_estGym(int estado){
	if(estado == 0)
		estadoGym = "Cerrado";
	else if(estado == 1)
		estadoGym = "Abierto";
	else if(estado == 2)
		estadoGym = "Mantenimiento";
}
void Gimnasio::set_estZonas(string zona, int estado){
	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->set_est_Rec(estado);
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona_pesas") == 0){
 		zonapesas->set_est_Pes(estado);
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona_cardio") == 0){
		zonacardio->set_est_Car(estado);
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona_humeda") == 0){
		zonahumeda->set_est_Hum(estado);
	}
}

void Gimnasio::set_CapMaximaGym(int num){
	capMaxGym = num;
}

void Gimnasio::set_CapMaxima(string zona, int capMax){
	
	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->set_CapMaximaRec(capMax);
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona_pesas") == 0){
 		zonapesas->set_CapMaximaPes(capMax);
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona_cardio") == 0){
		zonacardio->set_CapMaximaCar(capMax);
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona_humeda") == 0){
		zonahumeda->set_CapMaximaHum(capMax);
	}
}

void Gimnasio::set_AgrPersonasGym(int num){
	numPersonasGym += num;
}

void Gimnasio::set_EliPersonasGym(int num){
	numPersonasGym -= num;
}

//_______Metodos GET__________________

string Gimnasio::get_est_Gym(){
	return estadoGym;
}

int Gimnasio::get_CapMaximaGym(){
	return capMaxGym;
}

int Gimnasio::get_CapMaxima(string zona){
	
	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
		return  recepcion->get_CapMaximaRec();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
		return  zonapesas->get_CapMaximaPes();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		return  zonahumeda->get_CapMaximaHum();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		return  zonahumeda->get_CapMaximaHum();
	}
}

int Gimnasio::get_PersonasGym(){
	return numPersonasGym;
}

//METODOS APARTE

void Gimnasio::mostrar_estado_general(){
	cout<<"..::.. Bienvenido al modulo de Muestra de datos del Gimnasio en General"<<endl<<endl;
	cout<<"__Gimnasio__"<<endl;
	cout<<"El estado del Gimnasio es "<<estadoGym<<endl;
	cout<<"La capacidad maxima del Gimnasio es "<<capMaxGym<<endl;
	cout<<"El numero de personas dentro del Gimnasio es "<<numPersonasGym<<endl<<endl;
	cout<<"__Recepcion__"<<endl;
	cout<<"El estado de la recepcion es "<<recepcion->get_est_Rec()<<endl;
	cout<<"La capacidad maxima de la recepcion es "<<recepcion->get_CapMaximaRec()<<endl;
	cout<<"El numero de personas dentro de la recepcion es "<<recepcion->get_PersonasRec()<<endl<<endl;
	cout<<"__Zona Pesas__"<<endl;
	cout<<"El estado de la Zona Pesas es "<<zonapesas->get_est_Pes()<<endl;
	cout<<"La capacidad maxima de la Zona Pesas es "<<zonapesas->get_CapMaximaPes()<<endl;
	cout<<"El numero de personas dentro de la Zona Pesas es "<<zonapesas->get_PersonasPes()<<endl<<endl;
	cout<<"__Zona Humeda__"<<endl;
	cout<<"El estado de la Zona Humeda es "<<zonahumeda->get_est_Hum()<<endl;
	cout<<"La capacidad maxima de la Zona Humeda es "<<zonahumeda->get_CapMaximaHum()<<endl;
	cout<<"El numero de personas dentro de la Zona Humeda es "<<zonahumeda->get_PersonasHum()<<endl<<endl;
	cout<<"__Zona Cardio__"<<endl;
	cout<<"El estado de la Zona Cardio es "<<zonacardio->get_est_Car()<<endl;
	cout<<"La capacidad maxima de la Zona Cardio es "<<zonacardio->get_CapMaximaCar()<<endl;
	cout<<"El numero de personas dentro de la Zona Cardio es "<<zonacardio->get_PersonasCar()<<endl<<endl;
	system("PAUSE");
}

void Gimnasio::contratar_empleado_zona(string zona){

	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->contratar_empleado();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
 		zonapesas->contratar_empleado();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		zonacardio->contratar_empleado();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		zonahumeda->contratar_empleado();
	}
}

void Gimnasio::mostrar_datos_empleados_zona(string zona){
	if(zona.compare("Recepcion") == 0 || zona.compare("recepcion") == 0){
 		recepcion->mostrar_datos_empleado();
	}
	if(zona.compare("Zona Pesas") == 0 || zona.compare("zona pesas") == 0){
 		zonapesas->mostrar_datos_empleado();
	}
	if(zona.compare("Zona Cardio") == 0 || zona.compare("zona cardio") == 0){
		zonacardio->mostrar_datos_empleado();
	}
	if(zona.compare("Zona Humeda") == 0 || zona.compare("zona humeda") == 0){
		zonahumeda->mostrar_datos_empleado();
	}
}

//_______CONSTRUCTORES Y DESTRUCTORES__________________

Gimnasio::Gimnasio(){
	cout<<"Se ha creado el Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoGym = "Cerrado";
	recepcion = new Recepcion();
	zonapesas = new ZonaPesas();
	zonacardio = new ZonaCardio();
	zonahumeda = new ZonaHumeda();
}

Gimnasio::Gimnasio(int rec,int pes,int car, int hum, int gym){
	cout<<"Se ha creado el Gimnasio de Doraemon(con Administrador)"<<endl;
	estadoGym = "Cerrado";
	capMaxGym = gym;
	recepcion = new Recepcion(0,rec);
	zonapesas = new ZonaPesas(0,pes);
	zonacardio = new ZonaCardio(0,car);
	zonahumeda = new ZonaHumeda(0,hum);

}

Gimnasio::~Gimnasio(){
	cout<<"Se ha demolido el Gimnasio de Doraemon por inesperada bancarrota"<<endl;
	delete recepcion;
	delete zonapesas;
	delete zonacardio;
	delete zonahumeda;
}