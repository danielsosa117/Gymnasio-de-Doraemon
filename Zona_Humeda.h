#ifndef ZONAHUMEDA_H
#define ZONAHUMEDA_H

#include "Empleado.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const int MAXH = 4;

class ZonaHumeda{

private:

	string estadoHum;
	int capMaxHum;
	int numPersonasHum;
	Empleado *empleado[MAXH];
	int cont;

public:

	void set_est_Hum(int estado);
	void set_CapMaximaHum(int capMaxima);
	void set_AgrPersonaHum(int numero);
	void set_EliPersonaHum(int numero);

	string get_est_Hum();
	int get_CapMaximaHum();
	int get_PersonasHum();

	void contratar_empleado();
	void mostrar_datos_empleado();

	ZonaHumeda();
	ZonaHumeda(int estado, int car);
	~ZonaHumeda();
	
};

#endif