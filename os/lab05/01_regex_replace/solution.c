#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return 1;
    }

    regex_t regex;
    if (regcomp(&regex, argv[1], REG_EXTENDED)) {
        printf("Invalid regex\n");
        return 1;
    }

    char *text = argv[2];
    char *replacement = argv[3];
    size_t text_len = strlen(text);
    size_t repl_len = strlen(replacement);
    size_t buf_size = text_len + 1;
    char *buffer = malloc(buf_size);
    size_t buf_pos = 0;

    regmatch_t match;
    size_t offset = 0;

    while (!regexec(&regex, text + offset, 1, &match, 0)) {
        size_t match_start = match.rm_so + offset;
        size_t match_end = match.rm_eo + offset;
        size_t match_len = match_end - match_start;

        size_t new_size = buf_pos + (match_start - offset) + repl_len + 1;
        if (new_size > buf_size) {
            buf_size = new_size * 2;
            buffer = realloc(buffer, buf_size);
        }

        memcpy(buffer + buf_pos, text + offset, match_start - offset);
        buf_pos += match_start - offset;
        memcpy(buffer + buf_pos, replacement, repl_len);
        buf_pos += repl_len;

        offset = match_end;
    }

    size_t remaining = text_len - offset;
    size_t new_size = buf_pos + remaining + 1;
    if (new_size > buf_size) {
        buf_size = new_size;
        buffer = realloc(buffer, buf_size);
    }

    memcpy(buffer + buf_pos, text + offset, remaining);
    buf_pos += remaining;
    buffer[buf_pos] = '\0';

    printf("%s\n", buffer);

    free(buffer);
    regfree(&regex);
    return 0;
}