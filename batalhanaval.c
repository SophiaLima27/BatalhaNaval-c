#include <stdio.h>
#include <string.h>

int main() {
    printf("Batalha Naval\n");

    char jogador1[30];
    char jogador2[30];
   
    printf("digite o nome do primeiro jogador: ");
    fgets(jogador1, sizeof(jogador1), stdin);
    jogador1[strcspn(jogador1, "\n")] = '\0';

    printf("digite o nome do segundo jogador: ");
    fgets(jogador2, sizeof(jogador2), stdin);
    jogador2[strcspn(jogador2, "\n")] = '\0';

    printf("jogadores cadastrados %s vs %s \n", jogador1, jogador2);

    
    int a, b;
    int tamanho = 9;

    char tabuNavios[9][9];
    char tabTiros[9][9];
    char tabuNavios2[9][9];
    char tabTiros2[9][9];

    
    for(a = 0; a < tamanho; a++) {
        for(b = 0; b < tamanho; b++) {
            tabuNavios[a][b] = '~';
            tabTiros[a][b] = '~';
            tabuNavios2[a][b] = '~';
            tabTiros2[a][b] = '~';
        }
    }

    
    printf("--- TABULEIRO DE %s ---\n", jogador1);
    printf("  0 1 2 3 4 5 6 7 8\n");
    for(a = 0; a < tamanho; a++) {
        printf("%d ", a);
        for(b = 0; b < tamanho; b++) {
            printf("%c ", tabuNavios[a][b]);
        }
        printf("\n");
    }

    printf("======================================\n\n");

    
    printf("--- TABULEIRO DE %s ---\n", jogador2);
    printf("  0 1 2 3 4 5 6 7 8\n");
    for(a = 0; a < tamanho; a++) {
        printf("%d ", a);
        for(b = 0; b < tamanho; b++) {
            printf("%c ", tabuNavios2[a][b]);
        }
        printf("\n");
    }

    int linha, coluna;
    char direcao;
    int tamNavio = 3; 

    
    printf("\n%s, posicione seu navio de tamanho %d\n", jogador1, tamNavio);
    printf("Digite a linha, coluna e direcao (h para horizontal / v para vertical): ");
    if (scanf("%d %d %c", &linha, &coluna, &direcao) == 3) {
        if ((direcao == 'h') && (coluna + tamNavio <= tamanho)) {
            for (int i = 0; i < tamNavio; i++) {
                tabuNavios[linha][coluna + i] = 'N';
            }
        } else if ((direcao == 'v') && (linha + tamNavio <= tamanho)) {
            for (int i = 0; i < tamNavio; i++) {
                tabuNavios[linha + i][coluna] = 'N';
            }
        }
    }

    printf("\n%s, posicione seu navio de tamanho %d\n", jogador2, tamNavio);
    printf("Digite a linha (0-8), coluna (0-8) e orientacao (H para horizontal / V para vertical): ");
    if (scanf("%d %d %c", &linha, &coluna, &direcao) == 3) {
        if ((direcao == 'h') && (coluna + tamNavio <= tamanho)) {
            for (int i = 0; i < tamNavio; i++) {
                tabuNavios2[linha][coluna + i] = 'N';
            }
        } else if ((direcao == 'v') && (linha + tamNavio <= tamanho)) {
            for (int i = 0; i < tamNavio; i++) {
                tabuNavios2[linha + i][coluna] = 'N';
            }
        }
    }
    
   


    return 0;
}
