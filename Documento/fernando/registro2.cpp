#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>
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

int menu()
{
    int op;
    cout << "1. Agregar\n";
    cout << "2. Editar\n";
    cout << "3. Eliminar\n";
    cout << "4. Buscar\n";
    cout << "5. Mostrar todo\n";
    cout << "6. Salir\n";
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

void principal()
{
    int op;
    do
    {
        op = menu();
        switch (op)
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
        case 6:
            cout << "Adios\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
    } while (op != 6);
}

void pedirDatos()
{
    PERSONA persona;
    cout << "Datos de la persona\n";
    cout << "ID: ";
    cin >> persona.id;
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
    if (p.id != 0)
    {
        showData(p);
    }
    else
    {
        cout << "Registro no encontrado\n";
    }
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
    editar(&p, id);
    cout << "Registro actualizado...\n";
}

void eliminarDatos()
{
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

int main()
{
    principal();
    return 0;
}
