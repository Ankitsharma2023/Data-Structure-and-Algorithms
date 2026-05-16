class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n==0) return true;
        int j = flowerbed.size();
        for(int i =0;i<j;i++)
        {
            if(flowerbed[i]==0)
            {
                bool leftempty = (i==0)|| (flowerbed[i-1]==0);
                bool rightempty = (i==j-1) || (flowerbed[i+1]==0);

                if(leftempty && rightempty)
                {
                    flowerbed[i]=1;
                    n--;

                    if(n==0) return true;
                }
            }
        }

        return false;
    }
};