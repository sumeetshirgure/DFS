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


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n = 6;
	vi a(n); iota(all(a), 0);

	stack<vi> unvis; set<vi> vis;
	unvis.push(a); vis.insert(a);

	while (!unvis.empty()) {
		auto it = unvis.top();
		unvis.pop();
		vis.insert(it);

		FOR (i, 0, n - 1) {
			for (int j = i+3; j < n; j += 2) {
				vi nit(it);
				reverse(nit.begin()+i, nit.begin() + i+2);
				reverse(nit.begin() +i+2, nit.begin()+j+1);
				reverse(nit.begin()+i, nit.begin()+j+1);
				if (vis.count(nit)) continue;
				unvis.push(nit), vis.insert(nit);
			}
		}
	}
	pr(sz(vis));
	for (auto it: vis) {
		pr(it);
	}

	return 0;
}
