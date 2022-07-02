#include "tienda.h"
#include <iostream>
#include <cstring>

Tienda::Tienda()
{

}

Tienda::Tienda(string nombretienda,string direccionInternet,string direccionFisica,string telefono)
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

string Tienda::ObtenerNombreTienda()
{
    return this->nombretienda;
}

string Tienda::ObtenerDireccionInternet()
{
    return this->direccionInternet;
}

string Tienda::ObtenerDireccionFisica()
{
    return this->direccionFisica;
}

string Tienda::ObtenerTelefono()
{
    return this->telefono;
}

void Tienda::AgregarProducto(Producto *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
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

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << "Tienda: " << std::endl;

    for (Producto *producto: tienda->productos)
    {
        o << producto<< endl;
    }
    
    return o;
}