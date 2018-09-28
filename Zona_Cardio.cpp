#include "Zona_Cardio.h"
#include <iostream>
#include <string>
#include <cstdlib>

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

//_______Metodos SET__________________

void ZonaCardio::set_est_Car(int estado){
	if(estado == 0)
		estadoCar = "Cerrado";
	else if(estado == 1)
		estadoCar = "Abierto";
	else if(estado == 2)
		estadoCar = "Mantenimiento";
}

void ZonaCardio::set_CapMaximaCar(int num){
	capMaxCar = num;
}

void ZonaCardio::set_AgrPersonaCar(int num){
	numPersonasCar += num;
}

void ZonaCardio::set_EliPersonaCar(int num){
	numPersonasCar -= num;
}

//_______Metodos GET__________________

string ZonaCardio::get_est_Car(){
	return estadoCar;
}

int ZonaCardio::get_CapMaximaCar(){
	return capMaxCar;
}


int ZonaCardio::get_PersonasCar(){
	return numPersonasCar;
}

void ZonaCardio::contratar_empleado(string cargo){
	
	int codigo, salario;
	
	if(cargo.compare("entrenador_cardio") == 0){

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
		entrenador_cardio = new Empleado(cargo, codigo, salario);
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
		empleado_servicio = new Empleado(cargo, codigo, salario, aseguradora,subsidio);
	}
}


//_______CONSTRUCTORES Y DESTRUCTORES__________________

ZonaCardio::ZonaCardio(){
	cout<<"Se ha creado la zona cardio del Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoCar = "Cerrado";
}

ZonaCardio::ZonaCardio(int estado, int car){
	cout<<"Se ha creado la zona cardio del Gimnasio de Doraemon(con Administrador)"<<endl;
	if(estado == 0)
		estadoCar = "Cerrado";
	else if(estado == 1)
		estadoCar = "Abierto";
	else if(estado == 2)
		estadoCar = "Mantenimiento";
	capMaxCar = car;
}

ZonaCardio::~ZonaCardio(){
	cout<<"Se ha demolido la zona cardio del Gimnasio de Doraemon por inaudita bancarota"<<endl;
	delete entrenador_cardio;
	cout<< "se despidio el entrenador de zona cardio y el empleado de servicio"<<endl;
	delete empleado_servicio;
}

