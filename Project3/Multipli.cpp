#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include "Header.h"

int main()
{
	int n = 0;
	int exitFlag = 0;
	setlocale(LC_CTYPE, "Russian");
	int **A, **B, **C, size1, size2, sizeOfMult;
	printf_s("Введите размеры матриц ");
	size1 = InputSizeOfMatrix();
	input(A, size1);
	size2 = size1;
	input_2(B, size2);
	printf_s("Транпонировать матрицу B?\n");
	do
	{
		int repeatFlag = 0;
		printf_s("<1> - Да\n");
		printf_s("<2> - Нет\n");
		if (!scanf_s("%d", &n))
		{
			printf_s("Ошибка \n");
			exitFlag = 1;
		}
		do
		{
			switch (n)
			{
			case 1: transposition(B, size2);
				if (сheck(size1, size2))
				{
					sizeOfMult = size1;
					clock_t start = clock();
					MultAfterTranposition(A, B, C, sizeOfMult);
					clock_t end = clock();
					printf_s("%f", (double)(end - start) / CLOCKS_PER_SEC);
				}
				else
					printf_s("Умножение невозможно");
				_getch();
				exitFlag = 1;
				break;
			case 2: if (сheck(size1, size2))
			{
				sizeOfMult = size1;
				clock_t start = clock();
				Multipli(A, B, C, sizeOfMult);
				clock_t end = clock();
				printf_s("%f", (double)(end - start) / CLOCKS_PER_SEC);
			}
					else
				printf_s("Умножение невозможно");
				_getch();
				exitFlag = 1;
				break;
			default: printf_s("Ошибка ввода операции \n");
				exitFlag = 1;
				_getch();
			}
		} while (!exitFlag && !repeatFlag);
	} while (!exitFlag);
}

void input(int **&A, int N)
{
	A = new int*[N];
	srand((unsigned)time(0));
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			A[i][j] = rand();
		}
	}
}

void input_2(int **&B, int M)
{
	B = new int*[M];
	for (int i = 0; i < M; i++)
	{
		B[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			B[i][j] = rand();
		}
	}
}

void Multipli(int **A, int **B, int **&C, int Z)
{
	C = new int*[Z];
	for (int i = 0; i < Z; i++)
	{
		C[i] = new int[Z];
		for (int j = 0; j < Z; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < Z; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

int InputSizeOfMatrix()
{
	int N;
	int exitFlag = 0;
	while (exitFlag != 1)
	{
		scanf_s("%d", &N);
		if (N < 1)
		{
			printf_s("Некорректный ввод, повторите \n");
		}
		else
		{
			printf_s("Размер матриц равен %d \n", N);
			exitFlag++;
		}
	}
	return N;
}

inline bool сheck(int N, int M)
{
	return N == M;
}

void transposition(int **B, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; i < N; i++)
			B[i][j] = B[j][i];
	}
}

void MultAfterTranposition(int **A, int **B, int **&C, int Z)
{
	C = new int*[Z];
	for (int i = 0; i < Z; i++)
	{
		C[i] = new int[Z];
		for (int j = 0; j < Z; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < Z; k++)
			{
				C[i][j] += A[i][k] * B[j][k];
			}
		}
	}
}