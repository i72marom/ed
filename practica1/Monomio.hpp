/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

	// COMPLETAR
		double coeficiente_;
		int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

	// COMPLETAR

	/**----------------------------------------------------------
	@fn Monomio(double coeficiente = 0.0, int grado = 0)
	@brief Constructor parametrizado con valores por defecto. Crea un nuevo monomio usando los argumentos.
	@param double coeficiente
	@param int grado
	@pre El grado es mayor o igual que 0.
	@post El coeficiente del monomio es igual al valor del parametro "coeficiente".
	@post El grado del monomio es igual al valor del parametro "grado".
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline Monomio(double coeficiente = 0.0, int grado = 0) {
		// se comprueba la precondicion
		#ifndef NDEBUG
			assert(grado >= 0);
		#endif

		// se asignan los valores
		this->setGrado(grado);
		this->setCoeficiente(coeficiente);

		// postcondicion
		#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
			assert(this->getGrado() == grado);
		#endif
	}

	/**----------------------------------------------------------
	@fn Monomio(Monomio const &m)
	@brief Constructor de copia. Crea un nuevo monomio a partir de otro.
	@param Monomio const &m
	@post El coeficiente del monomio creado es igual al coeficiente del monomio "m".
	@post El grado del monomio creado es igual al grado del monomio "m".
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline Monomio(const Monomio &m) {
		// se asignan los valores
		this->setGrado(m.getGrado());
		this->setCoeficiente(m.getCoeficiente());

		// postcondicion
		#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
			assert(this->getGrado() == m.getGrado());
		#endif
	}

	//! \name Observadores: funciones de consulta de la clase Monomio

	// COMPLETAR

	/**----------------------------------------------------------
	@fn int getGrado()
	@brief Obtiene el grado del monomio.
	@return Devuelve el grado del monomio.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline int getGrado() const { return grado_; }
	
	/**----------------------------------------------------------
	@fn int getCoeficiente()
	@brief Obtiene el coeficiente del monomio.
	@return Devuelve el coeficiente del monomio.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline double getCoeficiente() const { return coeficiente_; }

	//! \name Funciones de modificación de la clase Monomio

	// COMPLETAR

	/**----------------------------------------------------------
	@fn inline void setGrado(int const grado)
	@brief Asigna un nuevo valor al grado del monomio
	@param int const grado
	@pre el entero grado es mayor o igual a 0.
	@post El grado del monomio es igual al parametro recibido.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline void setGrado(const int grado) {
		// se comprueba la precondicion
		#ifndef NDEBUG
			assert(grado >= 0);
		#endif

		grado_ = grado;

		// postcondicion
		#ifndef NDEBUG
			assert(this->getGrado() == grado);
		#endif
	}

	/**----------------------------------------------------------
	@fn inline void setCoeficiente(const double coeficiente)
	@brief Asigna un nuevo valor al coeficiente del monomio.
	@param double const coeficiente
	@post El coeficiente del del monomio es igual al numero real coeficiente.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline void setCoeficiente(const double coeficiente) {
		coeficiente_ = coeficiente;

		#ifndef NDEBUG
			assert((this->getCoeficiente() - coeficiente) < COTA_ERROR);
		#endif	
	}

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	/**----------------------------------------------------------
	@fn Monomio & operator=(Monomio const &m);
	@brief Modifica el monomio actual con los datos del monomio "m".
	@param Monomio const &m.
	@post El coeficiente del monomio actual es igual al coeficiente del monomio "m".
	@post El grado del monomio actual es igual al grado del monomio "m".
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	/**----------------------------------------------------------
	@fn Monomio & operator=(double const &x);
	@brief Modifica el monomio actual para que su grado sea 0 y su coeficiente el numero real x.
	@param int const &x.
	@post El coeficiente del monomio actual es igual al numero real x.
	@post El grado del monomio actual es igual 0.
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/**----------------------------------------------------------
	@fn Monomio & operator+=(Monomio const &m);
	@brief Modifica el monomio sumandole otro de igual grado.
	@param Monomio const &m
	@pre El monomio "m" tiene el mismo grado que el actual.
	@post El coeficiente del monomio actual se ha incrementado con el coeficiente de "m".
	@post El grado del monomio actual no se ha modificado.
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator+=(Monomio const &m);


	// COMPLETAR EL RESTO DE OPERADORES

	/**----------------------------------------------------------
	@fn Monomio & operator-=(Monomio const &m);
	@brief Modifica el monomio restandole otro de igual grado.
	@param Monomio const &m
	@pre El monomio "m" tiene el mismo grado que el actual.
	@post El coeficiente del monomio actual se ha decrementado con el coeficiente de "m".
	@post El grado del monomio actual no se ha modificado.
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator-=(Monomio const &m);

	/**----------------------------------------------------------
	@fn Monomio & operator*=(Monomio const &m);
	@brief Modifica el monomio multiplicandolo por otro.
	@param Monomio const &m
	@post El coeficiente del monomio actual se ha multiplicado por el coeficiente de "m".
	@post El grado del monomio actual se ha incrementado con el grado de "m".
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator*=(Monomio const &m);

	/**----------------------------------------------------------
	@fn Monomio & operator*=(Monomio const &m);
	@brief Modifica el monomio dividiendolo por otro.
	@param Monomio const &m
	@post El coeficiente del monomio actual se ha dividido por el coeficiente de "m".
	@post El grado del monomio actual se ha decrementado con el grado de "m".
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator/=(Monomio const &m);
	
	/**----------------------------------------------------------
	@fn Monomio & operator*=(int const &i);
	@brief Modifica el monomio actual multiplicandolo por un numero real.
	@param int const &i
	@post El coeficiente del monomio actual se ha multiplicado por el numero real i.
	@post El grado del monomio actual no se ha modificado.
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator*=(int const &i);
	
	/**----------------------------------------------------------
	@fn Monomio & operator/=(int const &i);
	@brief Modifica el monomio actual dividiendolo por un numero real.
	@param int const &i
	@pre El numero real i no es 0.0.
	@post El coeficiente del monomio actual se ha dividido por el numero real i.
	@post El grado del monomio actual no se ha modificado.
	@return Devuelve el monomio actual.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	Monomio & operator/=(int const &i);


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	// COMPLETAR
	
	/**----------------------------------------------------------
	@fn void leerMonomio()
	@brief Lee desde el teclado los atributos del monomio.
	@post El grado del monomio es mayor o igual a 0.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline void leerMonomio() {
		std::cout << "Introduce el coeficiente del Monomio: ";
		std::cin >> coeficiente_;
		std::cout << "Introduce el grado del Monomio: ";
		std::cin >> grado_;

		// postcondicion
		#ifndef NDEBUG
			assert(this->getGrado() >= 0);
		#endif
	}

	/**----------------------------------------------------------
	@fn void escribirMonomio()
	@brief Escribe por pantalla los atributos del monomio con el formato coeficiente X ^ grado.
	@return 
	@author Manuel Mariscal

	Notas:
		- Si el coeficiente es 1 entonces se escribirá X^grado.
		- Si el coeficiente es -1 entonces se escribirá -X^grado.
		- Si el grado es 0 entonces se escribirá solo el coeficiente.
		- Si el grado es 1 entonces se escribirá X pero sin grado
		
	----------------------------------------------------------*/
	inline void escribirMonomio() {
		if (grado_ == 0) std::cout << coeficiente_ << std::endl;
		
		else {
			if (coeficiente_ == -1) std::cout << "-";
			else if (coeficiente_ != 1) std::cout << coeficiente_;
			std::cout << "X";
			if (grado_ != 1) std::cout << "^" << grado_;
		}
	}


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	// COMPLETAR

	/**----------------------------------------------------------
	@fn double calcularValor(double valor)
	@brief Calcula el valor del monomio para un numero real.
	@param double valor
	@return Devuelve el valor del monomio.
	@author Manuel Mariscal
		
	----------------------------------------------------------*/
	inline double calcularValor(double valor) {
		valor = pow(valor, grado_);
		valor *= coeficiente_;

		return valor;
	}


};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
