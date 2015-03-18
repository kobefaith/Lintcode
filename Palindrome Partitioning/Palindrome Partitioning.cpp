class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        
        palindrome_partition(s,result,temp);
        
        return result;
    }
    void palindrome_partition(string s,vector<vector<string>> &result,vector<string> &temp){
        if (s.empty()){
            result.push_back(temp);
            return;
        }
        
        for (int i = 1; i <=s.size(); i++){
            string part = s.substr(0,i);
            if (ispalindrome(part)){
                temp.push_back(part);
                palindrome_partition(s.substr(i,s.size()-i),result,temp);
                temp.pop_back();
            }
        }
    }
    bool ispalindrome(string s){
        int beg = 0;
        int end = s.size()-1;
        if (s.size() == 1)
            return true;
            
        while (beg < end){
            if (s[beg++] != s[end--])
                return false;
        }
        
        return true;
    }
};
