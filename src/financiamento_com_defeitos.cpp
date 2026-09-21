// Codigo original fornecido em aula com os 12 defeitos (B1 a B12) para estudo.

int calcular_financiamento_com_defeitos(bool homem, int idade, int salario) {
    if (homem) {
        if (18 < idade && idade < 35) return 75 * salario;     // B1 (exclui 18), B2 (exclui 35)
        else if (31 < idade && idade < 40) return 55 * salario; // B3 (começa >31), B4 (termina <40), B5 (40-45 cai no else)
        else return 30 * salario;
    } else {
        if (18 < idade && idade < 30) return 75 * salario;     // B6 (exclui 18), B7 (fator 75 em vez de 70), B8 (exclui 30)
        else if (31 < idade && idade < 40) return 50 * salario; // B9 (exclui 31), B10 (exclui 40)
        else return 35 * salario;
    }
    // B11: sem rejeição de idade fora de [18, 55]
    // B12: sem rejeição de salário fora de [0, 10000]
}
