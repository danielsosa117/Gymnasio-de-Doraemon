#ifndef ZONACARDIO_H
#define ZONACARDIO_H

#include "Empleado.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const int MAXC = 4;

class ZonaCardio{

private:

	string estadoCar;
	int capMaxCar;
	int numPersonasCar;
	Empleado *empleado[MAXC];
	int cont;

public:

	void set_est_Car(int estado);
	void set_CapMaximaCar(int capMaxima);
	void set_AgrPersonaCar(int numero);
	void set_EliPersonaCar(int numero);

	string get_est_Car();
	int get_CapMaximaCar();
	int get_PersonasCar();

	void contratar_empleado();
	void mostrar_datos_empleado();
	void despedir_empleado();

	ZonaCardio();
	ZonaCardio(int estado, int car);
	~ZonaCardio();
	
};

#endif