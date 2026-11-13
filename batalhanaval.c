#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Batalha Naval\n");

    char jogador1[30];
    char jogador2[30];
   
    printf("Digite o nome do primeiro jogador: ");
    fgets(jogador1, sizeof(jogador1), stdin);
    jogador1[strcspn(jogador1, "\n")] = '\0';

    printf("Digite o nome do segundo jogador: ");
    fgets(jogador2, sizeof(jogador2), stdin);
    jogador2[strcspn(jogador2, "\n")] = '\0';

    printf("Jogadores cadastrados: %s vs %s \n", jogador1, jogador2);
    
    int a, b, i;
    int tamanho = 9;

    char tabuNavios[9][9];
    char tabTiros[9][9];
    char tabuNavios2[9][9];
    char tabTiros2[9][9];
    
    int meusBarcos[9][9] = {0};
    int meusBarcos2[9][9] = {0};
    
    for(a = 0; a < tamanho; a++) {
        for(b = 0; b < tamanho; b++) {
            tabuNavios[a][b] = '~';
            tabTiros[a][b] = '~';
            tabuNavios2[a][b] = '~';
            tabTiros2[a][b] = '~';
        }
    }

    int linha, coluna;

    printf("\n%s, posicione seus 5 barcos (tamanho 1)\n", jogador1);
    for (i = 0; i < 5; i++) {
        printf("Barco %d - Digite a linha e coluna (0-8): ", i + 1);
        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while(getchar() != '\n'); 
            i--;
            continue;
        }

        if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
            if (meusBarcos[linha][coluna] == 0) {
                meusBarcos[linha][coluna] = 1;
            } else {
                printf("Ja tem um barco nessa posicao! Escolha outra.\n");
                i--;
            }
        } else {
            printf("Posicao invalida! Tente novamente.\n");
            i--; 
        }
    }

    system("cls");

    printf("\n%s, posicione seus 5 barcos (tamanho 1)\n", jogador2);
    for (i = 0; i < 5; i++) {
        printf("Barco %d - Digite a linha e coluna (0-8): ", i + 1);
        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while(getchar() != '\n'); 
            i--;
            continue;
        }

        if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
            if (meusBarcos2[linha][coluna] == 0) {
                meusBarcos2[linha][coluna] = 1;
            } else {
                printf("Ja tem um barco nessa posicao! Escolha outra.\n");
                i--;
            }
        } else {
            printf("Posicao invalida! Tente novamente.\n");
            i--; 
        }
    }

    system("cls");

    int acertos1 = 0;
    int acertos2 = 0;
    int tiroValido;

    while (acertos1 < 5 && acertos2 < 5) {
        printf("\n--- VEZ DE %s ATIRAR ---\n", jogador1);
        printf("Seu tabuleiro de tiros:\n");
        printf("  0 1 2 3 4 5 6 7 8\n");
        for(a = 0; a < tamanho; a++) {
            printf("%d ", a);
            for(b = 0; b < tamanho; b++) {
                printf("%c ", tabTiros[a][b]);
            }
            printf("\n");
        }

        tiroValido = 0;
        while (!tiroValido) {
            printf("Digite a linha e coluna para atirar (0-8): ");
            if (scanf("%d %d", &linha, &coluna) != 2) {
                printf("Entrada invalida! Digite apenas numeros.\n");
                while(getchar() != '\n');
                continue;
            }

            if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
                if (tabTiros[linha][coluna] != '~') {
                    printf("Voce ja atirou nessa posicao! Escolha outra.\n");
                } else {
                    tiroValido = 1;
                    if (meusBarcos2[linha][coluna] == 1) {
                        tabTiros[linha][coluna] = 'V';
                        acertos1++;
                        printf("Voce acertou um barco!\n");
                    } else {
                        tabTiros[linha][coluna] = 'X';
                        printf("Voce errou (tiro na agua)!\n");
                    }
                }
            } else {
                printf("Posicao invalida! Tente novamente.\n");
            }
        }

        if (acertos1 == 5) {
            break;
        }

        printf("\n--- VEZ DE %s ATIRAR ---\n", jogador2);
        printf("Seu tabuleiro de tiros:\n");
        printf("  0 1 2 3 4 5 6 7 8\n");
        for(a = 0; a < tamanho; a++) {
            printf("%d ", a);
            for(b = 0; b < tamanho; b++) {
                printf("%c ", tabTiros2[a][b]);
            }
            printf("\n");
        }

        tiroValido = 0;
        while (!tiroValido) {
            printf("Digite a linha e coluna para atirar (0-8): ");
            if (scanf("%d %d", &linha, &coluna) != 2) {
                printf("Entrada invalida! Digite apenas numeros.\n");
                while(getchar() != '\n');
                continue;
            }

            if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
                if (tabTiros2[linha][coluna] != '~') {
                    printf("Voce ja atirou nessa posicao! Escolha outra.\n");
                } else {
                    tiroValido = 1;
                    if (meusBarcos[linha][coluna] == 1) {
                        tabTiros2[linha][coluna] = 'V';
                        acertos2++;
                    } else {
                        tabTiros2[linha][coluna] = 'X';
                    }
                }
            } else {
                printf("Posicao invalida! Tente novamente.\n");
            }
        }

        system("cls");
    }

    system("cls");
    if (acertos1 == 5) {
        printf("PARABENS %s! Voce destruiu todos os barcos e venceu o jogo!\n", jogador1);
    } else {
        printf("PARABENS %s! Voce destruiu todos os barcos e venceu o jogo!\n", jogador2);
    }
    
    return 0;
}