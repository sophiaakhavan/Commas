/********************************************************
 * CS 103 PA 1: Commas
 * Name: Sophia Akhavan
 * USC email: sakhavan@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 *
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long long n;
  cout << "Enter an integer:" << endl;

  /* Your code here */
  cin >> n;
  int digits;
  long long num=n;
  while(num!=0){ //counts how many digits in n
    digits++;
    num/=10;
  }
  if(n==0 && digits==0){
    cout << 0;
  }
  if(n<0){
    cout << "-";
    n*=-1;
  }
  while(digits>0){
    long long power=pow(10,digits-1); //variable to find first few digits
    if(digits<=3){ //if digits is less than or equal to 3, no commas needed
      if(n==0){
        cout << "000";
      }
      else if(n>=100){
        cout << n;
      }
      else if(n<100 && n>=10 && digits==3){
        cout << "0" << n;
      }
      else if(n<10 && n>0 && digits==3){
        cout << "00" << n;
      }
      else cout << n;
      break;
    }
    else if((digits)%3==0){ //if digits can evenly be divided by 3, commas easily placed
      if(n/(power/100) == 0){ //first 3 digits equal zero
        cout << "000" << ",";
      }
      else if(n/(power/100)<100 && n/(power/100)>=10){ //like 012
        cout << "0" << n/(power/100) << ",";
      }
      else if(n/(power/100)<10){
        cout << "00" << n/(power/100) << ","; //like 001
      }
      else cout << n/(power/100) << ","; //print first 3 digits + ,
      n%=(power/100); //now move to next 3 digits
      digits-=3;
    }
    else if((digits-1)%3==0){ //if digits is 4,7,10,etc
      cout << n/power << ","; //print first digit + ,
      n%=power; //now move over 1 digit
      digits-=1;
    }
    else if((digits-2)%3==0){
      cout << n/(power/10)<<","; //print first 2 digits + ,
      n%=(power/10); //move over 2 digits
      digits-=2;
    }  
  }
  cout << endl;
  /* End of your code */
  return 0;

}
