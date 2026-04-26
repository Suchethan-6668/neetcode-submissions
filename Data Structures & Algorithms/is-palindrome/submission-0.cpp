class Solution {
public:
    bool isPalindrome(string s) {
        string toc = "";
        for(char &c: s){
            if((c >= 'a'&& c <= 'z')||(c >= 'A'&& c <= 'Z')||(c >= '0'&& c <= '9')){
                toc+=tolower(c);
            }
        }
        int i = 0;
        int j = toc.size()-1;
        while(i < j){
            if(toc[i] != toc[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
