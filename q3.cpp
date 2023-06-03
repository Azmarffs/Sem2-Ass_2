/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
#include<string.h>

using namespace std;

class String {
    char* data;
    int size;
public:
    String() {}; //default constructor
    String(int length) { //parametrized constructor 1
        size = length;
        data = new char[size + 1];
        data[0] = '\0';
    }
    String(const char* str) { //parametrized constructor 2
        size = strlen(str);
        data = new char[size + 1];
        for (int i = 0; i <= size; i++) {
            data[i] = str[i];
        }
    }
    String(const String& str) { //copy constructor
        size = str.size;
        data = new char[size + 1];
        for (int i = 0; i <= size; i++) {
            data[i] = str.data[i];
        }
    }
    ~String() { //destructor
        delete[] data;
    }
    int stringLength() {
        int lenForData = 0;
        while (data[lenForData] != '\0') { //loop till it reaches the null character of Data
            lenForData++;
        }
        return lenForData; //returning the length of string
    }
    void clear() {
        delete[] data; //deleting the content in data
        size = 0;
        data = new char[1];
        data[0] = '\0';
    }
    bool isEmpty() {
        if (data[0] == '\0') { //checking if data is empty
            return true;
        }
        else {
            return false;
        }
    }
    int charAt(char c) {
        int lenForData = 0;
        while (data[lenForData] != '\0') { //calculating the length of data
            lenForData++;
        }
        for (int i = 0; i < lenForData; i++) {
            if (data[i] == c) { //checking if it gets equal to c
                return i; // we return it
            }
        }
        return -1; //else we return -1
    }
    char* getdata() {
        return data;
    }
    bool isEqual(const char* str) {
        int LenForStr = 0;
        while (str[LenForStr] != '\0') { //calculating size of str
            LenForStr++;
        }
        if (LenForStr == size) { //checking if it's equal to size
            return true;
        }
        else {
            return false;
        }
        int i = 0;
        while (i != size) { //loops continues till it gets equal to size
            if (data[i] != str[i]) { //checking if data string is equal to str
                return false;
            }
            i++;
        }
        return true;
    }
    bool equalsIgnoreCase(char* str){
    int LenforStr = 0;
    while(str[LenforStr] != '\0'){ //calculating size for str
        LenforStr++;
    }
    int LenforData = 0;
    while(data[LenforData] != '\0'){ //calculating size for data
        LenforData++;
    }
    if(LenforStr != LenforData){ //if both are not equal in length we return false
        return false;
    } else {
        for(int i = 0; i < LenforStr; i++){ 
            /*
            here we store both characters in variables
            */
            char forStr = str[i]; 
            char forData = data[i];
            if(forStr != forData){ //now we check if the characters for both are not equal then
                if((forStr >= 'A' && forStr <= 'Z' && forStr + 32 == forData) || (forStr >= 'a' && forStr <= 'z' && forStr - 32 == forData)){ //we check for upper and lower case
                    continue; //if they are upper case then we ignore and move to the next character
                }
                return false;
            }
        }
    }
    return true;
    }
    char* substring(char* substr, int startIndex){
        int lenForData = 0;
        while(data[lenForData] != '\0'){ //calculating len for data
            lenForData++;
        }
        int LenForSubstr = 0;
        while(substr[LenForSubstr] != '\0'){ //calculating len for substr
            LenForSubstr++;
        }
        char* val = ""; //making a string arr of type char
        bool IfEqual = true; //setting bool equal to true
        for(int i = startIndex; i < lenForData; i++){
            IfEqual = true; //resetting the bool value to true for each new substring
            for(int j = 0; j < LenForSubstr; j++){
                if(data[i + j] != substr[j]){ //searching for the substring in the original string
                    IfEqual = false; //if not found, set bool to false and break out of inner loop
                    break;
                }
            }
            if(IfEqual){ //if bool value remains true after the inner loop, the substring is found
                val = &data[i]; //store the substring along with its characters till the end
                break; 
            }
        }
        return val; //and returning it
    }
    char* substring(char* substr, int startIndex, int endIndex){
        int lenForData = 0;
        while(data[lenForData] != '\0'){ //calculating size of data
            lenForData++;
        }
        int LenForSubstr = 0;
        while(substr[LenForSubstr] != '\0'){ //calculating size of substr
            LenForSubstr++;
        }
        char* val = "";
        bool IfEqual = true;
        for(int i=startIndex;i<endIndex;i++){
            for(int j=0;j<LenForSubstr;j++){
                if(data[i+j] != substr[j]){  //searching for the substring in the original string
                    IfEqual = false; //if found then we change bool to false
                    break;
                }
            }
            if(IfEqual){
                val = &data[i]; //we store the substring along with its characters till ending index
                break;
            } else {
                IfEqual = true; // reset the IfEqual flag for the next iteration
            }
        }
        return val;
    }

    void print(){
        if(size == 0){ //if size is null we display null
            cout << "NULL";
        }else{ //else we return data
            cout << data;
        }
    }
};
int main() {
    // using default constructor
    String s1; // s1 is an empty string

    // using parameterized constructor 1
    String s2(5); // s2 is a string of length 5

    // using parameterized constructor 2
    String s3("Hello"); // s3 is a string initialized with "Hello"

    // using copy constructor
    String s4 = s3; // s4 is a copy of s3

    // using stringLength function
    int len = s3.stringLength();
    cout << "Length of s3 is: " << len << endl;

    // using clear function
    s3.clear();
    cout << "s3 after clear function: " << s3.getdata() << endl;

    // using isEmpty function
    if (s3.isEmpty()) {
        cout << "s3 is empty" << endl;
    }
    else {
        cout << "s3 is not empty" << endl;
    }

    // using charAt function
    int index = s4.charAt('o');
    if (index != -1) {
        cout << "Index of 'o' in s4 is: " << index << endl;
    }
    else {
        cout << "o not found in s4" << endl;
    }

    // using isEqual function
    if (s4.isEqual("Hello")) {
        cout << "s4 is equal to 'Hello'" << endl;
    }
    else {
        cout << "s4 is not equal to 'Hello'" << endl;
    }

    // using equalsIgnoreCase function
    if (s4.equalsIgnoreCase("heLLo")) {
        cout << "s4 is equal to 'heLLo' (ignoring case)" << endl;
    }
    else {
        cout << "s4 is not equal to 'heLLo' (ignoring case)" << endl;
    }

    // using substring function
    char* substr = new char[3];
    substr = s4.substring("el", 1);
    cout << "Substring of s4 starting from index 1 and containing 'el': " << substr << endl;

    return 0;
}
