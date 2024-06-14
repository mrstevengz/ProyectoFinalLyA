#include <iostream>
#include <string>
using namespace std;

struct Pago {
    string idUsuario;
    float cantidad;
    string fecha;
};

void registroPagos();

void registroPagos() {
    Pago nuevoPago;

cout << "Ingrese el ID del usuario: ";
cin >> nuevoPago.idUsuario;

cout << "Ingrese la cantidad pagada: ";
cin >> nuevoPago.cantidad;

cout << "Ingrese la fecha del pago: ";
cin >> nuevoPago.fecha;
}