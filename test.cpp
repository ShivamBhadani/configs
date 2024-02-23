#include <bits/stdc++.h>
#define ll        long long
#define endl      "\n"
#define debug     cout<<"hello"<<endl
#define mod       (ll)1e9+7
#define log(a)    cout<<a<<"\n"
using namespace std;
/* remember __builtin_popcount(n)  1s
            __builtin_parity(n)    1-odd 0-even
    */
ll bits(ll n){return (ll)log2(n) + 1;}
ll gcd1(ll a, ll b){return b == 0 ? a : gcd1(b, a % b);}
ll lcm1(ll a, ll b){return (a / gcd1(a, b)) * b;}
bool is_prime(int n){for(int i=2;i*i<=n;i++){
	if(n%i==0){return false;if(n%(n/i)!=0){return false;}}}return true;}
bool ispower2(ll n){if (n & (n - 1) == 0){
	return 1;}return 0;}
ll msbs(ll val) {if (val == 0){return 0;
	}ll count = 1;while (val >> count){count++;}return count;}
//----------------------->>>>>>>code starts here<<<<<<---------------------------------

void solve(){
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		solve();;
	
	}
	return 0;
}
