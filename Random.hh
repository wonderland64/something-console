#ifndef GUARD_Random_hh
#define GUARD_Random_hh

#include <random>
#include <chrono>

class Random {
public:
    Random() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        stdRand = std::default_random_engine(seed);
    }
    template<class T>
    T next(const T& min, const T& max) {
        auto rand = std::uniform_int_distribution<T>(min, max - 1);
        return rand(stdRand);
    }
    template<class T>
    T nextDouble(const T& min, const T& max) {
        auto rand = std::uniform_real_distribution<T>(min, max);
        return rand(stdRand);
    }

private:
    std::default_random_engine stdRand;
};

#endif
