#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "Persona.cpp"
using namespace std;

void escribir_o_leer(fstream &fcont, bool Escribir, int contador) {
        if (Escribir) {
            string tel, nombre;
            cout<<"ingrese nombre: ";
            cin>>nombre;
            cout<<"ingrese telefono: ";
            cin>>tel;
            Persona cont(tel, nombre, contador);
            fcont.write(reinterpret_cast<const char *>(&cont), sizeof(Persona));
        } else {
            for (size_t i = 0; i < contador; i++){
                Persona cont;
                fcont.seekp(i*sizeof(Persona));
                fcont.read(reinterpret_cast< char *>(&cont), sizeof(Persona));
                cout << cont.obtenerId() << ") Nombre: " << cont.obtenerNombre() << ",  Telefono: " <<cont.obtenerTelefono()<<endl;    
            }
        }
}


void escribir(fstream &fcont, Persona &cont) {
    int pos;
    cout<<"ingrese la posicion que desea moodificar: ";
    cin>>pos;
    fcont.seekp(pos*sizeof(Persona));
    string nombre_n;
    cout<<"Ingrese nuevo nombre: ";
    cin>>nombre_n;
    cont.establecerNombre(nombre_n);
    string tel;
    cout<<"Ingrese nuevo telefono: ";
    cin>>tel;
    cont.establecerTelefono(tel);
    fcont.write(reinterpret_cast<const char *>(&cont), sizeof(Persona));
}


void modificar(fstream &fcont) {
    Persona cont;
    escribir(fcont, cont);
}


int main() {
    fstream fcont0("Personas.dat", ios::out);  fcont0.close();   
    fstream fcont("Personas.dat", ios::in | ios::out | ios::binary );
    char resp='s';
    int opcion, contador=0;
    while(resp=='s' || resp=='S'){
        cout<<"1. Agregar"<<endl;
        cout<<"2. Listar"<<endl;
        cout<<"3. Modificar"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>opcion;
        switch (opcion){
            case 1:
                cout<<endl;
                escribir_o_leer(fcont, true, contador);
                contador++;
                cout<<endl;
            break;
     
            case 2:
                cout<<endl;
                escribir_o_leer(fcont, false, contador);
                cout<<endl;
            break;

            case 3:
                cout<<endl;
                escribir_o_leer(fcont, false, contador);
                cout<<endl;
                modificar(fcont);
            break;

            case 0:
                return (0);
            break;
            default:
            break;
        }
    }
}
