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
		string seguro;
		int horas_laboradas;
		int subsidio;
		
	//Declaracion de los métodos de la clase		
   public:
    	void set_Cargo(string);
    	void set_Codigo(int);
    	void set_Salario(int);
    	void set_Seguro(string);
    	void set_Horas_laboradas(int);
    	void set_Subsidio(int);
    	
    	string get_Cargo();
    	int get_Codigo();
    	int get_Salario();
    	string get_Seguro();
    	int get_Horas_laboradas();
    	int get_Subsidio();
    	
    	// metodos secundarios
    	void iniciar_horario();
    	void terminar_horario(int horas);
    	void pedir_permiso(int horas);
    	void entrar_comer();
    	void salir_comer();
    	void mostrar_datos();
    	
		//constructores
		
		Empleado();
		Empleado(string cargo, int codigo,int salario, string seguro, int subsidio);
		
		//destructor
		
		~Empleado();
};

#endif
