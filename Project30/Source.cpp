#include <iostream>
using namespace std;

void test(short int N){
	short int DIVAM = 0;
	short int MULAM = 0;
	short int temp = N;
	while(temp != 1){
		if (temp % 2 != 0){
			temp = 3 * temp + 1;
			MULAM++;
		}
		else{
			temp /= 2;
			DIVAM++;
		}
	}
	cout << DIVAM << " " << MULAM << "\n";
}

void task(short int N) {
	short int DIVAM = 0;
	short int MULAM = 0;

	cout << "C++:\n";
	test(N);

	cout << "Assembler:\n";
	__asm {

		CMP N, 1
		JZ CHECK
		
		BODY:	TEST N, 1
				JNZ ODD
				JZ EV

		ODD:	INC MULAM

				MOV BX, N
				MOV AX, 3
				MUL BX
				INC EAX

				MOV N, AX

				JMP CHECK

		EV:		INC DIVAM

				MOV DX, 0
				MOV AX, N
				MOV BX, 2
				DIV BX
				MOV N, AX

		CHECK : CMP N, 1
				JNE BODY
	}

	cout << DIVAM << " " << MULAM << "\n";

}

void main(){

	for(short int N = 1; N < 100; N++) {
		cout << "iteration " << N << "\n";
		task(N);
		cout << "\n";
	}

	cout << "\n";
	cout << "There is a tests for numbers from 1 to 100.\n";
	cout << "First number is DIV amount\n";
	cout << "Second number is MUL amount\n";
	
}