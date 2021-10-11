#include <iostream>
#include <math.h>// including math - to use pow() function
#include <bits/stdc++.h>
#include <sstream> //for the use of ostringstream - integer to string conversion

using namespace std;

//Validate function declaration - parameter recieved
bool ValidateInput(int Num){


    ostringstream ss;
    ss<<Num;

    //converting into string
    string sNum = ss.str();

    //checking for length - can only be 8 bits
    if (sNum.length()<9){

        //for loop - itertion -checking each character
        for (int i=0; i<sNum.length(); i++){

            //if... else checking if the value recieved only contains 0's and 1's
            if (sNum[i]=='0' || sNum[i]=='1'){

                //if statemnt - checking if all the numbers are ones and zeros and is the same length as the
                //value recieved.
                //returns the boolean value to the main function
                if (sNum[i]==sNum.length()){
                    return true;
                }//return

            }else{
                //error message - if not ones and zeros
                cout<<"Invalid Entry. Not Binary"<<endl;
                return false;

            }//if...else 0 ot1

        }//for i

    }else{
        //error message -  if there are more than 8 characters in the string
        cout<<"Invalid Entry. Bits Exceeded."<<endl;
        return false;

    }//if..else length

}//end of ValidateInput function



//global declaration, assigned to zero
int Decimal=0;

//conversion function - converting Binary to Decimal
//Base 2 to Base 10
//contains two parameters
int Convert(int Value, int Power){

    //variable declaration
    int Remainder;

    //if statement - condition
    if (Value>0){

         //finding the modulus of the Value (parameter) recieved
         Remainder = Value%10;

        //before the use of the function, Decimal=0
        //Binary is Base 2, therefore, the first value of the pow() function is 2
        //when using the converting method, the base is raised to the 0th power, parameter recieved is zero
        //remainder is the moudulus value
        //To the value of decimal, the decimal and remainder, multiplied by there base raised the power, is added
        Decimal = Decimal + Remainder * pow(2, Power);

        //the parameter value is then assigned to itself divided by 10
        Value = Value/10;

        //increment of power
        Power++;

        //recursion function
        //The function "called" within the function, having a condition (if statement) so there's a condition
        //for the function. Allowing the function to stop "calling" itself (recursion stops)
        Convert(Value, Power); //parameter values are added to the function, without mentioning data type again

        //returns the decimal value of the binary value, to the main function
        return Decimal;
    }//if
}//convert

int main()
{

//varable declaration
int BinaryVal;

//Asks the user for input
cout<< "Enter Binary: ";

//input stored in varaible
cin>>BinaryVal;

if (ValidateInput(BinaryVal)){

//global vaiable stored the function value recieved
//arguements are passed to the function Convert()
//output of the converted value
cout<< "The decimal form of " << BinaryVal << " is: " << Convert(BinaryVal, 0) ;

}else{
}

    return 0;
}
