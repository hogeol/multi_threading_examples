#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* factorial(void* number); //factorial function ����Լ� -- thread �����Լ�
inline int factorialTmp(const int& number); //factorial ����Լ�
void* sum(void* number); //sum ����Լ� -- thread �����Լ�
inline int sumTmp(const int& number); //sum ����Լ�

int main(int argc, char** argv)
{
  int Minput = atoi(argv[1]);
  pthread_t pthread[Minput]; //�Է¹��� ���ڸ�ŭ thread ����
  int thr_id;
  int status;
  for (size_t thread_num = 0 ; thread_num < Minput ; thread_num++){
    if(thread_num == 0){
      thr_id = pthread_create(&pthread[thread_num],NULL,&factorial,(void*) &Minput); //factorial thread ���� 
      pthread_join(pthread[thread_num],(void**)& status);
      // printf("1st thread determined return value is %d\n", status);
    }
    else{
      thr_id = pthread_create(&pthread[thread_num],NULL,&sum,(void*) &Minput); //sum threads ����
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