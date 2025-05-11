#include <iostream>
#include <fstream>
using namespace std;

//Creating a gobal variable for the grid
char grid[100][100];

//Creating the function to know if it is safe to place
bool safeToPlace(int x, int y, int row, int column){


    
//Checking left
     for(int j = y - 1; j >= 0; j--){
        if (grid[x][j] == 'R'){
            
            return false;
        }
        if(grid[x][j] == '*'){
            break;
        }
    }
//Checking right
    for(int j = y + 1; j < column; j++){
        if(grid[x][j] == 'R'){
            
            return false;
            
        }
        if(grid[x][j] == '*'){
            break;
        }
    }

//Checking up
    for(int i = x - 1; i >= 0; i--){
        if (grid[i][y] == 'R'){
            
            return false;
        }
        if(grid[i][y] == '*'){
            break;
        }
    }
//Checking down
    for(int i = x + 1; i < row; i++){
        if (grid[i][y] == 'R'){
            
            return false;
        }
        if(grid[i][y] == '*'){
            break;
        }
    }


    return true;
}



//Function to place the rooks
bool rookPlacing(int row, int column, int n, int placed){

    //Base case

    if(placed == n){

        return true;
    }
    //Placing the rooks
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j] == 'E' && safeToPlace(i,j,row,column)){
                grid[i][j] = 'R';
            
            if(rookPlacing(row, column, n, placed +1)){
                return true;
            }
            grid[i][j] = 'E';
            
            }
        }
    }    
    return false;

}

//Main function
int main(){
    string file;
    cout << "Please enter the name of the input file: "<< endl;

    cin >> file;
    //Opening file
    ifstream fin(file);
    int row;
    //Reading row
    fin >> row;

    int column;
    //Reading column
    fin >> column;

    cout << row;
    cout << column << endl;

   
    //Reading the grid
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            fin >> grid[i][j];
        }
    }

       // Close any open file streams
     fin.close();

    ///Printing the grid
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    
    int numRooks;

    cout << "Please enter the number of rooks you want to place on the printed board" << endl;
    //Reading the number of rooks
    cin >> numRooks;





    //Using the rookPlacing function

    if(rookPlacing(row, column, numRooks, 0)){
        cout << "The requested number of rooks can all be placed." << endl;
        //Printing new grid
        for(int i = 0; i < row; i++)
    {       for(int j = 0; j < column; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    //If the rookPlacing function does not work
    }else{

        cout << "It is not possible to place the requested number of rooks on the specified board." << endl;
        return 1;
    }


    
    return 0;
}