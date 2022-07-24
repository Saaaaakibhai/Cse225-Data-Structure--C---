#include<iostream>
#include<queue>
using namespace std;
int graph[8][8];
bool visited[8][8];
int level[8][8]= {0};
int time[8][8];
int tim = 0;
int dx[8]={0,0,-1,1,-1,1,-1,1};
int dy[8]={1,-1,0,0,1,1,-1,-1};

//traverse limitation

bool isValid(int sx, int sy)
{
    if(sx>=0 && sy>=0 && sx<8 && sy<8 && visited[sx][sy] == false)
        return true;
    else
        return false;
}
//depth first search
void DFS(int sx, int sy)
{
    visited[sx][sy] = true;
    time[sx][sy] = tim++;
    cout<<sx<<" "<<sy<<"   ";

    for(int i= 0 ; i < 4; i++)
    {
        int next_x = sx + dx[i];
        int next_y = sy + dy[i];
        if(isValid(next_x,next_y))
        {
            DFS(next_x,next_y);
        }
    }

}
//taking node
struct node
{
    int x;
    int y;
};
//breadth first search
void BFS(int sx,int sy)
{
    visited[sx][sy] = true;
    int xx,yy,next_x,next_y;
    queue<node> q;
    node n;
    n.x = sx;
    n.y = sy;
    q.push(n);
    while(!q.empty())
    {
        xx = q.front().x;
        yy = q.front().y;
        cout<<xx<<" "<<yy<<"   ";
        q.pop();
        for(int i= 0 ; i<8; i++)
        {
            next_x = xx+dx[i];
            next_y = yy+dy[i];
            if(isValid(next_x,next_y))
            {
                visited[next_x][next_y] = true;
                n.x = next_x;
                n.y = next_y;
                q.push(n);
                level[next_x][next_y] = level[xx][yy] + 1;
            }
        }
    }
}
void Initialize()
{
    for(int i= 0 ; i<8; i++)
    {
        for(int j= 0 ; j<8; j++)
        {
            visited[i][j] = false;
            level[i][j] = 0;
        }
    }
}

int main()
{
    Initialize();
    BFS(4,4);
    cout<<endl;
    Initialize();
    DFS(4,4);

    return 0;
}
