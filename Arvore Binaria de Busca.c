#include <stdio.h>
#include <stdlib.h>

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

int existir(arvore *a, int x)
{
    if(a==NULL)
        return 0;

    else if(x==a->info)
        return 1;

    else if(x<a->info)
        return existir(a->esq,x);

    
    else
        return existir(a->dir,x);


}

void imprimirmaioresiguais(arvore *a, int x)
{
    if(a!=NULL)
    {
        if(a->info>= x)
        {
            printf("%d", a->info);
            imprimirmaioresiguais(a->esq, x);
            imprimirmaioresiguais(a->dir, x);
        }

        else
            imprimirmaioresiguais(a->dir,x);

    }
}

void imprimirentrexey(arvore *a, int x, int y)
{
    if(a!=NULL)
    {
        if(a->info<=x)
            imprimirentrexey(a->dir,x,y);

        else if(a->info>=y)
            imprimirentrexey(a->esq,x,y);

    }

    else
    {
        printf("%d", a->info);
        imprimirentrexey(a->esq,x,y);
        imprimirentrexey(a->dir,x,y);

    }


}

arvore *inserir(arvore *a, int x)
{
    if(a==NULL)
    {
        a = (arvore*)malloc(sizeof(arvore))
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
    }

    else if(x<=a->info)
        a->esq = inserir(a->esq, x);
    else
        a->dir = inserir(a->dir, x);
    
    return a;


}

arvore *remove(arvore *a, int x)
{
    if(a!= NULL)
    {
        if(a->info==x)
        {
            if(a->esq == NULL && a->dir == NULL)
            {
                free(a);
                return NULL;
            }

        else if(a->esq == NULL)
        {
            arvore *aux=a->dir;
            free(a);
            return aux;
        }

        else if(a->dir == NULL)
        {
            arvore *aux = a->esq;
            free(a);
            return aux;
        }

        else
        {
            arvore *aux  = a->esq;
            while(aux->dir!= NULL)
             aux = aux->dir;

            a->info = aux->info;
            a->esq = remover(a->esq, aux->info);
        }
    

        else if(x<a->info)
        {
            a->esq = remover(a->esq, x);
            else
            a->dir = remover(a->dir,x);

            return a;
        }

    
    
    }
    }
}


void encontranivel(arvore *a, int x, int cont)
{
    if(a!= NULL)
    {
        if(a->info == x)
            printf("O elemento esta no nivel %d", cont++);
        
        else if(a->esq <= x)
                encontranivel(a, x, cont++);

        else if(a->dir >= x)
                encontranivel(a, x, cont++);

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


void folhasmenores(arvore *a, int x)
{
    if(a == NULL)
        return 0;

    else
    {
        if(x<a->info && a->dir == NULL && a->esq == NULL)
            printf("%d", a->info)

        else if(x<a->esq)
            folhasmenores(a->esq);
        else if(x<a->dir)
            folhasmenores(a->dir);

    }

}



