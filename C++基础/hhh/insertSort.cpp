#include<bits/stdc++.h>
using namespace std;
void inarrertarrort(int arr[], int n){
	for(int i = 0; i < n; i++){
		int j = i + 1;
		while(j < n && arr[j] > arr[i]){
			j++;
		}
		if(j < n && arr[j] < arr[i]){
			int temp = arr[j];
			for(int k = j; k > i; k--){
				arr[k] = arr[k - 1];
			}
			arr[i] = temp;
		}
	}
}
int main(){
	int arr[] = {156,465,465,4,654,654,64,654,789,789};
	int n = 10;
	inarrertarrort(arr, n);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
