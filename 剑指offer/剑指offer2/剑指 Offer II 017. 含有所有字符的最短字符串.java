class Solution 
{
    public String minWindow(String s, String t) {
        int[] mp = new int[256];
        for (char c : t.toCharArray()) mp[c] += 1;
        int start = 0, end = 0;
        int n = s.length(), m = t.length();
        int cnt = 0;
        int res = -1;
        String ans = "";
        while (end < n) {
            char c = s.charAt(end);
            mp[c] -= 1;
            if (mp[c] >= 0) cnt += 1;
            while (cnt == m) {
                if (res == -1 || res > end - start + 1) {
                    ans = s.substring(start, end + 1);
                    res = end - start + 1;
                }
                c = s.charAt(start);
                mp[c] += 1;
                if (mp[c] >= 1) cnt -= 1;
                start += 1;
            }
            end += 1;
        }
        return ans;
    }
}
