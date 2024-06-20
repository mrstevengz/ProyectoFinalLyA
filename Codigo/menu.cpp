#include <iostream>
#include "funciones.cpp"
using namespace std;

int menu();

int menu(){
    int opcion;
    cout << "1. Registro de datos\n";
    cout << "2. Registro de pagos\n";
    cout << "3. Sistema de multas\n";
    cout << "4. Datos residente\n";
    cout << "5. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void codigoPrincipal(){
    int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            registroDatos();
            break;
        case 2:
            registroPagos();
            break;
        case 4:
            searchUser();
            break;
        case 5:
            cout << "Saliendo del sistema\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
    } while (opcion !=5);
    
}

