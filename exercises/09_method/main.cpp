#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    Fibonacci() : cached(2) {
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < 128; ++i) {
            cache[i] = 0;  // 纭繚缂撳瓨涓殑鍏朵粬浣嶇疆琚垵濮嬪寲
        }
    }
    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        if(i<cached)return cache[i];
        for (; cached<=i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
