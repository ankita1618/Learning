#include <bits/stdc++.h>
using namespace std;

struct cell{
    int x;
    int y;
    int dis;

    cell(){}
    cell(int x,int y,int dis)
        :x(x),y(y),dis(dis){}

};


bool isSafe(int x,int y,int n)
{
    if(x>=0&&x<n&&y>=0&&y<n)
        return true;
    return false;
}


int bfs(int Kpos[],int Tpos[],int n){
    int moves =8;
    int dx[]={1,2,-1,-2,2,1,-1,-2};
    int dy[]={2,1,2,1,-1,-2,-2,-1};

    int visited[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        visited[i][j]=0;


    queue <cell> q;
    int x,y;
    q.push(cell(Kpos[0],Kpos[1],0));
     visited[Kpos[0]][Kpos[1]]=1;
    while(!q.empty())
    {
        cell i=q.front();

        if(i.x==Tpos[0]&&i.y==Tpos[1])
            return i.dis;

        for(int j=0;j<moves;j++)
        {
            int x1=i.x+dx[j];
            int y1=i.y+dy[j];
            if(isSafe(x1,y1,n)&&!visited[x1][y1])
            {
                int d = i.dis+1;
                q.push(cell(x1,y1,d));
                visited[x1][y1]=1;
            }
        }
        q.pop();
    }

}

int main()
{
    int x,y,a,b,n;
    cin>>n;
    cin>>x>>y>>a>>b;
    int Kpos[]={x,y};
    int Tpos[]={a,b};

    cout<<bfs(Kpos,Tpos,n)<<endl;
}
