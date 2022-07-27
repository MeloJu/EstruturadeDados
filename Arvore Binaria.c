#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arvore
{
    int info;
    struct arvore *esq, *dir;
}arvore;

arvore *LerArvore(FILE *arq) 
{
    arvore *a;
    char c;
    int n;
    
    fscanf(arq, "%c", &c);
    fscanf(arq, "%d", &n);

    if(n==-1)
    {
        
        fscanf(arq, "%c", &c);
        return NULL;
    }
    else
    {
        
        a = (arvore*) malloc(sizeof(arvore));
        a->info = n;
        a->esq = LerArvore(arq);
        a->dir = LerArvore(arq);
        fscanf(arq, "%c", &c);
        
        return a;
    }
}

void Imprimir(arvore *a)
{
    if(a != NULL)
    {
        printf("%d ", a->info);
        Imprimir(a->esq);
        Imprimir(a->dir);
    }
}

int Existe(arvore *a, int num) 
{
    if(a == NULL)
    {
    	return 0;
	}   
    else
    {
        if(num == a->info)
        {
        	return 1;	
		}
        else
        {
            if(Existe(a->esq, num)==1)
            {
            	return 1;	
			}
            return Existe(a->dir, num);
        }
    }
}

int ContarNivel(arvore *a, int cont, int nivel)
{
    if(a == NULL)
    {    
        return 0;
    }
    else
    {
        if(cont == nivel)
        {   
            return 1;
        }
        else
        {
            return ContarNivel(a->esq,cont+1,nivel)+ContarNivel(a->dir,cont+1, nivel);
        }
    }
}

int Altura(arvore *a)
{
    if(a == NULL)
    {
    	return 0;
	}
    else
    {
        int he = Altura(a->esq);
        int hd = Altura(a->dir);
        if(he>hd)
        {
        	return he+1;
		}
        else
        {
        	return hd+1;	
		}
    }
}

int Elementos(arvore *a) 
{
    if(a == NULL)
    {
    	return 0;
	}
    else
    {
    	return 1 + Elementos(a->esq) + Elementos(a->dir);
	}
}


int balanceada(arvore *a)
{
    if(a == NULL)
	{
		return 0;
	}
    else
    {
        if(abs(Altura(a->esq) - Altura(a->dir) <= 1))
        {
            return 1;
        }
        else
        {
        	return 0;
		}
    }
}

void ImprimeArvore(arvore *a, int op2)
{
    if(a!=NULL)
	{
        if(op2 == 1)
        {
            printf("%d ", a->info);
        }
        ImprimeArvore(a->esq, op2);
        if(op2 == 2)
        {
            printf("%d ", a->info);
        }
        ImprimeArvore(a->dir, op2);
        if(op2 == 3)
        {
            printf("%d ", a->info);
        }
    }
}

void VerNivel(arvore *a, int cont, int nivel)
{
    if(a!= NULL)
    {
        if(cont == nivel)
        {
        	printf("%d ", a->info);
		}
        else
        {
        	VerNivel(a->esq,cont+1,nivel);
            VerNivel(a->dir, cont+1, nivel);
		}
    }
}

void imprimelargura(arvore *a, int cont, int nivel)
{
    int i = 0;

    if(a == NULL)
    {
    	return 0;
	}
	else
    {
		while(i<Altura(a))
		{ 
		    VerNivel(a, cont, nivel+i);
		    printf("\n");
		    i++;
		}
    }
}

int cheia(arvore *a)
{
    int checar = pow(2, Altura(a));

    if(a == NULL)
    {
    	return 0;
	}
    if(Elementos(a) == checar-1)
    {
    	return 1;
	}
}

void buscarnivel(arvore *a, int x, int nivel)
{
    if(a !=NULL)
    {
        if(a->info == x)
        {
            printf("O elemento %d esta no nivel: %d", x, nivel);
        }
        else
        {
			buscarnivel(a->esq, x, nivel+1);
			buscarnivel(a->dir, x, nivel+1);
        }
    }
}

void folha(arvore *a)
{
    if(a == NULL)
    {
    	return 0;
	}
    else
    {
    	if(a->esq == NULL && a->dir == NULL)
        {
        	printf("Nos folhas: %d\n", a->info);
		}
    	
    	folha(a->esq);
    	folha(a->dir);
	}
}

arvore *libera(arvore *a)
{
    if(a == NULL)
    {
    	return NULL;
	}
    else
    {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

int main()
{
    arvore *a;
    int variavel = 0;
    char nomeArquivo[50];
    int variavel2 = 0;
    int x = 1;
    FILE *arq;
    while(x == 1)
    {
        printf("\n");
        printf("Digite uma opcao:\n1)Ler uma arvore fornecida pelo usuario\n");
        printf("2)Imprimir a arvore(opcoes: pre-ordem, em-ordem, pos-ordem, e em largura)\n");
        printf("3)Verificar se um elemento X existe na arvore\n");
        printf("4)Contar o numero de elementos na arvore\n");
        printf("5)Imprimir os nos folhas da arvore\n");
        printf("6)Verificar se uma arvore esta balanceada\n");
        printf("7)Verificar se uma arvore eh cheia\n");
        printf("8)Imprimir o nivel de um no X\n");
        printf("9)Sair\n");
        scanf("%d", &variavel);
        Sleep(350);
        system("cls");
        switch(variavel)
        {
		    printf("\n");
		    case 1:
		        printf("Digite o nome do arquivo:\n");
		        scanf("%s", nomeArquivo);
		        arq = fopen(nomeArquivo, "r");
		        a = LerArvore(arq);
		        fclose(arq);
		        printf("O arquivo foi lido com sucesso!\n");
		        break;
		     
		     case 2: 
		        printf("Digite seu modo de impressao:\n1- Pre-ordem\n2- Em-ordem\n3- Pos-ordem\n4- Largura\n");
		        scanf("%d", &variavel2);
		        ImprimeArvore(a,variavel2);
		        if(variavel2 == 4)
		        {
		            imprimelargura(a, 0, 0);
		        }
		        break;
		
		    case 3:
		        printf("Digite o elemento que quer buscar\n");
		        scanf("%d", &variavel2);
		      
		        if(Existe(a, variavel2) == 1)
		        {
		        	printf("O elemento existe\n");
				}
		        else
		        {
		        	printf("O elemento nao existe\n");
				} 
		        break;
		
		    case 4:
		        variavel2 = Elementos(a);
		        printf("A arvore tem %d elementos\n", variavel2);
		        break;
		        
		    case 5:
		        folha(a);
		        break;
		        
		    case 6:
		        variavel2 = balanceada(a);
		        if(variavel2 == 1)
		        {
		        	printf("A arvore eh balanceada\n");
				}    
		        else
		        {
		        	printf("A arvore nao eh balanceada\n");
				}
		        break;
		
		    case 7:
		        variavel2 = cheia(a);
		        if(variavel2 == 1)
		        {
		        printf("A arvore esta cheia\n");
				}		            
		        else
		        {
		        	printf("A arvore nao esta cheia\n");
				}
		        break; 
		    
		    case 8:
		        printf("Digite o numero que deseje saber o nivel\n");
		        scanf("%d", &variavel2);
		        buscarnivel(a, variavel2, 0);
		        break;
		
		    case 9:
		        x = 2;
		        a = libera(a);
		        break;
        }
    }
    return 0;
}
