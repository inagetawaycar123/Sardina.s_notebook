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