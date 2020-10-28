class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
		return nums;
	}
	void QuickSort(vector<int>& nums, int l, int r) {
		if (l < r)
		{
			int partition = randomPartition(nums, l, r);
			QuickSort(nums, l, partition - 1);
			QuickSort(nums, partition + 1, r);
		}
	}
	int randomPartition(vector<int>& nums, int l, int r)
	{
		int i = (rand() % (r - l + 1)) + l;//产生[a,b]的随机整数
		swap(nums[i], nums[l]);
		return partition(nums, l, r);
	}
	int partition(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];
		int i = l + 1, j = r;//双指针，分别指向首尾
		while (true)
		{
			while (i <= j && nums[i] <= pivot) i++;
			while (i <= j && nums[j] >= pivot) j--;
			if (i > j) break;
			//交换位置
			swap(nums[i], nums[j]);
		}
		//交换主元
		swap(nums[j], nums[l]);
		return j;
	}
};
