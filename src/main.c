/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <stdint.h>

typedef enum {
	no_separator,
	master,
	cond,
	linefeed,
} separator_type;

separator_type test_separator(char separator) {
	const char master_separators[] = {' ', '\t', ';', '-', '!'};
	const char cond_separators[] = {',', '.'};
	uint32_t i;

	if (separator == '\n') {
		return linefeed;
	}

	for (i = 0; i < sizeof(master_separators); i++) {
		if (master_separators[i] == separator) {
			return master;
		}
	}

	for (i = 0; i < sizeof(cond_separators); i++) {
		if (cond_separators[i] == separator) {
			return cond;
		}
	}

	return no_separator;
}

int main() {
	char c = 0;
	separator_type lastct = master, curretct;
	char buffer[4];
	int64_t words = 0;

	do {
		scanf("%c", &c);
		curretct = test_separator(c);
		
		switch (curretct) {
		case no_separator:
			if (lastct == master) {
				words++;
			} else if (lastct == cond) {
				if ((c < '0') || (c > '9')) {
					words++;
				}
			}
			break;
		
		default:
			break;
		}
		
		lastct = curretct;
	} while (c != '\n');

	printf("%d\n", words);
	return 0;
}
