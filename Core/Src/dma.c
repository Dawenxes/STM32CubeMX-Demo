//
// Created by 阳庆瑶 on 2023/9/16.
//
#include "dma.h"



const uint32_t aSRC_Buffer[BUFFER_SIZE] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
};
uint8_t aSRC_Buffer2[BUFFER_SIZE2];
uint32_t dest[BUFFER_SIZE];
DMA_HandleTypeDef dmaHandleTypeDef;

void dma_init() {
    //dmaHandleTypeDef.State = HAL_DMA_STATE_READY;
    dmaHandleTypeDef.DmaBaseAddress = DMA1;
    dmaHandleTypeDef.Instance = DMA1_Channel6;
    DMA_InitTypeDef DMA_Struct = {0};
    dmaHandleTypeDef.Init = DMA_Struct;
    DMA_Struct.Direction = DMA_MEMORY_TO_MEMORY;
    DMA_Struct.PeriphInc = DMA_PINC_ENABLE;
    DMA_Struct.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    DMA_Struct.MemDataAlignment = DMA_PDATAALIGN_WORD;
    DMA_Struct.MemInc = DMA_PINC_ENABLE;
    DMA_Struct.Mode = DMA_NORMAL;
    DMA_Struct.Priority = DMA_PRIORITY_VERY_HIGH;
    HAL_DMA_Init(&dmaHandleTypeDef);
    HAL_DMA_Start(&dmaHandleTypeDef, (uint32_t) aSRC_Buffer, (uint32_t) dest, BUFFER_SIZE);
}
