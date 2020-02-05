
#include<bits/stdc++.h>
using namespace std;
#define max 100005
long long ar[max];
vector<long long >tree(max*4);
long long cou = 0,k=0;
string s;
stack<char> stak,st;

long long phi(long long n) {
    if(n==1)
    {
        return 1;
    }
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        {
        result -= result / n;
    }
    //cout<<"n "<<n<<" result "<<result<<endl;
    return result;
}

void update(long long node,long long b,long long e,long long x,long long y)
{
    if(b>e||x<b||x>e)
    {
        return;
    }
    else if(b==e && e==x )
    {
        tree[node] = phi(y);
        return;
    }
else{
    long long left = node*2;
    long long right = (node*2)+1;
    long long mid = (b+e)/2;
    update(left ,b,mid, x,y);
    update(right,mid+1,e,x,y);
    tree[node] = tree[left]+tree[right];
    return ;
}

}
 long long  query(long long node,long long b,long long e,long long x,long long y)
{
    if(b>e||e<x||y<b)
    {
        return 0;
    }
    else if(b>=x && e<=y)
    {
        return tree[node];
        //cout<<"tree "<<tree[node]<<endl;
    }
    else{
    long long left = node*2;
    long long right = (node*2)+1;
    long long mid = (b+e)/2;
     long long a = query(left,b,mid,x,y);
     long long c = query(right,mid+1,e,x,y);
   //  cout<<"a c "<<a<<" "<<c<<endl;
     return (a+c);}
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	 long  long  x,y,z,a,b,c,t,i,j,n,k,h,e,w,p,q,l,o,d;
	//string s1,s,s2,str;
 //tree.resize(4*n);
    map<char, long long>ma;
    cin>>n>>t;
    long long ar[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
        update(1,1,n,i,ar[i]);
    }
    //cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a;
        if(a==2)
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
