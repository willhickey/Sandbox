#include <iostream>
#include <string>
using namespace std;

int main()
{
    string inputString;
    cin>>inputString;

    for(size_t i=0; i<=inputString.size()/2; i++)
    {
        char temp = inputString[i];
        char temp2 = inputString[inputString.size()-1-i];
        inputString.replace(i, (size_t)1, (size_t)1, temp2);
        inputString.replace(inputString.size()-1-i, 1, 1, temp);
    }
    cout<<inputString<<endl;
}
