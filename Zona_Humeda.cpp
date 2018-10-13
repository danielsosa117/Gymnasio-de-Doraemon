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

void ZonaHumeda::contratar_empleado(){
	string nombre, genero, cargo;
	int codigo, salario, edad, identidad;

	system("cls");
	cout<<"Bienvenido al metodo de contratacion de un empleado para la zona Humeda"<<endl;
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
void ZonaHumeda::mostrar_datos_empleado(){
	int emp;
	system("cls");
	if (cont == 0){
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

ZonaHumeda::ZonaHumeda(){
	cout<<"Se ha creado la zona humeda del Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoHum = "Cerrado";
	cont = 0;
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
	cont = 0;
}

ZonaHumeda::~ZonaHumeda(){
	cout<<"Se ha demolido la zona humeda del Gimnasio de Doraemon por inaudita bancarota"<<endl;
	delete *empleado;
	cout<< "se despidio el empleado de la zona humeda y el empleado de servicio"<<endl;

}

