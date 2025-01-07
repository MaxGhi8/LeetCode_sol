/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int check(int* Ls, int LsSize, int el){
    if (LsSize == 0) {
        return -1;
    }
    for (int i = 0; i < LsSize; i++) {
        if (el == Ls[i]) {
            return i;
        }
    }
    return -1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* Ls = (int*)malloc(nums1Size*sizeof(int));
    int counter = 0;
    for (int i = 0; i < nums1Size; i++){
        int el = nums1[i];
        int idx = check(nums2, nums2Size, el);
        if (idx >= 0) {
            Ls[counter] = el;
            nums2[idx] = -1;
            counter++;
        }
    }
    *returnSize = counter;
    return Ls;
    
}