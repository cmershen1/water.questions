#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        double l,d;
        scanf("%lf %lf",&l,&d);
        if(l<=d)
            printf("0.000000\n");
        else
            printf("%.6lf\n", 1+log(l/d));
    }
}
