#include<bits/stdc++.h>/*rimi*/
using namespace std;
#define max 100005
#define ll long long int
int ar[max];
vector<int >tree(max*4);
int k=1;
pair<int, int> t[4*100];
ll n;
ll temp[1000001];
ll match(ll ar[],ll left ,ll mid, ll right)
{
    ll count=0;
    ll i,j,k,l,m,o,p;
    i = left;
    j = mid;
    k=left;

    while((i<mid) &&(j<=right))
    {
        if(ar[i]>ar[j])
        {
            temp[k++] = ar[j++];
            count += mid-i;
        }
        else
        {
            temp[k++] = ar[i++];
        }
    }
    while(i<mid)
    {
        temp[k++]=ar[i++];
    }
    while(j<=right)
    {
        temp[k++] = ar[j++];
    }
    for(i=left;i<=right;i++)
    {
        ar[i]=temp[i];
    }
    return count;

}

ll partition(ll ar[],ll left, ll right)
{
    ll count =0;
    if(left<right)
    {
        ll mid = (left+right)/2;
       count+= partition(ar,left,mid);
       count+= partition(ar,mid+1,right);
       count+= match(ar,left,mid+1,right);
    }
    return count;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll z,m,a,b,c,t,i,j,n,k,h,e,w,q,l,o,d;
    double dou;
    string s1,s2,str;
    map<string, int>ma;
    map<string, int>::iterator it;
    cin>>n;
    ll ar[n+1];
    //int temp[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<partition(ar,0ll,n)<<endl;
return 0;
}


