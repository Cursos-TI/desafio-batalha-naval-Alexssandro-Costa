#include <stdio.h>
#include <stdlib.h>

int main() {

    int linhas = 10;
    int colunas = 10;

    // declaração da matriz 10x10
    int tabuleiro[linhas][colunas]; 

    // preenche todas as posições do tabuleiro 
    for(int i = 0; i < linhas;i++)
    {
        for(int j = 0; j < colunas; j++)
        {

            // posiciona dois navios horizontalmente no tabuleiro
            if((i == 0 && j < 3) ||  (i == 6 && j < 3))
            {
                tabuleiro[i][j] = 3;
                continue;
            }
            tabuleiro[i][j] = 0;
        }
    }

    // posiciona dois navios na diagonal do tabuleiro
    for(int controle = 0, i = 1, j = 8;  controle < 6; controle++)
    {
        tabuleiro[i][j] = 3;

        // troca o lado que o navio vai ser posicionado
        if(controle >= 2)
        {
            if(controle == 2)
            {
                i = 9;
                j = 9;
            }
            i--; // pula pra linha anterior
            j--; // pula pra coluna anterior
            continue;
        }

        
        i++; // pula pra proxima linha
        j--; // pula pra coluna anterior

    }

    // mostra o tabuleiro completo na tela
    puts("\t~~~~Tabuleiro~~~~");
    for(int i = 0; i < linhas;i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf(" %i ", tabuleiro[i][j]);
        }
        puts("");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
