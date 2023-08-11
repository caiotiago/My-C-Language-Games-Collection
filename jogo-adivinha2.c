#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

 printf("         P  /_\\  P                              \n");
 printf("        /_\\_|_|_/_\\                             \n");
 printf("   n_n | ||. .|| | n_n         Bem vindo ao     \n");
 printf("    |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao!\n");
 printf("   |" "  |  |_|  |"  " |                        \n");
 printf("   |_____| ' _ ' |_____|                        \n");
 printf("         \\__|_|__/                              \n");
 printf("Descubra um numero entre 0 e 99!\n");

    

    int segundos = time(0);
    srand(segundos);
    int nrandom = rand();
    int numerosecreto = nrandom % 100;
    int chute;
    int numerodetentativas = 5;
    int tentativas = 1;
    int acertou = 0;
    int nivel;
    double pontos = 1000;
    printf("Qual o nivel de dificuldade?\n");
    printf("(1)Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    switch (nivel)
    {
    case 1:
        numerodetentativas = 20;
        break;
    case 2:
        numerodetentativas = 10;
        break;
    default:
        numerodetentativas = 6;
        break;
    }
    system("cls");
    for(int i = 1; i <= numerodetentativas; i++)
    {
        printf("Tentativa %d \n", tentativas);
        printf("Qual e seu chute? \n");
        scanf("%d", &chute);
        printf("Seu chute foi: %d \n", chute);
        if (chute < 0)
        {
            printf("Não chute números negativos sua jamula!");
            continue;
            // ele vai pra for( ; ; cá!!!)
        }

        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;
        int menor = chute < numerosecreto;

        if (acertou)
        {
            break;
        }
        else if (maior)
        {
            printf("Seu chute foi maior que o numero secreto!\n");
        }
        else if (menor)
        {
            printf("Seu chute foi menor que o numero secreto\n");
        }
        tentativas++;
        double pontosperdidos = abs((chute - numerosecreto) / (double)2);
        pontos = pontos - pontosperdidos;
    }
    printf("FIM DE JOGO");
    if (acertou)
    {   
        printf("**************************************\n");
        printf("ORA ORA TEMOS UM SHERLOCK HOLMES AQUI!\n");
        printf("**************************************\n");
        printf("             OOOOOOOOOOO                 \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        } else{
            printf("Voce eh mt burro, tente denovo!\n");
        }
    
}

