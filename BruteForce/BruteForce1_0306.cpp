#include <stdio.h>
#include <iostream>
using namespace std;

int N;
int yut[10];
int score[31] = {0,5,10,15,20,
                 50,30,35,40,45,
                 100,55,60,65,70,
                 75,80,85,90,95,500,1000,
                 275,250,300,150,175,150,
                 125,350,400};

//*******//
int moving[31][6];

int table[11][6] ={
        {5,22,23,24,25,26},
        {10,27,28,24,29,30},
        {22,23,24,25,26,15},
        {23,24,25,26,15,16},
        {24,29,30,20,21,21},
        {25,26,15,16,17,18},
        {26,15,16,17,18,19},
        {27,28,24,29,30,20},
        {28,24,29,30,20,21},
        {29,30,20,21,21,21},
        {30,20,21,21,21,21},
        };


int main() {
    //********//
    for(int i = 0; i <11; i++){
        for(int j = 0; j < 6; j++){
            moving[table[i][0]][j] = table[i][j];
        }
    }

    cin>> N;
    for(int i = 0; i < N; i++){
        cin>> yut[i];
    }
    int p = 0;
    for(int i = 0; i < N; i++){
        //p가 어디인지 확
        bool flag = false;
        for(int j = 0; j <11; j++){
            if(p == table[j][0]){
                flag = true;
                break;
            }
        }

        if(flag){
            p = moving[p][yut[i]];
        }else{
            p += yut[i];
            if(p > 21)  p =21;
        }
        cout<<score[p]<<" ";
        
        if(p == 21) break;
    }

}