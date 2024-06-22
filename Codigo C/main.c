#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Funciones de apoyo
int CloseMainSupport(char userComand[]) {
	//Siempre cambiar el tamaño del array y size cada vez que se vaya a agregar un nuevo comando
	int size = 5;
	char comands[5][15] = {"PASSWORD", "APROBE?", "SUMA_PAR", "AGENDA", "AYUDA"};
	
	int i, j = 0, sum = 0, returned;
	bool loop = true;
	while(loop && j < size) {
		for(i = 0; i < strlen(comands[j]); i++) if(userComand[i] == comands[j][i]) sum++;
		
		if(sum == strlen(comands[j])) loop = false;
		else { j++; sum = 0; }
	}
	
	if(!loop) returned = j;
	else returned = -1;
	
	return returned;
}

void help() {
	printf("\"PASSWORD\"\tValidar una contraseña.\n");
	printf("\"APROBE?\"\tEn base a tres calificaciones, se determina si aprobaste o no el semestre.\n");
	printf("\"SUMA_PAR\"\tDame un numero y se sumaran todos los pares desde el 1 hasta tal numero.\n"); 
	printf("\"AGENDA\"\tGestor de actividades a travez de una agenda\n");
}


//Ejercicio 6
void actividad6() { //Diagrama de flujo completado 		//CODIGO TERMINAOOO
	int N, sumP = 2, sumT = 0, i;
	char mensaje[100] = "\tEspera, son legales los numeros negativos aqui?\n";
	
	printf("\tDame hasta donde sumaras: ");
	scanf("%d", &N);
	
	if(N < 0) {
		for(i = 0; i < strlen(mensaje); i++) {
			printf("%c", mensaje[i]);
			if(i != 8) Sleep(10); else Sleep(500);
		} Sleep(1000);
	}
	
	while(sumP <= N) {
		sumT += sumP;
		sumP += 2;
	} printf("\tLa suma es igual a %d\n", sumT);
}


//Ejercicio 7
void actividad7() { //Diagrama de flujo terminado 		//CODIGO TERMINAOOO
	srand(time(NULL));
	int password[4], passwordI[4], gan = 0, i, k = 0;
	for(i = 0; i < 4; i++) {
        passwordI[i] = rand()%9;
    }
	
	printf("\tAdivina una contraseña!\n");
	printf("\tDame digitos del cero al nueve\n");
	printf("\tTienes cinco intentos.\n");
    
    i = 0;
    while(i < 5) {
    	i++;
    	
    	printf("\n\tIntento No.%d\n", i);
		for(k = 0; k < 4; k++) {
			printf("\tDame el digito %d: ", k +1);
			scanf("%d", &password[k]);
		}
		
		for(k = 0; k < 4; k++) {
			Sleep(500);
			printf("\t\t%d - ", password[k]);
			if(password[k] == passwordI[k]) {
				printf("Cierto");
				gan++;
			} else printf("Falso");
			
			if(password[k] > 9) printf(" - Recuerda darme numeros del 0 al 9!\n");
			else if(password[k] < 0) printf(" - Negativos nooo\n");
			else printf("\n");
		}
		
		if(gan == 4) {
			i = 5;
			printf("\tGanaste :D!\n");
		} else gan = 0;
    }
    
    if(gan != 4) {
        printf("\n\tPerdiste :(\n");
        printf("\tLa contraseña era: ");
        
        for(i = 0; i < 4; i++) {
            printf("%d", passwordI[i]);
            Sleep(500);
            if(i != 3) printf(" - ");
            Sleep(500);
        } printf("\n");
}}


//Ejercicio 18
void actividad18() { //Diagrama de flujo completado		//CODIGO TERMINAOOO
	int i, k;
	float sum = 0, temp[3], promedio = 0;
	bool simon = true;
	char mensaje[4][100] = {
		"\tEspera un momento, introduciste una calificacion negativa?\n\n\a",
		"\tComo vas a sacar mas de diez? Ya ni Quico se atrevio a tanto xD\n\n\a",
		"\tAprobaste el semestre!\n\n",
		"\tReprobaste, reprobaste el semestre.\n\n"
	};
	
	printf("\tDame tres calificaciones a continuación:\n");
	for(i = 0; i < 3; i++) {
		printf("\tCalificacion No.%d: ", i +1);
		scanf("%f", &temp[i]);
		
		sum += temp[i];
	}
	
	printf("\tCalculando");
	for(i = 0; i < 4; i++) {
		printf(". ");
		Sleep(1000);
	}
	
	for(i = 0; i < 3; i++) {	
		if(temp[i] < 0) { 
			for(k = 0; k < strlen(mensaje[0]); k++) {
				printf("%c", mensaje[0][k]);
				if(k != 19) Sleep(10); else Sleep(500);
			} simon = false; break;
		} else if(temp[i] > 10) {
			for(k = 0; k < strlen(mensaje[1]); k++) {
				printf("%c", mensaje[1][k]);
				if(k != 30) Sleep(10); else Sleep(500);
			} simon = false; break;
	}}
	
	if(simon) {
		promedio = sum/3;
		if(sum/3 >= 6) for(k = 0; k < strlen(mensaje[2]); k++) { 
			printf("%c", mensaje[2][k]);
			Sleep(10);
		} else for(k = 0; k < strlen(mensaje[3]); k++) {
			printf("%c", mensaje[3][k]);
			Sleep(10);
	}}
	
	Sleep(1000);
	printf("\tTu promedio semestral fue de: %.1f\n", promedio);
	if(!simon) printf("\t0 por menso jijijiji\n"); else {
		if(promedio > 8) printf("\tQue buen estudiante!\n");
		else if(promedio > 6) printf("\tYa es algo!\n");
		else printf("\tBueno, a lo mejor, le intentaste! O tal vez no...\n");
}}


//Ejercicio 21
void actividad21() {
	printf("\tBienvenido al gestor de agendas!\n\tA continuación tienes lo que puedes hacer aqui:\n");
	printf("\t\"N\" -> Crea una nueva actividad.\n");
	printf("\t\"V\" -> Revisa las actividades que tienes guardadas dentro de la agenda.\n");
	printf("\t\"B\" -> Busca una agenda guardada por medio de su nombre.\n");
	printf("\t\"E\" -> Salir del subprograma \"Agenda\"\n");
	
	int i, j, k = 1;
	
	char actividad[100][12], opc, buscador[12], ind[10][100] = {
		"\n\tDame solo la hora (formato 24hrs) a la que lo realizaras: ", "\tHora invalida. Intentalo de nuevo: ",
		"\tDame los minutos de la hora: ", "\tMinutos invalidos. Intentalo de nuevo: ",
		"\tDame el dia del mes: ", "\tDia invalido. Dame un dia con rango del 1 al 30: ",
		"\tEl mes: ", "\tMes invalido. Intentalo de nuevo: ",
		"\tEl año: ", "" 
	}; for(i = 0; i < 100; i++) strcpy(actividad[i], "");
	
	int fecha[5][100], limits[10] = {
		1, 24,   //Hora
		1, 60,	 //Minutos
		1, 30,   //Dia
		1, 12, 	 //Mes
		2024, 2124 //Año
	};
	
	char mensaje[2][1000] = {
		"\tViajaras al pasado??\n\tAhi me saludas a los dinosaurios, y tambien al Alberto Instantaneo, y... no se a Chabelo jajajaja Salu2\n\n",
		"\tNada mal, esperaras un muy buen rato para esta actividad.\n\tEspero tengas suficiente paciencia y salud para completarla!\n\n"
	};
	
	for(i = 0; i < 100; i++) strcpy(actividad[i], "            ");
	
	do {
		printf("\n\tQue haremos? "); scanf("%s", &opc);
		switch(opc) {
			case 'N':
				printf("\tNueva actividad a guardar!\n\tDame su nombre clave: ");  scanf("%s", &actividad[k]);
				
				for(i = 0; i < 10; i += 2) {
					printf("%s", ind[i]);
					scanf("%d", &fecha[i/2][k]);
					
					while(fecha[i/2][k] < limits[i] || fecha[i/2][k] > limits[i +1]) {
						//printf("\ti: %d\n", i);
						if(i != 8) {
							printf("%s\a", ind[i +1]); 
							scanf("%d", &fecha[i/2][k]);
							
							printf("\n");							
						} else {
							if(fecha[i/2][k] < limits[i]) for(j = 0; j < strlen(mensaje[0]); j++) {
								printf("%c", mensaje[0][j]);
								if(j != 21 && j != 58 && j != 91 && j != 92 && j != 93 && j != 94) Sleep(10); else Sleep(1000);
							} else if(fecha[i/2][k] > limits[i +1]) for(j = 0; j < strlen(mensaje[1]); j++) {
								printf("%c", mensaje[1][j]);
								if(j != 10) Sleep(10); else Sleep(1000);
							}
							 break;
				}}}
				
				k++;
				break;
				
			case 'V':
				printf("\tNombre      \tDD\\MM\\AAAA\tHH:MM\n\t");
				for(i = 0; i < k; i++) if(i != 0) {
					Sleep(100);
					for(j = 0; j < 12; j++) printf("%c", actividad[i][j]); //Nombre
					printf("\t");
					
					if(fecha[2][i] < 10) printf("0");
					printf("%d\\", fecha[2][i]); //Dia
					
					if(fecha[3][i] < 10) printf("0");
					printf("%d\\", fecha[3][i]); //Mes
					
					for(j = 1; j < 4; j++) if(fecha[4][i] < pow(10, j)) printf("0");
					printf("%d\t", fecha[4][i]); //Año
					
					if(fecha[0][i] < 10) printf("0%d:", fecha[0][i]); //Hora
					else printf("%d:", fecha[0][i]);
					
					if(fecha[1][i] < 10) printf("0%d hrs\n\t", fecha[1][i]); //Minutos
					else printf("%d hrs\n\t", fecha[1][i]);
				} break;
				
			case 'B':
				printf("\tDame la actividad que vas a buscar por medio de su nombre clave: ");
				scanf("%s", &buscador);
				
				for(i = 0; i < k; i++) {
					if(strcmp(buscador, actividad[i]) == 0) {
						printf("\tActividad encontrada!\n\n");
						
						printf("\tNombre      \tDD\\MM\\AAAA\tHH:MM\n\t");
						for(j = 0; j < 12; j++) printf("%c", actividad[i][j]); //Nombre
						printf("\t");
						
						if(fecha[2][i] < 10) printf("0");
						printf("%d\\", fecha[2][i]); //Dia
						
						if(fecha[3][i] < 10) printf("0");
						printf("%d\\", fecha[3][i]); //Mes
						
						for(j = 1; j < 4; j++) if(fecha[4][i] < pow(10, j)) printf("0");
						printf("%d\t", fecha[4][i]); //Año
						
						if(fecha[0][i] < 10) printf("0%d:", fecha[0][i]); //Hora
						else printf("%d:", fecha[0][i]);
						
						if(fecha[1][i] < 10) printf("0%d hrs\n\t", fecha[1][i]); //Minutos
						else printf("%d hrs\n\t", fecha[1][i]);					
						break;
					}
					
					if(i == k -1) printf("\tNo se encontro ninguna actividad con \"%s\" de nombre clave.\n", buscador);
				} break;
				
			case 'E': 
				printf("\tHaz salido de la agenda!\n");
				break;
				
			case 'H':
				printf("\t\"N\" -> Crea una nueva actividad.\n");
				printf("\t\"V\" -> Revisa las actividades que tienes guardadas dentro de la agenda.\n");
				printf("\t\"B\" -> Busca una agenda guardada por medio de su nombre.\n");
				printf("\t\"E\" -> Salir del subprograma \"Agenda\"\n");				
				break;
				
			default: printf("\tOpción no conocida. Intentalo de nuevo! (Si tienes duda de que hacer, escribe \"H\")\n");
	}} while(opc != 'E');
}


//Codigo donde se ejecuta todo
int main(int argc, char *argv[]) {
	printf("Bienvenido a la fortaleza de la luz\n");
	help();
	
	char opcS[100], ciclo = 's'; int opcI;
	while(ciclo == 's') {
		printf("Dame una de las opciones: "); scanf("%s", &opcS);
		opcI = CloseMainSupport(opcS); //CloseMainSupport -> CMS --- CAS -> Close Air Support (profe ignore esto asdasdaikdaiks)
		
		switch(opcI) {
			case 0: actividad7();  break; //Contrasena
			case 1: actividad18(); break; //Promedio
			case 2: actividad6();  break; //NumeroPar
			case 3: actividad21(); break; //Agenda
			
			case 4: help(); break; //Ayuda
			default: printf("Intenta escribir \"AYUDA\" para obtener informacion sobre cada subprograma\a\n");
		}
		
		printf("\nQuieres probar algun otro subprograma? (s/n): ");
		scanf("%s", &ciclo);
	} printf("\aPrograma terminado!\n");
	
	system("PAUSE");
	return 0;
}
