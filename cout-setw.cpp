#include <iostream>
#include <iomanip>
using namespace std;
int main() {
 int x = 12345;
 cout << "La opcion predeterminada es justificado a la derecha:" << endl
 << setw( 10 ) << x;
 cout << "\n\nUso de std::left para justificar x a la izquierda:\n"
 << left << setw( 10 ) << x;
 cout << "\n\nUso de std::right para justificar x a la derecha:\n"
 << right << setw( 10 ) << x << endl;
}
