/**************************************************************************//**
 * @file     core_cm4_simd.h
 * @brief    CMSIS Cortex-M4 SIMD Header File
 * @version  V2.10
 * @date     19. July 2011
 *
 * @note
 * Copyright (C) 2010-2011 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __CORE_CM4_SIMD_H
#define __CORE_CM4_SIMD_H


/*******************************************************************************
 *                Hardware Abstraction Layer
 ******************************************************************************/


/* ###################  Compiler specific Intrinsics  ########################### */
/** \defgroup CMSIS_SIMD_intrinsics CMSIS SIMD Intrinsics
  Access to dedicated SIMD instructions
  @{
*/

#if   defined ( __CC_ARM ) /*------------------RealView Compiler -----------------*/
/* ARM armcc specific functions */

/*------ CM4 SOMD Intrinsics -----------------------------------------------------*/
#define __SADD8                           __sadd8
#define __QADD8                           __qadd8
#define __SHADD8                          __shadd8
#define __UADD8                           __uadd8
#define __UQADD8                          __uqadd8
#define __UHADD8                          __uhadd8
#define __SSUB8                           __ssub8
#define __QSUB8                           __qsub8
#define __SHSUB8                          __shsub8
#define __USUB8                           __usub8
#define __UQSUB8                          __uqsub8
#define __UHSUB8                          __uhsub8
#define __SADD16                          __sadd16
#define __QADD16                          __qadd16
#define __SHADD16                         __shadd16
#define __UADD16                          __uadd16
#define __UQADD16                         __uqadd16
#define __UHADD16                         __uhadd16
#define __SSUB16                          __ssub16
#define __QSUB16                          __qsub16
#define __SHSUB16                         __shsub16
#define __USUB16                          __usub16
#define __UQSUB16                         __uqsub16
#define __UHSUB16                         __uhsub16
#define __SASX                            __sasx
#define __QASX                            __qasx
#define __SHASX                           __shasx
#define __UASX                            __uasx
#define __UQASX                           __uqasx
#define __UHASX                           __uhasx
#define __SSAX                            __ssax
#define __QSAX                            __qsax
#define __SHSAX                           __shsax
#define __USAX                            __usax
#define __UQSAX                           __uqsax
#define __UHSAX                           __uhsax
#define __USAD8                           __usad8
#define __USADA8                          __usada8
#define __SSAT16                          __ssat16
#define __USAT16                          __usat16
#define __UXTB16                          __uxtb16
#define __UXTAB16                         __uxtab16
#define __SXTB16                          __sxtb16
#define __SXTAB16                         __sxtab16
#define __SMUAD                           __smuad
#define __SMUADX                          __smuadx
#define __SMLAD        ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �ZP�      InstallTimeHigh ����vk   ��    c InstallTimeLow. ����vk    �NQ    h InstallUser e 2 ����S - 1 - 5 - 1 8    ����nk  ��ZP�    xKQ        ��������   �OQ�d�����  �     �             Owners  ����vkW   �p        Microsoft-Windows-Client-Optional-Features-Package~31bf3856ad364e35~amd64~~10.0.14393.0 ����8OQ����lh �NQ"|P PQ�p����vk   �         SNMPe �����OQ����hTQ�����XQhbin PQ                       ����nk  �o]�    xKQ        ��������   �OQ�d�����  �                  Updates X���nk  AkU�[P�    X�'       �TQ����	   �QQ�d����� �        �       W   Microsoft-Windows-Spelling-Dictionaries-zh-Package~31bf3856ad364e35~amd64~~10.0.14393.0 ����vk 0   HQQ      InstallClient   ����P u s h   B u t t o n   R e s e t   -   F o D       ���� QQ�QQ�RQSQ0SQXSQ�SQ�SQ�SQ����vk �   �QQ      InstallName     @���M i c r o s o f t - W i n d o w s - S p e l l i n g - D i c t i o n a r i e s - z h - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m       ����vk F   �RQ      InstallLocation ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �[P�      InstallTimeHigh ����vk   �AkU�      InstallTimeLow  ����vk    �SQ      InstallUser     ����S - 1 - 5 - 1 8   �����nk  h�RZP�    xPQ        ��������   �OQ�d�����  �     �             Owners  ����vk[   �p        Microsoft-Windows-LanguageFeatures-Basic-zh-cn-Package~31bf3856ad364e35~amd64~~10.0.14393.0     ����lh TQ"|P`���nk  ]�PZP�    X�'       8YQ����	   �UQ�d����� �        �       O   Microsoft-Windows-SPP-Core-ds-Package~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0 ����vk :   �UQ      InstallClient   ����P u s h   B u t t o n   R e s e t   -   L a n g u a g e     �����UQ VQ�VQpWQ�WQ�WQ�WQXQ8XQ����vk �   HVQ      InstallName     P���M i c r o s o f t - W i n d o w s - S P P - C o r e - d s - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ z h - C N ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m       ����vk F    WQ      InstallLocation ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �ZP�      InstallTimeHigh ����vk   �]�P      InstallTimeLow  ����vk    `XQ      InstallUser     ����S - 1 - 5 - 1 8   C����nk  |O{-ZP�    �TQ        ��������   �OQ�d�����  �     �             Owners  ����vkL   �p        Microsoft-Windows-SPP-Core-Package~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0    ����lh xXQ"|P`���nk  i��ZP�    X�'       �]Q����	   PZQ�d����� �        �       J   Microsoft-Windows-SPP-Core-ds-Package~31bf3856ad364e35~amd64~~10.0.14393.0      ����vk 8   ZQ      InstallClient   ����P u s h   B u t t o n   R e s e t   -   E d i t i o n       �����YQxZQH[Q�[Q�[Q\Q8\Q`\Q�\Q����vk �   �ZQ      InstallName     X���M i c r o s o f t - W i n d o w s - S P P - C o r e - d s - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m         ����vk F   p[Q      InstallLocation ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �ZP�    b InstallTimeHigh ����vk   �i��      InstallTimeLow  ����vk    �\Q    g InstallUser�    ����S - 1 - 5 - 1 8    ����nk  ��ZP�    HYQ        ��������   �]Q�d�����  �     �             Owners  ����vkG   �p        Microsoft-Windows-SPP-Core-Package~31bf3856ad364e35~amd64~~10.0.14393.0 ���� ]Q����lh �\Q"|PP���nk  ]�PZP�    X�'       8bQ����	   �^Q�d����� �        �       ]   Microsoft-Windows-SPP-Core-mergedcomponents-Package~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0   ����vk :   p^Q      InstallClient   ����P u s h   B u t t o n   R e s e t   -   L a n g u a g e     ����H^Q�^Q�_Qp`Q�`Q�`Q�`QaQ8aQ����vk �    _Q      InstallName     8���M i c r o s o f t - W i n d o w s - S P P - C o r e - m e r g e d c o m p o n e n t s - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ z h - C N ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m   ����vk F    `Q      InstallLocation �����aQ����@fQhbin `Q                       ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �ZP�      InstallTimeHigh ����vk   �]�P      InstallTimeLow  ����vk    `aQ      InstallUser     ����S - 1 - 5 - 1 8   C����nk  |O{-ZP�    �]Q        ��������   �_Q�d�����  �     �             Owners  ����vkL   �p        Microsoft-Windows-SPP-Core-Package~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0    ����lh xaQ"|PX���nk  i��ZP�    X�'       �fQ����	   XcQ�d����� �        �       X   Microsoft-Windows-SPP-Core-mergedcomponents-Package~31bf3856ad364e35~amd64~~10.0.14393.0����vk 8   cQ      InstallClient   ����P u s h   B u t t o n   R e s e t   -   E d i t i o n       �����bQ�cQhdQ�dQeQ0eQXeQ�eQ�eQ����vk �   �cQ      InstallName     @���M i c r o s o f t - W i n d o w s - S P P - C o r e - m e r g e d c o m p o n e n t s - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m     ����vk F   �dQ      InstallLocation ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �ZP�      InstallTimeHigh ����vk   �i��     InstallTimeLow������vk    �eQ      InstallUserntity����S - 1 - 5 - 1 8    ����nk  ��ZP�    HbQ        ��������   �_Q�d�����  �     �             Owners  ����vkG   �p        Microsoft-Windows-SPP-Core-Package~31bf3856ad364e35~amd64~~10.0.14393.0 ����lh �eQ"|PX���nk  ]�PZP�    X�'       kQ����	   �gQ�d����� �        �       T   Microsoft-Windows-SPP-Core-onecore-Package~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0    ����vk :   �gQ      InstallClient   ����P u s h   B u t t o n   R e s e t   -   L a n g u a g e     ����XgQ�gQ�hQ@iQhiQ�iQ�iQ�iQjQ����vk �   hQ      InstallName     H���M i c r o s o f t - W i n d o w s - S P P - C o r e - o n e c o r e - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ z h - C N ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m     ����vk F   �hQ      InstallLocation ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �ZP�      InstallTimeHigh ����vk   �]�P      InstallTimeLow  ����vk    0jQ      InstallUser     ����S - 1 - 5 - 1 8   C����nk  |O{-ZP�    �fQ        ��������   kQ�d�����  �     �             Owners  ����vkL   �p        Microsoft-Windows-SPP-Core-Package~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0    �����jQ����lh HjQ"|P`���nk  i��ZP�    X�'       hoQ����	   (lQ�d����� �        �       O   Microsoft-Windows-SPP-Core-onecore-Package~31bf3856ad364e35~amd64~~10.0.14393.0 ����vk 8   �kQ      InstallClient   ����P u s h   B u t t o n   R e s e t   -   E d i t i o n       �����kQPlQ(mQ�mQ�mQ�mQnQ@nQhnQ����vk �   xlQ      InstallName     P���M i c r o s o f t - W i n d o w s - S P P - C o r e - o n e c o r e - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m       ����vk F   PmQ      InstallLocation ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
 nt32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uqadd16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UHADD16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uhadd16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SSUB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("ssub16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __QSUB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("qsub16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SHSUB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("shsub16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __USUB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("usub16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UQSUB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uqsub16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UHSUB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uhsub16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SASX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("sasx %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __QASX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("qasx %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SHASX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("shasx %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UASX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uasx %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UQASX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uqasx %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UHASX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uhasx %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SSAX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("ssax %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __QSAX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("qsax %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SHSAX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("shsax %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __USAX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("usax %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UQSAX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uqsax %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UHSAX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uhsax %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __USAD8(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("usad8 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __USADA8(uint32_t op1, uint32_t op2, uint32_t op3)
{
    uint32_t result;
    __ASM volatile("usada8 %0, %1, %2, %3" : "=r"(result) : "r"(op1), "r"(op2), "r"(op3));
    return (result);
}

#define __SSAT16(ARG1,ARG2) \
    ({                          \
        uint32_t __RES, __ARG1 = (ARG1); \
        __ASM ("ssat16 %0, %1, %2" : "=r" (__RES) :  "I" (ARG2), "r" (__ARG1) ); \
        __RES; \
    })

#define __USAT16(ARG1,ARG2) \
    ({                          \
        uint32_t __RES, __ARG1 = (ARG1); \
        __ASM ("usat16 %0, %1, %2" : "=r" (__RES) :  "I" (ARG2), "r" (__ARG1) ); \
        __RES; \
    })

__attribute__((always_inline)) static __INLINE uint32_t __UXTB16(uint32_t op1)
{
    uint32_t result;
    __ASM volatile("uxtb16 %0, %1" : "=r"(result) : "r"(op1));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __UXTAB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("uxtab16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SXTB16(uint32_t op1)
{
    uint32_t result;
    __ASM volatile("sxtb16 %0, %1" : "=r"(result) : "r"(op1));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SXTAB16(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("sxtab16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SMUAD(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("smuad %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SMUADX(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("smuadx %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SMLAD(uint32_t op1, uint32_t op2, uint32_t op3)
{
    uint32_t result;
    __ASM volatile("smlad %0, %1, %2, %3" : "=r"(result) : "r"(op1), "r"(op2), "r"(op3));
    return (result);
}

__attribute__((always_inline)) static __INLINE uint32_t __SMLADX(uint32_t op1, uint32_t op2, uint32_t op3)
{
    uint32_t result;
    __ASM volatile("smladx %0, %1, %2, %3" : "=r"(result) : "r"(op1), "r"(op2), "r"(op3));
    return (result);
}

#define __SMLALD(ARG1,ARG2,ARG3) \
    ({ \
        uint32_t __ARG1 = (ARG1), __ARG2 = (ARG2), __ARG3_H = (uint32_t)((uint64_t)(ARG3) >> 32), __ARG3_L = (uint32_t)((uint64_t)(ARG3) & 0xFFFFFFFFUL); \
        __ASM volatile ("smlald %0, %1, %2, %3" : "=r" (__ARG3_L), "=r" (__ARG3_H) : "r" (__ARG1), "r" (__ARG2), "0" (__ARG3_L), "1" (__ARG3_H) ); \
        (uint64_t)(((uint64_t)__ARG3_H << 32) | __ARG3_L); \
    })

#define __SMLALDX(ARG1,ARG2,ARG3) \
    ({ \
        uint32_t __ARG1 = (ARG1), __ARG2 = (ARG2), __ARG3_H = (uint32_t)((uint64_t)(ARG3) >> 32), __ARG3_L = (uint32_t)((uint64_t)(ARG3) & 0xFFFFFFFFUL); \
        __ASM volatile ("smlaldx %0, %1, %2, %3" : "=r" (__ARG3_L), "=r" (__ARG3_H) : "r" (__ARG1), "r" (__ARG2), "0" (__ARG3_L), "1" (__ARG3_H) ); \
        (uint64_t)(((uint64_t)__ARG3_H << 32) | __ARG3_L); \
    })

__attribute__((always_inline)) static __INLINE uint32_t __SMUSD(uint32_t op1, uint32_t op2)
{
    uint32_t result;
    __ASM volatile("smusd %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
    return (result);
}

__attribute__((always_8cT)���gT,�L�lT�<~I�pTr;���tT�=��@yT���q�}T��L0�T�5Ԙ�T�˥�T�χX�TN�y�ؓT��nNP�T������Tˏ��p�TO�����T�zPp�T ���Tf�nǈ�T��Xz��T��Yi��T���T�m9R��T���� �T�V�`�T�;���T�_h�H�T�B6r��Tb�Р�T����T�s�8�T7�~��T���(�T�,>��Tr�����TJ~`P�T��k��U���(U}b?hU��	��U�)7�UM,0�pUɒ��U�*R�H"U��j�&U l���+U��ݸ0U���(5U�C��9Uu)*0�=UQ_��hBU�̬��FU��v�(KU�`�� PUm�a�0TUV�r�XU�q��\UD���aUd£��eU
P)Z`jU�"�nURs��PsU:�鬸wU�W�@|U[�9D                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ����nk  ��ZP�    8�L        ��������   ��L�d�����  �     �             Owners  ����vkH   �p        Microsoft-Windows-SMBServer-Package~31bf3856ad364e35~amd64~~10.0.14393.0`���nk  ]�PZP�    X�'       �8Q����	   �5Q�d����� �        �       M   Microsoft-Windows-SMBServer-Package~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0   ����P u s h   B u t t o n   R e s e t   -   L a n g u a g e     ����ؗL�5Q�6Q�6Q 7QH7Qp7Q�7Q�7Q����vk �   �5Q      InstallName     X���M i c r o s o f t - W i n d o w s - S M B S e r v e r - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ z h - C N ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m   ����vk F   �6Q      InstallLocation ����\ \ ? \ C : \ W i n d o w s \ S e r v i c i n g \ P a c k a g e s \         ����vk   �p         CurrentState    ����vk
   �          SelfUpdate      ����vk
   �         Visibility      ����vk   �ZP�      InstallTimeHigh ����vk   �]�P      InstallTimeLow  ����vk    �7Q      InstallUser     ����S - 1 - 5 - 1 8   C����nk  |O{-ZP�    �4Q        ��������   �8Q�d�����  �     �             Owners  x���vko   �p        Microsoft-Windows-Client-Features-Package-AutoMerged-mergedcomponents~31bf3856ad364e35~amd64~zh-CN~10.0.14393.0 ����X8Q����lh  8Q"|Ph���nk  i��ZP�    X�'       P=Q����	   �9Q�d����� �        �       H   Microsoft-Windows-SMBServer-Package~31bf3856ad364e35~amd64~~10.0.14393.0����vk 8   �9Q      InstallClient   ����P u s h   B u t t o n   R e s e t   -   E d i t i o n       �����9Q :Q�:Q`;Q�;Q�;Q�;Q <Q(<Q����vk �   H:Q      InstallName     `���M i c r o s o f t - W i n d o w s - S M B S e r v e r - P a c k a g e ~ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 ~ a m d 6 4 ~ ~ 1 0 . 0 . 1 4 3 9 3 . 0 . m u m     ����vk F   ;Q      InstallLoc