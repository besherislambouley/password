/*
 * let num [i] be the number of occurrences of letter i in the answer
 * initially let ans = "aaaaaaa" ( num [a] times ) , we will try to add letters one by one
 * we use binary search to see the maximum size of a prefix such that the answer will be prefix + curr letter + suffix
 * we can check that by trying adding all the remaining letters of curr letter after the checked prefix 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 400
//#define mp make_pair
#define mid (l+r)/2
#define Le Node * 2 
#define Ri Node * 2 + 1 
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef pair<double,ll>pdi;
const ll inf=1e18;
const ll Mod=1e9+7;
const ld pai=acos(-1);
int n , k ;
string ans ;
int num [26] ;
unordered_map < string , int > mp ;
int query ( string x ) {
	if ( mp .count (x) ) return mp [x] ;
	cout << x << endl ;
	int mx ;
	cin >> mx ;
	mp [x] = mx ; 
	if ( mx == n ) exit (0) ;
	return mx ;
}
string make ( int x , int c ) {
	string ret = "" ;
	for ( int i = 0 ; i < x ; i ++ ) 
		ret += (char)( c + 'a' ) ;
	return ret ;
}
int check ( int id , int x , int len ) { 
	string ret = "" ;
	for ( int i = 0 ; i <= id ; i ++ ) ret += ans [i] ;
	for ( int i = 0 ; i < len ; i ++ ) ret += (char) ( x + 'a' ) ;
	return ( query ( ret ) == (int) ret .size() ) ;
}
int main () {
	cin >> n >> k ;
	for ( int i = 0 ; i < k ; i ++ ) {
		num [i] = query ( make ( n , i ) ) ;
	}
	for ( int i = 0 ; i < k ; i ++ ) {
		if ( num [i] ) {
			ans = make ( num [i] , i ) ;
			num [i] = 0 ;
			break ;
		}
	} 
	for ( int i = 0 ; i < k ; i ++ ) {
		if ( ! num [i] ) C ;
		int last = - 1 ;
		for ( int j = 0 ; j < num [i] ; j ++ ) {
			int l = last , r = (int) ans . size() ; 
			while ( r - l > 1 ) {
				if ( check ( mid , i , num [i] - j ) ) l = mid ;
				else r = mid ;
			}
			last = max ( -1 , l - 10 ) ;
			string ret ="";
			for ( int it = 0 ; it <= l ; it ++ ) ret += ans [it] ;
			ret += (char) ( i + 'a' ) ;
			for ( int it = l + 1 ; it < (int)ans .size () ; it ++ ) ret += ans [it] ;
			ans = ret ;  
		}
	}
	query ( ans ) ; 
}
