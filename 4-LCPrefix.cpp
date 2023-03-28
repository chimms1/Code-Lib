#include <bits/stdc++.h>
#include <string>
#include <cstring>

using namespace std;
class Solution {
public:
    int findMinLength(vector<string>& strs, int n)
    {
        int min = strs[0].length();
 
        for (int i=1; i<n; i++)
            if (strs[i].length() < min)
                min = strs[i].length();
 
        return(min);
    }

    string longestCommonPrefix(vector<string>& strs) {

        int minlen = findMinLength(strs, strs.size());
    
        string result;
        char current;
    
        for (int i=0; i<minlen; i++)
        {
            current = strs[0][i];
    
            for (int j=1 ; j<strs.size(); j++)
                if (strs[j][i] != current)
                    return result;

            result.push_back(current);
        }
    
        return (result);
    }
}; 
