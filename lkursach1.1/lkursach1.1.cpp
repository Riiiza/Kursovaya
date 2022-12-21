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
    printf("������� ���������� ������:");
    scanf("%d",&n);
    
    printf("\n������� ������� ���������:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    total_cost=prims();
    
    if(total_cost >= 9999)
	{
		printf("������� ��������� ���� ������ �� �����");
		printf("\n");
	}
	else{
		printf("������� ���������� ������ ��������� � ����� bebra.txt");
		fprintf(f, "\n������� ���������� ������:\n");
		for(i=0;i<n;i++)
		{
			fprintf(f,"\n");
			for(j=0;j<n;j++)
				fprintf(f, "%d\t",spanning[i][j]);
		}
	printf("\n\n������ ���������� ������=%d",total_cost);
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
    printf("������� ���������� ������:");
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
	printf("������� ���������� ������ ��������� � ����� bebrunya.txt");
    fprintf(fp, "\n������� ���������� ������:\n");
    
    for(i=0;i<n;i++)
    {
        fprintf(fp, "\n");
        for(j=0;j<n;j++)
            fprintf(fp, "%d\t",spanning[i][j]);
    }
    
    printf("\n\n������ ���������� ������=%d",total_cost);
	printf("\n");
    return 0;
}
int prims()
{
    int cost[MAX][MAX];
    int u,v = 1,min_distance,distance[MAX],from[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;
    
    //�������� cost[][] matrix,spanning[][]
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=G[i][j];
                spanning[i][j]=0;
        }
        
    //������������� visited[],distance[] and from[]
    distance[0]=0;
    visited[0]=1;
    
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
    
    min_cost=0;        //��� ���������� ������
    no_of_edges=n-1;        //���������� ����������� �����
    
    while(no_of_edges>0)
    {
        //����� ������� �� ����������� ���������� �� ������
        min_distance=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }
		
        u=from[v];
        
        //�������� ����� � ��������� ������
        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;
        
        //���������� ������� distance[] 
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
	printf("******************** �������� ������ �� ���� *********************\n");
	printf("********* ����������� ��������� ������ �� ��������� ����� ********\n");
	printf("************************   �������� ������� ������ 21��1  ********\n");
	printf("***************************************  ����������� �.�. ********\n");
	printf("************************  ������� ********************************\n");
	printf("***************************************  ������� �.�. ************\n");
	printf("***************************************  ����� �.�. **************\n");
	
	printf("+--------------------�----------------�--------------------------+\n");
	printf("+����� +---������------------------------------------------------+\n");
	printf("+  1   +---������ �������                                        +\n");
	printf("+  2   +---������������� ��������� �������                       +\n");
	printf("+  0   +---����� �� ���������                                    +\n");
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
			printf("������ \ n");
			break;
		}
		}
	}
	return 0;
}