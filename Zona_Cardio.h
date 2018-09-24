#ifndef ZONACARDIO_H
#define ZONACARDIO_H

#include "Empleado.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class ZonaCardio{

private:

	string estadoCar;
	int capMaxCar;
	int numPersonasCar;
	Empleado *entrenador_cardio;
	Empleado *empleado_servicio;

public:

	void set_est_Car(int estado);
	void set_CapMaximaCar(int capMaxima);
	void set_AgrPersonaCar(int numero);
	void set_EliPersonaCar(int numero);

	string get_est_Car();
	int get_CapMaximaCar();
	int get_PersonasCar();

	void contratar_empleado(string cargo);

	ZonaCardio();
	ZonaCardio(int estado, int car);
	~ZonaCardio();
	
};

#endif