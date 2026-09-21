#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include "financiamento.hpp"

int main() {
    std::cout << "Simulador de Financiamento - UTFPR\n";
    std::cout << "Calculo: salario * fator = financiamento\n\n";

    while (true) {
        try {
            std::string entrada_genero;
            std::cout << "Genero [M/F] (ou 'S' para sair): ";
            if (!(std::cin >> entrada_genero)) break;

            if (entrada_genero == "S" || entrada_genero == "s" ||
                entrada_genero == "sair" || entrada_genero == "SAIR") {
                std::cout << "Encerrando.\n";
                break;
            }

            Genero g = converter_genero(entrada_genero);

            int idade;
            std::cout << "Idade: ";
            if (!(std::cin >> idade)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n[Entrada Invalida] Informe uma idade numerica valida.\n\n";
                continue;
            }

            int salario;
            std::cout << "Salario mensal: ";
            if (!(std::cin >> salario)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n[Entrada Invalida] Informe um salario numerico valido.\n\n";
                continue;
            }

            int resultado = calcular_financiamento(g, idade, salario);
            int fator = (salario > 0) ? (resultado / salario) : 0;
            if (salario == 0) {
                if (g == Genero::Masculino) {
                    fator = (idade <= 35) ? 75 : ((idade <= 45) ? 55 : 30);
                } else {
                    fator = (idade <= 30) ? 70 : ((idade <= 40) ? 50 : 35);
                }
            }

            std::cout << "\n[Proposta Aprovada]\n";
            std::cout << "-> Fator aplicado: x" << fator << "\n";
            std::cout << "-> Financiamento concedido: R$ " << resultado << "\n";
            std::cout << "-> Calculo: R$ " << salario << " x " << fator << " = R$ " << resultado << "\n\n";

        } catch (const std::out_of_range& e) {
            std::string msg = e.what();
            if (msg.find("negativo") != std::string::npos || msg.find("negativa") != std::string::npos) {
                std::cout << "\n[Entrada Invalida] " << msg << "\n\n";
            } else {
                std::cout << "\n[Fora da Cobertura] " << msg << "\n\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "\n[Entrada Invalida] " << e.what() << "\n\n";
        } catch (const std::exception& e) {
            std::cout << "\n[Erro] " << e.what() << "\n\n";
        }
    }

    return 0;
}
