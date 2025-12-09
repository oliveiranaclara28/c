#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char nomes[50][50];
float precos[50];
int estoque [50];
int total = 0;

// LOGIN
int login() {
    char user[20], senha[20];

    printf("Usuario: ");
    scanf("%s", user);

    printf("Senha: ");
    scanf("%s", senha);

    if (strcmp(user, "farmcz") == 0 && strcmp(senha, "442266") == 0) {
        return 1;
    }

    return 0;
}

// CADASTRAR
void cadastrar() {
    printf("\nNome do produto: ");
    scanf("%s", nomes[50]);

    printf("Preço: ");
    scanf("%f", &precos[50]);

    printf("Quantidade no estoque: ");
    scanf("%d", &estoque[50]);

    total++;

    printf("PRODUTO CADASTRADO!\n");
}

// LISTAR
void listar() {
    if (total == 0) {
        printf("\nNENHUM PRODUTO CADASTRADO\n");
        return;
    }

    printf("\nPRODUTOS CADASTRADOS\n");

    for (int i = 0; i < total; i++) {
        printf("%d - %s | R$ %.2f\n | Estoque: %d\n", i + 1, nomes[i], precos[i], estoque[i]);
    }

    printf("\n");
}
    // COMPRAR
    void comprar(){
    int codigo, quantidade;

    if (total == 0){
        printf("\nSem produto cadastrado para comprar\n");
        return;
    }
    listar();

    printf("Digite o código do produto");
    scanf("%d", &codigo);
    codigo--;

    if (codigo < 0 || codigo>= total){
        printf("Código Inválido");
        return;
    }
    printf("Quantidade que deseja: ");
    scanf("%d", &quantidade);

    if(quantidade <= 0){
        printf("Quantidade Inválida\n");
        return;
    }
    if(quantidade > estoque[codigo]){
        printf("Estoque insuficiente. Atual estoque: %d\n", estoque[codigo]);
        return;
    }

    estoque[codigo] -= quantidade;

    printf("Compra feita. Estoque restante de %s: %d\n", nomes[codigo], estoque[codigo]);
    }
    // BAIXO ESTOQUE
    void estoqueBaixo(){
    int encontrou = 0;

    printf("\nRELATÓRIO DE ESTOQUE BAIXO\n");

    for (int i =0; i< total; i++){
        if (estoque[i] <= 5){
            printf("%s | Estoque: %d | Preço: R$ %.2f\n", nomes[i], estoque[i], precos[i]);
            encontrou = 1;
        }
    }

    if (!encontrou){
        printf("Sem produto com baixo estoque\n");
    }

    printf("\n");

    }

// MAIN E MENU
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    printf("----- LOGIN -----\n");

    if (!login()) {
        printf("Login incorreto!\n");
        return 0;
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Comprar\n");
        printf("4 - Sair\n");
        printf("5 - Relatório de Baixo Estoque\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrar();
        }
        else if (opcao == 2) {
            listar();
        }
    else if(opcao == 3){
        comprar();
    }
        else if (opcao == 5 ){
            estoqueBaixo();
        }

    } while (opcao != 4);

    printf("Saindo\n");
    return 0;
}
