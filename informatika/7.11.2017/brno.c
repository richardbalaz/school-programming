#include <stdio.h>
#include <string.h>

#define ADDRESS_LEN 100
#define ADDRESS_COUNT 42
#define CHARS_MAX 256

/* Parse addresses from standart input to addresses array
 * return parsed addresses count
 */
int get_addresses(char (*addr_list)[ADDRESS_LEN])
{
    int ptr = 0;
    while (fgets(addr_list[ptr], ADDRESS_LEN, stdin)) {
        size_t len = strlen(addr_list[ptr]);
        if (len > 0 && addr_list[ptr][len - 1] == '\n') {
            addr_list[ptr][--len] = '\0';
        }
        ptr++;
    }
    return ptr;
}

/* Go thru addr_list with len of addr_count
 * and if next address's prefix match, store it's index to addr_index
 * return 1 if match, otherwise 0 when no more matching address
 */

int next_valid_address(char *prefix, char (*addr_list)[ADDRESS_LEN], int addr_count, int *addr_index)
{
    int prefix_len = strlen(prefix);

    static int ptr = 0;
    for (int i = ptr; i < addr_count; i++) {
        int cmp = strncmp(prefix, addr_list[i], prefix_len);
        if (cmp == 0) {
            *addr_index = i;
            ptr = i + 1;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    /* prefix from argument */
    char prefix[ADDRESS_LEN];
    int prefix_len;
    if (argc > 1) {
        strcpy(prefix, argv[1]);
        prefix_len = strlen(prefix);
    }

    /* enabled characters list */
    char chars[CHARS_MAX];
    memset(chars, '\0', CHARS_MAX);

    /* all addresses */
    char addr_list[ADDRESS_COUNT][ADDRESS_LEN];
    int addr_count = get_addresses(addr_list);

    /* count valid addresses and store next char after prefix */
    int addr, addr_len;
    int valid_addr_count = 0;
    while (next_valid_address(prefix, addr_list, addr_count, &addr)) {
        addr_len = strlen(addr_list[addr]);
        if (addr_len > prefix_len) {
            char c = addr_list[addr][prefix_len];
            if (!chars[c])
                chars[c] = c;
        }
        valid_addr_count++;
    }

    /* no address starting with prefix found */
    if (valid_addr_count == 0) {
        printf("Not found\n");
    }
     /* exactly one result */
    else if (valid_addr_count == 1) {
        printf("Found: %s\n", addr_list[addr]);
    }
     /* more than one result, print chars */
    else if (valid_addr_count > 0) {
        printf("Enable: ");
        for (int c = 0; c < CHARS_MAX; c++) {
            if (chars[c]) {
                printf("%c", chars[c]);
            }
        }
        printf("\n");
    }

    return 0;
}
