```c
#include <stdio.h>

#define DIAS 7
#define BAIRROS 4

int main() {
    // Matriz que armazena a chuva de cada dia em cada bairro.
    float chuva[DIAS][BAIRROS];

    // Nomes dos bairros monitorados.
    char nomesBairros[BAIRROS][30] = {
        "Centro",
        "Jardim Azul",
        "Vila Nova",
        "Parque Sul"
    };

    // Vetor que armazena o acumulado de chuva por bairro.
    float totalBairro[BAIRROS] = {0};

    int dia, bairro;
    int caractere;
    int maiorBairro = 0;

    printf("============================================\n");
    printf("   SISTEMA DE MONITORAMENTO PLUVIOMETRICO\n");
    printf("============================================\n");
    printf("Periodo: %d dias | Bairros: %d\n", DIAS, BAIRROS);
    printf("Unidade de medida: milimetros (mm)\n");

    // Leitura dos dados utilizando dois lacos for.
    for (dia = 0; dia < DIAS; dia++) {
        printf("\n--- Registro do dia %d ---\n", dia + 1);

        for (bairro = 0; bairro < BAIRROS; bairro++) {
            while (1) {
                printf("Chuva em %s (mm): ",
                       nomesBairros[bairro]);

                if (scanf("%f", &chuva[dia][bairro]) == 1
                    && chuva[dia][bairro] >= 0) {
                    break;
                }

                printf("Valor invalido! Digite um numero "
                       "maior ou igual a zero.\n");

                // Limpa a entrada incorreta do teclado.
                while ((caractere = getchar()) != '\n'
                       && caractere != EOF) {
                }
            }

            // Acumula a chuva registrada em cada bairro.
            totalBairro[bairro] += chuva[dia][bairro];
        }
    }

    // Exibe a matriz completa de registros.
    printf("\n============================================\n");
    printf("         RELATORIO DE CHUVAS (mm)\n");
    printf("============================================\n");

    printf("%-8s", "Dia");
    for (bairro = 0; bairro < BAIRROS; bairro++) {
        printf("| %-12s", nomesBairros[bairro]);
    }
    printf("\n");

    for (dia = 0; dia < DIAS; dia++) {
        printf("%-8d", dia + 1);

        for (bairro = 0; bairro < BAIRROS; bairro++) {
            printf("| %-12.1f", chuva[dia][bairro]);
        }

        printf("\n");
    }

    // Apresenta o acumulado de chuva de cada bairro.
    printf("\n============================================\n");
    printf("       ACUMULADO POR BAIRRO (mm)\n");
    printf("============================================\n");

    for (bairro = 0; bairro < BAIRROS; bairro++) {
        printf("%-15s: %.1f mm\n",
               nomesBairros[bairro],
               totalBairro[bairro]);

        // Identifica o bairro com maior acumulado.
        if (totalBairro[bairro] > totalBairro[maiorBairro]) {
            maiorBairro = bairro;
        }
    }

    printf("\nMaior acumulado: %s (%.1f mm)\n",
           nomesBairros[maiorBairro],
           totalBairro[maiorBairro]);

    // BONUS: heatmap de intensidade pluviometrica.
    printf("\n============================================\n");
    printf("       HEATMAP DE INTENSIDADE\n");
    printf("============================================\n");
    printf("Legenda: . Baixa | ~ Moderada | * Alta | ! Muito alta\n");
    printf("Faixas:  < 5 | 5 a < 20 | 20 a < 50 | 50 mm ou mais\n\n");

    printf("%-8s", "Dia");
    for (bairro = 0; bairro < BAIRROS; bairro++) {
        printf("| %-12s", nomesBairros[bairro]);
    }
    printf("\n");

    for (dia = 0; dia < DIAS; dia++) {
        printf("%-8d", dia + 1);

        for (bairro = 0; bairro < BAIRROS; bairro++) {
            char intensidade;

            if (chuva[dia][bairro] < 5) {
                intensidade = '.';
            } else if (chuva[dia][bairro] < 20) {
                intensidade = '~';
            } else if (chuva[dia][bairro] < 50) {
                intensidade = '*';
            } else {
                intensidade = '!';
            }

            printf("|      %c       ", intensidade);
        }

        printf("\n");
    }

    printf("\nMonitoramento finalizado com sucesso!\n");
    printf("Obrigado por utilizar o sistema.\n");

    return 0;
}
```
