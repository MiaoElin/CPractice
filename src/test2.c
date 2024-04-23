void yo() {

    int *all = malloc(100*4); // all: 0x00
    int *eptr = &all[50]; // eptr: 0x50
    free(eptr); // 0x50

    int *value = malloc(4);
    free(value);

    int a; // Entry
    int *p = &a;
    free(p);

}