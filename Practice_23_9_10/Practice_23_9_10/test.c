#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int pnums1 = 0;
    int pnums2 = 0;
    int ret = 0;
    int tem = 0;
    if (nums1Size == 0 && nums2Size % 2 == 1)
    {
        return nums2[nums2Size / 2];
    }
    if (nums2Size == 0 && nums1Size % 2 == 1)
    {
        return nums1[nums1Size / 2];
    }
    if (nums1Size == 0 && nums2Size % 2 == 0)
    {
        return (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
    }
    if (nums2Size == 0 && nums1Size % 2 == 0)
    {
        return (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
    }
    if (nums1Size == 1 & nums2Size == 1)
    {
        return (nums1[0] + nums2[0]) / 2.0;
    }
    for (int i = 0; i < (nums1Size + nums2Size); i++)
    {
        if (pnums2 == nums2Size)
            goto lable;
        if (pnums1 == nums1Size || nums1[pnums1] > nums2[pnums2])
        {
            ret = nums2[pnums2];
            pnums2++;
        }
        else
        {
        lable:
            ret = nums1[pnums1];
            pnums1++;
        }
        if ((nums1Size + nums2Size) % 2 == 1 && i == (nums1Size + nums2Size) / 2)
            return (double)ret;
        if ((nums1Size + nums2Size) % 2 == 0 && i == (nums1Size + nums2Size) / 2 - 1)
            tem = ret;
        if ((nums1Size + nums2Size) % 2 == 0 && i == (nums1Size + nums2Size) / 2)
            return (tem + ret) / 2.0;
    }
    return 0.0;
}
int main()
{
    int arr1[2] = { 1,2 };
    int arr2[2] = { 3,4 };
    printf("%lf", findMedianSortedArrays(arr1, 2, arr2, 2));
    return 0;
}