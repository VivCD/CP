Bitwise AND operator: Extract a subset of bits in a value   //EX: // (n&(~(1ll << x))) seteaza bitul x cu 0
Bitwise OR operator: Set a subset of bits in a value  //EX: //   n|(1ll<<x)   seteaza bitul x cu 1
Bitwise XOR operator: toggle a subset of bits in a value


Înmulțirea cu o puterea lui 2 se face foarte rapid cu operația de deplasare la stânga pe biți, <<. Astfel, a * 2k este egal cu a << k. Desigur, atenție la overflow!

Reprezentarea în baza 2 a unui număr par (și reprezentarea sa internă) se termină cu cifra 0, iar a unui număr impar se termină cu 1.ÎN general n & 1 reprezintă ultimul bit din reprezentarea internă a lui n

Pentru a determina bitul k al lui n putem folosi expresia (n >> k) & 1. 




How to count the bits in a number: 
unsigned int BitCounter(unsigned n) {
    int counter = 0;
    while (n) {
        counter++;
        n = n >> 1;
    }
    return counter;
}



How to repesent a number in any base(2-10) :

    int n, b;
    cin >> n >> b;
    while (n) {
        int cif = n % b;
        cout << cif;
        n /= b;
    }


Size of an array:

 int n = sizeof(arr) / sizeof(arr[0]);


How to add 2 numbers using bitwise operators:


int func(int a, int b){
    while(b){
        int carry = a&b;
        a = a^b;
        b = carry<<1;
    }
    return a;
}