// Online C compiler to run C program online
#include <stdio.h>
struct Sample{
  int a;
  float b;
  char c;
}sample;

union Sample4{
  int a;
  float b;
  char c;
}sample4;

struct Sample2{
  int a;
  float b;
  char c;
}__attribute__((packed));
struct Sample2 sample2;

#pragma pack(1)
struct Sample3{
  int a;
  float b;
  char c;
}sample3;

int main() {
    // Write C code here
    printf("%d\n", sizeof(sample));
    printf("%d\n", sizeof(sample2));
    printf("%d\n", sizeof(sample3));
    printf("%d\n", sizeof(sample4));

    return 0;
}
