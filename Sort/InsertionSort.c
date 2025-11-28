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