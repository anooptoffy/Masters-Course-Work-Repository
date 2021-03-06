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
	long long int N, K, CITY_GROUP[100000], Q, temp, city, M, NN;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> K;
	for (int i = 1; i <= K; ++i)
	{
		cin >> temp;

		if (temp > 0)
		{
			for (int j = 0; j < temp; ++j)
			{
				cin >> city;
				CITY_GROUP[city] = i;
			}
		}
	}

	cin >> Q;
	cout << Q << endl;

	for (int i = 1; i <= N; ++i)
	{
		cout << i << " " <<CITY_GROUP[i] << endl;
	}
	
	for (int i = 0; i < Q; ++i)
	{
		cin >> M >> NN;
		if(CITY_GROUP[M] == CITY_GROUP[NN])
			cout << 0 << endl;
		else if(CITY_GROUP[M] == K && CITY_GROUP[NN] == 1)
			cout << 1 << endl;
		else if(CITY_GROUP[M] == 1 && CITY_GROUP[NN] == K)
			cout << 1 << endl;
		else
			cout << abs(CITY_GROUP[M] - CITY_GROUP[NN]) << endl;
	}
	return 0;
}