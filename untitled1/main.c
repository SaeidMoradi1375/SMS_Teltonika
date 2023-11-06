#include <stdio.h>
#include <stdint.h>

#include "arduino.h"
//#include "stdlib.h"
#include "Str.h"

//uint8_t LineBuffer[64];

//struct _TEL;
//typedef struct _TEL TEL;
//TEL tel1;
//typedef void (*Teltonika_CallbackFn)(uint32_t Num , char* Str );
//
//typedef union {
//    Teltonika_CallbackFn callbacks[2];
//    struct {
//        Teltonika_CallbackFn onFirst;
//        Teltonika_CallbackFn onSec;
//    };
//} Teltonika_Callbacks;
//
//struct _TEL {
//    Teltonika_Callbacks Callbacks;
//};
//
//void Teltonika_onFirst(TEL* tel, Teltonika_CallbackFn cb) ;
//void Teltonika_onSec(TEL* tel, Teltonika_CallbackFn cb) ;
//
//void User_onFirst(uint32_t Num , char* Str);
//void User_onSec(uint32_t Num , char* Str);
//
//void telton(uint8_t val, uint8_t *str);
//void receive(TEL *tel, uint8_t *Buffer);
//
//uint8_t Buff[128] = "  setparam 2001:internet;2002:internet1;2003:internet2:2004:avl2.teltonika.lt2005:12050:2006:0";

void setup() {
    millis(); // reference it from now
    setbuf(stdout, NULL); // Disable buffering for stdout
//    bool ret = UARTStream_init(
//            &uart1, "127.0.0.1", 8888, "COM16",
//            rxBuf1, sizeof(rxBuf1),
//            txBuf1, sizeof(txBuf1));
//    if (ret == false) {
//        printf("ret == false");
//        exit(0);
//    Teltonika_onFirst(&tel1 , User_onFirst);
//    receive(&tel1 , Buff );
}

void loop() {
printf("123\r\n");
}

//void receive(TEL *tel, uint8_t *Buffer) {
//    char *p0 = Str_indexOf((char *) Buffer+2, ' ');
//    char*    p1          = Str_indexOf(p0 + 1, ':');
//    *p1                 =0;
//    p0++;
//    uint32_t firstNum = 0;
//    char* firstStr = 0;
//    Str_convertUNum(p0, &firstNum, Str_Decimal);
//    p0                 = p1;
//    p1                 = Str_indexOf(p0 + 1, ';');
//    *p1                = 0;
//    p0++;
//    firstStr= (char*)p0;
//    if (tel->Callbacks.onFirst != NULL) {
//        tel->Callbacks.onFirst(firstNum , firstStr );
//    }
//    p0                 = p1;
//    p1                 = Str_indexOf(p0 + 1, ':');
//    *p1                = 0;
//    p0++;
//    uint32_t SectNum = 0;
//    char* SecStr = 0;
//    Str_convertUNum(p0, &SectNum, Str_Decimal);
//    p0                 = p1;
//    p1                 = Str_indexOf(p0 + 1, ';');
//    *p1                = 0;
//    p0++;
//    SecStr= (char*)p0;
//    if (tel->Callbacks.onSec != NULL) {
//        tel->Callbacks.onSec(firstNum , SecStr );
//    }
//}
//
//void Teltonika_onFirst(TEL* tel, Teltonika_CallbackFn cb) {
//    tel->Callbacks.onFirst = cb;
//}
//
//void Teltonika_onSec(TEL* tel, Teltonika_CallbackFn cb) {
//    tel->Callbacks.onFirst = cb;
//}
//
//void User_onFirst(uint32_t Num , char* Str){
//    printf("%d , %s" , Num , Str);
//}
//
//void User_onSec(uint32_t Num , char* Str){
//    printf("%d , %s" , Num , Str);
//}