/* 
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los m�todos de b�squeda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un m�todo de b�squeda,
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente con ajuste al Orden de complejidad.
 * 3. Comparar el coste temporal de dos m�todos de b�squeda
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente.
 */
#include "TestBusqueda.h"
#include "Constantes.h"
#include "AlgoritmosBusqueda.h"
#include "AlgoritmosOrdenacion.h"
#include "ConjuntoInt.h"
#include "Graficas.h"
#include "Mtime.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

TestBusqueda::TestBusqueda()
{
	nombreAlgoritmo.push_back("SecuencialI");
	complegidadAlgoritmo.push_back(AXpB);
	nombreAlgoritmo.push_back("BinariaR");
	complegidadAlgoritmo.push_back(logN);
	nombreAlgoritmo.push_back("TernariaR");
	complegidadAlgoritmo.push_back(logN);
} 
TestBusqueda::~TestBusqueda()
{
}

/*
 * Busca en un array de enteros seg�n el m�todo indicado
 * param v: el array de enteros a ordenar
 * param size: tama�o del array de enteros a ordenar
 * param metodo: Metodo de b�squeda a utilizar
 * return Tiempo empleado en la busqueda (en milisegundos)
 */
double TestBusqueda::buscaEnArrayDeInt(int key,int v[],int size,int metodo,int &posicion) 
{
    AlgoritmosBusqueda strategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	// Invoca al m�todo de b�squeda elegido
	QueryPerformanceCounter(&t_inicial);
    switch (metodo)	{
		case SECUENCIALIt: posicion=strategia.busquedaSecuencialIt(v, size, key);
            break;
		case BINARIARc: posicion=strategia.busquedaBinariaRc(v, size, key); 
            break;
		case TERNARIARc: posicion=strategia.busquedaTernariaRc(v, size, key); 
            break;
	}
	QueryPerformanceCounter(&t_final);
    return t.performancecounter_diff(&t_final, &t_inicial) * 1000000;   
}

/*
 * Comprueba los metodos de b�squeda
 */
void TestBusqueda::comprobarMetodosBusqueda(){
	int talla, clave, pos;
	cout << endl << endl << "Introduce la talla: ";
	cin >> talla;

	int antiguoCaso = ConjuntoInt::getCaso();
	ConjuntoInt::setCaso(MEJOR);/// De lo contrario la busqueda binaria no funcionaria
	ConjuntoInt *v = new ConjuntoInt(talla);
	v->GeneraVector(talla);
	cout << endl << endl << "Vector aleatorio: " << endl << endl;
	v->escribe();

	cout << endl << endl << "Introduce la clave de busqueda: ";
	cin >> clave;
	system("cls");
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		double secs = buscaEnArrayDeInt(clave, v->getDatos(), talla, metodo, pos);
		cout << endl << endl << "Tiempo empleado por " << nombreAlgoritmo[metodo] << ": " << secs << endl;
		if (pos == -1)
			cout << "La clave no se encuentra en el vector.";
		else cout << "Posicion de la clave: " << pos+1;
		cout << endl << endl;
	} /* fin del for */
	delete v;
	ConjuntoInt::setCaso(antiguoCaso);
	system("pause");
	system("cls");
}
    
/*
 * Compara dos metodos de b�squeda. 
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param metodo1: Primer metodo de b�squeda a comparar
 * param metodo2: Segundo metodo de b�squeda a comparar
 */
void TestBusqueda::comparar(int metodo1, int metodo2) 
{
   //** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
}
/*
 * Calcula el caso medio de un metodo de b�squeda,
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param metodo: metodo de b�squeda a estudiar.
 */
void TestBusqueda::casoMedio(int metodo)
{
   //** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
}	

void TestBusqueda::compararTodos()
{
	//** ESCRIBIR PARA COMPLETAR LA PRACTICA **//
}