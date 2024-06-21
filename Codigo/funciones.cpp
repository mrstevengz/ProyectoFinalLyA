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
void registroPago();
void agregarPago(Usuario &d);
void multa();

void registroPago(){
    int id;
    cout << "Introduce el ID del residente: ";
    cin >> id;
    Usuario d = search(id);
    cout << "Pago de la cuota mensual, el pago son 100C$" <<  endl;
    cout << "¿Usted ya pago?(si/no): ";
    scanf(" %[^\n]", d.pago);
    if (string(d.pago) == "si")
    {
        cout << "¿Cuantos cordobas ha pagado?" << endl;
        cin >> d.cantidad;
        if (d.cantidad ==100)
        {
            cout << "Usted ya ha pagado la cuota mensual" << endl;
        }
        else
        {
            cout << "Usted no ha pagado lo suficiente, el pago total son 100C$, porfavor pague en la caseta de seguridad." << endl;
        }
        
        
    }
    else
    {
        cout << "Usted no ha pagado, porfavor vaya a pagar en la caseta de seguridad." << endl;
    }
    agregarPago(d);
    cout << endl;



    
    
}


    void multa(){
    for (int i = 0; i < pos; i++)
    {
        if (std::string(usuariodatos[i].pago) != "si")
        {
            cout << "El usuario con ID " << usuariodatos[i].id << " tiene una multa por no pagar de 500C$." << endl;
        }
    }
cout << endl;
}

    



void agregarPago(Usuario &d){
    for (int i = 0; i < pos; i++)
    {
        if (usuariodatos[i].id == d.id)
        {
            usuariodatos[i] = d;
        }
    }
}



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
    cout << "Pago: " << d.pago << endl;
    cout << "Cantidad: " << d.cantidad << endl;
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
