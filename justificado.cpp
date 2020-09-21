#include <iostream>
#include <iomanip>
using namespace std;
int main() {
 int x = 10000;
 cout << x << " impreso como int justificado a la derecha y a la "
 << "izquierda\n y como hex con justificacion interna.\n"
 << "Uso del caracter de relleno predeterminado (espacio):" << endl;
 cout << showbase << setw( 10 ) << x << endl;
 cout << left << setw( 10 ) << x << endl;
 cout << internal << setw( 10 ) << hex << x << endl << endl;
 cout << "Uso de varios caracteres de relleno:" << endl;
 cout << right;
 cout.fill( '*' );
 cout << setw( 10 ) << dec << x << endl;
 cout << left << setw( 10 ) << setfill( '%') << x << endl;
 cout << internal << setw( 10 ) << setfill( '^' ) << hex
 << x << endl;
}