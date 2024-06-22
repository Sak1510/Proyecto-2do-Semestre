//Codigo completado
Proceso Actividad18 
	Definir i Como Entero;
	Definir temp, sum Como Real;
	sum <- 0;
	
	Escribir "Dame tres calificaciones a continuación:";
	Para i <- 0 Hasta 2 Con Paso 1 Hacer
		Escribir "Calificación No.", i +1, ":";
		Leer temp;
		
		sum <- sum +temp;
	Fin Para
	
	si sum/3 >= 6 Entonces
		Escribir "Aprobaste el semestre!";
	SiNo
		Escribir "Reprobaste, reprobaste el semestre.";
	FinSi
	
	Escribir "Tu promedio semestral fue de: ", sum/3;
FinProceso