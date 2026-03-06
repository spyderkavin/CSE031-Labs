#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i = 0; i < 4; i++)
        four_ints[i] = 2;

	printf("%x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i = 0; i < 4; i++)
        four_c[i] = 'A' + i; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:
	
	printf("four_ints[0] at end: %x\n", four_ints[0]); //#3
	printf("four_ints[1] in hex: %x\n", four_ints[1]); //#4
	printf("\nfour_ints:\n"); //#6
	for(i=0;i<4;i++){
		printf("Address: %p, Hex value: %x\n", (void*)&four_ints[i], four_ints[i]);
	}
	printf("\nfour_c:\n"); //#8
	for(i=0;i<4;i++){
		printf("Address: %p, Hex value: %x\n", (void*)&four_c[i], four_c[i]);
	}

	return 0;
}