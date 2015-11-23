/***********************************************************
	Author: Zachary Buffone
	Date: 11/22/2015

	This program provides a example of Typoglycemia,
		a condition in which humans can read scrambled
		words if the first and last letter has been
		untouched. Inspiration for this project came from
		https://www.reddit.com/r/dailyprogrammer/,
		where programming challanges are periodiclly
		posted.

***********************************************************/

#include <stdio.h>
#include <ctype.h>

#define WORD_BUFFER_SIZE 50

void scrambleWord(char* outputString, int nextWordStartingIndex, int nextWordLength);


int main(int argc, char* argv[]){
	int nextWordStartingIndex = 0;
	int nextWordLength = 0;
	char nextChar;
	int i = 0;

	//the string to be worked on.
	char outputString[] = "According to a research team at Cambridge University, it doesn't matter in what order the letters in a word are,\nthe only important thing is that the first and last letter be in the right place.\nThe rest can be a total mess and you can still read it without a problem.\nThis is because the human mind does not read every letter by itself, but the word as a whole.\nSuch a condition is appropriately called Typoglycemia.";


	nextChar = outputString[i];
	while (nextChar != '\0'){

		if (isalpha(nextChar) || nextChar == '\'')
		{
			if (nextWordLength == 0)					//start the index of the word at index of nextChar
				nextWordStartingIndex = i;				//if the word length is 0.

			nextWordLength++;							//increase the word length by one.
		}												
		else                                            
		{
			if (nextWordLength != 0)					//if wordLength is not zero, the previous indexes of the string
			{											//contain a word.
				if (nextWordLength > 3)
				{
					scrambleWord(outputString,			//scramble the word only if the length is
						nextWordStartingIndex,			//greater than 4. Only words who have
						nextWordLength);				//>= 2 middle chars can be worked on.
				}

				nextWordLength = 0;						//the word has ended, set word length to 0.
			}
		}

		i++;
		nextChar = outputString[i];
	}


	printf("%s\n\n", outputString);

	return 0;
}


void scrambleWord(char* outputString, int nextWordStartingIndex, int nextWordLength){
	int middleCharLength = nextWordLength - 2;
	char middleChars[WORD_BUFFER_SIZE - 2];
	int i = 0;

	//copys the middle chars from outputString into middleChars
	for (i = 0; i < middleCharLength; i++)
		middleChars[i] = outputString[nextWordStartingIndex + i + 1];

	//places chars back into outputString in reverse order
	for (int i = middleCharLength; i > 0; i--)
		outputString[nextWordStartingIndex + i] = middleChars[middleCharLength - i];

	return;
}
