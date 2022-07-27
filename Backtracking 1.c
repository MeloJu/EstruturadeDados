#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirC(char *vet, int pos, int n, char *vAux)
{
	if(pos == n){
		int e_i = 0;
		int a = 0;
		for(int i = 0; i < n; i++){
			if(vet[i] == 'a')
				a++;
            else
				e_i++;
		}

		if(a > e_i) {
				printf("%s\n",vet);
		}

	} else{
            for(int i = 0; i <= 2; i++) {
                vet[pos] = vAux[i];
                imprimirC(vet,pos+1,n,vAux);
		}
	}
}

int main(){
	int n;
	printf("Valor de n para as combinacoes:\n");
	scanf("%d",&n);
	printf("\n");
	char* vet=(char *)malloc(n * sizeof(char));
	char vAux[3] = "aei";
	imprimirC(vet, 0, n, vAux);
}
