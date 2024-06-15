#include <stdio.h>
int count_comparisons_Inserion =0;
int count_shifts_Insertion=0;

int count_comparisons_bubble=0;
int count_shifts_bubble=0;
void Linear_Insertion(int arr[],int n){
    int i,temp,j;
    for(int i=1; i<n; i++){
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            count_comparisons_Inserion++;
            count_shifts_Insertion++;
            arr[j+1] = arr[j];
            j=j-1;
            
            
        }
        arr[j+1] = temp;
        count_shifts_Insertion++;
    }
}
void Bubble_sort(int arr[],int n){
    for(int i =0; i<n; i++){
        
        for(int j =0; j<n-i-1; j++){
            count_comparisons_bubble++;
            if(arr[i] > arr[i+1]){
                count_shifts_bubble++;
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                
            }
            
        }
    }
}
void print_Array(int arr[],int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int Array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(Array)/sizeof(Array[0]);

    printf("Array Before sorting: \n");
    print_Array(Array,size);
      //call the fuction in main

    printf("Array After Linear insertion sort: \n");
    Linear_Insertion(Array,size); 
    print_Array(Array,size);
    printf("Linear Insertion--> Comparisons:%d Shifts:%d\n\n",count_comparisons_Inserion,count_shifts_Insertion);

    //comment one fuction because when passing the array it's already sorted 

    printf("Array After Bubble sort: \n");
    Bubble_sort(Array,size); 
    print_Array(Array,size);
    printf("Bubble Sort--> Comparisons:%d Shifts:%d\n\n",count_comparisons_bubble,count_shifts_bubble);
    return 0;
}