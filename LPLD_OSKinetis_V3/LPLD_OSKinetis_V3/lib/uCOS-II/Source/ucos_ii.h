/*
*********************************************************************************************************
*                                              uC/OS-II
*                                        The Real-Time Kernel
*
*                            (c) Copyright 1992-2012, Micrium, Weston, FL
*                                           All Rights Reserved
*
* File    : uCOS_II.H
* By      : Jean J. Labrosse
* Version : V2.92.07
*
* LICENSING TERMS:
* ---------------
*   uC/OS-II is provided in source form for FREE evaluation, for educational use or for peaceful research.
* If you plan on using  uC/OS-II  in a commercial product you need to contact Micrium to properly license
* its use in your product. We provide ALL the source code for your convenience and to help you experience
* uC/OS-II.   The fact that the  source is provided does  NOT  mean that you can use it without  paying a
* licensing fee.
*********************************************************************************************************
*/

#ifndef   OS_uCOS_II_H
#define   OS_uCOS_II_H

#ifdef __cplusplus
extern "C" {
#endif

/*
*********************************************************************************************************
*                                       uC/OS-II VERSION NUMBER
*********************************************************************************************************
*/

#define  OS_VERSION                 29207u              /* Version of uC/OS-II (Vx.yy mult. by 10000)  */

/*
*********************************************************************************************************
*                                        INCLUDE HEADER FILES
*********************************************************************************************************
*/

#include <app_cfg.h>
#include <os_cfg.h>
#include <os_cpu.h>

/*
*********************************************************************************************************
*                                            MISCELLANEOUS
*********************************************************************************************************
*/

#ifdef   OS_GLOBALS
#define  OS_EXT
#else
#define  OS_EXT  extern
#endif

#ifndef  OS_FALSE
#define  OS_FALSE                       0u
#endif

#ifndef  OS_TRUE
#define  OS_TRUE                        1u
#endif

#define  OS_ASCII_NUL            (INT8U)0

#define  OS_PRIO_SELF                0xFFu              /* Indicate SELF priority                      */
#define  OS_PRIO_MUTEX_CEIL_DIS      0xFFu              /* Disable mutex priority ceiling promotion    */

#if OS_TASK_STAT_EN > 0u
#define  OS_N_SYS_TASKS                 2u              /* Number of system tasks                      */
#else
#define  OS_N_SYS_TASKS                 1u
#endif

#define  OS_TASK_STAT_PRIO  (OS_LOWEST_PRIO - 1u)       /* Statistic task priority                     */
#define  OS_TASK_IDLE_PRIO  (OS_LOWEST_PRIO)            /* IDLE      task priority                     */

#if OS_LOWEST_PRIO <= 63u
#define  OS_EVENT_TBL_SIZE ((OS_LOWEST_PRIO) / 8u + 1u) /* Size of event table                         */
#define  OS_RDY_TBL_SIZE   ((OS_LOWEST_PRIO) / 8u + 1u) /* Size of ready table                         */
#else
#define  OS_EVENT_TBL_SIZE ((OS_LOWEST_PRIO) / 16u + 1u)/* Size of event table                         */
#define  OS_RDY_TBL_SIZE   ((OS_LOWEST_PRIO) / 16u + 1u)/* Size of ready table                         */
#endif

#define  OS_TASK_IDLE_ID            65535u              /* ID numbers for Idle, Stat and Timer tasks   */
#define  OS_TASK_STAT_ID            65534u
#define  OS_TASK_TMR_ID             65533u

#define  OS_EVENT_EN           (((OS_Q_EN > 0u) && (OS_MAX_QS > 0u)) || (OS_MBOX_EN > 0u) || (OS_SEM_EN > 0u) || (OS_MUTEX_EN > 0u))

#define  OS_TCB_RESERVED        ((OS_TCB *)1)

/*$PAGE*/
/*
*********************************************************************************************************
*                             TASK STATU  �        180D�`����vk   �        180E�b����vk   �        180F�c����vk   �       1810�d����vk   �        1812�`����vk   �       1A00�b����vk   �        1A02(e����vk   �        1A03`f����vk   �       1A04�`����vk   �       1A05�b����vk   �        1A06�c����vk   �       1A10�d����vk   �        1C00�e����vk   �       2000�`����vk   �       2005�c����vk   �       2100(e����vk   �       2101�`����I n t e r n e t   hbin �e                       ����vk   �       2102�b����vk   �       2103�c����vk   �       2104�d����vk   �       2105�e����vk   �       2106�f����vk   �       2107a����vk   �       2200�c����vk   �       2201�`����vk   �        2301�b����vk   �       2302�c����vk   �        2400�d����vk   �        2401�e����vk   �        2402�f����vk   �       2500�g����vk   �        2600a����vk   �        2700�`����vk   �        2701�b����vk   �        2702�c����vk   �        2703�d����vk   �        2704�e����vk   �       2708�f����vk   �       2709�g����vk   �        270Bi����vk   �        270C�`����vk   �       270D�b����vk   �        CurrentLevel0d����vk �   ��e    Description�eX���T h i s   z o n e   c o n t a i n s   W e b   s i t e s   t h a t   y o u   t r u s t   n o t   t o   d a m a g e   y o u r   c o m p u t e r   o r   d a t a .   ����vk    `�e    DisplayName``����T r u s t e d   s i t e s   ����vk   �!       Flagsd����vk *   ��e    Icon�e����i n e t c p l . c p l # 0 0 0 0 4 4 8 0   ����vk &   �e    LowIcon����i n e t c p l . c p l # 0 0 5 4 2 4   Hj����vk >   h�e    PMDisplayName`����T r u s t e d   s i t e s   [ P r o t e c t e d   M o d e ]   pd����vk   �       d 140C�ߣ����nk  �XTX��    �M�        ��������X   H�e0=F����  �        �          3z���������vk   �       10018E����(�e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e  f@ f` f� f� f� f� f f f@f`f�f�f�f�f�f�f�f8f�f�f    ����vk   �       1004F����vk   �       1200HG����vk   �       1201H����vk   �       1206 I����vk   �       12078J����vk   �       1208hL����vk   �       1209�M����vk   �       120A�Q����vk   �       120BO����vk   �       120C�Q����vk   �         1400    ����vk   �        1402�Q����vk   �          1405    ����vk   �       1406�Q����vk   �         1407    ����vk   �       1408�Q����vk   �        1409@T����vk   �        140A�Q����vk   �        1601@T����vk   �        1604HQ����vk   �        1605�S����vk   �        1606�P����vk   �       1607�Q����vk   �        1608�T����vk   �       1609Q����vk   �       160A�Q����vk   �        160B�T����vk   �        1802�Q����vk   �        1803@T����vk   �       1804�Q����vk   �       1805@T����vk   �       1806xU����vk   �       1807�Q����vk   �        1808@T����vk   �        1809xU����vk   �       180AQ����vk   �       180C�Q����vk   �       180D�Q����vk   �        180E@T����vk   �        180FxU����vk   �       18108V����vk   �       1812�Q����vk   �       1A00@T����vk   �        1A02�V����vk   �        1A03�W����vk   �       1A04�Q����vk   �       1A05@T����vk   �        1A06xU����vk   �       1A108V����vk   �        1C00PW����vk   �       2000�Q����vk   �       20058U����vk   �       2100�V����vk   �       2101�Q����vk   �       2102@T����vk   �       2103xU����vk   �       21048V����vk   �       2105PW����vk   �       2106hX����vk   �       2107�S����vk   �       22008U����vk   �       2201�Q����vk   �        2301@T����vk   �       2302xU����vk   �       24008V����vk   �        2401PW����(9f�:f    hbin  f                       ����vk   �       2402hX����vk   �        2500�Y����vk   �        2600�S����vk   �        2700�Q����vk   �       2701@T����vk   �        2702xU����vk   �       27038V����vk   �       2704PW����vk   �       2708hX����vk   �       2709�Y����vk   �       270B�Z����vk   �        270C�Q����vk   �       270D@T����vk   �        CurrentLevel�U����vk �   f    DescriptionWp���T h i s   z o n e   c o n t a i n s   a l l   W e b   s i t e s   y o u   h a v e n ' t   p l a c e d   i n   o t h e r   z o n e s   �[����vk    ��e      DisplayName     ����vk   �!         Flags   ����vk &   f    Icon�Q����i n e t c p l . c p l # 0 0 1 3 1 3   �T����vk &   Xf    LowIcon����i n e t c p l . c p l # 0 0 5 4 2 5   PW����vk 4   �f    PMDisplayNameX����I n t e r n e t   [ P r o t e c t e d   M o d e ]   ����vk   �       n 140Cݣ����nk  �XTX��    �M�        ��������W   �f0=F����  �        �          4    ����vk   �         10012   ����`f�f f f@f`f�f�f�f�f f f@f`f�f�f�f�f f f@f`f�f�f�f�f 	f 	f@	f`	f�	f�	f�	f�	f 
f 
f@
f`
f�
f�
f�
f�
f f f@f`f�f�f�f�f f f@f`f�f�f�f�f f f@f`f�f�f�f�f f f@f`f�f�f�f�f f f@f`f�f�f�f fHff�fhf�f����vk   �         1004�   ����vk   �         1200  ����vk   �        1201  ����vk   �         1206 8 ����vk   �       �?1207<�P�����vk   �         1208    ����vk   �         1209    ����vk   �       120A8E����vk   �         120B    ����vk   �       120C8E����vk   �         1400    ����vk   �       14028E����vk   �         1405    ����vk   �       14068E����vk   �         1407    ����vk   �       14088E����vk   �        1409F����vk   �        140A8E����vk   �       1601F����vk   �       1604�D����vk   �        1605�E����vk   �       1606(C����vk   �       1607�D����vk   �       1608hF����vk   �       16090D����vk   �       160AxE����vk   �        160B�F����vk   �       18028E����vk   �       1803F����vk   �       18048E����vk   �       1805F����vk   �       1806HG����vk   �       18078E����vk   �        1808F����vk   �        1809HG����vk   �       180A0D����vk   �       180BxE����vk   �       180C8E����vk   �       180DF����vk   �       180EHG����vk   �       180FH����vk   �       18108E����vk   �       1812F����vk   �       1A00�H����vk   �       1A02�I����vk   �       1A038E����vk   �       1A04F����vk   �       1A05HG����vk   �       1A06H����vk   �       1A10 I����vk   �        1C008E����vk   �       2000G����vk   �       2005�H����vk   �       21008E����vk   �       2101F����vk   �       2102HG����vk   �       2103H����vk   �       2104 I����vk   �       21058J����vk   �       2106�E����vk   �       2107G����vk   �       22008E����vk   �       2201F����vk   �        2301HG����vk   �       2302H����vk   �       2400 I����vk   �       24018J����vk   �       2402PK����vk   �        2500�E����vk   �       26008E����vk   �        2700F����vk   �       2701HG����vk   �        2702H����vk   �       2703 I����vk   �       27048J����vk   �       2708PK����vk   �       2709hL����vk   �       270B8E����vk   �        270CF����vk   �       270DHG����vk   �!       FlagsMhbin f                       ����vk   �        CurrentLevelHH����vk �   pf    Description�IX���T h i s   z o n e   c o n t a i n s   W e b   s i t e s   t h a t   c o u l d   p o t e n t i a l l y   d a m a g e   y o u r   c o m p u t e r   o r   d a t a .   ����vk "   @f    DisplayName(L����R e s t r i c t e d   s i t e s   ����vk *   �f    IconPK����i n e t c p l . c p l # 0 0 0 0 4 4 8 1   ����vk   �         140C�٣����nk  .��ZP�    p�        ��������    ����0f����  �                    Secure  ����sk  ����   �   ��  �               �     ?                ?                                    !       �         !    ?                                 ?                                                         �                        !    ?                ?            ?                           8   
           �1�?l�cL<�Pї�b�~z�������                        ����nk  � V��h�    �&�       0f����    ����������" �                     020E7935BC95FB340AEF232BD69E1878����nk  oU��h�    @f        ��������   ��e�{^ ����  �        �         Features����vk �    f    p DefaultFeatureP����vk	 6   Xf    p Publisher i l e ����P y t h o n   S o f t w a r e   F o u n d a t i o n   M 4 6 ����vk   �        p Size��������vk   �D      TEstimatedSizesT����vk   �       TSystemComponent����vk j   0f    rUninstallString����M s i E x e c . e x e   / I { 2 4 C 3 1 C C 2 - A 8 F 2 - 4 1 7 E - A 6 1 B - 5 E 6 8 2 D 3 9 8 9 3 B }   R ����vk   �        TURLInfoAbout��T����vk   �        TURLUpdateInfosT����vk   �       VersionMajor��������vk   �       TVersionMinor�sT����vk   �       TWindowsInstaller����vk   �f    TVersion����vk   �	      . Language����vk D   �f    e DisplayName r i ����P y t h o n   3 . 5 . 2   E x e c u t a b l e s   ( 6 4 - b i t )   ����nk  *ɧ��h�    `8f        ��������   �_d�{^ ����  �                  Patches ����vk
   �        I AllPatchesN I F ����nk  ����h�    `8f        ��������    ����x������  �                    Usage s ����nk  V���h�    �&�       f����    ����������" �                     3523E47AC6BC41249846FFEC3BD75B8D����nk  �.���h�    �f        ��������   �d�{^ ����  �        *          Features����vk *   �f    0 DefaultFeaturen ����k ? s i n E @ u v B } J y C 0 0 ` Q . o   4����lh `f:�8f�M�/�Af$��� Bf�T�	����nk  �����h�    �f        ��������   f�{^ ����  �     &   �          InstallProperties       ����vk B   �f    r LocalPackage    ����C : \ W I N D O W S \ I n s t a l l e r \ 4 2 6 a 6 9 a . m s i     �����fxf�f�f�f0fPfxf�f�f�f`f�f�ff0fXf @fH@fp@f�@f�@f�@fAf(Af����vk   �        x AuthorizedCDFPrefix     ����vk   �        C Comments����vk   �          Contact����vk    f    2 DisplayVersionM����3 . 5 . 2 1 5 0 . 0     �h�����vk   �        . HelpLink����vk   �        u HelpTelephone   ����vk    �f    m InstallDate h   ����2 0 1 7 0 1 0 7   �����vk   �        n InstallLocation ����vk �   f    0 InstallSource p @���C : \ U s e r s \ w a n g \ A p p D a t a \ L o c a l \ P a c k a g e   C a c h e \ { A 7 4 E 3 2 5 3 - C B 6 C - 4 2 1 4 - 8 9 6 4 - F F C E B 3 7 D B 5 D 8 } v 3 . 5 . 2 1 5 0 . 0 \     ����vk
 IO;
#else
typedef  INT16U   OS_PRIO;
#endif

#if (OS_EVENT_EN) && (OS_MAX_EVENTS > 0u)
typedef struct os_event {
    INT8U    OSEventType;                    /* Type of event control block (see OS_EVENT_TYPE_xxxx)    */
    void    *OSEventPtr;                     /* Pointer to message or queue structure                   */
    INT16U   OSEventCnt;                     /* Semaphore Count (not used if other EVENT type)          */
    OS_PRIO  OSEventGrp;                     /* Group corresponding to tasks waiting for event to occur */
    OS_PRIO  OSEventTbl[OS_EVENT_TBL_SIZE];  /* List of tasks waiting for event to occur                */

#if OS_EVENT_NAME_EN > 0u
    INT8U   *OSEventName;
#endif
} OS_EVENT;
#endif


/*
*********************************************************************************************************
*                                      EVENT FLAGS CONTROL BLOCK
*********************************************************************************************************
*/

#if (OS_FLAG_EN > 0u) && (OS_MAX_FLAGS > 0u)

#if OS_FLAGS_NBITS == 8u                    /* Determine the size of OS_FLAGS (8, 16 or 32 bits)       */
typedef  INT8U    OS_FLAGS;
#endif

#if OS_FLAGS_NBITS == 16u
typedef  INT16U   OS_FLAGS;
#endif

#if OS_FLAGS_NBITS == 32u
typedef  INT32U   OS_FLAGS;
#endif


typedef struct os_flag_grp {                /* Event Flag Group                                        */
    INT8U         OSFlagType;               /* Should be set to OS_EVENT_TYPE_FLAG                     */
    void         *OSFlagWaitList;           /* Pointer to first NODE of task waiting on event flag     */
    OS_FLAGS      OSFlagFlags;              /* 8, 16 or 32 bit flags                                   */
#if OS_FLAG_NAME_EN > 0u
    INT8U        *OSFlagName;
#endif
} OS_FLAG_GRP;



typedef struct os_flag_node {               /* Event Flag Wait List Node                               */
    void         *OSFlagNodeNext;           /* Pointer to next     NODE in wait list                   */
    void         *OSFlagNodePrev;           /* Pointer to previous NODE in wait list                   */
    void         *OSFlagNodeTCB;            /* Pointer to TCB of waiting task                          */
    void         *OSFlagNodeFlagGrp;        /* Pointer to Event Flag Group                             */
    OS_FLAGS      OSFlagNodeFlags;          /* Event flag to wait on                                   */
    INT8U         OSFlagNodeWaitType;       /* Type of wait:                                           */
    /*      OS_FLAG_WAIT_AND                                   */
    /*      OS_FLAG_WAIT_ALL                                   */
    /*      OS_FLAG_WAIT_OR                                    */
    /*      OS_FLAG_WAIT_ANY                                   */
} OS_FLAG_NODE;
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                        MESSAGE MAILBOX DATA
*********************************************************************************************************
*/

#if OS_MBOX_EN > 0u
typedef struct os_mbox_data {
    void   *OSMsg;                         /* Pointer to message in mailbox                            */
    OS_PRIO OSEventTbl[OS_EVENT_TBL_SIZE]; /* List of tasks waiting for event to occur                 */
    OS_PRIO OSEventGrp;                    /* Group corresponding to tasks waiting for event to occur  */
} OS_MBOX_DATA;
#endif

/*
*********************************************************************************************************
*                                  MEMORY PARTITION DATA STRUCTURES
*********************************************************************************************************
*/

#if (OS_MEM_EN > 0u) && (OS_MAX_MEM_PART > 0u)
typedef struct os_mem {                   /* MEMORY CONTROL BLOCK                                      */
    void   *OSMemAddr;                    /* Pointer to beginning of memory partition                  */
    void   *OSMemFreeList;                /* Pointer to list of free memory blocks                     */
    INT32U  OSMemBlkSize;                 /* Size (in bytes) of each block of memory                   */
    INT32U  OSMemNBlks;                   /* Total number of blocks in this partition                  */
    INT32U  OSMemNFree;                   /* Number of memory blocks remaining in this partition       */
#if OS_MEM_NAME_EN > 0u
    INT8U  *OSMemName;                    /* Memory partition name                                     */
#endif
} OS_MEM;


typedef struct os_mem_data {
    void   *OSAddr;                    /* Pointer to the beginning address of the memory partition     */
    void   *OSFreeList;                /* Pointer to the beginning of the free list of memory blocks   */
    INT32U  OSBlkSize;                 /* Size (in bytes) of each memory block                         */
    INT32U  OSNBlks;                   /* Total number of blocks in the partition                      */
    INT32U  OSNFree;                   /* Number of memory blocks free                                 */
    INT32U  OSNUsed;                   /* Number of memory blocks used                                 */
} OS_MEM_DATA;
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                   MUTUAL EXCLUSION SEMAPHORE DATA
*********************************************************************************************************
*/

#if OS_MUTEX_EN > 0u
typedef struct os_mutex_data {
    OS_PRIO OSEventTbl[OS_EVENT_TBL_SIZE];  /* List of tasks waiting for event to occur                */
    OS_PRIO OSEventGrp;                     /* Group corresponding to tasks waiting for event to occur */
    BOOLEAN OSValue;                        /* Mutex value (OS_FALSE = used, OS_TRUE = available)      */
    INT8U   OSOwnerPrio;                    /* Mutex owner's task priority or 0xFF if no owner         */
    INT8U   OSMutexPCP;                     /* Priority Ceiling Priority or 0xFF if PCP disabled       */
} OS_MUTEX_DATA;
#endif

/*
*********************************************************************************************************
*                                         MESSAGE QUEUE DATA
*********************************************************************************************************
*/

#if OS_Q_EN > 0u
typedef struct os_q {                   /* QUEUE CONTROL BLOCK                                         */
    struct os_q   *OSQPtr;              /* Link to next queue control block in list of free blocks     */
    void         **OSQStart;            /* Pointer to start of queue data                              */
    void         **OSQEnd;              /* Pointer to end   of queue data                              */
    void         **OSQIn;               /* Pointer to where next message will be inserted  in   the Q  */
    void         **OSQOut;              /* Pointer to where next message will be extracted from the Q  */
    INT16U         OSQSize;             /* Size of queue (maximum number of entries)                   */
    INT16U         OSQEntries;          /* Current number of entries in the queue                      */
} OS_Q;


typedef struct os_q_data {
    void          *OSMsg;               /* Pointer to next message to be extracted from queue          */
    INT16U         OSNMsgs;             /* Number of messages in message queue                         */
    INT16U         OSQSize;             /* Size of message queue                                       */
    OS_PRIO        OSEventTbl[OS_EVENT_TBL_SIZE];  /* List of tasks waiting for event to occur         */
    OS_PRIO        OSEventGrp;          /* Group corresponding to tasks waiting for event to occur     */
} OS_Q_DATA;
#endif

/*
*********************************************************************************************************
*                                           SEMAPHORE DATA
*********************************************************************************************************
*/

#if OS_SEM_EN > 0u
typedef struct os_sem_data {
    INT16U  OSCnt;                          /* Semaphore count                                         */
    OS_PRIO OSEventTbl[OS_EVENT_TBL_SIZE];  /* List of tasks waiting for event to occur                */
    OS_PRIO OSEventGrp;                     /* Group corresponding to tasks waiting for event to occur */
} OS_SEM_DATA;
#endif

/*
*********************************************************************************************************
*                                           TASK STACK DATA
*********************************************************************************************************
*/

#if OS_TASK_CREATE_EXT_EN > 0u
typedef struct os_stk_data {
    INT32U  OSFree;                    /* Number of free entries on the stack                          */
    INT32U  OSUsed;                    /* Number of entries used on the stack                          */
} OS_STK_DATA;
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                         TASK CONTROL BLOCK
*********************************************************************************************************
*/

typedef struct os_tcb {
    OS_STK          *OSTCBStkPtr;           /* Pointer to current top of stack                         */

#if OS_TASK_CREATE_EXT_EN > 0u
    void            *OSTCBExtPtr;           /* Pointer to user definable data for TCB extension        */
    OS_STK          *OSTCBStkBottom;        /* Pointer to bottom of stack                              */
    INT32U           OSTCBStkSize;          /* Size of task stack (in number of stack elements)        */
    INT16U           OSTCBOpt;              /* Task options as passed by OSTaskCreateExt()             */
    INT16U           OSTCBId;               /* Task ID (0..65535)                                      */
#endif

    struct os_tcb   *OSTCBNext;             /* Pointer to next     TCB in the TCB list                 */
    struct os_tcb   *OSTCBPrev;             /* Pointer to previous TCB in the TCB list                 */

#if (OS_EVENT_EN)
    OS_EVENT        *OSTCBEventPtr;         /* Pointer to          event control block                 */
#endif

#if (OS_EVENT_EN) && (OS_EVENT_MULTI_EN > 0u)
    OS_EVENT       **OSTCBEventMultiPtr;    /* Pointer to multiple event control blocks                */
#endif

#if ((OS_Q_EN > 0u) && (OS_MAX_QS > 0u)) || (OS_MBOX_EN > 0u)
    void            *OSTCBMsg;              /* Message received from OSMboxPost() or OSQPost()         */
#endif

#if (OS_FLAG_EN > 0u) && (OS_MAX_FLAGS > 0u)
#if OS_TASK_DEL_EN > 0u
    OS_FLAG_NODE    *OSTCBFlagNode;         /* Pointer to event flag node                              */
#endif
    OS_FLAGS         OSTCBFlagsRdy;         /* Event flags that made task ready to run                 */
#endif

    INT32U           OSTCBDly;              /* Nbr ticks to delay task or, timeout waiting for event   */
    INT8U            OSTCBStat;             /* Task      status                                        */
    INT8U            OSTCBStatPend;         /* Task PEND status                                        */
    INT8U            OSTCBPrio;             /* Task priority (0 == highest)                            */

    INT8U            OSTCBX;                /* Bit position in group  corresponding to task priority   */
    INT8U            OSTCBY;                /* Index into ready table corresponding to task priority   */
    OS_PRIO          OSTCBBitX;             /* Bit mask to access bit position in ready table          */
    OS_PRIO          OSTCBBitY;             /* Bit mask to access bit position in ready group          */

#if OS_TASK_DEL_EN > 0u
    INT8U            OSTCBDelReq;           /* Indicates whether a task needs to delete itself         */
#endif

#if OS_TASK_PROFILE_EN > 0u
    INT32U           OSTCBCtxSwCtr;         /* Number of time the task was switched in                 */
    INT32U           OSTCBCyclesTot;        /* Total number of clock cycles the task has been running  */
    INT32U           OSTCBCyclesStart;      /* Snapshot of cycle counter at start of task resumption   */
    OS_STK          *OSTCBStkBase;          /* Pointer to the beginning of the task stack              */
    INT32U           OSTCBStkUsed;          /* Number of bytes used from the stack                     */
#endif

#if OS_TASK_NAME_EN > 0u
    INT8U           *OSTCBTaskName;
#endif

#if OS_TASK_REG_TBL_SIZE > 0u
    INT32U           OSTCBRegTbl[OS_TASK_REG_TBL_SIZE];
#endif
} OS_TCB;

/*$PAGE*/
/*
*********************************************************************************************************
*                                          TIMER DATA TYPES
*********************************************************************************************************
*/

#if OS_TMR_EN > 0u
typedef  void (*OS_TMR_CALLBACK)(void *ptmr, void *parg);



typedef  struct  os_tmr {
    INT8U            OSTmrType;                       /* Should be set to OS_TMR_TYPE                                  */
    OS_TMR_CALLBACK  OSTmrCallback;                   /* Function to call when timer expires                           */
    void            *OSTmrCallbackArg;                /* Argument to pass to function when timer expires               */
    void            *OSTmrNext;                       /* Double link list pointers                                     */
    void            *OSTmrPrev;
    INT32U           OSTmrMatch;                      /* Timer expires when OSTmrTime == OSTmrMatch                    */
    INT32U           OSTmrDly;                        /* Delay time before periodic update starts                      */
    INT32U           OSTmrPeriod;                     /* Period to repeat timer                                        */
#if OS_TMR_CFG_NAME_EN > 0u
    INT8U           *OSTmrName;                       /* Name to give the timer                                        */
#endif
    INT8U            OSTmrOpt;                        /* Options (see OS_TMR_OPT_xxx)                                  */
    INT8U            OSTmrState;                      /* Indicates the state of the timer:                             */
    /*     OS_TMR_STATE_UNUSED                                       */
    /*     OS_TMR_STATE_RUNNING                                      */
    /*     OS_TMR_STATE_STOPPED                                      */
} OS_TMR;



typedef  struct  os_tmr_wheel {
    OS_TMR          *OSTmrFirst;                      /* Pointer to first timer in linked list                         */
    INT16U           OSTmrEntries;
} OS_TMR_WHEEL;
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

OS_EXT  INT32U            OSCtxSwCtr;               /* Counter of number of context switches           */

#if (OS_EVENT_EN) && (OS_MAX_EVENTS > 0u)
OS_EXT  OS_EVENT         *OSEventFreeList;          /* Pointer to list of free EVENT control blocks    */
OS_EXT  OS_EVENT          OSEventTbl[OS_MAX_EVENTS];/* Table of EVENT control blocks                   */
#endif

#if (OS_FLAG_EN > 0u) && (OS_MAX_FLAGS > 0u)
OS_EXT  OS_FLAG_GRP       OSFlagTbl[OS_MAX_FLAGS];  /* Table containing event flag groups              */
OS_EXT  OS_FLAG_GRP      *OSFlagFreeList;           /* Pointer to free list of event flag groups       */
#endif

#if OS_TASK_STAT_EN > 0u
OS_EXT  INT8U             OSCPUUsage;               /* Percentage of CPU u��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e`�e��e��e����vk   �       1004xz����vk   �        1200�{����vk   �       1201�|����vk   �       1206�|����vk   �        1207�t����vk   �        1208�v����vk   �       1209�w����vk   �       120A`�����vk   �        120B z����vk   �        120C`�����vk   �        1400�|����vk   �        1402`�����vk   �        1405`~����vk   �       1406`�����vk   �         1407    ����0ghbin �e                       ����vk   �        1408�~����vk   �        1409@�����vk   �        140A`�����vk   �        1601������vk   �        1604X����vk   �        1605�����vk   �        1606�~����vk   �       1607@�����vk   �        1608������vk   �       1609����vk   �        160A������vk   �        160B0�����vk   �        1802`�����vk   �        1803������vk   �       1804`�����vk   �        1809������vk   �        1812������vk   �       1A00`�����vk   �        1A02������vk   �        1A03������vk   �       1A04����vk   �       1A05������vk   �        1A06`�����vk   �       1A10������vk   �       1C00������vk   �        2000p�����vk   �        2001`�����vk   �        2004������vk   �        2005�����vk   �       2007 �����vk   �        2100`�����vk   �        2101������vk   �       2102������vk   �        2103p�����vk   �        2104������vk   �        2105`�����vk   �        2106p�����vk   �        2107�����vk   �       2108`�����vk   �       2200������vk   �       2201������vk   �       2300p�����vk   �        2301������vk   �       2302������vk   �        2400�����vk   �        2401p�����vk   �        2402`�����vk   �        2600������vk   �       2700������vk   �        2701p�����vk   �        2702������vk   �        2703������vk   �        2704������vk   �       2708�����vk   �       2709`�����vk   �        270B������vk   �       270C������vk   �        270Dp�����vk d   ��e    Descriptionȅ����W a r n   b e f o r e   r u n n i n g   p o t e n t i a l l y   d a m a g i n g   c o n t e n t .   ����vk @   �e    DisplayName@�����M e d i u m   s a f e t y   ( m e d i u m   s e c u r i t y )   0�����vk *   ��e    Iconȅ����w i n i n e t . d l l # 0 0 0 0 1 2 0 6   ����vk   �      TemplateIndex�����vk   �        u 140Cо�����nk  �XTX��    (�e        ��������O   p�e0=F����  �        T          MedLow  ����vk   �       9 1001.� ����P�e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e��e�e0�eP�ep�e��e��e��e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e`�e��e0�eX�e����vk   �         1004(m~ ����vk   �          1200 � ����vk   �         1201  ����vk   �         1206  ����vk   �         1207  ����vk   �        P�1208�����vk   �          1209   ����vk   �       120A�t����vk   �          120B    ����vk   �        120C�t����vk   �          1400    ����vk   �        1402�t����vk   �          1405    ����vk   �       1406�t����vk   �          1407    ����vk   �        1408�t����vk   �       1409�u����vk   �        140A�t����vk   �        1601�u����vk   �        1604`t����vk   �        1605Hu����vk   �        1606�s����vk   �        1607�t����vk   �        1608�u����vk   �       1609 t����vk   �        160A u����vk   �        160BPv����vk   �        1802�t����vk   �        1803�u����vk   �       1804�t����vk   �       1809�u����vk   �        1812�v����vk   �       1A00�t����vk   �        1A02�u����vk   �        1A03�v����vk   �        1A04 t����vk   �        1A05 u����vk   �        1A06�t����vk   �       1A10�u����vk   �       1C00�v����vk   �        2000�w����vk   �        2001�t����lh x�e
�1hbin �e                       ����vk   �        2004�u����vk   �        2005x����vk   �       2007@y����vk   �        2100�t����vk   �        2101�u����vk   �        2102�v����vk   �        2103�w����vk   �        2104�x����vk   �        2105�t����vk   �        2106�v����vk   �        2107x����vk   �       2108�t����vk   �        2200�u����vk   �        2201�v����vk   �       2300�w����vk   �       2301�x����vk   �       2302�y����vk   �        2400Hu����vk   �        2401�v����vk   �        2402�t����vk   �        2600�u����vk   �       2700�v����vk   �        2701�w����vk   �       2702�x����vk   �        2703�y����vk   �        2704�z����vk   �       2708Hu����vk   �       2709�t����vk   �        270B�u����vk   �       270C�v����vk   �        270D�w����vk 4   (�e    Description�x����R e c o m m e n d e d   f o r   i n t r a n e t .   ����vk T   ��e    DisplayName0|����I n t r a n e t   r e c o m m e n d e d   s a f e t y   ( l e s s   s e c u r e )   ����vk *    �e    Icon�t����w i n i n e t . d l l # 0 0 0 0 1 2 0 6   ����vk   �      TemplateIndexx����vk   �          140C ������nk  .��ZP�    `c�        ��������   ��e�  ����  �                  ProtocolDefaults����vk   �       @ivt8g������e0�eP�ep�e��e��e��e��e�e8�eX�ex�e    ����vk   �       fileph����vk   �       ftp8i����vk   �         http�   ����vk   �        https  ����vk   �          knownfolder   ����vk   �         ldap 8 ����vk   �       �?news<�P�����vk   �       nntp�n����vk   �         oecmd   ����vk   �        shelln����vk   �         snews   ����nk  ����sP�    c�        ��������   �e0=F����  �                   Passport Test   ����vk   �        ConfigVersionn����vk    H�e      LoginServerRealm����P a s s p o r t . N E T     ����lh ��e��z��e$�r�����nk  ���[P�    c�        ��������    ����0=F����  �                    Tracing ����nk  �XTX��    �M�        ��������X   P�e0=F����  �        �          1    ����vk   �       1001�e����0�e��e��e��e�e8�eX�ex�e��e��e��e��e�e8�eX�ex�e��e��e��e��e�e8�eX�ex�e��e��e��e��e�e8�eX�ex�e��e��e��e��e�e8�eX�ex�e��e��e��e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e��e �e �eh�e��e(�e    ����vk   �       1004�f����vk   �       1200`g����vk   �       1201xh����vk   �        1206�i����vk   �       1207�j����vk   �       1208�k����vk   �         1209    ����vk   �       120Ao����vk   �          120B    ����vk   �        120Co����vk   �         1400    ����vk   �        1402o����vk   �          1405    ����vk   �       1406o����vk   �         1407    ����vk   �       1408o����vk   �       1409�q����vk   �        140Ao����vk   �        1601�q����vk   �        1604n����vk   �        1605�o����vk   �        1606�m����vk   �        1607Pn����vk   �        1608�q����vk   �       1609�m����vk   �       160AXo����vk   �        160B8r����vk   �        1802o����vk   �        1803�q����vk   �       1804o����vk   �        1805�q����vk   �        1806�r����vk   �        1807o����vk   �        1808�q����vk   �       1809�r����vk   �        180A�m����vk   �       180CXo����vk   �        180Do����vk   �        180E�q����vk   �        180F�r����vk   �       1810xs����vk   �        1812o����fhbin �e                       ����vk   �       1A00�q����vk   �        1A02�s����vk   �        1A03(u����vk   �       1A04o����vk   �        1A05�q����vk   �        1A06�r����vk   �        1A10xs����vk   �        1C00�t����vk   �       2000o����vk   �       2005xr����vk   �       2100�s����vk   �       2101o����vk   �       2102�q����vk   �       2103�r����vk   �       2104xs����vk   �       2105�t����vk   �       2106�u����vk   �       2107�o����vk   �       2200xr����vk   �       2201o����vk   �       2301�q����vk   �       2302�r����vk   �        2400xs����vk   �        2401�t����vk   �        2402�u����vk   �       2500�v����vk   �        2600�o����vk   �        2700o����vk   �       2701�q����vk   �       2702�r����vk   �        2703xs����vk   �       2704�t����vk   �       2708�u����vk   �       2709�v����vk   �        270B�w����vk   �        270Co����vk   �       270D�q����vk   �        CurrentLevel�r����vk �   �e    DescriptionPt`���T h i s   z o n e   c o n t a i n s   a l l   W e b   s i t e s   t h a t   a r e   o n   y o u r   o r g a n i z a t i o n ' s   i n t r a n e t .   �y����vk    ��e    DisplayNameo����L o c a l   i n t r a n e t   �q����vk   ��       Flagsr����vk "   @�e    Icon�t����s h e l l 3 2 . d l l # 0 0 1 8   ����vk &   ��e    LowIcon����i n e t c p l . c p l # 0 0 5 4 2 3   �x����vk @   ��e    PMDisplayNamen����L o c a l   i n t r a n e t   [ P r o t e c t e d   M o d e ]   8s����vk   �       o 140C�S�����nk  �XTX��    �M�        ��������X   ��e0=F����  �        �          2    ����vk   �       1001�[������e(�eH�eh�e��e��e��e��e�e(�eH�eh�e��e��e��e��e�e(�eH�eh�e��e��e��e��e�e(�eH�eh�e��e��e��e��e�e(�eH�eh�e��e��e��e��e�e(�eH�eh�e��e��e��e��e�e(�eH�eh�e��e��e��e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�eh�e8�e��e��e��e@�e��e    ����vk   �       1004]����vk   �         1200    ����vk   �         1201    ����vk   �       1206�Q����vk   �       1207@T����vk   �       12088V����vk   �       1209PW����vk   �       120A�`����vk   �        120B�Y����vk   �        120C�`����vk   �       1400�\����vk   �        1402�`����vk   �        1405(^����vk   �       1406�`����vk   �         1407    ����vk   �       1408(_����vk   �        1409``����vk   �        140A�`����vk   �        1601�b����vk   �        1604 `����vk   �        1605a����vk   �        1606(_����vk   �       1607``����vk   �        1608�b����vk   �       1609�_����vk   �       160A�`����vk   �        160Bpc����vk   �        1802�`����vk   �        1803�b����vk   �       1804�`����vk   �       1805�b����vk   �       1806�c����vk   �       1807�`����vk   �        1808�b����vk   �       1809�c����vk   �       180A�_����vk   �       180C�`����vk OS_EVENT        *pevent,
                      INT32U           timeout,
                      INT8U           *perr);

#if OS_Q_PEND_ABORT_EN > 0u
INT8U         OSQPendAbort(OS_EVENT        *pevent,
                           INT8U            opt,
                           INT8U           *perr);
#endif

#if OS_Q_POST_EN > 0u
INT8U         OSQPost(OS_EVENT        *pevent,
                      void            *pmsg);
#endif

#if OS_Q_POST_FRONT_EN > 0u
INT8U         OSQPostFront(OS_EVENT        *pevent,
                           void            *pmsg);
#endif

#if OS_Q_POST_OPT_EN > 0u
INT8U         OSQPostOpt(OS_EVENT        *pevent,
                         void            *pmsg,
                         INT8U            opt);
#endif

#if OS_Q_QUERY_EN > 0u
INT8U         OSQQuery(OS_EVENT        *pevent,
                       OS_Q_DATA       *p_q_data);
#endif

#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                        SEMAPHORE MANAGEMENT
*********************************************************************************************************
*/
#if OS_SEM_EN > 0u

#if OS_SEM_ACCEPT_EN > 0u
INT16U        OSSemAccept(OS_EVENT        *pevent);
#endif

OS_EVENT     *OSSemCreate(INT16U           cnt);

#if OS_SEM_DEL_EN > 0u
OS_EVENT     *OSSemDel(OS_EVENT        *pevent,
                       INT8U            opt,
                       INT8U           *perr);
#endif

void          OSSemPend(OS_EVENT        *pevent,
                        INT32U           timeout,
                        INT8U           *perr);

#if OS_SEM_PEND_ABORT_EN > 0u
INT8U         OSSemPendAbort(OS_EVENT        *pevent,
                             INT8U            opt,
                             INT8U           *perr);
#endif

INT8U         OSSemPost(OS_EVENT        *pevent);

#if OS_SEM_QUERY_EN > 0u
INT8U         OSSemQuery(OS_EVENT        *pevent,
                         OS_SEM_DATA     *p_sem_data);
#endif

#if OS_SEM_SET_EN > 0u
void          OSSemSet(OS_EVENT        *pevent,
                       INT16U           cnt,
                       INT8U           *perr);
#endif

#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                           TASK MANAGEMENT
*********************************************************************************************************
*/
#if OS_TASK_CHANGE_PRIO_EN > 0u
INT8U         OSTaskChangePrio(INT8U            oldprio,
                               INT8U            newprio);
#endif

#if OS_TASK_CREATE_EN > 0u
INT8U         OSTaskCreate(void (*task)(void *p_arg),
                           void            *p_arg,
                           OS_STK          *ptos,
                           INT8U            prio);
#endif

#if OS_TASK_CREATE_EXT_EN > 0u
INT8U         OSTaskCreateExt(void (*task)(void *p_arg),
                              void            *p_arg,
                              OS_STK          *ptos,
                              INT8U            prio,
                              INT16U           id,
                              OS_STK          *pbos,
                              INT32U           stk_size,
                              void            *pext,
                              INT16U           opt);
#endif

#if OS_TASK_DEL_EN > 0u
INT8U         OSTaskDel(INT8U            prio);
INT8U         OSTaskDelReq(INT8U            prio);
#endif

#if OS_TASK_NAME_EN > 0u
INT8U         OSTaskNameGet(INT8U            prio,
                            INT8U          **pname,
                            INT8U           *perr);

void          OSTaskNameSet(INT8U            prio,
                            INT8U           *pname,
                            INT8U           *perr);
#endif

#if OS_TASK_SUSPEND_EN > 0u
INT8U         OSTaskResume(INT8U           RegPath p���S O F T W A R E \ M i c r o s o f t \ W i n d o w s \ C u r r e n t V e r s i o n \ I n t e r n e t   S e t t i n g s \ Z o n e s \ % s    ����vk    ��e     Text  ����P r o m p t     �%����vk    ��e      Type    ����r a d i o   ����vk	 
   ��e     ValueName     ����2 0 0 4   ����nk  .��ZP�    �ze       ��e����   ��e�  ���� �        T          MANIFESTPERMISSIONS  ����vk L   ��e      Bitmap  ����C : \ W i n d o w s \ S y s t e m 3 2 \ m s c o r i e r . d l l , 2 0 0 0   ����p�e �ex�e�e    �����ghbin �e                       ����vk
 (   H�e     PlugUIText    ����@ m s c o r i e r . d l l , - 1 0 0 7     ����vk T   ��e     Text  ����P e r m i s s i o n s   f o r   c o m p o n e n t s   w i t h   m a n i f e s t s   ����vk    �e    �?Type<�P�����g r o u p   ����nk  .��ZP�    �e        ��������   ��e@� ����  �        �          DISABLE ����vk   �         CheckedValue    ����x�e��e�e@�e�e(�eX�e����vk   �         DefaultValue    ����vk
 (   �e      PlugUIText      ����@ m s c o r i e r . d l l , - 1 0 0 3       ����vk �   `�e      RegPath p���S O F T W A R E \ M i c r o s o f t \ W i n d o w s \ C u r r e n t V e r s i o n \ I n t e r n e t   S e t t i n g s \ Z o n e s \ % s     ����vk    �e      Text    ����D i s a b l e   �-����vk    H�e      Type    ����r a d i o   ����vk	 
   ��e      ValueName       ����2 0 0 7   ����lh  �e��b֨�e��*y����nk  .��ZP�    �e        ��������   0�e@� ����  �        �       
   HIGHSAFETYd� ( ����vk   �         CheckedValue    �����eP�ex�eДe��e��e�e����vk   �         DefaultValue�������vk
 (   ��e      PlugUIText�8�������@ m s c o r i e r . d l l , - 1 0 0 8      ����vk �   �e      RegPath p���S O F T W A R E \ M i c r o s o f t \ W i n d o w s \ C u r r e n t V e r s i o n \ I n t e r n e t   S e t t i n g s \ Z o n e s \ % s   �?����vk    ��e    ��Text 8 ����H i g h   S a f e t y   <�P�����vk    ��e      Type   ����r a d i o   ����vk	 
   �e      ValueName       ����2 0 0 7   ����nk  ���[P�    �A�       �e����    ����0=F���� �                    TemplatePolicies����nk  �XTX��    (�e        ��������O    �e0=F����  �        b          High    ����vk   �       10018�������e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e@�e`�e��e��e��e�e �e �e@�e`�e��e�ep�e��e�e����vk   �       1004�����vk   �       1200H�����vk   �       1201�����vk   �       1206 �����vk   �       1207`�����vk   �       1208������vk   �       1209ȣ����vk   �       120AX�����vk   �         120B    ����vk   �       120CX�����vk   �         1400    ����vk   �       1402X�����vk   �         1405    ����vk   �       1406X�����vk   �         1407    ����vk   �       1408X�����vk   �        1409 �����vk   �        140AX�����vk   �       1601 �����vk   �       1604������vk   �        1605������vk   �       1606x�����vk   �       16078�����vk   �       1608X�����vk   �       1609������vk   �       160Ah�����vk   �        160B������vk   �       1802X�����vk   �       1803 �����vk   �       1804X�����vk   �        1809 �����vk   �       180B8�����vk   �       1812X�����vk   �       1A00 �����vk   �       1A028�����vk   �       1A03������vk   �       1A04h�����vk   �       1A05X�����vk   �       1A06 �����vk   �       1A108�����vk   �        1C00������vk   �       2000X�����vk   �       2001 �����vk   �       2004p�����vk   �       2005������vk   �       2007X�����vk   �       2100 �����vk   �       21018�����vk   �       2102������vk   �       2103�����vk   �       2104X�����vk   �       2105������vk   �       2106p�����vk   �       2107X�����vk   �       2200 �����vk   �       2201X�����vk   �       2300 �����vk   �        23018�����vk   �       2302������vk   �       2400�����vk   �       2401(�����vk   �       2402X�hbin �e                       ����vk   �       2600 �����vk   �        2700������vk   �       2701�����vk   �          2702    ����vk   �         2703    ����vk   �         2704    ����vk   �       2708X�����vk   �       2709 �����vk   �       270B8�����vk   �        270C������vk   �       270D�����vk b   ��e    Description8�����E x c l u d e   c o n t e n t   t h a t   c o u l d   d a m a g e   y o u r   c o m p u t e r .   ����vk 4   8�e    DisplayName�����H i g h   s a f e t y   ( v e r y   s e c u r e )   ����vk *   ��e    Icon������w i n i n e t . d l l # 0 0 0 0 1 2 0 5   ����vk   �       TemplateIndex�����vk   �          140Cף����lh ��e79 8�e.�  �e���$`�e�l-F��e�{-F����nk  �XTX��    (�e        ��������O   ��e0=F����  �        r          Low   ����vk   �        10018�������e�e�e0�eP�ep�e��e��eХe�e�e0�eP�ep�e��e��eЦe�e�e0�eP�ep�e��e��eЧe�e�e0�eP�ep�e��e��eШe�e�e0�eP�ep�e��e��eЩe�e�e0�eP�ep�e��e��eЪe�e�e0�eP�ep�e��e��eЫe�e�e0�eP�ep�e��e��eЬe�e�e0�eP�ep�e��e��eЭe�e�e��e�eh�e��e����vk   �       1004������vk   �        12008�����vk   �       1201������vk   �        1206`�����vk   �        1207x�����vk   �        1208������vk   �        1209������vk   �       120A8�����vk   �          120B    ����vk   �        120C8�����vk   �          1400    ����vk   �        14028�����vk   �          1405    ����vk   �        14068�����vk   �          1407    ����vk   �        14088�����vk   �       1409�����vk   �        140A8�����vk   �        1601�����vk   �        1604ؚ����vk   �        1605������vk   �        1606X�����vk   �        1607�����vk   �        1608h�����vk   �       1609������vk   �        160Ax�����vk   �        160BȜ����vk   �        18028�����vk   �        1803�����vk   �        18048�����vk   �       1809�����vk   �        1812H�����vk   �        1A008�����vk   �        1A02�����vk   �        1A03H�����vk   �          1A04    ����vk   �          1A05    ����vk   �        1A068�����vk   �        1A10�����vk   �       1C00H�����vk   �        2000�����vk   �        20018�����vk   �        2004�����vk   �        2005������vk   �       2007������vk   �        21008�����vk   �       2101�����vk   �        2102H�����vk   �        2103�����vk   �        2104 �����vk   �        21058�����vk   �        2106�����vk   �        2107������vk   �       21088�����vk   �        2200�����vk   �        2201H�����vk   �       2300�����vk   �       2301 �����vk   �       2302`�����vk   �        2400������vk   �        2401�����vk   �        24028�����vk   �        2600�����vk   �       2700H�����vk   �        2701�����vk   �       2702 �����vk   �        2703`�����vk   �        2704x�����vk   �       2708������vk   �       27098�����vk   �        270B�����vk   �       270CH�����vk   �        270D�����vk r   8�e    Description`�����D o   n o t   w a r n   b e f o r e   r u n n i n g   p o t e n t i a l l y   d a m a g i n g   c o n t e n t .   ����vk 6   خe    DisplayName�����L o w   s a f e t y   ( v e r y   i n s e c u r e )   �����vk *   8�e    Icon �����w i n i n e t . d l l # 0 0 0 0 1 2 0 7   ����vk   �       TemplateIndex�����vk   �        a 140C. E ����vk   �       1001`�����vk   �       1004��������e �e    hbin �e                       ����nk  �XTX��    (�e        ��������N   x�e0=F����  �        f          MedHigh ������eЯe��eرe��e�e8�eX�ex�e��e��eزe��e�e8�eX�ex�e��e��eسe��e�e8�eX�ex�e��e��eشe��e�e8�eX�ex�e��e��eصe��e�e8�eX�ex�e��e��eضe��e�e8�eX�ex�e��e��eطe��e�e8�eX�ex�e��e��eظe��e�e8�eX�ex�e��e��eعe��e�e8�eX�ex�e��e0�eȻe�e@�e    ����vk   �        1200������vk   �       1201p�����vk   �       1206������vk   �       1207������vk   �       1208Ј����vk   �       1209�����vk   �       120A������vk   �         120B    ����vk   �       120C������vk   �          1400    ����vk   �        1402������vk   �          1405    ����vk   �       1406������vk   �         1407    ����vk   �       1408������vk   �        14098�����vk   �        140A������vk   �        16018�����vk   �        16040�����vk   �        1605�����vk   �        1606������vk   �       1607p�����vk   �        1608������vk   �       1609������vk   �       160A������vk   �        160B �����vk   �        1802������vk   �        18038�����vk   �       1804������vk   �        18098�����vk   �       1812������vk   �       1A00������vk   �        1A028�����vk   �        1A03������vk   �       1A04������vk   �       1A05������vk   �        1A06������vk   �       1A108�����vk   �       1C00������vk   �        2000`�����vk   �        2001������vk   �        20048�����vk   �       2005ؑ����vk   �       2007�����vk   �        2100������vk   �        21018�����vk   �       2102������vk   �       2103`�����vk   �       2104x�����vk   �       2105������vk   �        2106`�����vk   �       2107ؑ����vk   �       2200������vk   �       22018�����vk   �       2300������vk   �        2301`�����vk   �       2302x�����vk   �       2400������vk   �        2401�����vk   �       2402`�����vk   �        2600������vk   �        27008�����vk   �        2701������vk   �        2702`�����vk   �       2703x�����vk   �        2704������vk   �       2708������vk   �       2709�����vk   �       270B������vk   �        270C8�����vk   �       270D������vk f   ��e    Description������H e l p   p r e v e n t   m a l w a r e   f r o m   a c c e s s i n g   y o u r   c o m p u t e r .   ������vk f   X�e    DisplayNamep�����I n t e r n e t   r e c o m m e n d e d   s a f e t y   ( m e d i u m   h i g h   s e c u r i t y )   �����vk *   �e    Icon������w i n i n e t . d l l # 0 0 0 0 1 2 0 6   ����vk   �      TemplateIndex�����vk   �          140C�ƣ����nk  �XTX��    (�e        ��������O   ؼe0=F����  �        d          Medium  ����vk   �       1001@y������e�e8�eX�ex�e��e��eؾe��e�e8�eX�ex�e��e��eؿe �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��e��e��e �e �e@�e`�e��e��eBOX_QUERY_EN
#error  "OS_CFG.H, Missing OS_MBOX_QUERY_EN: Include code for OSMboxQuery()"
#endif
#endif

/*
*********************************************************************************************************
*                                          MEMORY MANAGEMENT
*********************************************************************************************************
*/

#ifndef OS_MEM_EN
#error  "OS_CFG.H, Missing OS_MEM_EN: Enable (1) or Disable (0) code generation for MEMORY MANAGER"
#else
#ifndef OS_MAX_MEM_PART
#error  "OS_CFG.H, Missing OS_MAX_MEM_PART: Max. number of memory partitions"
#else
#if     OS_MAX_MEM_PART > 65500u
#error  "OS_CFG.H, OS_MAX_MEM_PART must be <= 65500"
#endif
#endif

#ifndef OS_MEM_NAME_EN
#error  "OS_CFG.H, Missing OS_MEM_NAME_EN: Enable memory partition names"
#endif

#ifndef OS_MEM_QUERY_EN
#error  "OS_CFG.H, Missing OS_MEM_QUERY_EN: Include code for OSMemQuery()"
#endif
#endif

/*
*********************************************************************************************************
*                                     MUTUAL EXCLUSION SEMAPHORES
*********************************************************************************************************
*/

#ifndef OS_MUTEX_EN
#error  "OS_CFG.H, Missing OS_MUTEX_EN: Enable (1) or Disable (0) code generation for MUTEX"
#else
#ifndef OS_MUTEX_ACCEPT_EN
#error  "OS_CFG.H, Missing OS_MUTEX_ACCEPT_EN: Include code for OSMutexAccept()"
#endif

#ifndef OS_MUTEX_DEL_EN
#error  "OS_CFG.H, Missing OS_MUTEX_DEL_EN: Include code for OSMutexDel()"
#endif

#ifndef OS_MUTEX_QUERY_EN
#error  "OS_CFG.H, Missing OS_MUTEX_QUERY_EN: Include code for OSMutexQuery()"
#endif
#endif

/*
*********************************************************************************************************
*                                           MESSAGE QUEUES
*********************************************************************************************************
*/

#ifndef OS_Q_EN
#error  "OS_CFG.H, Missing OS_Q_EN: Enable (1) or Disable (0) code generation for QUEUES"
#else
#ifndef OS_MAX_QS
#error  "OS_CFG.H, Missing OS_MAX_QS: Max. number of queue control blocks"
#else
#if     OS_MAX_QS > 65500u
#error  "OS_CFG.H, OS_MAX_QS must be <= 65500"
#endif
#endif

#ifndef OS_Q_ACCEPT_EN
#error  "OS_CFG.H, Missing OS_Q_ACCEPT_EN: Include code for OSQAccept()"
#endif

#ifndef OS_Q_DEL_EN
#error  "OS_CFG.H, Missing OS_Q_DEL_EN: Include code for OSQDel()"
#endif

#ifndef OS_Q_FLUSH_EN
#error  "OS_CFG.H, Missing OS_Q_FLUSH_EN: Include code for OSQFlush()"
#endif

#ifndef OS_Q_PEND_ABORT_EN
#error  "OS_CFG.H, Missing OS_Q_PEND_ABORT_EN: Include code for OSQPendAbort()"
#endif

#ifndef OS_Q_POST_EN
#error  "OS_CFG.H, Missing OS_Q_POST_EN: Include code for OSQPost()"
#endif

#ifndef OS_Q_POST_FRONT_EN
#error  "OS_CFG.H, Missing OS_Q_POST_FRONT_EN: Include code for OSQPostFront()"
#endif

#ifndef OS_Q_POST_OPT_EN
#error  "OS_CFG.H, Missing OS_Q_POST_OPT_EN: Include code for OSQPostOpt()"
#endif

#ifndef OS_Q_QUERY_EN
#error  "OS_CFG.H, Missing OS_Q_QUERY_EN: Include code for OSQQuery()"
#endif
#endif

/*
*********************************************************************************************************
*                                             SEMAPHORES
*********************************************************************************************************
*/

#ifndef OS_SEM_EN
#error  "OS_CFG.H, Missing OS_SEM_EN: Enable (1) or Disable (0) code generation for SEMAPHORES"
#else
#ifndef OS_SEM_ACCEPT_EN
#error  "OS_CFG.H, Missing OS_SEM_ACCEPT_EN: Include code for OSSemAccept()"
#endif

#ifndef OS_SEM_DEL_EN
#error  "OS_CFG.H, Missing OS_SEM_DEL_EN: Include code for OSSemDel()"
#endif

#ifndef OS_SEM_PEND_ABORT_EN
#error  "OS_CFG.H, Missing OS_SEM_PEND_ABORT_EN: Include code for OSSemPendAbort()"
#endif

#ifndef OS_SEM_QUERY_EN
#error  "OS_CFG.H, Missing OS_SEM_QUERY_EN: Include code for OSSemQuery()"
#endif

#ifndef OS_SEM_SET_EN
#error  "OS_CFG.H, Missing OS_SEM_SET_EN: Include code for OSSemSet()"
#endif
#endif

/*
*********************************************************************************************************
*                                           TASK MANAGEMENT
*********************************************************************************************************
*/

#ifndef OS_MAX_TASKS
#error  "OS_CFG.H, Missing OS_MAX_TASKS: Max. number of tasks in your application"
#else
#if     OS_MAX_TASKS < 2u
#error  "OS_CFG.H,         OS_MAX_TASKS must be >= 2"
#endif

#if     OS_MAX_TASKS >  ((OS_LOWEST_PRIO - OS_N_SYS_TASKS) + 1u)
#error  "OS_CFG.H,         OS_MAX_TASKS must be <= OS_LOWEST_PRIO - OS_N_SYS_TASKS + 1"
#endif

#endif

#if     OS_LOWEST_PRIO >  254u
#error  "OS_CFG.H,         OS_LOWEST_PRIO must be <= 254 in V2.8x and higher"
#endif

#ifndef OS_TASK_IDLE_STK_SIZE
#error  "OS_CFG.H, Missing OS_TASK_IDLE_STK_SIZE: Idle task stack size"
#endif

#ifndef OS_TASK_STAT_EN
#error  "OS_CFG.H, Missing OS_TASK_STAT_EN: Enable (1) or Disable(0) the statistics task"
#endif

#ifndef OS_TASK_STAT_STK_SIZE
#error  "OS_CFG.H, Missing OS_TASK_STAT_STK_SIZE: Statistics task stack size"
#endif

#ifndef OS_TASK_STAT_STK_CHK_EN
#error  "OS_CFG.H, Missing OS_TASK_STAT_STK_CHK_EN: Check task stacks from statistics task"
#endif

#ifndef OS_TASK_CHANGE_PRIO_EN
#error  "OS_CFG.H, Missing OS_TASK_CHANGE_PRIO_EN: Include code for OSTaskChangePrio()"
#endif

#ifndef OS_TASK_CREATE_EN
#error  "OS_CFG.H, Missing OS_TASK_CREATE_EN: Include code for OSTaskCreate()"
#endif

#ifndef OS_TASK_CREATE_EXT_EN
#error  "OS_CFG.H, Missing OS_TASK_CREATE_EXT_EN: Include code for OSTaskCreateExt()"
#else
#if (OS_TASK_CREATE_EXT_EN == 0u) && (OS_TASK_CREATE_EN == 0u)
#error  "OS_CFG.H,         OS_TASK_CREATE_EXT_EN or OS_TASK_CREATE_EN must be Enable (1)"
#endif
#endif

#ifndef OS_TASK_DEL_EN
#error  "OS_CFG.H, Missing OS_TASK_DEL_EN: Include code for OSTaskDel()"
#endif

#ifndef OS_TASK_NAME_EN
#error  "OS_CFG.H, Missing OS_TASK_NAME_EN: Enable task names"
#endif

#ifndef OS_TASK_SUSPEND_EN
#error  "OS_CFG.H, Missing OS_TASK_SUSPEND_EN: Include code for OSTaskSuspend() and OSTaskResume()"
#endif

#ifndef OS_TASK_QUERY_EN
#error  "OS_CFG.H, Missing OS_TASK_QUERY_EN: Include code for OSTaskQuery()"
#endif

#ifndef OS_TASK_REG_TBL_SIZE
#error  "OS_CFG.H, Missing OS_TASK_REG_TBL_SIZE: Include code for task specific registers"
#else
#if     OS_TASK_REG_TBL_SIZE > 255u
#error  "OS_CFG.H,         OS_TASK_REG_TBL_SIZE must be <= 255"
#endif
#endif

/*
*********************************************************************************************************
*                                           TIME MANAGEMENT
*********************************************************************************************************
*/

#ifndef OS_TICKS_PER_SEC
#error  "OS_CFG.H, Missing OS_TICKS_PER_SEC: Sets the number of ticks in one second"
#endif

#ifndef OS_TIME_DLY_HMSM_EN
#error  "OS_CFG.H, Missing OS_TIME_DLY_HMSM_EN: Include code for OSTimeDlyHMSM()"
#endif

#ifndef OS_TIME_DLY_RESUME_EN
#error  "OS_CFG.H, Missing OS_TIME_DLY_RESUME_EN: Include code for OSTimeDlyResume()"
#endif

#ifndef OS_TIME_GET_SET_EN
#error  "OS_CFG.H, Missing OS_TIME_GET_SET_EN: Include code for OSTimeGet() and OSTimeSet()"
#endif

/*
*********************************************************************************************************
*                                          TIMER MANAGEMENT
*********************************************************************************************************
*/

#ifndef OS_TMR_EN
#error  "OS_CFG.H, Missing OS_TMR_EN: When (1) enables code generation for Timer Management"
#elif   OS_TMR_EN > 0u
#if     OS_SEM_EN == 0u
#error  "OS_CFG.H, Semaphore management is required (set OS_SEM_EN to 1) when enabling Timer Management."
#error  "          Timer management require TWO semaphores."
#endif

#ifndef OS_TMR_CFG_MAX
#error  "OS_CFG.H, Missing OS_TMR_CFG_MAX: Determines the total number of timers in an application (2 .. 65500)"
#else
#if OS_TMR_CFG_MAX < 2u
#error  "OS_CFG.H, OS_TMR_CFG_MAX should be between 2 and 65500"
#endif

#if OS_TMR_CFG_MAX > 65500u
#error  "OS_CFG.H, OS_TMR_CFG_MAX should be between 2 and 65500"
#endif
#endif

#ifndef OS_TMR_CFG_WHEEL_SIZE
#error  "OS_CFG.H, Missing OS_TMR_CFG_WHEEL_SIZE: Sets the size of the timer wheel (1 .. 1023)"
#else
#if OS_TMR_CFG_WHEEL_SIZE < 2u
#error  "OS_CFG.H, OS_TMR_CFG_WHEEL_SIZE should be between 2 and 1024"
#endif

#if OS_TMR_CFG_WHEEL_SIZE > 1024u
#error  "OS_CFG.H, OS_TMR_CFG_WHEEL_SIZE should be between 2 and 1024"
#endif
#endif

#ifndef OS_TMR_CFG_NAME_EN
#error  "OS_CFG.H, Missing OS_TMR_CFG_NAME_EN: Enable Timer names"
#endif

#ifndef OS_TMR_CFG_TICKS_PER_SEC
#error  "OS_CFG.H, Missing OS_TMR_CFG_TICKS_PER_SEC: Determines the rate at which the timer management task will run (Hz)"
#endif

#ifndef OS_TASK_TMR_STK_SIZE
#error  "OS_CFG.H, Missing OS_TASK_TMR_STK_SIZE: Determines the size of the Timer Task's stack"
#endif
#endif


/*
*********************************************************************************************************
*                                            MISCELLANEOUS
*********************************************************************************************************
*/

#ifndef OS_ARG_CHK_EN
#error  "OS_CFG.H, Missing OS_ARG_CHK_EN: Enable (1) or Disable (0) argument checking"
#endif


#ifndef OS_CPU_HOOKS_EN
#error  "OS_CFG.H, Missing OS_CPU_HOOKS_EN: uC/OS-II hooks are found in the processor port files when 1"
#endif


#ifndef OS_APP_HOOKS_EN
#error  "OS_CFG.H, Missing OS_APP_HOOKS_EN: Application-defined hooks are called from the uC/OS-II hooks"
#endif


#ifndef OS_DEBUG_EN
#error  "OS_CFG.H, Missing OS_DEBUG_EN: Allows you to include variables for debugging or not"
#endif


#ifndef OS_LOWEST_PRIO
#error  "OS_CFG.H, Missing OS_LOWEST_PRIO: Defines the lowest priority that can be assigned"
#endif


#ifndef OS_MAX_EVENTS
#error  "OS_CFG.H, Missing OS_MAX_EVENTS: Max. number of event control blocks in your application"
#else
#if     OS_MAX_EVENTS > 65500u
#error  "OS_CFG.H, OS_MAX_EVENTS must be <= 65500"
#endif
#endif


#ifndef OS_SCHED_LOCK_EN
#error  "OS_CFG.H, Missing OS_SCHED_LOCK_EN: Include code for OSSchedLock() and OSSchedUnlock()"
#endif


#ifndef OS_EVENT_MULTI_EN
#error  "OS_CFG.H, Missing OS_EVENT_MULTI_EN: Include code for OSEventPendMulti()"
#endif


#ifndef OS_TASK_PROFILE_EN
#error  "OS_CFG.H, Missing OS_TASK_PROFILE_EN: Include data structure for run-time task profiling"
#endif


#ifndef OS_TASK_SW_HOOK_EN
#error  "OS_CFG.H, Missing OS_TASK_SW_HOOK_EN: Allows you to include the code for OSTaskSwHook() or not"
#endif


#ifndef OS_TICK_STEP_EN
#error  "OS_CFG.H, Missing OS_TICK_STEP_EN: Allows to 'step' one tick at a time with uC/OS-View"
#endif


#ifndef OS_TIME_TICK_HOOK_EN
#error  "OS_CFG.H, Missing OS_TIME_TICK_HOOK_EN: Allows you to include the code for OSTimeTickHook() or not"
#endif

/*
*********************************************************************************************************
*                                         SAFETY CRITICAL USE
*********************************************************************************************************
*/

#ifdef SAFETY_CRITICAL_RELEASE

#if    OS_ARG_CHK_EN < 1u
#error "OS_CFG.H, OS_ARG_CHK_EN must be enabled for safety-critical release code"
#endif

#if    OS_APP_HOOKS_EN > 0u
#error "OS_CFG.H, OS_APP_HOOKS_EN must be disabled for safety-critical release code"
#endif

#if    OS_DEBUG_EN > 0u
#error "OS_CFG.H, OS_DEBUG_EN must be disabled for safety-critical release code"
#endif

#ifdef CANTATA
#error "OS_CFG.H, CANTATA must be disabled for safety-critical release code"
#endif

#ifdef OS_SCHED_LOCK_EN
#error "OS_CFG.H, OS_SCHED_LOCK_EN must be disabled for safety-critical release code"
#endif

#ifdef VSC_VALIDATION_MODE
#error "OS_CFG.H, VSC_VALIDATION_MODE must be disabled for safety-critical release code"
#endif

#if    OS_TASK_STAT_EN > 0u
#error "OS_CFG.H, OS_TASK_STAT_EN must be disabled for safety-critical release code"
#endif

#if    OS_TICK_STEP_EN > 0u
#error "OS_CFG.H, OS_TICK_STEP_EN must be disabled for safety-critical release code"
#endif

#if    OS_FLAG_EN > 0u
#if    OS_FLAG_DEL_EN > 0
#error "OS_CFG.H, OS_FLAG_DEL_EN must be disabled for safety-critical release code"
#endif
#endif

#if    OS_MBOX_EN > 0u
#if    OS_MBOX_DEL_EN > 0u
#error "OS_CFG.H, OS_MBOX_DEL_EN must be disabled for safety-critical release code"
#endif
#endif

#if    OS_MUTEX_EN > 0u
#if    OS_MUTEX_DEL_EN > 0u
#error "OS_CFG.H, OS_MUTEX_DEL_EN must be disabled for safety-critical release code"
#endif
#endif

#if    OS_Q_EN > 0u
#if    OS_Q_DEL_EN > 0u
#error "OS_CFG.H, OS_Q_DEL_EN must be disabled for safety-critical release code"
#endif
#endif

#if    OS_SEM_EN > 0u
#if    OS_SEM_DEL_EN > 0u
#error "OS_CFG.H, OS_SEM_DEL_EN must be disabled for safety-critical release code"
#endif
#endif

#if    OS_TASK_DEL_EN > 0u
#error "OS_CFG.H, OS_TASK_DEL_EN must be disabled for safety-critical release code"
#endif

#if    OS_CRITICAL_METHOD != 3u
#error "OS_CPU.H, OS_CRITICAL_METHOD must be type 3 for safety-critical release code"
#endif

#endif  /* ------------------------ SAFETY_CRITICAL_RELEASE ------------------------ */

#ifdef __cplusplus
}
#endif

#endif
