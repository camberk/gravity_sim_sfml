#include "Rng.h"

Rng::Rng(int distMax) : generator(std::random_device()()), distribution(1, distMax) {}

int Rng::getRandomNumber() {
    return distribution(generator);
}