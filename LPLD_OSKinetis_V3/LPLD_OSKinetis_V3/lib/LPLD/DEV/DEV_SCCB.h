/**
 * @file DEV_SCCB.h
 * @version 0.1[By LPLD]
 * @date 2013-09-24
 * @brief SCCB�豸��������
 *
 * ���Ľ���:�ɸ���ʵ��Ӳ���޸�
 *
 * ��Ȩ����:�����������µ��Ӽ������޹�˾
 * http://www.lpld.cn
 * mail:support@lpld.cn
 *
 * @par
 * ����������������[LPLD]������ά������������ʹ���߿���Դ���롣
 * �����߿���������ʹ�û��Դ���롣�����μ�����ע��Ӧ���Ա�����
 * ���ø��Ļ�ɾ��ԭ��Ȩ���������������ο����߿��Լ�ע���ΰ�Ȩ�����ߡ�
 * ��Ӧ�����ش�Э��Ļ����ϣ�����Դ���롢���ó��۴��뱾����
 * �������²���������ʹ�ñ��������������κ��¹ʡ��������λ���ز���Ӱ�졣
 * ����������������͡�˵��������ľ���ԭ�������ܡ�ʵ�ַ�����
 * ������������[LPLD]��Ȩ�������߲��ý�������������ҵ��Ʒ��
 */
#ifndef __DEV_SCCB_H__
#define __DEV_SCCB_H__

#include "common.h"

#define ADR_OV7670      0x42

/********�û����޸�ֵ ��ʼ***********/
//����SCCB�豸��ַ
#define SCCB_DEV_ADR    ADR_OV7670
//����SCL��SDA������
#define SCCB_SCL        PTC17_O
#define SCCB_SDA_O      PTC16_O
#define SCCB_SDA_I      PTC16_I
//����SDA�������
#define SCCB_SDA_OUT()  DDRC16 = 1
#define SCCB_SDA_IN()   DDRC16 = 0
/********�û����޸�ֵ ����***********/

#define SCCB_DELAY()    LPLD_SCCB_Delay(5000)

void LPLD_SCCB_Init(void);
uint8_t LPLD_SCCB_WriteReg(uint16_t, uint8_t);
uint8_t LPLD_SCCB_ReadReg(uint8_t, uint8_t *, uint16_t);

#endif