#include "tienda.h"
#include <iostream>
#include <cstring>

namespace Tarea3
{

Tienda::Tienda()
{

}

Tienda::Tienda(std::string nombretienda,std::string direccionInternet,std::string direccionFisica,std::string telefono)
{
    strcpy(this->nombretienda, nombretienda.c_str());
    strcpy(this->direccionInternet, direccionInternet.c_str());
    strcpy(this->direccionFisica, direccionFisica.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Tienda::~Tienda()
{
    for (Producto *producto : this->productos)
    {
        delete producto;
    }
}

std::string Tienda::ObtenerNombreTienda()
{
    return this->nombretienda;
}

std::string Tienda::ObtenerDireccionInternet()
{
    return this->direccionInternet;
}

std::string Tienda::ObtenerDireccionFisica()
{
    return this->direccionFisica;
}

std::string Tienda::ObtenerTelefono()
{
    return this->telefono;
}

void Tienda::AgregarProducto(Producto *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda::GuardarEnStreamBinario(std::ostream *streamSalida)
{
    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Tienda::CargarDesdeStreamBinario(std::istream *streamEntrada)
{
    streamEntrada->seekg( 0, std::ios::end );
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = cantidadBytesEnArchivo / sizeof(Producto);
    streamEntrada->seekg( 0, std::ios::beg ); 
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto)); 
        this->AgregarProducto(producto);
    }
    
}

std::ostream& operator << (std::ostream &o, const Tienda *tienda)
{
    o << tienda->nombretienda << std::endl;
    o << tienda->direccionInternet << std::endl;
    o << tienda->direccionFisica << std::endl;
    o << tienda->telefono << std::endl;

    for (Producto *producto: tienda->productos)
    {
        o << producto<< std::endl;
    }
    
    return o;
}
}