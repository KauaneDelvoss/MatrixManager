#include <stdio.h>
#include <stdlib.h>
const int M = 5;
const int N = 5;

void showMenu(int matrix[][N], int qtdConjuntos);
void showMatrix(int matrix[][N], int qtdConjuntos);
int main()
{
    int matrix[M][N], qtdConjuntos = 4;

    // inicializando a matriz vazia
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            matrix[m][n] = 0;
            //printf("%d ", matrix[m][n]);
        }
        //printf("\n");
    }
    
    //printa matriz
    showMatrix(matrix, qtdConjuntos);
    // menu com as opções
    showMenu(matrix, qtdConjuntos);
}

void showMatrix(int matrix[][N], int qtdConjuntos){
    for (int m = 0; m < qtdConjuntos; m++)
    {
        for (int n = 0; n < N; n++)
        {   
            if(n==0) printf("(%d) - ",m);
            printf("%d ", matrix[m][n]);
        }
        printf("\n");
    }
}


int createSet(int matrix[][N], int qtdConjuntos);
int removeSet(int matrix[][N], int qtdConjuntos);

void showMenu(int matrix[][N], int qtdConjuntos)
{
    int option = 0;
    do {
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
            qtdConjuntos = createSet(matrix, qtdConjuntos);
            break;
        case 2:
            // insertSet(matrix, qtdConjuntos);
            break;
        case 3:
            qtdConjuntos = removeSet(matrix, qtdConjuntos);
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
            showMatrix(matrix, qtdConjuntos);
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
            showMenu(matrix, qtdConjuntos);
            break;
        }
    } while (option != 9);
}

// talvez vamos ter que usar ponteiros para alterar o valor de qtdConjuntos e da matriz. Seria bem mais fácil ao invés de ficar retornando de função em função.
int createSet(int matrix[][N],int qtdConjuntos)
{
    if(qtdConjuntos < M){
        // Explicar para que serve essa funcionalidade ao usuário
        printf("\nAdicionando 1 conjunto a matriz. \n\n");
        qtdConjuntos++;
        // Adiciona uma nova linha zerada.
        for (int m = 0; m < qtdConjuntos; m++)
        {
            for (int n = 0; n < N; n++)
            {
                if(m - 1 == qtdConjuntos){
                    matrix[m][n] = 0;
                }
            }
        }
        return qtdConjuntos;
    }
    printf("\nA matriz ja contem %d conjuntos, nada foi feito. \n\n", M);
    return qtdConjuntos;
}

int removeSet(int matrix[][N],int qtdConjuntos)
{
    int removingSet = M + 1;
    printf("Matriz atual: \n");
    showMatrix(matrix, qtdConjuntos);
    printf("Selecione o index do conjunto que deseja remover: \n");
    scanf("%d", &removingSet);
    if(removingSet > qtdConjuntos - 1 || removingSet < 0){
        printf("Valor invalido selecionado, nada foi feito. \n\n");
        return qtdConjuntos;
    }
    //int newMatrix[qtdConjuntos - 1][N];
    for (int m = removingSet; m < qtdConjuntos - 1; m++)
    {
        for (int n = 0; n < N; n++)
        {
            matrix[m][n] = matrix[m + 1][n];
        }
    }
    
    showMatrix(matrix, qtdConjuntos - 1);
    //matrix = newMatrix;
    return qtdConjuntos - 1;
}



