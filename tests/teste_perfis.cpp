#include "financiamento.hpp"
#include <gtest/gtest.h>

// Testes de classes de equivalencia e verificacao da lacuna da especificacao

// Mulher com 51 anos: faixa sem fator na especificacao original
TEST(Perfis, MulherIdade51_LacunaRequisito_Rejeita) {
    EXPECT_THROW(calcular_financiamento(Genero::Feminino, 51, 1000), std::out_of_range);
}

// Mulher com 55 anos: limite superior da lacuna
TEST(Perfis, MulherIdade55_LacunaRequisito_Rejeita) {
    EXPECT_THROW(calcular_financiamento(Genero::Feminino, 55, 1000), std::out_of_range);
}

// Homem com 51 anos tem fator definido normalmente (fator 30)
TEST(Perfis, HomemIdade51_Fator30_Valido) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 51, 1000), 30000);
}

// Casos representativos de cada particao masculina
TEST(Perfis, HomemEC_TodasAsParticoes) {
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 20, 1000), 75000); // 18 a 35 -> fator 75
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 38, 1000), 55000); // 36 a 45 -> fator 55
    EXPECT_EQ(calcular_financiamento(Genero::Masculino, 48, 1000), 30000); // 46 a 55 -> fator 30
}

// Casos representativos de cada particao feminina valida
TEST(Perfis, MulherEC_ParticoesValidas) {
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 25, 1000), 70000); // 18 a 30 -> fator 70
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 32, 1000), 50000); // 31 a 40 -> fator 50
    EXPECT_EQ(calcular_financiamento(Genero::Feminino, 42, 1000), 35000); // 41 a 50 -> fator 35
}
