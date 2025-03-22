#include <iostream>
#include <string>

using namespace std;

// interface dla vichislenia harakteristik chisel
class NumberCounter {
public:
    // virt vichislenia harakteristik chisel
    virtual int count(int number) = 0;

    virtual ~NumberCounter() {}
};

//class dla vichislenia  kolichestva simvolov v  desitichnoi zapisi chisla
class DigitCounter : public NumberCounter {
public:
    // pereopredelenie count
    int count(int number) override {
        if (number == 0) {
            return 1;
        }

        int count = 0;
        int num = number; // copia chisla chtobi ne izmenat ishodnoe
        if (num < 0) num = -num; // obrabativanie otricatelnih chisel

        while (num != 0) {
            num /= 10; // otbras poslednyy cifry 
            count++;    // yvelich schetchik simvolov
        }

        return count;
    }
};

// class dla vichislenia colvo razlichnix prostix mnogitilei chisla
class PrimeFactorCounter : public NumberCounter {
private:
    //proverka prostoe or no
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    //  count
    int count(int number) override {
        if (number <= 1) {
            return 0; // 1 and chisla <= 0 dont have prostix mnogitelei
        }

        int num = number; // copia chisla
        if (num < 0) num = -num; // obrabat otric chisla

        int primeCount = 0;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0 && isPrime(i)) {
                primeCount++;    // yvelich count, esli mnogitel prostoi
                while (num % i == 0) {
                    num /= i;    // ebiraem vse vhogdenia etogo prost mnog
                }
            }
        }

        if (num > 1 && isPrime(num)) {
            primeCount++; // esli ostalos < 1, to eto prostoi mnog
        }

        return primeCount;
    }
};

int main() {
    int number;

    cout << "vvedite celoe chislo: ";
    cin >> number;

    // sozdanie object class DigitCounter and PrimeFactorCounter
    DigitCounter digitCounter;
    PrimeFactorCounter primeFactorCounter;

    // vichislaem i vivodim haracteristiki chisla
    int digitCount = digitCounter.count(number);
    int primeFactorCount = primeFactorCounter.count(number);

    cout << "colichestvo simvolov v desatichnoi zapisi chisla: " << digitCount << endl;
    cout << "colichestvo razlichnix prostix mnogitelei chisla: " << primeFactorCount << endl;

}