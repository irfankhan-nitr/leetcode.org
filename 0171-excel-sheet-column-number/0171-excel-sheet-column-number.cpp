class Solution {
public:
    int titleToNumber(string title) {
        int ans=0;
        for(int i=1;i<title.size();i++){
            ans+=pow(26,i);
        }
        for(int i=0;i<title.size();i++){
            ans+=(title[i]-'A')*pow(26,title.size()-1-i);
        }
        ans+=1;
        return ans;
    }
};