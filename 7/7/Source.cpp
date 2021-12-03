#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue> 
#include <locale.h>
using namespace std;
void BFSD(int** G, int* vis, int num, int n, int* dist) {
	queue <int> q;
	int i;
	q.push(num);
	vis[num] = 0;
	dist[num] = 0;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		printf("%d ", num);
		for (i = 0; i < n; i++) {
			if (vis[i] == 0 && G[num][i] > 0 && dist[i] > dist[num] + G[num][i]) {
				q.push(i);
				vis[i] = 1;
				dist[i] = dist[num] + G[num][i];
				
			}
		}
	}
}

int main(void) {
	setlocale(LC_ALL, "Rus");
	int** a;
	int** c;
	int N;
	printf("Введите N: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* b = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			b[j] = 0;
		}
		a[i] = b;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 10;
				a[i][j] = num;
				a[j][i] = num;
			}
		}
	}
	printf("Неориентированный граф");
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	c = (int**)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* d = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			d[j] = 0;
		}
		c[i] = d;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num1 = rand() % 10;
				c[i][j] = num1;
					c[j][i] = 0;
				
			
			}
		}
	}
	printf("Ориентированный граф");
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	int len = N;

	int* dist = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < len; i++) {
		dist[i] = 1000;
	}
	int* visits = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < len; i++) {
		visits[i] = 0;
	}
	printf("Введите вершину: ");
	scanf("%d", &N);
	BFSD(a, visits, N, len, dist);
	
	printf("\n");
	for (int i = 0; i < len; i++) {
		printf("%s%d %s ","расстояние до ",i,"=");
		
		printf("%d ", dist[i] );
		printf("\n");
	}
	
}

