#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
void merge(int *array, int l, int h, int m, int tar, int CHECK) //main merge which goes through and sorts through the array. At the same time it checks whether
{//the current numbers in memory add up to the target. If they do the program stops checking for the sums and finishes up sorting.
    int i, j, k, check, temp[1000];
    i = l, k = l, j = m + 1, check = CHECK;
    while (i <= m && j <= h && check==0) 
    {
        if (array[i] < array[j]) 
        {
            temp[k] = array[i];
            i++;
        }
        else  
        {
            temp[k] = array[j];
            j++;
        }
        if((array[l] + array[h] == tar) && check==0)
        {
            printf("The number %d at index %d plus number %d at index %d equals the target number %d\n", array[l], l, array[h], h, tar);
            check = 1;//The repeated print statements are at points where it might be possible to find the target sum at. Ugly, but necessary.
        }
        k++;
    }
    while (i <= m && check==0) 
    {
        temp[k] = array[i];
        k++, i++;
        if((array[l] + array[h] == tar) && check==0)
        {
            printf("The number %d at index %d plus number %d at index %d equals the target number %d\n", array[l], l, array[h], h, tar);
            check = 1;
        }
    }
    while (j <= h && check==0) 
    {
        temp[k] = array[j];
        k++, j++;
        if((array[l] + array[h] == tar) && check==0)
        {
            printf("The number %d at index %d plus number %d at index %d equals the target number %d\n", array[l], l, array[h], h, tar);
            check = 1;
        }
    }
    for (i = l; i < k; i++)  
    {
        array[i] = temp[i];
    }
}
void mergeSort(int *array, int l, int h, int tar, int check) //various ints for the two sub arrays as well as the target and a check to make sure there's no
{ //repeated sum of variables
   int m;
   if(l < h) 
   {
        m = (h + l)/2;
        // low, high, and middle.
        if(array[l] + array[h] == tar)
        {
            printf("The number %d at index %d plus number %d at index %d equals the target number %d\n", array[l], l, array[h], h, tar);
            check = 1;
        }
        mergeSort(array, l, m, tar, check);
        mergeSort(array, m+1, h, tar, check);
        merge(array, l, h, m, tar, check);
   }
}
int main()
{
    printf("Enter the length of your array.\n");//main code asks for valid length, valid ints for the array, valid target, and prints back out the sorted array
    int ArrLen, tempPlace, tar, i;
    while(!(cin >> ArrLen))
    {
       cout << "Enter a valid integer." << endl;
        cin.clear();
    }
    cin.clear();
    int arr[ArrLen];
    for(i = 0; i < ArrLen; i++)
    {
        printf("Enter the digit for %d index of your array.\n", i); 
        while(!(cin >> tempPlace))
        {
            cout << "Enter a valid integer." << endl;
            cin.clear();
        }
    arr[i]=tempPlace;
    }
    cin.clear();
    printf("Enter the target number.\n");
    while(!(cin >> tar))
    {
       cout << "Enter a valid integer." << endl;
       cin.clear();
    }
    cin.clear();
    mergeSort(arr, 0, (ArrLen-1), tar, 0);
    cout << "Sorted" << endl;
    for(int i = 0; i < ArrLen; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl;
}
