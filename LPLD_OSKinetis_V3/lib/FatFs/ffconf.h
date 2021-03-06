/*---------------------------------------------------------------------------/
/  FatFs - FAT file system module configuration file  R0.09b (C)ChaN, 2013
/----------------------------------------------------------------------------/
/
/ CAUTION! Do not forget to make clean the project after any changes to
/ the configuration options.
/
/----------------------------------------------------------------------------*/
#ifndef _FFCONF
#define _FFCONF 82786   /* Revision ID */


/*---------------------------------------------------------------------------/
/ Functions and Buffer Configurations
/----------------------------------------------------------------------------*/

#define _FS_TINY        0   /* 0:Normal or 1:Tiny */
/* When _FS_TINY is set to 1, FatFs uses the sector buffer in the file system
/  object instead of the sector buffer in the individual file object for file
/  data transfer. This reduces memory consumption 512 bytes each file object. */


#define _FS_READONLY    0   /* 0:Read/Write or 1:Read only */
/* Setting _FS_READONLY to 1 defines read only configuration. This removes
/  writing functions, f_write, f_sync, f_unlink, f_mkdir, f_chmod, f_rename,
/  f_truncate and useless f_getfree. */


#define _FS_MINIMIZE    0   /* 0 to 3 */
/* The _FS_MINIMIZE option defines minimization level to remove some functions.
/
/   0: Full function.
/   1: f_stat, f_getfree, f_unlink, f_mkdir, f_chmod, f_truncate and f_rename
/      are removed.
/   2: f_opendir and f_readdir are removed in addition to 1.
/   3: f_lseek is removed in addition to 2. */


#define _USE_STRFUNC    2   /* 0:Disable or 1-2:Enable */
/* To enable string functions, set _USE_STRFUNC to 1 or 2. */


#define _USE_MKFS       1   /* 0:Disable or 1:Enable */
/* To enable f_mkfs function, set _USE_MKFS to 1 and set _FS_READONLY to 0 */


#define _USE_FASTSEEK   1   /* 0:Disable or 1:Enable */
/* To enable fast seek feature, set _USE_FASTSEEK to 1. */


#define _USE_LABEL      0   /* 0:Disable or 1:Enable */
/* To enable volume label functions, set _USE_LAVEL to 1 */


#define _USE_FORWARD    0   /* 0:Disable or 1:Enable */
/* To enable f_forward function, set _USE_FORWARD to 1 and set _FS_TINY to 1. */


/*---------------------------------------------------------------------------/
/ Locale and Namespace Configurations
/----------------------------------------------------------------------------*/

#define _CODE_PAGE  1250
/* The _CODE_PAGE specifies the OEM code page to be used on the target system.
/  Incorrect setting of the code page can cause a file open failure.
/
/   932  - Japanese Shift-JIS (DBCS, OEM, Windows)
/   936  - Simplified Chinese GBK (DBCS, OEM, Windows)
/   949  - Korean (DBCS, OEM, Windows)
/   950  - Traditional Chinese Big5 (DBCS, OEM, Windows)
/   1250 - Central Europe (Windows)
/   1251 - Cyrillic (Windows)
/   1252 - Latin 1 (Windows)
/   1253 - Greek (Windows)
/   1254 - Turkish (Windows)
/   1255 - Hebrew (Windows)
/   1256 - Arabic (Windows)
/   1257 - Baltic (Windows)
/   1258 - Vietnam (OEM, Windows)
/   437  - U.S. (OEM)
/   720  - Arabic (OEM)
/   737  - Greek (OEM)
/   775  - Baltic (OEM)
/   850  - Multilingual Latin 1 (OEM)
/   858  - Multilingual Latin 1 + Euro (OEM)
/   852  - Latin 2 (OEM)
/   855  - Cyrillic (OEM)
/   866  - Russian (OEM)
/   857  - Turkish (OEM)
/   862  - Hebrew (OEM)
/   874  - Thai (OEM, Windows)
/   1    - ASCII only (Valid for non LFN cfg.)
*/


#define _USE_LFN    3       /* 0 to 3 */
#define _MAX_LFN    64      /* Maximum LFN length to handle (12 to 255) */
/* The _USE_LFN option switches the LFN support.
/
/   0: Disable LFN feature. _MAX_LFN and _LFN_UNICODE have no effect.
/   1: Enable LFN with static working buffer on the BSS. Always NOT reentrant.
/   2: Enable LFN with dynamic working buffer on the STACK.
/   3: Enable LFN with dynamic working buffer on the HEAP.
/
/  The LFN working buffer occupies (_MAX_LFN + 1) * 2 bytes. To enable LFN,
/  Unicode handling functions ff_convert(  �        �Status�����vk    R    �RuntimeVersion�����v 4 . 0 . 3 0 3 1 9   ags������vk	 �   R    �ImageListrsion  ����lh pR0   pR1   ����nk  ~V��Z�    pR        ��������   �R @F����           �          1   X������vk   �        2 Scenario�����R�R�R����vk �   R    m Config  X���C : / P r o g r a m   F i l e s   ( x 8 6 ) / M i c r o s o f t   V i s u a l   S t u d i o / 2 0 1 7 / C o m m u n i t y / C o m m o n 7 / I D E / v s n . e x e   ����vk   �         Status.0����vk   �       o StatusI hbin R                        8���   QjK�-��w��"��n   
  C : \ P r o g r a m   F i l e s   ( x 8 6 ) \ M i c r o s o f t   V i s u a l   S t u d i o \ 2 0 1 7 \ C o m m u n i t y \ M S B u i l d \ 1 5 . 0 \ B i n \ a m d 6 4 \ t r \ M i c r o s o f t . B u i l d . U t i l i t i e s . C o r e . r e s o u r c e s . d l l   �   M i c r o s o f t . B u i l d . U t i l i t i e s . C o r e . r e s o u r c e s ,   V e r s i o n = 1 5 . 1 . 0 . 0 ,   C u l t u r e = t r ,   P u b l i c K e y T o k e n = b 0 3 f 5 f 7 f 1 1 d 5 0 a 3 a             .��˴<�m��(;_)   �   m s c o r l i b ,   V e r s i o n = 4 . 0 . 0 . 0 ,   C u l t u r e = n e u t r a l ,   P u b l i c K e y T o k e n = b 7 7 a 5 c 5 6 1 9 3 4 e 0 8 9            u @���nk  ~V��Z�    �BG       R����   �RI����                 m   C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/MSBuild/15.0/Bin/amd64/tr/MSBuild.resources.dll s �����R����nk  ~V��Z�    �R        ��������   (R @F����           f         0tatus�����vk   �        �Scenario����R@RR(RpR����vk �   `R    goConfig�X���C : / P r o g r a m   F i l e s   ( x 8 6 ) / M i c r o s o f t   V i s u a l   S t u d i o / 2 0 1 7 / C o m m u n i t y / C o m m o n 7 / I D E / v s n . e x e   ����vk   �         yStatus y����vk    PR    ClRuntimeVersioni ����v 4 . 0 . 3 0 3 1 9    . C l����vk	 f  �R    A ImageList       ����   ������}���s�   �   C : \ P r o g r a m   F i l e s   ( x 8 6 ) \ M i c r o s o f t   V i s u a l   S t u d i o \ 2 0 1 7 \ C o m m u n i t y \ M S B u i l d \ 1 5 . 0 \ B i n \ a m d 6 4 \ t r \ M S B u i l d . r e s o u r c e s . d l l   �   M S B u i l d . r e s o u r c e s ,   V e r s i o n = 1 5 . 1 . 0 . 0 ,   C u l t u r e = t r ,   P u b l i c K e y T o k e n = b 0 3 f 5 f 7 f 1 1 d 5 0 a 3 a             .��˴<�m��(;_)   �   m s c o r l i b ,   V e r s i o n = 4 . 0 . 0 . 0 ,   C u l t u r e = n e u t r a l ,   P u b l i c K e y T o k e n = b 7 7 a 5 c 5 6 1 9 3 4 e 0 8 9               P u����lh �R0    R1   ����nk  ~V��Z�    �R        ��������   �R @F����           �          1 p . E ����vk   �        W Scenario����xR�RpR����vk �   �R     Config�X���C : / P r o g r a m   F i l e s   ( x 8 6 ) / M i c r o s o f t   V i s u a l   S t u d i o / 2 0 1 7 / C o m m u n i t y / C o m m o n 7 / I D E / v s n . e x e   ����vk   �       9 StatusC 8���nk  ~V��Z�    �BG       �R����   xRI����                 u   C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/MSBuild/15.0/Bin/amd64/tr/MSBuildTaskHost.resources.dll o ����vk   �       u Statusy ����XR����nk  ~V��Z�    �R        ��������   �R @F����           �         0cenario����vk   �        �Scenario�����RR�R�R@R����vk �   0R    �ConfignX���C : / P r o g r a m   F i l e s   ( x 8 6 ) / M i c r o s o f t   V i s u a l   S t u d i o / 2 0 1 7 / C o m m u n i t y / C o m m o n 7 / I D E / v s n . e x e   ����vk   �        �StatusID����vk     R     RuntimeVersi