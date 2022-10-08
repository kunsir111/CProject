#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N];
int pre[N] , suf[N] , last[30];
signed main()
{
    cin >> s + 1;
    cout<<s + 1;
    int n = strlen(s + 1) , ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        pre[i] = last[s[i] - 'a'];
        last[s[i] - 'a'] = i;
    }
    for(int j = 0 ; j <= 25 ; j ++) last[j] = n + 1;
    for(int i = n ; i >= 1 ; i --){
        suf[i] = last[s[i] - 'a'];
        last[s[i] - 'a'] = i;
    }
    for(int i = 1 ; i <= n ; i ++){
        ans += (i - pre[i]) * (suf[i] - i);
    }
    cout << ans << '\n';
    return 0;
}