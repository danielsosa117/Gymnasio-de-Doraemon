#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

const int ano = 2018; //Constante para calcular el año de nacimiento
const int  a = 160, o = 162, i = 161, e = 130, u = 163;

//Implementacion metodos SET
void Persona :: set_Nombre(string nomb){
	Nombre = nomb;
}
void Persona :: set_Edad(int edad){
	this->edad = edad;
}

void Persona :: set_Estatura(float estatura){
	this->estatura = estatura;
}

void Persona :: set_Peso(float peso){
	this->peso = peso;
}

void Persona :: set_Genero(string genero){
	this->genero = genero;
}

void Persona :: set_identidad(int edad, int numero){
	if(edad < 18)
		tarjeta_identidad = numero;
	else if(edad>=18)
		cedula = numero;
}

//Implementacion metodos GET
string Persona::get_Nombre(){
	return Nombre;
}
int Persona :: get_Edad(){
	return edad;
}

float Persona :: get_Estatura(){
	return estatura;
}

float Persona :: get_Peso(){
	return peso;
}

string Persona :: get_Genero(){
	return genero;
}

int Persona :: get_identidad(int edad, int numero){
	if(edad < 18)
		return tarjeta_identidad;
	else if(edad>=18)
		return cedula;
}


//Implementacion metodos propios
void Persona :: calcularNacimiento(){
	cout << "El año de su nacimiento es: %d" << get_Edad() - ano << endl;
}

void Persona :: dieta(){
	if(get_Peso() > get_Estatura()){
		cout << "Debe hacer dieta" << endl;
	}
	else if(get_Peso() < get_Estatura()){
		cout << "Debe subir de peso" << endl;
	}
	else{
		cout << "Se encuentra estable segun su peso y estatura" << endl;
	}	
}

//Implementacion de los contructores

//Constructor por defecto
Persona :: Persona(){
	cout << "Se ha creado una nueva persona (por defecto)" << endl;
	set_Nombre("PEPITO");
	set_Edad(666);
	set_Genero("Indefinido");
	set_identidad(18,00000000);
}

//Constructor con datos
Persona :: Persona(string nombre, int edad, string gen, int iden){
	cout << "Se ha creado una nueva persona (con datos)" << endl;
	set_Nombre(nombre);
	set_Edad(edad);
	set_Genero(gen);
	set_identidad(edad,iden);
}

//Implementacion del destructor
Persona :: ~Persona(){
	cout << "Esta persona se ha muerto" << endl;
}

