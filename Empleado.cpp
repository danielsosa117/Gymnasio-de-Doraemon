/*
	IMPLEMENTACION DE LOS ATRIBUTOS
*/

#include <string>
#include "Empleado.h"
#include <iostream>
using namespace std;

/*
Nombres: Juan Sebastian Reyes Layton
		 Daniel Sosa
		 Carlos Andres Angel
Fecha:  Septiembre 15 de 2018
Descripci�n General: En este archivo estan todas la implentaciones de los m�todos
declarados en "Empleado.h".  Cada uno de los archivos se va a explicar por separado.
*/

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

////////////////M�TODOS SET////////////////

void Empleado::set_Cargo(string cargo){
	this->cargo=cargo;
}//metodo para la modificacion de la variable privada cargo

void Empleado::set_Codigo(int codigo){
	this->codigo=codigo;
}//metodo para la modificacion de la variable privada codigo

void Empleado::set_Salario(int salario){
	this->salario = salario;
}//metodo para la modificacion de la variable privada salario

////////////////M�TODOS GET////////////////


//Los m�todos get se usan para recuperar, obtener o leer el valor para cada una de los aributos


string Empleado::get_Cargo(){
	return cargo;
}

int Empleado::get_Codigo(){
	return codigo;
}

int Empleado::get_Salario(){
	return salario;
}


////////////////M�TODOS SET////////////////


/*
Los m�todos set se usan para modificar, cambiar, asignar un valor para cada una de los aributos
*/


void Empleado::iniciar_horario(){
	cout << "Bienvenido al local" << get_Cargo() << endl;
}

void Empleado::terminar_horario(int horas){
	cout << "Hasta luego" << get_Cargo() << endl;
}

void Empleado::pedir_permiso(int horas){
	cout << "Has pedido permiso se�@r" << get_Cargo()  << endl;
}

void Empleado::entrar_comer(){
	cout << "Bienvenido al restaurante" << get_Cargo() << endl;
}

void Empleado::salir_comer(){
	cout << "Hasta luego se�@r" << get_Cargo() << endl;
}

void Empleado::mostrar_datos(){
	cout << "Cargo: " << get_Cargo() <<endl;
	cout << "C"<<(char)o<<"digo: " << get_Codigo() <<endl;
	cout << "Salario: " << get_Salario() <<endl;
	cout << "Nombre: " << get_Nombre() <<endl;
	cout << "Genero: " << get_Genero() <<endl;
	cout << "Edad: " << get_Edad() <<endl;
	cout << "identificacion: " << get_identidad(get_Edad()) <<endl;
}

////////////////Constructores////////////////

/*
Descripcion: Es el constructor por defecto
Entradas: Ninguna
Salida: Ninguna
Precondiciones: Ninguna
Poscondiciones: Ninguna
*/

Empleado::Empleado(){
	cout <<endl;
	cout << "**** Contratacion empleado (Por defecto)" <<endl;
	set_Cargo("Empleado de servicio");
	set_Codigo(3236301);
	set_Salario(800000);
}

/*
Descripcion: Es el constructor
Entradas:
	cargo: Cargo del Usuario
	codigo: Codigo del Usuario
	salario: Salario del Usuario
	seguro: Seguro del Usuario
	subsidio: Subsidio del Usuario
Salida: Ninguna  // No es necesario, los constructores no tienen salida
Precondiciones: Ninguna
Poscondiciones: Ninguna
*/

Empleado::Empleado(string cargo, int codigo,int salario, string nombre, int edad, string gen, int iden){
	cout <<endl;
	cout << "**** Contratacion empleado" <<endl;
	set_Cargo(cargo);
	set_Codigo(codigo);
	set_Salario(salario);
	set_Nombre(nombre);
	set_Edad(edad);
	set_Genero(gen);
	set_identidad(edad,iden);
}

////////////////Destructor////////////////

/*
Descripcion: Es destructor
Entradas: Ninguna
Salida: Ninguna
Precondiciones: Ninguna
Poscondiciones: Ninguna
*/

Empleado::~Empleado(){
	cout <<endl;
	cout << "Aabas de despedir a un empleado "<<endl;
}
