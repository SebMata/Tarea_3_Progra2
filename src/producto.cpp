#include "producto.h"
#include <iostream>
#include <cstring>

Producto::Producto(int id, string nombre, int existencia)
{
    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    this->existencia = existencia;
}

Producto::Producto()
{
    this->id = 0;
    strcpy(this->nombre, "");
    this->existencia = existencia;
}

int Producto::ObtenerID()
{
    return this->id;
}

string Producto::ObtenerNombre()
{
    return this->nombre;
}

int Producto::ObtenerExistencia()
{
    return this->existencia;
}

ostream& operator << (ostream &o, const Producto *producto)
{
    o << producto->id << " " << producto->nombre << " " << producto->existencia;  
    return o;
}