extern int* InsertionSort(int* array, int length){
    int* head = array;
    for(int i = 1; i < length; i++){
        int temp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j]>temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
    return head;
}

extern int* BubbleSort(int* array, int length){
    int* head = array;
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
    return head;
}

extern int* SelectSort(int *array, int length){
    int* head = array;
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
    return head;
}