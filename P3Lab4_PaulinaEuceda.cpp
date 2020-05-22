#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "Persona.h"
#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

string encriptarYDes(int);

int main(int argc, char** argv) {
	vector<Persona> vectPersonas;
	
	vectPersonas.push_back(Persona("Paulina", "Euceda", "123"));
	vectPersonas[0].setMensaje("este mensaje es de prueba");
//    vectPersonas.push_back(10); 
//    cout<<vectPersonas[0];

	int posicionDelUsuarioIngresado;
	
	bool salidaDelMenu = true;
	
	while(salidaDelMenu){
		int x,y;
		cout<<"1) Registrarse" << endl 
			<<"2) Ingresar "<<endl
			<<"3) Salir "<<endl
			<<"Opcion: ";
		
		int opcionDelMenu;
		cin >> opcionDelMenu;
		cout << endl;
		switch(opcionDelMenu) {
			case 1:{
				cout<< "---Registro---"<<endl;
				//se registra al usuario
				string nombreRegistro, apellidoRegistro, contraRegistro;
				
				cout<<"Escriba su nombre: ";
				cin >> nombreRegistro;
				
				cout<<"Escriba su apellido: ";
				cin >> apellidoRegistro;
				
				cout<<"Escriba la contraseña: ";
				cin >> contraRegistro;
				
				Persona* objPersona =NULL;
				//objPersona = new Persona(nombreRegistro, apellidoRegistro, contraRegistro);
				vectPersonas.push_back(Persona(nombreRegistro, apellidoRegistro, contraRegistro));
				
				cout << "Registrado con exito"<<endl;
				cout << endl;
				
				cout << "Su nombre es: "<<vectPersonas[vectPersonas.size()-1].getNombre()<<endl;
				cout << "Su apellido es: "<<vectPersonas[vectPersonas.size()-1].getApellido()<<endl;
				cout << "Su contraseña es: "<<vectPersonas[vectPersonas.size()-1].getContrasena()<<endl;
				
				cout << endl;
				
				break;
			}
			case 2:{
				//pide los tamanos para mandar al metodo con matriz definida
				cout<< "---Ingreso---"<<endl;
				
				string nombreIngreso, contraIngreso;
				
				cout<<"Escriba su nombre: ";
				cin >> nombreIngreso;
				
				cout<<"Escriba la contraseña: ";
				cin >> contraIngreso;
				
				bool loginCorrecto = false;
				for(int i=0; i<vectPersonas.size(); i++){
					if(nombreIngreso==vectPersonas[i].getNombre() && contraIngreso==vectPersonas[i].getContrasena()){
						loginCorrecto = true;
						posicionDelUsuarioIngresado = i;
						break;
					}
				}
				
				if(loginCorrecto == true){
					bool salidaDelLogin = true;
					
					cout<< "Se inició sesión con éxito"<<endl<<endl;
					
					
					while(salidaDelMenu){
						
						cout<<"1) Enviar mensaje" << endl 
							<<"2) Ver mensajes "<<endl
							<<"3) Ver mi llave "<<endl
							<<"4) Salir "<<endl
							<<"Opcion: ";
						
						int opcionDeMensajeria;
						cin >>  opcionDeMensajeria;
						switch(opcionDeMensajeria) {
							case 1:{
								//enviar mensaje
								cout<<endl << "--Enviar mensaje a: "<<endl;
								for(int i=0; i<vectPersonas.size(); i++){
									int ordenListado = i+1;
									cout << ordenListado << ") " << vectPersonas[i].getNombre()<<endl;
									
								}
								
								
								break;
							}
							case 2:{
								cout << "---Lista de mensajes---"<<endl;
								//ver mensajes
								for(int i=0; i<vectPersonas[posicionDelUsuarioIngresado].getMensajes().size(); i++){
									int ordenListado = i+1;
									cout << ordenListado << ") De: " << vectPersonas[posicionDelUsuarioIngresado].getMensaje(i)<<endl;
									
								}
								cout << endl;
								break;
							}
							case 3:{
								//ver llave
								cout<<"Su llave es: " << vectPersonas[posicionDelUsuarioIngresado].getLlave()<< endl;
								cout << endl;
								break;
							}
							default:
								salidaDelMenu = false;
								cout<< "Cerrado de Sesion correcto. Adios"<<endl<<endl;
								break;
						}
					}
					
					
					
				}else{
					cout<< "Usuario o contraseña incorrecta"<<endl<<endl;
				}
				
				break;
			}
			default:
				salidaDelMenu = false;
				break;
		}
	}
	return 0;
}
string encriptarYDes(int llave){
	
}






