#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void dispOptions(char[]); //Displays Options
void askInputs(vector<char>&,char[],vector<char>&); // Asks for Inputs
void inpHist(vector<char>); // Input History
void deleteChar(char[],char); // Deletes Character from choices
bool checkInput(char[],char); // Checks if Input is allowed

void genOffset(char[],char[]); // Generate Offset
void dispHW(char[]); // Display Hello World
void checkHW(char[],vector<char>,char[],bool[]); // Check Hello World
bool checkComplete(bool[]);

int main()
{
   vector<char> userInputs;
   vector<char> inputCopies;

   bool isComplete[8];
   bool finish;

   char charOptions[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
   char charOffset[26];
   char helloWorld[] = {"_____ _____"};

   genOffset(charOptions, charOffset);

   do
   {
      dispOptions(charOptions);

      dispHW(helloWorld);

      askInputs( userInputs, charOptions, inputCopies);

      inpHist(userInputs);
      checkHW(charOffset, userInputs, helloWorld, isComplete);
      finish = checkComplete(isComplete);
   }
while ( !finish );

}

void dispOptions( char options[] )
{
   cout << "ALL CHARACTER CHOICES AVAILABLE \n"
        << endl;

   for( int i = 0; i < 26; i++ )
   {
      cout << options[i] << "  ";
      if( i == 12 )
         cout << endl;
   }
   cout << endl;

   for( int i = 0; i < 13; i++ )
      cout << "---";

   cout << endl;
}

void askInputs( vector<char> &userInputs, char inputList[], vector<char> &copies )
{
   bool legitInput = false;
   char input;

   cout << "Enter an character:   ";
   cin  >> input;
   input = tolower(input);
   legitInput = checkInput(inputList, input);

   while( !legitInput )
   {
      cout << "Invalid input. Please enter a valid choice:  ";
      cin  >> input;
      input = tolower(input);
      legitInput = checkInput(inputList, input);
   }
   userInputs.push_back(input);
   deleteChar(inputList, input);
}

void inpHist( vector<char> userInputs )
{
   int index = 0;
   cout << "Input History:  ";

   for( int i = 0; i < userInputs.size(); i++ )
      cout << userInputs[i] << "  ";

   cout << endl
        << endl;
}

bool checkInput( char inputs[], char input )
{
   bool isFound = false;

   for( int i = 0; i < 26; i++ )
   {
      if( inputs[i] == input)
         isFound = true;
   }
   return isFound;
}

void deleteChar( char inputs[], char input )
{
   for( int i = 0; i < 26; i ++)
   {
      if( inputs[i] ==  input)
      {
         inputs[i] = '*';
      }
   }
}

void genOffset( char options[], char offset[] )
{
   srand(time(NULL));
   int randInt = rand() % 26;

   for( int i = 0; i < 26; i++ )
      options[i] = tolower(options[i]);

   for ( int i = 0; i < 26; i++ )
   {
      offset[i] = options[randInt];
      randInt++;
      if( randInt >= 26 )
         randInt = 0;
   }
}

void dispHW( char HW[] )
{
   for(int i = 0; i < 11; i++ )
   {
      cout << HW[i] << " ";
   }
   cout << endl;
}

void checkHW( char offset[], vector<char> copies, char hw[], bool HW[] )
{
   for( int i = 0; i < copies.size(); i++ )
   {
      if ( copies.at(i) == offset[3] )
         {
            hw[10] = 'd';
            HW[7] = true;
            //copies.erase(i, i + 1 );
         }
      if ( copies.at(i) == offset[4] )
         {
            hw[1] == 'e';
            HW[1] == true;
            //copies.erase(i, i + 1 );
         }
      if( copies.at(i) == offset[7] )
         {
            hw[0] == 'h';
            HW[0] = true;
         }
      if ( copies.at(i) == offset[11] )
      {
         hw[2] = 'l';
         hw[3] = 'l';
         hw[9] = 'l';
         HW[3] = true;
         //copies.erase(i, i + 1 );
      }
      if( copies[i] == offset[14] )
      {
         hw[4] = 'o';
         hw[7] = 'o';

         HW[4] = true;
         //copies.erase(i, i + 1 );
      }
      if ( copies.at(i) == offset[17] )
         {
            hw[8] = 'r';

            HW[6] = true;
            //copies.erase(i, i + 1 );
         }
      if( copies.at(i) == offset[22] )
         {
            hw[6] = 'w';

            HW[5] = true;
            //copies.erase(i, i + 1 );
         }
   }
}

bool checkComplete( bool completion[] )
{
   bool x = true;

   for( int i = 0; i < 8; i++)
   {
      if( completion[i] != true)
         x = false;
   }
   return x;
}
