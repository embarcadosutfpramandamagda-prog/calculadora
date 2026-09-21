# Defeitos B1 a B12 — Laboratório de Financiamento Imobiliário
**Programa:** Mestrado em Engenharia Elétrica — UTFPR  
**Disciplina:** Sistemas Embarcados  
**Dupla:** Amanda Stadler e Magda Fernandes  
**Código com Defeitos:** `src/financiamento_com_defeitos.cpp`  
**Código Corrigido:** `src/financiamento.cpp`

---

## 1. Código Original com Defeitos Propositais

```c
int calcular_financiamento_com_defeitos(bool homem, int idade, int salario) {
  if (homem) {
    if (18 < idade && idade < 35) return 75 * salario;
    else if (31 < idade && idade < 40) return 55 * salario;
    else return 30 * salario;
  } else {
    if (18 < idade && idade < 30) return 75 * salario;
    else if (31 < idade && idade < 40) return 50 * salario;
    else return 35 * salario;
  }
}
```

---

## 2. Quadro Completo dos 12 Defeitos e Correções

| Defeito | Descrição Detalhada | Categoria | Requisito Violado | Teste que Revela a Falha | Correção Aplicada |
|:---|:---|:---|:---|:---|:---|
| **B1** | Homem com 18 anos excluído da faixa jovem | Limites (`18 < idade` em vez de `18 <= idade`) | RQ-MTG-03 | `Limites.Homem18_LimiteInferiorGlobal` | `18 <= idade` |
| **B2** | Homem com 35 anos excluído da faixa jovem | Limites (`idade < 35` em vez de `idade <= 35`) | RQ-MTG-03 | `Limites.Homem35Jovem_LimiteSuperior` | `idade <= 35` |
| **B3** | Homem meia-idade começando em 32 em vez de 36 | Condição incorreta (`31 < idade`) | RQ-MTG-04 | `Limites.Homem36MeiaIdade_LimiteInferior` | Início ajustado para 36 |
| **B4** | Homem meia-idade terminando em 39 em vez de 45 | Condição incorreta (`idade < 40`) | RQ-MTG-04 | `Limites.Homem45MeiaIdade_LimiteSuperior` | `idade <= 45` |
| **B5** | Homem de 40 a 45 anos caindo no fator incorreto 30 | Consequência de B3 e B4 | RQ-MTG-04 | `Limites.Homem45MeiaIdade_LimiteSuperior` | Fator 55 aplicado a toda faixa 36–45 |
| **B6** | Mulher com 18 anos excluída da faixa jovem | Limites (`18 < idade` em vez de `18 <= idade`) | RQ-MTG-06 | `Limites.Mulher18_LimiteInferiorGlobal` | `18 <= idade` |
| **B7** | Mulher jovem recebendo fator incorreto 75 em vez de 70 | Valor de negócio incorreto | RQ-MTG-06 | `Nominal.MulherJovem_Idade25_Fator70` | `fator = 70` |
| **B8** | Mulher com 30 anos excluída da faixa jovem | Limites (`idade < 30` em vez de `idade <= 30`) | RQ-MTG-06 | `Limites.Mulher30Jovem_LimiteSuperior` | `idade <= 30` |
| **B9** | Mulher meia-idade com 31 anos excluída | Limites (`31 < idade` em vez de `31 <= idade`) | RQ-MTG-07 | `Limites.Mulher31MeiaIdade_LimiteInferior` | `31 <= idade` |
| **B10** | Mulher com 40 anos excluída da faixa meia-idade | Limites (`idade < 40` em vez de `idade <= 40`) | RQ-MTG-07 | `Limites.Mulher40MeiaIdade_LimiteSuperior` | `idade <= 40` |
| **B11** | Ausência de rejeição para idades fora de 18 a 55 anos | Prevenção (validação de domínio) | RQ-MTG-01 / R6 | `Prevencao.IdadeAbaixo18_Rejeita`, `Prevencao.IdadeAcima55_Rejeita` | `throw std::out_of_range("idade")` |
| **B12** | Ausência de rejeição para salários fora de 0 a 10.000 | Prevenção (validação de domínio) | RQ-MTG-02 / R6 | `Prevencao.SalarioNegativo_Rejeita`, `Prevencao.SalarioAcima10000_Rejeita` | `throw std::out_of_range("salario")` |

---

## 3. Lacuna de Requisitos (Ambiguidade da Especificação)

Além dos 12 defeitos de código, a especificação continha uma **lacuna proposital de requisitos**:
- O que fazer com **mulheres entre 51 e 55 anos**?
- *Tratamento adotado:* Como a especificação não definiu um fator de multiplicação para este grupo, a função rejeita a solicitação lançando `std::out_of_range("idade feminina 51-55")`, evitando decisões financeiras arbitrárias sem base legal.
