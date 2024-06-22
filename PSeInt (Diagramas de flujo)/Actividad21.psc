Proceso Actividad21
	Escribir 'Bienvenido al gestor de agendas!';
	Escribir '1 -> Crea una nueva actividad.';
	Escribir '2 -> Revisa las actividades que tienes guardadas';
	Escribir '3 -> Busca una agenda guardada por medio de su nombre.';
	Escribir '4 -> Salir del subprograma Agenda';
	Definir i, j, k, opc Como Entero;
	k <- 1;
	Definir actividad, buscador, ind Como Cadena;
	Dimensionar actividad(100), ind(10);
	ind[0] <- 'Dame solo la hora (formato 24hrs) a la que lo realizaras:';
	ind[1] <- 'Hora invalida. Intentalo de nuevo.';
	ind[2] <- 'Dame los minutos de la hora:';
	ind[3] <- 'Minutos invalidos. Intentalo de nuevo:';
	ind[4] <- 'Dame el dia del mes:';
	ind[5] <- 'Dia invalido. Dame un dia con rango del 1 al 30:';
	ind[6] <- 'El mes: ';
	ind[7] <- 'Mes invalido. Intentalo de nuevo:';
	ind[8] <- 'El año: ';
	ind[9] <- '';
	Definir fecha, limits Como Entero;
	Dimensionar fecha(5,100), limits(10);
	limits[0] <- 1;
	limits[1] <- 24;
	limits[2] <- 1;
	limits[3] <- 60;
	limits[4] <- 1;
	limits[5] <- 30;
	limits[6] <- 1;
	limits[7] <- 12;
	limits[8] <- 2024;
	limits[9] <- 2124;
	Definir loop Como Logico;
	Repetir
		Escribir '';
		Escribir 'Que haremos?';
		Leer opc;
		Segun opc Hacer
			1:
				Escribir 'Dame el nombre clave:';
				Leer actividad[k]; // Crear nueva actividad
				loop <- Verdadero;
				Para i<-0 Hasta 8 Con Paso 2 Hacer
					Escribir ind[i];
					Leer fecha[i/2,k];
					Mientras fecha[i/2,k]<limits[i] Y loop=Verdadero O fecha[i/2,k]>limits[i+1] Y loop=Verdadero Hacer
						Si i<>8 Entonces
							Escribir ind[i+1];
							Leer fecha[i/2,k];
							Escribir '';
						SiNo
							Si fecha[i/2,k]<limits[i] Entonces
								Escribir 'Entonces viajaras al pasado?';
								Escribir 'Interesante';
							SiNo
								Escribir 'Nada mal, esperaras un muy buen rato para hacer ', actividad[k];
								Escribir 'Espero tengas suficiente paciencia y salud para completarla!';
							FinSi
							loop <- Falso;
						FinSi
					FinMientras
				FinPara
				k <- k+1;
			2:
				Para i<-0 Hasta k-1 Con Paso 1 Hacer
					Si i<>0 Entonces // Imprimir todas las actividades guardadas
						Escribir '';
						Escribir 'Actividad: ', actividad[i];
						Escribir 'Dia: ', fecha[2,i];
						Escribir 'Mes: ', fecha[3,i];
						Escribir 'Año: ', fecha[4,i];
						Escribir 'Hora: ', fecha[0,i];
						Escribir 'Minutos: ', fecha[1,i];
					FinSi
				FinPara
			3:
				Escribir 'Dame la actividad que vas a buscar por medio de su nombre clave:';
				Leer buscador; // Buscar actividad
				Para i<-1 Hasta k-1 Con Paso 1 Hacer
					Si actividad[i]=buscador Entonces
						Escribir 'Actividad encontrada!';
						Escribir '';
						Escribir 'Actividad: ', actividad[i];
						Escribir 'Dia: ', fecha[2,i];
						Escribir 'Mes: ', fecha[3,i];
						Escribir 'Año: ', fecha[4,i];
						Escribir 'Hora: ', fecha[0,i];
						Escribir 'Minutos: ', fecha[1,i];
					FinSi
					Si i=k-1 Entonces
						Escribir 'No se encontro ninguna actividad con ', buscador, ' de nombre clave';
					FinSi
				FinPara
			4:
				Escribir 'Haz salido de la agenda!';
			5:
				Escribir 'Bienvenido al gestor de agendas!';
				Escribir '1 -> Crea una nueva actividad.';
				Escribir '2 -> Revisa las actividades que tienes guardadas';
				Escribir '3 -> Busca una agenda guardada por medio de su nombre.';
				Escribir '4 -> -> Salir del subprograma Agenda';
			De Otro Modo:
				Escribir 'Intenta escribir 5 para obtener ayuda';
		FinSegun
	Hasta Que opc=4
FinProceso
