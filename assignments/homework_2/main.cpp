/**
 * File: main.cpp
 * Aurhor: Kevin McNeil Jr
 * Course: CMPS 1063 - Fall 2019
 * Date: 10/8/2019
 * Description:
 *    Struct implementation file for our array based stack of ints read from input.
 */

#include <iostream>
#include <fstream>

using namespace std;

struct Stack{
    int *A;
    int Top;
    int Size;

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
    Stack(){
        Size = 10;
        A = new int [Size];
        Top = 0;
    }

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
    Stack(int s){
        Size = s;
        A = new int [Size];
        Top = 0;
    }

/**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
    bool Push(int val){
        if(!Full()){
            A[Top] = val;
            Top++;
            A[Top] = 0;
            return true;
        }else{
            return false;
        }
}

/**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    void
 * Returns:
 *     int : item on stack
 */
    int Pop(){
        if(!Empty()){
            int temp = 0;   
            temp = A[Top];
            Top--;
            return temp;
        }else{
            // should return a value that implies failure, but good enough for now
            cout<<"Cannot remove item from empty stack"<<endl;
        }
  return 0;
}

/**
 * Print
 * Description:
 *    Prints stack for inspection
 * Params:
 *    void
 * Returns:
 *     void
 */
    void Print(int maxSize){
        ofstream fout;
        fout.open("output.dat");
        
        fout << "Kevin McNeil Jr." << endl;
        fout << "10/8/2019" << endl;
        fout << "Program 2\n\n\n";
        
        fout << "Stack Size: " << Top << endl;
        fout << "Largest Size: " << maxSize << endl;
        for(int i = Top; i >= 0 ; i--){
            fout << A[i] << " ";
        } 
    }

/**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
    bool Empty(){
        return Top < 0;
    }

/**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
    bool Full(){
        return (Top == Size);
    }
/**
 * Full
 * Description:
 *    Checks if stack is 80% full or 20% full
 * Params:
 *    double
 * Returns:
 *    top if true
 */
    double checkResize(){
        double cEnlarge = .8 * (double)Size;
        double cReduce = .2 * (double)Size;
        
        if(Top >= cEnlarge){
            return Top;
        }else if(Top <= cReduce){
            return Top;
        }
        return false;
    }
/**
 * Full
 * Description:
 *    enlarges stack
 * Params:
 *    void
 * Returns:
 *    enlarged stack with new size and old data
 */
    void Enlarge(){
        if(checkResize() >= .8 * (double)Size){
            int nSize = Size * 1.5;
            int *A2 = new int [nSize];
            for( int i = 0; i < Size; i++){
                A2[i] = A[i];
            }
            int *tempDel = A;
            Size = nSize;
            A = A2;
            delete[] tempDel;
        }
    }
/**
 * Full
 * Description:
 *    reduces stack 
 * Params:
 *    void
 * Returns:
 *    reduced stack with new size and old data
 */
    void Reduce(){
        if(checkResize() <= .2 * (double)Size){
            int nSize = Size * .5;
            int *A2 = new int [nSize];
            for( int i = 0; i < Size; i++){
                A2[i] = A[i];
            }
            int *tempDel = A;
            Size = nSize;
            A = A2;
            delete[] tempDel;
        }
    }
};

int main(){
    Stack s(10);
    
    int maxLength = 0;
    char input = ' ';
    int data = 0;

    ifstream fin;
    fin.open("input_data.txt");

    while(!fin.eof()){
        fin >> input;
        fin >> data;

        if(input == '+'){
            s.Push(data);
            s.Enlarge();
            if(maxLength < s.Size){
                maxLength = s.Size;
            }
        }else if(input == '-'){
            s.Pop();
            s.Reduce();
        }
    }
    s.Print(maxLength);
    return 0;
}
