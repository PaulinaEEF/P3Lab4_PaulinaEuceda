#ifndef PERSONA_H
#define PERSONA_H
#include <string.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Persona
{
	public:
		Persona();
		Persona(string nombre, string apellido, string contrasena);
		string getNombre(); 
		void setNombre(string);
		string getApellido(); 
		void setApellido(string);
		string getContrasena(); 
		void setContrasena(string);
		int getLlave(); 
		string getMensaje(int);
		void setMensaje(string);
		vector <string>& getMensajes();
		
		
		~Persona();
	protected: string nombre;
	protected: string apellido;
	protected: string contrasena;
	protected: int llave;
	protected: vector<string> mensajes;
};

#endif
