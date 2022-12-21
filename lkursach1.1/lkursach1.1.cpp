#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
 
#define infinity 9999
#define MAX 20
 
int G[MAX][MAX],spanning[MAX][MAX],n;
 
int prims();
 
int adj()
{
	FILE *f;
	f = fopen("bebra.txt", "w+");
	setlocale(LC_ALL, "Rus");
    int i,j,total_cost;
    printf("Введите количетсво вершин:");
    scanf("%d",&n);
    
    printf("\nВведите матрицу смежности:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    total_cost=prims();
    
    if(total_cost >= 9999)
	{
		printf("Матрица смежности была задана не верно");
		printf("\n");
	}
	else{
		printf("Матрица связующего дерева находится в файле bebra.txt");
		fprintf(f, "\nМатрица связующего дерева:\n");
		for(i=0;i<n;i++)
		{
			fprintf(f,"\n");
			for(j=0;j<n;j++)
				fprintf(f, "%d\t",spanning[i][j]);
		}
	printf("\n\nРазмер связующего дерева=%d",total_cost);
	printf("\n");
	}
    
   
    return 0;
}
 

int rand_adj()
{
	FILE *fp;
	fp = fopen("bebrunya.txt", "w+");
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int i,j,total_cost;
    printf("Введите количетсво вершин:");
    scanf("%d",&n);

	for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
			if (i==j){
				G[i][j] = 0;
				continue;
			}
            G[i][j] =  1 + rand() % 10;
			G[j][i] = G[i][j];
			
            //printf("%3d", array[i][j]);
        }
    }


	
	for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
			printf("%3d", G[i][j]);
		}
		printf("\n");
	}
	total_cost=prims();
	printf("Матрица связующего дерева находится в файле bebrunya.txt");
    fprintf(fp, "\nМатрица связующего дерева:\n");
    
    for(i=0;i<n;i++)
    {
        fprintf(fp, "\n");
        for(j=0;j<n;j++)
            fprintf(fp, "%d\t",spanning[i][j]);
    }
    
    printf("\n\nРазмер связующего дерева=%d",total_cost);
	printf("\n");
    return 0;
}
int prims()
{
    int cost[MAX][MAX];
    int u,v = 1,min_distance,distance[MAX],from[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;
    
    //создание cost[][] matrix,spanning[][]
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=G[i][j];
                spanning[i][j]=0;
        }
        
    //инициализация visited[],distance[] and from[]
    distance[0]=0;
    visited[0]=1;
    
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
    
    min_cost=0;        //вес связующего дерева
    no_of_edges=n-1;        //количество добавляемых ребер
    
    while(no_of_edges>0)
    {
        //поиск вершины на минимальном расстоянии от дерева
        min_distance=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }
		
        u=from[v];
        
        //добавить ребро в связующее дерево
        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;
        
        //обновление массива distance[] 
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][v]<distance[i])
            {
                distance[i]=cost[i][v];
                from[i]=v;
            }
        
        min_cost=min_cost+cost[u][v];
	
    }
    
    return(min_cost);
}

void menu()
{
	setlocale(LC_ALL, "Rus");
	printf("\n");
	printf("******************** КУРСОВАЯ РАБОТА НА ТЕМУ *********************\n");
	printf("********* МИНИМАЛЬНОЕ СВЯЗУЮЩЕЕ ДЕРЕВО ИЗ АЛГОРИТМА ПРИМА ********\n");
	printf("************************   ВЫПОЛНИЛ СТУДЕНТ ГРУППЫ 21ВВ1  ********\n");
	printf("***************************************  ХОРОШИЛЬЦЕВ Е.А. ********\n");
	printf("************************  ПРИНЯЛИ ********************************\n");
	printf("***************************************  АКИФЬЕВ И.В. ************\n");
	printf("***************************************  ЮРОВА О.В. **************\n");
	
	printf("+--------------------—----------------—--------------------------+\n");
	printf("+Номер +---Задача------------------------------------------------+\n");
	printf("+  1   +---Задать матрицу                                        +\n");
	printf("+  2   +---Сгенерировать рандомную матрицу                       +\n");
	printf("+  0   +---Выход из программы                                    +\n");
	printf("+----------------------------------------------------------------+\n");
}

int main()
{
	while (1)
	{
		menu();
		int n = 0;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			adj();
			break;
		case 2:
			rand_adj();
			break;
		case 0:
			exit(0);
		default:
		{
			printf("Ошибка \ n");
			break;
		}
		}
	}
	return 0;
}