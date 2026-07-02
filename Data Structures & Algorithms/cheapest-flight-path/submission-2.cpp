class Solution {
    unordered_map<int,vector<pair<int,int>>> linked_dest;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price_to_arrive(n,INT_MAX);
        price_to_arrive[src] = 0;

        for(int i=0;i<=k;i++)
        {
            vector<int> price_to_arrive_with_k = price_to_arrive;
            for(auto f:flights)
            {
                auto src_arp=f[0];
                auto dst_arp=f[1];
                auto leg_price=f[2];
                auto price_to_dst = price_to_arrive[src_arp]+leg_price;
                if(price_to_arrive[src_arp]!=INT_MAX and price_to_dst<price_to_arrive_with_k[dst_arp])
                {
                    price_to_arrive_with_k[dst_arp] = price_to_dst;
                }
            }
            price_to_arrive = price_to_arrive_with_k;
        }

        return price_to_arrive[dst]==INT_MAX?-1:price_to_arrive[dst];

    }

};
