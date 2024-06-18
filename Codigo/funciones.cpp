#include <iostream>
#include <string>
#include "variables.h"

Usuario usuariodatos[MAX_REG];
using namespace std;
int pos = 0;
int obtPos(int id);
void agregarUsuario();
void registroDatos();
void mostrarDatos();
void showData(Usuario &d);
void searchUser();
Usuario search(int id);

void agregarUsuario(Usuario *d)
{
    usuariodatos[pos] = *d;
    pos ++;
}

void showData(Usuario &d){
    cout << "ID: " << d.id << endl;
    cout << "Nombre: " << d.nombre << endl;
    cout << "Apellidos: " << d.apellidos << endl;
    cout << "Telefono: " << d.telefono << endl;
    cout << "\n";
}

void registroDatos(){
    Usuario usuariodatos;

    cout << "Por favor, introduce tu nombre: ";
    scanf(" %[^\n]", usuariodatos.nombre);

    cout << "Por favor, introduce tus apellidos: ";
    scanf(" %[^\n]", usuariodatos.apellidos);

    cout << "Por favor, introduce tu numero de telefono: ";
    scanf(" %[^\n]", usuariodatos.telefono);

    cout << "Por favor, introduce tu numero de casa: ";
    cin >> usuariodatos.id;

    agregarUsuario(&usuariodatos);
    cout << "\n Informacion Introducida \n";
}

void mostrarDatos(){
    for (int i = 0; i < pos; i++)
    {
       showData(usuariodatos[i]);
    }
    cout << "\n";
}

Usuario search(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (usuariodatos[i].id == id)
        {
            return usuariodatos[i];
        }
    }
}

void searchUser(){
    int id;
    cout << "Introduce el ID del residente: ";
    cin >> id;
    Usuario d = search(id);
    showData(d);
    
}
