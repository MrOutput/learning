#include <stdio.h>

#define CSI       "\e["
#define BOLD      "1"
#define ITALIC    "3"
#define UNDERLINE "4"
#define REVERSE   "7"

#define BLACK_FG  "30"
#define RED_FG    "31"
#define GREEN_FG  "32"
#define YELLOW_FG "33"
#define BLUE_FG   "34"
#define MAGENTA_FG "35"
#define CYAN_FG   "36"
#define WHITE_FG  "37"

#define BLACK_BG  "40"
#define RED_BG    "41"
#define GREEN_BG  "42"
#define YELLOW_BG "43"
#define BLUE_BG   "44"
#define MAGENTA_BG "45"
#define CYAN_BG   "46"
#define WHITE_BG  "47"

#define SGR_END   "m"
#define AND       ";"

#define RESET CSI SGR_END

#define KEYWORD CSI ITALIC AND MAGENTA_FG SGR_END
#define LITERAL CSI YELLOW_FG SGR_END
#define KEY CSI UNDERLINE SGR_END
#define COMMENT CSI CYAN_FG SGR_END
#define TODO CSI UNDERLINE AND WHITE_FG SGR_END

int main(void)
{
    printf("%s", CSI "2J" CSI "H");

    char *lang = " 1 " COMMENT "/* " RESET TODO "TODO" RESET COMMENT " Test Comment\n" RESET
                 " 2 " COMMENT " * testing\n" RESET
                 " 3 " COMMENT " */\n" RESET
                 " 2 "KEYWORD "async function" RESET " Hello(arr, destruct) {\n"
                 " 3     " KEYWORD "var" RESET " x = " LITERAL "-1.23e+8" RESET  ";\n"
                 " 4     " KEYWORD "var" RESET " y = " LITERAL "0xAF" RESET  ";\n"
                 " 5     " KEYWORD "var" RESET " mystring = " LITERAL "\"Hello, world!\"" RESET  ";\n"
                 " 6     " KEYWORD "let" RESET " blah = arr[" LITERAL "\"somekey\"" RESET "];" COMMENT "//My comment\n" RESET
                 " 7     " KEYWORD "let" RESET " { method, status, part } = destruct;\n"
                 " 8     " KEYWORD "let" RESET " path = " LITERAL "`/endpoint/" RESET "${part}" LITERAL "/done`" RESET ";\n"
                 " 9     " KEYWORD "var" RESET " myobj = " LITERAL "{ " RESET KEY "name" RESET LITERAL": " RESET "mystring" LITERAL ", " RESET "\"" KEY "person age" RESET "\"" LITERAL": 23, " RESET KEY "path" RESET LITERAL", [" RESET "mystring" LITERAL "]: \"Hi\" }" RESET ";\n"
                 "10     " KEYWORD "if" RESET " (" LITERAL "true" RESET " || x " KEYWORD "instanceof" RESET " Number) {\n"
                 "11     } " KEYWORD "else" RESET " {\n"
                 "12     }\n"
                 "13     " KEYWORD "for" RESET " (" KEYWORD "let" RESET " i = " LITERAL "0" RESET "; i < arr.length; i++) {\n"
                 "14     }\n"
                 "15     " KEYWORD "var" RESET " p = " KEYWORD "new" RESET " Promise(" KEYWORD "function" RESET" (resolve, reject) {\n"
                 "16         resolve(" LITERAL "18" RESET ");\n"
                 "17     });\n"
                 "18     " KEYWORD "let" RESET" a = (" LITERAL "true" RESET ") ? " LITERAL "3" RESET" : " LITERAL "5" RESET ";\n"
                 "19     " KEYWORD "return await" RESET " sum(x, y, " LITERAL "25" RESET ");\n"
                 "20 }";
    puts(lang);

    char *prompt = CSI "2G" CSI BOLD AND RED_FG SGR_END "->" RESET " ";
    char *line = NULL;
    size_t size = 0;
    ssize_t read = 0;

    puts("\n" CSI ITALIC AND CYAN_FG SGR_END "Welcome:" RESET);

    do {
        printf("%s", prompt);
        read = getline(&line, &size, stdin);
    } while (1);

    return 0;
}
