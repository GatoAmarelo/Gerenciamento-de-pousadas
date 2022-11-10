#include <stdio.h> 
#include <stdlib.h> 

#include "pousada.h"


struct quarto{
	    char hospede[60];
	    float preco;
	    int numero;
	    char tipo[60];
	    int duracao;
	    int status;
	    
};

struct lista{
	struct quarton* info;
	struct lista * prox;
	
}

struct pousadap{
	   char nome[50];
	   char localizacao;
	   int avaliacao;
	   struct quarto info;
};






void PreencheQuarto(char *nomeArquivo){
    
    Pousadap q; 
    printf("Digite o nome do hospede: \n");
    scanf("%s", q.info.hospede); // q-> pois foi usado um ponteiro para Pousadap: typedef struct pousadap *Pousadap;
    printf("Digite o preco : ");
    scanf("%f", &q.info.preco);
    printf("Digite o numero do quarto : \n");
    scanf(" %d", &q.info.numero);
   printf("Qual tipo de quarto deseja ? \n");
   scanf("%s", q.info.tipo);
    printf("Quantos dias deseja ficar ? \n");
    scanf("%d", &q.info.duracao);

	
    printf("Cadastro do quarto realizado com sucesso ! \n");
    
    
   int otimo = 0, bom = 0, ruim =0, medio=0;
   
   
	printf("Avalie a pousada \n");
	printf("1 Otimo;\n2 Bom;\n3 medio;\n4 ruim; \n");
	scanf("%d", &q.avaliacao);
	
	switch (q.avaliacao){ // avaliando a pousada
		case 1 :
			otimo++; // caso o usuario escolha a primeira opcao (Otimo) recebe + 1
			break;
		    
		case 2 :
			bom++ ;
			break;
		
		case 3 :
		    medio ++;
		    break;
		case 4 :
			ruim++;
			break;
		
		default :
			printf("Opcao invalida !\n");
			break;
		  }

      
	
    FILE *arquivo = fopen(nomeArquivo, "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1); 
    }

     
	
          fprintf(arquivo, "\nHospede : %s \t Preco : %.2f R$ \t Numero : %d \t Tipo : %s \t Duracao da estadia : %d dias \n", q.info.hospede, q.info.preco, q.info.numero, q.info.tipo, q.info.duracao);
          fprintf(arquivo, "Avaliaï¿½ï¿½o do cliente :  Otimo (%d) Bom (%d) Medio (%d) Ruim (%d)",otimo, bom, medio, ruim);
          

	   fclose(arquivo);
	}
	
	
 Pousadap * cria (){ // criando uma lista
	Pousadap * lista = (Pousadap*) malloc(sizeof(Pousadap));
	   if (lista!=NULL)
		   lista = NULL;
		   return lista;	   
}

//int InsereHospede(Pousadap * lista){
//	Pousadap * novo = (Pousadap*)malloc(sizeof(Pousadap));
//	novo -> info = // preenchequarto ;
//	novo -> prox = lista;
// 	return novo;}
