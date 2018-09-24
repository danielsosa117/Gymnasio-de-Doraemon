#ifndef ZONAPESAS_H
#define ZONAPESAS_H

#include "Empleado.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class ZonaPesas{

private:

	string estadoPes;
	int capMaxPes;
	int numPersonasPes;
	Empleado *entrenador_pesas;
	Empleado *empleado_servicio;

public:

	void set_est_Pes(int estado);
	void set_CapMaximaPes(int capMaxima);
	void set_AgrPersonaPes(int numero);
	void set_EliPersonaPes(int numero);

	string get_est_Pes();
	int get_CapMaximaPes();
	int get_PersonasPes();

	void contratar_empleado(string cargo);

	ZonaPesas();
	ZonaPesas(int estado, int rec);
	~ZonaPesas();
	
};

#endif