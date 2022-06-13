#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sum(const int& number);

int main(int argc, char** argv)
{
  int Minput = atoi(argv[1]);
  pid_t Mpid = fork();
  int sum_of_number=sum(Minput);

  if(Mpid == 0) { //child process 실행
    printf("launch : start sumfact %d\n", Minput);
    execlp("./sumfact","sumfact",argv[1], NULL);
  }
  else
    printf("launch : sum = %d\n", sum_of_number); //parent process 실행
  return 0;
}

//parent process sum 계산함수
int sum(const int& number)
{
  int result = number;
  if(result == 0)
    return 0;
  return result + sum(result - 1);
}