#include <iostream>
using namespace std;
int main() {
 int valorAnchura = 4;
 char enunciado[ 10 ];
 cout.fill('.');
 cout << "Escriba un enunciado:" << endl;
 cin.width( 5 );
 while ( cin >> enunciado ) {
 cout.width( valorAnchura++ );
 cout << enunciado << ":" << valorAnchura - 1 << endl;
 cin.width( 5 );
 }
}
