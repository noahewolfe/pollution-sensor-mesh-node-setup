#include "Base64.hpp"

void Converter::convert() {
	//char * digits = (char *) malloc (expectedBase64Length);
	// for some values, we can say a zero is defined elsewhere
	int val = num + zeroVal;//abs(num - zeroVal);

	int currentQuotient = val;
	int currentRemainder;
	int charPosition = expectedBase64Length - 1;

	do {
		currentRemainder     = currentQuotient % 64;
		currentQuotient      = currentQuotient / 64;
		base64[charPosition] = NUMERALS[currentRemainder];

		Serial.print(F("Char Pos: "));
		Serial.println(charPosition);
		Serial.print(F("Q: "));
		Serial.println(currentQuotient);
		Serial.print(F("R: "));
		Serial.println(currentRemainder);
		Serial.print("Char: ");
		Serial.println(base64[charPosition]);

		charPosition--;
	} while(currentQuotient > 0 && charPosition >= 0);

	while(charPosition >= 0) {

		Serial.print(F("Char Pos in Padding: "));
		Serial.println(charPosition);

		base64[charPosition] = NUMERALS[0]; // pad with zero char
		charPosition--;
	}
}

void convertNumber(char arr[], int num, int zeroVal, int expectedBase64Length) {

	//char * digits = (char *) malloc (expectedBase64Length);

	// for some values, we can say a zero is defined elsewhere
	int val = num + zeroVal;//abs(num - zeroVal);

	int currentQuotient = val;
	int currentRemainder;
	int charPosition = expectedBase64Length - 1;

	do {
		currentRemainder     = currentQuotient % 64;
		currentQuotient      = currentQuotient / 64;
		arr[charPosition] = NUMERALS[currentRemainder];

		/*
		Serial.print("Char Pos: ");
		Serial.println(charPosition);
		Serial.print("Q: ");
		Serial.println(currentQuotient);
		Serial.print("R: ");
		Serial.println(currentRemainder);
		*/

		charPosition--;
	} while(currentQuotient > 0 && charPosition >= 0);

	while(charPosition >= 0) {

		/*
		Serial.print("Char Pos in Padding: ");
		Serial.println(charPosition);
		*/

		arr[charPosition] = NUMERALS[0]; // pad with zero char
		charPosition--;
	}

}
