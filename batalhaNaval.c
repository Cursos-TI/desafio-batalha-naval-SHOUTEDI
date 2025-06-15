#include <stdio.h>

// --- Constantes do Jogo ---
// É uma boa prática usar constantes para valores fixos, facilitando a manutenção.
#define TAM_NAVIO_H 4      // Tamanho do navio horizontal (Nível Novato)
#define TAM_NAVIO_V 3      // Tamanho do navio vertical (Nível Novato)
#define TAM_TABULEIRO 10   // Dimensão do tabuleiro 10x10 (Nível Aventureiro)
#define HABILIDADE_TAM 5   // Dimensão das matrizes de habilidade (Nível Mestre)

// --- Protótipos das Funções ---
// Declarar as funções aqui permite que a função main() as conheça antes de serem usadas.

// Funções do Nível Aventureiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

// Funções do Nível Mestre
void criarHabilidadeCone(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]);
void criarHabilidadeCruz(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]);
void criarHabilidadeOctaedro(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]);
void exibirMatrizHabilidade(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]);

/*
================================================
           FUNÇÃO PRINCIPAL (main)
================================================
*/
int main() {
    printf("======================================\n");
    printf("     DESAFIO BATALHA NAVAL\n");
    printf("======================================\n\n");

    /*
    ################################################
    #            🏅 NÍVEL NOVATO 🏅                 #
    ################################################
    Objetivo: Posicionar dois navios (vertical e horizontal) e exibir suas coordenadas.
    */
    printf("--- NÍVEL NOVATO ---\n");
    printf("Exibindo coordenadas dos navios:\n\n");

    // 1. Posicionamento do Navio Horizontal
    int navio_h_y = 2; // Coordenada Y fixa do navio horizontal
    int navio_h_x_inicial = 1; // Coordenada X inicial
    printf("Coordenadas do Navio Horizontal (Tamanho %d):\n", TAM_NAVIO_H);
    for (int i = 0; i < TAM_NAVIO_H; i++) {
        // Para cada parte do navio, calculamos e exibimos sua coordenada X e Y
        printf("  Parte %d: [X: %d, Y: %d]\n", i + 1, navio_h_x_inicial + i, navio_h_y);
    }

    // 2. Posicionamento do Navio Vertical
    int navio_v_x = 5; // Coordenada X fixa do navio vertical
    int navio_v_y_inicial = 4; // Coordenada Y inicial
    printf("\nCoordenadas do Navio Vertical (Tamanho %d):\n", TAM_NAVIO_V);
    for (int i = 0; i < TAM_NAVIO_V; i++) {
        // O mesmo para o navio vertical, mas incrementando a coordenada Y
        printf("  Parte %d: [X: %d, Y: %d]\n", i + 1, navio_v_x, navio_v_y_inicial + i);
    }


    /*
    ################################################
    #         🏅 NÍVEL AVENTUREIRO 🏅               #
    ################################################
    Objetivo: Usar uma matriz 10x10 para posicionar 4 navios, incluindo diagonais,
    e exibir o tabuleiro completo. (0 = Água, 3 = Navio)
    */
    printf("\n\n--- NÍVEL AVENTUREIRO ---\n");
    printf("Exibindo o tabuleiro 10x10 com 4 navios posicionados:\n\n");

    // Cria a matriz que representa o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Preenche o tabuleiro com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Posiciona os 4 navios (horizontal, vertical, e dois diagonais)
    // Navio 1: Horizontal (Tamanho 4) na linha 1
    for(int i=0; i < 4; i++) tabuleiro[1][1+i] = 3;
    
    // Navio 2: Vertical (Tamanho 3) na coluna 8
    for(int i=0; i < 3; i++) tabuleiro[4+i][8] = 3;
    
    // Navio 3: Diagonal (Tamanho 3) começando em [3,2]
    for(int i=0; i < 3; i++) tabuleiro[3+i][2+i] = 3;

    // Navio 4: Diagonal (Tamanho 3) começando em [8,1]
    for(int i=0; i < 3; i++) tabuleiro[8-i][1+i] = 3;

    // Mostra o tabuleiro final no console
    exibirTabuleiro(tabuleiro);


    /*
    ################################################
    #            🥇 NÍVEL MESTRE 🥇                 #
    ################################################
    Objetivo: Criar e exibir matrizes que representam áreas de habilidades especiais
    com padrões de cone, cruz e octaedro. (0 = Normal, 1 = Afetada)
    */
    printf("\n\n--- NÍVEL MESTRE ---\n");
    printf("Exibindo as matrizes de Habilidades Especiais:\n");

    // Declara as 3 matrizes para as habilidades
    int matrizCone[HABILIDADE_TAM][HABILIDADE_TAM];
    int matrizCruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int matrizOctaedro[HABILIDADE_TAM][HABILIDADE_TAM];

    // Preenche cada matriz com seu padrão específico
    criarHabilidadeCone(matrizCone);
    criarHabilidadeCruz(matrizCruz);
    criarHabilidadeOctaedro(matrizOctaedro);

    // Exibe cada matriz de habilidade
    printf("\n1. Habilidade em Cone:\n");
    exibirMatrizHabilidade(matrizCone);

    printf("\n2. Habilidade em Cruz:\n");
    exibirMatrizHabilidade(matrizCruz);
    
    printf("\n3. Habilidade em Octaedro:\n");
    exibirMatrizHabilidade(matrizOctaedro);

    printf("\n");
    return 0; // Finaliza o programa com sucesso
}


/*
================================================
       IMPLEMENTAÇÃO DAS FUNÇÕES AUXILIARES
================================================
*/

/**
 * @brief Preenche uma matriz (tabuleiro) com zeros.
 * @param tabuleiro A matriz 10x10 a ser inicializada.
 */
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Usa um loop aninhado para percorrer cada célula da matriz
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Define o valor como 0
        }
    }
}

/**
 * @brief Exibe o tabuleiro de Batalha Naval no console.
 * @param tabuleiro A matriz 10x10 a ser exibida.
 */
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Loop aninhado para passar por cada linha e coluna
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // Imprime o valor da célula seguido de um espaço
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula para a próxima linha ao final de cada linha da matriz
    }
}

/**
 * @brief Cria o padrão de habilidade em CONE.
 * @param matriz A matriz 5x5 onde o padrão será desenhado.
 */
void criarHabilidadeCone(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    // Primeiro, inicializa toda a matriz com 0
    for(int i=0; i<HABILIDADE_TAM; i++) for(int j=0; j<HABILIDADE_TAM; j++) matriz[i][j] = 0;
    
    // Define as posições do padrão como 1
    matriz[0][2] = 1;
    matriz[1][1] = 1; matriz[1][2] = 1; matriz[1][3] = 1;
    matriz[2][0] = 1; matriz[2][1] = 1; matriz[2][2] = 1; matriz[2][3] = 1; matriz[2][4] = 1;
}

/**
 * @brief Cria o padrão de habilidade em CRUZ.
 * @param matriz A matriz 5x5 onde o padrão será desenhado.
 */
void criarHabilidadeCruz(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    // Inicializa com 0
    for(int i=0; i<HABILIDADE_TAM; i++) for(int j=0; j<HABILIDADE_TAM; j++) matriz[i][j] = 0;
    
    // Define as posições da cruz como 1
    matriz[0][2] = 1;
    for(int i=0; i<HABILIDADE_TAM; i++) matriz[1][i] = 1; // Linha horizontal
    matriz[2][2] = 1;
}

/**
 * @brief Cria o padrão de habilidade em OCTAEDRO (conforme exemplo).
 * @param matriz A matriz 5x5 onde o padrão será desenhado.
 */
void criarHabilidadeOctaedro(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    // Inicializa com 0
    for(int i=0; i<HABILIDADE_TAM; i++) for(int j=0; j<HABILIDADE_TAM; j++) matriz[i][j] = 0;
    
    // Define as posições do padrão como 1
    matriz[0][2] = 1;
    matriz[1][1] = 1; matriz[1][2] = 1; matriz[1][3] = 1;
    matriz[2][2] = 1;
}

/**
 * @brief Exibe uma matriz de habilidade 5x5.
 * @param matriz A matriz a ser exibida.
 */
void exibirMatrizHabilidade(int matriz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}