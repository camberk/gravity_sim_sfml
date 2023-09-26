#ifndef RNG_H
#define RNG_H

#pragma once

#include <random>

class Rng {
public:
    Rng(int distMax);
    int getRandomNumber();

private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
};

#endif