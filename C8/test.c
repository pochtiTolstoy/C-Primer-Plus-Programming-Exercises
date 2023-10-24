#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	char ch;
	float num_of_letters = 0, num_of_words = 0;
	float average;
	bool new_word = true;
	
	while ((ch = getchar()) != EOF)
	{
		if (ispunct(ch))
			continue;
		else if (isspace(ch))
		{
			new_word = true;
			continue;
		}
		else
		{
			num_of_letters++;
			if (new_word)
			{
				num_of_words++;
				new_word = false;
			}
		}
	}
	
	printf("letters  - %.2f\n", num_of_letters);
	printf("words - %.2f\n", num_of_words);
	average = num_of_letters / num_of_words;
	printf("The average number of letters per word is %f.\n", average);
	
	return 0;
}
