#include<windows.h>
#include<conio.h>
#include<stdio.h>
 
#define buffer_size 10
int in=0, counter=0,out=0,NextProduced=1,NextConsumed;
int buffer[buffer_size];   //size buffer  khoi tao bang 10
void producer()//tao ham producer, khi khoi tao luong producer se tro den ham nay
     {
               while(1){
                        while(counter==buffer_size);
                        buffer[in]=NextProduced;
                        printf("\n san pham thu %d dua vao la:%d",in,buffer[in]);
                        NextProduced++;
                        in = (in +1)%buffer_size;
                        counter++;
                        Sleep(100);
                        }
     }
void consumer()
     {
               while(1){
                       
                        while(counter==0);
                        NextConsumed=buffer[out];
                        printf("\n san pham thu %d lay ra la:%d",out,NextConsumed);
                        out=(out+1)% buffer_size;
                        counter--;
                        Sleep(20);
                        }
     }      
main()
      {
             HANDLE Producer;
             DWORD idp;
             Producer=CreateThread(0,0, (LPTHREAD_START_ROUTINE)producer,0, CREATE_SUSPENDED, &idp);                              
             HANDLE Consumer;
             DWORD idc;
             Consumer=CreateThread(0,0, (LPTHREAD_START_ROUTINE)consumer,0, CREATE_SUSPENDED, &idc);
             printf("\n nhan s de luong thuc hien");
             printf("\n nhan e de dung thuc hien");
             switch(getch())
                            {
                                  case 's':
                                       {
                                           ResumeThread(Producer);
                                           ResumeThread(Consumer);
                                           break;
                                       }
                                       
                                  case 'e':
                                       {
                                           CloseHandle(Producer);
                                           CloseHandle(Consumer);
                                            break;
                                       }
                                      
                            }
             
             getch();
             }
