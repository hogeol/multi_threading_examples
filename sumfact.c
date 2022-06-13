#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* factorial(void* number); //factorial function 출력함수 -- thread 실행함수
inline int factorialTmp(const int& number); //factorial 계산함수
void* sum(void* number); //sum 출력함수 -- thread 실행함수
inline int sumTmp(const int& number); //sum 계산함수

int main(int argc, char** argv)
{
  int Minput = atoi(argv[1]);
  pthread_t pthread[Minput]; //입력받은 인자만큼 thread 생성
  int thr_id;
  int status;
  for (size_t thread_num = 0 ; thread_num < Minput ; thread_num++){
    if(thread_num == 0){
      thr_id = pthread_create(&pthread[thread_num],NULL,&factorial,(void*) &Minput); //factorial thread 실행 
      pthread_join(pthread[thread_num],(void**)& status);
      // printf("1st thread determined return value is %d\n", status);
    }
    else{
      thr_id = pthread_create(&pthread[thread_num],NULL,&sum,(void*) &Minput); //sum threads 실행
      pthread_join(pthread[thread_num],(void**)& status);
      // printf("%d thread determined return value is %d\n", thread_num+1, status);
    }
  }

  return 0;
}

void* factorial(void* number)
{
  int num = *((int*)number);
  num = factorialTmp(num);
  printf("sumfact : factorial = %d\n", num);
}

inline int factorialTmp(const int& number)
{
  int result = number;
  if(result == 0)
    return 1;
  else
    return (result) * factorialTmp(result - 1);
}

void* sum(void* number)
{
  int num = *((int*)number);
  num = sumTmp(num);
  printf("sumfact : sum = %d\n", num);
}

inline int sumTmp(const int& number)
{ 
  int result = number;
  if(result == 0)
    return 0;
  return (result) + sumTmp(result - 1);
}