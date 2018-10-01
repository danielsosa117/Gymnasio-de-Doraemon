#ifndef BASESDATOS_H
#define BASESDATOS_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Archivos {
	private:
		string archivo;
		vector< vector<string> > datos;

	public:

		Archivos();
		Archivos(string archivo);

		void getDatos();
		void setDatos();

		void getArchivo(string archivo);
		string setArchivo();

		~Archivos();

};

#endif