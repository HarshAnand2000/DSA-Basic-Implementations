#include<iostream>
#include"queue.cpp"

void BFS(int G[][8], int start, int n)          //n is  no. of vertices
{
    int i = start,j;
    int visited[7]={0};

    cout<<i<<" ";
    visited[i]=1;
    enqueue(1);

    while(!isEmpty())
    {
        i = dequeue();
        for(j = 1; j<=n ;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][8], int start, int n)
{
    static int visited[7]={0};
    int j;
    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;

        for(j=1;j<=n;j++)
        {
            if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n);
        }
    }
}

int main()
{
    int G[8][8] =   {{0,0,0,0,0,0,0,0},
                    {0,0,1,1,1,0,0,0},
                    {0,1,0,1,0,0,0,0},
                    {0,1,1,0,1,1,0,0},
                    {0,1,0,1,0,1,0,0},
                    {0,0,0,1,1,0,1,1},
                    {0,0,0,0,0,1,0,0},
                    {0,0,0,0,0,1,0,0}};

    BFS(G,1,7);
    cout<<endl;
    DFS(G,1,7);

                  
}