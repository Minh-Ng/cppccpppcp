class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void quicksort(vector<int>& nums, int i, int j) {
        if (j <= i) {
            return;
        }
        
        int partitionIndex = partition(nums, i, j);
        quicksort(nums, i, partitionIndex - 1);
        quicksort(nums, partitionIndex + 1, j);
    }
    
    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = std::rand() % (hi - lo) + lo;
        std::swap(nums[pivot], nums[hi]);
        
        pivot = lo;
        for (int j = lo; j < hi; ++j) {
            if (nums[j] < nums[hi]) {
                std::swap(nums[pivot++], nums[j]);
            }
        }
        
        std::swap(nums[pivot], nums[hi]);
        return pivot;
    }
};
