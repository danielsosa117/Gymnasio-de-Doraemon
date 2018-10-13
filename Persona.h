#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using namespace std;


//Declaracion de la Clase Persona.
class Persona{
	//Atributos
	private:
		string Nombre;
		int edad;
		float estatura;
		float peso;
		string genero;
		int cedula;
		int tarjeta_identidad; 
		
	//Metodos	
	public:
		//SET
		void set_Nombre(string Nombre);
		void set_Edad(int edad);
		void set_Estatura(float estatura);
		void set_Peso(float peso);
		void set_Genero(string genero);
		void set_identidad(int edad, int numero);
		
		//GET
		string get_Nombre();
		int get_Edad();
		float get_Estatura();
		float get_Peso();
		string get_Genero();
		int get_identidad(int edad);
		
		//Operaciones Adicionales
		void calcularNacimiento();
		void imprimirGenero();
		void dieta();

		
		//Constructores
		//Por defecto
		Persona();
		//Con datos
		Persona(string nombre,int e,string g, int iden);
		
		//Destructor
		~Persona();
		
};

#endif
