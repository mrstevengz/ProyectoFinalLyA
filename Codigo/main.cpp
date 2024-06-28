#include <iostream>
#include <string.h>
#include <locale.h>
#include <fstream>
#include "funciones.cpp"

int main()
{
    setlocale(LC_ALL, "");
    cargarDeFichero();  // Cargar los datos del fichero al inicio
    principal();
    guardarEnFichero();  // Guardar los datos en el fichero al final
    return 0;
}