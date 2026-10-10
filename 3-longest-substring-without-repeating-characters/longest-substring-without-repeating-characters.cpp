class Solution {
    
    public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> lastseen;

        int left=0;
        int right=0;
        int maxlen=0;

        while(right<n){
            if(lastseen.count(s[right]) && lastseen[s[right]]>=left){
                left=lastseen[s[right]] + 1;
            }
            lastseen[s[right]]=right;

            maxlen=max(maxlen, right-left+1);

            right++;

        }

        return maxlen;
    }
};