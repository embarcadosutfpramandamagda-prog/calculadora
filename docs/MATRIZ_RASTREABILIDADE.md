# Matriz de Rastreabilidade — Financiamento Imobiliário
**Programa:** Mestrado em Engenharia Elétrica — UTFPR  
**Disciplina:** Sistemas Embarcados  
**Dupla:** Amanda Stadler e Magda Fernandes  

---
| Requisito | Oráculo | Caso de Teste (Suíte.Nome) | Técnica de Teste | Saída Esperada |
|:---|:---|:---|:---|:---|
| RQ-MTG-03 | T01 | `Nominal.HomemJovem_Idade25_Fator75` | Nominais (Casos Típicos) | 375.000 |
| RQ-MTG-06 | – | `Nominal.MulherJovem_Idade25_Fator70` | Nominais (Casos Típicos) | 350.000 |
| RQ-MTG-04 | – | `Nominal.HomemMeiaIdade_Idade40_Fator55` | Nominais (Casos Típicos) | 55.000 |
| RQ-MTG-07 | – | `Nominal.MulherMeiaIdade_Idade35_Fator50` | Nominais (Casos Típicos) | 50.000 |
| RQ-MTG-03 | T02 | `Limites.Homem35Jovem_LimiteSuperior` | Limites (Valor Limite) | 375.000 |
| RQ-MTG-04 | T03 | `Limites.Homem36MeiaIdade_LimiteInferior` | Limites (Valor Limite) | 275.000 |
| RQ-MTG-04 | T06 | `Limites.Homem45MeiaIdade_LimiteSuperior` | Limites (Valor Limite) | 55 |
| RQ-MTG-05 | T07 | `Limites.Homem46Senior_LimiteInferior` | Limites (Valor Limite) | 30 |
| RQ-MTG-06 | T04 | `Limites.Mulher30Jovem_LimiteSuperior` | Limites (Valor Limite) | 350.000 |
| RQ-MTG-07 | T05 | `Limites.Mulher31MeiaIdade_LimiteInferior` | Limites (Valor Limite) | 250.000 |
| RQ-MTG-07 | T08 | `Limites.Mulher40MeiaIdade_LimiteSuperior` | Limites (Valor Limite) | 50 |
| RQ-MTG-08 | T09 | `Limites.Mulher41Senior_LimiteInferior` | Limites (Valor Limite) | 35 |
| RQ-MTG-01 | – | `Limites.Homem18_LimiteInferiorGlobal` | Limites (Limite Global) | 375.000 |
| RQ-MTG-01 | – | `Limites.Mulher18_LimiteInferiorGlobal` | Limites (Limite Global) | 350.000 |
| RQ-MTG-05 | – | `Limites.Homem55_LimiteSuperiorGlobal` | Limites (Limite Global) | 300.000 |
| RQ-MTG-08 | – | `Limites.Mulher50_LimiteSuperiorValido` | Limites (Limite Válido Feminino) | 350.000 |
| RQ-MTG-01 | T10 | `Prevencao.IdadeAbaixo18_Rejeita` | Prevenção (Idade Inválida) | Exceção `out_of_range` |
| RQ-MTG-01 | T11 | `Prevencao.IdadeAcima55_Rejeita` | Prevenção (Idade Inválida) | Exceção `out_of_range` |
| RQ-MTG-02 | – | `Prevencao.SalarioNegativo_Rejeita` | Prevenção (Salário Inválido) | Exceção `out_of_range` |
| RQ-MTG-02 | T12 | `Prevencao.SalarioAcima10000_Rejeita` | Prevenção (Salário Inválido) | Exceção `out_of_range` |
| RQ-MTG-10 | – | `Prevencao.SalarioZero_EValido` | Prevenção (Limite Zero Válido) | 0 |
| RQ-MTG-09 | – | `Perfis.MulherIdade51_LacunaRequisito_Rejeita` | Perfis (Lacuna de Requisito) | Exceção `out_of_range` |
| RQ-MTG-09 | – | `Perfis.MulherIdade55_LacunaRequisito_Rejeita` | Perfis (Lacuna de Requisito) | Exceção `out_of_range` |
| RQ-MTG-05 | – | `Perfis.HomemIdade51_Fator30_Valido` | Perfis (Faixa Sênior Homem) | 30.000 |
| RQ-MTG-03..05 | – | `Perfis.HomemEC_TodasAsParticoes` | Perfis (Partições Homem) | 75.000, 55.000, 30.000 |
| RQ-MTG-06..08 | – | `Perfis.MulherEC_ParticoesValidas` | Perfis (Partições Mulher) | 70.000, 50.000, 35.000 |

**Total:** 26 casos de teste automatizados com rastreabilidade direta aos requisitos.
