#include<bits/stdc++.h>
using namespace std;

#define ll                                      long long
#define pb                                      push_back
#define pf                                      push_front
#define eb                                      emplace_back
#define mp                                      make_pair
#define ff                                      first
#define ss                                      second
#define db                                      double
#define pll                                     pair<ll, ll>
#define ALL(a)                                  (a).begin(),(a).end()
#define endl                                    "\n"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define ford1(i, n) for (int i = int(n) - 1; i >= 1; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define forabd(i, a, b) for(int i = int(a); i >= int(b); i--)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0)

/// ---------------------------- (Debug) ------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cout << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cout << endl; }
eni(!=) cout << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/// --------------------------------------------------------------------


const ll sz = 131077;
const ll mod = 1e9 + 7;
const db PI = acos(-1);
const db eps = 1e-10;
const ll INF = 1e18 + 5;


typedef vector<ll> VL;
typedef vector<pll > VLL;
typedef vector<vector<ll> > VVL;
typedef vector<vector<vector<ll> > > VVVL;



ll power(ll n, ll k, ll m) {
	ll ans = 1;
	while (k) {
		if (k & 1){
			ans = (ans * n) % m;
			k--;
		}
		else{
			n = (n * n) % m;
			k /= 2;
		}
	}
	return ans;
}

struct trie{
	trie* left; // 0
	trie* right; // 1
};

void insert(ll x,trie* head){
	trie* curr=head;
	for(ll i=63;i>=0;i--){
		if(x & (1LL<<i)){
			if(!curr->right){
				curr->right=new trie();
			}
			curr=curr->right;
		}
		else{
			if(!curr->left){
				curr->left=new trie();
			}
			curr=curr->left;
		}
	}
}

ll maxXOR(VL &a,ll n,trie* head){
	ll pre=0,ans=0;
	
	for(int i=0;i<n;i++){
		trie* curr=head;
		pre^=a[i];
		insert(pre,head);
		ll tmp=0;
		for(int j=63;j>=0;j--){
			//if(!curr)break;
			if(pre & (1LL<<j)){
				if(curr->left){
					tmp|=(1LL<<j);
					curr=curr->left;
				}
				else curr=curr->right;
			}
			else{
				if(curr->right){
					tmp|=(1LL<<j);
					curr=curr->right;
				}
				else curr=curr->left;
			}
		}
		ans=max(ans,tmp);
		
	}
	return ans;
}
				

void solver() {
	ll n;cin>>n;
	VL a(n);
	forn(i,n)cin>>a[i];
	trie* head=new trie();
	cout<<maxXOR(a,n,head)<<endl;
	delete head;
	

}


int main() {
	IOS;
	ll T = 1; //cin >> T;
	forn1(i, T + 1) {
		solver();
	}
	return 0;
}
