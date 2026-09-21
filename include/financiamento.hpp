#ifndef FINANCIAMENTO_HPP
#define FINANCIAMENTO_HPP

#include <stdexcept>
#include <string>
#include <cctype>

// Genero do solicitante
enum class Genero {
    Masculino,
    Feminino
};

// Funções para converter caractere ou string para o enum Genero ('M'/'F')
Genero converter_genero(char c);
Genero converter_genero(const std::string& str);

// Calcula o valor do financiamento: salario * fator
// Regras:
//   - Idade valida: 18 a 55 anos
//   - Salario valido: 0 a 10.000
//   - Entradas fora do dominio ou mulher de 51 a 55 anos lancam std::out_of_range
int calcular_financiamento(Genero genero, int idade, int salario);

#endif // FINANCIAMENTO_HPP
