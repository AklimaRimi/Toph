#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll a,b,n,e,f,i,j,k=0;

char ar[25][25];
int visit[25][25];

ll water=0,earth=0;
ll c=0,d=0;

void bfs(int x,int y)
{
    if(x<=0||y<=0||x>n||y>n|| ar[x][y]=='.')
    {
        visit[x][y]=1;
         //cout<<"aise"<<endl;
        return;
    }
    else
    {
            if(ar[x][y]=='#')
            {
                if(d>0)
                {
                    c=1;
                }

            }

          if(ar[x][y]=='*'&&visit[x][y]==0)
         {
             d--;
            visit[x][y]=1;
            ar[x][y]='-';
            bfs(x+1,y);
            bfs(x-1,y);
            bfs(x,y+1);
            bfs(x,y-1);
         }
        else if(ar[x][y]=='$'&&visit[x][y]==0)
        {
             if(d>0)
            {
                    d=15;
                    k=1;
            }
            else
            {
                k=0;
            }
            visit[x][y]=1;
            ar[x][y]='-';
            bfs(x+1,y);
            bfs(x-1,y);
            bfs(x,y+1);
            bfs(x,y-1);
        }
    }
}

int main()
{
    ll test,te;

    cin>>n;
    ll s1=0,s2=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>ar[i][j];
            if(ar[i][j]=='@')
            {
                s1=i;
                s2=j;
                visit[i][j]=1;
            }
        }
    }


    water=earth=c=d=15;
    bfs(s1+1,s2);
    bfs(s1,s2+1);
    bfs(s1-1,s2);
    bfs(s1,s2-1);
    if(c==1&&k==1)cout<<"Yes"<<endl;
    else if(c==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}


