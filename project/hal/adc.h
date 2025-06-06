// <editor-fold defaultstate="collapsed" desc="Description/Instruction ">
/**
 * @file adc.h
 *
 * @brief This header file lists the functions and definitions - to configure 
 * and enable ADC Module and its features 
 * 
 * Definitions in the file are for dsPIC33AK128MC106 MC DIM plugged onto 
 * Motor Control Development board from Microchip
 *
 * Component: ADC
 *
 */
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Disclaimer ">

/*******************************************************************************
* SOFTWARE LICENSE AGREEMENT
* 
* � [2024] Microchip Technology Inc. and its subsidiaries
* 
* Subject to your compliance with these terms, you may use this Microchip 
* software and any derivatives exclusively with Microchip products. 
* You are responsible for complying with third party license terms applicable to
* your use of third party software (including open source software) that may 
* accompany this Microchip software.
* 
* Redistribution of this Microchip software in source or binary form is allowed 
* and must include the above terms of use and the following disclaimer with the
* distribution and accompanying materials.
* 
* SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
* APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
* MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL 
* MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR 
* CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO
* THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE 
* POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY
* LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL
* NOT EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS
* SOFTWARE
*
* You agree that you are solely responsible for testing the code and
* determining its suitability.  Microchip has no obligation to modify, test,
* certify, or support the code.
*
*******************************************************************************/
// </editor-fold>

#ifndef _ADC_H
#define _ADC_H
        
// <editor-fold defaultstate="collapsed" desc="HEADER FILES ">
        
#include <xc.h>
#include <stdint.h>
        

        
// </editor-fold>

#ifdef __cplusplus  // Provide C++ Compatability
    extern "C" {
#endif
        
// <editor-fold defaultstate="collapsed" desc="DEFINITIONS/CONSTANTS ">
/*Maximum count in 12-bit ADC*/
#define MAX_ADC_COUNT     4096.0f
#define HALF_ADC_COUNT    2048   

#define ADCBUF_PFC_IL       (int16_t)(AD1CH6DATA - HALF_ADC_COUNT)<<4 // Range Changed : -32767 to 32767
#define ADCBUF_PFC_VAC      (int16_t)(AD2CH1DATA - HALF_ADC_COUNT)<<4 // Range Changed : -32767 to 32767      
#define ADCBUF_VDC          (uint16_t)(AD1CH4DATA)<<4    // Range Changed : 0 to 65535 
             
#define MC1_ADCBUF_IA    (int16_t)(HALF_ADC_COUNT - AD1CH0DATA)<<4
#define MC1_ADCBUF_IB    (int16_t)(HALF_ADC_COUNT - AD2CH0DATA)<<4
#define MC1_ADCBUF_POT        (int16_t)AD1CH1DATA
#define MC_ADCBUF_VDC         (int16_t)AD1CH4DATA 
        
#define ADCBUF_IBUS1   (int16_t)((AD1CH2DATA- HALF_ADC_COUNT)<<4)
#define ADCBUF_IBUS2   (int16_t)((AD1CH3DATA- HALF_ADC_COUNT)<<4)      


/* IL (AD1CH6) is the ADC Interrupt source */
#define EnablePFCADCInterrupt()     _AD1CH6IE = 1
#define DisablePFCADCInterrupt()    _AD1CH6IE = 0        
#define ClearPFCADCIF()             _AD1CH6IF = 0   
#define ClearPFCADCIF_ReadADCBUF()  AD1CH6DATA        
#define PFC_ADCInterrupt            _AD1CH6Interrupt           
        
/* POT (AD1CH1) is the ADC Interrupt source in Dual Shunt*/
#define MC1_EnableADCInterrupt()            _AD1CH1IE = 1
#define MC1_DisableADCInterrupt()           _AD1CH1IE = 0
#define MC1_ADC_INTERRUPT                   _AD1CH1Interrupt  
#define MC1_ClearADCIF()           			_AD1CH1IF = 0  
#define MC1_ClearADCIF_ReadADCBUF()        MC1_ADCBUF_POT 

// </editor-fold>       

// <editor-fold defaultstate="collapsed" desc="INTERFACE FUNCTIONS ">        
void InitializeADCs(void);

// </editor-fold> 

#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif
#endif      // end of ADC_H

