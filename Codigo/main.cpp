#include <iostream>
#include <string.h>
#include <locale.h>
#include <fstream>
#include "funciones.cpp"

int main()
{
    setlocale(LC_ALL, "");
    cargarDeFichero();  
    principal();
    guardarEnFichero();  
    return 0;
}