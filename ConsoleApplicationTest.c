#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Alumno
{
	char nombre[20];
	int edad;
	char carrera[20];
	float promedioGeneral;
};

int main() {

	int nAlumnos;
	char buffer[20], cualquiercosa[20];

	struct Alumno* alumnos;

	puts("Programa de structs ingrese su nombre: ");
	gets(cualquiercosa);
	fflush(stdout);
	puts("Hola");
	puts(&cualquiercosa);

	printf("\nIngrese el numero de alumnos que desea ingresar: ");
	fgets(buffer, sizeof(buffer), stdin);
	nAlumnos = atoi(buffer);

	alumnos = (struct Alumno*)malloc(nAlumnos * sizeof(struct Alumno));

	if (alumnos == NULL) {
		printf("Error de memoria\n");
		return 1;
	}

	if (nAlumnos > 0)
	{
		for (int i = 0; i < nAlumnos; i++)
		{
			printf("Ingrese el nombre del alumno %d: ", i + 1);
			fgets(alumnos[i].nombre, sizeof(alumnos[i].nombre), stdin);
			alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = 0;

			printf("Ingrese la edad del alumno %d: ", i + 1);
			fgets(buffer, sizeof(buffer), stdin);
			alumnos[i].edad = atoi(buffer);

			printf("Ingrese la carrera del alumno %d: ", i + 1);
			fgets(alumnos[i].carrera, sizeof(alumnos[i].carrera), stdin);
			alumnos[i].carrera[strcspn(alumnos[i].carrera, "\n")] = 0;

			printf("Ingrese el promedio general del alumno %d: ", i + 1);
			fgets(buffer, sizeof(buffer), stdin);
			alumnos[i].promedioGeneral = atof(buffer);
		}

		for (int i = 0; i < nAlumnos; i++)
		{
			printf("El nombre del alumno %d es %s, tiene %d de edad, estudia la carrera de %s y tiene un promedio de %.2f\n", i + 1, alumnos[i].nombre, alumnos[i].edad, alumnos[i].carrera, alumnos[i].promedioGeneral);
		}
	}

	free(alumnos);

	return 0;
}
