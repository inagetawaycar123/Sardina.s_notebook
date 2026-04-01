#include <stdio.h>
#include <stdlib.h>

int minf(int x, int y) {
    return x < y ? x : y;
}

extern void InsertionSort(int* array, int length){
    for(int i = 1; i < length; i++){
        int temp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j]>temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

extern void BubbleSort(int* array, int length){
    int count = 0;
    do{
        count = 0;
        for(int i=0; i < length-1; i++){
            if(array[i] > array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                count++;
            }
        }
    } while(count!=0);
}

extern void SelectSort(int *array, int length){
    for(int i = 0; i < length - 1; i++){
        int temp = array[i];
        int pos = i;
        for(int j = i + 1; j < length; j++){
            if(temp > array[j]){
                temp = array[j];
                pos = j;
            }
        }
        array[pos] = array[i];
        array[i] = temp;
    }
}

extern void MergeSort(int *array, int length){
    int *a = array;
    int *b = malloc(length * sizeof(int));
    for(int seg = 1; seg < length; seg += seg){
        for(int start = 0; start < length; start += 2*seg){
            int head = start, mid = minf(start + seg, length),
            end = minf(start + 2*seg, length);
            int k = head;
            int lt1 = head, lt2 = mid, rt1 = mid, rt2 = end;
            while(lt1 < rt1 && lt2 < rt2){
                b[k++] = a[lt1] < a[lt2] ? a[lt1++] : a[lt2++];
            }
            while(lt1 < rt1){
                b[k++] = a[lt1++];
            }
            while(lt2 < rt2){
                b[k++] = a[lt2++];
            }
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if(a != array){
        for(int i = 0; i < length; i++){
            a[i] = b[i]; 
        }
    }  
    free(b);
}

extern void ShellSort(int *array, int length){
    int gap, i, j, temp;
    for(gap = length/2; gap > 0; gap /= 2){
        for(i = 0; i + gap < length; i++){
            j = i + gap;
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int Partition(int *array, int low, int high){
    int pivot = array[low];
    while(low < high){
        while(high > low && array[high] >= pivot){
            --high;
        }
        array[low] = array[high];
        while(low < high && array[low] <= pivot){
            ++low;
        }
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}

extern void QuickSort(int *array, int low, int high){
    if(low < high){
        int pivotpos = Partition(array, low, high);
        QuickSort(array, low, pivotpos-1);
        QuickSort(array, pivotpos+1, high);
    }
}