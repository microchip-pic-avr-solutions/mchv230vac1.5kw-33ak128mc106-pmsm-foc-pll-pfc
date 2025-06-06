// <editor-fold defaultstate="collapsed" desc="Description/Instruction ">
/**
 * @file diagnostics.h
 *
 * @brief This header file lists the functions and definitions to configure 
 * diagnostics routines for the X2C Scope
 *
 * Component: DIAGNOSTICS - X2C SCOPE
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

#ifndef __DIAGNOSTICS_H
#define __DIAGNOSTICS_H

#ifdef __cplusplus
extern "C" {
#endif
    
// <editor-fold defaultstate="collapsed" desc="DEFINITIONS/CONSTANTS ">
    
#define ENABLE_DIAGNOSTICS   

// </editor-fold>    
    
// <editor-fold defaultstate="expanded" desc="INTERFACE FUNCTIONS ">
    
/**
 * Initializes diagnostics
 */
void DiagnosticsInit(void);

/**
 * Executes diagnostic tasks during the controller ISR
 */
void DiagnosticsStepIsr(void);

/**
 * Executes diagnostic tasks during the main loop
 */
void DiagnosticsStepMain(void);

// </editor-fold>

#ifdef __cplusplus
}
#endif

#endif /* end of __DIAGNOSTICS_H */
