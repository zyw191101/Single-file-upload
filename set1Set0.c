int main() {
    int a = 0; // 假设a是一个初始化为0的整型变量。

    // 设置（置1）a的第3位
    a |= (1 << 3);

    printf("After setting bit 3: %d\n", a);

    // 清除（置0）a的第3位
    a &= ~(1 << 3);

    printf("After clearing bit 3: %d\n", a);

    return 0;
}
