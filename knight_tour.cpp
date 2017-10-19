#include<stdio.h>
#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[],  int yMove[]);

/* A utility function to check if i,j are valid indexes
   for N*N chessboard */
bool isSafe(int x, int y, int sol[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && sol[x][y] == -1);
}

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

bool solveKT()
{
    int sol[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            sol[i][j]=-1;

    int xMove[8]={2,1,-1,-2,-2,-1,2,1};
    int yMove[8]={1,2,2,1,-1,-2,-1,-2};

    sol[0][0]=0;

      if(solveKTUtil(0,0,1,sol,xMove,yMove)==false)
      {
          printf("solution does not exist");
          return false;
      }
      else
        printSolution(sol);
      return true;
}
int solveKTUtil(int x,int y,int movei,int sol[N][N],int xMove[N],int yMove[N])
{
    int k,next_x,next_y;
    if(movei== N*N)
        return true;
     for(k=0;k<8;k++)
     {
         next_x=x+xMove[k];
         next_y=y+yMove[k];

         if(isSafe(next_x,next_y,sol))
         {
             sol[next_x][next_y]=movei;
             if(solveKTUtil(next_x,next_y,movei+1,sol,xMove,yMove)==true)
                return true;
             else
                sol[next_x][next_y]=-1;
         }
     }
     return false;
}

int main()
{
    solveKT();
    return 0;
}
