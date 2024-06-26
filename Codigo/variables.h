#define MAX_REG 100

// Definición de la estructura PERSONA
struct PERSONA {
    int id;
    char nombre[50];
    char apellidos[50];
    char numeroCedula[20];
    char numeroTelefono[20];
    char numeroCasa[10];
    char pago[MAX_REG];
    int cantidad;
    char fecha [MAX_REG];
};