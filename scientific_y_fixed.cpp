#include <iostream>
using namespace std;
int main() {
 double x = 0.001234567;
 double y = 1.946e9;
 cout << "Mostrados en el formato predeterminado:" << endl
 << x << '\t' << y << endl;
 cout << "\nMostrados en el formato cientifico:" << endl
 << scientific << x << '\t' << y << endl;
 cout << "\nMostrados en formato fijo:" << endl
 << fixed << x << '\t' << y << endl;
}
