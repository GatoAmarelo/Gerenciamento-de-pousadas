#include "pousada.h"
#include<stdio.h>

int main (){ 
	 Pousadap * lista;
	 lista = cria();
     printf("Menu da Pousada \n");
     printf("1 - Adiciona hospede \n");
     printf("2 - Remove hospede \n");
     printf("3 - Sair \n");
     printf("Digite uma opcao \n");
     int op;
     scanf("%d", &op);
     
     switch (op) {
	case 1 :
       //  lista =  InsereHospede(lista, v);
         
		break;
    case 2 : 
           printf("Remove hospede \n");
           break;
    case 3 : return (1);
}


	
	return 0;
}
