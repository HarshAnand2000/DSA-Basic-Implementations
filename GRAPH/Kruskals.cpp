#include <iostream>
using namespace std;


int edges [3][9] = {{1,1,2,2,3,4,4,5,5},{2,6,3,7,4,5,6,7},{25,5,12,10,8,16,14,20,18}};
int S[8]={-1};
int included[9]={0};
int t[2][6];

void Union(int u, int v)                    //u,v head of two sets
{
    if(S[u]<S[v])
    {
        S[u] = S[u] + S[v];
        S[v] = u;
    }
    else
    {
        S[v] = S[v] + S[u];
        S[u] = v;
    }
}

int find(int u)
{
    int x =u,v=0;
    while(S[x] > 0)
    {
        x = S[x];
    }

    while(u!=x)
    {
        v = S[u];
        S[u] = x;
        u = v;
    }

    return x;
}

int main()
{
    int i =0,j,k,u,v,min = INT32_MAX,n =7, e =9;

    while(i< n-1)                //bcoz n-1 edges we have to take whre n is vertex
    {
        min = INT32_MAX;
        for(j=0;j<e;j++)
        {
            if(included[j]==0 && edges[2][j]<min)
            {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }

        if(find(u) != find(v))
        {
            t[0][i]=u;
            t[1][i]=v;
            Union(find(u),find(v));    //we should join parenst not vertex...that's why find(u)
            i++;
        }
        included[k]=1;
    }

cout<<"Spanning Tree: "<<endl;
for(i = 0; i<n-1;i++)
{
    cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
}

}