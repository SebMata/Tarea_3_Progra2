#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>


class Producto {

    int id; 
    char nombre[20]; 
    int existencia; 
    

    public:
    Producto(int id, std::string nombre, int existencia);
    Producto();

    int ObtenerID();
    std::string ObtenerNombre();
    int ObtenerExistencia();

    friend std::ostream& operator << (std::ostream &o, const Producto *producto);
};

#endif