# Especificação de Requisitos — Financiamento Imobiliário

**Programa:** Mestrado em Engenharia Elétrica — UTFPR  
**Disciplina:** Sistemas Embarcados  
**Dupla:** Amanda Stadler e Magda Fernandes  

---

## 1. Requisitos do Sistema (R1 a R7)

| ID | Descrição do Requisito |
|:---|:---|
| **R1** | A função deve aceitar gênero, idade e salário. |
| **R2** | A faixa de idade válida deve ser de 18 a 55 anos. |
| **R3** | A faixa de salário válida deve ser de R$ 0 a R$ 10.000. |
| **R4** | Para homens: 18 a 35 anos → fator 75; 36 a 45 anos → fator 55; 46 a 55 anos → fator 30. |
| **R5** | Para mulheres: 18 a 30 anos → fator 70; 31 a 40 anos → fator 50; 41 a 50 anos → fator 35; 51 a 55 anos → indefinido. |
| **R6** | Entradas fora do domínio definido devem ser rejeitadas lançando exceção (`std::out_of_range`). |
| **R7** | Para entradas válidas, `financiamento = salário × fator_aplicável`. |

---

## 2. Requisitos Verificáveis (Declarações Formais)

| Identificador | Declaração Verificável | Pré-condição | Pós-condição / Saída |
|:---|:---|:---|:---|
| **RQ-MTG-01** | O sistema deve rejeitar proponente com idade < 18 ou > 55 anos. | `idade < 18` ou `idade > 55` | Lança `std::out_of_range("idade")` |
| **RQ-MTG-02** | O sistema deve rejeitar proponente com salário < 0 ou > 10.000. | `salario < 0` ou `salario > 10000` | Lança `std::out_of_range("salario")` |
| **RQ-MTG-03** | O sistema deve aplicar fator 75 para homens de 18 a 35 anos. | `genero == Masculino`, `18 <= idade <= 35` | `financiamento = salario * 75` |
| **RQ-MTG-04** | O sistema deve aplicar fator 55 para homens de 36 a 45 anos. | `genero == Masculino`, `36 <= idade <= 45` | `financiamento = salario * 55` |
| **RQ-MTG-05** | O sistema deve aplicar fator 30 para homens de 46 a 55 anos. | `genero == Masculino`, `46 <= idade <= 55` | `financiamento = salario * 30` |
| **RQ-MTG-06** | O sistema deve aplicar fator 70 para mulheres de 18 a 30 anos. | `genero == Feminino`, `18 <= idade <= 30` | `financiamento = salario * 70` |
| **RQ-MTG-07** | O sistema deve aplicar fator 50 para mulheres de 31 a 40 anos. | `genero == Feminino`, `31 <= idade <= 40` | `financiamento = salario * 50` |
| **RQ-MTG-08** | O sistema deve aplicar fator 35 para mulheres de 41 a 50 anos. | `genero == Feminino`, `41 <= idade <= 50` | `financiamento = salario * 35` |
| **RQ-MTG-09** | O sistema deve rejeitar mulheres de 51 a 55 anos (lacuna de requisito). | `genero == Feminino`, `51 <= idade <= 55` | Lança `std::out_of_range("idade feminina 51-55")` |
| **RQ-MTG-10** | O sistema deve retornar 0 quando o salário for 0. | `salario == 0`, idade e gênero válidos | `financiamento = 0` |

---

## 3. Tabela de Classes de Equivalência

| Faixa Etária | Fator Homem (×) | Fator Mulher (×) | Situação |
|:---|:---|:---|:---|
| 18 a 30 anos | 75 | 70 | Válido |
| 31 a 35 anos | 75 | 50 | Válido |
| 36 a 40 anos | 55 | 50 | Válido |
| 41 a 45 anos | 55 | 35 | Válido |
| 46 a 50 anos | 30 | 35 | Válido |
| 51 a 55 anos | 30 | **INDEFINIDO** | Homem: Válido / Mulher: Rejeitado |
