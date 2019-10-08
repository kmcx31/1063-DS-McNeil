#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack{
private:
    

public:
    int *A;
    int top;
    int Size;

    Stack(){
        Size = 10;
        A = new int [Size];
        top = 0;
    }

    Stack(int s){
        Size = s;
        A = new int [Size];
        top = 0;
    }

    bool checkResize(){
        if(top >= .8 * Size){
            return true;
        }else if(top <= .2 * Size){
            return true;
        }
        return false;
    }

    void Enlarge(){
        if(checkResize()){
            int new_size = Size * 1.5;
            int *A2 = new int[new_size];
            for(int i = 0; i < new_size ;i++){
                A2[i] = A[i];
            }
            int *temp = A;
            A = A2;
            delete[] temp;
        }
    }
    
    void Reduce(){
        if(checkResize() && Size > 10){
            int new_size = Size * .5;
            int *A2 = new int[new_size];
            for(int i = 0; i < new_size ;i++){
                A2[i] = A[i];
            }
            int *temp = A;
            A = A2;
            delete[] temp;
        }
    }
    
    void push(int val){
        A[top] = val;
        top++;
    }

    int pop(){
        int temp = A[top];
        top--;
        return temp;
    }

    void Print(){
        for(int i = top; i>=0; i--){
        cout << A[i] << endl;
  }
}
};



int main(){
    Stack Array(10);

    //cout << "This is the current size: " << Array.Size;
    ifstream fin;
    fin.open("input_data.txt");
    
    while(!fin.eof()){
        char direction = ' ';
        int i = 0;
        fin >> direction;
        fin >> i;
        if(direction == '+'){
            Array.push(i);
            cout << i << endl;
            Array.Enlarge();
            cout << "This is the current size: " << Array.Size << endl;
        }else{
            Array.pop();
            Array.Reduce();
            cout << "This is the current size: " << Array.Size << endl;
        }
    }
    cout << "This is the final Array size " << Array.Size;
    Array.Print();
return 0;
}