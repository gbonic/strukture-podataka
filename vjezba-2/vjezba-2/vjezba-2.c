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

#define EXIT_FAILURE (-1)

typedef struct _person* position;
typedef struct _person{
	char name[MAX_SIZE]; 
	char surname[MAX_SIZE];
	int birthYear;
	position next;
}Person;

position createPerson();
int addToBeginning(position person);
int addToEnd(position head);
int printPerson(position person);
int printList(position firstPerson);

int main() {
	Person Head = { .name = {0}, .surname = {0}, .birthYear = 0, .next = NULL };
	Head.next = NULL;
	int choice;
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthYear = 0;

	while (1) {
		printf("\nUnesi 1 za unos na pocetak liste, 2 za ispis liste, 3 za unos na kraj liste i 0 za izlaz iz programa.\n");
		scanf("%d", &choice);

		if (choice == 1) {
			addToBeginning(&Head);
		}
		else if (choice == 2) printList(Head.next);
		else if (choice == 3)addToEnd(&Head);
		else if (choice == 0) break;
		else printf("Nisi unio ispravan broj!\n");
	}
	return EXIT_SUCCESS;
}

position createPerson() {
	position newPerson = NULL;
	char name[MAX_SIZE] = { 0 };
	char surname[MAX_SIZE] = { 0 };
	int birthYear = 0;

	newPerson = (position)malloc(sizeof(Person));
	if (!newPerson) {
		printf("Can't allocate memory! \n");
		return NULL;
	}

	printf("Enter name: \n");
	scanf("%s", name);
	printf("Enter surname: \n"); 
	scanf("%s", surname);
	printf("Enter birth year: \n");
	scanf("%d", &birthYear);

	strcpy(newPerson->name, name);
	strcpy(newPerson->surname, surname);
	newPerson->birthYear = birthYear;
	/*newPerson->next = NULL;*/

	return newPerson;
}

int addToBeginning(position head)
{
	position newPerson = NULL;
	newPerson=createPerson();

	if (!newPerson){
		printf("\nNeuspjesna alokacija memorije!\n");
		return EXIT_FAILURE;
	}

	newPerson->next = head->next;
	head->next = newPerson;
	return EXIT_SUCCESS;
}

int printPerson(position person) {
	printf("%s\t %s\t\t %d\n", person->name, person->surname, person->birthYear);
	return EXIT_SUCCESS;
}

//B.ispisuje listu,
int printList(position firstPerson) 
{
	position current = firstPerson;

	if (!firstPerson) {
		printf("The list is empty.\n");
	}

	printf("Name:\t Surname:\t Birth year:\n");
	while (current) {
		printPerson(current);
		current = current->next;
	}
	return EXIT_SUCCESS;
}

position findLast(position head) {
	position current = head;

	while (current->next != NULL) {
		current = current->next;
	}
}
//C.dinamički dodaje novi element na kraj liste,
int addToEnd(position head) {
	position newPerson = NULL;
	position last = NULL;

	newPerson = createPerson();

	if (newPerson)
	{
		last = findLast(head);
		newPerson->next = last->next;
		last->next = newPerson;
	}

	return EXIT_SUCCESS;
}