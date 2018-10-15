#ifndef Recepcion_h
#define Recepcion_h

#include "Empleado.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const int MAXR = 4;

class Recepcion{

private:

	string estadoRec;
	int capMaxRec;
	int numPersonasRec;
	int cont;
	Empleado *empleado[MAXR];

public:

	void set_est_Rec(int estado);
	void set_CapMaximaRec(int capMaxima);
	void set_AgrPersonaRec(int numero);
	void set_EliPersonaRec(int numero);

	string get_est_Rec();
	int get_CapMaximaRec();
	int get_PersonasRec();

	void contratar_empleado();
	void mostrar_datos_empleado();
	void despedir_empleado();

	Recepcion();
	Recepcion(int estado, int rec);
	~Recepcion();
	
};

#endif