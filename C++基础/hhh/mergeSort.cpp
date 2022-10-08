#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int r){
	int mid = (l + r) / 2;
	int i = l;
	int j = mid + 1;
	int k = 0;
	int temp[100];
	while(i < mid && j < r){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while(i < mid){
		temp[k++] = arr[i++];
	}
	while(j < r){
		temp[k++] = arr[j++];
	}
	for(int i = 0; i < k; i++){
		arr[l + i] = temp[i];
	}
}

void mergeSort(int arr[], int l, int r){
	if(l < r){
		int mid = (l + r) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l , r);
	}
}

int main(){
	int arr[] = {156,465,465,4,654,654,64,654,789,789};
	int n = 10;
	mergeSort(arr, 0, 10);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
