#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto {

    int id; 
    char nombre[20]; 
    int existencia; 
    

    public:
    Producto(int id, string nombre, int existencia);
    Producto();

    int ObtenerID();
    string ObtenerNombre();
    int ObtenerExistencia();

    friend ostream& operator << (ostream &o, const Producto *producto);
};

#endif