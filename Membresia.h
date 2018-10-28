#ifndef MEMBRESIA_H
#define MEMBRESIA_H

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

class Membresia{
	
	//Declaracion de los atributos de la clase
   private:
    	string membresia;
	    int costo;
        int codigoM;
		
	//Declaracion de los métodos de la clase		
   public:
    	void setMembresia(int);
    	void setCosto(int);
    	void setCodigoM(int);
    	
    	string getMembresia();
    	int getCosto();
    	int getCodigoM();
        void mostrar_datos();
    	
		//constructores
		
		Membresia();
		Membresia(int membresia, int costo,int codigo);
		
		//destructor
		
		~Membresia();
};

#endif
