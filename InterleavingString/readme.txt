public class Solution {  
    /** 
     * Determine whether s3 is formed by interleaving of s1 and s2. 
     * @param s1, s2, s3: As description. 
     * @return: true or false. 
     */  
    public boolean isInterleave(String s1, String s2, String s3) {  
        if(null == s1 || null == s2 || null == s3 || s1.length() + s2.length() != s3.length())  
            return false;  
        if(s1.length() <= 0 && s2.length() <= 0 && s3.length() <= 0)  
            return true;  
  
        boolean[][] common = new boolean[s1.length() + 1][s2.length() + 1];  
        for(int i = 1;i <= s1.length();i++)  
        {  
            if(s1.charAt(i - 1) == s3.charAt(i - 1))  
            {  
                common[i][0] = true;  
            }  
        }  
  
        for(int i = 1;i <= s2.length();i++)  
        {  
            if(s2.charAt(i - 1) == s3.charAt(i - 1))  
            {  
                common[0][i] = true;  
            }  
        }  
  
        for(int i = 1;i <= s1.length();i++)  
        {  
            for(int j = 1;j <= s2.length();j++)  
            {  
                if(s1.charAt(i - 1) == s3.charAt(i + j - 1))  
                {  
                    common[i][j] = common[i - 1][j];  
                }  
  
                if(common[i][j])  
                {  
                    continue;  
                }  
  
                if(s2.charAt(j - 1) == s3.charAt(i + j - 1))  
                {  
                    common[i][j] = common[i][j - 1];  
                }  
            }  
        }  
        return common[s1.length()][s2.length()];  
    }  
}  