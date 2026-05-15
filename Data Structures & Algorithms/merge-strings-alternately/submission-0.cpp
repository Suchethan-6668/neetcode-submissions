class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";

        int n1 = word1.size(),n2 = word2.size();

        int i = 0,j = 0,k = 0;

        while(i < n1 && j < n2) {
            if(k%2){
                res += word2[j];
                j++;
            }else{
                res += word1[i];
                i++;
            }
            k++;
        }
        while(i < n1){
            res += word1[i++];
        }
        while(j < n2) {
            res += word2[j++];
        }
        return res;
    }
};