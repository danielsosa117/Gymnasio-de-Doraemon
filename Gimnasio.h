#ifndef Gimnasio_h
#define Gimnasio_h

#include "Recepcion.h"
#include "Zona_Pesas.h"
#include "Zona_Cardio.h"
#include "Zona_Humeda.h"
#include "BasesDatos.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
using std::cout;
using std::ostream;


class Gimnasio{ 

	friend ostream &operator<<(ostream &,const Gimnasio *);

	private:

		string estadoGym;
		int capMaxGym;
		int numPersonasGym;
		Recepcion *recepcion;
		ZonaPesas *zonaPesas;
		ZonaCardio *zonaCardio;
		ZonaHumeda *zonaHumeda;

	public:

		virtual void setEstadoGym(int estado); 
		void setEstadoZonas(string zonas, int estado);
		void setCapacidadMaximaGym(int num);
		void setCapacidadMaxima(string zona, int capMax);
		void setAgregarPersonasGym(int num);
		void setEliminarPersonasGym(int num);

		virtual string getEstadoGym();
		string getEstadoZonas(string);
		int getCapacidadMaximaGym();
		int getCapacidadMaxima(string zona);
		virtual int getPersonasGym();

		void mostrarEstadoGeneral();
		void mostrarDatosEmpleadosZona(string zona);
		void contratarEmpleadoZona(string zona);
		void despedirEmpleadoZona(string zona);
		
		//Constructores
		Gimnasio();
		Gimnasio(int rec,int pes,int car, int hum, int gym);
		//Destructores
		~Gimnasio();
};

#endif
