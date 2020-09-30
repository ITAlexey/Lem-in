//
// Created by alexey on 30.09.2020.
//

#include "tests.h"

void 		success(void)
{
	printf("| %sSUCCESS%s |\n", GREEN, RESET);
}

void 		fail(void)
{
	printf("|   %sFAIL%s  |\n", RED, RESET);
}

int 	main(void)
{
	printf("Validation:\n\n");
	__CHECK_VALIDATION__();
	printf("\nEnds of tests.\n");
}