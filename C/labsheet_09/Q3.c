#include <stdio.h>
struct household{
    int id_num;
    int income;
    int No_members; 
};

int main(){
    struct household house[5] = {{3210, 190, 6 },{9280 ,250 ,2 },{3600 ,290 ,5 },{4725 ,590 ,3 },{6217 ,600 ,2 }};
    FILE *file = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\labsheet_09\\readme.txt","w");
    if(file==NULL){
        perror("Error");
        return 1;
    }
    fprintf(file,"ID Number     Anual income       Number of Members\n");
    for(int i=0; i<5; i++){
        fprintf(file,"%d \t\t\t\t\t%d \t\t\t\t\t%d \n",house[i].id_num,house[i].income,house[i].No_members);
    }
    fclose(file);
    printf("Successfully written to the file\n");

    FILE *file2 = fopen("C:\\Users\\PR\\OneDrive\\Documents\\C and DSA\\C\\labsheet_09\\readme.txt","r");
    if(file2 == NULL){
        perror("Error");
        return 1;
    }
    int num = 0;
    printf("ID number     Annual Income      No of Members\n");
    while(fscanf(file2,"%d %d %d",&house[num].id_num,&house[num].income,&house[num].No_members) != EOF){
        printf("%d \t\t%d \t\t%d\n",house[num].id_num,house[num].income,house[num].No_members);
        num++;
    }
    fclose(file2);
    return 0;
}