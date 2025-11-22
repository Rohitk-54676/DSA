#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class stack{
    private:
    Node* top;
    int size;
    public:
    stack(){
        top=NULL;
        size=0;
    }
    void push(int n){
        Node* temp=new Node(n);
        if(temp==NULL){
            cout<<"stack overflow"<<endl;
        }else{
            temp->next=top;
            top=temp;
            size++;
            cout<<n<<" pushed"<<endl;
        }     
    }
    void pop(){
        if(top==NULL){
            cout<<"stack underflow"<<endl;
        }else{
            Node* temp=top;
            cout<<top->data<<" Poped"<<endl;
            top=top->next;
            delete temp;
            size--;
        }
    }
    bool IsEmpty(){
        return size==0;
    }
    int Peek(){
        return top->data;
    }
    int IsSize(){
        return size;
    }
};

int main(){
    stack s;
    s.push(5);
    s.push(6);
    s.push(9);
    cout<<s.IsEmpty()<<endl;
    cout<<s.Peek()<<endl;
    cout<<s.IsSize()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}