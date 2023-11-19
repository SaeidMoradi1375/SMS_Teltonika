#include <stdio.h>
#include <stdint.h>
#include "stdlib.h"
#include "str.h"

uint8_t rxBuf1[64];
uint8_t txBuf1[512];
uint8_t LineBuffer[64];

struct _TEL;
typedef struct _TEL TEL;
TEL tel1;
typedef void (*Teltonika_CallbackFn)(uint32_t Num , char* Str );

typedef union {
    Teltonika_CallbackFn callbacks[1];
    struct {
        Teltonika_CallbackFn callback;
    };
} Teltonika_Callbacks;

struct _TEL {
    Teltonika_Callbacks Callbacks;
};
int countSemicolons(char *str);
void Teltonika_callback(TEL* tel, Teltonika_CallbackFn cb) ;


void User_callback(uint32_t Num , char* Str);

void receive(TEL *tel, uint8_t *Buffer, uint8_t i);

void main(void){
    Teltonika_callback(&tel1 , User_callback);

uint8_t Buff[] = "New value 2001:internet;2002:internet1;2003:internet2;2004:avl2.teltonika.lt;2005:12050:2006:0;2002:internet1;2003:internet2;";
uint8_t i = countSemicolons(Buff);
receive(&tel1 ,Buff , i );
while(1){

}
}

void receive(TEL *tel, uint8_t *Buffer , uint8_t i ) {
    //first
    uint32_t Num = 0;
    char* Str = 0;
    uint8_t j =0;
    char *p0 = Str_indexOf((char *) Buffer+5, ' ');
    char* p1 = Str_indexOf(p0 + 1, ':');
    *p1 = NULL;
    p0++;
    Str_convertUNum(p0, &Num, Str_Decimal);
    p0                 = p1;
    p1                 = Str_indexOf(p0 + 1, ';');
    *p1                = NULL;
    p0++;
    Str= (char*)p0;
    if (tel->Callbacks.callback != NULL) {
        tel->Callbacks.callback(Num ,Str );
    }
    //loop
    for (j =0 ; j<i-1 ; j++){
    p0                 = p1;
    p1                 = Str_indexOf(p0 + 1, ':');
    *p1                = NULL;
    p0++;
    Str_convertUNum(p0, &Num, Str_Decimal);
    p0                 = p1;
    p1                 = Str_indexOf(p0 + 1, ';');
    *p1                = NULL;
    p0++;
    Str= (char*)p0;
    if (tel->Callbacks.callback != NULL) {
        tel->Callbacks.callback(Num ,Str );
    }
    }
//end
    p0                 = p1;
    p1                 = Str_indexOf(p0 + 1, ':');
    *p1                = NULL;
    p0++;
    Str_convertUNum(p0, &Num, Str_Decimal);
    p0                 = p1;
    p1                 = Str_indexOf(p0 + 1, "NULL");
    *p1                = NULL;
    p0++;
    Str= (char*)p0;
    if (tel->Callbacks.callback != NULL) {
        tel->Callbacks.callback(Num ,Str );
    }
}

void Teltonika_callback(TEL* tel, Teltonika_CallbackFn cb) {
    tel->Callbacks.callback = cb;
}

void User_callback(uint32_t Num , char* Str){
    printf("%d , %s\n" , Num , Str);
}

int countSemicolons(char *str) {
    int count = 0;

    while (*str != '\0') {
        if (*str == ';') {
            count++;
        }
        str++;
    }
    return count;
}
