/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	/**----------------------------------------------------------
	@fn bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	@brief Comprueba si dos monomios son iguales.
	@param ed::Monomio const & m1
	@param ed::Monomio const & m2
	@post El valor devuelto es verdadero si los dos monomios tienen el mismo grado y coeficiente, y falso en caso contrario.
	@return Un valor de tipo bool.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);


	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD
	
	/**----------------------------------------------------------
	@fn bool operator==(ed::Monomio const & m1, int const x)
	@brief Comprueba si un monomio es igual a un numero real.
	@param ed::Monomio const & m1
	@param int const x
	@post El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al numero x, y falso en caso contrario.
	@return Un valor de tipo bool.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	bool operator==(ed::Monomio const & m1, int const x);
	
	/**----------------------------------------------------------
	@fn bool operator==(int const x, ed::Monomio const & m1)
	@brief Comprueba si un monomio es igual a un numero real.
	@param int const x
	@param ed::Monomio const & m1
	@post El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al numero x, y falso en caso contrario.
	@return Un valor de tipo bool.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	bool operator==(int const x, ed::Monomio const & m1);

	//! \name Operadores de desigualdad 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	
	/**----------------------------------------------------------
	@fn bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	@brief Comrueba si dos monomios no son iguales.
	@param ed::Monomio const & m1
	@param ed::Monomio const & m2
	@post El valor es verdadero si los dos monomios no tienen el mismo grado o no tienen el mismo coeficiente.
	@return Un valor de tipo bool.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD
	
	/**----------------------------------------------------------
	@fn bool operator!=(ed::Monomio const & m1, int const x)
	@brief Comrueba si un monomio y un numero real no son iguales.
	@param ed::Monomio const & m1
	@param  int const x
	@post El valor devuelto es verdadero si el monomio no tiene grado 0 o su coeficiente no es igual al numero x.
	@return Un valor de tipo bool.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	bool operator!=(ed::Monomio const & m1, int const x);
	
	/**----------------------------------------------------------
	@fn bool operator!=(int const x, ed::Monomio const & m1)
	@brief Comrueba si un monomio y un numero real no son iguales.
	@param  int const x
	@param ed::Monomio const & m1
	@post El valor devuelto es verdadero si el monomio no tiene grado 0 o su coeficiente no es igual al numero x.
	@return Un valor de tipo bool.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	bool operator!=(int const x, ed::Monomio const & m1);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	/**----------------------------------------------------------
	@fn ed::Monomio & operator+(ed::Monomio const & m)
	@brief Operador aritmetico unario prefijo +
	@param ed::Monomio const & m
	@post El monomio devuelto es igual al monomio m. Es decir, tienen el mismo grado y coeficiente.
	@return Devuelve una copia del monomio m.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator+(ed::Monomio const & m);

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator-(ed::Monomio const & m)
	@brief Operador aritmetico unario prefijo -
	@param ed::Monomio const & m
	@post El monomio devuelto tiene el mismo grado que el monomio m, pero su coeficiente es opuesto.
	@return Devuelve el opuesto del monomio m.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator-(ed::Monomio const & m);

	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	@brief operador aritmetico binario +.
	@param ed::Monomio const &m1
	@param ed::Monomio const &m2
	@pre Los monomios tienen el mismo grado.
	@post El monomio devuelto tiene el mismo grado que los monomios m1 y m2.
	@post El coeficiente del monomio devuelto es la suma de los coeficientes de los monomios.
	@return Devuelve otro monomio que es la suma de dos monomios.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	@brief operador aritmetico binario -.
	@param ed::Monomio const &m1
	@param ed::Monomio const &m2
	@pre Los monomios tienen el mismo grado.
	@post El monomio devuelto tiene el mismo grado que los monomios m1 y m2.
	@post El coeficiente del monomio devuelto es la resta de los coeficientes de los monomios.
	@return Devuelve otro monomio que es la resta de dos monomios.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);

	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	@brief operador aritmetico binario *.
	@param ed::Monomio const &m1
	@param ed::Monomio const &m2
	@post El monomio devuelto tiene el un grado que es la suma de los monomios m1 y m2.
	@post El coeficiente del monomio devuelto es el producto de los coeficientes de los monomios.
	@return Devuelve otro monomio que es el producto de dos monomios.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator* (ed::Monomio const &m1, int const x)
	@brief operador aritmetico binario *.
	@param ed::Monomio const &m1
	@param int const x
	@post El monomio devuelto tiene el mismo grado que el monomio m1.
	@post El coeficiente del monomio devuelto es el producto del coeficiente del monomio por un numero real.
	@return Devuelve otro monomio que es el producto de un monomio por un numero real.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator* (int const x, ed::Monomio const &m1);
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator* (ed::Monomio const &m1, int const x)
	@brief operador aritmetico binario *.
	@param int const x
	@param ed::Monomio const &m1
	@post El monomio devuelto tiene el mismo grado que el monomio m1.
	@post El coeficiente del monomio devuelto es el producto del coeficiente del monomio por un numero real.
	@return Devuelve otro monomio que es el producto de un monomio por un numero real.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator* (int const x, ed::Monomio const &m1);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	@brief operador aritmetico binario /.
	@param ed::Monomio const &m1
	@param ed::Monomio const &m2
	@pre El grado del m2 es menor o igual que el grado del monomio m1.
	@pre El coeficiente del m2 no es 0.0.
	@post El monomio devuelto tiene el un grado que es la resta de los monomios m1 y m2.
	@post El coeficiente del monomio devuelto es el cociente de los coeficientes de los monomios.
	@return Devuelve otro monomio que es la division de dos monomios.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator/ (ed::Monomio const &m1, int const x)
	@brief operador aritmetico binario /.
	@param ed::Monomio const &m1
	@param int const x
	@pre El numero real no es 0.0.
	@post El monomio devuelto tiene el mismo grado que el monomio m1.
	@post El coeficiente del monomio devuelto es el cociente del coeficiente del monomio entre el numero real.
	@return Devuelve otro monomio que es la division de m por el numero x.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator/ (ed::Monomio const &m1, int const x);
	
	/**----------------------------------------------------------
	@fn ed::Monomio & operator/ (int const x, ed::Monomio const &m1)
	@brief operador aritmetico binario /.
	@param int const x
	@param ed::Monomio const &m1
	@pre El grado del monomio es 0 y su coeficiente distinto de 0.0.
	@post El monomio devuelto tiene grado igual a 0.
	@post El coeficiente del monomio devuelto es el cociente del coeficiente del monomio entre el numero real.
	@return Devuelve otro monomio que es la division de x por el monomio.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ed::Monomio & operator/ (int const x, ed::Monomio const &m1);

	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	
	/**----------------------------------------------------------
	@fn istream &operator>>(istream &stream, ed::Monomio &m)
	@brief Sobrecarga del operador del flujo de entrada. Lee desde el flujo de entrada los atributos de un monomio separados por espacios.
	@param istream &stream
	@param ed::Monomio &m
	@return devuelve el flujo de entrada.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	
	/**----------------------------------------------------------
	@fn ostream &operator<<(ostream &stream, ed::Monomio const &m)
	@brief Sobrecarga del operador del flujo de salida. Escribe en el flujo de salida los atributos del monomio separados por espacios.
	@param ostream &stream
	@param ed::Monomio const &m
	@return devuelve el flujo de salida.
	@author Manuel Mariscal

	----------------------------------------------------------*/
	ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


