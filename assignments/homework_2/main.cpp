#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack{
private:
    

public:
    int *A;
    int top;
    int data;
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

    bool checkResize(double size, int top){
		if(top >= .8 * size){
            return true;
        }else if(top <= .2 * size){
            return true;
        }else{
            return false;
        }
        
    }

    void Enlarge(){
        int new_size = Size * 1.5; 
		int *A2 = new int[new_size]; 
		for (int i = 0; i < Size; i++){
			A2[i] = A[i];
		}
		int *temp = A;
		A = A2;
		delete[] temp;
    }
    
    void Reduce(){
        int new_size = Size * .5; 
		int *A2 = new int[new_size]; 
		for (int i = 0; i < Size; i++){
			A2[i] = A[i];
		}
		int *temp = A;
		A = A2;
		delete[] temp;
    }
    
    bool Empty(){
        return top < 0;
    }

    bool Full(){
        return (top == Size);
        }

    bool Push(int val){
        if(!Full()){
            A[top] = val;
            top++;
            return true;
        }else{
            return false;
        }
    }

    int Pop(){
        if(!Empty()){
            int temp = 0;   
            temp = A[top];
            temp--;
            return temp;
        }else{
            cout << "Cannot remove item from empty stack" << endl;
        }
        return 0;
    }

    void Print(int bigSize){
        ofstream outfile; 
        outfile.open ("output.dat");

        outfile << "Kevin McNeil Jr." << endl;
        outfile << "10/7/19" << endl;
        outfile << "Homework 2" << endl << endl << endl;

        outfile << "Final size: " << Size << endl;
        outfile << "Biggest size: " << bigSize << endl;
        outfile << "Values: ";
        for (int i = top; i >= 0; i--){
            outfile << A[i] << " ";
        }
    }

};


int main(){
    char direction = ' ';
    int data = 0;
    int bigSize = 10;

    Stack Array(10);

    ifstream fin;
    fin.open("input_data.txt");
    while(!fin.eof()){
        

        fin >> direction;
        fin >> data;


        if(direction == '+'){
            Array.Push(data);
        }else{
            Array.Pop();
        }


        if(Array.checkResize(Array.Size, Array.top)){
            Array.Enlarge();
            if(bigSize < Array.Size){
                bigSize = Array.Size;
                }
        }else{
            if(Array.checkResize(Array.Size, Array.top)){
                Array.Reduce();
                }    
        } 
    }
    Array.Print(bigSize);
    return 0;
}
