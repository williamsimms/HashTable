#ifndef UTIL_H
#define UTIL_H
#include <cmath>

int RoundUp(int numToRound, int multiple) {
  if (multiple == 0) {
    return numToRound;
  }

  int remainder = abs(numToRound) % multiple;

  if (remainder == 0) {
    return numToRound;
  }

  if (numToRound < 0) {
    return -(abs(numToRound) - remainder);
  } else {
    return numToRound + multiple - remainder;
  }
}

#endif