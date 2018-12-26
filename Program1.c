/*#ifndef __AES_NI_H__
#define __AES_NI_H__
*/
#include<stdio.h>
#include <stdint.h>     //for int8_t
#include <string.h>     //for memcmp
#include <wmmintrin.h>  //for intrinsics for AES-NI
//compile using gcc and following arguments: -g;-O0;-Wall;-msse2;-msse;-march=native;-maes

void encrypt(uint8_t *plainText, //pointer to the PLAINTEXT
    uint8_t *cipherText, //pointer to the CIPHERTEXT buffer
    __m128i *key_schedule) //pointer to the expanded key schedule
{
    __m128i tmp;
    int i,j;
    for(i=0;i<16;i++)
    {
        tmp = _mm_loadu_si128((__m128i*)plainText);
        tmp = _mm_xor_si128(tmp, ((__m128i*)key_schedule)[0]);
        for (j = 1; j <10; j++)
        {
            tmp = _mm_aesenc_si128(tmp, ((__m128i*)key_schedule)[j]);
        }
        tmp = _mm_aesenclast_si128(tmp, ((__m128i*)key_schedule)[j]);
        _mm_storeu_si128((((__m128i*)cipherText)), tmp);
    }
}

void Key_Expansion (uint8_t *userkey,__m128i *key)
 {
 __m128i temp1, temp2;
 __m128i *Key_Schedule = (__m128i*)key;

 temp1 = _mm_loadu_si128((__m128i*)userkey);
 Key_Schedule[0] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1 ,0x1);
  __m128i temp3;
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
 Key_Schedule[1] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x2);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
 Key_Schedule[2] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x4);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
 Key_Schedule[3] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x8);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
 Key_Schedule[4] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x10);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
  Key_Schedule[5] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x20);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2); 
 Key_Schedule[6] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x40);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
 Key_Schedule[7] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x80);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
Key_Schedule[8] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x1b);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
 Key_Schedule[9] = temp1;
 temp2 = _mm_aeskeygenassist_si128 (temp1,0x36);
 temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
 temp3 = _mm_slli_si128 (temp1, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp3 = _mm_slli_si128 (temp3, 0x4);
 temp1 = _mm_xor_si128 (temp1, temp3);
 temp1 = _mm_xor_si128 (temp1, temp2);
  Key_Schedule[10] = temp1;
 } 


int main(){

    uint8_t plain[]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    uint8_t key[]    = {0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10};
    uint8_t computed_cipher[16];
    __m128i key_schedule[16];
    //empty_key[16];
    int i;
    Key_Expansion (key,key_schedule);
    encrypt(plain,computed_cipher,key_schedule);
    printf("testing line!! ---plz ignore \n\n ");

    //part of the program reqd for computing time of 1000 block cipher encryption.
    int counter=0;
    for(i=0;i<1000;i++)
    {
        encrypt(plain,computed_cipher,key_schedule);
        printf("%d,",counter);
        counter ++;
    }
    for(i=0; i < 16; i++)
    {
        printf("%x  ",computed_cipher[i]);
    }



 return 0;

}

