class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int b = nums1.size();
        int c = nums2.size();
        vector<int> nums3(b+c);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        sort(nums3.begin(),nums3.end());
        int a= nums3.size();
        /*cout<<a<<endl;
        for(int i=0;i<a;i++){
            cout<<nums3[i]<<" ";
        }
        cout<<endl;*/
        if(a==0){
            return 0;
        }
            if(a%2==0){
                double a1 = nums3[a/2];
                double a2 = nums3[a/2 - 1];
                return (a1+a2)/2;
            }
            else if(a%2==1){
                return nums3[a/2];
            }
        return 0;
    }
};
