#include "factorial.h"

Factorial::Factorial() {}

Factorial::~Factorial() {}

int Factorial::computeFactorial(int n) {
  return (n < 1) ? 1 : computeFactorial(n-1) * n;
}