#include "financiamento.hpp"
#include <gtest/gtest.h>

// Testes nominais: casos tipicos dentro das faixas validas

// Homem jovem tipico (25 anos, fator 75)
TEST(Nominal, HomemJovem_Idade25_Fator75) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 25, 5000), 375000);
}

// Mulher jovem tipica (25 anos, fator 70)
TEST(Nominal, MulherJovem_Idade25_Fator70) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 25, 5000), 350000);
}

// Homem de meia-idade (40 anos, fator 55)
TEST(Nominal, HomemMeiaIdade_Idade40_Fator55) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 40, 1000), 55000);
}

// Mulher de meia-idade (35 anos, fator 50)
TEST(Nominal, MulherMeiaIdade_Idade35_Fator50) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 35, 1000), 50000);
}
