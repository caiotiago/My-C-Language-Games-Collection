#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"
#define TAMANHO_PALAVRA 50

char chutes[26];
char palavrasecreta[TAMANHO_PALAVRA];
chutesdados = 0;

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void escolhepalavra()
{
    FILE *f;

    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}
void adicionapalavra()
{
    char quer;
    printf("Deseja adicionar nova palavra (S/N)?\n");
    scanf(" %c", &quer);
    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra?");
        scanf("%s", novapalavra);

        FILE *f;
        int qtd;

        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);
        fclose(f);
    }
}

void chuta()
{
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute); // espaço garante a ignoração do enter kkkkkkkkkkkkkkkkkkk
    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}
void desenhaforca()
{
    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
           (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
           (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '),
           (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    printf("Voce ainda tem %d chances\n", 5 - erros);
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {

        if (jachutou(palavrasecreta[i]))
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
}

int chuteserrados()
{
    int erros = 0;
    // vamos fazer o loop em todos os chutes dados
    for (int i = 0; i < chutesdados; i++)
    {

        int existe = 0;

        // agora vamos olhar letra a letra da palavra secreta
        // e ver se encontramos o chute aqui
        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {

                // encontramos, vamos quebrar o loop
                existe = 1;
                break;
            }
        }

        // se nao encontrou, soma um na quantidade de erros
        if (!existe)
            erros++;
    }
    return erros;
}
int enforcou()
{
    return chuteserrados() >= 5;
}
int acertou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    abertura();
    escolhepalavra();
    do
    {
        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());
    system("cls");
    if (acertou())
    {
        printf("        ##########################         \n");
        printf("        ##########################          \n");
        printf("   #####################################    \n");
        printf(" #########################################  \n");
        printf("####      ######################       #### \n");
        printf("###       ######################        ### \n");
        printf("##        ######################        ### \n");
        printf("###     ##########################      ### \n");
        printf("###    ############################    #### \n");
        printf(" ###   ### #################### ###    ###  \n");
        printf(" ####   ### ################## ####  ####   \n");
        printf("   ####  ######################### #####    \n");
        printf("    ######## ################ #########     \n");
        printf("      ######  ##############   ######       \n");
        printf("               ############                 \n");
        printf("                 ########                   \n");
        printf("                   ####                     \n");
        printf("                   ####                     \n");
        printf("                   ####                     \n");
        printf("                   ####                     \n");
        printf("               ############                 \n");
        printf("            ##################              \n");
        printf("            ##################              \n");
        printf("            ###            ###              \n");
        printf("            ###            ###              \n");
        printf("            ###            ###              \n");
        printf("            ##################              \n");
        printf("            ##################              \n");
        printf("          ######################            \n");
        printf("         ########################           \n");
        printf("Huuum nao fez mais que sua obrigacao. Aqui esta seu trofeu, espertinho!\n");
    }
    else
    {
        printf("                    @@@@@@@@@@@@@@@@@@@                   \n");
        printf("                 @@@@@@             @@@@@@@                \n");
        printf("              @@@@                       @@@@              \n");
        printf("             @@@                             @@            \n");
        printf("            @@                                @@           \n");
        printf("           @@                     `           @@          `\n");
        printf("          @@                                   @@          \n");
        printf("          @@ @@                             @@ @@          \n");
        printf("          @@ @@                             @@  @          \n");
        printf("          @@ @@                             @@  @          \n");
        printf("          @@  @@                            @@ @@          \n");
        printf("          @@  @@                           @@  @@          \n");
        printf("           @@ @@   @@@@@@@@     @@@@@@@@   @@ @@           \n");
        printf("            @@@@ @@@@@@@@@@     @@@@@@@@@@ @@@@@           \n");
        printf("             @@@ @@@@@@@@@@     @@@@@@@@@@ @@@             \n");
        printf("    @@@       @@  @@@@@@@@       @@@@@@@@@  @@      @@@@   \n");
        printf("   @@@@@     @@   @@@@@@@   @@@   @@@@@@@   @@     @@@@@@  \n");
        printf("  @@   @@    @@     @@@    @@@@@    @@@     @@    @@   @@  \n");
        printf(" @@@    @@@@  @@          @@@@@@@          @@  @@@@    @@@ \n");
        printf("@@         @@@@@@@@       @@@@@@@       @@@@@@@@@        @@\n");
        printf("@@@@@@@@@@     @@@@@@@@    @@@@@@@    @@@@@@@@      @@@@@@@@\n");
        printf("  @@@@ @@@@@      @@@@@              @@@ @@     @@@@@@ @@@ \n");
        printf("          @@@@@@  @@@  @@           @@  @@@  @@@@@@        \n");
        printf("              @@@@@@ @@ @@@@@@@@@@@ @@ @@@@@@              \n");
        printf("                  @@ @@ @ @ @ @ @ @ @ @ @@                 \n");
        printf("                @@@@  @ @ @ @ @ @ @ @   @@@@@              \n");
        printf("            @@@@@ @@   @@@@@@@@@@@@@   @@ @@@@@            \n");
        printf("    @@@@@@@@@@     @@                 @@      @@@@@@@@@    \n");
        printf("   @@           @@@@@@@             @@@@@@@@          @@   \n");
        printf("    @@@     @@@@@     @@@@@@@@@@@@@@@     @@@@@     @@@    \n");
        printf("      @@   @@@           @@@@@@@@@           @@@   @@      \n");
        printf("      @@  @@                                   @@  @@      \n");
        printf("       @@@@                                     @@@@       \n");
        printf("Perdeu sua jamula!, a palavra secreta era: %s\n", palavrasecreta);
    }
    adicionapalavra();
}