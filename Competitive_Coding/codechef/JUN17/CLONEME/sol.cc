#include <bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define ll long long
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvl;

const ll mod = 2e18;
const int N = 3e5;

int main(int argc, char const *argv[])
{
	// For handling large inputs.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll int T, N, Q, Arr[100005], a, b, c, d;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	while(T-- > 0) {
	    cin >> N >> Q;
	    for (ll int i = 1; i <= N; ++i)
	    {
	    	cin >> Arr[i];
	    }

	    for (ll int i = 0; i < Q; ++i)
	    {
	    	cin >> a >> b >> c >> d;
	    	vll one, two;
	    	for (int k = a; k <= b; ++k)
	    	{
	    		one.pb(Arr[k]);
	    	}

	    	for (int k = c; k <= d; ++k)
	    	{
	    		two.pb(Arr[k]);
	    	}

	    	sort(one.begin(), one.end());
	    	sort(two.begin(), two.end());

	    	int count;
	    	count = 0;

	    	for (vll::iterator it = one.begin(), it2 = two.begin()  ; it != one.end() && it2 != two.end(); ++it, ++it2)
    		{
    			//cout << (*it) << " " << *it2 << endl;
    			if(*it != *it2)
    				count++;
    		}	

    		if(count <= 1)
    			cout << "YES" << endl;
    		else
    			cout << "NO" << endl;
	    }
	}
	
	return 0;
}