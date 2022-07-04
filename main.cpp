#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    int a[12][12], i, j, x, y, br;
    char c[12][12];

    srand(time(0));

    // Ucitavanje
    for(i = 0; i < 12; i++)
        for(j = 0; j < 12; j++)
        a[i][j] = 0;

    //Dodela mina
    for(int k = 0; k < 10; k++){
        i = rand() % 10 + 1;
        j = rand() % 10 + 1;
        if(a[i][j] == 9)
            k--;
        a[i][j] = 9;
    }

    //Dodela vrednosti
    for(i = 0; i < 12; i++)
        a[i][0] = 1;
        a[i][11] = 1;
    for(j = 0; j < 12; j++)
        a[0][j] = 1;
        a[11][j] = 1;
    for(i = 1; i < 11; i++)
        for(j = 1; j < 11; j++)
            if(a[i][j] == 9){
                for(int ii = i - 1; ii < i + 2; ii++)
                    for(int jj = j - 1; jj < j + 2; jj++)
                        if(a[ii][jj] != 9)
                            a[ii][jj]++;
            }
    for(i = 1; i < 11; i++)
        for(j = 1; j < 11; j++)
            c[i][j] = 'X';

    //Igra
    do{
        br = 0;
        cout<<"0.  ";

        for(j = 1; j < 11; j++)
            cout<<j<<". ";
        cout<<endl;

        for(i = 1; i < 10; i++){
            cout<<i<<".  ";
            for(j = 1; j < 11; j++)
                cout<<c[i][j]<<"  ";
            cout<<endl;
        }

        cout<<i<<". ";
        for(j = 1; j < 11; j++)
        cout<<c[i][j]<<"  "<<endl;
        cout<<"X:";
        cin>>x;
        cout<<"Y:";
        cin>>y;
        system("CLS");
        if(x > 10 || x < 1 || y < 1 || y > 10)
            continue;

        if(a[x][y] == 0)
            for(i = x - 1; i < x + 2; i++)
                for(j = y - 1; j < y + 2; j++){
                    if(a[i][j]==0)c[i][j]='0';
                    if(a[i][j]==1)c[i][j]='1';
                    if(a[i][j]==2)c[i][j]='2';
                    if(a[i][j]==3)c[i][j]='3';
                    if(a[i][j]==4)c[i][j]='4';
                    if(a[i][j]==5)c[i][j]='5';
                    if(a[i][j]==6)c[i][j]='6';
                    if(a[i][j]==7)c[i][j]='7';
            }

        if(a[x][y] == 1)
            c[x][y] = '1';
        if(a[x][y] == 2)
            c[x][y] = '2';
        if(a[x][y] == 3)
            c[x][y]='3';
        if(a[x][y] == 4)
            c[x][y] = '4';
        if(a[x][y] == 5)
            c[x][y] = '5';
        if(a[x][y] == 6)
            c[x][y] = '6';
        if(a[x][y] == 7)
            c[x][y] = '7';
        if(a[x][y] == 8)
            c[x][y] = '8';
        if(a[x][y] == 9)
            exit(9);
        for(i = 1; i < 11; i++)
        for(j = 1; j < 11; j++)
            if(c[i][j] != 'X')
                br++;
    } while(br != 90);

    //Prikaz
    system("CLS");
    for(i = 1; i < 11; i++){
        for(j = 1; j < 11; j++)
        cout<<a[i][j]<<" "<<endl;
    }
    cout<<"Cestitamo pobedili ste!";
}
