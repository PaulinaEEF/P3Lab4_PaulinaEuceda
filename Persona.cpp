#include "Persona.h"
#include <string>
#include <iostream>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <ctime>

string nombre;
string apellido;
string contrasena;
int llave;
vector<string> vectMensajes;

using std::cout;
using std::endl;
using std::string;

Persona::Persona()
{	
}

Persona::Persona(string nombre, string apellido, string contrasena)
{	
	this->nombre = nombre;
	this->apellido = apellido;
	this->contrasena = contrasena;
	this->llave = 1+rand() % 15;
	
}

string Persona::getNombre(){
	return nombre;
}

void Persona::setNombre(string nombre){
	this->nombre=nombre;
}

string Persona::getApellido(){
	return apellido;
}

void Persona::setApellido(string apellido){
	this->apellido=apellido;
}

string Persona::getContrasena(){
	return contrasena;
}

void Persona::setContrasena(string contrasena){
	this->contrasena=contrasena;
}

int Persona::getLlave(){
	return llave;
}


string Persona::getMensaje(int posicionMensaje){
	return vectMensajes[posicionMensaje];
}

void Persona::setMensaje(string mensaje){
	vectMensajes.push_back(mensaje); 
}

vector <string>& Persona::getMensajes(){
	
	return vectMensajes;
}



Persona::~Persona()
{
}
