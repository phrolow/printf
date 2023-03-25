extern void _printf(const char *str, ...);

int main() {
    _printf("Dos%s pizd%s %% %x %d %d %d o %d %d s %d\n", "434", "4", 0xbaadf00dbaadf00d, 7, 7, 7, 8800, 8723);

    return 0;
}