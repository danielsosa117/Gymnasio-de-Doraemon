#ifndef Recepcion_h
#define Recepcion_h

#include "Empleado.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const int MAX = 3;

class Recepcion{

private:

	string estadoRec;
	int capMaxRec;
	int numPersonasRec;
	Empleado *recepcionista;
	Empleado *empleado_servicio;

public:

	void set_est_Rec(int estado);
	void set_CapMaximaRec(int capMaxima);
	void set_AgrPersonaRec(int numero);
	void set_EliPersonaRec(int numero);

	string get_est_Rec();
	int get_CapMaximaRec();
	int get_PersonasRec();

	void contratar_empleado(string cargo);

	Recepcion();
	Recepcion(int estado, int rec);
	~Recepcion();
	
};

#endif