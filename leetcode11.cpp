class Solution {
public:
    int maxArea(vector<int>& height) {
         int maxW=0;
         int lp=0;
         int rp=height.size() - 1;;
        while(rp>lp){
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int currW=w*ht;
            maxW=max(maxW,currW);
            height[lp]<height[rp]? lp++ : rp-- ;
        }
        return maxW;
    }

};