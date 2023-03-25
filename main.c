extern void _printf(const char *str, ...);

int main() {
    int popusk = 2147483647;

    _printf("%d %o %% %m %s %b %x %c o %d %d %d\n", -1, 072, "BIBA", 0b101, 0xbad, 'A', popusk, popusk, popusk);

    _printf("text\n");

    _printf("Attemption to DOD #%d: FAILED\n", popusk);

    return 0;
}