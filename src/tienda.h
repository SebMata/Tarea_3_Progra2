#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>

namespace Tarea3
{
class Tienda {

    char nombretienda[15];
    char direccionInternet[24]; 
    char direccionFisica[24]; 
    char telefono[8]; 

    public:
    std::vector<Producto *> productos;
    Tienda(std::string nombretienda,std::string direccionInternet,std::string direccionFisica,std::string telefono);
    Tienda();
    ~Tienda();

    std::string ObtenerNombreTienda();
    std::string ObtenerDireccionInternet();
    std::string ObtenerDireccionFisica();
    std::string ObtenerTelefono();
    int TotalProductos();
    void ObtenerProductos();

    void EliminarProductoTienda(int idPorEliminar);
    void AgregarProducto(Producto *nuevoProducto);
    void ModificarProductoTienda(int idPorCambiar,std::string nombrenuevo,int existencianueva);
    
    void GuardarEnStreamBinario(std::ostream *streamSalida);
    void CargarDesdeStreamBinario(std::istream *streamEntrada);

    friend std::ostream& operator << (std::ostream &o, const Tienda *tienda);
};
}

#endif