#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct de alumno
struct Alumno
{
	char nombre[20];
	int edad;
	char carrera[20];
	float promedioGeneral;
};

int main() {

	//Declaración de variables
	int nAlumnos;
	char buffer[20], cualquiercosa[20];
	 
	//Se crea un array de alumnos con memoria dinamica
	struct Alumno* alumnos;

	//Para incluir el gets, puts y fflush
	puts("Programa de structs ingrese su nombre: ");
	gets(cualquiercosa);
	fflush(stdout);
	puts("Hola");
	puts(&cualquiercosa);

	//Ingresar el tamaño del array
	printf("\nIngrese el numero de alumnos que desea ingresar: ");
	fgets(buffer, sizeof(buffer), stdin); //Uso de gets
	nAlumnos = atoi(buffer); //Convierte a entero

	//Asignación de memoria dinamica
	alumnos = (struct Alumno*)malloc(nAlumnos * sizeof(struct Alumno));

	//Ve que no halla error en la asignacion de memoria
	if (alumnos == NULL) {
		printf("Error de memoria\n");
		return 1;
	}

	//Para evitar errrores
	if (nAlumnos > 0)
	{
		//Asigna cada variable a cada elemento del array con for
		for (int i = 0; i < nAlumnos; i++)
		{
			printf("Ingrese el nombre del alumno %d: ", i + 1);
			fgets(alumnos[i].nombre, sizeof(alumnos[i].nombre), stdin);
			alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = 0; //Para el salto de linea

			printf("Ingrese la edad del alumno %d: ", i + 1);
			fgets(buffer, sizeof(buffer), stdin); //Uso de gets
			alumnos[i].edad = atoi(buffer); //Convierte a entero

			printf("Ingrese la carrera del alumno %d: ", i + 1);
			fgets(alumnos[i].carrera, sizeof(alumnos[i].carrera), stdin);
			alumnos[i].carrera[strcspn(alumnos[i].carrera, "\n")] = 0;

			printf("Ingrese el promedio general del alumno %d: ", i + 1);
			fgets(buffer, sizeof(buffer), stdin);
			alumnos[i].promedioGeneral = atof(buffer); //Convierte a flotante
		}

		//Imprime todo el array
		for (int i = 0; i < nAlumnos; i++)
		{
			printf("El nombre del alumno %d es %s, tiene %d de edad, estudia la carrera de %s y tiene un promedio de %.2f\n", i + 1, alumnos[i].nombre, alumnos[i].edad, alumnos[i].carrera, alumnos[i].promedioGeneral);
		}
	}

	//libera memoria
	free(alumnos);

	return 0;
}
