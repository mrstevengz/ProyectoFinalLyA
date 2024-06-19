#include <iostream>
#include <string>

using namespace std;

// Definición de la estructura Persona
struct Persona {
    string nombre;
    string apellidos;
    int id;
    string numeroTelefono;
    string numeroCasa;
};

// Constante para el tamano maximo de registros
const int MAX_PERSONAS = 100;

// Función para registrar una nueva persona
void registrarPersona(Persona registros[], int &contador) {
    if (contador < MAX_PERSONAS) {
        Persona nuevaPersona;

        cout << "Ingrese el nombre: ";
        getline(cin, nuevaPersona.nombre);

        cout << "Ingrese los apellidos: ";
        getline(cin, nuevaPersona.apellidos);

        cout << "Ingrese el ID: ";
        cin >> nuevaPersona.id;
        cin.ignore(); // Ignorar el salto de linea despues de ingresar el ID

        cout << "Ingrese el numero de telefono: ";
        getline(cin, nuevaPersona.numeroTelefono);

        cout << "Ingrese el numero de casa: ";
        getline(cin, nuevaPersona.numeroCasa);

        registros[contador] = nuevaPersona;
        contador++;
    } else {
        cout << "No se pueden registrar mas personas. Limite alcanzado." << endl;
    }
}

// Funcion para mostrar los registros
void mostrarRegistros(const Persona registros[], int contador) {
    for (int i = 0; i < contador; i++) {
        cout << "-------------------------" << endl;
        cout << "Nombre: " << registros[i].nombre << endl;
        cout << "Apellidos: " << registros[i].apellidos << endl;
        cout << "ID: " << registros[i].id << endl;
        cout << "Numero de telefono: " << registros[i].numeroTelefono << endl;
        cout << "Numero de casa: " << registros[i].numeroCasa << endl;
        cout << "------------------------" << endl;
    }
}

int main() {
    Persona registros[MAX_PERSONAS];
    int contador = 0;
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Registrar una nueva persona" << endl;
        cout << "2. Mostrar todos los registros" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin.ignore(); // Ignorar el salto de línea despues de ingresar la opcion
        cin >> opcion;
        

        switch (opcion) {
            case 1:
                registrarPersona(registros, contador);
                break;
            case 2:
                mostrarRegistros(registros, contador);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 3);

    return 0;
}
