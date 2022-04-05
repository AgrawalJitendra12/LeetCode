//First Attempt (Brute Force)
/*class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int area=0;
        int smallerVal=0;
        
        if(!height.empty()){            
            for(int i=0; i<height.size()-1;i++){
                for(int j=i+1;j<height.size();j++){
                    //determine which value is smaller
                     if(height.at(i)>=height.at(j))
                     {
                         smallerVal=height.at(j);
                     }
                    else
                    {
                        smallerVal=height.at(i);
                    }

                    //calculate area
                    area=smallerVal*(j-i);

                    //determine if the area is larger than the current max area
                    if(area>maxArea){
                        maxArea=area;
                    }
                }
            }
        }
        
        return maxArea;
    }
};*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int area=0;
        int smallerVal=0;
        int i = 0;
        int j = height.size()-1;
        
         while(i!=j){
             if(height.at(i)>height.at(j))
             {
                 area=height.at(j) * (j-i);
                 j--;
             }
            else
            {
                area=height.at(i) * (j-i);
                i++;
            }
             
            if(area>maxArea){
                maxArea=area;
            }
         }
        
        return maxArea;
    }
};
