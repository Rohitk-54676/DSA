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
void LinearSearch(int arr[],int n,int num){
    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            index=i+1;
            break;
        }
    }
    if(index==-1){
        printf("\n Not Found \n");
    }else{
        printf("Found at position %d",index);
    }
}
void BinarySearch(int arr[],int n,int num){
    int index=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==num){
            index=mid+1;
            break;
        }
        if(arr[mid]>num){
            high=mid-1;
        }
        if(arr[mid]<num){
            low=mid+1;
        }
    }
    if(index==-1){
        printf("\n Not Found \n");
    }else{
        printf("Found at position %d",index);
    }
}
int main(){
    printf("Enter no of element in array");
    int a;
    scanf("%d",&a);
    int arr[a];
    int arr1[a];
    for(int i=0;i<a;i++){
        printf("Now enter elemets %d ",i+1);
        scanf("%d",&arr[i]);
        arr1[i]=arr[i];
    }
    Display(arr,a);
    BubbleSort(arr,a);
    InsertionSort(arr,a);
    SelectionSort(arr,a);
    int find;
    printf("Enter the element to find");
    scanf("%d",&find);
    LinearSearch(arr1,a,find);
    BinarySearch(arr,a,find);

}
