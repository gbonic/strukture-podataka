/*
1. Napisati program koji prvo pročita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamički alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i učitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.

Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relativan_br_bodova = br_bodova/max_br_bodova*100
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (30)
#define MAX_POINTS (15)
#define MAX_LINE (1024) //max broj linija u datoteci

#define FILE_NOT_OPEN (-1) //deskriptivan nacin zapisivanja da znamo sta se dogada pri izlasku iz funkcije
#define EXIT_SUCCESS (0)

typedef struct{ //koja je razlika ako ovdi stavin _student
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int points;
}student;

int readFromFile(FILE* filePointer, student* Student, int counter);

int main()
{
	int counter = 0;
	FILE* filePointer = NULL;
	filePointer = fopen("students.txt", "r");

	if (!filePointer) {
		printf("\nDatoteka se ne moze ucitati.");
		return FILE_NOT_OPEN;
	}
	while (!feof(filePointer)) { //dok ne dodemo do end of file
		if (fgetc(filePointer) == '\n') counter++; //fgetc gleda sljedeci znak
	}
	counter++; //zadnji student kad se upise ne stavljamo novi red pa ga dodamo 'manualno'
	printf("Upisano je %d studenata.\n", counter);

	student* Student = NULL;
	Student = (student*)malloc(counter*sizeof(student));
	if (!Student) {
		printf("\nAlokacija memorije nije uspjela");
	}

	rewind(filePointer); //vraca na pocetak datoteke
	readFromFile(filePointer, Student, counter);
	fclose(filePointer); //uvik zatvarat datoteku

	return EXIT_SUCCESS;
}
int readFromFile(FILE* filePointer, student* Student, int counter)
{
	int i;
	double relativePoints;
	printf("Ime i prezime:\t Bodovi:  Postotak:\t\n");

	for (i = 0; i < counter; i++) {
		fscanf(filePointer, "%s %s %d\n", &Student[i].name, &Student[i].surname, &Student[i].points); //javlja gresku ignoring return value
		relativePoints = ((double)Student[i].points / MAX_POINTS) * 100;
		printf("%s\t%s\t %d\t  %.2lf \n", Student[i].name, Student[i].surname, Student[i].points, relativePoints);
	}
	return EXIT_SUCCESS;
}