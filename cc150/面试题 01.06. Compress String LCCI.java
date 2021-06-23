class Solution {
    public String compressString(String S) {
       if(S.length()==0) return S;
       StringBuilder ans=new StringBuilder();
       int cnt=1;
       char ch=S.charAt(0);
       for(int i=1;i<S.length();++i){
           if(ch==S.charAt(i)) cnt++;
           else {
               ans.append(ch);
               ans.append(cnt);
               ch=S.charAt(i);
               cnt=1;
           }
       }
       ans.append(ch);
       ans.append(cnt);
       return ans.length()>=S.length()? S: new String(ans);
    }
}

