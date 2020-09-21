#include <string> 
#include "Persona.hpp"
using namespace std;
Persona::Persona(const string &Tel, const string &Nom, const int Id) {
 establecerTelefono(Tel); establecerNombre(Nom); id = Id; }
string Persona::obtenerTelefono() const { return telefono; }
void copiar_cadena(const string Cadena, char cadena[], int long_max) {
 int longitud = Cadena.size();
 longitud = (longitud < long_max ? longitud : long_max - 1);
 Cadena.copy(cadena, longitud); cadena[longitud] = '\0';
}
void Persona::establecerTelefono(const string &Telefono) {
 copiar_cadena(Telefono, telefono, 15);
}
string Persona::obtenerNombre() const { return nombre; }
void Persona::establecerNombre(const string &Nombre) {
 copiar_cadena(Nombre, nombre, 50);
}
void Persona::establecerId(const int Id) { id = Id; }
int Persona::obtenerId() const { return id; }