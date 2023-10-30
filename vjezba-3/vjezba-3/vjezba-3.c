//2. Definirati strukturu osoba(ime, prezime, godina rođenja) i napisati program koji :
//A.dinamički dodaje novi element na početak liste,
//B.ispisuje listu,
//C.dinamički dodaje novi element na kraj liste,
//D.pronalazi element u listi(po prezimenu),
//E.briše određeni element iz liste,
//U zadatku se ne smiju koristiti globalne varijable.

//3. Prethodnom zadatku dodati funkcije :
//A.dinamički dodaje novi element iza određenog elementa,
//B.dinamički dodaje novi element ispred određenog elementa,
//C.sortira listu po prezimenima osoba,
//D.upisuje listu u datoteku,
//E.čita listu iz datoteke.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (32)

#define EXIT_FAILURE (-1)
#define EMPTY_LIST (-1)
#define PERSON_NOT_FOUND (-1)

typedef struct _person* position;
typedef struct _person {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthYear;
	position next;
}Person;

position createPerson();
int menu(Person Head);
int addToBeginning(position person);
int addToEnd(position head);
int printPerson(position person);
int printList(position firstPerson);
int deletePerson(position head);
int findPerson(position head);
int insertBeforePerson(position head);

int main() {
	Person Head = { .name = {0}, .surname = {0}, .birthYear = 0, .next = NULL };
	Head.next = NULL;
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthYear = 0;
	menu(Head);
	return EXIT_SUCCESS;
}

position createPerson() {
	position newPerson = NULL;
	char name[MAX_SIZE] = { 0 };
	char surname[MAX_SIZE] = { 0 };
	int birthYear = 0;

	newPerson = (position)malloc(sizeof(Person));
	if (!newPerson) {
		printf("Neuspjesna alokacija memorije! \n");
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
	newPerson = createPerson();

	if (!newPerson) {
		printf("\nNeuspjesna alokacija memorije!\n");
		return EXIT_FAILURE;
	}

	newPerson->next = head->next;
	head->next = newPerson;
	return EXIT_SUCCESS;
}

int printPerson(position person) {
	printf("%s\t%s\t %d\n", person->name, person->surname, person->birthYear);
	return EXIT_SUCCESS;
}

//B.ispisuje listu,
int printList(position firstPerson)
{
	position current = firstPerson;

	if (!firstPerson) {
		printf("Lista je prazna!\n");
	}

	printf("Ime:\tPrezime:\tGodina rodjenja:\n");
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

char* enterSurname() {
	char surname[MAX_SIZE] = { 0 };
	printf("Prezime trazene osobe:\n");
	scanf("%s", surname);

	return surname;
}

//D.pronalazi element u listi(po prezimenu),
int findPerson(position head) {
	position current = head;
	char surname[MAX_SIZE] = { 0 };

	if (!head) {
		printf("\nLista je prazna!\n");
		return PERSON_NOT_FOUND;
	}

	strcpy(surname, enterSurname());
	while (current != 0 && strcmp(current->surname, surname) != 0) {
		current = current->next;
	}if (strcmp(current->surname, surname) == 0) {
		printf("Ime:\t Prezime:\t Godina rodjenja:\n");
		printPerson(current);
		return current;
	}
	return PERSON_NOT_FOUND;
}

//E.briše određeni element iz liste,
int deletePerson(position head) {
	position current = head;
	char surname[MAX_SIZE] = { 0 };

	strcpy(surname, enterSurname());
	if (head->next != NULL) {
		position previous = NULL;

		while (current->next && strcmp(current->surname, surname) != 0) {
			previous = current;
			current = current->next;
		}
		if (strcmp(current->surname, surname) == 0) {
			printf("\nSljedeca osoba je izbrisana:\n");
			printPerson(current);
			previous->next = current->next;
			free(current);
		}
		else {
			printf("Nema osobe tog prezimena.\n");
		}

	}
	return EXIT_SUCCESS;
}

int menu(Person Head) {
	while (1) {
		int choice;
		printf("\nUnesi 1 za unos na pocetak liste,\n\t2 za ispis liste,\n\t3 za unos na kraj liste,\n\t4 za pretragu po prezimenu,\n\t5 za brisanje osobe,\n\t6 za dodavanje nakon odredjene osobe i\n\t0 za izlaz iz programa.\n");
		scanf("%d", &choice);

		if (choice == 1) addToBeginning(&Head);
		else if (choice == 2) printList(Head.next);
		else if (choice == 3)addToEnd(&Head);
		else if (choice == 4)findPerson(&Head);
		else if (choice == 5) deletePerson(&Head);
		else if (choice == 6) {
			position person = NULL;
			printf("Upisujete osobu nakon sljedece osobe:\n");
			person=findPerson(&Head);
			insertAfterPerson(person);
		}
		else if (choice == 0) break;
		else printf("Nisi unio ispravan broj!\n");
	}
	return EXIT_SUCCESS;
}

//A.dinamički dodaje novi element iza određenog elementa,
int insertAfterPerson(position person) {
	position newPerson = NULL;
	newPerson = createPerson();

	if (newPerson) {
		newPerson->next = person->next;
		person->next = newPerson;
	}
	return EXIT_SUCCESS;
}