#include<iostream>
#include<queue>
#define max_size 100

using namespace std;
int graph[max_size][max_size] = {0};
int node, edge;
int level[max_size];
bool visited[max_size];

//Near Node of root/subroot

void AdjacentNode(int source)
{
    for(int i= 0 ; i<node; i++)
    {
        if(graph[source][i] == 1)
        {
            cout<<i<<" ";
        }
    }
}
//traverse
void Initialize()
{
    for(int i= 0 ; i<node; i++)
    {
        visited[i] = false;
        level[i] = 0;
    }
}
//depth first search
void DFS(int source)
{
    visited[source] = true;
    cout<<source<<" ";
    for(int i= 0 ; i < node; i++)
    {
        if(graph[source][i] == 1)
        {
            if(visited[i] == false)
            {
                DFS(i);
            }
        }
    }
}
//breadth first search
void BFS(int source)
{
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while(!q.empty())
    {
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for(int i = 0; i < node; i++)
        {
            if(graph[x][i] == 1)
            {
                if(visited[i] == false)
                {
                    visited[i] = true;
                    level[i]= level[x]+1;
                    q.push(i);
                }
            }
        }
    }
}

int main()
{
    cin>>node>>edge;
    for(int i=0 ; i <edge; i++)
    {
        int m,n;
        cin>>m>>n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }

     //Dfs
   Initialize();
   DFS(0);
     cout<<endl;

     //Bfs
   Initialize();
   BFS(0);
     cout<<endl;

     //Levels
   for(int i=0; i<node; i++){
     cout<<level[i]<<" ";
   }
    return 0;
}

/*
Nodes- 11 Edges-11
Input:

11 11
0 1
1 8
1 2
1 6
1 3
8 9
2 4
6 5
6 7
3 10
4 7


13 12
0 1
1 2
1 7
1 8
2 3
2 6
3 4
3 5
8 9
8 12
9 10
9 11
*/


