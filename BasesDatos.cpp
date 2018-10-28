#include <iostream>
#include <vector>
#include <fstream>
#include "BasesDatos.h"
#include "Gimnasio.h"
using namespace std;

Archivos::Archivos(){
	archivo = "Personas.txt"; 
}

Archivos::Archivos(string archivoTexto){
	archivo = archivoTexto;
}

void Archivos::setDatos(){
	ifstream baseDatos(archivo.c_str());
	string linea, dato;
	vector<string> facts;
	while(getline(baseDatos,linea)){
		for (int i = 0; i < linea.size(); i++){
			if (linea[i] != '-')
				dato.push_back(linea[i]);
			else {
				facts.push_back(dato);
				dato.clear();
			}

			if (i == linea.size() - 1){
				facts.push_back(dato);
				datos.push_back(facts);
			}
		}
		dato.clear();
		facts.clear();
	}
	baseDatos.close(); 
}

vector< vector<string> > Archivos::getDatos(){

	return datos;
}

void Archivos::setArchivo(string archivoTexto){
	archivo = archivoTexto;
}

string Archivos::getArchivo(){
	return archivo;
}

Archivos::~Archivos(){
}
