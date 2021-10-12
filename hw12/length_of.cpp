int length_of(char *s) {
    int length = 0;

    for (int i = 0; *(s + i) != 0; i++) {
        length++;
    }

    return length;
}