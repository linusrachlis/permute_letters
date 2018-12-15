#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "mystr.h"

// Print all permutations of the given letters.
void TraversePermutations(mystr Path, mystr Remainder, size_t TotalIndex)
{
	if (Remainder.Length > 0)
	{
		for (size_t I = 0; I < Remainder.Length; ++I)
		{
			if (Path.Length == 0)
				printf("\n");

			mystr NewPath = AppendByteToCopyOfString(Remainder.Data[I], Path);

			mystr NewRemainder = AllocateString(Remainder.Length - 1);
			int CopyDestIndex = 0;
			for (size_t CopySrcIndex = 0; CopySrcIndex < Remainder.Length; ++CopySrcIndex)
			{
				if (CopySrcIndex == I) continue;
				NewRemainder.Data[CopyDestIndex++] = Remainder.Data[CopySrcIndex];
			}

			size_t NewTotalIndex = (Path.Length > 0) ? TotalIndex + I : 0;
			TraversePermutations(NewPath, NewRemainder, NewTotalIndex);
		}
	}
	else
	{
		for (size_t I = 0; I < TotalIndex; ++I)
		{
			printf(" ");
		}
		char *PathCString = GetCString(Path);
		printf("%s\n", PathCString);
		free(PathCString);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "I need an argument - the word to anagram!\n");
		return 1;
	}

	mystr Word = MakeString(argv[1]);
	if (Word.Length < 1)
	{
		fprintf(stderr, "Empty word, that's no fun...\n");
		return 1;
	}
	else if (Word.Length > 7)
	{
		fprintf(stderr, "Look, 8! or more is just too big a number. Get real, man.\n");
		return 1;
	}
	else
	{
		TraversePermutations(MakeString(""), Word, 0);
	}

	return 0;
}
