main: Gimnasio_Doraemon.o Gimnasio.o Zona_Pesas.o Zona_Humeda.o Zona_Cardio.o Persona.o Membresia.o Empleado.o Cliente.o BasesDatos.o Recepcion.o
	g++ Gimnasio_Doraemon.o Gimnasio.o Zona_Pesas.o Zona_Humeda.o Zona_Cardio.o Persona.o Membresia.o Empleado.o Cliente.o Recepcion.o BasesDatos.o -o Gimnasio_Doraemon


Gimnasio.o: Gimnasio.cpp
	g++ Gimnasio.cpp -c

Recepcion.o: Recepcion.cpp
	g++ Recepcion.cpp -c

Zona_Pesas.o: Zona_Pesas.cpp
	g++ Zona_Pesas.cpp -c

Zona_Cardio.o: Zona_Cardio.cpp
	g++ Zona_Cardio.cpp -c

Zona_Humeda.o: Zona_Humeda.cpp
	g++ Zona_Humeda.cpp -c

BasesDatos.o: BasesDatos.cpp
	g++ BasesDatos.cpp -c

Persona.o: Persona.cpp
	g++ Persona.cpp -c

Cliente.o: Cliente.cpp
	g++ Cliente.cpp -c

Empleado.o: Empleado.cpp
	g++ Empleado.cpp -c

Membresia.o: Membresia.cpp
	g++ Membresia.cpp -c

Gimnasio_Doraemon.o: Gimnasio_Doraemon.cpp
	g++ Gimnasio_Doraemon.cpp -c

clean:
	del -f *.o
