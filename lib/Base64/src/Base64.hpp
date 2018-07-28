#include <Arduino.h>

static const char NUMERALS[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'+', '/'
};

//static const int MAX_ONE_DIGIT = 63;
//static const int MAX_TWO_DIGIT = 4095;
//static const int MAX_THREE_DIGIT = 258111;

class Converter {
	public:
		void convert();
		int num;
		int zeroVal;
		int expectedBase64Length;
		char base64[1];
};

void convertNumber(char arr[], int num, int zeroVal, int expectedBase64Length);
