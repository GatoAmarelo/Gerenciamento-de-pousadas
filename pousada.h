
typedef struct pousadap Pousadap; 
typedef struct quarto Quarto;
typedef struct li Lista;
Quarto * PreencheQuarto(void);
Lista * cria (void);
Lista * InsereQuarto(Lista * lista, Quarto * hospede);
Lista * RemoverHospede(Lista*lista, char* nomedohospede);
void ListarQuarto(Lista *lista);
Lista * BuscaHospede(Lista*lista, char * nomedohospede);
void MudarCadastro(Lista*a);
