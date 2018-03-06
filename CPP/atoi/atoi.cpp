#include <iostream>
using namespace std;
int myAtoi(string);

int main()
{
    string foo;
    cout<<"Enter a number:"<<endl;
    cin>>foo;
    cout<<foo<<endl;
    try {
        int i = myAtoi(foo);
        cout<<i<<endl;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }

}

//no overflow support here... it just keeps wrapping once it hits 2^31
int myAtoi(string input)
{
    int number =  0;
    for(size_t i=0; i<input.size(); i++)
    {
        //char c = input[i];
        int digit = input[i] & 207;
        if(digit > 9 || digit < 0)
        {
            //return 0;
            throw "Not a number";
        }
        else {
            number = 10 * number + digit;
        }
    }
    return number;
}
