#include <iostream>
#include <fstream>

using namespace std;

class Stack{
private:
    

public:
    int *A;
    int top;
    int data;
    int Size;
    char direction;

    Stack(){
        data = 0;
        Size = 10;
        A = new int [Size];
        top = 0;
        direction = ' ';
    }

    Stack(int s){
        int data = 0;
        Size = s;
        A = new int [Size];
        top = 0;
        direction = ' ';
    }

    bool checkResize(Stack s, int size){
        return size;
    }

    Stack Enlarge(Stack s){
        return s;
    }
    
    Stack Reduce(Stack s){
        return s;
    }

    int popI(){
        int temp = A[top];
        A[top]--;
        return temp;
    }

    char popC(){
        char temp = A[top];
        return temp;
    }

    void print(){
        for(int i = top; i >= 0; i--){
            cout << A[direction] << " " << A[top] << endl;
        }
    }
};



int main(){
    Stack Array;

    ifstream fin;
    fin.open("input_data.txt");
    
    int i = 0;
    while(!fin.eof()){
        fin >> Array.direction;
        fin >> Array.top;
        
        //cout << Array.direction << " " << Array.top << endl;
        Array.top++;
        i++;
    }

    Array.print();

    /*for(int i = Array.top; i >= 0; i--){
        if(Array.direction == '-'){
            Array.popC();
            Array.popI();
            cout << Array.direction << " " << Array.top << endl; 
        }
    }*/

return 0;
}