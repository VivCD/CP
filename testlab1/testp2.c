int OddSequence() {
    int counter = 0, backup = 0, max = 0, sum = 0, n;
    scanf("%f",n);
    while (n > 0) {
        sum = 0;
        backup = n;
        while (backup) {
            sum += backup % 10;
            backup /= 10;
        }
        if (sum % 2 == 1) {
            counter++;
        }
        else {
            if (counter >= max) {
                max = counter;
            }
            counter = 0;
        }
        cin >> n;
    }
    return max;
}