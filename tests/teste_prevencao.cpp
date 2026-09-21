#include "financiamento.hpp"
#include <gtest/gtest.h>

// Testes de robustez: verificacao de entradas fora do dominio valido

// Idade abaixo de 18 anos deve ser rejeitada
TEST(Prevencao, IdadeAbaixo18_Rejeita) {
    EXPECT_THROW(calcular_financiamento(Genero::Masculino, 17, 5000), std::out_of_range);
}

// Idade acima de 55 anos deve ser rejeitada
TEST(Prevencao, IdadeAcima55_Rejeita) {
    EXPECT_THROW(calcular_financiamento(Genero::Feminino, 56, 5000), std::out_of_range);
}

// Salario negativo deve ser rejeitado
TEST(Prevencao, SalarioNegativo_Rejeita) {
    EXPECT_THROW(calcular_financiamento(Genero::Masculino, 25, -1), std::out_of_range);
}

// Salario acima de 10.000 deve ser rejeitado
TEST(Prevencao, SalarioAcima10000_Rejeita) {
    EXPECT_THROW(calcular_financiamento(Genero::Masculino, 25, 10001), std::out_of_range);
}

// Salario zero e valido e resulta em financiamento 0
TEST(Prevencao, SalarioZero_EValido) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 25, 0), 0);
}
