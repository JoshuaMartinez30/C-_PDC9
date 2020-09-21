#include <iostream>
using namespace std;
int main() {
 const int TAMANIO = 80;
 char buffer1[ TAMANIO ];
 char buffer2[ TAMANIO ];
 cout << "Escriba un enunciado:" << endl;
 cin >> buffer1;
 cout << "\nLa cadena leida con cin fue:" << endl
 << buffer1 << endl << endl;
 cin.get( buffer2, TAMANIO );
 cout << "La cadena leida con cin.get fue:" << endl
 << buffer2 << endl;
}