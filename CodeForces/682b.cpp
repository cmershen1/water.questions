#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++) {
      if(a[i]>ans)
        ans++;
    }
    ans++;
    printf("%d\n",ans);
  }
