#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <iostream>

/*
  Tests cache misses.
*/

void option1(long * data, int m, int n);
void option2(long * data, int m, int n);
void option3(long * data, int m, int n);

int main(int argc, char **argv)
{
  if (argc < 3){
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]);
  long sJ = atoi(argv[2]);

  printf("Operating on matrix of size %ld by %ld\n", sI, sJ);

  long *arr = new long[sI*sJ]; // double array.

  std::chrono::steady_clock::time_point start, end;
  std::chrono::duration<double> dif;
  // auto start = std::chrono::steady_clock::now()

  // option 1
  start = std::chrono::steady_clock::now();
  option1(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  dif = end - start;
  std::cout << dif.count() << "\n";
      
  // option 2
  start = std::chrono::steady_clock::now();
  option2(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  dif = end - start;
  std::cout << dif.count() << "\n";

  // option 3
  start = std::chrono::steady_clock::now();
  option3(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  dif = end - start;
  std::cout << dif.count() << "\n";

  // why this?
  printf("%ld\n", arr[0]);

  // free memory
  delete [] arr; 

  return 0;
}

void option1(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(i * (n)) + j ] = i;
}

void option2(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(j * (m)) + i ] = i;
}

void option3(long * data, int m, int n)
{
  for (int i=0; i < m*n; ++i) data[i] = i;
}