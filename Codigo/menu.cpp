#include <iostream>
#include "funciones.cpp"
using namespace std;

int menu();
int menu2();

int menu(){
    int opcion;
    cout << "1. Registro de datos\n";
    cout << "2. Menu de pagos\n";
    cout << "3. Sistema de multas\n";
    cout << "4. Datos residentes\n";
    cout << "5. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int menu2(){
    int opcion;
    cout << "1. Registrar pago para un residente\n";
    cout << "2. Mostrar pagos de los residentes\n";
    cout << "3. Eliminar pagos\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void menuPagos(){
    int opcion;
    do
    {
        opcion = menu2();
        switch (opcion)
        {
        case 1:
            registroPagos();
            break;
        case 2:
            searchPayment();
            break;
        case 3:
            eliminarPagos();
            break;
        case 4:
            cout << "Saliendo del sistema\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
    } while (opcion !=4);
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
            menuPagos();
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