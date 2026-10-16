class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int minlen=INT_MAX;
        int sindex=-1;
        int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int,int> mpp;

        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }

        while(r<n){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;

            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(sindex==-1) return "";
        return s.substr(sindex,minlen);
    }
};