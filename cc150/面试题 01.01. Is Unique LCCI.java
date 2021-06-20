class Solution {
    public boolean isUnique(String astr) {
        for (int i=0;i<astr.length();i++){
            if (astr.lastIndexOf(astr.charAt(i))!=i){
                return false;
            }
        }
        return true;
    }
}



class Solution {
    public boolean isUnique(String astr) {
        int mark = 0;
        for(char ch : astr.toCharArray()) {
            int index = ch - 'a';
            if((mark & (1 << index)) != 0) {
                return false;
            } else {
                mark |= (1 << index);
            }
        }
        return true;
    }
}
