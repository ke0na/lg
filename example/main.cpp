#include "Lg.h"

using namespace lg;

int main(int argc, char *argv[]) {
  // log out with no arguments
  out("No arguments log.\n");
  // log out single argument
  out("This is a test with one single argument. This is the number one --> "
      "{}.\n",
      1);
  // log out multiple arguments
  out("This is a test with multiple arguments. These are the numbers one "
      "(int), two dot two(float), three dot three(double) "
      "and the character 'c' --> {}, {}, {} and {}.\n",
      1, 2.2f, 3.3, 'c');
  // log out and add a new line
  outln("New line log:");
  out("I am on a new line.");
  return 0;
};
