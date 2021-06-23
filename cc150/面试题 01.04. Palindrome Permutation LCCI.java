class Solution {
        public boolean canPermutePalindrome(String s) {
        int[] map = new int[128];
        int count = 0;
        for (char ch : s.toCharArray()) {
            //如果当前位置的字符数量是奇数，再加上当前字符
            //正好是偶数，表示消掉一个，我们就把count减一，
            //否则count就加一
            if ((map[ch]++ & 1) == 1) {
                count--;
            } else {
                count++;
            }
        }
        return count <= 1;
    }
}

class Solution {
    public boolean canPermutePalindrome(String s) {
        if(s == null){
            return false;
        }
        char[] chars = s.toCharArray();
        Set<Character> set = new HashSet<>();
        for(char c : chars){
            if(set.contains(c)){
                set.remove(c);
            }else{
                set.add(c);
            }
        }
        return set.size() <= 1;
    }
}
