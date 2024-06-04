Proceso Pago_factura
	// Este programa es el que  registra si el usuario ya realizo el pago y cuantos cordobas pago el usuario
	Definir pago Como Entero;
	Definir ValorPago Como Entero;
	Escribir 'Programa de pago del servicio de seguridad del mes de junio, el pago es de 100 cordobas por casa';
	Escribir 'Usted ya pago la factura del servicio de seguridad en el mes de junio(Escribir 1 = si/ 0 = no';
	Leer pago;
	Si pago=0 Entonces
		Escribir 'Este usuario no ha realizado el pago de la factura del mes de junio';
	SiNo
		Escribir 'Cuantos cordobas pago? ';
		Leer ValorPago;
		Si ValorPago<100 Entonces
			Escribir 'Usted no ha pagado lo suficiente, el pago debe ser de 100 cordobas.';
		SiNo
			Escribir 'Pago completado.';
		FinSi
	FinSi
FinProceso
