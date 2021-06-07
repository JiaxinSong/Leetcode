class Solution {
    int count = 0;
    public int reversePairs(int[] nums) {
        int end=nums.length-1;
        if(end==-1) return 0;
        mergeSort(nums,0,end);
        return count;
    }
    
    void mergeSort(int[] nums, int start, int end){
        int mid=start+((end-start)>>1);
        if(start<end){
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    }
    void merge(int[] nums,int start, int mid, int end){
        int[] temparr=new int [end-start+1];
        int index=0;
        int temp1=start,temp2=mid+1;
        while(temp1<=mid&&temp2<=end){
            if(nums[temp1]<=nums[temp2]){
                temparr[index++]=nums[temp1++];
            }else{
                temparr[index++]=nums[temp2++];
                count+=mid-temp1+1;
            }
        }
        while(temp1<=mid){
            temparr[index++]=nums[temp1++];
        }
        while(temp2<=end){
            temparr[index++]=nums[temp2++];
        }
        for(int i=0;i<temparr.length;i++){
            nums[start+i]=temparr[i];
        }
    }
}
