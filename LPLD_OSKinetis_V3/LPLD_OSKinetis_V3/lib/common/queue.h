/**
 * @file queue.h
 * @version 3.0[By LPLD]
 * @date 2013-06-18
 * @brief 实现先进先出链表
 *
 * 更改建议:不建议修改
 *
 * 版权所有:北京拉普兰德电子技术有限公司
 * http://www.lpld.cn
 * mail:support@lpld.cn
 *
 * @par
 * 本代码由拉普兰德[LPLD]开发并维护，并向所有使用者开放源代码。
 * 开发者可以随意修使用或改源代码。但本段及以上注释应予以保留。
 * 不得更改或删除原版权所有者姓名，二次开发者可以加注二次版权所有者。
 * 但应在遵守此协议的基础上，开放源代码、不得出售代码本身。
 * 拉普兰德不负责由于使用本代码所带来的任何事故、法律责任或相关不良影响。
 * 拉普兰德无义务解释、说明本代码的具体原理、功能、实现方法。
 * 除非拉普兰德[LPLD]授权，开发者不得将本代码用于商业产品。
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

/********************************************************************/

/*
 * Individual queue node
 */
typedef struct NODE {
    struct NODE *next;
} QNODE;

/*
 * Queue Struture - linked list of qentry items
 */
typedef struct {
    QNODE *head;
    QNODE *tail;
} QUEUE;

/*
 * Functions provided by queue.c
 */
void queue_init(QUEUE *);

int32_t queue_isempty(QUEUE *);

void queue_add(QUEUE *, QNODE *);

QNODE *queue_remove(QUEUE *);

QNODE *queue_peek(QUEUE *);

void queue_move(QUEUE *, QUEUE *);

/********************************************************************/

#endif /* _QUEUE_H_ */
