/*
	IMPLEMENTACION DE LOS ATRIBUTOS
*/

#include <string>
#include "Membresia.h"
#include "Cliente.h"
#include <iostream> 
using namespace std;

/*
Nombres: Juan Sebastian Reyes Layton
		 Daniel Sosa
		 Carlos Andres Angel
Fecha:  Septiembre 15 de 2018
Descripción General: En este archivo estan todas la implentaciones de los métodos 
declarados en "Empleado.h".  Cada uno de los archivos se va a explicar por separado.
*/

const int  a = 160, o = 162, i = 161, e = 130, u = 163;

////////////////MÉTODOS SET////////////////
	
void Cliente::setMembresia(int membresia){
	this->membresia->setMembresia(membresia);
}//metodo para la modificacion de la variable privada cargo

void Cliente::setCapital(int capital){
	this->capital=capital;
}//metodo para la modificacion de la variable privada codigo

void Cliente::setCodigo(int codigo){
	this->codigo = codigo;
}//metodo para la modificacion de la variable privada salario

////////////////MÉTODOS GET////////////////


//Los métodos get se usan para recuperar, obtener o leer el valor para cada una de los aributos 


string Cliente::getMembresia(){
	return membresia->getMembresia();
}

int Cliente::getCodigo(){
	return codigo;
}

int Cliente::getCapital(){
	return capital;
}


////////////////Constructores////////////////

/*
Descripcion: Es el constructor por defecto
Entradas: Ninguna
Salida: Ninguna 
Precondiciones: Ninguna 
Poscondiciones: Ninguna
*/

Cliente::Cliente(){
	cout <<endl;
	cout << "**** Contratacion Cliente (Por defecto)" <<endl;
	setCapital(00000);
	setCodigo(00000);
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

Cliente::Cliente(int capital, int codigo, int mem, int codigoM, string nombre, int edad, string gen, int iden){
	cout <<endl;
	cout << "**** Contratacion Cliente" <<endl;
	membresia = new Membresia(mem, 50000, codigoM);
	setCapital(capital);
	setCodigo(codigo);
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

Cliente::~Cliente(){
	cout <<endl;
	delete membresia;
	cout << "Aabas de despedir a un empleado "<<endl;
}
