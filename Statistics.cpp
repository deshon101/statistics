//------------------------------------------------------------------
// File name:  statistics.cpp
// Assign ID:   PROG7
// Due Date:    2/26/2017 at 11:59 pm
//
// Purpose: Calculate two statistics, average(mean) and standard 
//          deviation of decimal (float) test scores stored in 
//           file scores.dat.
// Author: dgrant De'Shon Grant  
//
//------------------------------------------------------------------ 
#include <fstream> 
#include <iomanip> 
#include <iostream> 
#include <cmath>
using namespace std;
int main() {
    
   
    cout << endl << "(c) 2017, dgrant De'Shon Grant " << endl << endl; 
    
    //----------------
    // 1. Initialize accumulators, N (count), SumX and SumXsq, to 0
    //---------------- 
    
    int N = 0; 
   double Avg,
          SumX = 0, 
          SumXsq = 0, 
          StdDev,
          Var,
          score = 0;
     
     
    
    //----------------
    // 2. Repeat for each score in the file 
    //  2.a) Read a Score 
    //  2.b) Increment N, the number of  scores read.  
    //  2.c) Add Score to SumX. 
    //  2.d) Add Score * Score to SumXsq 
    //---------------- 
    
    ifstream inF; 
    
    inF.open("scores.dat"); 
    
    if(inF.fail()) 
        cout << " FATAL ERROR: UNABLE TO OPEN FILE \"scores.dat\". TERMINATING..." << endl;
      
   
    
    while(inF >> score) {
        N ++;
        SumX += score; 
        SumXsq += pow(score, 2.0); 
        
    } 
    
    
    
   //--------------------
   // 3. Compute the mean (average) using equation (b). 
   //-------------------- 
    
    Avg = SumX / N; 
    
   //------------------- 
   //4. Compute the Variance using equation (d). 
   //------------------- 
    
    Var = (SumXsq - 2 * Avg * SumX + N * pow(Avg,2.0)) / N;        
   //-------------------
   // 5. Compute the standard deviation (StdDev) using the equation (e). 
   //-------------------     
    
        StdDev = sqrt(Var); 
    
    
    if(N == 0) 
        Avg = 0.00; 
        Var = 0.00; 
        StdDev = 0.00;
        
        cout << "All statistics are ZERO !!" << endl; 
    
    
    //-------------------
    // 6. Display the computed values in the Statistical Analysis Report. 
    //------------------- 
     
    
    cout << "STATISTICAL ANALYSIS REPORT"<< endl;
    cout << "==========================="<< endl;
    cout << "                          "<< endl; 
    cout << " SCORE COUNT    = " << right << setw(9) << N << endl;
    cout << " SUM OF VALUES  = " << fixed << showpoint << setprecision(2) << right << setw(9) << SumX << endl ;
    cout << " SUM OF SQUARES = " <<  fixed << showpoint << setprecision(2) << right << setw(9) << SumXsq << endl ;
    cout << " AVERAGE        = " << fixed << showpoint << setprecision(2) <<  right << setw(9) << Avg << endl ;
    cout << " VARIANCE       = " << fixed << showpoint << setprecision(2) << right << setw(9) << Var << endl ;
    cout << " STD DEVIATION  = " << fixed << showpoint << setprecision(2) << right << setw(9) << StdDev << endl ;
    cout << "                          "<< endl; 
    cout << "==========================="<< endl; 
  
    
    inF.close();
    
        
    cout << endl << "(c) 2017, dgrant De'Shon Grant " << endl << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0; 
}//main
