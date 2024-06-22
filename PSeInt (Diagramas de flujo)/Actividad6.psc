//Codigo completado
Proceso Actividad6 
	Definir N, sumP, sumT Como Entero;
	sumP <- 2;
	sumT <- 0;
	
	Escribir 'Dame hasta donde sumaras:';
	Leer N;
	
	Mientras sumP <= N Hacer
		sumT <- sumT+sumP;
		sumP <- sumP+2;
	FinMientras 
	Escribir 'La suma es igual a ', sumT;
FinProceso