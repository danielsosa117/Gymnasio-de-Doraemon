#ifndef Gimnasio_h
#define Gimnasio_h

#include "Recepcion.h"
#include "Zona_Pesas.h"
#include "Zona_Cardio.h"
#include "Zona_Humeda.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
class Gimnasio{ 

	private:

		string estadoGym;
		int capMaxGym;
		int numPersonasGym;
		Recepcion *recepcion;
		ZonaPesas *zonapesas;
		ZonaCardio *zonacardio;
		ZonaHumeda *zonahumeda;

	public:

		virtual void set_estGym(int estado);
		void set_estZonas(string zonas, int estado);
		void set_CapMaximaGym(int num);
		void set_CapMaxima(string zona, int capMax);
		void set_AgrPersonasGym(int num);
		void set_EliPersonasGym(int num);

		virtual string get_est_Gym();
		int get_CapMaximaGym();
		int get_CapMaxima(string zona);
		virtual int get_PersonasGym();

		void mostrar_estado_general();
		void mostrar_datos_empleados_zona(string zona);
		void contratar_empleado_zona(string zona);
		void despedir_empleado_zona(string zona);
		
		//Constructores
		Gimnasio();
		Gimnasio(int rec,int pes,int car, int hum, int gym);
		//Destructores
		~Gimnasio();
};

#endif
