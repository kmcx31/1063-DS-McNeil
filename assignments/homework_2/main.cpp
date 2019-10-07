#include <iostream>
#include <fstream>

using namespace std;

class Stack{
private:

public:
    int *A;
    int top;
    int Size;
    int data;
    char direction;

    Stack(){
        Size = 10;
        A = new int [Size];
        top = 0;
        data = 0;
        direction = ' ';
    }

    Stack(int s){
        Size = s;
        A = new int [Size];
        top = 0;
        data = 0;
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
};



int main(){
    Stack S[10];

    ifstream fin;
    fin.open("input_data.txt");
    
    int count = 0;

    while(!fin.eof()){
        fin >> S[count].direction;
        fin >> S[count].data;
        S.top;
        
        if(S[count].direction == '-'){
            delete S[count].direction;
            delete S[count].data;
        }



        cout << S[count].direction;
        cout << S[count].data << endl;
        S.top--;
        count++;
    }  


return 0;
}