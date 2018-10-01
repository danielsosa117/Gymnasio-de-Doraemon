#include "Zona_Humeda.h"
#include <iostream>
#include <string>
#include <cstdlib>

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

//_______Metodos SET__________________

void ZonaHumeda::set_est_Hum(int estado){
	if(estado == 0)
		estadoHum = "Cerrado";
	else if(estado == 1)
		estadoHum = "Abierto";
	else if(estado == 2)
		estadoHum = "Mantenimiento";
}

void ZonaHumeda::set_CapMaximaHum(int num){
	capMaxHum = num;
}

void ZonaHumeda::set_AgrPersonaHum(int num){
	numPersonasHum += num;
}

void ZonaHumeda::set_EliPersonaHum(int num){
	numPersonasHum -= num;
}

//_______Metodos GET__________________

string ZonaHumeda::get_est_Hum(){
	return estadoHum;
}

int ZonaHumeda::get_CapMaximaHum(){
	return capMaxHum;
}


int ZonaHumeda::get_PersonasHum(){
	return numPersonasHum;
}

void ZonaHumeda::contratar_empleado(string cargo){
	string aseguradora;
	int codigo, salario, subsidio;
	
	if(cargo.compare("encargado_zona") == 0){

		system("cls");
		cout<<"Bienvenido al metodo de contratacion de un empleado"<<endl;
		cout<<"Porfavor ingresa los siguientes datos:"<<endl;
		cout<<"Cargo: ";
		cin>>cargo;
		cout<<"Codigo: ";
		cin>>codigo;
		cout<<"Salario: ";
		cin>>salario;
		system("cls");
		encargado_zona = new Empleado(cargo, codigo, salario);
	}

	else if(cargo.compare("empleado_servicio") == 0){
		
		system("cls");
		cout<<"Bienvenido al metodo de contratacion de un empleado"<<endl;
		cout<<"Porfavor ingresa los siguientes datos:"<<endl;
		cout<<"Cargo: ";
		cin>>cargo;
		cout<<"Codigo: ";
		cin>>codigo;
		cout<<"Salario: ";
		cin>>salario;
		system("cls");
		cout<<"Gracias por su colaboracion"<<endl;
		empleado_servicio = new Empleado(cargo, codigo, salario);
	}
}


//_______CONSTRUCTORES Y DESTRUCTORES__________________

ZonaHumeda::ZonaHumeda(){
	cout<<"Se ha creado la zona humeda del Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoHum = "Cerrado";
}

ZonaHumeda::ZonaHumeda(int estado, int hum){
	cout<<"Se ha creado la zona humeda del Gimnasio de Doraemon(con Administrador)"<<endl;
	if(estado == 0)
		estadoHum = "Cerrado";
	else if(estado == 1)
		estadoHum = "Abierto";
	else if(estado == 2)
		estadoHum = "Mantenimiento";
	capMaxHum = hum;
}

ZonaHumeda::~ZonaHumeda(){
	cout<<"Se ha demolido la zona humeda del Gimnasio de Doraemon por inaudita bancarota"<<endl;
	delete encargado_zona;
	cout<< "se despidio el empleado de la zona humeda y el empleado de servicio"<<endl;
	delete empleado_servicio;
}

