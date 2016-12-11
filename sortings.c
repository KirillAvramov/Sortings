#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Библиотека с компаратором

void swap (char **p, char **s);
void qsorting (char *m[], int a, int b);
void mergesort(char *m[], int n_strngs, int a, int b);
void insert (char *m[], int a, int b);
void bubble (char *m[], int a, int b);

int main(int argc, char **argv)
{
	if (argc != 3)
	{
    		printf("Некорректное количество аргументнов \n");
    		exit(1);
	}	
	
	int n = atoi(argv[1]); 		// Количество строк	
	
	FILE *fl = fopen(argv[2], "r");
	if (fl == 0) 
	{
		printf("Файл не может открыться\n");
		exit(1);
	}
	
	char **strngs;	// Массив строк из файла
	strngs = (char **) malloc(n*sizeof(char*)); // Выделили память на количество строк
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int k = 0;	// Счетчик символов в строке
		char c = 0;	// Символ в строке
		while (c != '\n' && !feof(fl))
		{
			c = fgetc(fl);
			++k;
		}
		++k;
		if (max < k)
			max = k;
	}
	for (int j = 0; j < n; ++j)
		strngs[j] = (char *) malloc(max*sizeof(char)); // Выделили память на количество символов в каждой строке
	
	int c = -1;
	while (c != 0)
	{
		rewind(fl);				// Перезаписывание
		for (int i = 0; i < n; i++)		//
			fgets(strngs[i], 256 , fl);	// массива
		
		printf("Exit - 0, qsort - 1, merge - 2, insert - 3, bubble - 4\n");
		scanf("%d", &c);
		switch (c)
		{
		case 0:
			break;
		case 1:
			qsorting (strngs, 0, n-1);
			break;
		case 2:
			mergesort (strngs, n, 0, n-1);
			break;
		case 3:
			insert (strngs, 0, n-1);
			break;
		case 4:
			bubble (strngs, 0, n-1);
			break;
		default:
			break;
		}
		
		printf("\n");				// Вывод
		for (int j = 0; c != 0 && j < n; j++)	// отсортированного
			printf("%s", strngs[j]);	// массива
		printf("\n");				// strngs
	}

	--n;
	for (n; n >= 0; --n)
		free(strngs[n]);
	free(strngs);	// Освобождение памяти для строк	
	fclose(fl);
	return 0;
}

void qsorting (char *m[], int a, int b)
{
	int l = a, r = b; // r - индекс опорного элемента
	while (l != r)
		
		if (strcmp(m[l], m[r]) >= 0)
		{
			swap(&m[l], &m[r]);
			swap(&m[l], &m[--r]);
		}
		else ++l;
		
	if (r > a)
		qsorting (m, a, r-1);
	if (l < b)
		qsorting (m, l+1, b);
}

void mergesort(char *m[], int n_strngs, int a, int b)
{
	int l = a, r = b;
	int mid = (l+r)/2 ;
	char **temp = (char **)malloc(n_strngs * sizeof(char*));
	
	if (r-l > 1)				
	{
		mergesort(m, n_strngs, l, mid);	  // Рекурсия продолжается до образования пары
		mergesort(m, n_strngs, mid+1, r); // которая будет сортироваться по алгоритму ниже
	}
	
	int l1 = l;
	int l2 = mid+1;
	int L = l;

	for (int q = 0; q < n_strngs; ++q)
		*(temp+q) = m[q];
	
	int c;
	while ((l1 <= mid || l2 <= r) && L <= r)
		if (c = ((l1 > mid) + 2*(l2 > r))) // Случай, если правое или левое деление полностью отсортирвалось в массив, а другое еще осталось
		{
			switch (c) {
			case 1:
				m[L++] = *(temp+l2);
				++l2;
				break;
			case 2:
				m[L++] = *(temp+l1);
				++l1;
				break;
			}
		}
		else if (strcmp(*(temp+l1), *(temp+l2)) < 0)
		{	
			m[L++] = *(temp+l1);
			++l1;
		}
		else if (strcmp(*(temp+l1), *(temp+l2)) > 0)
		{	
			m[L++] = *(temp+l2);
			++l2;
		}
		else if (strcmp(*(temp+l1), *(temp+l2)) == 0)
		{	
			m[L++] = *(temp+l1);
			++l1;
			m[L++] = *(temp+l2);
			++l2;
		}
	free(temp);
}

void insert (char *m[], int a, int b)
{
	for (int i = a+1; i <= b; ++i)
		for (int c = i; c > a; --c)
			if (strcmp(m[c], m[c-1]) < 0)
				swap(&m[c], &m[c-1]);
			else
				c = a;
}

void bubble (char *m[], int a, int b)
{
	int j;
	while (b > a)
	{
		for (j = a; j < b; ++j)
				if (strcmp(m[j], m[j+1]) > 0)
					swap (&m[j], &m[j+1]);
		--b;
	}	
}

void swap(char **p, char **s)
{
	char *temp = *p;
	*p = *s;
	*s = temp;
}
