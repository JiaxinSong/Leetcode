//归并排序 重点是参数：（数组，起点，终点） 用一个数组temp存放合并后的结果并覆盖原来的数组    

//   简单的分析下元素长度为n的归并排序所消耗的时间 T[n]：调用mergeSort()函数划分两部分，那每一小部分排序好所花时间则为  T[n/2]，而最后把这两部分有序的数组合并成一个有序的数组_mergeSort()函数所花的时间为  O(n)；

//         公式：T[n]  =  2T[n/2] + O(n)；
        
//         公式就不仔细推导了，可以参考下： 排序算法之快速排序及其时间复杂度和空间复杂度里面时间复杂度的推导；

//         所以得出的结果为：T[n] = O( nlogn )





class Solution {
public:
    int res=0; 
    int temp[50000];
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0) return 0;
        mergesort(nums,0,nums.size()-1);
        return res;
    }
    void mergesort(vector<int>& nums, int s, int e){
        if(s==e) return;    //只有一个元素
        int mid=s+(e-s)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);
        merge(nums,s,e);
    }
    void merge(vector<int>&nums,int s,int e){
        int mid = s+(e-s)/2;
        int i=s;        
        int j=mid+1;        
        int k=s;              //temp 数组的游标
        while((i<=mid)&&(j<=e)){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }else{
                temp[k++]=nums[j++];
                res+=mid-i+1;         //一旦发现左边比右边大说明左边从i到mid都能的j形成逆序对 
            }
        }

        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=e){
            temp[k++]=nums[j++];
        }
        for(int i=s;i<=e;i++){
            nums[i]=temp[i];
        }
    }

};
