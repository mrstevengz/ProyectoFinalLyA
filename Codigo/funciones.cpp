#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>

Usuario usuariodatos[MAX_REG];
Usuario regpagos[MAX_REG];
using namespace std;
int pos = 0;
int obtPos(int id);
void agregarUsuario();
void registroDatos();
void showData(Usuario &d);
void editar(Usuario *p, int id);
void searchUser();
void eliminar(int id);
void editarDatos();
void eliminarDatos();
void mostrarDatos();



void showPayments(Usuario &p);
void registroPagos();
void agregarPago();
void eliminarPagos();
Usuario search(int id);

//Funcion de registro de datos

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
    cout << "Cedula: " << d.cedula << endl;
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

    cout << "Por favor, introduce tu numero de cedula: ";
    cin >> usuariodatos.cedula;

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
    cout << "Introduce el numero de casa del residente: ";
    cin >> id;
    Usuario d = search(id);
    showData(d);
    
}

void eliminar(int id)
{
    int posi = obtPos(id);
    for (int i = posi; i < pos - 1; i++)
    {
        usuariodatos[i] = usuariodatos[i + 1];
    }
    pos--;
}

void eliminarDatos(){
    int id;
    cout << "ID de la persona a eliminar: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "Registro no encontrado\n";
        return;
    }
    eliminar(id);
    cout << "Registro eliminado...\n";
}

void editar(Usuario *p, int id){
    int posi = obtPos(id);
    strcpy(usuariodatos[posi].nombre, p->nombre);
    strcpy(usuariodatos[posi].apellidos, p->apellidos);
    strcpy(usuariodatos[posi].telefono, p->telefono);
    strcpy(usuariodatos[posi].cedula, p->cedula);
}

void editarDatos(){
    int id;
    cout << "ID de la persona a editar: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "Registro no encontrado\n";
        return;
    }
    Usuario p = search(id);
    cout << "Datos actuales:\n";
    showData(p);
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(p.nombre, 50);
    cout << "Apellidos: ";
    cin.getline(p.apellidos, 50);
    cout << "Telefono: ";
    cin.getline(p.telefono, 20);
    cout << "Cedula: ";
    cin.getline(p.cedula, 20);
    editar(&p, id);
    cout << "Registro actualizado...\n";

}
//*Funcion de registro de pagos

void agregarPago(Usuario *p)
{
    regpagos[pos] = *p;
    pos ++;
}

void registroPagos(){
    Usuario regpagos;

    cout << "Por favor, introduce el numero de casa del residente: ";
    cin >> regpagos.id;

    cout << "Por favor, introduce el pago del residente: ";
    scanf(" %[^\n]", regpagos.pagos);

    cout << "Por favor, introduce la fecha limite para pagar: ";
    scanf(" %[^\n]", regpagos.fecha);

    agregarPago(&regpagos);
    cout << "\n Pago registrado \n";

}

Usuario searchPaym(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (regpagos[i].id == id)
        {
            return regpagos[i];
        }
    }
}

void searchPayment(){
    int id;
    cout << "Introduce el numero de casa del residente: ";
    cin >> id;
    Usuario p = searchPaym(id);
    cout << "ID: " << p.id << endl;
    cout << "Pago pendiente: " << p.pagos << endl;
    cout << "Fecha limite: " << p.fecha << endl;
    cout << "\n";
}

void eliminar(int id)
{
    int posi = obtPos(id);
    for (int i = posi; i < pos - 1; i++)
    {
        regpagos[i] = regpagos[i + 1];
    }
    pos--;
}
void eliminarPagos(){
    int id;
    cout << "Elimina un pago\n";
    cout << "ID: ";
    cin >> id;
    eliminar(id);
}

int obtPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (regpagos[i].id == id)
        {
            return i;
        }
    }
    return -1;
}