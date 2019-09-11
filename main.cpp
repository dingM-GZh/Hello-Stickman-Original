#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void dispOptions(char[]); //Displays Options
void askInputs(char[],char[],int&); // Asks for Inputs
void inpHist(char[]); // Input History
void deleteChar(char[],char); // Deletes Character from choices
bool checkInput(char[],char); // Checks if Input is allowed

void genOffset(char[],char[]); // Generate Offset
void dispHW(string); // Display Hello World
void checkHW(string&,char[],char[],int); // Check Hello World
bool checkCompletion(string);

void asdf(char[]);

int main()
{
   char userInputs[26];
   for (int i = 0; i < 26; i++)
      userInputs[i] = '*';

   char charOptions[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
   char charOffset[26];
   string helloWorld = "_____ _____";

   int valsEntered = 0;

   genOffset(charOptions, charOffset);

   do
   {
      dispOptions(charOptions);
//      asdf(charOffset);

      dispHW(helloWorld);

      askInputs( userInputs, charOptions, valsEntered);

      inpHist(userInputs);
      checkHW( helloWorld, charOffset, userInputs, valsEntered - 1);
   }
   while ( !checkCompletion(helloWorld) );

   dispHW(helloWorld);
   cout << endl;

   cout << "CONGRATULATIONS - YOU WIN \n"
        << valsEntered << " letters used \n";

   inpHist( userInputs );

   return 0;
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

void askInputs( char userInputs[], char inputList[], int &values )
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
   userInputs[values] = input;
   values++;
   deleteChar(inputList, input);
}

void inpHist( char userInputs[] )
{
   int index = 0;
   cout << "Input History:  ";

   while( userInputs[index] != '*')
   {
      cout << userInputs[index] << " ";
      index++;
      if( index >= 26 )
         break;
   }

   cout << endl
        << endl;
}

bool checkInput( char inputs[], char input )
{
   bool isFound = false;

   for( int i = 0; i < 26; i++ )
      if( inputs[i] == input)
         isFound = true;

   return isFound;
}

void deleteChar( char inputs[], char input )
{
   for( int i = 0; i < 26; i ++)
      if( inputs[i] ==  input)
         inputs[i] = '*';
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

void dispHW( string HW )
{
   for(int i = 0; i < 11; i++ )
      cout << HW[i] << " ";

   cout << endl;
}

void checkHW( string &hw, char offset[], char inputs[], int values )
{
   if( inputs[values] == offset[7] )
      hw[0] = 'h';

   else if( inputs[values] == offset[4] )
      hw[1] = 'e';

   else if( inputs[values] == offset[11] )
   {
      hw[2] = 'l';
      hw[3] = 'l';
      hw[9] = 'l';
   }
   else if( inputs[values] == offset[14] )
   {
      hw[4] = 'o';
      hw[7] = 'o';
   }
   else if( inputs[values] == offset[22] )
      hw[6] = 'w';

   else if( inputs[values] == offset[17] )
      hw[8] = 'r';

   else if( inputs[values] == offset[3] )
      hw[10] = 'd';
}

bool checkCompletion( string hw )
{
   string test = "hello world";
   if( hw.compare(test) == 0 )
      return true;
   else
      return false;
}

void asdf ( char offset[] )
{
   for( int i = 0; i < 26; i++ )
   {
      cout << offset[i] << "  ";
      if( i == 12 )
         cout << endl;
   }
   cout << endl;

   for( int i = 0; i < 13; i++ )
      cout << "---";

   cout << endl;
}