Proceso informacion_usuario
	Definir nombre Como Cadena;
	Definir apellidos Como Cadena;
	Definir telefono Como Entero;
	Definir numeroCasa Como Entero;
	Definir Cedula Como Entero;
	// Entrada de datos
	Escribir 'Por favor, introduce tu Cedula: ';
	Leer Cedula;
	Si Cedula=0 Entonces
		Escribir 'No es valido ';
	SiNo
		Escribir 'Por favor, introduce tu nombre: ';
		Leer nombre;
		Escribir 'Por favor, introduce tus apellidos: ';
		Leer apellidos;
		Escribir 'Por favor, introduce tu n�mero de tel�fono: ';
		Leer telefono;
		Si telefono=0 Entonces
			Escribir 'No es valido ';
		SiNo
			Escribir 'Por favor, introduce tu n�mero de casa: ';
			Leer numeroCasa;
		FinSi
	FinSi
	// Salida de datos
	Escribir '';
	Escribir 'Informaci�n Introducida';
	Escribir 'Nombre: ', nombre;
	Escribir 'Apellidos: ', apellidos;
	Escribir 'N�mero de tel�fono: ', telefono;
	Escribir 'N�mero de casa: ', numeroCasa;
FinProceso
