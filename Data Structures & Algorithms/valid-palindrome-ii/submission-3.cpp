class Solution {
public:
    bool ispal(string s,int i,int j){
        int n = s.size();
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int n = s.size();
        int i = 0,j = n-1;
        int k = 1;
        while(i < j) {
            if(s[i]!=s[j]){
                return ispal(s,i+1,j) || ispal(s,i,j-1);
                

            }
            else{
                i++;
                j--;
            }

        }
            return true;    
    }
};