/*!
\file Polinomio.hpp
\brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz {

	//! \name Atributos privados de la clase Polinomio
	private:
		std::vector <Monomio> polinomio_;

	// COMPLETAR

	//! \name Funciones o métodos públicos de la clase Polinomio
	public:

	//! \name Constructores de la clase Polinomio

	/**----------------------------------------------------------
	@fn Polinomio()
	@brief Crea un nuevo monomio usando el coeficiente 0.0 y el grado 0.
	@post El polinomio creado es nulo.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline Polinomio() {
		Monomio m;

		// se comprueba la postcondicion
		#ifndef NDEBUG
			assert(this->esNulo());
		#endif
	}

	/**----------------------------------------------------------
	@fn Polinomio(Polinomio p)
	@brief Crea un nuevo polinomio a partir de otro polinomio.
	@post El polinomio creado es igual al polinomio p.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
/*	inline Polinomio(Polinomio &p) {
		

		// se comprueba la postcondicion
		#ifndef NDEBUG
			assert(this->esNulo());
		#endif
	}*/

	//! \name Observadores: funciones de consulta de la clase Polinomio

	/**----------------------------------------------------------
	@fn bool esNulo()
	@brief Comprueba si un polinomio es igual al monomio de coeficiente 0.0 y grado 0.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline bool esNulo() const {
	//	ed::Monomio m(this->polinomio_.front());

		if (this->polinomio_.front().getGrado() != 0 || this->polinomio_.front().getCoeficiente() != 0.0) return false;
		return true;
	}




	//! \name Funciones de modificación de la clase Polinomio

	// COMPLETAR


	////////////////////////////////////////////////////////////////

	//! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

	// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);


	// COMPLETAR EL RESTO DE OPERADORES


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

	// COMPLETAR


	}; // Fin de la definición de la clase Polinomio




	} // \brief Fin de namespace ed.

	//  _POLINOMIO_HPP_
	#endif
