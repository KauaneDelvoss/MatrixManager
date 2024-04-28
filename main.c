#include <time.h>
#include <stdio.h>
#include <stdlib.h>

const int M = 5;
const int N = 5;

int createSet(int matrix[][N], int qtdConjuntos);
int removeSet(int matrix[][N], int qtdConjuntos);
void showMenu(int matrix[][N], int qtdConjuntos);
void showMatrix(int matrix[][N], int qtdConjuntos);
void insertSet(int matrix[][N], int qtdConjuntos);
int unionSet(int matrix[][N], int qtdConjuntos);
int searchValue(int item, int matrix[][N], int begin, int end, int row);
int interSecctionSet(int matrix[][N], int qtdConjuntos);

int main()

{
	int matrix[M][N], qtdConjuntos = 4;

	srand(time(0));

	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			int aux = n > 1 ? 0 : rand() % 11;
			matrix[m][n] = aux;
		}
	}
	showMatrix(matrix, qtdConjuntos);
	showMenu(matrix, qtdConjuntos);
}

void showMatrix(int matrix[][N], int qtdConjuntos) {
	for (int m = 0; m < qtdConjuntos; m++) {
		for (int n = 0; n < N; n++) {
			if (n == 0)
				printf("(%d) - ", m);
			printf("%d ", matrix[m][n]);
		}
		printf("\n");
	}
}

void showSet(int matrix[][N], int qtdConjuntos) {
	int index = 0;

	printf("A matriz possui %i conjuntos. Qual você deseja visualizar?", qtdConjuntos);
	scanf("%i", &index);
	printf("[ ");

	for (int m = 0; m < N; m++) {
		printf(" %i ", matrix[index][m]);
	}
	printf(" ]");
}

void showMenu(int matrix[][N], int qtdConjuntos) {
	int option = 0;

	do

	{
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
				insertSet(matrix, qtdConjuntos);
				break;
			case 3:
				qtdConjuntos = removeSet(matrix, qtdConjuntos);
				break;
			case 4:
				qtdConjuntos = unionSet(matrix, qtdConjuntos);
				break;
			case 5:
				qtdConjuntos = interSecctionSet(matrix, qtdConjuntos);
				break;
			case 6:
				showSet(matrix, qtdConjuntos);
				break;
			case 7:
				showMatrix(matrix, qtdConjuntos);
				break;
			case 8:
				searchValue(0, matrix, 0, N - 1, -1);
				break;
			case 9:
				exit;
				break;
			default:
				system("cls");
				printf("Opção inválida\n\n");
				showMenu(matrix, qtdConjuntos);
				break;
		}
	} while (option != 9);
}

int createSet(int matrix[][N], int qtdConjuntos) {

	if (qtdConjuntos < M) {

		printf("\nAdicionando 1 conjunto a matriz. \n\n");
		qtdConjuntos++;

		for (int m = 0; m < qtdConjuntos; m++) {

			for (int n = 0; n < N; n++) {

				if (m + 1 == qtdConjuntos)
				{
					matrix[m][n] = 0;
				}
			}
		}

		return qtdConjuntos;
	}

	printf("\nA matriz ja contem %d conjuntos, nada foi feito. \n\n", M);

	return qtdConjuntos;
}

int removeSet(int matrix[][N], int qtdConjuntos) {

	int removingSet = M + 1;

	printf("Matriz atual: \n");

	showMatrix(matrix, qtdConjuntos);

	printf("Selecione o index do conjunto que deseja remover: \n");

	scanf("%d", &removingSet);

	if (removingSet > qtdConjuntos - 1 || removingSet < 0) {
		printf("Valor invalido selecionado, nada foi feito. \n\n");

		return qtdConjuntos;
	}


	for (int m = removingSet; m < qtdConjuntos - 1; m++) {
		for (int n = 0; n < N; n++) {

			matrix[m][n] = matrix[m + 1][n];
		}
	}

	showMatrix(matrix, qtdConjuntos - 1);

	return qtdConjuntos - 1;
}

void insertSet(int matrix[][N], int qtdConjuntos)

{
	int indice, valor;

	printf("Selecione o index que deseja inserir os valores: ");

	showMatrix(matrix, qtdConjuntos);

	scanf("%i", &indice);

	for (int i = 0; i < N; i++) {
		printf("\nValor %i: ", i);

		scanf("%i", &valor);

		matrix[indice][i] = valor;
	}

	showMatrix(matrix, qtdConjuntos);
}

int unionSet(int matrix[][N], int qtdConjuntos)

{
	int first, second, count = 0, vetor[] = { 0, 0, 0, 0, 0 };

	int conjuntos = createSet(matrix, qtdConjuntos);

	if (qtdConjuntos == conjuntos) {
		return qtdConjuntos;
	}

	printf("Deseja fazer a união entre quais conjuntos?\n");

	showMatrix(matrix, qtdConjuntos);

	scanf("%i%i", &first, &second);


	for (int i = 0; i < N; i++) {
		if (count > N) {

			printf("Não é possível realizar a união entre conjuntos!");
			return qtdConjuntos;
		}

		if (matrix[first][i] != 0) {

			count++;
			vetor[count - 1] = matrix[first][i];
		}
	}

	for (int i = 0; i < N; i++) {
		if (count > N) {

			printf("Não é possível realizar a união entre conjuntos!");
			return qtdConjuntos;
		}

		if (matrix[second][i] != 0) {

			count++;
			vetor[count - 1] = matrix[second][i];
		}
	}


	for (int i = 0; i < N; i++) {

		matrix[conjuntos - 1][i] = vetor[i];
		printf(" %i ", vetor[i]);
	}

	printf("\n");

	return conjuntos;
}

int interSecctionSet(int matrix[][N], int qtdConjuntos)

{
	int first, second, count = 0, vetor[] = { 0, 0, 0, 0, 0 };

	int conjuntos = createSet(matrix, qtdConjuntos);

	if (qtdConjuntos == conjuntos) {
		return qtdConjuntos;
	}

	printf("Deseja fazer a intersecção entre quais conjuntos?\n");

	showMatrix(matrix, qtdConjuntos);

	scanf("%i%i", &first, &second);


	for (int i = 0; i < N; i++) {
		if (count > N) {

			printf("Não é possível realizar a intersecção entre conjuntos!");

			return qtdConjuntos;
		}

		if (matrix[first][i] != 0) {
			count++;
		}

		if (matrix[second][i] != 0) {
			count++;
		}
	}

	int counter = 0;

	int hasTheSame = 0;

	for (int i = 0; i < N; i++) {

		if (searchValue(matrix[first][i], matrix, matrix[second][0], matrix[second][N - 1], second))
		{
			vetor[i] = matrix[first][i];

			counter++;
		}
	}

	if (counter == 0)
	{
		system("cls");

		printf("Os conjuntos não possuem elementos iguais!\n\n");

		return qtdConjuntos;
	}


	for (int i = 0; i < N; i++) {
		matrix[conjuntos - 1][i] = vetor[i];

		printf(" %i ", vetor[i]);
	}

	printf("\n");

	return conjuntos;
}

int searchValue(int item, int matrix[][N], int begin, int end, int row)

{
	int row1 = row;

	if (row1 == -1) {
		printf("Deseja pesquisar em qual linha? ");

		scanf("%i", &row1);

		if (row1 < 0 || row1 >= N)
		{
			printf("Linha inválida.\n");

			return -1;
		}
	}

	int i = (begin + end) / 2;

	if (begin > end) { 

		return -1;
	}

	if (matrix[row1][i] == item && item != 0) { 

		return i;
	}

	if (matrix[row1][i] < item) { 
		return searchValue(item, matrix, i + 1, end, row1);
	} else { 
		return searchValue(item, matrix, i - 1, end, row1);
	}
}