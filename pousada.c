#include <stdio.h> 
#include <stdlib.h> 
#include<string.h>
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
    
    FILE *arquivor = fopen("pousadax.txt", "r");
         if(arquivor == NULL){
         printf("Erro ao abrir o arquivo");
         exit(1); 
		 }
    
         
	Quarto * novoQuarto = (Quarto*) malloc(sizeof(Quarto)); // alocando um quarto


  //  Pousadap avalia;

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

	
    printf("=== Cadastro do quarto realizado com sucesso ! ===\n");
 /** printf("Avalie a pousada \n");
	printf("1 Otimo;\n2 Bom;\n3 medio;\n4 ruim; \n");
    
    scanf("%d", &avaliacao);




    
   int otimo = 0, bom = 0, ruim =0, medio=0;
   
	   switch (avalia.avaliacao){ // avaliando a pousada
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
			
		  }
        
		
      
 
*/

      fprintf(arquivor, "\nHospede : %s \t Preco : %.2f R$ \t Numero : %d \t Tipo : %s \t Duracao da estadia : %d dias \n", novoQuarto->hospede, novoQuarto->preco, novoQuarto->numero, novoQuarto->tipo, novoQuarto->duracao);
  //    fprintf(arquivor, "Avaliacao do cliente :  Otimo %d Bom %d Medio %d Ruim %d",otimo, bom, medio, ruim);
          
     // fprintf(arquivor,"avaliacao %d", avalia.avaliacao);

	  
	  
		 return novoQuarto;


      
	

	 fclose(arquivor); 
	}
	
 	
 Lista * cria (void){ // criando uma lista
     return NULL;
	  } // certo

 Lista * InsereQuarto(Lista * lista, Quarto * hospede){ // adicionando hospede 
	Lista * novo = (Lista*)malloc(sizeof(Lista));
	novo -> info = hospede;
	novo -> prox = lista;
 	return novo; //tudo certo
	}



Lista * RemoverHospede(Lista*lista, char* nomedohospede){
Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* ponteiro = lista; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(strcmp(ponteiro->info->hospede,nomedohospede)!= 0){ // strcmp comparando os nomes
    	if (ponteiro==NULL){
        	return lista; 
			}
			/* n?o achou: retorna lista original */
        ant = ponteiro;
        ponteiro = ponteiro->prox;
            /* verifica se achou elemento */

    }
    /* retira elemento */
    if (ant==NULL)
    /* retira elemento do inicio */
        lista = ponteiro->prox;
    else
    /* retira elemento do meio da lista */
        ant->prox = ponteiro->prox;
    free(ponteiro);
    return lista;
}

void imprime_quarto(Quarto*q){
	printf("============================== \n");
	printf("=== Nome do Hospede : %s  \n", q->hospede);
	printf("=== Preco : %.2f reais       \n", q->preco);
	printf("=== Numero do Quarto : %d  \n", q->numero);
	printf("=== Tipo de Quarto : %s     \n",q->tipo);
	printf("==  Dias : %d        \n",q->duracao); // certo
    printf("============================== \n");
}


void ListarQuarto(Lista *lista){ // listar hospedes cadastrados
	Lista * aux; // variavel auxiliar para percorrer a lista
    for(aux=lista; aux!=NULL; aux=aux->prox) { //enquanto a variavel aux nao chegar ao final da lista, aux aponta para o proximo
	imprime_quarto (aux->info); // chamando a funcao imprimir
	} // aux->info = elemento da lista
    if(lista==NULL){ // se nenhum hospede tiver sido cadastrado // verificando se a lista esta vazia
		printf("===Nenhum hospede cadastrado===\n");
	}
}




Lista * BuscaHospede(Lista*lista, char * nomedohospede){ // buscar hospede
	     Lista * no; 

	    for(no=lista;no!=NULL;no=no->prox) { // percorrendo a lista
		if(strcmp(no->info->hospede, nomedohospede)== 0){// verificando se o elemento e igual a nomehospede	
			printf("====== Hospede encontado ===== \n");
			printf(" Dados do Hospede :  \n");
        	printf("=== Nome do Hospede : %s  \n", no->info->hospede);
	        printf("=== Preco : %.2f reais      \n", no->info->preco);
	        printf("=== Numero do Quarto : %d  \n", no->info->numero);
	        printf("=== Tipo de Quarto : %s     \n",no->info->tipo);
	        printf("==  Dias : %d        \n",no->info->duracao); 
            printf("============================== \n");
        

			  
			return no;
		}  // retorna no da lista e o hospede e encontrado
	  }
	  printf("=== Hospede nao encontrado === \n");
	  return NULL; // nao achou o hospede
}



 void MudarCadastro(Lista * lista){
	    
		

		Quarto * edita = (Quarto*) malloc(sizeof(Quarto)); // alocando um quarto 
	    Lista * aux = NULL; // auxiliar 

        printf("Digite o nome do hospede que deseja editar o cadastro : \n");
        scanf(" %[^\n]", edita->hospede); 

        aux = BuscaHospede(lista, edita->hospede);
       if(aux!=NULL){
                lista = aux;
				lista->info = edita;
               }

		printf("Mude o nome do hospede : \n");
		scanf(" %[^\n]", edita->hospede);
        printf("Digite o novo preco : ");
        scanf("%f", &edita->preco);
        printf("Digite o numero do quarto : \n");
        scanf("%d", &edita->numero);
        printf("Qual tipo de quarto deseja ? \n");
        scanf(" %[^\n]", edita->tipo);
        printf("Quantos dias deseja ficar ? \n");
        scanf("%d", &edita->duracao);

	
} 




