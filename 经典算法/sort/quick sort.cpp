//j是小于等于pivot的最大元素的下标
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



class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

