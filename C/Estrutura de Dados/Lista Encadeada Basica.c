#include <stdio.h>
#include <stdlib.h>

// Criando Nós do tipo Aluno.
typedef struct Aluno
{
    int matricula;
    float notas[4];
    float media;
    int aprovado;
    struct Aluno *proximo;
} Aluno;

// Criando A lista de Alunos.
typedef struct Lista
{
    Aluno *primeiro;
    int tamanho;
} Lista;

// O cadastro é "simples", ele adiciona um aluno novo ao
// fim da lista. Da mesma forma como uma fila.
void Cadastrar(Lista *lista);

//Essa função faz o óbvio, ela lista os alunos.
void ListarAlunos(Lista *lista);

int main()
{
    int escolha;

    // Montando a struct listaDeAlunos.
    Lista listaDeAlunos;
    listaDeAlunos.tamanho = 0;
    listaDeAlunos.primeiro = NULL;

    do
    {
        printf("--------------------------\n");
        printf("    TERMINAL DA ESCOLA    \n");
        printf("--------------------------\n");
        printf("    [1] Cadastrar Aluno   \n");
        printf("    [2] Listar Alunos     \n");
        printf("    [3] Sair              \n");
        printf("--------------------------\n");
        printf(">");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
            Cadastrar(&listaDeAlunos);
            break;

        case 2:
            ListarAlunos(&listaDeAlunos);
            break;

        case 3:
            printf("Obrigado por me testar :)\n");
            break;

        default:
            printf("ERROR: comando invalido\n");
            break;
        }

    } while (escolha != 4);

    return 0;
}

void Cadastrar(Lista *lista){

    // Criando um lugar na memória e armazenando esse lugar num ponteiro.
    // Vamos também zerar esse nó para não ter problemas com valores lixo.
    Aluno *No = (Aluno *)calloc(1, sizeof(Aluno));
    No->aprovado = 0;
    No->matricula = 0;
    No->media = 0;
    No->notas[0] = 0;
    No->proximo = NULL;

    lista->tamanho++;

    // Esta seção de código destina-se a encaixar o Nó em algum ponto na lista, no final ou
    // no inicio.
    // Se a lista estiver vazia, o nó que criamos será o primeiro da lista.
    if (lista->primeiro == NULL)
    {
        lista->primeiro = No;
    }

    // Caso o contrário, vamos percorrer a lista inteira até achar o ultimo nó.
    // e então cadastrar o nó que criamos depois do ultimo.
    else
    {
        Aluno *ultimo = lista->primeiro;

        while (ultimo->proximo != NULL)
        {
            ultimo = ultimo->proximo;
        }

        ultimo->proximo = No;
    }
    // Fim da seção de código que destina-se a encaixar o Nó em algum ponto na lista.

    // A seção de código abaixo destina-se a cadastrar o aluno.
    No->media = 0;
    printf("Insira os dados do aluno:\n\n");

    // Salvando a matrícula
    printf("Insira o numero de matricula: ");
    scanf("%i", &No->matricula);

    // Salvando as notas no vetor;
    for (int i = 0; i < 4; i++)
    {

    initio:
        printf("Insira a nota da avaliacao %i: ", i + 1);
        scanf("%f", &No->notas[i]);

        // Se o usuário inserir uma nota inválida, a interação retorna a initio.
        if (No->notas[i] > 10 || No->notas[i] < 0)
        {
            printf("ERROR: Voce inseriu uma nota invalida\n");
            goto initio;
        }

        else
        {
            No->media = No->media + No->notas[i];
        }
    }

    // Calculando a média.
    No->media = (No->media) / 4;

    // Dando a situação do aluno
    if (No->media >= 7)
    {
        No->aprovado = 1;
    }
    else
    {
        No->aprovado = 0;
    }
    // Fim da seção de código que destinava-se a cadastrar o aluno.
}


void ListarAlunos(Lista *lista){

    //O aluno atual é o primeiro aluno da lista.
    Aluno *atual = lista->primeiro;
    int contador=0;

    while (atual!=NULL){

        printf("---------------------------------\n");
        printf("         DADOS DO ALUNO %i       \n", contador+1);
        printf("---------------------------------\n");
        printf("Matricula.....%i\n",atual->matricula);
        printf("Nota 1........%.2f\n", atual->notas[0]);
        printf("Nota 2........%.2f\n", atual->notas[1]);
        printf("Nota 3........%.2f\n", atual->notas[2]);
        printf("Nota 4........%.2f\n", atual->notas[3]);
        printf("Media Final...%.2f\n", atual->media);
        printf("Situacao......");
        atual->aprovado == 1? printf("Aprovado!\n") : printf("Reprovado\n");


        //Passando para o proximo aluno
        atual = atual->proximo;
        contador++;
    }
}


