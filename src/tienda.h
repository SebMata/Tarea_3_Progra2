#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>

using namespace std;

class Tienda {

    vector<Producto *> Productos;

    char nombretienda[15];
    char direccionInternet[24]; 
    char direccionFisica[24]; 
    char telefono[8]; 

    public:
    Tienda(string nombretienda,string direccionInternet,string direccionFisica,string telefono);
    ~Tienda();

    void AgregarEmpleado(Producto *nuevoProducto);

    void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStreamBinario(istream *streamEntrada);
    void CargarEmpleadoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionEmpleado);

    friend ostream& operator << (ostream &o, const Tienda *tienda);
};

#endif