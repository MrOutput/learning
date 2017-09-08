/*
 * File name: rafael_cepeda_project_5.c
 * Author: Rafael Cepeda
 * Email: r.cepeda@linux.com, rlc50@students.uwf.edu
 * Assignment Number: 5
 * Last Changed: 08 September 2017
 *
 * Compile with:
 * cc -o fletters -O2 -s -march=native rafael_cepeda_project_5.c
 *
 * This filter program filters previously seen characters from the input.
 * Ex:
 *     > echo "Rafael Leonidas Cepeda" | ./fletters 
 *     > Rafel Lonids Cp
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


/*
 * look up c in bitmap.
 * if unused, c's flag is set and 1 is returned,
 * else 0 is returned.
 *
 * lookup is a half-split bitmap (indicating if alpha c has appeared before).
 * The lower half is for lowercase;
 * the higher half for uppercase.
 *
 * this function makes the assumption that the caller has
 * verified that c is an alpha char.
 */
int unused_set(char c)
{
    static unsigned long long int lookup;
    char bindex, bpos_offset, bpos;

    if (isupper(c)) {
        bindex = (c-'A');
        bpos_offset = ((sizeof(lookup)<<2)-1);
    } else {
        bindex = (c-'a');
        bpos_offset = 0;
    }
    bpos = (bindex+bpos_offset);
    const unsigned long long int bit = (1<<bpos);

    if ((lookup&bit) == 0) {
        lookup |= bit;
        return 1;
    }

    return 0;
}

/*
 * filters letters already encountered.
 *
 * maintains two pointers to the string, s and t, s always advances until EOL.
 * t only advances if the current char c is fresh,
 * else it will be overwritten on the
 * next iteration (with the following input character).
 *
 * it is always safe to reuse the line buffer since the filtered
 * string will never overflow the original.
 */
void filter(char *s)
{
    char *t;
    for (t=s; *s!='\0'; s++) {
        *t = *s;
        if (!isalpha(*s) || unused_set(*s))
            t++;
    }
    *t = '\0';
}

int main()
{
    char *line = NULL;
    size_t len = 0;
    
    while (getline(&line, &len, stdin) != -1) {
        filter(line);
        /* no newline here because it is already in the line buffer. */
        printf("%s", line);
    }

    /*
     * not neccessary because the process's
     * address space is reclaimed by the os,
     * but why not?
     */
    free(line);
}
