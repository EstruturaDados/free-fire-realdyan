#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// define uma constante par ao comprimento que cada texto pode ter
#define MAX_STR_LEN 50
// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.



// Prototipos funções
void limparTela();
void exibirMenu();
void inserirItem();
void removerItem();
void listarItems();

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os items
    // 4. Ordenar os items por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // Exibir Menu
    exibirMenu();
    
    
    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.
typedef struct {
    char nome[MAX_STR_LEN];
    char tipo[MAX_STR_LEN];
    int quantidade;
} Item;

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos items (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 items coletados.
// Variáveis de controle: numItems (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).
Item mochila[10];
int numItems = 0;

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.
void limparTela() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.
void exibirMenu() {
    int opcao;

    do {
    printf("\n--- MOCHILA DE SOBREVIVENCIA ---\n");
    printf("Total de itens: %d/10\n", numItems);
    printf("1. Adicionar item\n");
    printf("2. Remover item\n");
    printf("3. Listar items na mochila\n");
    printf("4. Buscar item por nome\n");
    printf("0. Sair\n");
    printf("--------------------------------\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
        inserirItem();
        break;
    
    case 2:
        removerItem();
        break;
    
    case 3:
        listarItems();
        break;

    case 4:
        /* 4. "Buscar item por nome" */
        break;

    case 0:
        printf("Saindo...\n");
        break;

    default:
        printf("Opção inválida!\n");
        break;
    }
    } while (opcao != 0);
}
// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
void inserirItem(){
    // Verifica se a mochila está cheia
    if (numItems >= 10) {
        printf("\nMochila cheia! Nao é possivel adicionar mais items.\n");
        return;
    }

    printf("\n--- ADICIONAR ITEM ---\n");

  
    // Solicita informação do nome
    printf("nome do item: ");
    fgets(mochila[numItems].nome, MAX_STR_LEN, stdin);
    mochila[numItems].nome[strcspn(mochila[numItems].nome, "\n")] = '\0'; // Remove o \n
    
    // Solicita informação do tipo
    printf("Tipo de item: ");
    fgets(mochila[numItems].tipo, MAX_STR_LEN, stdin);
    mochila[numItems].tipo[strcspn(mochila[numItems].tipo, "\n")] = '\0'; // Remove o \n
    
    // Solicita informação da quantidade
    printf("Quantidade: ");
    scanf("%d", &mochila[numItems].quantidade);
    getchar();

    numItems++;
    printf("\nItem adicionado com sucesso!\n");

}
// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void removerItem() {
    // Verifica se a mochila está vazia
    if (numItems == 0) {
        printf("\nMochila vazia! Não há items para remover.\n");
        return;
    }

    // Declara variavel nomeBusca[MAX_STR_LEN]
    char nomeBusca[MAX_STR_LEN];
    // Le entrada do usuario nome do item a ser removido
    printf("\n--- REMOVER ITEM ---\n");
    printf("Digite o nome do item a remover: ");
    fgets(nomeBusca, MAX_STR_LEN, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    // variavel indiceEncontrado para ser na busca do item pelo nome
    int indiceEncontrado = 1;
    // Busca o item pelo nome
    for (int i = 0; i < numItems; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            indiceEncontrado = i;
        }
    }

    // Se não encontrou o item
    if (indiceEncontrado == -1) {
        printf("\nItem '%s' não encontrado na mochila!\n", nomeBusca);
        return;
    }

    // Reorganiza o vetor, movendo os items para preencher o espaço
    for (int i = indiceEncontrado; i < numItems - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    numItems--;
    printf("\nItem removido com sucesso!\n");

}
// listarItems():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.
void listarItems() {
    if (numItems == 0) {
        printf("\nMochila vazia! Nehum item para exibir.");
        return;
    }

    printf("\n--- ITENS NA MOCHILA ===\n");
    printf("%-30s %-20s %-10s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("----------------------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf("%-30s %-20s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }

    printf("----------------------------------\n");
    printf("Total de itens: %d/10\n", numItems);
}
// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
