/*!
	\file MonomioUnittest.cpp
	\brief test de unidad de las funciones y operaciones internas y externas de la clase Monimio
*/


#include "gtest/gtest.h"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"
#include <iostream>

#define FLOAT_PRESICION 0.0003

    /////////////////
  // Constructor //
/////////////////

TEST(Monomio, default_constructor)
{
	ed::Monomio m = ed::Monomio();
	EXPECT_NEAR(m.getCoeficiente(), 0.0, FLOAT_PRESICION);
	EXPECT_EQ(m.getGrado(), 0);
}


TEST(Monomio, constructor)
{
	ed::Monomio m = ed::Monomio(1.2, 3);
	EXPECT_NEAR(m.getCoeficiente(), 1.2, FLOAT_PRESICION);
	EXPECT_EQ(m.getGrado(), 3);
}

TEST(Monomio, faulty_constructor)
{
	ed::Monomio m = ed::Monomio(-1.2, -3);
	EXPECT_NEAR(m.getCoeficiente(), -1.2, FLOAT_PRESICION);
	EXPECT_NE(m.getGrado(), -3);
	EXPECT_EQ(m.getGrado(), 0);
}

TEST(Monomio, copy_constructor)
{
	ed::Monomio m1 = ed::Monomio(1.2, 3);
	ed::Monomio m2 = ed::Monomio(m1);
	EXPECT_NEAR(m2.getCoeficiente(), m1.getCoeficiente(), FLOAT_PRESICION);
	EXPECT_EQ(m2.getGrado(), m1.getGrado());
}

    /////////////////////////
  // getters_and_setters //
/////////////////////////

TEST(Monomio, getters_and_setters)
{
	ed::Monomio m = ed::Monomio();
	m.setCoeficiente(1.2);
	m.setGrado(3);
	EXPECT_NEAR(m.getCoeficiente(), 1.2, FLOAT_PRESICION);
	EXPECT_EQ(m.getGrado(), 3);
}


TEST(Monomio, faulty_getters_and_setters)
{
	ed::Monomio m = ed::Monomio();
	m.setCoeficiente(-1.2);
	m.setGrado(-3);
	EXPECT_NEAR(m.getCoeficiente(), -1.2, FLOAT_PRESICION);
	EXPECT_EQ(m.getGrado(), 0);
}


    ///////////////
  // OPERATORS //
///////////////

// Equality

TEST(Monomio, operator_equality)
{
	ed::Monomio m1 = ed::Monomio(1, 2);
	ed::Monomio m2 = ed::Monomio(1, 2);
	ed::Monomio m3 = ed::Monomio(2, 1);
	EXPECT_TRUE(m1 == m2);
	EXPECT_FALSE(m1 == m3);
	EXPECT_EQ(m1, m2); // redundant but I like to test it
	EXPECT_NE(m1, m3);

	ed::Monomio m4 = ed::Monomio(1, 0);
	EXPECT_TRUE(m4 == 1);
	EXPECT_FALSE(m4 == 2);
	EXPECT_FALSE(m1 == 1);
	EXPECT_TRUE(1 == m4);
	EXPECT_FALSE(2 == m4);
	EXPECT_FALSE(1 == m1);
}

TEST(Monomio, operator_not_equality)
{
	ed::Monomio m1 = ed::Monomio(1, 2);
	ed::Monomio m2 = ed::Monomio(1, 2);
	ed::Monomio m3 = ed::Monomio(2, 1);
	EXPECT_FALSE(m1 != m2);
	EXPECT_TRUE(m1 != m3);

	ed::Monomio m4 = ed::Monomio(1, 0);
	EXPECT_FALSE(m4 != 1);
	EXPECT_TRUE(m4 != 2);
	EXPECT_TRUE(m1 != 1);
	EXPECT_FALSE(1 != m4);
	EXPECT_TRUE(2 != m4);
	EXPECT_TRUE(1 != m1);
}

// assignation

TEST(Monomio, operator_assignation)
{
	ed::Monomio m1 = ed::Monomio(1, 2);
	ed::Monomio m2 = ed::Monomio(3, 4);
	EXPECT_EQ(m2, (m1 = m2));
	EXPECT_EQ(m1, m2);

	ed::Monomio m3 = ed::Monomio(5, 0);
	EXPECT_EQ(m3, (m1 = 5));
}

// copy operators

TEST(Monomio, operator_plus_unary)
{
	ed::Monomio m1 = ed::Monomio(1, 2);
	ed::Monomio m2 = ed::Monomio(1, 2);
	EXPECT_EQ(m1, +m2);
}

TEST(Monomio, operator_minus_unary)
{
	ed::Monomio m1 = ed::Monomio(1, 2);
	ed::Monomio m2 = ed::Monomio(-1, 2);
	EXPECT_EQ(m1, -m2);
}

// basic operators

TEST(Monomio, operator_plus)
{
	ed::Monomio m1 = ed::Monomio(3, 2);
	ed::Monomio m2 = ed::Monomio(1, 2);
	ed::Monomio m3 = ed::Monomio(4, 2);
	EXPECT_EQ(m3, (m1 + m2));
}

TEST(Monomio, operator_minus)
{
	ed::Monomio m1 = ed::Monomio(3, 2);
	ed::Monomio m2 = ed::Monomio(1, 2);
	ed::Monomio m3 = ed::Monomio(2, 2);
	EXPECT_EQ(m3, (m1 - m2));
}

TEST(Monomio, operator_multiply)
{
	ed::Monomio m1 = ed::Monomio(5, 2);
	ed::Monomio m2 = ed::Monomio(5, 3);
	ed::Monomio m3 = ed::Monomio(25, 5);
	EXPECT_EQ(m3, (m1 * m2));

	ed::Monomio m4 = ed::Monomio(25, 2);
	EXPECT_EQ(m4, (5 * m1));
	EXPECT_EQ(m4, (m1 * 5));
}

TEST(Monomio, operator_division)
{
	ed::Monomio m1 = ed::Monomio(10, 3);
	ed::Monomio m2 = ed::Monomio(5, 2);
	ed::Monomio m3 = ed::Monomio(2, 1);
	EXPECT_EQ(m3, (m1 / m2));

	ed::Monomio m4 = ed::Monomio(2, 3);
	EXPECT_EQ(m4, (m1 / 5));

	ed::Monomio m5 = ed::Monomio(0.5, 0);
	EXPECT_EQ(m5, (5 / m1));
}

// complex operators

TEST(Monomio, operator_plus_equal)
{
	ed::Monomio m1 = ed::Monomio(10, 3);
	ed::Monomio m2 = ed::Monomio(5, 3);
	ed::Monomio m3 = ed::Monomio(15, 3);
	EXPECT_EQ(m3, (m1 += m2));
}

TEST(Monomio, operator_minus_equal)
{
	ed::Monomio m1 = ed::Monomio(10, 3);
	ed::Monomio m2 = ed::Monomio(5, 3);
	ed::Monomio m3 = ed::Monomio(5, 3);
	EXPECT_EQ(m3, (m1 -= m2));
}

TEST(Monomio, operator_multiply_equal)
{
	ed::Monomio m1 = ed::Monomio(10, 3);
	ed::Monomio m2 = ed::Monomio(5, 3);
	ed::Monomio m3 = ed::Monomio(50, 6);
	EXPECT_EQ(m3, (m1 *= m2));

	ed::Monomio m4 = ed::Monomio(10, 3);
	ed::Monomio m5 = ed::Monomio(20, 3);
	EXPECT_EQ(m5, (m4 *= 2));
}

TEST(Monomio, operator_division_equal)
{
	ed::Monomio m1 = ed::Monomio(10, 3);
	ed::Monomio m2 = ed::Monomio(5, 3);
	ed::Monomio m3 = ed::Monomio(5, 6);
	EXPECT_EQ(m3, (m1 /= m2));

	ed::Monomio m4 = ed::Monomio(10, 3);
	ed::Monomio m5 = ed::Monomio(5, 3);
	EXPECT_EQ(m5, (m4 /= 2));
}

TEST(Monomio, calcularValor)
{
	ed::Monomio m = ed::Monomio(2, 3);
	EXPECT_NEAR(m.calcularValor(5), 250, FLOAT_PRESICION);
}