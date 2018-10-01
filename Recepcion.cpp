#include "Recepcion.h"
#include <iostream>
#include <string>
#include <cstdlib>

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

//_______Metodos SET__________________

void Recepcion::set_est_Rec(int estado){
	if(estado == 0)
		estadoRec = "Cerrado";
	else if(estado == 1)
		estadoRec = "Abierto";
	else if(estado == 2)
		estadoRec = "Mantenimiento";
}

void Recepcion::set_CapMaximaRec(int num){
	capMaxRec = num;
}

void Recepcion::set_AgrPersonaRec(int num){
	numPersonasRec += num;
}

void Recepcion::set_EliPersonaRec(int num){
	numPersonasRec -= num;
}

//_______Metodos GET__________________

string Recepcion::get_est_Rec(){
	return estadoRec;
}

int Recepcion::get_CapMaximaRec(){
	return capMaxRec;
}


int Recepcion::get_PersonasRec(){
	return numPersonasRec;
}

// METODOS APARTE

void Recepcion::contratar_empleado(string cargo){
	string aseguradora;
	int codigo, salario, subsidio;
	
	if(cargo.compare("recepcionista") == 0){

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
		recepcionista = new Empleado(cargo, codigo, salario);
	}

	else if(cargo.compare("empleado servicio") == 0){
		
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

Recepcion::Recepcion(){
	cout<<"Se ha creado la recepci"<<(char)o<<"n del Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoRec = "Cerrado";
}

Recepcion::Recepcion(int estado, int rec){
	cout<<"Se ha creado la recepci"<<(char)o<<"n del Gimnasio de Doraemon(con Administrador)"<<endl;
	if(estado == 0)
		estadoRec = "Cerrado";
	else if(estado == 1)
		estadoRec = "Abierto";
	else if(estado == 2)
		estadoRec = "Mantenimiento";
	capMaxRec = rec;
}

Recepcion::~Recepcion(){
	cout<<"Se ha demolido la recepci"<<(char)o<<"n del Gimnasio de Doraemon por inaudita bancarota"<<endl;
	delete recepcionista;
	delete empleado_servicio;
	cout<<"se ha despedido el recepcionista y el empleado_servicio"<<endl;
}

