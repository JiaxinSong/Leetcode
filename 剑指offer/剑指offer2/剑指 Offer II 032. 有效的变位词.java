class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;
        if(s.equals(t)) return false;
        Map<Character,Integer> map=new HashMap<>();
        for(int i=0;i<s.length();i++){
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
            map.put(t.charAt(i),map.getOrDefault(t.charAt(i),0)-1);
        }
        Iterator<Map.Entry<Character,Integer>> it= map.entrySet().iterator();

        while(it.hasNext()){
            Map.Entry<Character,Integer> en=it.next();
            if(en.getValue()!=0) return false;
        }


        return true;

    }
}

