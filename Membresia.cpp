/*
	IMPLEMENTACION DE LOS ATRIBUTOS
*/

#include <string>
#include "Membresia.h"
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
	
void Membresia::setMembresia(int mem){
	if(mem == 1)
		membresia = "General";
	else if(mem == 2)
		membresia = "Especial";
	else if(mem == 3)
		membresia = "Premium";
	else if(mem == 4)
		membresia = "Platino";
}//metodo para la modificacion de la variable privada cargo

void Membresia::setCosto(int costo){
	this->costo=costo;
}//metodo para la modificacion de la variable privada codigo

void Membresia::setCodigoM(int codigoM){
	this->codigoM = codigoM;
}//metodo para la modificacion de la variable privada salario

////////////////MÉTODOS GET////////////////


//Los métodos get se usan para recuperar, obtener o leer el valor para cada una de los aributos 


string Membresia::getMembresia(){
	return membresia;
}

int Membresia::getCosto(){
	return costo;
}

int Membresia::getCodigoM(){
	return codigoM;
}


////////////////MÉTODOS SET////////////////

void Membresia::mostrar_datos(){
	cout << "Membresia: " << getMembresia() <<endl;
	cout << "Costo: " << getCosto() <<endl;
	cout << "Codigo: " << getCodigoM() <<endl;
	
}

////////////////Constructores////////////////

/*
Descripcion: Es el constructor por defecto
Entradas: Ninguna
Salida: Ninguna 
Precondiciones: Ninguna 
Poscondiciones: Ninguna
*/

Membresia::Membresia(){
	cout <<endl;
	cout << "**** Contratacion Membresia (Por defecto)" <<endl;
	setMembresia(1);
	setCosto(50000);
	setCodigoM(000000);
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

Membresia::Membresia(int membresia, int costo,int codigoM){
	cout <<endl;
	cout << "**** Contratacion Membresia" <<endl;
	setMembresia(membresia);
	setCosto(costo);
	setCodigoM(codigoM);
}

////////////////Destructor////////////////

/*
Descripcion: Es destructor
Entradas: Ninguna
Salida: Ninguna
Precondiciones: Ninguna 
Poscondiciones: Ninguna
*/

Membresia::~Membresia(){
	cout <<endl;	
	cout << "Aabas de destruir una membresia "<<endl;
}
