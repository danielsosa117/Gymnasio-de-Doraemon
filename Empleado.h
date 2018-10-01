#ifndef Empleado_h
#define Empleado_h

#include <string>
#include "Persona.h"
#include <iostream> 
using namespace std;

/*
        _____GIMNACIO DE DORAEMON_______
  
Nombres: Daniel Sosa
         Juan Sebastian Reyes
         Carlos Andres Angel 
Fecha:  Septiembre 15 de 2018
Descripción General: Abstraccion de lo empleados de una empresa, en este caso e particular 
                     el gimnacio de doraemon

*/

class Empleado : public Persona{
	
	//Declaracion de los atributos de la clase
   private:
    	string cargo;
	    int codigo;
        int salario;
		
	//Declaracion de los métodos de la clase		
   public:
    	void set_Cargo(string);
    	void set_Codigo(int);
    	void set_Salario(int);
    	
    	string get_Cargo();
    	int get_Codigo();
    	int get_Salario();
    	
    	// metodos secundarios
    	void iniciar_horario();
    	void terminar_horario(int horas);
    	void pedir_permiso(int horas);
    	void entrar_comer();
    	void salir_comer();
    	void mostrar_datos();
    	
		//constructores
		
		Empleado();
		Empleado(string cargo, int codigo,int salario);
		
		//destructor
		
		~Empleado();
};

#endif
