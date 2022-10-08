#include<bits/stdc++.h>
using namespace std;
void swap1(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectSort(int arr[], int n){
	for(int i = 0, j; i < n - 1; i++){
		int index = i;
		int temp = arr[i];
		for(j = i+1; j < n; j++){
			if(temp > arr[j]){
				index = j;
				temp = arr[j];
			}
		}
		swap1(&arr[i], &arr[index]);
	}
}
int main(){
	int arr[] = {156,465,465,4,654,654,64,654,789,789};
	int n = 10;
	selectSort(arr, n);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	//cout<<n<<endl;
	cout<<endl;
	return 0;
}
