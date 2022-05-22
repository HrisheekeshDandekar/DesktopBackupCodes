/*
    leetCode [HARD]
        -> https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#define MEDIANS_NEEDED_ONE -1
#define MEDIANS_NEEDED_TWO -2

typedef struct Return_Values{
    int nums1_c;
    int nums2_c;
    int merged_c;
    int median1;
    int median2;
} Return_Values;

void fill_medians(int* nums1,int nums1Size, int* nums2,int nums2Size,
                  int elements_total, Return_Values* counters);
void median_location_count_calculated(int elements_total, Return_Values* counters);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    //Memory Innitialization
    Return_Values counters = {
        .num1_c = 0,
        .nums2_c = 0,
        .merged_c = 0,
        .median1 = -69,    //Set to the total medians needed
        .median2 = -69     //Set to first median required in case 2 medians need calculation
    };
    int elements_total = nums1Size + nums2Size;

    //Calculating median location, 
    median_location_count_calculated(elements_total, &counters);

    //Calculating median values
    fill_medians(nums1, nums1Size, nums2, nums2Size,
                          elements_total, &counters);

   //Calculate Final Median and return           
   double final_median = ((double)counters.median1 + (double)counters.median2) / 2;
   return final_median;
}

void median_location_count_calculated(int elements_total, Return_Values* counters)
{
    //If even number of total elements present, 
    //set correct falags and indicate which counter positions
    //Flag set on first median member, first counter set on
    if (!(elements_total % 2))
    {
        counters->median1 = MEDIANS_NEEDED_TWO;
        //As two medians needed, the position of first median in the 
        //simulated sorted array is stored in median2
        counters->median2 = (elements_total / 2) - 1; // FAILS AT 1 || 2 total_elements case
    }
    else //Odd total elements
    {
        counters->median1 = MEDIANS_NEEDED_ONE;
        counters->median2 = elements_total / 2; 
    }
}

void fill_medians(int* nums1,int nums1Size, int* nums2,int nums2Size,
                  int elements_total, Return_Values* counters)
{
    for (int i = 0; i < counters->median2; i++)
    {
        if (counters->nums1_c == nums1Size)
        {
            if (counters->nums2_c < nums2Size)
            {

            }
        }
        else if (counters->nums2_c == nums2Size)
        {
            if (counters->nums1_c < nums1Size)
            {

            }
        }

        if (nums1[counters->nums1_c] <= nums2[counter->nums2_c])
        {
            counters->nums1_c++;
        }
        else
        {
            counters->nums2_c++;
        }
        
        counters->merged_c++;
    }

    if (counters->median1 == MEDIANS_NEEDED_TWO)
    {
        //if an array is exhausted
        if (counters->nums1_c == nums1Size)
        {

        }
    }
    else
    {
        counters->median1;
    }
}
