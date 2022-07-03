#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"
#include "./../src/ExcepcionProductoNoExiste.h"

using namespace Tarea3;

    TEST(Tienda_Test, Test_AgregarProducto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","2575123");

        // Act - ejecute la operación
        Producto *producto1 = new Producto(1,"Jabon",3);
        tiendaEsperada->AgregarProducto(producto1);

        Producto *producto2 = new Producto(2,"Sandia",6);
        tiendaEsperada->AgregarProducto(producto2);

        Producto *producto3 = new Producto(3,"Banano",4);
        tiendaEsperada->AgregarProducto(producto3);

        int actual1= tiendaEsperada->TotalProductos();
        int esperada1= 3;

        delete tiendaEsperada;

        // Assert - valide los resultados
        EXPECT_EQ(esperada1, actual1);
    }


    TEST(Tienda_Test, Escribir_Leer_Archivo_Binario_Test)
    {

        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","2575123");

        Producto *producto1 = new Producto(1,"Jabon",3);
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

        std::string esperado = "Walmart\nwalmartgmail\nCartago\n2575123\n1 Jabon 3\n"; 
        std::string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        EXPECT_EQ(esperado, salidaTiendaEsperada);

        std::string salidaTiendaLeidaDeArchivo = streamSalidaTiendaEsperada.str();

        EXPECT_EQ(esperado, salidaTiendaLeidaDeArchivo); 
    }

    TEST(Tienda_Test, Test_ModificarProductoTienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","2575123");

        // Act - ejecute la operación
        Producto *producto1 = new Producto(1,"Jabon",3);
        tiendaEsperada->AgregarProducto(producto1);

        Producto *producto2 = new Producto(2,"Sandia",6);
        tiendaEsperada->AgregarProducto(producto2);

        tiendaEsperada->ModificarProductoTienda(2,3,"Banano",5);

        int actual1= producto2->ObtenerID();
        int esperada1= 3;

        std::string actual2= producto2->ObtenerNombre();
        std::string esperada2 = "Banano";

        int actual3= producto2->ObtenerExistencia();
        int esperada3= 5;

        delete tiendaEsperada;

        // Assert - valide los resultados
        EXPECT_EQ(esperada1, actual1);
        EXPECT_EQ(esperada2, actual2);
        EXPECT_EQ(esperada3, actual3);
    }

    TEST(Tienda_Test, Test_EliminarProducto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","2575123");

        // Act - ejecute la operación
        Producto *producto1 = new Producto(1,"Jabon",3);
        tiendaEsperada->AgregarProducto(producto1);

        Producto *producto2 = new Producto(2,"Sandia",6);
        tiendaEsperada->AgregarProducto(producto2);

        Producto *producto3 = new Producto(3,"Banano",4);
        tiendaEsperada->AgregarProducto(producto3);

        tiendaEsperada->EliminarProductoTienda(2);

        int actual1= tiendaEsperada->TotalProductos();
        int esperada1= 2;

        delete tiendaEsperada;

        // Assert - valide los resultados
        EXPECT_EQ(esperada1, actual1);
    }

    TEST(Tienda_Test, Test_ObtenerInformacionTienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","2575123");

        // Act - ejecute la operación

        std::string actual1= tiendaEsperada->ObtenerNombreTienda();
        std::string esperada1 = "Walmart";

        std::string actual2= tiendaEsperada->ObtenerDireccionInternet();
        std::string esperada2 = "walmartgmail";

        std::string actual3= tiendaEsperada->ObtenerDireccionFisica();
        std::string esperada3 = "Cartago";

        std::string actual4= tiendaEsperada->ObtenerTelefono();
        std::string esperada4 = "2575123";

        delete tiendaEsperada;

        // Assert - valide los resultados
        EXPECT_EQ(esperada1, actual1);
        EXPECT_EQ(esperada2, actual2);
        EXPECT_EQ(esperada3, actual3);
        EXPECT_EQ(esperada4, actual4);
    }

    TEST(Tienda_Test, Test_Excepcion_Producto_No_Existe)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Walmart","walmartgmail","Cartago","2575123");

        // Act - ejecute la operación
        Producto *producto1 = new Producto(1,"Jabon",3);
        tiendaEsperada->AgregarProducto(producto1);

        Producto *producto2 = new Producto(2,"Sandia",6);
        tiendaEsperada->AgregarProducto(producto2);

        Producto *producto3 = new Producto(3,"Banano",4);
        tiendaEsperada->AgregarProducto(producto3);

        EXPECT_THROW({
            tiendaEsperada->EliminarProductoTienda(4);
        }, ExcepcionProductoNoExiste);

        EXPECT_THROW({
            tiendaEsperada->ModificarProductoTienda(5,3,"Banano",5);
        }, ExcepcionProductoNoExiste);

        delete tiendaEsperada;

        // Assert - valide los resultados
    }

    
    
