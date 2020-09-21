#include <iostream>
#include <iomanip>
using namespace std;
int main() {
 int numero;
 cout << "Escriba un numero decimal: ";
 cin >> numero;
 cout << numero << " en hexadecimal es: " << hex << numero << endl;
 cout << dec << numero << " en octal es: " << oct << numero << endl;
 cout << setbase( 10 ) << numero << " en decimal es: " << numero << endl;
}
