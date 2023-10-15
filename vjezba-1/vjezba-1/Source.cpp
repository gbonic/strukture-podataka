#include <iostream>
using namespace std;

void funkcija() {
	cout << "\nHvala na pokusaju!\n";
}

int main() {
	int a;
	cout << "Upisi broj izmedu 4 i 9: ";
	cin >> a;
	while (a < 4 | a>9) {
		printf("Krivo!\n");
		cout << "Upisi broj izmedu 4 i 9: ";
		cin >> a;
	}
	printf("Broj je u ispravnom intervalu.");

	funkcija();
	return 0;
}