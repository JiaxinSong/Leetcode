class Solution {
public:
int coun=0;
int temp[50000];
void merge(vector<int>&arr, int s, int e) {

	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;

	while ((i <= mid) && (j <= e)) {
		if (arr[i] <=arr[j]) {
			temp[k++] = arr[i++];
		}
		else if (arr[i] > arr[j]) {
			temp[k++] = arr[j++];
			coun += (mid - i + 1);
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= e) {
		temp[k++] = arr[j++];
	}
	for (int i = s; i <= e; i++) {
		arr[i] = temp[i];
	}
	
}
void mergeSort(vector<int>&arr, int s, int e) {
	if (s >= e) {
		return;
	}
	int mid = (s + e) / 2;
	mergeSort(arr, s, mid);
	mergeSort(arr, mid + 1, e);
	merge(arr, s, e);
}
    int reversePairs(vector<int>& data) {
        int n=data.size();
        if(n==0)  return 0;
        int s=0;int e=n-1;
        mergeSort(data, s, e);
        return coun;
    }
};

