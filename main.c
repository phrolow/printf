extern void _printf(const char *str, ...);

int main() {
    int popusk = 2147483647;

    _printf("Dos%d pizd%d %% %d %d %d %d o %d %d s %d\n", popusk, popusk, popusk, popusk, popusk, popusk, popusk, popusk, popusk);

    _printf("PIZDA\n");

    _printf("DOD #%d: FAILED\n", popusk);

    return 0;
}