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
const int SZ = 17;

typedef unsigned long long Long;
typedef double dd;

int main(int argc, const char **argv)
{
    int test;
    Long N;
    sf("%d",&test);
    REP(i,1,test)
    {
        sf("%llu",&N);
        int turn = 0;
        while(N>1)
        {
            if(N>9223372036854775808)
            {
                N -= 9223372036854775808;
                turn++;
            }
            else
            {
                Long tmp = pow(2,floor(log2(N)));
                if(tmp==N) N/=2;
                else N -= tmp;
                turn++;
            }
        }
        if(turn&1) pf("Louise\n");
        else pf("Richard \n");
    }
    return 0;
}
