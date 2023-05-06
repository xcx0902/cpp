#include <bits/stdc++.h>
using namespace std;
const int MAXN=200010,P=1e9+7;
int n,x,y,eg,hd[MAXN],ver[2*MAXN],nx[2*MAXN],siz[MAXN],f[MAXN];
void add_edge (int x,int y) {
	ver[++eg]=y;
	nx[eg]=hd[x];
	hd[x]=eg;
	return;
}
int qpow (int a,int b) {
	int res=1;
	while (b) {
		if (b&1) {res=(1ll*res*a)%P;}
		a=(1ll*a*a)%P,b>>=1; 
	}
	return res;
}
void dfs1 (int x,int fa) {
	siz[x]=1;
	for (int i=hd[x];i;i=nx[i]) {
		if (ver[i]==fa) {continue;}
		dfs1(ver[i],x);
		siz[x]+=siz[ver[i]];
	}
	f[1]=(1ll*f[1]*siz[x])%P;
	return;
}
void dfs2 (int x,int fa) {
	for (int i=hd[x];i;i=nx[i]) {
		if (ver[i]==fa) {continue;}
		f[ver[i]]=(1ll*f[x]*((1ll*(n-siz[ver[i]])*qpow(siz[ver[i]],P-2))%P))%P; 
		dfs2(ver[i],x);
	}
	return;
}
int main () {
	scanf("%d",&n);
	f[1]=1;
	for (int i=1;i<=n-1;i++) {
		scanf("%d%d",&x,&y);
		add_edge(x,y),add_edge(y,x);
	}
	dfs1(1,0);
    for (int i = 1; i <= n; i++)
        cerr << f[i] << endl;
    cerr << endl;
	dfs2(1,0);
    for (int i = 1; i <= n; i++)
        cerr << f[i] << endl;
    cerr << endl;
	int tmp=1;
	for (int i=1;i<=n;i++) {tmp=(1ll*tmp*i)%P;}
	for (int i=1;i<=n;i++) {printf("%d\n",(1ll*tmp*qpow(f[i],P-2))%P);}
	return 0;
}
