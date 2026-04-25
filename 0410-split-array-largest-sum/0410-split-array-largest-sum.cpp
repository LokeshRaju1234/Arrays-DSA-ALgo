class Solution {
public:
 int func(vector<int>& arr,int pages)
    {
        int studentpages = 0,student = 1;
        for(int i = 0;i < arr.size();i++)
        {
            //if the pages that the student is holding and the current book is under
            //the range so we can add pages or allocate this page to the student
            if(studentpages + arr[i] <= pages)
            {
                studentpages += arr[i];
            }
            else
            {
                //go to next student and restart wth 0
                student++;
                studentpages = arr[i];
            }
        }
        
        return student;
    }
    
    int findPages(vector<int> &arr, int k) 
    {
        //not possible bcz if there is more number of students than the pages 
        //we cant allocate the pages to the students
          if(k > arr.size()) return -1;
          int ans = -1;
        // code here
        int low = *max_element(arr.begin(),arr.end());
        //to get sum we use accumulate
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            //if the number of students is more eliminate the left half
            int cntstd = func(arr,mid);
            if(cntstd > k)
            {
                
                low  = mid + 1;
            }
            else
            {
                //if it is less or equal to i will look into minimum so i will eliminate right half
                high = mid - 1;
            }
        }
        
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};