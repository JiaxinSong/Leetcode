class Solution {
    public List<Integer> findAnagrams(String s2, String s1) {
        List<Integer> list=new ArrayList<>();
        int n=s1.length(),m=s2.length();
        if(n>m) return list;
        int[] cnt=new int [26];
        for(int i=0;i<n;i++){
            --cnt[s1.charAt(i)-'a'];
        }
        int left=0;
        for(int right=0;right<m; ++right){
            int x=s2.charAt(right)-'a';
            ++cnt[x];
            while(cnt[x]>0){
                --cnt[s2.charAt(left)-'a'];
                ++left;
            }
            if(right-left+1==n) {
                list.add(left);
            }
        }
        return list;
    }
}


