/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	
	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		// COMPLETAR Y MODIFICAR
		bool aux;

		if (m1.getCoeficiente() == m2.getCoeficiente() && m1.getGrado() == m2.getGrado()) aux = true;
		else aux = false;

		// postcondicion
		#ifndef NDEBUG	
			if (m1.getCoeficiente() == m2.getCoeficiente() && m1.getGrado() == m2.getGrado()) assert(aux == true);
			else assert(aux == false);
		#endif
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aux;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD
	bool operator==(ed::Monomio const & m1, int const x)
	{
		// COMPLETAR Y MODIFICAR
		bool aux;

		if (m1.getCoeficiente() == x && m1.getGrado() == 0) aux = true;
		else aux = false;

		// postcondicion
		#ifndef NDEBUG	
			if (m1.getCoeficiente() == x && m1.getGrado() == 0) assert(aux == true);
			else assert(aux == false);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aux;
	}

	bool operator==(int const x, ed::Monomio const & m1)
	{
		// COMPLETAR Y MODIFICAR
		bool aux;

		if (m1.getCoeficiente() == x && m1.getGrado() == 0) aux = true;
		else aux = false;

		// postcondicion
		#ifndef NDEBUG	
			if (m1.getCoeficiente() == x && m1.getGrado() == 0) assert(aux == true);
			else assert(aux == false);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aux;
	}


	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		// COMPLETAR Y MODIFICAR
		bool aux;

		if (m1.getCoeficiente() != m2.getCoeficiente() || m1.getGrado() != m2.getGrado()) aux = true;
		else aux = false;

		// postcondicion
		#ifndef NDEBUG	
			if (m1.getCoeficiente() != m2.getCoeficiente() || m1.getGrado() != m2.getGrado()) assert(aux == true);
			else assert(aux == false);
		#endif
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aux;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD
	bool operator!=(ed::Monomio const & m1, int const x)
	{
		// COMPLETAR Y MODIFICAR
		bool aux;

		if (m1.getCoeficiente() != x || m1.getGrado() != 0) aux = true;
		else aux = false;

		// postcondicion
		#ifndef NDEBUG	
			if (m1.getCoeficiente() != x || m1.getGrado() != 0) assert(aux == true);
			else assert(aux == false);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aux;
	}

	bool operator!=(int const x, ed::Monomio const & m1)
	{
		// COMPLETAR Y MODIFICAR
		bool aux;

		if (m1.getCoeficiente() != x || m1.getGrado() != 0) aux = true;
		else aux = false;

		// postcondicion
		#ifndef NDEBUG	
			if (m1.getCoeficiente() != x || m1.getGrado() != 0) assert(aux == true);
			else assert(aux == false);
		#endif

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aux;
	}



	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		// postcondicion
		#ifndef NDEBUG
			assert(std::abs(nuevo->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
			assert(nuevo->getGrado() == m.getGrado());
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(-m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		// postcondicion
		#ifndef NDEBUG
			assert(std::abs(nuevo->getCoeficiente() + m.getCoeficiente()) < COTA_ERROR);
			assert(nuevo->getGrado() == m.getGrado());
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		// precondicion
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m2.getGrado());
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs((m1.getCoeficiente() + m2.getCoeficiente()) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator-	 (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		// precondicion
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m2.getGrado());
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() - m2.getCoeficiente())) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	//////////////////
	// Multiplicación

	ed::Monomio & operator*	 (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() + m2.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == (m1.getGrado() + m2.getGrado()));
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * m2.getCoeficiente())) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator*	 (ed::Monomio const &m1, int const x)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * x);
		nuevo->setGrado(m1.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * x)) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator*	 (int const x, ed::Monomio const &m1)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * x);
		nuevo->setGrado(m1.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * x)) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// División

	ed::Monomio & operator/	 (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		// precondicion
		#ifndef NDEBUG
			assert(m2.getGrado() < m1.getGrado());
			assert(m2.getCoeficiente() != 0.0);
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() / m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() - m2.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == (m1.getGrado() - m2.getGrado()));
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / m2.getCoeficiente())) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/	 (ed::Monomio const &m1, int const x)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		// precondicion
		#ifndef NDEBUG
			assert(x != 0.0);
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() / x);
		nuevo->setGrado(m1.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / x)) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/	 (int const x, ed::Monomio const &m1)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		// precondicion
		#ifndef NDEBUG
			assert(m1.getCoeficiente() != 0.0);
			assert(m1.getGrado() == 0);
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() / x);
		nuevo->setGrado(m1.getGrado());
	
		// postcondicion
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / x)) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{
		// COMPLETAR
		float x;
		int y;

		stream >> x;
		m.setCoeficiente(x);

		stream >> y;
		m.setGrado(y);

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		// COMPLETAR
		stream << m.getCoeficiente() << " " << m.getGrado();

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
