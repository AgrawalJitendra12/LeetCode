//First attempt. Uses sorted array and pointers to each end of the sorted array
/*class Solution {
public:
    void MergeSortedIntervals(vector<int>& v, int s, int m, int e) {
	
        // temp is used to temporary store the vector obtained by merging
        // elements from [s to m] and [m+1 to e] in v
        vector<int> temp;

        int i, j;
        i = s;
        j = m + 1;

        while (i <= m && j <= e) {

            if (v[i] <= v[j]) {
                temp.push_back(v[i]);
                ++i;
            }
            else {
                temp.push_back(v[j]);
                ++j;
            }

        }

        while (i <= m) {
            temp.push_back(v[i]);
            ++i;
        }

        while (j <= e) {
            temp.push_back(v[j]);
            ++j;
        }

        for (int i = s; i <= e; ++i)
            v[i] = temp[i - s];

    }

    // the MergeSort function
    // Sorts the array in the range [s to e] in v using
    // merge sort algorithm
    void MergeSort(vector<int>& v, int s, int e) {
        if (s < e) {
            int m = (s + e) / 2;
            MergeSort(v, s, m);
            MergeSort(v, m + 1, e);
            MergeSortedIntervals(v, s, m, e);
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> trips;
        
        if(nums.size()>2){
            vector<int> trip;
            int i = 0;
            int jVal = 0;
            int k = nums.size()-1;

            MergeSort(nums, 0, k);
            
            while(k>i){
                jVal=0-(nums.at(i)+nums.at(k));
                if(jVal>=nums.at(i) && jVal<=nums.at(k)){
                    trip.clear();
                    for(int j=i+1;j<k;j++){
                        if(nums.at(j)==jVal){
                            trip.push_back(nums.at(i));
                            trip.push_back(nums.at(j));
                            trip.push_back(nums.at(k));
                            i=j;
                            trips.push_back(trip);
                            break;
                        }
                    }
                }
                else{
                    k--;
                }
            }
            
        }
        
        return trips;
    }
};*/

//bad brute force (does not work)
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> trips;
        
        if(nums.size()>2){

            unordered_map<int, int> umap;
            
            for(int i=0; i<nums.size();i++){
                umap[nums.at(i)]+=1;
            }
            
            for(int i=0;i<nums.size();i++){
                for(int j=i;j<nums.size();j++){
                    int k = 0-(i+j);
                    umap[nums.at(i)]--;
                    umap[nums.at(j)]--;
                    if(umap[k]!=0){
                        bool flag = true;
                        for(int x=0; x<trips.size();x++){
                            if(trips.at(x).at(0)==nums.at(i) &&
                               trips.at(x).at(1)==nums.at(j) &&
                               trips.at(x).at(2)==k){
                                flag = false;
                                break;
                            }
                        }
                        if(flag){
                            vector<int> trip;
                            trip.push_back(nums.at(i));
                            trip.push_back(nums.at(j));
                            trip.push_back(k);
                            trips.push_back(trip);
                        }
                    }
                    umap[nums.at(i)]++;
                    umap[nums.at(j)]++;
                }
            }
        }
        
        return trips;
    }
};
*/