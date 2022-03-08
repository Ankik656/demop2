//eideted 3rd time
//edited second time
#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,m,a[N],b[N],c[N],tp[N],pos[N];
long long ans;
void work(int l,int r,int L,int R)
{
	if(l>r)return;
	int mid=l+r>>1,now=0,minn=0,where=L;
	for(int i=L+1;i<=R;++i)
	{
		if(b[mid]>a[i-1])now--;
		if(b[mid]<a[i-1])now++;
		if(now<minn)
		{
			minn=now;
			where=i;
		}
	}
	pos[mid]=where;
	work(l,mid-1,L,where);
	work(mid+1,r,where,R);
}
void mergesort(int *d,int l,int r)
{
	if(l>=r)return;
	int mid=l+r>>1;
	mergesort(d,l,mid);
	mergesort(d,mid+1,r);
	int p=l,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(d[i]<=d[j])tp[p++]=d[i++];
		else tp[p++]=d[j++],ans+=mid-i+1;
	}
	while(i<=mid)tp[p++]=d[i++];
	while(j<=r)tp[p++]=d[j++];
	for(i=l;i<=r;i++)
	d[i]=tp[i];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{	
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int j=1;j<=m;j++)cin>>b[j];
		sort(b+1,b+1+m);
		work(1,m,1,n+1);
		int j=1,p=0;	
		for(int i=1;i<=n;i++)
		{
			while(j<=m&&pos[j]<=i)c[++p]=b[j++];
			c[++p]=a[i];
		}
		while(j<=m)c[++p]=b[j++];
		mergesort(c,1,p);
		cout<<ans<<endl;		
	}
	return 0;
}
