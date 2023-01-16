// Source: https://github.com/CUICUI2010/OI-Templates/blob/main/template.cpp
/**
 * @file template.cpp
 * @author Cui2010
 * @brief A C++ template.
 * @version 0.2.0
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
 * Templates. To go to the bottom, hit:
 * 518G cc
 */

// GCOJ Official file.


#include <bits/stdc++.h>

// Defines.

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define iint signed

using namespace std;

// Consts.

const int INF = 0x3f3f3f3f;
const int IINF = 0x3f3f3f3f3f3f3f3f;
const int RINF = 0x7fffffff;
const int OVER_MAX = 2147483648LL;
const int OVER_MIN = -2147483649LL;
const int SHORT_MAX = 32767;
const int SHORT_MIN = -32768;
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
const int MOD3 = 1145141919810LL;
const int MAXN = 200000;
const double PI = acos(-1.0);
const double E = 2.718281828;
const double PHI = (sqrt(5.0) - 1) / 2.0;

// Debugger.
// Grammar: debug << ...$$

bool is_debug = false;

#define debug if(is_debug) cout
#define setd is_debug = true

// Quick things

//#pragma GCC optimize(3)

inline int read(){
	int ans = 0;
	char c = getchar();
	while(!isdigit(c)){
		c = getchar();
	}
	while(isdigit(c)){
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}

struct Bigint{
	string s;
};
bool operator==(const Bigint &a, const Bigint &b){
	return a.s == b.s;
}
bool operator<(const Bigint &a, const Bigint &b){
	if(a.s.length() < b.s.length()){
		return true;
	}
	for(int i = 0;i < a.s.length();i++){
		if(a.s[i] < b.s[i]){
			return true;
		}
		else if(a.s[i] > b.s[i]){
			return false;
		}
	}
	return false;
}
bool operator>(const Bigint &a, const Bigint &b){
	if(a.s.length() > b.s.length()){
		return true;
	}
	for(int i = 0;i < a.s.length();i++){
		if(a.s[i] > b.s[i]){
			return true;
		}
		else if(a.s[i] < b.s[i]){
			return false;
		}
	}
	return false;
}
bool operator<=(const Bigint &a, const Bigint &b){
	return a == b || a < b;
}
bool operator>=(const Bigint &a, const Bigint &b){
	return a == b || a > b;
}
Bigint operator+(const Bigint &a, const Bigint &b){
	Bigint ans;
    string x = a.s, y = b.s;
    if(x.length() < y.length()) swap(x, y);
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
    int now = 0;
	for(int i = 0;i < max(x.length(), y.length());i++){
		now += x[i] - '0';
        if(i < y.length()){
            now += y[i] - '0';
        }
		ans.s = ans.s + (char)(now % 10 + '0');
		now /= 10;
	}
    if(now){
        ans.s = ans.s + '1';
    }
	reverse(ans.s.begin(), ans.s.end());
	return ans;
}
Bigint operator*(const Bigint &a, const Bigint &b){
	Bigint ans;
    string x = a.s, y = b.s;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	int t[x.length() + y.length() + 10];
	memset(t, 0, sizeof(t));
	for(int i = 0;i < x.length();i++){
		for(int j = 0;j < y.length();j++){
			t[i + j] += (x[i] - '0') * (y[j] - '0');
		}
	}
    int xx = 0;
	for(int i = 0;i < x.length() + y.length() - 1;i++){
        xx += t[i];
		ans.s = ans.s + (char)(xx % 10 + '0');
		xx /= 10;
	}
    if(xx){
        ans.s = ans.s + (char)(xx + '0');
    }
    reverse(ans.s.begin(), ans.s.end());
	return ans;
}

/**
 * @brief DisJoint Sets.
 * 
 * @details DisJoint Sets with route optimization.
 * 			Time complexity O(a(n)), good.
 * 
 * @todo Add the DSU with weights.
 * 
 */
class DSU{
	public:
		int father[MAXN];
		void init(int n, int p){
			memset(father, 0, sizeof(father));
			for(int i = 0;i < n;i++){
				father[i] = i + p;
			}
		}
		int findfather(int n){
			if(father[n] == n){
				return n;
			}
			return findfather(father[n]);
		}
		void Union(int a, int b){
			a = findfather(a), b = findfather(b);
			if(a != b){
				father[a] = b;
			}
		}
	
};

// The lowbit calculation.

inline int lowbit(int n){
	return n & (-n);
}

inline int cnto(int n){
	int t = 1, ans = 0;
	while(t > 0){
		ans += (bool)(n & t);
		t <<= 1;
	}
	return ans;
}


class BIT{
	private:
		int s[100001], sz;
	public:
		void init(int z){
			memset(s, 0LL, sizeof(s));
			sz = z;
		}
		void add(int n, int k){
			while(n <= sz){
				s[n] += k;
				n += lowbit(n);
			}
		}
		int query(int n){
			int ans = 0LL;
			while(n >= 1){
				ans += s[n];
				n -= lowbit(n);
			}
			return ans;
		}
};

// Struct for segmenttrees.

struct Segment_tree{
	int l, r;
	long long val, lazy;
};



/**
 * @brief Segment trees.
 * 
 * @details This segment tree is a stimulation
 * 			of the segment tree.
 * 
 * @warning ONLY THE SEGMENTTREE STRUCT CAN BE MODIFIED!
 * 
 * @todo Add the functions.
 */
class SegmentTree{
	private:
		Segment_tree tree[2000001];
	public:
		void build(int l, int r, int k, int *a){
			tree[k].l = l;
			tree[k].r = r;
			if(l == r){
				tree[k].val = a[l];
				return;
			}
			int mid = (l + r) >> 1;
			build(l, mid, k * 2, a);
			build(mid + 1, r, k * 2 + 1, a);
			tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
			return; 
		}
		void marks(int p){
			if(tree[p].lazy){
				tree[p * 2].val += tree[p].lazy * (tree[p * 2].r - tree[p * 2].l + 1);
				tree[p * 2 + 1].val += tree[p].lazy * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);
				tree[p * 2].lazy += tree[p].lazy;
				tree[p * 2 + 1].lazy += tree[p].lazy;
				tree[p].lazy = 0LL; 
			}
			return;
		}
		void add(int l, int r, int k, int d){
			if(l <= tree[d].l && r >= tree[d].r){
				tree[d].val += (long long)(k) * (tree[d].r - tree[d].l + 1LL); 
				tree[d].lazy += k;
				return;
			}
			marks(d);
			int mid = (tree[d].l + tree[d].r) >> 1;
			if(l <= mid){
				add(l, r, k, d * 2);
			}
			if(r > mid){
				add(l, r, k, d * 2 + 1);
			}
			tree[d].val = tree[d * 2].val + tree[d * 2 + 1].val; 
		}
		long long query(int l, int r, int k){
			if(l <= tree[k].l && r >= tree[k].r){
				return tree[k].val;
			}
			marks(k);
			int mid = (tree[k].l + tree[k].r) >> 1;
			long long val = 0LL;
			if(l <= mid){
				val += query(l, r, k * 2);
			}
			if(r > mid){
				val += query(l, r, k * 2 + 1);
			}
			return val;
		}
};

template<typename T> class p_stack{
	private:
		stack<T> st;
		int lst[1000001], tot = 0;
	public:
		void add(T k, int(cmp)(T, T) = less<T>()){
			while(st.size() && *(cmp)(st.top(), k)){
				lst[k] = ++tot;
				st.pop();
			}
			st.push(k);
		}
		vector<int> collect(int n, int none_var = 0){
			vector<int> ans;
			for(int i = 0;i < n;i++){
				if(lst[i]){
					ans.push_back(lst[i]);
				}
				else{
					ans.push_back(none_var);
				}
			}
			return ans;
		}
		T get_top(){
			return st.top();
		}
};

template<typename T> class pqueue{
	private:
		deque<T> deq;
};

// Math functions

bool isPrime(int n, bool special){
	if(n == 0 || n == 1){
		return special;
	}
	for(int i = 2;i * i <= n;i++){
		if(!(n % i)){
			return false;
		}
	}
	return true;
}

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}
int lcm(int a, int b){
	return a * b / gcd(a, b);
}

int power(int a, int b, int q){
	if(b == 0){
		return 1;
	}
	if(b % 2 == 1){
		return (power(a, b - 1, q) * a) % q;
	}
	int temp = power(a, b / 2, q) % q;
	return (temp * temp) % q;
}

// Strings.

bool is_palin(string s){
	string p = s;
	reverse(p.begin(), p.end());
	return p == s;
}

// Quicker than STL.

int mmax(int a, int b){
	return a < b ? b : a;
}
int mmin(int a, int b){
	return a < b ? a : b;
}
void ckmax(int *a, int b){
	*a = mmax(*a, b);
}
void ckmin(int *a, int b){
	*a = mmin(*a, b);
}

// Quick OJ tools.

#define ncinn int n; cin >> n
#define tcin int n, m; cin >> n >> m
#define allcin int a[n]; for(int i = 0;i < n;i++){cin >> a[i];}
#define sorta sort(a, a + n)
#define mltst() int t;cin >> t;while(t--)

// RE&TLE helpers

#define dd cout << "|" << endl
#define di cout << "@" << endl
#define df cout << "#" << endl

// Quick cout tools

void parr(int a[], int n, char sep){
	for(int i = 0;i < n;i++){
		cout << a[i] << sep;
	}
	cout << endl;
}
void pres(bool ok){
	cout << (ok ? "YES" : "NO") << endl;
}
void cmin(int a, int b){
	cout << ((a < b) ? "YES" : "NO") << endl;
}
void cmax(int a, int b){
	cout << ((a > b) ? "YES" : "NO") << endl;
}

// Some basic algorithms.

bool is32_overflow(int n){
	return n > INT_MAX || n < INT_MIN;
}
bool is16_overflow(int n){
	return n > SHORT_MAX || n < SHORT_MIN;
}

// Hashing.

uint _hash(string s){
	uint a = 0;
	for(int i = 0;i < s.length();i++){
		a = a * 128 + (int)(s[i]);
	}
	return a;
}

// Memset.

void aset(int *a, int n, int k){
	for(int i = 0;i < n;i++){
		*(a + i) = k;
	}
}

// Links.

template<typename T1> class Link{
	public:
		struct node{
			T1 val;
			node *prev, *next;
		};
		node *head, *tail;
		void init(){
			head = new node();
			tail = new node();
			head->val = tail->val = 0;
			head->next = tail;
			tail->prev = head;
		}
		void insert(node *p, int n){
			node *k = new node();
			k->val = n;
			k->next = p->next;
			k->prev = p;
			p->next->prev = k;
			p->next = k;
		}
		void del(node *p){
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
		}
		void recycle(){
			while(head != tail){
				head = head->next;
				delete head->prev;
			}
			delete tail;
		}
};

// Graphs and trees.

struct ged{
	int u, v, w;
	bool operator < (const ged x){
		return w < x.w;
	}
};
class Graph{
	private:
		int vis[1000001];
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	public:
		int d[1000001];
		vector<pair<int, int> > gv[100001];
		vector<ged> ge;
		void add_edge(int u, int v, int w, bool dir){
			gv[u].push_back(make_pair(v, w));
			ge.push_back((ged){u, v, w});
			if(!dir){
				gv[v].push_back(make_pair(u, w));
				ge.push_back((ged){v, u, w});
			}
		}
		void dij(int k){
			memset(d, 0x3f3f3f3f3f3f3f3f, sizeof(d));
			memset(vis, 0, sizeof(vis));
			d[k] = 0;
			pq.push(make_pair(k, 0));
			while(pq.size()){
				int x = pq.top().second;
				pq.pop();
				if(vis[x]) continue;
				vis[x] = 1;
				for(int i = 0;i < gv[x].size();i++){
					int y = gv[x][i].first, z = gv[x][i].second;
					if(d[y] > d[x] + z){
						d[y] = d[x] + z;
						pq.push(make_pair(d[y], y));
					}
				}
			}
		}
		int MST(int n){
			DSU ds;
			ds.init(n, 1);
			sort(ge.begin(), ge.end());
			int tot = 0, ans = 0, i = 0;
			while(i < ge.size() && tot < n - 1){
				if(ds.findfather(ge[i].u) != ds.findfather(ge[i].v)){
					tot++, ans += ge[i].w;
					ds.Union(ge[i].u, ge[i].v);
				}
				i++;
			}
			if(tot != n - 1){
				return -1;
			}
			return ans;
		}
		bool is_exist(int u, int v){
			for(int i = 0;i < gv[u].size();i++){
				if(gv[u][i].first == v){
					return true;
				}
			}
			return false;
		}
};

struct customother{
	int sz, de, dfn;
	int an[21];
};
class Tree{
	private:
		bool vis[100001];
		int tot = 0;
	public:
		customother ot[100001];
		Graph g;

		void add_edge(int u, int v){
			g.add_edge(u, v, -1, false);
		}

		void dfs(int n, int fa){
			ot[n].sz = 1;
			if(fa == -1){
				ot[n].an[0] = n;
			}
			for(int i = 1;i <= 20;i++){
				ot[n].an[i] = ot[ot[n].an[i - 1]].an[i - 1];
			}
			for(int i = 0;i < g.gv[n].size();i++){
				if(g.gv[n][i].first == fa){
					continue;
				}
				ot[g.gv[n][i].first].de = ot[n].de + 1;
				dfs(g.gv[n][i].first, n);
				ot[n].sz += ot[g.gv[n][i].first].sz;
				ot[n].dfn = ++tot;
			}
		}

		int lca(int u, int v){
			if(ot[u].de < ot[v].de){
				swap(u, v);
			}
			for(int i = 20;i >= 0;i--){
				if (ot[ot[u].an[i]].de >= ot[v].de){
					u = ot[u].an[i];
				}
			}
			if(u == v){
				return u;
			}
			for(int i = 20;i >= 0;i--){
				if(ot[u].an[i] != ot[v].an[i]){
					u = ot[u].an[i], v = ot[v].an[i];
				}
			}
			return ot[u].an[0];
		}
		
};

//-------------by @cui2010 -------------

signed main(){
	IO;
	// Type your code...
	return 0;
}