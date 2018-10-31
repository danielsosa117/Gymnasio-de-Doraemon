#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Persona.h"
#include "Membresia.h"
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

class Cliente : public Persona{

	//Declaracion de los atributos de la clase
   private:
    	Membresia *membresia;
	    int capital;
        int codigo;

	//Declaracion de los métodos de la clase
   public:
    	void setMembresia(int);
    	void setCapital(int);
    	void setCodigo(int);

    	string getMembresia();
    	int getCapital();
    	int getCodigo();
      void mostrardatos();

		Cliente();
		Cliente(int capital, int codigo, int membresia, int codigoM, string nombre, int edad, string gen, int iden);

		//destructor

		~Cliente();
};

#endif
