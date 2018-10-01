#include "Zona_Pesas.h"
#include <iostream>
#include <string>
#include <cstdlib>

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

//_______Metodos SET__________________

void ZonaPesas::set_est_Pes(int estado){
	if(estado == 0)
		estadoPes = "Cerrado";
	else if(estado == 1)
		estadoPes = "Abierto";
	else if(estado == 2)
		estadoPes = "Mantenimiento";
}

void ZonaPesas::set_CapMaximaPes(int num){
	capMaxPes = num;
}

void ZonaPesas::set_AgrPersonaPes(int num){
	numPersonasPes += num;
}

void ZonaPesas::set_EliPersonaPes(int num){
	numPersonasPes -= num;
}


//_______Metodos GET__________________

string ZonaPesas::get_est_Pes(){
	return estadoPes;
}

int ZonaPesas::get_CapMaximaPes(){
	return capMaxPes;
}


int ZonaPesas::get_PersonasPes(){
	return numPersonasPes;
}

void ZonaPesas::contratar_empleado(string cargo){
	string aseguradora;
	int codigo, salario, subsidio;
	
	if(cargo.compare("entrenador_pesas") == 0){

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
		entrenador_pesas = new Empleado(cargo, codigo, salario);
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

ZonaPesas::ZonaPesas(){
	cout<<"Se ha creado la zona pesas del Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoPes = "Cerrado";
	entrenador_pesas = new Empleado();
	empleado_servicio = new Empleado();
}

ZonaPesas::ZonaPesas(int estado, int pes){
	cout<<"Se ha creado la zona pesas del Gimnasio de Doraemon(con Administrador)"<<endl;
	if(estado == 0)
		estadoPes = "Cerrado";
	else if(estado == 1)
		estadoPes = "Abierto";
	else if(estado == 2)
		estadoPes = "Mantenimiento";
	capMaxPes = pes;
	entrenador_pesas = new Empleado("entrenador_pesas",001,870000,"Cosalud", 01);
	empleado_servicio=new Empleado("Empleado Servicio",002,800000,"coomeva", 01);
}

ZonaPesas::~ZonaPesas(){
	cout<<"Se ha demolido la zona pesas del Gimnasio de Doraemon por inaudita bancarota"<<endl;
	delete entrenador_pesas;
	cout<< "se despidio el entrenador de zona pesas y el empleado de servicio"<<endl;
	delete empleado_servicio;
}

