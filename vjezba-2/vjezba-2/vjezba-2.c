//2. Definirati strukturu osoba(ime, prezime, godina rođenja) i napisati program koji :
//A.dinamički dodaje novi element na početak liste,
//B.ispisuje listu,
//C.dinamički dodaje novi element na kraj liste,
//D.pronalazi element u listi(po prezimenu),
//E.briše određeni element iz liste,
//U zadatku se ne smiju koristiti globalne varijable.

/*
vezana lista struktura, & je lokacija
next je pokazivac na strukturu, u njega spremamo lokaciju iduce strukture
zadnji next pokazuje na null
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (32)

#define EXIT_SUCCESS (0)

typedef struct _person* position;
typedef struct _person{
	char name[MAX_SIZE]; 
	char surname[MAX_SIZE];
	int birthYear;
	position next;
}Person;

int addToBeginning(position p);

int main() {
	Person Head = { .name = {0}, .surname = {0}, .birthYear = 0, .next = NULL };
	Head.next = NULL;
	int choice;

	while (1) {
		printf("Unesi 1 za unos na pocetak liste, a 0 za izlaz iz programa.\n");
		scanf("%d", &choice);

		if (choice == 1) addToBeginning(&Head);
		else if (choice == 0) break;
		else printf("Nisi unio ispravan broj!\n");
	}
	return EXIT_SUCCESS;
}

int addToBeginning(position p)
{
	position q = NULL;
	q = (position)malloc(sizeof(Person));
	if (q == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}

	printf("Unesi ime osobe: ");
	scanf("%s", q->name);
	printf("Unesi prezime osobe: ");
	scanf("%s", q->surname);
	printf("Unesi godinu rodenja osobe: ");
	scanf("%d", &q->birthYear);

	q->next = p->next;
	p->next = q;
	return 0;
}

//napravit izbornik da korisnik bira oce dodat nekoga i slicno

