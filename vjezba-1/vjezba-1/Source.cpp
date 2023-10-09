#include <iostream>
using namespace std;

int main() {
	int a;
	cout << "Upisi broj izmedu 4 i 9: ";
	cin >> a;
	while (a < 4 | a>9) {
		printf("Krivo!");
		cout << "Upisi broj izmedu 4 i 9: ";
		cin >> a;
	}
	printf("Broj je u ispravnom intervalu.");
	return 0;
}