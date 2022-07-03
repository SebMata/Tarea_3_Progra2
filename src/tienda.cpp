#include "tienda.h"
#include "ExcepcionProductoNoExiste.h"
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

void Tienda::ModificarProductoTienda(int idPorCambiar,int idnueva,std::string nombrenuevo,int existencianueva)
{
    int a = 0;
    for (Producto *producto: this->productos){
        if((producto->ObtenerID())==idPorCambiar){
            producto->ModificarProducto(idnueva,nombrenuevo,existencianueva);
            a = 1;
        }
    }

    if(a==0){
        throw ExcepcionProductoNoExiste();
    }
}

void Tienda::ObtenerProductos()
{
    for (Producto *producto: this->productos){
    
        std::cout << producto << std::endl;
    }

}

void Tienda::EliminarProductoTienda(int idPorEliminar)
{
    int i = 0;
    int a = 0;
    for (Producto *producto: this->productos){
        if((producto->ObtenerID())==idPorEliminar){
            productos.erase(productos.begin()+i);
            a = 1;
        }
        i++;
    }
    if(a==0){
        throw ExcepcionProductoNoExiste();
    }
}

int Tienda::TotalProductos()
{
    return this->productos.size();
}

void Tienda::GuardarEnStreamBinario(std::ostream *streamSalida)
{
    streamSalida->write((char *)nombretienda, sizeof(nombretienda));
    streamSalida->write((char *)direccionFisica, sizeof(direccionFisica));
    streamSalida->write((char *)direccionInternet, sizeof(direccionInternet));
    streamSalida->write((char *)telefono, sizeof(telefono));

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

    streamEntrada->read((char *)nombretienda, sizeof(nombretienda));
    streamEntrada->read((char *)direccionFisica, sizeof(direccionFisica));
    streamEntrada->read((char *)direccionInternet, sizeof(direccionInternet));
    streamEntrada->read((char *)telefono, sizeof(telefono));

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