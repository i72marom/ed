/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m) {
	// COMPLETAR
	this->setGrado(m.getGrado());
	this->setCoeficiente(m.getCoeficiente());

	// postcondicion
	#ifndef NDEBUG
		assert((this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
		assert(this->getGrado() == getGrado());
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x) {
	// COMPLETAR
	this->setGrado(0);
	this->setCoeficiente(x);

	// postcondicion
	#ifndef NDEBUG
		assert((this->getCoeficiente() - x) < COTA_ERROR);
		assert(this->getGrado() == 0);
	#endif

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m) {
	// COMPLETAR
	int g = this->getGrado();
	double c = this->getCoeficiente();

	// se comprueba la precindicion
	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
	#endif

	this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

	// postcondicion
	#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - (c + m.getCoeficiente())) < COTA_ERROR);
		assert(g == this->getGrado());
	#endif	

	// Se devuelve el objeto actual
	return *this;
}



// COMPLETAR EL RESTO DE OPERADORES
ed::Monomio & ed::Monomio::operator-=(Monomio const &m) {
	// COMPLETAR
	int g = this->getGrado();
	double c = this->getCoeficiente();

	// se comprueba la precindicion
	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
	#endif

	this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

	// postcondicion
	#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - (c - m.getCoeficiente())) < COTA_ERROR);
		assert(g == this->getGrado());
	#endif	

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(Monomio const &m) {
	// COMPLETAR
	int g = this->getGrado();
	double c = this->getCoeficiente();

	// se comprueba la precindicion
	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
	#endif

	this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
	this->setGrado(this->getGrado() + m.getGrado());

	// postcondicion
	#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - (c * m.getCoeficiente())) < COTA_ERROR);
		assert(this->getGrado() == (g + m.getGrado()));
	#endif	

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(Monomio const &m) {
	// COMPLETAR
	int g = this->getGrado();
	double c = this->getCoeficiente();

	// se comprueba la precindicion
	#ifndef NDEBUG
		assert(grado_ >= m.getGrado());
		assert(coeficiente_ != 0.0);
	#endif

	this->setCoeficiente(this->getCoeficiente() / m.getCoeficiente());
	this->setGrado(this->getGrado() - m.getGrado());

	// postcondicion
	#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - (c / m.getCoeficiente())) < COTA_ERROR);
		assert(this->getGrado() == (g - m.getGrado()));
	#endif	

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(int const &i) {
	int g = this->getGrado();
	double c = this->getCoeficiente();	

	this->setCoeficiente(this->getCoeficiente() * i);

	// postcondicion
	#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - (c * i)) < COTA_ERROR);
		assert(this->getGrado() == g);
	#endif

	return *this;
}

ed::Monomio & ed::Monomio::operator/=(int const &i) {
	int g = this->getGrado();
	double c = this->getCoeficiente();
	
	// se comprueba la precindicion
	#ifndef NDEBUG
		assert(i != 0.0);
	#endif

	this->setCoeficiente(this->getCoeficiente() / i);

	// postcondicion
	#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - (c / i)) < COTA_ERROR);
		assert(this->getGrado() == g);
	#endif

	// Se devuelve el objeto actual
	return *this;
}




///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR

