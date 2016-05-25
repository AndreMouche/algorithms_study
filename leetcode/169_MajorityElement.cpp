int majorityElement(int* nums, int numsSize) {
    int cur = 0;
    int total = 0;
    for(int id=0;id<numsSize;id++){
        if(total==0 || cur==nums[id]){
            cur=nums[id];
            total++;
            continue;
        }
        total--;
    }
    return cur;
}
