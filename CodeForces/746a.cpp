#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(a,min(b/2,c/4))*7<<endl;
}
