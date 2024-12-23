/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool check(int* Ls, int LsSize, int el){
    if (LsSize == 0) {
        return false;
    }
    for (int i = 0; i < LsSize; i++) {
        if (el == Ls[i]) {
            return true;
        }
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* Ls = (int*)malloc(nums1Size*sizeof(int));
    int counter = 0;
    for (int i = 0; i < nums1Size; i++){
        int el = nums1[i];
        if (check(nums2, nums2Size, el) && !check(Ls, counter, el)) {
            Ls[counter] = el;
            counter++;
        }
    }
    *returnSize = counter;
    return Ls;
    
}