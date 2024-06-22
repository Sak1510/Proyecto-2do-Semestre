//Codigo completado
Proceso Actividad7
	Definir i, k, password, passwordI, gan Como Entero;
	Dimensionar password[4], passwordI[4];
	
	Para i<-0 Hasta 3 Con Paso 1 Hacer
		passwordI[i] <- azar(9);
	FinPara
	
	Escribir 'Adivina la contraseña!';
	Escribir 'Dame digitos del uno al nueve';
	Escribir 'Tienes cinco intentos.';	
	
	i <- 0;
	Mientras i<5 Hacer
		gan <- 0;
		i <- i+1;
		
		Escribir ' ';
		Escribir 'Intento No.', i;
		Para k<-0 Hasta 3 Con Paso 1 Hacer
			Escribir 'Dame el digito ', k +1, ':';
			Leer password[k];
		FinPara
		
		Escribir ' ';
		Para k<-0 Hasta 3 Con Paso 1 Hacer
			Si password[k]=passwordI[k] Entonces
				Escribir password[k], ' - Cierto';
				gan <- gan+1;
			SiNo
				Escribir password[k], ' - Falso';
			FinSi
		FinPara
		Si gan=4 Entonces
			i <- 5;
			Escribir 'Ganaste :D!';
		FinSi
	FinMientras
	Si gan<>4 Entonces
		Escribir ' ';
		Escribir 'Perdiste :(';
		Escribir 'La contraseña era: ';
		
		Para i <- 0 Hasta 3 Con Paso 1 Hacer
			Escribir passwordI[i];
		FinPara
	FinSi
	
	Escribir "";
FinProceso