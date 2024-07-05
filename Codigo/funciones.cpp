#include <iostream>
#include <string.h>
#include <locale.h>
#include <fstream>
#include "variables.h"
using namespace std;

PERSONA personas[MAX_REG];
int pos = 0;

// CRUD
int obtPos(int id);
void agregar(PERSONA *p);
void editar(PERSONA *p, int id);
void eliminar(int id);
PERSONA buscar(int id);
int menu();
void principal();
void pedirDatos();
void mostrarDatos();
void showData(PERSONA &p);
void buscarPorID();
void editarDatos();
void eliminarDatos();
int menu2();
int menu3();
void menupagos();
void menuprincipal();

void registroPago();
void agregarPago(PERSONA &b);
void eliminarPagos();
PERSONA BUSCAR(int id);
void buscarPago();

// Funciones para ficheros
void guardarEnFichero();
void cargarDeFichero();

void agregar(PERSONA *p)
{
    personas[pos] = *p;
    pos++;
}

PERSONA buscar(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (id == personas[i].id)
        {
            return personas[i];
        }
    }
    PERSONA p;
    return p;
}

int obtPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (personas[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void editar(PERSONA *p, int id)
{
    int posi = obtPos(id);
    strcpy(personas[posi].nombre, p->nombre);
    strcpy(personas[posi].apellidos, p->apellidos);
    strcpy(personas[posi].numeroCedula, p->numeroCedula);
    strcpy(personas[posi].numeroTelefono, p->numeroTelefono);
    strcpy(personas[posi].numeroCasa, p->numeroCasa);
}

void eliminar(int id)
{
    int posi = obtPos(id);
    for (int i = posi; i < pos - 1; i++)
    {
        personas[i] = personas[i + 1];
    }
    pos--;
}

int menu(){
    int op;
    cout << " \nBienvenido al sistema de cobro seguridad!" << endl;
    cout << "1. Menu de registro de datos\n";
    cout << "2. Menu de pagos\n";
    cout << "3. Guardar informacion\n";
    cout << "4. Salir\n";
    cout << "Digite la opcion: ";
    cin >> op;
    system("cls");
    return op;
}

int menu2()
{
    int op2;
    cout << "Menu de registro de datos\n";
    cout << "1. Agregar\n";
    cout << "2. Editar\n";
    cout << "3. Eliminar\n";
    cout << "4. Buscar\n";
    cout << "5. Mostrar todo\n";
    cout << "6. Salir\n";
    cout << "Digite la opcion: ";
    cin >> op2;
    system("cls");
    return op2;
}

int menu3(){
    int op3;
    cout << "Menu de pagos\n";
    cout << "1. Agregar Pago\n";
    cout << "2. Mostrar pagos de un residente\n";
    cout << "3. Eliminar pagos\n";
    cout << "4. Salir del menu\n";
    cout << "Digite la opcion: ";
    cin >> op3;
    system("cls");
    return op3;
}

void principal(){
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            menuprincipal();
            break;
        case 2:
            menupagos();
            break;
        case 3:
            guardarEnFichero();
            break;
        case 4:
            cout << "Saliendo del sistema\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
    } while (op != 4);
}

void menuprincipal()
{
    int op2;
    do
    {
        op2 = menu2();
        switch (op2)
        {
        case 1:
            pedirDatos();
            break;
        case 2:
            editarDatos();
            break;
        case 3:
            eliminarDatos();
            break;
        case 4:
            buscarPorID();
            break;
        case 5:
            mostrarDatos();
            break;
            break;
        case 6:
            cout << "Regresando al menu\n";
            break;
        default:
            cout << "Error // Opcion no valida\n";
            break;
        }
    } while (op2 != 6);
}

void menupagos(){
    int op3;
    do
    {
        op3 = menu3();
        switch (op3)
        {
        case 1:
            registroPago();
            break;
        case 2:
            buscarPago();
            break;
        case 3:
            eliminarPagos();
            break;
        case 4:
            cout << "Regresando al menu\n";
            break;
        default:
            cout << "Error // Opcion no valida\n";
            break;
        }
    } while (op3 != 4);

}

void pedirDatos()
{
    PERSONA persona;
    cout << "Datos de la persona\n";
    cout << "ID: ";
    scanf("%d", &persona.id);
    if (obtPos(persona.id) != -1)
    {
        cout << "Ya existe un registro con este ID\n";
        return;
    }
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(persona.nombre, 50);
    cout << "Apellidos: ";
    cin.getline(persona.apellidos, 50);
    cout << "Numero de cedula: ";
    cin.getline(persona.numeroCedula, 20);
    cout << "Numero de telefono: ";
    cin.getline(persona.numeroTelefono, 20);
    cout << "Numero de casa: ";
    cin.getline(persona.numeroCasa, 10);
    agregar(&persona);
    cout << "Registro agregado...\n";
}

void mostrarDatos()
{
    if (pos == 0)
    {
        cout << "No hay registros\n";
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        showData(personas[i]);
    }
}

void buscarPorID()
{
    int id;
    cout << "ID de la persona a buscar: ";
    cin >> id;
    PERSONA p = buscar(id);
    if (obtPos(id) == -1)
    {
        cout << "Registro no encontrado\n";
        return;}

        showData(p);
    
}

void showData(PERSONA &p)
{
    cout << "==================\n";
    cout << "ID: " << p.id << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Apellidos: " << p.apellidos << endl;
    cout << "Numero de cedula: " << p.numeroCedula << endl;
    cout << "Numero de telefono: " << p.numeroTelefono << endl;
    cout << "Numero de casa: " << p.numeroCasa << endl;
    if (p.pago > 0)
    {
        cout << "Pago: " << p.pago << endl;
    }
    else
    {
        cout << "No hay pagos pendientes\n";
    }
    cout << "==================\n";
}

void editarDatos()
{
    int id;
    cout << "ID de la persona a editar: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "Registro no encontrado\n";
        return;
    }
    PERSONA p = buscar(id);
    cout << "Datos actuales:\n";
    showData(p);
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(p.nombre, 50);
    cout << "Apellidos: ";
    cin.getline(p.apellidos, 50);
    cout << "Numero de cedula: ";
    cin.getline(p.numeroCedula, 20);
    cout << "Numero de telefono: ";
    cin.getline(p.numeroTelefono, 20);
    cout << "Numero de casa: ";
    cin.getline(p.numeroCasa, 10);
    cout << "Pago: ";
    cin.getline(p.pago, 20);
    editar(&p, id);
    cout << "Registro actualizado...\n";
}

void eliminarDatos()
{
    int id;
    mostrarDatos();
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

// Pagos
void registroPago(){
    PERSONA b;
    cout << "Registro de pagos\n";
    cout << "ID: ";
    scanf("%d", &b.id);
    if (obtPos(b.id) == -1)
    {
        cout << "No existe un registro de residente con este ID\n";
        return;
    }
    cout << "Pago: ";
    cin.ignore();
    cin.getline(b.pago, 20);
    cout << "Fecha limite (dd/mm/aa): ";
    cin.ignore();
    cin.getline(b.fecha, 20);
    agregarPago(b);
    cout << "Pago registrado...\n";

}

void agregarPago(PERSONA &b){
    for (int i = 0; i < pos; i++)
    {
        if (personas[i].id == b.id)
        {
            strcpy(personas[i].pago, b.pago);
            strcpy(personas[i].fecha, b.fecha);
            break;
        }
    }
}

void eliminarPagos(){
    int id;
    cout << "ID del residente al que deseas eliminar el pago: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "Registro no encontrado\n";
        return;}
    for (int i = 0; i < pos; i++)
    {
        if (personas[i].id == id)
        {
            strcpy(personas[i].pago, "");
            strcpy(personas[i].fecha, "");
            cout << "Pago eliminado...\n";
            return;
        }
    }
    
}


PERSONA BUSCAR(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (personas[i].id == id)
        {
            return personas[i];
        }
    }
}

void buscarPago(){
    int id;
    cout << "Introduce el ID del residente al que deseas buscar: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "Registro no encontrado\n";
        return;}

    PERSONA b = BUSCAR(id);
    cout << "=====================\n";
    cout << "ID: " << b.id << endl;
    cout << "Nombre: " << b.nombre << endl;
    cout << "Pago pendiente: " << b.pago << endl;
    cout << "Fecha limite: " << b.fecha << endl;
    cout << "=====================\n";
    cout << "\n";
}

// Funciones de fichero
void guardarEnFichero(){
    ofstream archivo("datos.txt");
    if (archivo.is_open()){
        for (int i = 0; i < pos; i++){
            archivo << personas[i].id << "\n";
            archivo << personas[i].nombre << "\n";
            archivo << personas[i].apellidos << "\n";
            archivo << personas[i].numeroCedula << "\n";
            archivo << personas[i].numeroTelefono << "\n";
            archivo << personas[i].numeroCasa << "\n";
            archivo << personas[i].pago << "\n";
            archivo << personas[i].fecha << "\n";
        }
        archivo.close();
        cout << "Datos guardados en fichero.\n";
    } else {
        cout << "No se pudo abrir el fichero.\n";
    }
}

void cargarDeFichero(){
    ifstream archivo("datos.txt");
    if (archivo.is_open()){
        pos = 0;
        while (!archivo.eof() && pos < MAX_REG){
            int id;
            archivo >> id;
            if (archivo.fail()) break; 
            archivo.ignore();
            archivo.getline(personas[pos].nombre, 50);
            archivo.getline(personas[pos].apellidos, 50);
            archivo.getline(personas[pos].numeroCedula, 20);
            archivo.getline(personas[pos].numeroTelefono, 20);
            archivo.getline(personas[pos].numeroCasa, 10);
            archivo.getline(personas[pos].pago, 20);
            archivo.getline(personas[pos].fecha, 20);
            personas[pos].id = id; 
            pos++;
        }
        archivo.close();
        cout << "Datos cargados del fichero.\n";
    } else {
        cout << "No se pudo abrir el fichero.\n";
    }
}
