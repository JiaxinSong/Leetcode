class Solution {
    public int maxProduct(String[] words) {
        int[] hash=new int[words.length];
        int n=words.length;
        int max=0;
        for(int i=0;i<n;++i){
            for(char c:words[i].toCharArray()) hash[i]|=1<<(c-'a');
        }
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;j++){
                if((hash[i]&hash[j])==0) max=Math.max(words[i].length()*words[j].length(),max);
            }
        }
        return max;
    }
}
