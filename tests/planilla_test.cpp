#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/planilla.h"

using namespace std;

namespace
{
    TEST(Planilla_Test, Escribir_Leer_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Planilla *planillaEsperada = new Planilla();

        Empleado *empleado1 = new Empleado(1, 20, "Pedro");
        planillaEsperada->AgregarEmpleado(empleado1);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("archivo_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
            FAIL();
        }

        planillaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Planilla *planillaLeida = new Planilla();
        planillaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        ostringstream streamSalidaPlanillaLeida;
        streamSalidaPlanillaLeida << planillaLeida;

        ostringstream streamSalidaPlanillaEsperada;
        streamSalidaPlanillaEsperada << planillaEsperada;

        delete planillaLeida;
        delete planillaEsperada;

        string esperado = "Planilla: \n[1] - Pedro 20\n"; 
        string salidaPlanillaEsperada = streamSalidaPlanillaEsperada.str();

        // Primero, validar la salida de la planilla esperada sea correcta
        EXPECT_EQ(esperado, salidaPlanillaEsperada);

        string salidaPlanillaLeidaDeArchivo = streamSalidaPlanillaEsperada.str();
        EXPECT_EQ(esperado, salidaPlanillaLeidaDeArchivo);
    }
    
}