#include <iostream>
#include <string>

using namespace std;


void registroDatos();

// Definición de la estructura
struct InformacionUsuario {
    string nombre;
    string apellidos;
    string telefono;
    string numeroCasa;
};

void registroDatos(){
    InformacionUsuario usuario;

    cout << "Por favor, introduce tu nombre: ";
    getline(cin, usuario.nombre);

    cout << "Por favor, introduce tus apellidos: ";
    getline(cin, usuario.apellidos);

    cout << "Por favor, introduce tu numero de telefono: ";
    getline(cin, usuario.telefono);

    cout << "Por favor, introduce tu numero de casa: ";
    getline(cin, usuario.numeroCasa);

    cout << "\n Informacion Introducida \n";
    cout << "Nombre: " << usuario.nombre << "\n";
    cout << "Apellidos: " << usuario.apellidos << "\n";
    cout << "Numero de telefono: " << usuario.telefono << "\n";
    cout << "Numero de casa: " << usuario.numeroCasa << "\n";
}
