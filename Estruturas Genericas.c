#include "stdlib.h"
#include "stdio.h"
#include "string.h"
//1==profssesores:matricula nome e salario 
//2==aluno:matricula nome curso ano de ingressao
/*
inserir pessoa na lista
remover pela matricula
buscar pela matricula, caso encontre printar 
contar numero de alunos em determinado curso
imprimir professores com maior salario(2 whiles, 1 pra ver o maior salario e outro para printar)
/*/

typedef struct professor{
	int matricula;
	char nome [50];
	float salario;
}professor;

typedef struct aluno{
	int matricula;
	char nome[50];
	int curso;
	int ano;
}aluno;

typedef struct escola{
	int tipo;
	void *item;
	struct escola *prox;
}escola;

escola *inicializar()
{
	return NULL;
}

escola *inserirGeral(escola *l, void *item, int tipo)
{
	escola *no = (escola*)malloc(sizeof(escola));
	no->tipo = tipo;
	no->item = item;
	no->prox = l;
	return no;
}

escola *inserir(escola *l)
{
	int tipo;
	printf("1 - Aluno\n2 - Professor\n");
	scanf("%d", &tipo);
	if(tipo == 1)
	{
		aluno *a = (aluno *)malloc(sizeof(aluno));
		printf("Digite a matricula do aluno\n");
		scanf("%d", &a->matricula);
		printf("Digite o nome do aluno\n");
		scanf("%s", a->nome);
		printf("Digite o codigo do curso do aluno\n");
		scanf("%d", &a->curso);
		printf("Digite o ano de ingresso do aluno\n");
		scanf("%d", &a->ano);
		l = inserirGeral(l,a,tipo);
	}
	if(tipo == 2)
	{
		professor *b = (professor *)malloc(sizeof(professor));
		printf("Digite a matricula do professor\n");
		scanf("%d", &b->matricula);
		printf("Digite o nome do professor\n");
		scanf("%s", b->nome);
		printf("Digite o salario do professor\n");
		scanf("%f", &b->salario);
		l = inserirGeral(l,b,tipo);

	}
	
	return l;
}

escola *RemoverPelaMatricula(escola *l, int matricula)
{
	escola *aux;
	if(l != NULL)
	{
		if(l->tipo == 1)
		{
			aluno *a = (aluno*)l->item; 
			if(a->matricula == matricula)
			{
				aux = l->prox;
				free(l->item);
				free(l);
				return aux;
			}
			else
			aux = RemoverPelaMatricula(l->prox, matricula);
		}
			if(l->tipo == 2)
		{
			professor *b = (professor*)l->item;
			if(b->matricula == matricula)
			{
				aux = l->prox;
				free(l->item);
				free(l);
				return aux;
			}

			else
			aux = RemoverPelaMatricula(l->prox, matricula);
		}
		



	}
}

void ImprimirGeral(escola *l, int matricula)
{

	if(l != NULL)
	{
		if(l->tipo == 1)
		{
			aluno *a = (aluno*)l->item; 
			if(a->matricula == matricula)
			{
				printf("Matricula: %d\nNome: %s\nCurso: %d\nAno de ingresso: %d\n", a->matricula, a->nome, a->curso, a->ano);
			}
			else
			ImprimirGeral(l->prox, matricula);
		}
			if(l->tipo == 2)
		{
			professor *b = (professor*)l->item;
			if(b->matricula == matricula)
			{
				printf("Matricula: %d\nNome: %s\nSalario: %.2f\n", b->matricula, b->nome, b->salario);
			}
			else
			ImprimirGeral(l->prox, matricula);
		}
	}
}



void ContaAlunos(escola *l, int curso, int cont)
{
	if(l != NULL)
	{
		aluno *a = (aluno*)l->item; 
		if(a->curso == curso)
		{
			cont++;
		}
	}

	else
	printf("O total de alunos eh %d\n", cont);

}

void ProfRicao(escola *l, int salario)
{
	escola *aux = l;
	if(l!= NULL)
	{
		while(aux != NULL)
		{
			professor *b = (professor*)aux->item;
			{
			if(salario<b->salario)
				salario = b->salario;
			}

			aux = aux->prox;
		}

	aux = l;
		while(aux != NULL)
		{
			professor *b = (professor*)aux->item;
			{
			if(salario == b->salario)
				printf("Matricula do prof: %d\n", b->matricula);
			}

			aux = aux->prox;
		}	
	}

}



int main()
{
	int op;
	int aux2;
	escola *l = inicializar();
	while(op != 6)
	{
		printf(" 1 - Inserir uma pessoa\n");
		printf(" 2 - remover uma pessoa pela matricula\n");
		printf(" 3 - Buscar uma pessoa pela matrícula\n");
		printf(" 4 - Contar o numero de alunos e um determinado curso\n");
		printf(" 5 - Imprimir os professores de maior salario\n");
		printf(" 6 - Sair\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			l = inserir(l);
			break;
			
			case 2:
				printf("Digite a matricula\n");
				scanf("%d", &aux2);
				l = RemoverPelaMatricula(l, aux2);
				break;
			
			case 3:
				printf("Digite a matricula\n");
				scanf("%d", &aux2);
				ImprimirGeral(l, aux2);
				break;

			case 4:
				printf("Digite o curso");
				scanf("%d", &aux2);
				ContaAlunos(l, aux2, 0);
				break;
			
			case 5:
				ProfRicao(l, 0);
				break;

			case 6:
				op == 6;
				break;




		}






	}


}
