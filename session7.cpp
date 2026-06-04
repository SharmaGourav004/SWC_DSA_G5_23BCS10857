class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int>mp;
       for(auto i:t){
        mp[i]++;
       }
       int left=0;
       int right=0;
       int cnt=t.size();
       int minlen=INT_MAX;
       int start=0;
       while(right<s.size()){
        if(mp[s[right]]>0){
            cnt--;
        }
        mp[s[right]]--;
        right++;
        while(cnt==0){
            if(right-left<minlen){
                minlen=right-left;
                start=left;
            }
            mp[s[left]]++;
            if(mp[s[left]]>0){
                cnt++;
            }
            left++;
        }
       } 
           return minlen== INT_MAX ? "" : s.substr(start,minlen);

    }
};