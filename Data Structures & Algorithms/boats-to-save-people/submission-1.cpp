class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n= people.size();

        sort(people.begin(),people.end());

        int i = 0,j = n-1;
        int sum = 0;
        int cnt = 0;
        while(i < j) {
            sum = people[i]+people[j];
            if(sum <= limit){
                cnt++;
                i++;
                j--;
                continue;
            }
            int diff1 = limit - people[i];
            int diff2 = limit - people[j];
            if(diff1 <= diff2){
                cnt++;
                i++;
            }else{
                cnt++;
                j--;
            }
        }
        if(i == j)cnt++;
        return cnt;
    }
};