/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
#include<string>
using namespace std;

class Integer {
    int num;
    string str;

public:
    Integer() {}

    // Constructor with integer value as parameter
    Integer(int n) {
        num = n;
        str = to_string(n);
    }

    // Constructor with string representation of integer value as parameter
    Integer(string s) {
        num = stoi(s);
        str = s;
    }

    // Method for setting integer value
    void set(int val) {
        num = val;
        str = to_string(val);
    }

    // Method for getting integer value
    int get() const {
        return num;
    }

    // Method for counting the number of bits in the binary representation of the integer value
    int bitCount() {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '1') {
                count++;
            }
        }
        return count;
    }

    // Method for comparing two Integer objects
    // Returns -1 if this object is less than obj, 0 if they are equal, and 1 if this object is greater than obj
    int compareTo(Integer obj) {
        if (num < obj.get()) {
            return -1;
        } else if (num > obj.get()) {
            return 1;
        } else {
            return 0;
        }
    }

    // Method for converting the integer value to a double
    double doubleValue() {
        return static_cast<double>(num);
    }

    // Method for converting the integer value to a float
    float floatValue() {
        return static_cast<float>(num);
    }

    // Method for adding two Integer objects and returning the result as a new Integer object
    Integer plus(const Integer obj) {
        return Integer(num + obj.get());
    }

    // Method for subtracting obj from this object and returning the result as a new Integer object
    Integer minus(const Integer obj) {
        return Integer(num - obj.get());
    }

    // Method for multiplying two Integer objects and returning the result as a new Integer object
    Integer multiply(const Integer obj) {
        return Integer(num * obj.get());
    }

    // Method for dividing this object by obj and returning the result as a new Integer object
    Integer divide(const Integer obj) {
        return Integer(num / obj.get());
    }

    // Static method for counting the number of leading zeros in the binary representation of an integer value
    static int numberOfLeadingZeros(int i) {
        int count = 0;
        while (i > 0) {
            count++;
            i >>= 1;
        }
        return 32 - count;
    }

    // Static method for counting the number of trailing zeros in the binary representation of an integer value
    static int numberOfTrailingZeros(int i) {
        int count = 0;
        while ((i & 1) == 0) {
            count++;
            i >>= 1;
        }
        return count;
    }

    // Static method for converting an integer value to a binary string representation
    static string toBinaryString(int i) {
        string res = "";
        while (i > 0) {
            if (i % 2 == 0) {
                res = "0" + res;
            } else {
                res = "1" + res;
            }
            i >>= 1;
        }
        return res;
    }

    // Static method for converting an integer value to a hexadecimal string representation
    static string toHexString(int i) {
        string hex_digits = "0123456789ABCDEF";
        string res = "";
        while (i > 0) {
            res = hex_digits[i % 16] + res;
            i /= 16;
        }
        return res;
    }
};
int main() {
    Integer a(42);
    Integer b("123");

    std::cout << "a = " << a.get() << std::endl;
    std::cout << "b = " << b.get() << std::endl;

    Integer c = a.plus(b);
    std::cout << "c = a + b = " << c.get() << std::endl;

    std::cout << "Number of leading zeros in 123: " << Integer::numberOfLeadingZeros(123) << std::endl;
    std::cout << "Binary representation of 42: " << Integer::toBinaryString(42) << std::endl;
    std::cout << "Hexadecimal representation of 123: " << Integer::toHexString(123) << std::endl;

    return 0;
}