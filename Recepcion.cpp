#include "Recepcion.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

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

void Recepcion::contratar_empleado(){
	string nombre, genero, cargo;
	int codigo, salario, edad, identidad;

	system("cls");
	cout<<"Bienvenido al metodo de contratacion de un empleado para la zona Recepcion"<<endl;
	if(cont <= 4){
		cout<<"Porfavor ingresa los siguientes datos:"<<endl;
		cout<<"El numero de empleados contratados es "<<cont<<" de 4 como maximo"<<endl<<endl;
		cout<<"Nombre: ";
		getline(cin,nombre);
		cout<<"Edad: ";
		cin>>edad;
		cin.ignore();
		cout<<"Genero: ";
		getline(cin, genero);
		cout<<"Cedula/Tarjeta Identidad: ";
		cin>>identidad;
		cin.ignore();
		cout<<"Cargo: ";
		getline(cin, cargo);
		cout<<"Codigo: ";
		cin>>codigo;
		cout<<"Salario: ";
		cin>>salario;
		system("cls");
		empleado[cont] = new Empleado(cargo, codigo, salario, nombre, edad, genero, identidad);
		cont +=1;
	}
	else{
		cout<<"Ya se ha completado el cupo maximo de empleados"<<endl;
	}
	system("cls");
	cout<<"Gracias por su colaboracion"<<endl;
}
void Recepcion::mostrar_datos_empleado(){
	int emp;
	system("cls");
	if (cout == 0){
		cout<<"Hasta el momento no has contratado a ningun empleado en esta zona"<<endl;
	}
	else{
		cout<<"..::.. Bienvenido al modulo de Muestra de datos de empleados..::.."<<endl;
		cout<<"El numero de empleados contratados es "<<cont<<" de 4 como maximo"<<endl<<endl;
		cout<<"__lista de empleados por nombre__"<<endl;
		for(int i = 0; i < cont; i++){
			cout<<"Nombre: "<<empleado[i]->get_Cargo()<<endl;
		}
		cout<<"ingresa el numero del empleado: ";
		cin>>emp;
		empleado[emp]->mostrar_datos();
		
	}

}

//_______CONSTRUCTORES Y DESTRUCTORES__________________

Recepcion::Recepcion(){
	cout<<"Se ha creado la recepci"<<(char)o<<"n del Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoRec = "Cerrado";
	cont = 0;
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
	cont = 0;
}

Recepcion::~Recepcion(){
	cout<<"Se ha demolido la recepci"<<(char)o<<"n del Gimnasio de Doraemon por inaudita bancarota"<<endl;
	delete *empleado;
	cout<<"se ha despedido el recepcionista y el empleado_servicio"<<endl;
}

