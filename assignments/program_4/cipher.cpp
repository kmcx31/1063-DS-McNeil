///////////////////////////////////////////////////////////////////////////////
//
// Author:           KEVIN MCNEIL JR.
// Assignment:       Program_04
// Date:             8 DECEMBER 2019
// Title:            Program 4 - CIPHER
// Semester:         Spring 2018
// Course:           CMPS 1063 
// 
// Files:            cipher.cpp, 
//                   encrypted.txt, 
//                   decrypted.txt 
//       
// Description:
//       The purpose of this program is to decrypt given strings and output the result.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//have global access to opened files to modify
ifstream fin("encrypted.txt");
ofstream fout("decrypted.txt");

//class for cipher
class CaesarCipher{
    private:
        string e = " ";     //encrypted message
        string d = " ";     //decrypted message
        int shift = 13;     //shift, default value is 13

    public:
        /**
        * Encrypt
        * 
        * Description:
        *      Encrypts a given message.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      String of encrypted message.
        */
        string Encrypt(){                               //encrypt method
            int val = 0;                                     
            string text = d;
            for(int i = 0; i < text.length(); i++){     //for loop to loop thru string
                if(text[i] >= 65 && text[i] <= 90){     //if the letter is a capital letter
                    val = (int)text[i] - 65;            //subtract 65 from ascii value, making it a numerical value
                    val += shift % 26;                  //wrap around if needed 
                    text[i] = val + 65;                 //add 65 to make it a letter again
                }
            }
            e = text;
            return e;
        }

        /**
        * Decrypt
        * 
        * Description:
        *      Decrypts a given message.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      String of Decrypted message.
        */
        string Decrypt(){
            int val = 0;                                //decrypt method
            string text = e;                            
            for(int i = 0; i < text.length(); i++){     //for loop to loop thru string
                if(text[i] >= 65 && text[i] <= 90){     
                    val = (int)text[i] - 65;            //make numerical value
                    val =  val - shift;                 //subtract shift to find new letter
                    if(val < 0){                        //if you get a negative number
                        val = val + 26;                 //add 26 to get a letter
                    }
                    val = val % 26;                    
                    text[i] = val + 65;
                }
            }
            cout << text << endl;
            d = text;
            return d;
        }

        /**
        * Uppercase
        * 
        * Description:
        *      Sets a message to all uppercase letters.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      String of uppercase message.
        */
        string UpperCase(){
            for(int i = 0; i < d.length(); i++){        //loop thru string
                if(d[i] >= 97 || d[i] <= 122){          //if ascii value != uppercase letter
                    d[i] = d[i] - 32;                   //make it uppercase
                }
            }
            return d;
        }

        /**
        * SetShift
        * 
        * Description:
        *      Sets a shift from file.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      None
        */
        void SetShift(){
            fin >> shift;                               //set shift according to file
        }

        /**
        * ReadCipherText
        * 
        * Description:
        *      Reads in new message to be decoded.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      String of encrypted message.
        */
        string ReadCipherText(){
            SetShift();                                 //call setshift
            getline(fin, e);                            //getline reads to get to the new line with the text
            getline(fin, e);                            //getline reads actually reads the text
            //cout << d << endl;
            return e;
        }
        
        /**
        * WriteCipherText
        * 
        * Description:
        *      Write out encrypted message.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      None
        */
        void WriteCipherText(){
            fout << e << endl;                           //write out encrypted message
        }

        /**
        * ReadPlainText
        * 
        * Description:
        *      Read in a encrypted message.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      String of encrypted message.
        */
        string ReadPlainText(){
            getline(fin, e);                             //read in to get to message
            getline(fin, e);                             //actually read the message
            UpperCase();                                 //make message uppercase
            return e;   
        }

        /**
        * WritePlainText
        * 
        * Description:
        *      Writes a decoded message.
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      None
        */
        void WritePlainText(){
            fout << d << endl;                            //write out decrypted message
        }

};

int main(){
    int c = 0;                                             //counter 
    fin >> c;                                              //read in counter

    for(int i = 0; i < c; i++){                            //loop thru until we reach the counter
        CaesarCipher CC;                                   //create a new cc everytime so we get a fresh message every loop
        CC.ReadCipherText();                               //call methods
        CC.Decrypt();
        CC.WritePlainText();
    }
    return 0;
}