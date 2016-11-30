/**
*@author:cmershen
*@description:已知两数a和b，求gcd和lcm
*/
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b) {
    return a*b/gcd(a,b);
}