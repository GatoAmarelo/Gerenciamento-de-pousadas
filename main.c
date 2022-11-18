#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "pousada.c"

#define TITULO_OPCAO1 "Adicionar Hospede" // texto exibido no menu
#define TITULO_OPCAO2 "Remover Hospede"
#define TITULO_OPCAO3 "Listar Hospedes Cadastrados"
#define TITULO_OPCAO4 "Buscar Hospede"
#define TITULO_OPCAO5 "Editar Cadastro De Hospede"
#define TITULO_OPCAO6 "Consultar Quartos Disponiveis"
#define TITULO_OPCAO7 "Consultar Quantitativo De Quartos Por Status"
#define TITULO_OPCAO8 "Sair"

#define N_OPCOES 8 // quantidade de opções do menu
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

/****
* Função: LimpaBuffer()
* Descrição: Lê e descarta caracteres encontrados na entrada
* Parâmetros: Nenhum
* Retorno: Nada
****/
void LimpaBuffer(void) {  
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}
/****
* Função: LeOpcao()
* Descrição: Lê e valida a opção digitada pelo usuário
* Parâmetros:
*   menorValor (entrada): o menor valor válido
*   maiorValor (entrada): o maior valor válido
* Retorno: A opção lida é validada
****/
int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}

/****
* Função: ApresentaMenu
* Descrição: Apresenta menu com número indeterminado de opções
* Parâmetros:
*   nItens (entrada): número de itens no menu
*   menorOpcao (entrada): caractere associado ao item I
* Retorno: Nada
****/
void ApresentaMenu(int nItens, int menorOpcao, ...) { // funcao responsavel por imprimir o menu
    int i;
    va_list argumentos;
    /* Inicia lista de argumentos variáveis */
    va_start(argumentos, menorOpcao);
    /* Lê cada argumento e imprime na tela. Note que o */
    /* tipo de cada argumento é char *, que é o tipo que */
    /* representa strings em C */
    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);/* Encerra processamento de argumentos */
}

int main(void) { 
    unsigned char op; // opcao que o usuario digita
    unsigned int saida = 0; // variável aux para sair do programa
    Lista * listadequarto = cria();
    Lista * aux=NULL; // auxiliar usado para a lista nao ser anulada quando um hospede nao for encontrado
    char nomedohospede[60];

   
    do { // repetir menu 
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, 
					  TITULO_OPCAO6, TITULO_OPCAO7, TITULO_OPCAO8);
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1); 
        
        switch(op) {
            case OPCAO1:             
                Beep(1000,500); /* Emite um beep */
                 // chamada da funcao que adiciona hospede
               Quarto * novoquarto = PreencheQuarto();
               listadequarto = InsereQuarto(listadequarto, novoquarto);
               break;
               
            case OPCAO2: // Remove Hospede

               Beep(1000,500); // Beep faz o barulho 
               printf("Digite o nome do hospede que deseja remover : \n");
               scanf(" %[^\n]", nomedohospede);
               printf("Removendo...");
               aux = RemoverHospede(listadequarto, nomedohospede);
               if(aux!=NULL){
                listadequarto = aux;
               }

                break;
 
            case OPCAO3:
                Beep(1000,500);
                ListarQuarto(listadequarto); // chama a funcao de listar quarto
                break;


            case OPCAO4: // Buscar Hospede
                Beep(1000,500);
            
                
             
               printf("Digite o nome do hospede que deseja buscar : \n");
               scanf(" %[^\n]", nomedohospede); // lendo o nome do hospede que devera ser encontrado
              
               aux = BuscaHospede(listadequarto, nomedohospede ); // chamado a funcao busca hospede
                 if(aux!=NULL){ // 
                listadequarto = aux;
               }
    
            break;
            case OPCAO5: //Editar hospede


                Beep(1000,500);
               
                // editar cadastro do hospede
                   printf("Digite o nome do hospede que deseja editar o cadastro : \n");
                   scanf(" %[^\n]", nomedohospede);
                   MudarCadastro(listadequarto);
               
                break;
            case OPCAO6:
                Beep(1000,500);
               
                
                break;
            case OPCAO7:
                Beep(1000,500);
               
                break;

            case OPCAO8:
                Beep(1000,500);
                saida = 1;
                printf("Obrigado por usar este programa.");
                break;

            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    } while(!saida);
    return 0;
}