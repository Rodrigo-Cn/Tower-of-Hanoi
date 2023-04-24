#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define TAM 100

typedef struct torre
{
    int v[TAM];
    int topo;
} Torre;

void menu();
void push();
void pop();
void imprimir();
int top();

int main ()
{
    system("color F0");
    setlocale(LC_ALL, "");
    int opcao, opcao2, dificuldade, opcao3, opcao4, receber, aux=0, cont=0, x;
    char nome[TAM];
    Torre t[3];
    t[0].topo = -1;
    t[1].topo = -1;
    t[2].topo = -1;

    menu();
    scanf("%d", &opcao);

    while(opcao!=1 || opcao!=2 || opcao!=3)
    {
        FILE *ponteiro;
        ponteiro = fopen("pontos.txt", "a");

        if(opcao==1)
        {
            system("cls");
            printf("|-----------------------------------------------------------------------------|\n");
            printf("|                                                                             |\n");
            printf("| ***    *   *****   *    *****    *   *   *       * *     ****   * *    **** | \n");
            printf("| *  *   *   *****   *    *        *   *   *       *  *    *  *   *  *   *    | \n");
            printf("| *  *   *   *       *    *        *   *   *       *  *    ****   *  *   **** | \n");
            printf("| *  *   *   *       *    *        *   *   *       *  *    *  *   *  *   *    | \n");
            printf("| ***    *   *       *    *****    *****   *****   * *     *  *   * *    **** | \n");
            printf("|                                                                             |\n");
            printf("|-----------------------------------------------------------------------------|\n");
            printf("|                                                                             |\n");
            printf("|                          FÁCIL - 1  (3 DISCOS)                              |\n");
            printf("|                                                                             |\n");
            printf("|                          MÉDIO - 2  (5 DISCOS)                              |\n");
            printf("|                                                                             |\n");
            printf("|                         DIFÍCIL - 3  (8 DISCOS)                             |\n");
            printf("|                                                                             |\n");
            printf("|-----------------------------------------------------------------------------|\n");
            scanf("%d", &opcao2);
            Beep(330, 150);
            Beep(330, 150);

            printf("\n\nDIGITE SEU NOME: ");
            setbuf(stdin, 0);
            fgets(nome, TAM, stdin);
            nome[strlen(nome)-1] = '\0';

            if(opcao2==1)
            {
                dificuldade = 3;
                push(&t[0],3);
                push(&t[0],2);
                push(&t[0],1);
            }
            else if(opcao2==2)
            {
                dificuldade = 5;
                push(&t[0],5);
                push(&t[0],4);
                push(&t[0],3);
                push(&t[0],2);
                push(&t[0],1);
            }
            else if(opcao2==3)
            {
                dificuldade = 8;
                push(&t[0],8);
                push(&t[0],7);
                push(&t[0],6);
                push(&t[0],5);
                push(&t[0],4);
                push(&t[0],3);
                push(&t[0],2);
                push(&t[0],1);
            }

            cont=0;
            x=0;
            while(t[2].topo!=dificuldade-1 || t[1].topo!=dificuldade-1)
            {
                system("cls");
                printf("\nTORRE 1: \n");
                imprimir(t[0]);

                printf("\nTORRE 2: \n");
                imprimir(t[1]);

                printf("\nTORRE 3: \n");
                imprimir(t[2]);

                if(cont>0)
                {
                    if(opcao2==1)
                    {
                        x = (7*100)/cont;
                        if(cont<=7)
                        {
                            printf("\nPONTUAÇÃO MÁXIMA: 100 POR CENTO");
                        }
                        else
                        {
                            printf("\nPONTUAÇÃO: %d POR CENTO", x);
                        }
                    }
                    else if(opcao2==2)
                    {
                        x = (31*100)/cont;
                        if(cont<=31)
                        {
                            printf("\nPONTUAÇÃO MÁXIMA: 100 POR CENTO");
                        }
                        else
                        {
                            printf("\nPONTUAÇÃO: %d POR CENTO", x);
                        }

                    }
                    else if(opcao2==3)
                    {
                        x = (255*100)/cont;
                        if(cont<=251)
                        {
                            printf("\nPONTUAÇÃO MÁXIMA: 100 POR CENTO");
                        }
                        else
                        {
                            printf("PONTUAÇÃO: %d POR CENTO", x);
                        }
                    }

                }

                printf("\n\nESCOLHA QUAL TORRE PEGAR O DISCO: ");
                scanf("%d", &opcao3);

                printf("ESCOLHA EM QUAL HASTE COLOCAR: ");
                scanf("%d", &opcao4);

                while( top(t[opcao3-1]) > top(t[opcao4-1]) && (t[opcao4-1].topo)!=-1 && cont>0 || opcao4==opcao3)
                {
                    printf("\nESCOLHA POSIÇÕES CORRETAS!!!");

                    printf("\nESCOLHA QUAL TORRE PEGAR O DISCO: ");
                    scanf("%d", &opcao3);

                    printf("ESCOLHA EM QUAL HASTE COLOCAR: ");
                    scanf("%d", &opcao4);
                }
                Sleep(500);
                cont++;

                if(opcao3==1)
                {
                    receber = top(t[0]);
                    pop(&t[0]);
                }
                else if(opcao3==2)
                {
                    receber = top(t[1]);
                    pop(&t[1]);

                }
                else if(opcao3==3)
                {
                    receber = top(t[2]);
                    pop(&t[2]);
                }

                if(opcao4==1)
                {
                    push(&t[0], receber);
                }
                else if(opcao4==2)
                {
                    push(&t[1], receber);
                }
                else if(opcao4==3)
                {
                    push(&t[2], receber);
                }

                if(t[1].topo==dificuldade-1 || t[2].topo==dificuldade-1)
                {
                    system("cls");
                    printf("         ________00000000000000000000000000             \n");
                    printf("         ________00000000000000000000000000             \n");
                    printf("         ___00000000000000000000000000000000000000      \n");
                    printf("         _00000000000000000000000000000000000000000     \n");
                    printf("         0000______0000000000000000000000_______0000    \n");
                    printf("         000_______0000000000000000000000________000    \n");
                    printf("         00________0000000000000000000000________000    \n");
                    printf("         000_____00000000000000000000000000______000    \n");
                    printf("         000____0000000000000000000000000000____0000    \n");
                    printf("         _000___000_00000000000000000000_000____000     \n");
                    printf("         _0000___000_000000000000000000_0000__0000      \n");
                    printf("         ___0000__000000000000000000000000_00000        \n");
                    printf("         ____00000000_0000000000000000_00000000         \n");
                    printf("         ______000000__00000000000000___000000          \n");
                    printf("         _______________000000000000                    \n");
                    printf("         _________________00000000                      \n");
                    printf("         ___________________0000                        \n");
                    printf("         ___________________0000                        \n");
                    printf("         ___________________0000                        \n");
                    printf("         _______________000000000000                    \n");
                    printf("         ____________000000000000000000                 \n");
                    printf("         ____________000000000000000000                 \n");
                    printf("         ____________000    VOCÊ    000                 \n");
                    printf("         ____________000   VENCEU   000                 \n");
                    printf("         ____________000    !!!     000                 \n");
                    printf("         ____________000000000000000000                 \n");
                    printf("         ____________000000000000000000                 \n");
                    printf("         __________0000000000000000000000               \n");
                    if(opcao2==1)
                    {
                        x = (7*100)/cont;
                        if(cont==7)
                        {
                            printf("\nVOCÊ OBTEVE A PONTUAÇÃO MÁXIMA: 100 POR CENTO");
                        }
                        else
                        {
                            printf("\nPONTUAÇÃO: %d POR CENTO", x);
                        }
                    }
                    else if(opcao2==2)
                    {
                        x = (31*100)/cont;
                        if(cont==31)
                        {
                            printf("\nVOCÊ OBTEVE PONTUAÇÃO MÁXIMA: 100 POR CENTO");
                        }
                        else
                        {
                            printf("\nPONTUAÇÃO: %d POR CENTO", x);
                        }

                    }
                    else if(opcao2==3)
                    {
                        x = (255*100)/cont;
                        if(cont==255)
                        {
                            printf("\nVOCÊ OBTEVE PONTUAÇÃO MÁXIMA: 100 POR CENTO");
                        }
                        else
                        {
                            printf("PONTUAÇÃO: %d POR CENTO", x);
                        }
                    }

                    fprintf(ponteiro, "\n\nNOME DO JOGADOR: %s", nome);
                    fprintf(ponteiro, "\nPONTUAÇÃO: %d", x);
                    fclose(ponteiro);

                    Beep(264, 150);
                    Beep(297, 150);
                    Beep(264, 150);
                    Beep(297, 150);
                    Beep(396, 150);
                    printf("\n1 - VOLTAR AO MENU\n");
                    scanf("%d", &opcao);
                    if(opcao2==1)
                    {
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);

                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                    }
                    else if(opcao2==2)
                    {
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);

                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                    }
                    else if(opcao2==3)
                    {
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);
                        pop(&t[1]);

                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                        pop(&t[2]);
                    }

                    break;
                }
            }


        }
        else if(opcao==2)
        {
            system("cls");
            printf("Torre de Hanói é um 'quebra-cabeça' que consiste em uma base contendo três pinos, \nem um dos quais são dispostos alguns discos uns sobre \nos outros, em ordem crescente de \ndiâmetro, de cima para baixo. O problema consiste em \npassar todos os discos de um pino para outro qualquer, \nusando um dos pinos como auxiliar, de maneira que um disco maior nunca \nfique em cima de outro menor em nenhuma situação. \nO número de discos pode variar sendo que o \nmais simples contém apenas três.");
            printf("\n\n");
            printf("1 - VOLTAR\\n");
            scanf("%d", &opcao);

        }
        else if(opcao==3)
        {
            system("cls");
            break;
        }
        menu();
        scanf("%d", &opcao);
    }


}

void menu ()
{
    system("cls");
    printf("---------------------------------------------------\n");
    printf("|                TORRE DE HANÓI                   |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                 (pressione)                     |\n");
    printf("|                                                 |\n");
    printf("|              1 - INICIAR JOGO                   |\n");
    printf("|                                                 |\n");
    printf("|           2 - REGRAS E INSTRUÇÕES               |\n");
    printf("|                                                 |\n");
    printf("|                  3 - SAIR                       |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|    *Contrutores:                Aumente         |\n");
    printf("|    *Rodrigo Costa                  o            |\n");
    printf("|    *Samuel Araújo            volume do fone!!!  |\n");
    printf("|                                                 |\n");
    printf("---------------------------------------------------\n");

    Beep(330, 150);
    Beep(330, 150);

}

void push (Torre *t, int x)
{
    if(t->topo == TAM-1)
    {
        /*printf("OVERFLOW");*/
    }
    else
    {
        t->topo++;
        t->v[t->topo] = x;
    }
}

void pop (Torre *t)
{
    if(t->topo==-1)
    {
        /*printf("UNDERFLOW");*/
    }
    else
    {
        t->topo--;
    }
}

void imprimir (Torre t)
{
    while(t.topo != -1)
    {
        if(t.v[t.topo]==1)
        {
            printf("\n                [=%i=]         ",t.v[t.topo]);

        }
        else if(t.v[t.topo]==2)
        {
            printf("\n               [==%i==]         ",t.v[t.topo]);

        }
        else if(t.v[t.topo]==3)
        {
            printf("\n              [===%i===]         ",t.v[t.topo]);

        }
        else if(t.v[t.topo]==4)
        {
            printf("\n             [====%i====]         ",t.v[t.topo]);

        }
        else if(t.v[t.topo]==5)
        {
            printf("\n            [=====%i=====]         ",t.v[t.topo]);

        }
        else if(t.v[t.topo]==6)
        {
            printf("\n           [======%i======]         ",t.v[t.topo]);

        }
        else if(t.v[t.topo]==7)
        {
            printf("\n          [=======%i=======]         ",t.v[t.topo]);

        }
        else if(t.v[t.topo]==8)
        {
            printf("\n         [========%i========]         ",t.v[t.topo]);

        }
        pop(&t);

    }
    printf("\n");
    printf("    00000000000000000000000000000     \n");
}

int top (Torre t)
{
    return t.v[t.topo];
}
