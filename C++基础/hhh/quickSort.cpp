#include<bits/stdc++.h>
using namespace std;
void quickSort(int arr[], int l, int r){
	if(l < r){
		int temp = arr[l];
		int i = l;
		int j = r;
		while(i < j){
			while(i < j && temp <= arr[j]){
				j--;
			}
			arr[i] = arr[j];
			while(i < j && temp >= arr[i]){
				i++;
			}
			arr[j] = arr[i];
		}
		
		arr[i] = temp;
		quickSort(arr, l, i - 1);
		quickSort(arr, i + 1, r);	
	}
}
int main(){
	int arr[] = {156,465,465,4,654,654,64,654,789,789};
	int n = 10;
	quickSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
