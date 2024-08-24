class Solution {
public:
    // int PivotIndex(vector<int>& nums){
    //     int s=0,e=nums.size()-1,mid;
    //     while(s<=e){
    //         mid=s+(e-s)/2;
    //         //corner case
    //         if(s==e){
    //             return s;
    //         }
    //         //bhaiya ne yaha pe bhi mistake kia tha
    //         else if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
    //             return mid;
    //         }
    //         //bhaiya ne yaha pe bhi mistake kia tha
    //         else if(mid-1 >= 0 && nums[mid]<nums[mid-1]){
    //             return mid-1;
    //         }
    //         //bhaiya ne yaha pe mistake kiya tha
    //         else if(nums[mid]<nums[0]){
    //            e=mid-1;
    //         }
    //         else{
    //             s=mid+1;
    //         }

              
            
    //     }
    //     return -1;
    // }

    //another way of finding pivoteIndex

    int PivotIndex(vector<int> & nums){
       int s = 0,e = nums.size()-1;
       int pivoteIndex;
       while(s<=e){
        int mid = s +(e-s)/2;
        if(nums[mid]<nums[0]){
          e = mid-1;
        }
        else{
            pivoteIndex = mid;
            s = mid+1;
        }
       }

       return pivoteIndex;
    }

    int BinarySearch(vector<int>& nums, int target, int Index ){
        int s,e,mid;
       
        if(target<nums[0]){
            s=Index+1;
            e=nums.size()-1;
        }
        else{
            s=0;
           e=Index;
        }


        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
        }
        return -1;

    }


    int search(vector<int>& nums, int target) {
        int Index=PivotIndex(nums);
        int Ans=BinarySearch(nums, target, Index);
        return Ans;
        
    }
};
