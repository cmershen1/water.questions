/**
*@source:POJ 2891
*@中国剩余定理（不互质模板）
*@求模线性方程组x=ai(mod ni),ni可以不互质
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef __int64 int64;
int64 Mod;

int64 gcd(int64 a, int64 b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int64 Extend_Euclid(int64 a, int64 b, int64&x, int64& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int64 d = Extend_Euclid(b,a%b,x,y);
    int64 t = x;
    x = y;
    y = t - a/b*y;
    return d;
}

//a在模n乘法下的逆元，没有则返回-1
int64 inv(int64 a, int64 n)
{
    int64 x,y;
    int64 t = Extend_Euclid(a,n,x,y);
    if(t != 1)
        return -1;
    return (x%n+n)%n;
}

//将两个方程合并为一个
bool merge(int64 a1, int64 n1, int64 a2, int64 n2, int64& a3, int64& n3)
{
    int64 d = gcd(n1,n2);
    int64 c = a2-a1;
    if(c%d)
        return false;
    c = (c%n2+n2)%n2;
    c /= d;
    n1 /= d;
    n2 /= d;
    c *= inv(n1,n2);
    c %= n2;
    c *= n1*d;
    c += a1;
    n3 = n1*n2*d;
    a3 = (c%n3+n3)%n3;
    return true;
}

//求模线性方程组x=ai(mod ni),ni可以不互质
int64 Chinese_Remainder(int len, int64* a, int64* n)
{
    int64 a1=a[0],n1=n[0];
    int64 a2,n2;
    for(int i = 1; i < len; i++)
    {
        int64 aa,nn;
        a2 = a[i],n2=n[i];
        if(!merge(a1,n1,a2,n2,aa,nn))
            return -1;
        a1 = aa;
        n1 = nn;
    }
    Mod = n1;
    return (a1%n1+n1)%n1;
}
int64 a[1000],b[1000];
int main()
{
    int i;
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(i = 0; i < k; i++)
            scanf("%I64d %I64d",&a[i],&b[i]);
        /*for( i = 0 ; i < k ; ++i )
      scanf( "%I64d" , &a[ i ] ) ;
    for( i = 0 ; i < k ; ++i )
      scanf( "%I64d" , &b[ i ] );
      */
    printf("%I64d\n",Chinese_Remainder(k,b,a));
    }
    return 0;
}
