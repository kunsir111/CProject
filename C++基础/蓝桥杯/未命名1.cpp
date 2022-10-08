#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+10;
int main(){
	int n, i = 2, ans = 1;
	scanf("%d", &n);
	if(n == 1){
		printf("%d\n", ans);
		return 0;
	}
	ans = 1;
	long long s[N], t[N];
	s[1] = 1, s[2] = 0;
	memset(t, 0, sizeof(t));
	while(i <= 2000){
		t[1] = 1;
		ans++;
		for(int j = 2; j < i; j++){
			t[j] = s[j - 1] + s[j];
			ans++;
			if(t[j] == n){
				printf("%d\n", ans);
				return 0;
			}
		}
		t[i] = 1;
		ans++;
//		for(int j = 1; j <= i; j++){
//			printf("%d ", t[j]);
//		}
		for(int j = 1; j <= i; j++){
			s[j] = t[j];
		}
		i++;
	}
//	for(int j = 1; j <= i; j++){
//		printf("%lld ", t[j]);
//	}
//	printf("\n");
	return 0;
}
