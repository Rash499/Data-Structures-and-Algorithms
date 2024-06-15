#include<stdio.h>
double arr[15] = {34.5, 56.7, 12.6, 98.4, 54.21,
                89.55, 54.2, 98.4, 73.2, 21.45,
                34.5, 98.4, 21.45, 98.4, 9.3};
double total(){
    double count =0;
    for(int i=0;i<15;i++){
        count = count + arr[i];
    }
    return count;
}
double average(){
    double avg = 0;
    double count = 0; 
    for(int i=0; i<15; i++){
        count = count + arr[i];
    }
    avg = count/15;
    return avg;
}
double max(){
    double temp =arr[0];
    for(int i=0; i<15; i++){
        if(temp <arr[i+1]){
            temp = arr[i+1];
        }
    }
    return temp;
}
double min(){
    double temp =arr[0];
    for(int i=0; i<15; i++){
        if(temp >arr[i]){
            temp = arr[i];
        }
    }
    return temp;
}
int count_max(){
    double temp =arr[0];
    int count=0;
    for(int i=0; i<15; i++){
        if(temp <arr[i+1]){
            temp = arr[i+1];
        }
    }
    for(int i=0; i<15; i++){
        if(arr[i] == temp){
            count++;
        }
    }
    return count;
}
int main(){
    printf("total: %lf\n",total());
    printf("Average: %lf\n",average());
    printf("MAX: %lf\n",max());
    printf("Min: %lf\n",min());
    printf("Max numbers: %d",count_max());
    return 0;

}