class Solution {
    public String addBinary(String a, String b) {
        StringBuilder ans= new StringBuilder();
        int ca=0;
        int i=a.length()-1,j=b.length()-1;

        while(j>=0||i>=0){
            int sum=ca;
            sum+=  i>=0? a.charAt(i)-'0':0;
            sum+=  j>=0? b.charAt(j)-'0':0;
            ans.append(sum%2);
            ca=sum/2;
            i--;
            j--;
        }
        ans.append(ca==1? ca:"");
        return ans.reverse().toString();

    }
}


