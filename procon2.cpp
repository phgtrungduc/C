#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#define BUFFER_SIZE  10          //s? lu?ng khoang ch?a

int buffer[BUFFER_SIZE];          //b? nh? d?m size 10 p.t? 
int in=0;                        //con tr? t?i v? trí tr?ng k? ti?p
int out=0;                      //con tr? t?i v? trí tr?ng ti?p theo

int nextProduced=1;    //t?o 1 s?n ph?m du?c s?n xu?t k? ti?p

//Hàm s?n xu?t:
void Producer()
{
   while (1)
   {
      //Quá trình t?o ra 1 s?n ph?m
      // ... San xuat (nextProduced

      //vòng l?p qu?n t?i dây cho d?n khi có 1 ch? tr?ng trong b? d?m hay ngan ch?a s?n ph?m
      while(((in+1)%BUFFER_SIZE)==out);

      //khi vòng l?p while k?t thúc =>có 1 ch? tr?ng d? chèn s?n ph?m vào
      buffer[in]=nextProduced++;      //chèn s?n ph?m t?i v? trí in vô ngan ch?a, s?n ph?m du?c s?n xu?t
      in=(in+1)%BUFFER_SIZE;       //tìm v? trí khác d? Producer chèn thêm s?n ph?m vào

      //hàm SuspendThread dùng d? t?o ngung 1 lu?ng hi?n hành
      SuspendThread(GetCurrentThread());
   }
}

//Hàm tiêu th?:
void Consumer()
{
   int nextConsumed;
   while (1)
   {
      // vòng l?p qu?n t?i dây khi các ngan ch?a s?n ph?m d?u tr?ng
      while(in==out);

      //vòng l?p while thoát khi có 1 ngan ch?a s?n ph?m
      nextConsumed=buffer[out];   //l?y s?n ph?m t?i v? trí out ra kh?i ngan
      out=(out+1)%BUFFER_SIZE;   //tìm v? trí khác d? Consumer l?y s?n ph?m

      // ... Tieu thu (nextConsumed)--> quá trình tiêu th? sàn ph?m

      //hàm Sleep dua lu?ng vào tr?ng thái ng? trong khi ch? Producer s?n xu?t thêm s?n ph?m
      //d?m s? mili giây trong gi? hi?n t?i % 5000, h?t th?i gian th?c hi?n while k? ti?p
      Sleep(GetTickCount()%5000);
   }
}

int main(){
   HANDLE ProducerHandle1, ProducerHandle2;//bi?n HANDLE ch?a m?c qu?n nhà s?n xu?t
   HANDLE ConsumerHandle1, ConsumerHandle2;// bi?n HANDLE ch?a m?c qu?n nhà tiêu th?

   DWORD ProducerID1, ProducerID2, ConsumerID1, ConsumerID2;//ch?a ID nhà s?n xu?t và nhà tiêu th?
   
   //kh?i t?o nhà s?n xu?t v?i các thông tin: Producer, ID, s? 4 bi?u th? tr?ng thái c?a Producer lúc kh?i t?o: tr?ng thái ng?
   ProducerHandle1=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Producer,0,4,&ProducerID1);
   ProducerHandle2=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Producer,0,4,&ProducerID2);

   //kh?i t?o nhà tiêu th? v?i các thông tin: Consumer, ID, s? 0 bi?u th? tr?ng thái c?a Producer lúc kh?i t?o: tr?ng thái th?c
   ConsumerHandle1=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Consumer,0,0,&ConsumerID1);
   ConsumerHandle2=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Consumer,0,0,&ConsumerID2);

   while(1)
   {
      printf("\n- Nhan phim P/p de san xuat, nhan 0 de ket thuc:");
      switch (getch())
      {
         //nh?n phím P=Producing
         case 'P':
               // dánh th?c Producer lúc này dang ? tr?ng thái ng?
               ResumeThread(ProducerHandle1);
            break;
         //nh?n phím p=Producing
         case 'p':   ResumeThread(ProducerHandle2);      break;

         //gi?i phóng Producer và Consumer kh?i b? nh?
         case '0':
         {
            CloseHandle(ProducerHandle1);
            CloseHandle(ProducerHandle2);
            CloseHandle(ConsumerHandle1);
            CloseHandle(ConsumerHandle2);
            return 0;

         }
      }
      //ng?ng 1 kho?ng th?i gian nh?t d?nh d? nhà s?n xu?t v?a du?c dánh th?c k?p hoàn t?t 1 chu trình công vi?c 
      Sleep(1);

      //show k?t qu? sau khi s?n xu?t tiêu th?
      //ShowBuffer();
   }
}


