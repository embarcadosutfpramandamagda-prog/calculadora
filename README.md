# Laboratório de Testes de Financiamento Imobiliário

**Programa:** Mestrado em Engenharia Elétrica — UTFPR  
**Disciplina:** Sistemas Embarcados  
**Dupla:** Amanda Stadler e Magda Fernandes  

---

## Descrição do Projeto

Este projeto implementa e testa uma função de cálculo de financiamento imobiliário usando como entradas: o gênero, o salário e a idade em C++17, analisa especificações para encontrar lacunas e erros e trata bugs com Google Test. Foi desenvolvida como atividade para Sistemas Embarcados do Mestrado de Engenharia Elétrica UTFPR.

O valor do financiamento é calculado pela fórmula:
`financiamento = salário * fator`

### Entradas
- **Gênero:** Masculino (`Genero::Masculino`) ou Feminino (`Genero::Feminino`)
- **Idade:** Faixa válida de 18 a 55 anos
- **Salário:** Faixa válida de R$ 0 a R$ 10.000

---

## Tabela de Fatores

| Faixa Etária | Homem | Mulher | Regra |
|:---|:---:|:---:|:---|
| 18 a 30 anos | ×75 | ×70 | Válido |
| 31 a 35 anos | ×75 | ×50 | Válido |
| 36 a 40 anos | ×55 | ×50 | Válido |
| 41 a 45 anos | ×55 | ×35 | Válido |
| 46 a 50 anos | ×30 | ×35 | Válido |
| 51 a 55 anos | ×30 | Indefinido | Homem válido; Mulher lança `std::out_of_range` |
| Fora de [18, 55] | Rejeitado | Rejeitado | Lança `std::out_of_range("idade")` |
| Fora de [0, 10000] | Rejeitado | Rejeitado | Lança `std::out_of_range("salario")` |

> **Nota sobre mulheres de 51 a 55 anos:** A especificação original não definiu fator para mulheres nessa faixa etária. Como critério de projeto, entradas nessa condição são tratadas como fora do domínio, lançando exceção `std::out_of_range`.

---

## Estrutura do Repositório

```
embarcados/
├── CMakeLists.txt              # Configuração de build e integração com Google Test
├── Makefile                    # Comandos rápidos de compilação e execução
├── README.md                   # Instruções e documentação do projeto
├── include/
│   └── financiamento.hpp       # Declaração dos tipos e da função
├── src/
│   ├── financiamento.cpp       # Implementação corrigida
│   ├── financiamento_com_defeitos.cpp # Código original com os 12 defeitos da aula
│   └── main.cpp                # Interface de terminal (CLI) para teste manual
├── tests/
│   ├── teste_nominal.cpp       # Testes com casos típicos (Nominais)
│   ├── teste_limites.cpp       # Testes de valores limite nas faixas (Limites)
│   ├── teste_prevencao.cpp     # Testes com entradas fora do domínio (Prevenção)
│   └── teste_perfis.cpp        # Testes de perfis de cliente e da lacuna (Perfis)
├── docs/
│   ├── REQUISITOS.md           # Especificação formal dos requisitos (R1 a R7)
│   ├── DEFEITOS.md             # Análise detalhada dos 12 defeitos (B1 a B12)
│   ├── MATRIZ_RASTREABILIDADE.md # Matriz ligando requisitos aos testes
│   ├── DICIONARIO_DADOS.md     # Tipos, parâmetros e tratamento de erros
│   └── WORKFLOW_GITHUB.md      # Padrão de branches, commits e issues
└── .github/workflows/
    └── ci.yml                  # Pipeline de Integração Contínua (GitHub Actions)
```

---

## Como Compilar e Executar

### Pré-requisitos
- Compilador C++ com suporte a C++17 (GCC, Clang ou MSVC)
- CMake 3.20 ou superior
- Make (opcional, para usar os atalhos)

### 1. Executar todos os testes
```bash
make test
```
Compila a biblioteca, baixa o Google Test automaticamente e executa os 26 testes unitários via CTest.

### 2. Executar suítes específicas
```bash
make limites      # Executa apenas os testes de limites de faixas
make prevencao    # Executa apenas os testes de prevenção a entradas inválidas
make perfis       # Executa apenas os testes de perfis de cliente
```

### 3. Executar o simulador no terminal
```bash
make run
```

### 4. Limpar arquivos de compilação
```bash
make clean
```

### No Windows (PowerShell ou Prompt de Comando)
Caso não possua o `make` instalado, utilize os comandos nativos do CMake:
```powershell
# Configurar o projeto
cmake -S . -B build

# Compilar tudo
cmake --build build

# Executar os 26 testes
ctest --test-dir build --output-on-failure

# Executar o simulador no terminal
.\build\Debug\cli_financiamento.exe
```

---

## Autoras
- Amanda Stadler
- Magda Fernandes
