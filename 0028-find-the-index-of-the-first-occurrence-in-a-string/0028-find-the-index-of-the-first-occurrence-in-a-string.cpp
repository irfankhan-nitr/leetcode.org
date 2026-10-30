class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                int j=i;
                while( j<haystack.size() and j-i< needle.size() and haystack[j]==needle[j-i]) j++;
               if(j-i==needle.size())return i;
            }
        }
    return -1;}
};