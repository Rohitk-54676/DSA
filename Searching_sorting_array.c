#include<stdio.h>
void Display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void BubbleSort(int arr[],int a){
    for(int i=0;i<a;i++){
        for(int j=0;j<a-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Bubble Sort \n");
    for(int i=0;i<a;i++){
        printf("%d ",arr[i]);
    }
}
void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("\n Insertion Sort \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void SelectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        if(minindex!=i){
            int temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
        }
    }
    printf("selection Sort \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    printf("Enter no of element in array");
    int a;
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
        printf("Now enter elemets %d ",i+1);
        scanf("%d",&arr[i]);
    }
    Display(arr,a);
    BubbleSort(arr,a);
    InsertionSort(arr,a);
    SelectionSort(arr,a);
}
