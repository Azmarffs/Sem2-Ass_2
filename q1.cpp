/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
using namespace std;

struct Pixel{ 
    int red;
    int green;
    int blue;
};

class Image{
    int row;
    int col;
    int depth;
    Pixel*** image;

public:
    Image(int d=1, int r=1, int c=1){
        row = r;
        col = c;
        depth = d;
        image = new Pixel**[row]; //2D dynamic array
        for(int i=0;i<row;i++){
            image[i] = new Pixel*[col];
            for(int j=0;j<col;j++){
                image[i][j] = new Pixel[depth];
                for(int k=0;k<depth;k++){
                    image[i][j][k] = Pixel();
                }
            }
        }
    }

    Image(const Image& img){ //copy constructor
        row = img.row;
        col = img.col;
        depth = img.depth;
        image = new Pixel**[row];
        for(int i=0;i<row;i++){
            image[i] = new Pixel*[col];
            for(int j=0;j<col;j++){
                image[i][j] = new Pixel[depth];
                for(int k=0;k<depth;k++)
                    image[i][j][k] = img.image[i][j][k];
            }
        }
    }

    ~Image(){ //destructor
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                delete[] image[i][j];
            }
            delete[] image[i];
        }
        delete[] image;
    }

    int getRow(){
        return row;
    }

    int getCol(){
        return col;
    }

    int getDepth(){
        return depth;
    }

    Pixel getPixel(int x, int y, int z){
        return image[x][y][z]; // returning pixel at specific coordinates x, y ,z
    }

    void setPixel(int x, int y, int z, Pixel p){
        image[x][y][z] = p; //setting image equal to pixel
    }

    void fill(Pixel p){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                for(int k=0;k<depth;k++){
                    image[i][j][k] = p; //flling the entire image with pixel
                }
            }
        }
    }

    void clear(){ //clearing the imgae
        fill(Pixel());
    }

    double getAverageBrightness(){
        double avg = 0;
        int forTotalPixels = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                for(int k=0;k<depth;k++){
                    avg += (image[i][j][k].red + image[i][j][k].green + image[i][j][k].blue)/3.0; //we add all the element colors of the image and div by total number to get avg
                    forTotalPixels++; //to get the number for total pixels
                }
            }
        }
        avg = avg/forTotalPixels;
        return avg;
    }
    int getMaximumBrightness(int depth) {
    int maxBrightness = 0; // setting initial brightness to 0
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int temp = image[i][j][depth].red + image[i][j][depth].green + image[i][j][depth].blue; // sum of rgb 
            if (temp > maxBrightness) { // checking if sum of all rgb is greater than maxBrightness
                maxBrightness = temp; // set temp val to brightness
            }
        }
    }
    return maxBrightness;
    }

    int countBrightPixel() {
        int counterForPixel = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < depth; k++) {
                    if ((image[i][j][k].red + image[i][j][k].green + image[i][j][k].blue) == 255) { // count till 255
                        counterForPixel++; // store the val for counter
                        break;
                    }
                }
            }
        }
        return counterForPixel; // return the counter value
    }

    void transpose(int depth) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                Pixel transpose = image[i][j][depth]; // get transpose by swapping as we do in matrix
                image[i][j][depth] = image[j][i][depth];
                image[j][i][depth] = transpose;
            }
        }
    }
};
