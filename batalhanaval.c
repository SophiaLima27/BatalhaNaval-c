#include <stdio.h>
#include <string.h>

int main() {
    printf("Batalha Naval\n");

    char jogador1[30];
    char jogador2[30];
    \\ cadastro dos jogadores
    printf("digite o nome do primeiro jogador: ");
    fgets(jogador1, sizeof(jogador1), stdin);
    jogador1[strcspn(jogador1, "\n")] = '\0';

    printf("digite o nome do segundo jogador: ");
    fgets(jogador2, sizeof(jogador2), stdin);
    jogador2[strcspn(jogador2, "\n")] = '\0';

    printf("jogadores cadastrados %s vs %s \n", jogador1, jogador2);

    \\ parte2 posicionar os navios
    printf("o jogador %s: deve posicionar os navios.", jogador1);

    printf("agora o jogador %s: deve posicionar os navios", jogador2);

    return 0;
}