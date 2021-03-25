#ifndef __SHT31_H
#define __SHT31_H

#include "hk32f10x.h"
#include "delay.h"
#include "i2c.h"

/* ö��SHT3x�����б� */
typedef enum
{
    /* �����λ���� */
    SOFT_RESET_CMD = 0x30A2,	
    /* ���β���ģʽ
    ������ʽ��Repeatability_CS_CMD
    CS�� Clock stretching */
    HIGH_ENABLED_CMD    = 0x2C06,
    MEDIUM_ENABLED_CMD  = 0x2C0D,
    LOW_ENABLED_CMD     = 0x2C10,
    HIGH_DISABLED_CMD   = 0x2400,
    MEDIUM_DISABLED_CMD = 0x240B,
    LOW_DISABLED_CMD    = 0x2416,

    /* ���ڲ���ģʽ
    ������ʽ��Repeatability_MPS_CMD
    MPS��measurement per second */
    HIGH_0_5_CMD   = 0x2032,
    MEDIUM_0_5_CMD = 0x2024,
    LOW_0_5_CMD    = 0x202F,
    HIGH_1_CMD     = 0x2130,
    MEDIUM_1_CMD   = 0x2126,
    LOW_1_CMD      = 0x212D,
    HIGH_2_CMD     = 0x2236,
    MEDIUM_2_CMD   = 0x2220,
    LOW_2_CMD      = 0x222B,
    HIGH_4_CMD     = 0x2334,
    MEDIUM_4_CMD   = 0x2322,
    LOW_4_CMD      = 0x2329,
    HIGH_10_CMD    = 0x2737,
    MEDIUM_10_CMD  = 0x2721,
    LOW_10_CMD     = 0x272A,
	/* ���ڲ���ģʽ��ȡ�������� */
	READOUT_FOR_PERIODIC_MODE = 0xE000,
	/* ��ȡ������������� */
	READ_SERIAL_NUMBER = 0x3780,
} SHT30_CMD;

uint8_t SHT30_Init(void);

static uint8_t STH30_Send_Cmd(SHT30_CMD cmd);

static uint8_t SHT30_Read_Data(uint8_t length, uint8_t *data);

uint8_t SHT30_ReadSerialNumber(uint32_t *serialNumber);

uint8_t CheckCrc8(uint8_t *const message, uint8_t initial_value);

uint8_t SHT30_Get_Humiture_periodic(double *Tem_val, double *Hum_val);

uint8_t SHT30_Get_Humiture_single(double *Tem_val, double *Hum_val);

#endif

