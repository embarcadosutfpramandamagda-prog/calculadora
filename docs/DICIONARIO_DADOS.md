# Dicionário de Dados — Financiamento Imobiliário
**Programa:** Mestrado em Engenharia Elétrica — UTFPR  
**Disciplina:** Sistemas Embarcados  
**Dupla:** Amanda Stadler e Magda Fernandes  
**Função Principal:** `int calcular_financiamento(Genero genero, int idade, int salario)`

---

## 1. Parâmetros de Entrada

| Parâmetro | Tipo | Domínio Válido | Descrição | Violação / Exceção |
|:---|:---|:---|:---|:---|
| `genero` | `Genero` | `Genero::Masculino`, `Genero::Feminino` | Gênero do solicitante | `std::invalid_argument` via `converter_genero()` se inválido |
| `idade` | `int` | `18 ≤ idade ≤ 55` | Idade em anos | `std::out_of_range("idade")` se `< 18` ou `> 55` |
| `salario` | `int` | `0 ≤ salario ≤ 10000` | Salário mensal | `std::out_of_range("salario")` se `< 0` ou `> 10000` |

---

## 2. Tipos e Enums

### `enum class Genero`
* `Genero::Masculino`: Solicitante do gênero masculino.
* `Genero::Feminino`: Solicitante do gênero feminino.

### Funções de Conversão
* `Genero converter_genero(char c)`: Converte `'M'`/`'m'` para `Genero::Masculino` e `'F'`/`'f'` para `Genero::Feminino`.
* `Genero converter_genero(const std::string& str)`: Converte string para `Genero`.

---

## 3. Valor de Retorno

| Nome | Tipo | Expressão de Cálculo | Domínio Possível |
|:---|:---|:---|:---|
| `financiamento` | `int` | `salario * fator_aplicavel` | `0 ≤ financiamento ≤ 750.000` |

*O valor máximo teórico ocorre com `salario = 10.000` e `fator = 75`, resultando em `750.000`, dentro dos limites de um inteiro de 32 bits com sinal (`INT_MAX = 2.147.483.647`).*

---

## 4. Tratamento de Exceções

Conforme exigido pelo requisito **R6** (*"Entradas fora do domínio definido devem ser rejeitadas"*):

* `std::out_of_range("salario")`: Lançada se `salario < 0` ou `salario > 10000` (Corrige B12).
* `std::out_of_range("idade")`: Lançada se `idade < 18` ou `idade > 55` (Corrige B11).
* `std::out_of_range("idade feminina 51-55")`: Lançada para mulheres entre 51 e 55 anos (lacuna proposital da especificação).
* `std::invalid_argument`: Lançada se a entrada de gênero for diferente de M ou F.
