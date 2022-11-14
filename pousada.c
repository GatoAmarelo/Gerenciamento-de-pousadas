#include <stdio.h> 
#include <stdlib.h> 

#include "pousada.h"


struct quarto{
	    char hospede[60];
	    float preco;
	    int numero;
	    char tipo[60];
	    int duracao;
	    char status[60];
	    
};

struct li{
	struct quarto* info;
	struct li* prox;
	
};

struct pousadap{
	   char nome[50];
	   char localizacao;
	   int avaliacao;
	   Lista * quartos;
};






Quarto * PreencheQuarto(void){

	Quarto * novoQuarto = (Quarto*) malloc(sizeof(Quarto));
	
    
    //Pousadap q; 
    printf("Digite o nome do hospede: \n");
    scanf(" %[^\n]", novoQuarto->hospede); // q-> pois foi usado um ponteiro para Pousadap: typedef struct pousadap *Pousadap;
    printf("Digite o preco : ");
    scanf("%f", &novoQuarto->preco);
    printf("Digite o numero do quarto : \n");
    scanf("%d", &novoQuarto->numero);
    printf("Qual tipo de quarto deseja ? \n");
    scanf(" %[^\n]", novoQuarto->tipo);
    printf("Quantos dias deseja ficar ? \n");
    scanf("%d", &novoQuarto->duracao);

	
    printf("Cadastro do quarto realizado com sucesso ! \n");
    
    
  // int otimo = 0, bom = 0, ruim =0, medio=0;
   
   
	//printf("Avalie a pousada \n");
	//printf("1 Otimo;\n2 Bom;\n3 medio;\n4 ruim; \n");
	//scanf("%d", &q.avaliacao);
	
	//switch (q.avaliacao){ // avaliando a pousada
	//	case 1 :
	//		otimo++; // caso o usuario escolha a primeira opcao (Otimo) recebe + 1
	//		break;
		    
	//	case 2 :
		/*	bom++ ;
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
          fprintf(arquivo, "Avaliacao do cliente :  Otimo (%d) Bom (%d) Medio (%d) Ruim (%d)",otimo, bom, medio, ruim);
          

	   fclose(arquivo); */ 
       return novoQuarto;
	}
	
 	
 Lista * cria (void){ // criando uma lista
     return NULL;
	  }

 Lista * InsereQuarto(Lista * lista, Quarto * hospede){ // adicionando hospede 
	Lista * novo = (Lista*)malloc(sizeof(Lista));
	novo -> info = hospede;
	novo -> prox = lista;
 	return novo;
	}


Lista * RemoverHospede(Lista*lista, char* nomedohospede){ //remover hospede
      Lista * ant = NULL; 
	  Lista * p = lista;
	  while(p->info->hospede!= nomedohospede)
	  if (p==NULL)
	  return lista;
	  ant = p;
	  	  p = p-> prox;

 }



void imprime_quarto(Quarto*q){
	printf("%s \n", q->hospede);
	printf("%f \n", q->preco);
	printf("%d \n", q->numero);
	printf("%s \n",q->tipo);
	printf("%d \n",q->duracao);
}

void ListarQuarto(Lista *lista){ // listar hospedes cadastrados
	Lista * aux; // variavel auxiliar para percorrer a lista
    for(aux=lista; aux!=NULL; aux=aux->prox) {
	imprime_quarto (aux->info);
	}
    if(lista==NULL){ // se nenhum hospede tiver sido cadastrado // verificando se a lista esta vazia
		printf("Nenhum hospede cadastrado");
	}
}




Lista * BuscaHospede(Lista*lista, char * nomedohospede){ // buscar hospede
	  Lista * p; 
	  for(p=lista;p!=NULL;p=p->prox){ // percorrendo a lista
		if(strcmp(p->info->hospede, nomedohospede)== 0) // verificando se o elemento e igual a nomehospede
		printf("Hospede encontado");
		return p; // retorna no da lista e o hospede e encontrado
	  }
	  printf("Hospede nao encontrado");
	  return NULL; // nao achou o hospede
}




