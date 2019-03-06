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
		if (this->polinomio_.front().getGrado() != 0 || this->polinomio_.front().getCoeficiente() != 0.0) return false;
		return true;
	}

	/**----------------------------------------------------------
	@fn int getGrado()
	@brief Obtiene el grado del polinomio.
	@pre Los monomios están ordenados de mayor a menor grado.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline int getGrado() const {

		#ifndef NDEBUG
			std::vector <Monomio> :: iterator itPolinomio;
			for (itPolinomio = this->polinomio_.begin(); itPolinomio != this->polinomio_.end(); itPolinomio++) {
				assert(itPolinomio->getGrado() > itPolinomio+1->getGrado());
			}
		#endif

		return this->front().getGrado();
	}


	//! \name Funciones de modificación de la clase Polinomio

	// COMPLETAR


	////////////////////////////////////////////////////////////////

	//! \name Operadores de la clase Polinomio

	/**----------------------------------------------------------
	@fn Polinomio & operator=(Polinomio const &p)
	@brief Operador de asignacion que copia un polinomio en el polinomio actual 
	@param Polinomio const &p
	@pre El polinomio p debe ser diferente al polinomio actual.
	@post El polinomio actual debe ser igual al polinomio p.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Polinomio & operator=(Polinomio const &p);

	/**----------------------------------------------------------
	@fn Polinomio & operator=(Monomio const &m)
	@brief Operador de asignacion que copia un monomio en el polinomio actual 
	@param Monomio const &m
	@post El polinomio actual debe tener un unico monomio que será igual al monomio m.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Polinomio & operator=(Monomio const &m);

	/**----------------------------------------------------------
	@fn Polinomio & operator=(double const &x)
	@brief Operador de asignacion que copia un numero en el polinomio actual 
	@param double const x
	@post El polinomio actual debe ser igual al numero x.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Polinomio & operator=(double const &x);

	// Operadores aritméticos y asignación

	/**----------------------------------------------------------
	@fn 
	@brief 
	@param 
	@param 
	@pre 
	@post 
	@post 
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
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
