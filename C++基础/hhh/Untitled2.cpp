#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp; 
			}
		}
	}
}
int main(){
	int arr[] = {156,465,465,4,654,654,64,654,789,789};
	int n = 10;                                      
	bubbleSort(arr, n);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" "; 
	}
	cout<<endl;
	return 0;
} 
