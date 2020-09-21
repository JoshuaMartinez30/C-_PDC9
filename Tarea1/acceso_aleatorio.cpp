#include <iostream> // acceso_aleratorio.cpp
#include <fstream>
#include <cstdlib>
#include "Contacto.cpp"
using namespace std;

void escribir_o_leer(fstream &fcont, bool Escribir) {
    for (int i = 0; i < 6; ++i)
        if (Escribir) {
            Contacto cont("FALTA TELEFONO", "Nombre " + to_string(i), i);
            fcont.write(reinterpret_cast<const char *>(&cont), sizeof(Contacto));
        } else {
            Contacto cont;
            fcont.seekp(i*sizeof(Contacto));
            fcont.read(reinterpret_cast< char *>(&cont), sizeof(Contacto));
            cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
        }
}

void leer_el_3(fstream &fcont, Contacto &cont){
 fcont.seekp(3*sizeof(Contacto));
 fcont.read(reinterpret_cast< char *>(&cont), sizeof(Contacto));
 cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
}

void escribir_el_3(fstream &fcont, Contacto &cont) {
fcont.seekp(3*sizeof(Contacto));
 cont.establecerId(5000);
 cont.establecerNombre("NOMBRE 5 -> 5000");
 fcont.write(reinterpret_cast<const char *>(&cont), sizeof(Contacto));
}


void cambios(fstream &fcont) {
 Contacto cont;
 leer_el_3(fcont, cont);
 escribir_el_3(fcont, cont);
 leer_el_3(fcont, cont);
}

int main() {
 fstream fcont("contactos.dat", ios::in | ios::out | ios::binary );
 escribir_o_leer(fcont, true);
 cout << "ANTES:" << endl;
 escribir_o_leer(fcont, false);
 cout << endl << "CAMBIOS:" << endl;
 cambios(fcont);
 cout << endl << "DESPUES:" << endl;
 escribir_o_leer(fcont, false);
}
