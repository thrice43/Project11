#include <iostream>
//#include <iomanip>
//#include <cmath>
using namespace std;


//Prototypes
int getTotal(int twoDim[3][3]); // Accepts a Two dimenstional Array as an argument,
                              // Returns the total value of all the values of the array
                            
// Accepts: A Two Dimensional Array As an arguement
// Returns: Average of all values in array w/ precision of two
int getAverage( int twoDim[3][3] ) ; 

// Accepts: Two Dimensional Array as an argument, and second argument of int should be the indice of the row.
// Returns: Total of all the members of the array as an Int
int getRowTotal (int twoDim[3][3], int row ) ; 


/********************* REQUIRED *************************/
// Accepts: Two arguments, an Two-Dimensional Array, and a second argument where the subscript of the first row
// Returns: The total of the values in a subscript
int getColumnTotal ( int twoDim[3][3], int  column) ;  


// Accepts: A two dimentional array Second argument is the row indice, therefore colums must be iterated
// Returns: Integer Value of the highest value
int getHighestInRow( int twoDim[3][3], int row) ; 
/********************************************************/

// Accepts: Two dimensional Array and a int row, therefore columns is iterated
// Returns the lowest in the twoDim[3][3]
int getLowestInRow( int twoDim[3][3], int row) ;

void areYouStillDown(int twoDim[3][3], bool &doneFlag);
void printArray(int twoDim[3][3]);

int main(){
    int theArray [3] [3] = { 
							{10, 20, 30},  
							{78, 35,18} , 
							{105, 24, 1} 
						   };
	bool done = false;
	areYouStillDown(theArray, done) ; 
    return 0 ; 
}

//  int twoDim[row][column]
int getTotal(int twoDim[3][3]){
    const int TOP = 3 ; 
    int accum = 0; 
    for (int i = 0 ; i < TOP ; i++){
        for (int j = 0 ; j < TOP ; j++){
            accum += twoDim[i][j] ; 
        }
    }
	return accum; 
}
int getAverage( int twoDim[3][3] ){
	int tot = 0 ; 
    for (int i = 0 ; i < 3 ; i ++){
		for (int j = 0 ; j <3 ; j++ ) {
			tot += twoDim[i][j];
		}
	}
	int total = tot/9.0 ; 
	return total ; 
}
int getRowTotal (int twoDim[3][3], int row ){
    //Declare/Initialize
    int i = 0 ; 
    int rTotal = 0 ; 
    while (i < 3){
        rTotal+=twoDim[row-1][i];
        i++;
    }
    return rTotal;
}                                      
int getColumnTotal ( int twoDim[3][3], int  column){
    //Declare/Initialize
    int i = 0 ; 
    int cTotal = 0 ; 
    while (i < 3){
        cTotal+=twoDim[i][column-1];
        i++;
    }
    return cTotal;
}
int getHighestInRow( int twoDim[3][3], int row){
    //Inialize and Delcare variables and ocnstantas
    int high = 0 ; 
    int i = 0 ;
     
    while(i < 3){
        //if twodim locaiton is higher than high than
        if (twoDim[row][i] > high){
            high = twoDim[row][i] ;// high is now that location
        }
        i++;
    }
    return high ; 
        
}
int getLowestInRow( int twoDim[3][3], int row){
    int i = 0 ; 
    int low = twoDim[row][i] ;
    //While twoDim[row][i] is 'something' 
    while(twoDim[row][i]){
        
        
        // speificed entry in twoDim is less than low
        if (twoDim[row][i] < low ){
            low = twoDim[row][i];    // low is now equal to the new 'low'
        }
        i++; 
    } 
    return low ; 
}


void areYouStillDown(int twoDim[3][3] , bool &doneFlag){
	int userIn = 0 ; 
	int outTmp = 0 ; 
	double dbl = 0.00;
	int row = 0 , column = 0 ; 

	cout << "Quite Interestings......." << endl; 
	
	do {
		
		cout << "1.) View Array" ;
		cout << "\n2.) Get Total\n3.) Get Average";
		cout << "\n4.) Get Row Total";
		cout << "\n5.) Get Column Total\n6.) Get Highest In Row" ;
		cout << "\n7.) Get Lowest In Row\n\n\tInput: "  ;
		try{
			cin >> userIn ; 
			if ( userIn < 1 || userIn > 7){
				userIn = 0 ;
				cout << "\nError!!!! Try Againz" << endl;
			}
		}
		catch(string){
			cout << "Error: Try Again";
		}
		catch(char){
			cout << "Error: Try Again";
		}

		if (userIn == 1){
	
			printArray(twoDim);
			doneFlag = true;
		}
		else if (userIn == 2){
			outTmp = getTotal(twoDim); 
			doneFlag = true;
		}
		else if (userIn == 3){
			dbl = getAverage(twoDim);
			doneFlag = true ;
		}
		else if (userIn == 4){
			
			cout << "Enter a number 1-3: ";
			cin >> row ; 
			outTmp = getRowTotal(twoDim, row);
			doneFlag = true;
		}
		else if (userIn == 5){
			outTmp = getColumnTotal(twoDim,column);
			doneFlag = true;
		}
		else if (userIn == 6){
			cout << "Enter a number (1-3) for Highest # in Row 1-3: ";
			cin >> row ; 
			outTmp = getHighestInRow(twoDim,row);
			doneFlag = true;
		}
		else if (userIn == 7){
			cout << "Enter a number (1-3) for Highest # in Row 1-3: ";
			cin >> row ; 
			outTmp = getLowestInRow(twoDim, row);
			doneFlag = true;
		}
		else {

		}
	}while(!doneFlag || userIn < 1 || userIn > 8);
}



void printArray(int twoDim[3][3]){
	for (int i = 0 ; i < 3 ; i++){			
		for (int j = 0 ; j < 3 ; j++ ){
			cout << "{ " << twoDim[i][j]<<", " ; 
	}
	cout << "} " << endl;
	}
}



















