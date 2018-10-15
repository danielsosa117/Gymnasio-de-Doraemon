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

void ZonaCardio::contratar_empleado(){
	string nombre, genero, cargo;
	int codigo, salario, edad, identidad;

	system("cls");
	cout<<"Bienvenido al metodo de contratacion de un empleado para la Zona Cardio"<<endl;
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

void ZonaCardio::mostrar_datos_empleado(){
	int emp;
	system("cls");
	if (cont == 0){
		cout<<"Hasta el momento no has contratado a ningun empleado en esta zona"<<endl;
		system("PAUSE");
	}
	else{
		cout<<"..::.. Bienvenido al modulo de Muestra de datos de empleados..::.."<<endl;
		cout<<"El numero de empleados contratados es "<<cont<<" de 4 como maximo"<<endl<<endl;
		cout<<"__lista de empleados por nombre__"<<endl;
		for(int i = 0; i < cont; i++){
			cout<<i+1<<"  Nombre: "<<empleado[i]->get_Nombre()<<endl;
		}
		bool aceptado = false;
		while(aceptado == false){
			cout<<endl<<"ingresa el numero del empleado: ";
			cin>>emp;
			try{
				if(emp<1 or emp>cont) throw 1;
			}
			catch(int error){
				system("cls");
				cout<< "Valor ingresado invalido. "<< endl;
				if(error == 1){
					cout<<"entrada incorrecta.... El numero esta por fuera del rango"<<endl;
					aceptado = false;
					system("PAUSE");
				}
			}
			aceptado = true;
		}
		empleado[emp-1]->mostrar_datos();
		system("PAUSE");
	}
}

void ZonaCardio::despedir_empleado(){
	int emp;
	system("cls");
	if (cont == 0){
		cout<<"Hasta el momento no has contratado a ningun empleado en esta zona"<<endl;
		system("PAUSE");
	}
	else{
		cout<<"..::.. Bienvenido al modulo de Despido de empleados..::.."<<endl;
		cout<<"El numero de empleados contratados es "<<cont<<" de 4 como maximo"<<endl<<endl;
		cout<<"__lista de empleados por nombre__"<<endl;
		for(int i = 0; i < cont; i++){
			cout<<i+1<< "  Nombre: "<<empleado[i]->get_Nombre()<<endl;
		}
		bool aceptado = false;
		while(aceptado == false){
			cout<<endl<<"ingresa el numero del empleado: ";
			cin>>emp;
			try{
				if(emp<1 or emp>cont) throw 1;
			}
			catch(int error){
				system("cls");
				cout<< "Valor ingresado invalido. "<< endl;
				if(error == 1){
					cout<<"entrada incorrecta.... El numero esta por fuera del rango"<<endl;
					aceptado = false;
					system("PAUSE");
				}
			}
			aceptado = true;
		}
		delete empleado[emp-1];
		system("PAUSE");
		
	}
}
//_______CONSTRUCTORES Y DESTRUCTORES__________________

ZonaCardio::ZonaCardio(){
	cout<<"Se ha creado la zona cardio del Gimnasio de Doraemon(sin Administrador)"<<endl;
	estadoCar = "Cerrado";
	cont = 0;
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
	cont = 0;
}

ZonaCardio::~ZonaCardio(){
	cout<<"Se ha demolido la zona cardio del Gimnasio de Doraemon por inaudita bancarota"<<endl;
	delete *empleado;
	cout<< "se despidio el entrenador de zona cardio y el empleado de servicio"<<endl;

}

