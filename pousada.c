#include <stdio.h> 
#include <stdlib.h> 
#include<string.h>
#include "pousada.h"


struct quarto{
	    char hospede[60];
	    float preco;
	    int numero;
	    int tipo;
	    int duracao;
	    char status[60];
		
};

struct li{
	struct quarto* info;
	struct li* prox;
	
	
};

struct pousadap{
	   char nome[60];
	   char localizacao[60];
	   int avaliacao;
	   int quartos;
      
};   
    
	int disp = 0;
	int inds = 0;
	int manu = 0;
	int pequeno = 0;
    int grande = 0, medio = 0;
	int otimo =0, bom =0, ruim =0, media=0;
    
Pousadap * PousadaPreenche(void){
	       FILE *arquivo = fopen("pousadx.txt", "a");
           if(arquivo == NULL){
           printf("Erro ao abrir o arquivo");
           exit(1); 
		 }

	      Pousadap * l = (Pousadap*) malloc(sizeof(Pousadap));
          printf("Digite o nome da pousada : \n"); 
          scanf(" %[^\n]", l->nome);
          printf("Digite a localizacao da pousada : \n");
          scanf(" %[^\n]", l->localizacao);

		  printf("...\n");
		  printf("Ha tres tipos de quartos na pousada : \nPequeno, medio e grande\n");
		  printf("Digite a disponibilidade em cada uma das tres categorias\n");
		  printf("Quantos quartos pequenos tem disponiveis na pousada ? \n");
		  scanf("%d", &pequeno);
		  printf("Quantos quartos medios tem disponiveis na pousada ? \n");
		  scanf("%d", &medio);
		  printf("Quantos quartos grandes tem disponiveis na pousada ? \n");
		  scanf("%d", &grande);
		  disp = (pequeno+grande+medio);
		  printf("Existe algum quarto em manutencao ? se sim, digite a quantidade \n");
		  scanf("%d", &manu);

		  fprintf(arquivo,"\nNome da Pousada : %s : Localizacao : %s\n",l->nome,l->localizacao);
          return l;

		 fclose(arquivo);
}
 
Quarto * PreencheQuarto(void){
    
    FILE *arquivor = fopen("pousadx.txt", "a");
         if(arquivor == NULL){
         printf("Erro ao abrir o arquivo");
         exit(1); 
		 }

	Quarto * novoQuarto = (Quarto*) malloc(sizeof(Quarto)); 
    
	 
	if(disp == 0){
		printf("Nao ha mais quartos disponiveis no momento e os outros se encontram em manutencao");
		printf("Por favor, volte mais tarde");
		return 0;
	}

    
    
    printf("Digite o nome do hospede: \n");
    scanf(" %[^\n]", novoQuarto->hospede); 
    printf("Digite o preco : ");
    scanf("%f", &novoQuarto->preco);
    printf("Digite o numero do quarto : \n");
    scanf("%d", &novoQuarto->numero);
    printf("Qual tipo de quarto deseja ? \n");
	printf("1 Pequeno \n2 Medio  \n3 Grande \n");
    scanf("%d", &novoQuarto->tipo);
     
     switch (novoQuarto->tipo){
		case 1 :
		inds ++;
		disp --;
		pequeno --;
        break;
		case 2 :
		inds ++;
		disp --;
		medio--;
		break;
		case 3 :
		inds ++;
		disp --;
		grande--;
		break;
		default :
		printf("Erro ao escolher quarto\n");
		printf("Quarto sendo escolhido pela pousada\n");
		novoQuarto->tipo = 2;
		medio--;
		inds ++;
		disp --;
		break;

	 }
      
	printf("Quantos dias deseja ficar ? \n");
    scanf("%d", &novoQuarto->duracao);

    
    printf("=== Cadastro do quarto realizado com sucesso ! ===\n");
    
	printf("=== Avalie a pousada ===\n");
	printf("1 Otimo;\n2 Bom;\n3 medio;\n4 ruim; \n");
    Pousadap *avalia = (Pousadap*) malloc(sizeof(Pousadap));
    scanf("%d", &avalia->avaliacao);
    
	
	if(avalia->avaliacao == 1){
		otimo++;
	} else if(avalia->avaliacao == 2){
		bom++;
	}else if(avalia->avaliacao == 3){
		media++;
	}else if(avalia->avaliacao == 4){
		ruim++;
	} else{
		printf("Erro ao fazer avaliacao\n");
	} 

	

    
     fprintf(arquivor, "\nHospede : %s  Preco : %.2f R$  Numero : %d  Tipo : %d  Duracao da estadia : %d dias\n", novoQuarto->hospede, novoQuarto->preco, novoQuarto->numero, novoQuarto->tipo, novoQuarto->duracao);
    
	 fprintf(arquivor, "\nAvaliacao dos clientes :  Otimo %d Bom %d Medio %d Ruim %d\n",otimo, bom, media, ruim);
    
  
		 return novoQuarto;

	 fclose(arquivor); 
	}
	
    	
 Lista * cria (void){ 
     return NULL;
	  } 

 Lista * InsereQuarto(Lista * lista, Quarto * hospede){ 
	Lista * novo = (Lista*)malloc(sizeof(Lista));
	novo -> info = hospede;
	novo -> prox = lista;
 	return novo; 
	}



Lista * RemoverHospede(Lista*lista, char* nomedohospede){
Lista* ant = NULL; 
    Lista* ponteiro = lista; 
   
    while(strcmp(ponteiro->info->hospede,nomedohospede)!= 0){
    	if (ponteiro==NULL){
        	return lista; 
			}
			
        ant = ponteiro;
        ponteiro = ponteiro->prox;

    }
    
    if (ant==NULL)
    
        lista = ponteiro->prox;
    else
    
        ant->prox = ponteiro->prox;
        free(ponteiro);
		inds--;

    return lista;
}

void imprime_quarto(Quarto*q){
	printf("============================== \n");
	printf("=== Nome do Hospede : %s  \n", q->hospede);
	printf("=== Preco : %.2f reais       \n", q->preco);
	printf("=== Numero do Quarto : %d  \n", q->numero);
	printf("=== Tipo de Quarto : %d    \n",q->tipo);
	printf("==  Dias : %d        \n",q->duracao); 
    printf("============================== \n");
	
}


void ListarQuarto(Lista *lista){ 
	Lista * aux; 
    for(aux=lista; aux!=NULL; aux=aux->prox) { 
	imprime_quarto (aux->info); 
	} 
    if(lista==NULL){ 
		printf("===Nenhum hospede cadastrado===\n");
	}
}




Lista * BuscaHospede(Lista*lista, char * nomedohospede){ 
	     Lista * no; 

	    for(no=lista;no!=NULL;no=no->prox) { 
		if(strcmp(no->info->hospede, nomedohospede)== 0){
			printf("====== Hospede encontado ===== \n");
			printf(" Dados do Hospede :  \n");
        	printf("=== Nome do Hospede : %s  \n", no->info->hospede);
	        printf("=== Preco : %.2f reais      \n", no->info->preco);
	        printf("=== Numero do Quarto : %d  \n", no->info->numero);
	        printf("=== Tipo de Quarto : %d     \n",no->info->tipo);
	        printf("==  Dias : %d        \n",no->info->duracao); 
            printf("============================== \n");
        

			  
			return no;
		}  
	  }
	  printf("=== Hospede nao encontrado === \n");
	  return NULL; 
}


void MudarCadastro(Lista * lista){
	    
		

		Quarto * edita = (Quarto*) malloc(sizeof(Quarto)); 
	    Lista * aux = NULL; 

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
        printf("1 - Pequeno \n2 - Medio  \n3 - Grande \n");
        scanf("%d", &edita->tipo);
		switch (edita->tipo){
		case 1 :
		pequeno --;
        break;
		case 2 :
		medio--;
		break;
		case 3 :
		grande--;
		break;
		default :
		printf("Erro ao escolher quarto\n");
		printf("Quarto sendo escolhido pela pousada\n");
		edita->tipo = 2;
		medio--;
		break;

	 }
	
        printf("Quantos dias deseja ficar ? \n");
        scanf("%d", &edita->duracao);

	
} 





