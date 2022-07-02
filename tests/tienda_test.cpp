#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"

using namespace std;

namespace
{
    TEST(Tienda_Test, Escribir_Leer_Archivo_Binario_Test)
    {

        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","25751238");

        Producto *producto1 = new Producto(1,"Jabón",3);
        tiendaEsperada->AgregarProducto(producto1);

        ofstream archivoSalida;
        archivoSalida.open("archivo_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Tienda *tiendaLeida = new Tienda("Walmart","walmartgmail","Cartago","25751238");
        tiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        ostringstream streamSalidaTiendaLeida;
        streamSalidaTiendaLeida << tiendaLeida;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaLeida;
        delete tiendaEsperada;

        string esperado = "Walmart\nwalmartgmail\nCartago\n25751238\n1 Jabón 3\n"; 
        string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        EXPECT_EQ(esperado, salidaTiendaEsperada);

        string salidaTiendaLeidaDeArchivo = streamSalidaTiendaEsperada.str();
        EXPECT_EQ(esperado, salidaTiendaLeidaDeArchivo); 
    }


    TEST(Tienda_Test, Test_ObtenerInformacion)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","25751238");

        // Act - ejecute la operación
        string actual = tiendaEsperada->ObtenerNombreTienda();
        string esperada = "Walmart";

        delete tiendaEsperada;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
    
}