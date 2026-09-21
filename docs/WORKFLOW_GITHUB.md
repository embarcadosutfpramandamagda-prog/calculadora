# Guia de Workflow do GitHub & Rastreabilidade
**Programa:** Mestrado em Engenharia Elétrica — UTFPR  
**Disciplina:** Sistemas Embarcados  
**Dupla:** Amanda Stadler e Magda Fernandes  
**Repositório Oficial:** `mortgage-testing-lab`

---

## 1. Princípio de Rastreabilidade

> *"Use version control to make the reasoning auditable — not just to store the final answer."*  
> — Slide 17 / 19

O fluxo completo conecta cada elemento do ciclo de vida:
$$\text{Requirement (RQ-MTG-xx)} \longrightarrow \text{Test ID (T01..T12)} \longrightarrow \text{GitHub Issue} \longrightarrow \text{Branch} \longrightarrow \text{Commit} \longrightarrow \text{PR} \longrightarrow \text{CI Result}$$

---

## 2. Estrutura de Branches Recomendada pelo Professor

| Branch | Finalidade | Regra |
|--------|------------|-------|
| `main` | Código de entrega oficial (versão corrigida) | Protegida; apenas merges via PR após CI verde |
| `buggy-baseline` | Código original fornecido pelo professor com os 12 bugs | Referência imutável do laboratório |
| `test/boundaries` | Adição de testes de limites antes das correções | Revela as falhas em vermelho (RED) |
| `fix/age-boundaries` | Correção dos limites e transições de faixa etária | Corrige B1 a B10 |
| `fix/input-validation` | Adição das validações de domínio de idade e salário | Corrige B11 e B12 |

---

## 3. Padrão de Commits com Rastreabilidade

Cada commit deve referenciar o requisito afetado seguindo o padrão Conventional Commits com identificador:

```bash
# Exemplo 1: Adicionando teste de fronteira
git commit -m "test(RQ-MTG-06): add female 30/31 boundary tests [T04, T05]"

# Exemplo 2: Corrigindo off-by-one de fronteira
git commit -m "fix(RQ-MTG-06): correct inclusive female young range (<= 30) fixing B8"

# Exemplo 3: Rejeição de domínio
git commit -m "test(RQ-MTG-01): reject age outside [18,55] with std::out_of_range [T10, T11]"
git commit -m "fix(RQ-MTG-01): add domain check for age [18..55] fixing B11"
```

---

## 4. Fluxo de Pull Requests & Code Review

1. **Abrir uma Issue** no GitHub para o defeito ou requisito (ex: `Issue #3: Defeito B7 — Fator jovem feminino incorreto 75 vs 70`).
2. **Criar a branch correspondente**:
   ```bash
   git checkout -b fix/B7-female-factor
   ```
3. **Reproduzir a falha primeiro (RED)** com o teste unitário.
4. **Implementar a correção mínima (GREEN)** no código.
5. **Submeter o Pull Request**:
   * **Título**: `[FIX] Corrigir fator feminino jovem para 70 (RQ-MTG-06, B7)`
   * **Descrição**:
     - *Requisito:* `RQ-MTG-06`
     - *Defeito:* `B7`
     - *Testes:* `Nominal.MulherJovem_Idade25_Fator70`
     - *Evidência:* CI verde no GitHub Actions
     - *Closes:* `#3`
6. **Code Review Mútuo**:
   * Se a **Amanda** abriu o PR, a **Magda** analisa e aprova.
   * Se a **Magda** abriu o PR, a **Amanda** analisa e aprova.
7. **Merge no `main`**: Apenas quando todos os checks do GitHub Actions estiverem verdes!

---

## 5. Pipeline de CI Automático (GitHub Actions)

Definido no arquivo `.github/workflows/ci.yml`:
* Disparado automaticamente em todo `push` e `pull_request`.
* Executa em runner `ubuntu-latest`:
  1. `cmake -S . -B build` (baixa Google Test via `FetchContent`)
  2. `cmake --build build`
  3. `ctest --test-dir build --output-on-failure`
