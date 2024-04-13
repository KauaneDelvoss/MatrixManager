#include <stdio.h>
#include <stdlib.h>
const int M = 10;
const int N = 10;

void showMenu();
int main()
{
    int matrix[M][N], qtdConjuntos = 0;

    // inicializando a matriz vazia
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            matrix[m][n] = 0;
            // printf("%d ", matrix[m][n]);
        }
        // printf("\n");
    }

    // menu com as opções
    showMenu();
}

void showMenu()
{
    int option = 0;

    printf("1 - Inserir um novo conjunto vazio\n");
    printf("2 - Inserir dados a um conjunto\n");
    printf("3 - Remover um conjunto\n");
    printf("4 - Realizar união entre dois conjuntos\n");
    printf("5 - Realizar Intersecção entre dois conjuntos\n");
    printf("6 - Mostrar um conjunto de acordo com o seu índice\n");
    printf("7 - Mostrar todos os conjuntos\n");
    printf("8 - Busca por um valor\n");
    printf("9 - Sair\n");

    scanf("%d", &option);

    switch (option)
    {
    case 1:
        // createSet(matrix, qtdConjuntos);
        break;
    case 2:
        // insertSet(matrix, qtdConjuntos);
        break;
    case 3:
        // removeSet(matrix, qtdConjuntos);
        break;
    case 4:
        // unionSet(matrix, qtdConjuntos);
        break;
    case 5:
        // interssectionSet(matrix, qtdConjuntos);
        break;
    case 6:
        // showSet(matrix, qtdConjuntos);
        break;
    case 7:
        // showMatrix(matrix, qtdConjuntos);
        break;
    case 8:
        // searchValue(matrix, qtdConjuntos);
        break;
    case 9:
        // exit();
        break;
    default:
        system("cls");
        printf("Opção inválida\n\n");
        showMenu();
        break;
    }
}

// talvez vamos ter que usar ponteiros para alterar o valor de qtdConjuntos e da matriz. Seria bem mais fácil ao invés de ficar retornando de função em função.
int createSet(int qtdConjuntos)
{
    // Explicar para que serve essa funcionalidade ao usuário
    qtdConjuntos++;
    return qtdConjuntos;
}