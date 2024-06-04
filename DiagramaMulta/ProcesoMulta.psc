Proceso ProcesoMulta
	Definir EstadoMulta, Multa Como Entero;
	Definir NombreCompl Como Cadena;
	Multa <- 1500;
	Escribir 'Ingrese el nombre completo del residente: ';
	Leer NombreCompl;
	Escribir 'El residente ha pagado a tiempo este mes? (1 para si, 0 para no): ';
	Leer EstadoMulta;
	Si EstadoMulta=0 Entonces
		Escribir 'El residente ', NombreCompl, ' debe pagar una multa de ', Multa, ' cordobas';
	SiNo
		Escribir 'El residente ', NombreCompl, ' no debe ningun pago';
	FinSi
FinProceso
