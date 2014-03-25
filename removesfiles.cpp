
//Program to remove comments from .cpp file. Tons of room for improvement, this was a quick that that I didn't
// even bother using string members to do.
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdio>

using namespace std;

string removeCommentsA(string fileString); //remove comments
void createOutputFile(string remString, string name);

int main()
{
string fileName;
string stringHolder;
string removedText;
char charHolder;

ifstream textFile;

int counter = 0;
int i = 0;

cout << "Enter name of file: " <<endl;

cin >> fileName;

 textFile.open(fileName.data());

     if(textFile.is_open()){

        while(!(textFile.eof())){

            charHolder = textFile.get();
            stringHolder.insert(i,1,charHolder);
            i++;
        }
        textFile.close();
        
        removedText = removeCommentsA(stringHolder);
        createOutputFile(removedText, fileName);
    }

    else {
        cout << "Error. Invalid file name. Terminating." << endl;
    }
//Function to remove comments
//By Colin O'Brien
//March 19th 2014
    return 0;
}

string removeCommentsA(string fileString){
    
    int charCounter = 0;
    char current; 
    int tempCounter = 0;
    
    int stringSize = fileString.size(); //avoid calling .size() a bunch
    
    for(charCounter; charCounter <= stringSize; charCounter++){

        current = fileString[charCounter];
        
    
        if(current == '/'){
            tempCounter = charCounter;
            
            if(fileString[tempCounter+1] == '/'){ //This is for single line comments  -- Working

            while(fileString[tempCounter] != '\n'){
                fileString[tempCounter] = ' '; 
                tempCounter++;
              
                }
            
            tempCounter = 0;
            } //end while loop
            
            
            
            
                        //This is for block comments    

            else if(fileString[tempCounter+1] == '*'){ //At this point we know it's a block comment tC = / tC+1 = *

              fileString[tempCounter] = ' '; fileString[tempCounter + 1] = ' ';// originally backspace

                while(!((fileString[tempCounter] == '*') && (fileString[tempCounter+1] == '/'))){//check for end of block
                    
                fileString[tempCounter] = ' ';// originally backspace
                tempCounter++; 
                    
                }
                //Remove the */
             fileString[tempCounter] = ' '; fileString[tempCounter + 1] = ' ';// originally backspace

            tempCounter = 0;
            }
            
            
        }//end of first if statement


    }// end of for loop
    
    fileString.erase(fileString.size() - 1); //remove redundant EOF
    
  // cout << fileString; //for testing
   
return fileString;
}

//Function to create the ouput file with comments removed

void createOutputFile(string remString, string name){ //TODO - Validate file does not exist already.
    
    string newFileName = "new" + name;

    ofstream outputFile (newFileName.c_str());
    

     if(outputFile.is_open()){
    
     outputFile << remString;
    
     outputFile.close();
    
     }
     
     else if(!(outputFile.is_open())){
         cout << "File is not open.\nTerminating." << endl;
     }
     
     else{
         cout << "Unknown error. Terminating." << endl;
     }
    
}






