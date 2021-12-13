#include <stdio.h>
#include <time.h>

void whereMines(int back[6][8])
{
    int i = 0, j = 0, random, x = 0;
    for (i = 0; i < 6; i++)
    {
        printf("\n");
        for (j = 0; j < 8; j++)
        {
            random = rand() % 100 + 1;
            back[i][j] = random;
 			printf("%d" , back[i][j]);
			printf("\t");          
        }
    }
}

void printMatris(char front[6][8], int m, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < 6; i++)
    {
        printf("\n");

        for (j = 0; j < 8; j++)
        {
            front[i][j] = '*';
            printf("%c", front[i][j]);
            printf("\t");
        }
  }
}

void print_Matris(char front[6][8], int m, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < 6; i++)
    {
        printf("\n");
        for (j = 0; j < 8; j++)
        {
            printf("%c", front[i][j]);
            printf("\t");
        }
    }
}

int findMines(int back[6][8], char front[6][8])
{
    int i = 0, j = 0, x = 0;
    printf("\nInput (row,column) you want to step on\n");
    scanf_s("%d,%d", &i, &j);

    do 
    {
        int x = 0;
        printf("\nInput (row,column) you want to step on\n");
        scanf_s("%d,%d", &i, &j);
        x++;

        if (back[i][j] % 5 == 0)
        {
            front[i][j] = '.';
            system("cls"); // clear screen 
            print_Matris(front, 6, 8); // and print matris with dot
            return x;
        }
    }

    while (back[i][j] % 5 != 0); 
    printf("You hit the mine, get out!");
  
}

int main()
{
	
    int back[6][8];
    char front[6][8];
    int i = 0, j = 0, n = 0, m = 0;
    srand(time(NULL));

    whereMines(back);
    printMatris(front, i, j);
    findMines(back, front);


  return 0;
}
