#ifndef BASESDATOS_H
#define BASESDATOS_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Gimnasio.h"

using namespace std;

class Archivos {

	private:
		string archivo;
		vector< vector<string> > datos;

	public:

		Archivos();
		Archivos(string archivo);

		vector< vector<string> > getDatos();
		void setDatos();

		void setArchivo(string archivo);
		string getArchivo();

		~Archivos();

};

#endif