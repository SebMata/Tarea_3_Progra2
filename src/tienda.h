#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>

using namespace std;

class Tienda {

    vector<Producto *> productos;

    char nombretienda[15];
    char direccionInternet[24]; 
    char direccionFisica[24]; 
    char telefono[8]; 

    public:
    Tienda(string nombretienda,string direccionInternet,string direccionFisica,string telefono);
    Tienda();
    ~Tienda();

    string ObtenerNombreTienda();
    string ObtenerDireccionInternet();
    string ObtenerDireccionFisica();
    string ObtenerTelefono();

    void AgregarProducto(Producto *nuevoProducto);

    void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStreamBinario(istream *streamEntrada);

    friend ostream& operator << (ostream &o, const Tienda *tienda);
};

#endif