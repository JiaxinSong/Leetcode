class Solution {
    public boolean isFlipedString(String s1, String s2) {
        int len=s1.length();
        if(len==s2.length()){
            String x=s1+s1;
            if (x.contains(s2)==true) return true;
        }
        return false;
    }
}
