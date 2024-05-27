class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>merge;
        int a=0,b=0;
        while(a<m&&b<n){
            if(nums1[a]<=nums2[b]){
                merge.push_back(nums1[a]);
                a++;
            }
            else{
                merge.push_back(nums2[b]);
                b++;
            }
        }
        while(a<m){
            merge.push_back(nums1[a]);
            a++;
        }
        while(b<n){
            merge.push_back(nums2[b]);
            b++;
        }
        for(int i=0;i<merge.size();i++){
            nums1[i]=merge[i];
        }
        

    }
};
