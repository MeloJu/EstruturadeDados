//Bernardo Ramos e Juan Melo
//Tratamento de colisão Hash2
//Data: 16/06/2022
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int mat;
    char nome[100];
    char curso[50];
    int disponibilidade;
}aluno;

#define SIZE 61

int hash(int key)
{
    return key%SIZE;
}

int hash2(int key)
{
    return SIZE-2-(key%(SIZE-2));
}

int acharposicao(char *nomearq, int x)
{
    int pos = hash(x);
    aluno a;
    FILE *arq = fopen(nomearq, "rb");
    fseek(arq, pos*sizeof(aluno), SEEK_SET);
    fread(&a, sizeof(aluno), 1, arq);
    while(a.disponibilidade == 0)
    {
        pos = hash2(pos);
        fseek(arq,pos*sizeof(aluno), SEEK_SET);
        fread(&a,sizeof(aluno),1,arq);
    }
    fclose(arq);
    return pos;

}


void inicializar(char *nomearq)
{
    FILE *arq = fopen(nomearq, "wb");
    aluno a;
    int i;
    a.disponibilidade = 1;
    for(i = 0;i<SIZE; i++)
        fwrite(&a,sizeof(aluno), 1, arq);

    fclose(arq);
}



void inserir(char *nomearq, aluno x)
{
    int pos = acharposicao(nomearq, x.mat);
    FILE *arq = fopen(nomearq, "wb");
    aluno a;
    a = x;
    a.disponibilidade = 0;
    fseek(arq, pos*sizeof(aluno), SEEK_SET);
    fwrite(&a,sizeof(aluno), 1, arq);
    fclose(arq);
}

void buscar(int matricula, char *nomearq)
{
    FILE *arq = fopen(nomearq, "rb");
    aluno a;
    int pos = hash(matricula);
    fseek(arq, pos*sizeof(aluno), SEEK_SET);
    fread(&a,sizeof(aluno), 1, arq);
    if(a.mat != matricula)
    {
        while(a.mat != matricula)
            {
                pos = hash2(pos);
                fseek(arq, pos*sizeof(aluno), SEEK_SET);
                fread(&a,sizeof(aluno), 1, arq);
            }

        printf("|matricula: %d  Curso:  %s   Nome %s\n|", a.mat, a.curso, a.nome);
    }


    else
        printf("|matricula: %d  Curso:  %s   Nome %s\n|", a.mat, a.curso, a.nome);

    

    fclose(arq);
}


void imprimirhash(char *nomearq)
{
    aluno a;
    FILE *arq = fopen(nomearq, "rb");
    while(fread(&a, sizeof(aluno), 1, arq) != 0)
    {
        printf("|matricula: %d  Curso:  %s   Nome %s\n|", a.mat, a.curso, a.nome);
    }


    fclose(arq);
}


int main()
{
    int op = 0;
    aluno a;
    char nomearq[50];
    printf("Digite o nome do arquivo que deseja abrir\n");
    gets(nomearq);
    inicializar(nomearq);
    while(op != 4)
    {
        printf("Menu\n\n");
        printf(" 1 - Adicionar um novo aluno\n");
        printf(" 2 - Imprimir dados de um aluno\n");
        printf(" 3 - Imprimir a tabela de dispersão\n");
        printf(" 4 - Encerrar programa\n");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                printf("Digite a matrícula:\n"); 
                scanf("%d", &a.mat);
                printf("Digite o curso\n");
                scanf("%s", a.curso);
                printf("Digite o nome\n");
                scanf("%s", a.nome);
                inserir(nomearq, a);
                break;

            case 2:
                printf("Digite a matrícula\n");
                scanf("%d", &a.mat);
                buscar(a.mat, nomearq);
                break;
        
            case 3:
                imprimirhash(nomearq);
                break;
        
            case 4:
            op = 4;
            break;
        }


    }








}
