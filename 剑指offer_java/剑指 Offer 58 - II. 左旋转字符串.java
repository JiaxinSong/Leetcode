class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuilder res= new StringBuilder();
        String s1=s.substring(n);
        String s2=s.substring(0,n);
        res.append(s1);
        res.append(s2);
        return res.toString();
    }
}
