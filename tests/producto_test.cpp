#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/producto.h"

using namespace Tarea3;

    TEST(Producto_Test, Test_ModificarProducto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto1 = new Producto(1,"Jabon",3);

        producto1->ModificarProducto(2,"Manzana",4);

        int actual1= producto1->ObtenerID();
        int esperada1= 2;

        std::string actual2= producto1->ObtenerNombre();
        std::string esperada2 = "Manzana";

        int actual3= producto1->ObtenerExistencia();
        int esperada3= 4;

        delete producto1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada1, actual1);
        EXPECT_EQ(esperada2, actual2);
        EXPECT_EQ(esperada3, actual3);
    }

    TEST(Producto_Test, Test_OperadorProducto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto1 = new Producto(1,"Jabon",3);

        std::ostringstream streamSalida {};

        streamSalida << producto1;

        std::string esperado = "1 Jabon 3";
        std::string actual = streamSalida.str();

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }