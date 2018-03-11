//https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0/?ref=self
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

bool debug = false;
int getMaxLengthValidForward(string);
int main()
{
	int numberOfTests;
    cin>>numberOfTests;
    for(int testNumber=0; testNumber<numberOfTests; testNumber++)
    {
		string inputString;
		cin>>inputString;
		int maxForward = getMaxLengthValidForward(inputString);
		reverse(inputString.begin(), inputString.end());
		replace(inputString.begin(), inputString.end(), '(', 'x');
		replace(inputString.begin(), inputString.end(), ')', '(');
		replace(inputString.begin(), inputString.end(), 'x', ')');

		int maxBackward = getMaxLengthValidForward(inputString);
		if(maxBackward > maxForward)
			cout<<maxBackward<<endl;
		else
			cout<<maxForward<<endl;
		if(debug) cout<<"Results: "<<maxForward<<","<<maxBackward<<endl;

    }
	return 0;
}

int getMaxLengthValidForward(string inputString)
{
//in retrospect this is needlessly complex, but it works so I'm not going to rewrite it.
//A better solution would be to use the stack to store the previous valid sum which
//would replace sumOfPreviousContigousValidSections and make the bookkeeping much easier.
	int maximumValidLength = 0;
	int currentValidLength = 0;
	int sumOfPreviousContigousValidSections = 0;
	bool currentlyValid = false;
	stack<int> characterStack;

	for(int i=0; i<(int)inputString.length(); i++)
	{
		if(debug) cout<<i<<","<<inputString[i];
		if(inputString[i]=='(')
		{
			characterStack.push(i);
		}
		else if(inputString[i]==')')
		{
			if(!characterStack.empty())
			{
				int popDepth = characterStack.top();
				if(debug) cout<<" popping: "<<popDepth;
				currentValidLength = (i-popDepth+1) > currentValidLength ? (i-popDepth)+1 : currentValidLength;

				if(debug) cout<<" currentMaxUpdated: "<<currentValidLength;
				characterStack.pop();
				if(characterStack.empty())
				{

					sumOfPreviousContigousValidSections += i-popDepth+1;
					if(sumOfPreviousContigousValidSections > maximumValidLength)
					{
						maximumValidLength = sumOfPreviousContigousValidSections;
					}
					currentValidLength = 0;
					if(debug) cout<<" Sum: "<<sumOfPreviousContigousValidSections;
				}
			}
			else
			{

				if(currentValidLength + sumOfPreviousContigousValidSections > maximumValidLength)
				{
					maximumValidLength = currentValidLength + sumOfPreviousContigousValidSections;
				}
				if(debug) cout<<" invalid. currentValidLength:"<<currentValidLength<<" sumOfPrevious:"<<sumOfPreviousContigousValidSections<<" newMax:"<<maximumValidLength;
				sumOfPreviousContigousValidSections = 0;
			}
		}
		if(characterStack.empty())
		{
			if(currentValidLength + sumOfPreviousContigousValidSections > maximumValidLength)
			{
				maximumValidLength = currentValidLength + sumOfPreviousContigousValidSections;
			}
		}
		else
		{
			if(currentValidLength > maximumValidLength)
			{
				maximumValidLength = currentValidLength;
			}
		}
		if(debug) cout<<endl;
	}
	if(debug) cout<<"Return: "<<maximumValidLength<<endl;
	return maximumValidLength;

}
