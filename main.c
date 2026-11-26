#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funcoes essenciais
int isInVector(int arr[], int size, int target) {
    int isInVector = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

// variaveis globais
typedef struct {
    int matriceSize;
    int deathIsPossible;
} GameConfig;

typedef struct {
    int* matrice;
    int* matriceDiscovered;
} GameManager;

typedef struct {
    GameConfig gameConfig;
    GameManager gameManager;
    int points;
    int lifes;
} GameState;

int printMenu() {
    int choosed = 0;
    int option = 0;

    while (!choosed) {
        printf("                                                 oo          \n");
        printf("\n");
        printf("88d8b.d8b. .d8888b. 88d8b.d8b. .d8888b. 88d888b. dP .d8888b. \n");
        printf("88'`88'`88 88ooood8 88'`88'`88 88'  `88 88'  `88 88 88'  `88 \n");
        printf("88  88  88 88.  ... 88  88  88 88.  .88 88       88 88.  .88 \n");
        printf("dP  dP  dP `88888P' dP  dP  dP `88888P' dP       dP `88888P8 \n");

        printf("\n");
        printf("Escolha uma opção: ");
        printf("1 - Iniciar novo jogo\n");
        // Validar se há um jogo salvo
        // printf("2 - Carregar novo jogo\n");
        printf("3 - Sair\n");

        scanf("%d", &option);
        choosed = 1;
    }
    return option;
}

GameConfig getConfigs() {
    GameConfig config;

    int matriceSizeChoosed, deathIsPossibleChoosed = 0;
    while (!matriceSizeChoosed) {
        printf("Quantidade de Cartas (total de cartas usadas na criação do jogo)");
        printf("1 - 18 cartas\n");
        printf("2 - 20 cartas\n");
        printf("3 - 22 cartas\n");

        int option;
        scanf("%d", &option);
        switch (option) {
            case 1: {
                matriceSizeChoosed = 1;
                config.matriceSize = 18;
                break;
            }
            case 2: {
                matriceSizeChoosed = 1;
                config.matriceSize = 20;
                break;
            }
            case 3: {
                matriceSizeChoosed = 1;
                config.matriceSize = 22;
                break;
            }
            default: printf("Opção inválida\n"); break;
        }
    }

    while (!deathIsPossibleChoosed) {
        printf("Morte Possível? (Se ativar, além dos pontos, existirá uma quantidade de vidas que diminui ao errar, chegar a zero causa a morte)");
        printf("1 - Sim\n");
        printf("2 - Não\n");

        int option;
        scanf("%d", &option);
        switch (option) {
            case 1: {
                deathIsPossibleChoosed = 1;
                config.deathIsPossible = 1;
                break;
            }
            case 2: {
                deathIsPossibleChoosed = 1;
                config.deathIsPossible = 0;
                break;
            }
            default: printf("Opção inválida\n"); break;
        }
    }

    return config;
}

GameManager generateNewGame(GameConfig* config) {
    GameManager gameManager;

    gameManager.matrice = (int*)malloc(config->matriceSize * sizeof(int));
    gameManager.matriceDiscovered = (int*)malloc(config->matriceSize * sizeof(int));

    // qual o maior valor que pode ser atribuído a uma carta?
    int maxCardValue = config->matriceSize / 2;

    srand(time(NULL));

    // preenche a matriz com valores aleatórios
    for (int i = config->matriceSize; i > 0; i--) {
        gameManager.matrice[i - 1] = rand() % maxCardValue + 1;
        gameManager.matriceDiscovered[i - 1] = 0;
    }

    return gameManager;
}

void startNewGame() {
    GameConfig newGameConfig = getConfigs();
    GameManager newGameManager = generateNewGame(&newGameConfig);
    GameState gameState = {newGameConfig, newGameManager, 0, 3};
}

void loadGame() {

}

int main() {
    int option = printMenu();

    switch (option) {
        case 1: startNewGame(); break;
        case 2: loadGame(); break;
        case 3: break;
    }

    return 0;
}
