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

void encriptarYDes(string, int, bool);

string mensajeEN; //mensaje encriptado
int main(int argc, char** argv) {
	vector<Persona> vectPersonas;
	
	vectPersonas.push_back(Persona("Paulina", "Euceda", "123"));
	vectPersonas[0].setMensaje("holaquestapasandoaquicon");
	vectPersonas.push_back(Persona("Juan", "Bados", "123"));
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
					
					
					while(salidaDelLogin){
						
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
								cout<<endl << "--Listado de Personas-- "<<endl;
								for(int i=0; i<vectPersonas.size(); i++){
									int ordenListado = i+1;
									cout << ordenListado << ") " << vectPersonas[i].getNombre()<<endl;
									
								}
								int posReceptorMensaje;
								cout << "Enviar mensaje a: ";
								cin >> posReceptorMensaje;
								posReceptorMensaje--;
								cout<<endl;
								
								string mensajeSE;//mensaje sin encriptar
								cout << "Escriba el mensaje que quiere enviar: ";
								cin >> mensajeSE;
								
								
								
								vectPersonas[posReceptorMensaje].setMensaje(mensajeSE);
								//vectPersonas[posReceptorMensaje].getMensajes().push_back(mensajeSE);//este no funciona
								cout << vectPersonas[posReceptorMensaje].getMensajes().size();
								
								cout<<endl<<endl;
								break;
							}
							case 2:{
								cout << "---Lista de mensajes---"<<endl;
								//ver mensajes
								
								int llave = vectPersonas[posicionDelUsuarioIngresado].getLlave();
								for(int i=0; i<vectPersonas[posicionDelUsuarioIngresado].getMensajes().size(); i++){
									
									string cadena = vectPersonas[posicionDelUsuarioIngresado].getMensaje(i);
									int ordenListado = i+1;
									
									encriptarYDes(cadena, llave, true);
									cout << ordenListado << ") " << mensajeEN <<endl;
									mensajeEN = "";
									
								}
								int mensajeSeleccionado;
								cout << "Seleccione el mensaje: ";
								cin >> mensajeSeleccionado;
								mensajeSeleccionado--;
								cout<<endl;
								
								llave = vectPersonas[posicionDelUsuarioIngresado].getLlave();//se me fue el tempo :p
								string cadena = vectPersonas[posicionDelUsuarioIngresado].getMensaje(mensajeSeleccionado);
								encriptarYDes(cadena, llave, false);
								cout << "[Mensaje] " << mensajeEN;
								mensajeEN = "";
								cout << endl<<endl;
								break;
							}
							case 3:{
								//ver llave
								cout<<"Su llave es: " << vectPersonas[posicionDelUsuarioIngresado].getLlave()<< endl;
								cout << endl;
								break;
							}
							default:
								salidaDelLogin = false;
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


void encriptarYDes(string cadena, int llave, bool direccion){
	bool direccionGen = direccion;
	if(llave > 0){
		for (int a = 0; a < cadena.size(); a+=llave){
			for (int b = a; b < llave; b++){
			
				if(direccion == true){
					char caracter_pos = cadena[b];
					
					int valor_ascci = caracter_pos;
					valor_ascci+=llave;
					char caracter = (char) valor_ascci;
					mensajeEN+=caracter;
					
				}else{
					
					char caracter_pos = cadena[b];
					
					int valor_ascci = caracter_pos;
					valor_ascci-=llave;
					char caracter = (char) valor_ascci;
					
					mensajeEN+=caracter+"";
					
				}
			}
			if(direccion == true){
				direccion = false;
			}else{
				direccion = true;
			}
		
		}
		llave--;
		encriptarYDes(cadena, llave, direccionGen);
	}

}
	
	
	
	
	
	
	
	







