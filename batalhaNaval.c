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
            tabuleiro[i][j] = 0; // preenche o tabuleiro com agua
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

    
    // preenche o tabuleiro com a habilidade de cruz
    for(int i = 4; i < 9 ; i ++)
    {
        for (int j = 2; j < 7; j++)
        {
            // preenche a linha com um elemento 
            if(i != 6)
            {
                tabuleiro[i][4] = 1;
                break;
            }
            tabuleiro[i][j] = 1; // preenche a linha com 5 elementos 
        }
    }
    
     // preenche o tabuleiro com a habilidade de cone
    int aux = 5;
    for(int i = 0; i < 3; i++)
    {
        // preenche a linha com 1 + n elementos, com n cemçando em 0
        // e aumentando de 2 em 2 a cada ciclo 
        for(int j = aux; j < (colunas-(aux-1)); j++)
        {
                tabuleiro[i][j] = 1;   
        }
        if (aux > 0) aux -= 1;
    }

    

   // preenche o tabuleiro com a habilidade de octaedro
    for(int i = 4; i < 7; i++)
    {
        
        for(int j = 7; j < 10; j++)
        {
            // preenche a linha com apenas um elemento 
            if(i !=5)
            {
                tabuleiro[i][8] = 1;
                break;
            }
            tabuleiro[i][j] = 1; // preenche a linha com 3 elementos
        }
    }


    
    // mostra o tabuleiro completo na tela
    puts("\t~~~~Tabuleiro~~~~");
    for(char i = 'a'; i <= 'j'; i++) // mostra as cordenadas verticais
    {
        printf("   %c", i);
    }
    puts("");
    for(int i = 0; i < linhas;i++)
    {
        printf("%i-", i); // mostra as cordenadas horizontais

        for(int j = 0; j < colunas; j++)
        {
            printf(" %i  ", tabuleiro[i][j]);
        }
        puts("");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // preenche as matrizes do cone, cruz e octaedro com zeros
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // completa a matriz com um cone
    int aux_cone = 2;
    for(int i = 0; i < 3; i++)
    {
        for(int j = aux_cone; j < (5-aux_cone); j++)
        {
                cone[i][j] = 1;   
        }
        if (aux_cone > -1) aux_cone-= 1;
    }

    // preenche a matriz com uma cruz
    for(int i = 0; i < 3 ; i ++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(i != 1)
            {
                cruz[i][2] =  1;
                break;
            }
            cruz[i][j] = 1;
        }
    }

    // preenche a matriz com um octaedro

    for(int i = 0; i < 3; i ++)
    {
        for(int j = 1; j < 4; j++ )
        {
            if(i != 1)
            {
                octaedro[i][2] = 1;
                break;
            }
            octaedro[i][j] = 1;
        }
    }


    return 0;
}
