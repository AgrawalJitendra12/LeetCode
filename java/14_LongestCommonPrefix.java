/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
public String longestCommonPrefix(String[] strs) {
    if(strs == null || strs.length == 0)    return "";
    String pre = strs[0];
    int i = 1;
    while(i < strs.length){
        while(strs[i].indexOf(pre) != 0)
            pre = pre.substring(0,pre.length()-1);
        i++;
    }
    return pre;
}

//brute force
/*
class Solution {
    public String longestCommonPrefix(String[] strs) 
    {
        String prefix = "";
        for(int i=0; i<strs.length; i++)
        {
            String tempPrefix = "";
            for(int j=0; j<strs[i].length();j++)
            {
                if(strs[i+1].length()>=j)
                {
                    if(strs[i].charAt(j) == strs[i+1].charAt(j))
                    {
                        tempPrefix = tempPrefix + strs[i].charAt(j);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if(tempPrefix.length()>prefix.length())
            {
                prefix = tempPrefix;
            }
        }
        return prefix;
    }
}
*/