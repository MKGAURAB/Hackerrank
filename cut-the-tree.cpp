//Md. Khairullah Gaurab
//CSE, SUST  20th
//gaurab.cse.sust@gmail.com

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>


#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
                 vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;

const int inf = 2000000000;
const int SZ = 100005;

typedef long long Long;
typedef double dd;

vector<int> adj[SZ];

int val[SZ];
int sum[SZ];
bool color[SZ];

int DFS(int src)
{
    int lcost = 0;
    color[src] = true;
    int k = adj[src].size();
    REP(i,0,int(k-1))
    {
        int v = adj[src][i];
        if(color[v]) continue;
        lcost += DFS(v);
    }
    return sum[src] = val[src] + lcost;
}

int main(int argc, const char **argv)
{
    int N, tot, minc;
    sf("%d",&N);
    tot = 0;
    minc = inf;
    REP(i,1,N)
    {
        sf("%d",&val[i]);
        tot += val[i];
    }
    REP(i,1,N-1)
    {
        int u, v;
        sf("%d %d",&u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    DFS(1);
    REP(i,1,N)
    {
        if(abs(tot-(2*sum[i]))<minc)
        {
            minc = abs(tot - 2*sum[i]);
        }
    }
    pf("%d\n",minc);
    return 0;
}
