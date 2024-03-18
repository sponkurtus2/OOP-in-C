#include <stdio.h>
#include <stdlib.h>

struct laptop {
  /*Abstraction
   * Here we define the attributes of our class (struct)
   */
  float price;
  char *name;

  void (*setPrice)(struct laptop *, float);
  float (*getPrice)(struct laptop *);

  void (*setName)(struct laptop *, char *);
  char *(*getName)(struct laptop *);

  void (*addDiscount)(struct laptop *, float);
};

/* Abstraction
 * And because C isn't OOP, we define the functions manually, in this case,
 * these are the setters/getters
 */
void setPrice(struct laptop *lap, float lapPrice) { lap->price = lapPrice; }

float getPrice(struct laptop *lap) { return lap->price; }

void setName(struct laptop *lap, char *lapName) { lap->name = lapName; }

char *getName(struct laptop *lap) { return lap->name; }

// Function to add disccount
void addDiscount(struct laptop *lap, float discount) {
  float newPrice = (lap->price * discount) / 100;
  lap->price = lap->price - newPrice;
}

int main() {
  struct laptop myLap;
  myLap.getPrice = getPrice;
  myLap.setPrice = setPrice;
  myLap.addDiscount = addDiscount;

  myLap.setName = setName;
  myLap.getName = getName;

  myLap.setPrice(&myLap, 190);
  myLap.setName(&myLap, "Huawei");

  printf("Laptop name: %s\n", myLap.getName(&myLap));
  printf("Laptop price: %e\n", myLap.getPrice(&myLap));

  // myLap.addDiscount(&myLap, 30);
  myLap.addDiscount(&myLap, 25);

  printf("Laptop price after discount: %0.2fl\n", myLap.getPrice(&myLap));
  return 0;
}
