#include "financiamento.hpp"

Genero converter_genero(char c) {
    char maiusculo = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    if (maiusculo == 'M') return Genero::Masculino;
    if (maiusculo == 'F') return Genero::Feminino;
    throw std::invalid_argument("Gênero inválido. Utilize 'M' (Masculino) ou 'F' (Feminino).");
}

Genero converter_genero(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("Gênero não pode ser vazio.");
    }
    return converter_genero(str[0]);
}

int calcular_financiamento(Genero genero, int idade, int salario) {
    // Validacao do salario (R$ 0 a R$ 10.000)
    if (salario < 0) {
        throw std::out_of_range("Salario nao pode ser negativo.");
    }
    if (salario > 10000) {
        throw std::out_of_range("Salario acima de R$ 10.000,00 esta fora da faixa de cobertura.");
    }

    // Validacao da idade (18 a 55 anos)
    if (idade < 0) {
        throw std::out_of_range("Idade nao pode ser negativa.");
    }
    if (idade < 18) {
        throw std::out_of_range("Idade abaixo de 18 anos esta fora da faixa minima de cobertura.");
    }
    if (idade > 55) {
        throw std::out_of_range("Idade acima de 55 anos para homens esta fora da faixa maxima de cobertura.");
    }

    int fator;

    if (genero == Genero::Masculino) {
        // Regras para homens
        if (idade <= 35) {
            fator = 75;
        } else if (idade <= 45) {
            fator = 55;
        } else {
            fator = 30; // 46 a 55 anos
        }
    } else {
        // Regras para mulheres
        if (idade <= 30) {
            fator = 70;
        } else if (idade <= 40) {
            fator = 50;
        } else if (idade <= 50) {
            fator = 35;
        } else {
            // Mulheres de 51 a 55 anos: a especificacao original nao definiu fator
            throw std::out_of_range("Idade acima de 50 anos para mulheres esta fora da faixa maxima de cobertura.");
        }
    }

    // Calculo: salario * fator
    return salario * fator;
}
