#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char nomes[50][50];
float precos[50];
int estoque[50];
int total = 0;

float totalVendido = 0;

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
    if (total >= 50) {
        printf("\nLIMITE DE PRODUTOS ATINGIDO!\n");
        return;
    }

    printf("\nNome do produto: ");
    scanf("%s", nomes[total]);

    printf("Preço: ");
    scanf("%f", &precos[total]);

    printf("Quantidade no estoque: ");
    scanf("%d", &estoque[total]);

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
        printf("%d - %s | R$ %.2f | Estoque: %d\n",
                i + 1, nomes[i], precos[i], estoque[i]);
    }

    printf("\n");
}

// COMPRAR
void comprar() {
    int codigo, quantidade;

    if (total == 0) {
        printf("\nSem produto cadastrado para comprar\n");
        return;
    }
    listar();

    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    codigo--;

    if (codigo < 0 || codigo >= total) {
        printf("Código Inválido\n");
        return;
    }
    printf("Quantidade que deseja: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade Inválida\n");
        return;
    }
    if (quantidade > estoque[codigo]) {
        printf("Estoque insuficiente. Atual estoque: %d\n", estoque[codigo]);
        return;
    }

    estoque[codigo] -= quantidade;

    float valorCompra = quantidade * precos[codigo];
    totalVendido += valorCompra;

    printf("Compra feita. Total da compra: R$ %.2f\n", valorCompra);
    printf("Estoque restante de %s: %d\n\n", nomes[codigo], estoque[codigo]);
}
//TOTAL VENDIDO
void mostrarTotalVendido(){
    printf("VALOR TOTAL: R$ %.2f\n\n", totalVendido);
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
        printf("\n---- MENU ----\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Comprar\n");
        printf("4 - Total de Compras\n");
        printf("5 - Sair\n");
        printf("\nOpção: \n");
        scanf("%d", &opcao);

       switch (opcao){
        case 1:
            cadastrar();
            break;

        case 2:
            listar();
            break;

        case 3:
            comprar();
            break;

        case 4:
            mostrarTotalVendido();
            break;

        case 5:
            printf("Saindo");
            break;

        default:
            printf("\nOpção Inválida\n");
            break;
       }


    } while (opcao != 5);

    return 0;
}

