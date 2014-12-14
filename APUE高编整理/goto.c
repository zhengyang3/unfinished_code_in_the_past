#include <stdio.h>

int main()
{
	// 1
	/*
	int i = 0;
	int j = 0;

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			if (i*j == 15) {
				printf("%d ", i*j);
				goto here;
				//break;
				// return 0; // exit(0);
			}
		}
		printf("\n");
	}
here: 
	printf("over\n");
*/

	// 2
	getA();
	if (err)
		goto getA_err;

	getB();
	if (err)
		goto getB_err;

	getC();
	if (err)
		goto getC_err;

	getZ();
	if (err) {
		return 0;
	}

	xxxxxxxxx;
	xxxxxxx;
	xxxxxx;
	xxxxx;
	xxxxxx;

	freeZ();
getZ_err:
	freeY();
getY_err:
	freeX();
	....;
	freeD();
	freeC();
getC_err:
	freeB();
getB_err:
	freeA();
getA_err:

	return 0;
}





