#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p)
{return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v)
{bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
template<typename T, typename Comp=less<T>> bool setMin(T &mem, T const&v,Comp comp=Comp())
{ return comp(v, mem) ? mem = v, true : false; }
template<typename T, typename Comp=less<T>> bool setMax(T &mem, T const&v,Comp comp=Comp())
{ return comp(mem, v) ? mem = v, true : false; }


int X, A, B;
int win(vector<vector<int>>& a) {
	FOR (i, 0, 3) {
		FOR (j, 0, 3) if (a[i][j]) {
			if (i-1>=0 and i+1<=3 and a[i-1][j] == a[i][j] and a[i][j] == a[i+1][j]) return a[i][j];
			if (j-1>=0 and j+1<=3 and a[i][j-1] == a[i][j] and a[i][j] == a[i][j+1]) return a[i][j];
			if (i-1>=0 and j-1>=0 and i+1<=3 and j+1<=3 and a[i-1][j-1] == a[i][j] and a[i][j] == a[i+1][j+1]) return a[i][j];
			if (i-1>=0 and j-1>=0 and i+1<=3 and j+1<=3 and a[i+1][j-1] == a[i][j] and a[i][j] == a[i-1][j+1]) return a[i][j];
		}
	}
	return 0;
}
set<vector<vector<int>>> st;
set<vector<vector<int>>> vis;
void f(vector<vector<int>> &a, int t, ii last) {
	if (win(a)) {
		if (t == 1 and last.F == A and last.S == B) {
			st.insert(a);
		}
		return;
	}
	if (vis.count(a)) {
		return;
	}
	vis.insert(a);
	FOR (i, 0, 3) if (a[3][i] == 0) {
		int j = 3; while (j-1 >= 0 and a[j-1][i] == 0) --j;
		a[j][i] = t;
		f(a, t^3, ii(j, i));
		a[j][i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> X >> A >> B;
	--X, --A, --B;
	vector<vector<int>> a(4, vi(4));
	a[0][X] = 1;
	f(a, 2, ii(0, X));
	cout << sz(st);
}