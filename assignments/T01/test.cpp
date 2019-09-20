//Kevin McNeil Jr.
#include <iostream>
#include <cmath>


using namespace std;


//1.
int sumArrays(int A[], int B[], int C[], int size){
    int sum;
    for(int i = 0; i < size; i++){
        sum += A[i];
        sum += B[i];
        sum += C[i];
    }
    return sum;
}

//2.
double avg2D(int A[5][5], int size){
    double avg, sum;
    for(int i = 0; i < size; i++){
        for(int n = 0; n < size; n++){
            sum += A[i][n];
        }
    }
    avg = sum / (double)size;
    return avg;
}

//3.
void printX(int size){
    for(int i = 0; i < size; i++){
        if(i == 0){
            cout << "X" << endl;
        }else if(i == 1){
            cout << "XX" << endl;
        }else if(i == 2){
            cout << "XXXX" << endl;
        }else if(i == 3){
            cout << "XXXXXXXX" << endl;
        }else if(i == 4){
            cout << "XXXXXXXXXXXXXXXX" << endl;
        }else if(i == 5){
            cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
        }
    }
}

//4.
struct Stats1{
   int min;
   int max;
   double avg;
   int sum;  
};

Stats1 aggregateVals(double A[], int size){
  Stats1 info;
  double sum = 0;
  info.min = A[0];
  info.max = A[0];
  info.avg = 0.0;

  for(int i=0;i<size;i++){
    if(A[i] < info.min){
      info.min = A[i];
    }
    if(A[i] > info.max){
      info.max = A[i];
    }
    sum += A[i];
  }

  info.avg = sum / size;

  return info;

}

//5.
struct Stats2{
    int min;
    int max;
    double avg;
    int sum;

    Stats2(){
        min = 0;
        max = 0;
        avg = 0.0;
    }
};

//6.
double calcStdDev(double A[], int size){
    double sum, mean, squareRoot,subtractM[size];
    for(int i = 0; i < size; i++){
        sum += A[i];
    }
    mean = sum / (double)size;
    for(int j = 0; j < size; j++){
        subtractM[j] = A[j] - mean;
        subtractM[j] *= subtractM[j];
    }
    for(int n = 0; n < size; n++){
        sum += subtractM[n];
    }
    mean = sum / (double)size;
    squareRoot = sqrt(mean);
    return squareRoot;
}

//7.
int initIntArray(int size){
    int *temp = new int[size];
    for(int i = 0; i < size; i++){
        temp[i] = 0;
    }
    return *temp;
}


int main(){
    
   // printX(4);
   // printX(6);

   // initIntArray(5);

    return 0;
}