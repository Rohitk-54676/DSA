#include<iostream>
using namespace std;
class stack{
    private:
    int *arr;
    int size;
    int top;
    public:
    stack(int n){
        size=n;
        top=-1;
        arr=new int[size];
    }
    void push(int n){
        if(top==size-1){
            cout<<"stack Overflow\n";
            return;
        }else{
            top++;
            arr[top]=n;
            cout<<n<<" Successfully Push\n";
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow\n";
            return;
        }else{
            top--;
        }
        cout<<arr[top+1]<<" Successfully Push\n";
    }
    int peek(){
        if(top==-1){
            cout<<"Stack Underflow\n";
            return -1;
        }else{
        return arr[top];
        }
    }
    bool IsEmpty(){
        return top==-1;
    }
    int IsSize(){
        return top+1;
    }

};
int main(){
    cout<<"Enter the size of stack"<<endl;
    int a;
    cin>>a;
    stack s(a);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();
    cout<<s.IsEmpty()<<endl;
    cout<<s.IsSize()<<endl;
    cout<<s.peek()<<endl;
    return 0;
}