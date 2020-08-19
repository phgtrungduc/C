#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#define BUFFER_SIZE  10          //s? lu?ng khoang ch?a

int buffer[BUFFER_SIZE];          //b? nh? d?m size 10 p.t? 
int in=0;                        //con tr? t?i v? tr� tr?ng k? ti?p
int out=0;                      //con tr? t?i v? tr� tr?ng ti?p theo

int nextProduced=1;    //t?o 1 s?n ph?m du?c s?n xu?t k? ti?p

//H�m s?n xu?t:
void Producer()
{
   while (1)
   {
      //Qu� tr�nh t?o ra 1 s?n ph?m
      // ... San xuat (nextProduced

      //v�ng l?p qu?n t?i d�y cho d?n khi c� 1 ch? tr?ng trong b? d?m hay ngan ch?a s?n ph?m
      while(((in+1)%BUFFER_SIZE)==out);

      //khi v�ng l?p while k?t th�c =>c� 1 ch? tr?ng d? ch�n s?n ph?m v�o
      buffer[in]=nextProduced++;      //ch�n s?n ph?m t?i v? tr� in v� ngan ch?a, s?n ph?m du?c s?n xu?t
      in=(in+1)%BUFFER_SIZE;       //t�m v? tr� kh�c d? Producer ch�n th�m s?n ph?m v�o

      //h�m SuspendThread d�ng d? t?o ngung 1 lu?ng hi?n h�nh
      SuspendThread(GetCurrentThread());
   }
}

//H�m ti�u th?:
void Consumer()
{
   int nextConsumed;
   while (1)
   {
      // v�ng l?p qu?n t?i d�y khi c�c ngan ch?a s?n ph?m d?u tr?ng
      while(in==out);

      //v�ng l?p while tho�t khi c� 1 ngan ch?a s?n ph?m
      nextConsumed=buffer[out];   //l?y s?n ph?m t?i v? tr� out ra kh?i ngan
      out=(out+1)%BUFFER_SIZE;   //t�m v? tr� kh�c d? Consumer l?y s?n ph?m

      // ... Tieu thu (nextConsumed)--> qu� tr�nh ti�u th? s�n ph?m

      //h�m Sleep dua lu?ng v�o tr?ng th�i ng? trong khi ch? Producer s?n xu?t th�m s?n ph?m
      //d?m s? mili gi�y trong gi? hi?n t?i % 5000, h?t th?i gian th?c hi?n while k? ti?p
      Sleep(GetTickCount()%5000);
   }
}

int main(){
   HANDLE ProducerHandle1, ProducerHandle2;//bi?n HANDLE ch?a m?c qu?n nh� s?n xu?t
   HANDLE ConsumerHandle1, ConsumerHandle2;// bi?n HANDLE ch?a m?c qu?n nh� ti�u th?

   DWORD ProducerID1, ProducerID2, ConsumerID1, ConsumerID2;//ch?a ID nh� s?n xu?t v� nh� ti�u th?
   
   //kh?i t?o nh� s?n xu?t v?i c�c th�ng tin: Producer, ID, s? 4 bi?u th? tr?ng th�i c?a Producer l�c kh?i t?o: tr?ng th�i ng?
   ProducerHandle1=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Producer,0,4,&ProducerID1);
   ProducerHandle2=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Producer,0,4,&ProducerID2);

   //kh?i t?o nh� ti�u th? v?i c�c th�ng tin: Consumer, ID, s? 0 bi?u th? tr?ng th�i c?a Producer l�c kh?i t?o: tr?ng th�i th?c
   ConsumerHandle1=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Consumer,0,0,&ConsumerID1);
   ConsumerHandle2=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Consumer,0,0,&ConsumerID2);

   while(1)
   {
      printf("\n- Nhan phim P/p de san xuat, nhan 0 de ket thuc:");
      switch (getch())
      {
         //nh?n ph�m P=Producing
         case 'P':
               // d�nh th?c Producer l�c n�y dang ? tr?ng th�i ng?
               ResumeThread(ProducerHandle1);
            break;
         //nh?n ph�m p=Producing
         case 'p':   ResumeThread(ProducerHandle2);      break;

         //gi?i ph�ng Producer v� Consumer kh?i b? nh?
         case '0':
         {
            CloseHandle(ProducerHandle1);
            CloseHandle(ProducerHandle2);
            CloseHandle(ConsumerHandle1);
            CloseHandle(ConsumerHandle2);
            return 0;

         }
      }
      //ng?ng 1 kho?ng th?i gian nh?t d?nh d? nh� s?n xu?t v?a du?c d�nh th?c k?p ho�n t?t 1 chu tr�nh c�ng vi?c 
      Sleep(1);

      //show k?t qu? sau khi s?n xu?t ti�u th?
      //ShowBuffer();
   }
}


