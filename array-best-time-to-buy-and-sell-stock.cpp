class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
        return 0;
        int p=prices[1]-prices[0];
        int m=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-m>p)
            p=prices[i]-m;
            
            if(m>prices[i])
            m=prices[i];
        }
        return (p>=0)?p:0;
    }
};
