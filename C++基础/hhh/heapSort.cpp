#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapAdjust(int arr[], int l, int r){
	int i = l;
	int j = 2 * l + 1;
	while(j <= r){
		if(j + 1 < r && arr[j] < arr[j + 1]){
			j++;
		}
		if(arr[i] <= arr[j]){
			swap(&arr[i], &arr[j]);
			i = j;
		j = 2 * i + 1;
		} else {
			break;
		}
	}
} 
void heapSort(int arr[], int n){
	for(int i = n/2; i >= 0; i--){
		heapAdjust(arr, i, n - 1);
	}
	for(int i = n - 1; i > 0; i--){
		swap(&arr[0], &arr[i]);
		heapAdjust(arr, 0, i - 1);
	}
}
int main(){
	int arr[] = {156,465,465,4,654,654,64,654,789,789};
	int len = (int)sizeof(arr) / sizeof(*arr);
	cout<<sizeof(arr) <<" "<< sizeof(*arr)<<endl;
	int n = 10;
	heapSort(arr, n);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
