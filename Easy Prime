#include<bits/stdc++.h>//rimi
using namespace std;
#define max 100005
int ar[max];
vector<int >tree(max*4);

bool prime(int n)
{
    if(n==2)
    {
        return 1;

    }
    else if(n<=1)
    {
        return 0;
    }
    else
    {for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return 0;

        }
    }
    }
    return 1;
}

void input(int node , int b,int e)
{
    if(b == e)
    {
        tree [ node] = ar[b];
        return;
    }
    int left = node*2;int right = (node*2)+1;
    int mid = (b+e)/2;
    input(left ,b,mid );
    input(right,mid+1,e);
    tree[node] = prime(tree[left])+prime(tree[right]);
   cout<<node<<" "<<tree[node]<<endl;

}
void update(int node,int b,int e,int x,int y)
{
    if(b>e||x<b||x>e)
    {
        return;
    }
    else if(b==e && e==x )
    {
        tree[node] = prime(y);
        return;
    }
else{
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    update(left ,b,mid, x,y);
    update(right,mid+1,e,x,y);
    tree[node] = tree[left]+tree[right];
    return ;
}

}
long long int  query(int node,int b,int e,int x,int y)
{
    if(b>e||e<x||y<b)
    {
        return 0;
    }
    else if(b>=x && e<=y)
    {
        return tree[node];
        cout<<"tree "<<tree[node]<<endl;
    }
    else{
    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
     int a = query(left,b,mid,x,y);
     int c = query(right,mid+1,e,x,y);
   //  cout<<"a c "<<a<<" "<<c<<endl;
     return (a+c);}
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	 long  long int x,y,z,a,b,c,t,i,j,n,k,h,e,w,p,q,l,o,d;
	string s1,s,s2,str;
 //tree.resize(4*n);
    map<char, int>ma;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
        update(1,1,n,i,ar[i]);
    }
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>p>>q;
            cout<<query(1,1,n,p,q)<<endl;
        }
        else
        {
            cin>>p>>q;
            update(1,1,n,p,q);
        }
    }


    return 0;
}
