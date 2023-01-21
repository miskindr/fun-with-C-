#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// use this function to pass in the filename to open file and display txt in file.
void readFromFile(string fileName)
{
    ifstream file;
    file.open(fileName, ios::in);
    if (file.is_open())
    {
        //set a string variable to store txt in file
        string line;
        // stores data from the text in line
        while (getline(file, line)) 
        {
            //display the line of text
            cout << line << endl;
        }
    }
    // Dont forget to close the file
    file.close();
}

int main()
{   
    //prepare file
    fstream file;
    //global variables that I will be using in main
    string file_name, text;
    char ch;
    int wordCount = 1;
   
    //Intro txt
    cout<<"Welcome to file creater where you can create, write, and read to a file.\n";
    cout<<"\n";

   
    cout << "First off what would you like your file to say:\n";
    //store text string of the input to the file.
    cin >> text;


    cout<<"Now what would you like the name of you file to be (make sure to add [.txt] to the end of file name):\n";
    //Store the file name in a string variable
    cin >> file_name;


    //open file
    file.open(file_name, ios::app);
    file << text<< endl;
    file.close();

    
    //error message for no file created
    if(!file)
    {
        cout<<"Error in creating file!!!";
        return 0;
    }

    //notify that the file was created
    cout<<"File created successfully."<<endl;
    
    //calculate the word count
    while (getline (file, text)) {
        // I want the loop to go through the text character by character and when htere is a space add one to the word count
        if (text == " "){
            wordCount++;
        }
    }
    //Display the word count
    cout << wordCount<<endl;
    
    //call the read file function and pass the filename sting so it can open the file
    readFromFile(file_name);

    //Just some math using the math class
    cout << "Some quick math "<< sqrt(49);

    
    return 0;
}