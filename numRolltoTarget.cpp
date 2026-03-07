//
//  Number_of_dice_roll_with_target.cpp
//  DS_in_Cpp
//
//  Created by Veepin_Chaudhary on 24/02/26.
//


#include <iostream>
#include <vector>
using namespace std;
class solution{
public:
    
    int dice_target(int n,int k,int target){
        if(target==0 and n==0) return 1;
        if(n==0) return 0;
        int sum=0;
        for(int i=1;i<=k;i++){
            
                sum+=dice_target(n-1,k,target-i);
            
        }
        return sum;
        
        
    }
    int numsRolltoTarget(int n,int k,int target){
        return dice_target(n,k,target);
    }
};


int main(){
    class solution S;
    cout<<S.numsRolltoTarget(2,6,7)<<endl;
    return 0;
}
