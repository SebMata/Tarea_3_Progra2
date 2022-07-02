#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"

using namespace Tarea3;


    TEST(Tienda_Test, Escribir_Leer_Archivo_Binario_Test)
    {

        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","25751238");

        Producto *producto1 = new Producto(1,"Jabón",3);
        tiendaEsperada->AgregarProducto(producto1);

        std::ofstream archivoSalida;
        archivoSalida.open("archivo_test.dat", std::ios::out|std::ios::binary);

        if (!archivoSalida.is_open())
        {
            std::cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        std::ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", std::ios::in|std::ios::binary);

        if (!archivoEntrada.is_open())
        {
            std::cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Tienda *tiendaLeida = new Tienda();
        tiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        std::ostringstream streamSalidaTiendaLeida;
        streamSalidaTiendaLeida << tiendaLeida;

        std::ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaLeida;
        delete tiendaEsperada;

        std::string esperado = "Walmart\nwalmartgmail\nCartago\n25751238\n1 Jabón 3\n"; 
        std::string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        std::cout << salidaTiendaEsperada << std::endl;
        

        EXPECT_EQ(esperado, salidaTiendaEsperada);

        std::string salidaTiendaLeidaDeArchivo = streamSalidaTiendaEsperada.str();

        std::cout << salidaTiendaLeidaDeArchivo << std::endl;
        EXPECT_EQ(esperado, salidaTiendaLeidaDeArchivo); 
    }


    TEST(Tienda_Test, Test_ObtenerInformacion)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","25751238");

        // Act - ejecute la operación
        std::string actual = tiendaEsperada->ObtenerNombreTienda();
        std::string esperada = "Walmart";

        delete tiendaEsperada;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }
    
