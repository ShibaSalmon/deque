// 做一個「雙入雙出」的queue(using struct)

// 指令：

// push()：從後面塞一個元素進去
// pop()：將最後面的元素移除，並印出來
// unshift()：從前面塞一個元素進去
// shift()：將最前面的元素移除，並印出來
// clear()：清空所有元素
// print()：印出所有元素
// ---------------
// reverse()：由前到後反轉所有元素
// sort()：由小到大排序所有元素

#include <iostream>
#include <cstring>
using namespace std;

void push(int);
void pop(void);
void unshift(int);
void shift(void);
void clear(void);
void print(void);
void reverse(void);
void sort(void);

struct node{
    int data;
    struct node *next;
    struct node *previous;
};
typedef struct node Node;
Node *first = NULL;
Node *last = NULL;

int main(void){

    char command[10];
    int num;

    while(cin >> command){
        
        if(strcmp("push", command) == 0){
            cin >> num;
            push(num);
        }
        else if(strcmp("pop", command) == 0){
            pop();
        }
        else if(strcmp("unshift", command) == 0){
            cin >> num;
            unshift(num);
        }
        else if(strcmp("shift", command) == 0){
            shift();
        }
        else if(strcmp("clear", command) == 0){
            clear();
        }
        else if(strcmp("print", command) == 0){
            print();
        }
        else if(strcmp("reverse", command) == 0){
            reverse();
        }
        else if(strcmp("sort", command) == 0){
            sort();
        }
        else{
            cout << "Error! Please Input Again!\n" << endl;
        }
    }
    return 0;

}

void push(int num){
    
    if(last == NULL){
        first = last = new Node;
        last->previous = last->next = NULL;
        last->data = num;
    }
    else{
        Node *newNode = new Node;
        newNode->next = NULL;
        newNode->previous = last;
        last->next = newNode;
        last = newNode;
        last->data = num;
    }
}

void pop(){
    
    if(last == NULL){
        
        cout << "empty!" << endl;
    }
    else{
        
        cout << last->data << endl;
        if(last->previous == NULL){
            delete last;
            first = last = NULL;
            
        }
        else{
            Node *tmp = last->previous;
            tmp->next = NULL;
            delete last;
            last = tmp;
        }
    }
}

void unshift(int num){

    if(first == NULL){
        first = last = new Node;
        first->previous = first->next = NULL;
        last->data = num;
    }
    else{
        Node *newNode = new Node;
        newNode->previous = NULL;
        newNode->next = first;
        first->previous = newNode;
        first = newNode;
        first->data = num;
    }
}

void shift(){
    if(first == NULL){
        
        cout << "empty!" << endl;
    }
    else{
        
        cout << first->data << endl;
        if(first->next == NULL){
            delete first;
            first = last = NULL;
        }
        else{
            Node *tmp = first->next;
            tmp->previous = NULL;
            delete first;
            first = tmp;
        }
    }
}

void clear(){
    
    while(first != NULL){
        if(first->next == NULL){
            delete first;
            first = last = NULL;
        }
        else{
            Node *tmp = first->next;
            tmp->previous = NULL;
            delete first;
            first = tmp;
        }
    }
}

void print(){

    if(first == NULL){
        cout << "empty!" << endl;
    }
    else{
        Node *tmp = first;
        while(tmp != NULL){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

void reverse(){

    Node *tmp = first;
    Node *swap;
    while(tmp != NULL){
        swap = tmp->next;
        tmp->next = tmp->previous;
        tmp->previous = swap;
        tmp = swap;
    }
    swap = last;
    last = first;
    first = swap;
}

void sort(){
    
    Node *tmp1 = last;
    Node *tmp2;
    int swap;
    while(tmp1 != first){
        tmp2 = first;
        while(tmp2 != tmp1){
            if(tmp2->data > tmp2->next->data){
                swap = tmp2->data;
                tmp2->data = tmp2->next->data;
                tmp2->next->data = swap;
            }
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->previous;
    }
}