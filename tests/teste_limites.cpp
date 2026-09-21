#include "financiamento.hpp"
#include <gtest/gtest.h>

// Testes de fronteira: analise dos limites das faixas etarias

// Homem no limite da faixa jovem (35 anos, fator 75)
TEST(Limites, Homem35Jovem_LimiteSuperior) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 35, 5000), 375000);
}

// Homem no inicio da meia-idade (36 anos, fator 55)
TEST(Limites, Homem36MeiaIdade_LimiteInferior) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 36, 5000), 275000);
}

// Homem no final da meia-idade (45 anos, fator 55)
TEST(Limites, Homem45MeiaIdade_LimiteSuperior) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 45, 1), 55);
}

// Homem no inicio da faixa senior (46 anos, fator 30)
TEST(Limites, Homem46Senior_LimiteInferior) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 46, 1), 30);
}

// Mulher no limite da faixa jovem (30 anos, fator 70)
TEST(Limites, Mulher30Jovem_LimiteSuperior) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 30, 5000), 350000);
}

// Mulher no inicio da meia-idade (31 anos, fator 50)
TEST(Limites, Mulher31MeiaIdade_LimiteInferior) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 31, 5000), 250000);
}

// Mulher no final da meia-idade (40 anos, fator 50)
TEST(Limites, Mulher40MeiaIdade_LimiteSuperior) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 40, 1), 50);
}

// Mulher no inicio da faixa seguinte (41 anos, fator 35)
TEST(Limites, Mulher41Senior_LimiteInferior) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 41, 1), 35);
}

// Limite inferior global: 18 anos homem
TEST(Limites, Homem18_LimiteInferiorGlobal) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 18, 5000), 375000);
}

// Limite inferior global: 18 anos mulher
TEST(Limites, Mulher18_LimiteInferiorGlobal) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 18, 5000), 350000);
}

// Limite superior global: 55 anos homem (fator 30)
TEST(Limites, Homem55_LimiteSuperiorGlobal) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 55, 10000), 300000);
}

// Limite superior valido para mulher: 50 anos (fator 35)
TEST(Limites, Mulher50_LimiteSuperiorValido) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 50, 10000), 350000);
}
