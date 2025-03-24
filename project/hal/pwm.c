// <editor-fold defaultstate="collapsed" desc="Description/Instruction ">
/**
 * @file pwm.c
 *
 * @brief This module configures and enables the PWM Module 
 * 
 * Definitions in this file are for dsPIC33AK128MC106
 *
 * Component: PWM
 *
 */
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Disclaimer ">

/*******************************************************************************
* SOFTWARE LICENSE AGREEMENT
* 
* © [2024] Microchip Technology Inc. and its subsidiaries
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

// <editor-fold defaultstate="collapsed" desc="HEADER FILES ">

#include <xc.h>
#include <stdint.h>
#include "pwm.h"

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="INTERFACE FUNCTIONS ">

/**
* <B> Function: InitPWMGenerators()    </B>
*
* @brief Function initializes the registers common for all PWM modules and 
* configures individual PWM module. The function enables the PWM module 
* and completes the boot strap charging sequence
*        
* @param none.
* @return none.
* 
* @example
* <CODE> InitPWMGenerators();     </CODE>
*
*/
void InitPWMGenerators(void)
{

    PCLKCON      = 0x0000;
    /* PWM Clock Divider Selection bits
       0b11 = 1:16 ; 0b10 = 1:8 ;0b01 = 1:4 ; 0b00 = 1:2*/
    PCLKCONbits.DIVSEL = 0;
    /* PWM Master Clock Selection bits
       1 = CLKGEN5 ; 0 = UPB clock */
    PCLKCONbits.MCLKSEL = 1;
    /* Lock bit: 0 = Write-protected registers and bits are unlocked   */
    PCLKCONbits.LOCK = 0;

    /* Initialize Master Phase Register */
    MPHASE       = 0x0000;
    /* Initialize Master Duty Cycle */
    MDC          = 0x0000;
    /* Initialize Master Period Register */
    MPER         = LOOPTIME_TCY;
    
    /* Initialize FREQUENCY SCALE REGISTER*/
    FSCL          = 0x0000;
    /* Initialize FREQUENCY SCALING MINIMUM PERIOD REGISTER */
    FSMINPER     = 0x0000;
    /* Initialize Linear Feedback Shift Register */
    LFSR         = 0x0000;
    /* Initialize Combinational Trigger Register */
    CMBTRIG     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 1 */
    LOGCONA     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 1 */
    LOGCONB     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 2 */
    LOGCONC     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 2 */
    LOGCOND     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 3 */
    LOGCONE     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 3 */
    LOGCONF     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER A */
    PWMEVTA     = 0x0000;     
    /* PWM EVENT OUTPUT CONTROL REGISTER B */
    PWMEVTB     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER C */
    PWMEVTC     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER D */
    PWMEVTD     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER E */
    PWMEVTE     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER F */
    PWMEVTF     = 0x0000;
    
    
        /* PWM Event Output Enable bit  
       1 = Event output signal is output on PWMEy pin
       0 = Event output signal is internal only */
    PWMEVTAbits.EVTAOEN  = 1;
    /* EVTyPOL: PWM Event Output Polarity bit
       1 = Event output signal is active-low
       0 = Event output signal is active-high */
    PWMEVTAbits.EVTAPOL  = 0;
    /* EVTySTRD: PWM Event Output Stretch Disable bit
       1 = Event output signal pulse width is not stretched
       0 = Event output signal is stretched to eight PWM clock cycles minimum */
    PWMEVTAbits.EVTASTRD = 1; 
    /* EVTySYNC: PWM Event Output Sync bit
       1 = Event output signal is synchronized to the system clock
       0 = Event output is not synchronized to the system clock
       Event output signal pulse will be two system clocks when this bit is set and EVTySTRD = 1 */
    PWMEVTAbits.EVTASYNC = 1;
    /* EVTySEL[3:0]: PWM Event Selection bits
       1111-1010 = Reserved
       1001 = ADC Trigger 2 signal
       1000 = ADC Trigger 1 signal
       0111 = STEER signal (available in Push-Pull Output modes only)(4)
       0110 = CAHALF signal (available in Center-Aligned modes only)(4)
       0101 = PCI Fault active output signal
       0100 = PCI Current limit active output signal
       0011 = PCI Feed-forward active output signal
       0010 = PCI Sync active output signal
       0001 = PWM Generator output signal(3)
       0000 = Source is selected by the PGTRGSEL[2:0] bits */
    PWMEVTAbits.EVTASEL  = 0b1000;
    /* EVTyPGS[2:0]: PWM Event Source Selection bits
       111-100 = Reserved
       011 = PWM Generator 4
       ...
       000 = PWM Generator 1 */
    PWMEVTAbits.EVTAPGS  = 3;
    
    
    
    /* PWM Event Output Enable bit  
       1 = Event output signal is output on PWMEy pin
       0 = Event output signal is internal only */
    PWMEVTBbits.EVTBOEN  = 1;
    /* EVTyPOL: PWM Event Output Polarity bit
       1 = Event output signal is active-low
       0 = Event output signal is active-high */
    PWMEVTBbits.EVTBPOL  = 0;
    /* EVTySTRD: PWM Event Output Stretch Disable bit
       1 = Event output signal pulse width is not stretched
       0 = Event output signal is stretched to eight PWM clock cycles minimum */
    PWMEVTBbits.EVTBSTRD = 1; 
    /* EVTySYNC: PWM Event Output Sync bit
       1 = Event output signal is synchronized to the system clock
       0 = Event output is not synchronized to the system clock
       Event output signal pulse will be two system clocks when this bit is set and EVTySTRD = 1 */
    PWMEVTBbits.EVTBSYNC = 1;
    /* EVTySEL[3:0]: PWM Event Selection bits
       1111-1010 = Reserved
       1001 = ADC Trigger 2 signal
       1000 = ADC Trigger 1 signal
       0111 = STEER signal (available in Push-Pull Output modes only)(4)
       0110 = CAHALF signal (available in Center-Aligned modes only)(4)
       0101 = PCI Fault active output signal
       0100 = PCI Current limit active output signal
       0011 = PCI Feed-forward active output signal
       0010 = PCI Sync active output signal
       0001 = PWM Generator output signal(3)
       0000 = Source is selected by the PGTRGSEL[2:0] bits */
    PWMEVTBbits.EVTBSEL  = 0b1000;
    /* EVTyPGS[2:0]: PWM Event Source Selection bits
       111-100 = Reserved
       011 = PWM Generator 4
       ...
       000 = PWM Generator 1 */
    PWMEVTBbits.EVTBPGS  = 0;
    
    /* Function call to Initialize individual PWM modules*/
    InitPWMGenerator1 ();
    InitPWMGenerator2 ();
    InitPWMGenerator3 (); 
    InitPWMGenerator4 ();
    
    InitDutyPWM123Generators();

    /* Clearing and disabling PWM Interrupt */
    _PWM1IF = 0;
    _PWM1IE = 0;
    _PWM1IP = 7;
    
    /* Enable the PWM module after initializing generators*/ 
	PG2CONbits.ON = 1;      
    PG3CONbits.ON = 1;      
    PG1CONbits.ON = 1;   
    PG4CONbits.ON = 1;

    /* Function call to charge Bootstrap capacitors*/
    ChargeBootstrapCapacitors();
}
/**
* <B> Function: InitDutyPWM123Generators()    </B>
*
* @brief Function initialize the duty to zero by overriding and 
* reset the duty registers for Boot strap charging
*        
* @param none.
* @return none.
* 
* @example
* <CODE> InitDutyPWM123Generators();     </CODE>
*
*/
void InitDutyPWM123Generators(void)
{
    
    /** Set Override Data on all PWM outputs */
    /* 0b00 = State for PWM3H,L, if Override is Enabled */
    PG3IOCONbits.OVRDAT = 0;
    /* 0b00 = State for PWM2H,L, if Override is Enabled */
    PG2IOCONbits.OVRDAT = 0; 
    /* 0b00 = State for PWM1H,L, if Override is Enabled */
    PG1IOCONbits.OVRDAT = 0; 

    /* 1 = OVRDAT<1> provides data for output on PWM3H */
    PG3IOCONbits.OVRENH = 1; 
    /* 1 = OVRDAT<0> provides data for output on PWM3L */
    PG3IOCONbits.OVRENL = 1; 
    
    /* 1 = OVRDAT<1> provides data for output on PWM2H */
    PG2IOCONbits.OVRENH = 1;
    /* 1 = OVRDAT<0> provides data for output on PWM2L */
    PG2IOCONbits.OVRENL = 1; 
    
    /* 1 = OVRDAT<1> provides data for output on PWM1H */
    PG1IOCONbits.OVRENH = 1;  
    /* 1 = OVRDAT<0> provides data for output on PWM1L */
    PG1IOCONbits.OVRENL = 1;  

    /* Set all PWM Duty to zero */
    PG3DC = 0;
    PG2DC = 0;      
    PG1DC = 0;

}
/**
* <B> Function: ChargeBootstrapCapacitors()    </B>
*
* @brief Function to implement Boot Strap Capacitor charging sequence
*        
* @param none.
* @return none.
* 
* @example
* <CODE> ChargeBootstrapCapacitors();     </CODE>
*
*/
void ChargeBootstrapCapacitors(void)
{
    uint32_t i = BOOTSTRAP_CHARGING_COUNTS;
    uint16_t prevStatusCAHALF = 0,currStatusCAHALF = 0;

    /* Enable PWMs only on PWMxL ,to charge bootstrap capacitors at the beginning
     * Hence PWMxH is over-ridden to "LOW" */
    /* 0b00 = State for PWM3H-L,PWM2H-L and PWM1H-L if Override is Enabled*/
    PG3IOCONbits.OVRDAT = 0;  
    PG2IOCONbits.OVRDAT = 0;  
    PG1IOCONbits.OVRDAT = 0; 
    
    /* 1 = OVRDAT<1> provides data for output on PWM3H,PWM2H and PWM1H*/
    PG3IOCONbits.OVRENH = 1;  
    PG2IOCONbits.OVRENH = 1;  
    PG1IOCONbits.OVRENH = 1;  

    /* 1 = OVRDAT<1> provides data for output on PWM3L,PWM2L and PWM1L*/
    PG3IOCONbits.OVRENL = 1;  
    PG2IOCONbits.OVRENL = 1;  
    PG1IOCONbits.OVRENL = 1;  

    /* PDCx: PWMx GENERATOR DUTY CYCLE REGISTER
     * Initialize the PWM duty cycle for charging */
    MC1_PWM_PHASE3 = TICKLE_CHARGE_DUTY;
    MC1_PWM_PHASE2 = TICKLE_CHARGE_DUTY;
    MC1_PWM_PHASE1 = TICKLE_CHARGE_DUTY;
    MC1_PWM_PDC3 = TICKLE_CHARGE_DUTY;
    MC1_PWM_PDC2 = TICKLE_CHARGE_DUTY;
    MC1_PWM_PDC1 = TICKLE_CHARGE_DUTY;
    
    /* 0 = PWM generator provides data for PWM1L/2L/3L pin */
    PG1IOCONbits.OVRENL = 0;
    PG2IOCONbits.OVRENL = 0;  
    PG3IOCONbits.OVRENL = 0; 

    /*While loop for the Bootstrap charging time in number of PWM Half Cycles*/
    while(i)
    {
        prevStatusCAHALF = currStatusCAHALF;
        currStatusCAHALF = PG1STATbits.CAHALF;
        if (prevStatusCAHALF != currStatusCAHALF)
        {
            /*Monitoring the Bootstrap charging time in number of PWM Half Cycles*/
            if (currStatusCAHALF == 0)
            {
                i--; 
            }
        }
    }
    /* PDCx: PWMx GENERATOR DUTY CYCLE REGISTER
     * Reset the PWM duty cycle to zero after charging */
    MC1_PWM_PHASE3 = 0;
    MC1_PWM_PHASE2 = 0;
    MC1_PWM_PHASE1 = 0;
    MC1_PWM_PDC3 = 0;
    MC1_PWM_PDC2 = 0;
    MC1_PWM_PDC1 = 0;

    /* 0 = PWM generator provides data for output on PWM3H,PWM2H and PWM1H*/
    PG3IOCONbits.OVRENH = 0;  
    PG2IOCONbits.OVRENH = 0;  
    PG1IOCONbits.OVRENH = 0;   
     
}
/**
* <B> Function: InitPWMGenerator1()    </B>
*
* @brief Function to configure PWM Module # 1
*        
* @param none.
* @return none.
* 
* @example
* <CODE> InitPWMGenerator1();     </CODE>
*
*/
void InitPWMGenerator1 (void)
{

    /* Initialize PWM GENERATOR 1 CONTROL REGISTER LOW */
    PG1CON      = 0x0000;
    /* PWM Generator 1 Enable bit : 1 = Is enabled, 0 = Is not enabled */
    /* Ensuring PWM Generator is disabled prior to configuring module */
    PG1CONbits.ON = 0;
    /* Clock Selection bits
       0b01 = Macro uses Master clock selected by the PCLKCON.MCLKSEL bits*/
    PG1CONbits.CLKSEL = 1;
    /* PWM Mode Selection bits
     * 110 = Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
       100 = Center-Aligned PWM mode(interrupt/register update once per cycle)*/
#ifdef SINGLE_SHUNT
    PG1CONbits.MODSEL = 6;
#else
    PG1CONbits.MODSEL = 4;
#endif 
    /* Trigger Count Select bits
       000 = PWM Generator produces 1 PWM cycle after triggered */
    PG1CONbits.TRGCNT = 0;
    
    /* Initialize PWM GENERATOR 1 CONTROL REGISTER HIGH */
    /* Master Duty Cycle Register Select bit
       1 = Macro uses the MDC register instead of PG1DC
       0 = Macro uses the PG1DC register*/
    PG1CONbits.MDCSEL = 0;
    /* Master Period Register Select bit
       1 = Macro uses the MPER register instead of PG1PER
       0 = Macro uses the PG1PER register */
    PG1CONbits.MPERSEL = 1;
    /* MPHSEL: Master Phase Register Select bit
       1 = Macro uses the MPHASE register instead of PG1PHASE
       0 = Macro uses the PG1PHASE register */
    PG1CONbits.MPHSEL = 0;
    /* Master Update Enable bit
       1 = PWM Generator broadcasts software set/clear of UPDATE status bit and 
           EOC signal to other PWM Generators
       0 = PWM Generator does not broadcast UPDATE status bit or EOC signal */
    PG1CONbits.MSTEN = 1;
    /* PWM Buffer Update Mode Selection bits 
       Update Data registers at start of next PWM cycle if UPDATE = 1. */
    PG1CONbits.UPDMOD = 0;
    /* PWM Generator Trigger Mode Selection bits
       0b00 = PWM Generator operates in Single Trigger mode */
    PG1CONbits.TRGMOD = 1;
    /* Start of Cycle Selection bits
       0000 = Local EOC*/
    PG1CONbits.SOCS = 0xF;
    
    /* Clear PWM GENERATOR 1 STATUS REGISTER*/
    PG1STAT      = 0x0000;
    /* Initialize PWM GENERATOR 1 I/O CONTROL REGISTER LOW */
    PG1IOCON    = 0x0000;

    /* Current Limit Mode Select bit
       0 = If PCI current limit is active, then the CLDAT<1:0> bits define 
       the PWM output levels */
    PG1IOCONbits.CLMOD = 0;
    /* Swap PWM Signals to PWM1H and PWM1L Device Pins bit 
       0 = PWM1H/L signals are mapped to their respective pins */
    PG1IOCONbits.SWAP = 0;
    /* User Override Enable for PWM1H Pin bit
       0 = PWM Generator provides data for the PWM1H pin*/
    PG1IOCONbits.OVRENH = 0;
    /* User Override Enable for PWM1L Pin bit
       0 = PWM Generator provides data for the PWM1L pin*/
    PG1IOCONbits.OVRENL = 0;
    /* Data for PWM1H/PWM1L Pins if Override is Enabled bits
       If OVERENH = 1, then OVRDAT<1> provides data for PWM1H.
       If OVERENL = 1, then OVRDAT<0> provides data for PWM1L */
    PG1IOCONbits.OVRDAT = 0;
    /* User Output Override Synchronization Control bits
       00 = User output overrides via the OVRENL/H and OVRDAT<1:0> bits are 
       synchronized to the local PWM time base (next start of cycle)*/
    PG1IOCONbits.OSYNC = 0;
    /* Data for PWM1H/PWM1L Pins if FLT Event is Active bits
       If Fault is active, then FLTDAT<1> provides data for PWM1H.
       If Fault is active, then FLTDAT<0> provides data for PWM1L.*/
    PG1IOCONbits.FLTDAT = 0;
    /* Data for PWM1H/PWM1L Pins if CLMT Event is Active bits
       If current limit is active, then CLDAT<1> provides data for PWM1H.
       If current limit is active, then CLDAT<0> provides data for PWM1L.*/
    PG1IOCONbits.CLDAT = 0;
    /* Data for PWM1H/PWM1L Pins if Feed-Forward Event is Active bits
       If feed-forward is active, then FFDAT<1> provides data for PWM1H.
       If feed-forward is active, then FFDAT<0> provides data for PWM1L.*/
    PG1IOCONbits.FFDAT = 0;
    /* Data for PWM1H/PWM1L Pins if Debug Mode is Active and PTFRZ = 1 bits
       If Debug mode is active and PTFRZ=1,then DBDAT<1> provides PWM1H data.
       If Debug mode is active and PTFRZ=1,then DBDAT<0> provides PWM1L data. */
    PG1IOCONbits.DBDAT = 0;
    
    /* Initialize PWM GENERATOR 1 I/O CONTROL REGISTER HIGH */    

    /* Time Base Capture Source Selection bits
       000 = No hardware source selected for time base capture ? software only*/
    PG1IOCONbits.CAPSRC = 0;
    /* Dead-Time Compensation Select bit 
       0 = Dead-time compensation is controlled by PCI Sync logic */
    PG1IOCONbits.DTCMPSEL = 0;
    /* PWM Generator Output Mode Selection bits
       00 = PWM Generator outputs operate in Complementary mode*/
    PG1IOCONbits.PMOD = 0;
    /* PWM1H Output Port Enable bit
       1 = PWM Generator controls the PWM1H output pin
       0 = PWM Generator does not control the PWM1H output pin */
    PG1IOCONbits.PENH = 1;
    /* PWM1L Output Port Enable bit
       1 = PWM Generator controls the PWM1L output pin
       0 = PWM Generator does not control the PWM1L output pin */
    PG1IOCONbits.PENL = 1;
    /* PWM1H Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG1IOCONbits.POLH = 0;
    /* PWM1L Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG1IOCONbits.POLL = 0;
    
    /* Initialize PWM GENERATOR 1 EVENT REGISTER LOW*/
    PG1EVT      = 0x0000;
    /* ADC Trigger 1 Post-scaler Selection bits
       00000 = 1:1 */
    PG1EVTbits.ADTR1PS = 0;
    /* ADC Trigger 1 Source is PG1TRIGC Compare Event Enable bit
       0 = PG1TRIGC register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG1EVTbits.ADTR1EN3  = 0;
    /* ADC Trigger 1 Source is PG1TRIGB Compare Event Enable bit
       0 = PG1TRIGB register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG1EVTbits.ADTR1EN2 = 0;    
    /* ADC Trigger 1 Source is PG1TRIGA Compare Event Enable bit
       1 = PG1TRIGA register compare event is enabled as trigger source for 
           ADC Trigger 1 */
    PG1EVTbits.ADTR1EN1 = 1;
    /* Update Trigger Select bits
       01 = A write of the PG1DC register automatically sets the UPDATE bit*/
    PG1EVTbits.UPDTRG = 1;
    /* PWM Generator Trigger Output Selection bits
       000 = EOC event is the PWM Generator trigger*/
    PG1EVTbits.PGTRGSEL = 0;
    
    /* Initialize PWM GENERATOR 1 EVENT REGISTER HIGH */
    /* FLTIEN: PCI Fault Interrupt Enable bit
       1 = Fault interrupt is enabled */
    PG1EVTbits.FLTIEN = 1;
    /* PCI Current Limit Interrupt Enable bit
       0 = Current limit interrupt is disabled */
    PG1EVTbits.CLIEN = 0;
    /* PCI Feed-Forward Interrupt Enable bit
       0 = Feed-forward interrupt is disabled */
    PG1EVTbits.FFIEN = 0;
    /* PCI Sync Interrupt Enable bit
       0 = Sync interrupt is disabled */
    PG1EVTbits.SIEN = 0;
    /* Interrupt Event Selection bits
       00 = Interrupts CPU at EOC
       01 = Interrupts CPU at TRIGA compare event
       10 = Interrupts CPU at ADC Trigger 1 event
       11 = Time base interrupts are disabled */
    PG1EVTbits.IEVTSEL = 3;

        /* ADC Trigger 2 Source is PG1TRIGC Compare Event Enable bit
       0 = PG1TRIGC register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTbits.ADTR2EN3 = 0;
    /* ADC Trigger 2 Source is PG1TRIGB Compare Event Enable bit
       0 = PG1TRIGB register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTbits.ADTR2EN2 = 0;
    /* ADC Trigger 2 Source is PG1TRIGA Compare Event Enable bit
       0 = PG1TRIGA register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTbits.ADTR2EN1 = 0;
    /* ADC Trigger 1 Offset Selection bits
       00000 = No offset */
    PG1EVTbits.ADTR1OFS = 0;
    
#ifndef ENABLE_PWM_FAULT_PCI
    /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG1FPCI     = 0x0000;
#else
       /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG1FPCI     = 0x0000;
    /* Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG1FPCIbits.TSYNCDIS = 0;
    /* Termination Event Selection bits
       001 = Auto-Terminate: Terminate when PCI source transitions from 
             active to inactive */
    PG1FPCIbits.TERM = 1;
    /* Acceptance Qualifier Polarity Select bit: 0 = Not inverted 1 = Inverted*/
    PG1FPCIbits.AQPS = 0;
    /* Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to 0)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)        
       000 = No acceptance qualifier is used (qualifier forced to 1) */
    PG1FPCIbits.AQSS = 0;
    /* PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC*/
    PG1FPCIbits.PSYNC = 0;
    /* PCI Polarity Select bit 0 = Not inverted 1 = Inverted */
    PG1FPCIbits.PPS = 1;
    /* PCI Source Selection bits
       11111 = CLC1
       ? ?
       11101 Comparator 3 output
       ? ?
       01000 RPn input, PCI8R
       ? ?
       00001 = Internally connected to the output of PWMPCI[2:0] MUX
       00000 = Tied to ?0? */
    PG1FPCIbits.PSS = 0b11101;
    /* PCI Bypass Enable bit
       0 = PCI function is not bypassed */
    PG1FPCIbits.BPEN   = 0;
    /* PCI Bypass Source Selection bits(1)
       000 = PCI control is sourced from PG1 PCI logic when BPEN = 1 */
    PG1FPCIbits.BPSEL   = 0;
    /* PCI Termination Polarity Select bits 
       0 = Inverter, 1 = Non Inverted */
    PG1FPCIbits.TERMPS = 0;
    /* PCI Acceptance Criteria Selection bits
       101 = Latched any edge(2)
       100 = Latched rising edge
       011 = Latched
       010 = Any edge
       001 = Rising edge
       000 = Level-sensitive*/
    PG1FPCIbits.ACP   = 3;
    /* PCI SR Latch Mode bit
       1 = SR latch is Reset-dominant in Latched Acceptance modes
       0 = SR latch is Set-dominant in Latched Acceptance modes*/
    PG1FPCIbits.LATMOD  = 0;
    /* Termination Qualifier Polarity Select bit 1 = Inverted 0 = Not inverted*/
    PG1FPCIbits.TQPS   = 0;
    /* Termination Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to '0')(3)
       110 = Selects PCI Source #9 (pwm_pci[9] input port)
       101 = Selects PCI Source #8 (pwm_pci[8] input port)
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No termination qualifier used (qualifier forced to '1')(3)*/
    PG1FPCIbits.TQSS  = 3;
#endif    

    /* PWM GENERATOR 1 Current Limit PCI REGISTER LOW */
    PG1CLPCI    = 0x0000;
    /* PWM GENERATOR 1 Feed Forward PCI REGISTER LOW */
    PG1FFPCI    = 0x0000;
    /* PWM GENERATOR 1 Sync PCI REGISTER LOW */
    PG1SPCI     = 0x0000;
    
    /* TSYNCDIS: Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG1SPCIbits.TSYNCDIS = 1;
    /* TERM[2:0]: Termination Event Selection bits
       111 = Selects PCI Source #9
       110 = Selects PCI Source #8
       101 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI[2:0] bits)
       100 = PGxTRIGC trigger event
       011 = PGxTRIGB trigger event
       010 = PGxTRIGA trigger event
       001 = Auto-Terminate: Terminate when PCI source transitions from active to inactive
       000 = Manual Terminate: Terminate on a write of ?1? to the SWTERM bit location */
    PG1SPCIbits.TERM = 1;
    /* AQPS: Acceptance Qualifier Polarity Select bit
       1 = Inverted
       0 = Not inverted */
    PG1SPCIbits.AQPS = 0;
    /* AQSS[2:0]: Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to ?0?)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI[2:0] bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No acceptance qualifier is used (qualifier forced to ?1?) */    
    PG1SPCIbits.AQSS = 0;
    /* PSYNC: PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC */
    PG1SPCIbits.PSYNC = 0;
    /* PPS: PCI Polarity Select bit
       1 = Inverted
       0 = Not inverted */
    PG1SPCIbits.PPS = 0;
    /* PSS[4:0]: PCI Source Selection bits
       11111 = CLC1
       11110-11100 = Reserved
       11011 = Comparator 1 output
       11010 = PWM Event D
       11001 = PWM Event C
       11000 = PWM Event B
       10111 = PWM Event A
       10110-10100 = Reserved
       10011 = Device pin, PCI[19]
       10010 = RPn input, PCI18R
       10001 = RPn input, PCI17R
       10000 = RPn input, PCI16R
       01111 = RPn input, PCI15R
       01110 = RPn input, PCI14R
       01101 = RPn input, PCI13R
       01100 = RPn input, PCI12R
       01011 = RPn input, PCI11R
       01010 = RPn input, PCI10R
       01001 = RPn input, PCI9R
       01000 = RPn input, PCI8R
       00100-00111 = Reserved
       00011 = Internally connected to Combo Trigger B
       00010 = Internally connected to Combo Trigger A
       00001 = Internally connected to the output of PWMPCI[2:0] MUX
       00000 = Tied to ?0? */
    PG1SPCIbits.PSS = 0b10111;
    
    /* Initialize PWM GENERATOR 1 LEADING-EDGE BLANKING REGISTER LOW */
    PG1LEB      = 0x0000;
    
    /* Initialize PWM GENERATOR 1 PHASE REGISTER */
    PG1PHASE     = MIN_DUTY;
    /* Initialize PWM GENERATOR 1 DUTY CYCLE REGISTER */
    PG1DC        = MIN_DUTY;
    /* Initialize PWM GENERATOR 1 DUTY CYCLE ADJUSTMENT REGISTER */
    PG1DCA       = 0x0000;
    /* Initialize PWM GENERATOR 1 PERIOD REGISTER */
    PG1PER       = 0x0000;
    /* Initialize PWM GENERATOR 1 DEAD-TIME REGISTER LOW */
    PG1DTbits.DTH       = DEADTIME;
    /* Initialize PWM GENERATOR 1 DEAD-TIME REGISTER HIGH */
    PG1DTbits.DTL      = DEADTIME;

    /* Initialize PWM GENERATOR 1 TRIGGER A REGISTER */
    PG1TRIGA     = ADC_SAMPLING_POINT;
    /* Initialize PWM GENERATOR 1 TRIGGER B REGISTER */
    PG1TRIGB     = 0x0000;
    /* Initialize PWM GENERATOR 1 TRIGGER C REGISTER */
    PG1TRIGC     = 0x0000;
    
} 
/**
* <B> Function: InitPWMGenerator2()    </B>
*
* @brief Function to configure PWM Module # 2
*        
* @param none.
* @return none.
* 
* @example
* <CODE> InitPWMGenerator2();     </CODE>
*
*/
void InitPWMGenerator2 (void)
{

    /* Initialize PWM GENERATOR 2 CONTROL REGISTER LOW */
    PG2CON      = 0x0000;
    /* PWM Generator 2 Enable bit : 1 = Is enabled, 0 = Is not enabled */
    /* PWM Generator is disabled prior to configuring module */
    PG2CONbits.ON = 0;
    /* Clock Selection bits
       0b01 = Macro uses Master clock selected by the PCLKCON.MCLKSEL bits*/
    PG2CONbits.CLKSEL = 1;
    /* PWM Mode Selection bits
     * 110 = Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
       100 = Center-Aligned PWM mode(interrupt/register update once per cycle)*/
#ifdef SINGLE_SHUNT
    PG2CONbits.MODSEL = 6;
#else
    PG2CONbits.MODSEL = 4;
#endif 
    /* Trigger Count Select bits
       000 = PWM Generator produces 1 PWM cycle after triggered */
    PG2CONbits.TRGCNT = 0;
    
    /* Initialize PWM GENERATOR 2 CONTROL REGISTER HIGH */
    /* Master Duty Cycle Register Select bit
       1 = Macro uses the MDC register instead of PG2DC
       0 = Macro uses the PG2DC register*/
    PG2CONbits.MDCSEL = 0;
    /* Master Period Register Select bit
       1 = Macro uses the MPER register instead of PG2PER
       0 = Macro uses the PG2PER register */
    PG2CONbits.MPERSEL = 1;
    /* MPHSEL: Master Phase Register Select bit
       1 = Macro uses the MPHASE register instead of PG2PHASE
       0 = Macro uses the PG2PHASE register */
    PG2CONbits.MPHSEL = 0;
    /* Master Update Enable bit
       1 = PWM Generator broadcasts software set/clear of UPDATE status bit and 
           EOC signal to other PWM Generators
       0 = PWM Generator does not broadcast UPDATE status bit or EOC signal */
    PG2CONbits.MSTEN = 0;
     /* PWM Buffer Update Mode Selection bits 
       0b010 = Slaved SOC Update Data registers at start of next cycle if a 
       master update request is received. A master update request will be 
       transmitted if MSTEN = 1 and UPDATE = 1 for the requesting PWM
       Generator.. */
	PG2CONbits.UPDMOD = 0b010;
    /* PWM Generator Trigger Mode Selection bits
       0b00 = PWM Generator operates in Single Trigger mode */
    PG2CONbits.TRGMOD = 0;
    /* Start of Cycle Selection bits
       0001 = PWM1 trigger o/p selected by PG1 PGTRGSEL<2:0> bits(PGxEVT<2:0>)*/
    PG2CONbits.SOCS = 1;
    
    /* Clear PWM GENERATOR 2 STATUS REGISTER*/
    PG2STAT      = 0x0000;
    /* Initialize PWM GENERATOR 2 I/O CONTROL REGISTER LOW */
    PG2IOCON    = 0x0000;

    /* Current Limit Mode Select bit
       0 = If PCI current limit is active, then the CLDAT<1:0> bits define 
       the PWM output levels */
    PG2IOCONbits.CLMOD = 0;
    /* Swap PWM Signals to PWM2H and PWM2L Device Pins bit 
       0 = PWM2H/L signals are mapped to their respective pins */
    PG2IOCONbits.SWAP = 0;
    /* User Override Enable for PWM2H Pin bit
       0 = PWM Generator provides data for the PWM2H pin*/
    PG2IOCONbits.OVRENH = 0;
    /* User Override Enable for PWM2L Pin bit
       0 = PWM Generator provides data for the PWM2L pin*/
    PG2IOCONbits.OVRENL = 0;
    /* Data for PWM2H/PWM2L Pins if Override is Enabled bits
       If OVERENH = 1, then OVRDAT<1> provides data for PWM2H.
       If OVERENL = 1, then OVRDAT<0> provides data for PWM2L */
    PG2IOCONbits.OVRDAT = 0;
    /* User Output Override Synchronization Control bits
       00 = User output overrides via the OVRENL/H and OVRDAT<1:0> bits are 
       synchronized to the local PWM time base (next start of cycle)*/
    PG2IOCONbits.OSYNC = 0;
    /* Data for PWM2H/PWM2L Pins if FLT Event is Active bits
       If Fault is active, then FLTDAT<1> provides data for PWM2H.
       If Fault is active, then FLTDAT<0> provides data for PWM2L.*/
    PG2IOCONbits.FLTDAT = 0;
    /* Data for PWM2H/PWM2L Pins if CLMT Event is Active bits
       If current limit is active, then CLDAT<1> provides data for PWM2H.
       If current limit is active, then CLDAT<0> provides data for PWM2L.*/
    PG2IOCONbits.CLDAT = 0;
    /* Data for PWM2H/PWM2L Pins if Feed-Forward Event is Active bits
       If feed-forward is active, then FFDAT<1> provides data for PWM2H.
       If feed-forward is active, then FFDAT<0> provides data for PWM2L.*/
    PG2IOCONbits.FFDAT = 0;
    /* Data for PWM2H/PWM2L Pins if Debug Mode is Active and PTFRZ = 1 bits
       If Debug mode is active and PTFRZ=1,then DBDAT<1> provides PWM2H data.
       If Debug mode is active and PTFRZ=1,then DBDAT<0> provides PWM2L data. */
    PG2IOCONbits.DBDAT = 0;
    
    /* Initialize PWM GENERATOR 2 I/O CONTROL REGISTER HIGH */    
    /* Time Base Capture Source Selection bits
       000 = No hardware source selected for time base capture ? software only*/
    PG2IOCONbits.CAPSRC = 0;
    /* Dead-Time Compensation Select bit 
       0 = Dead-time compensation is controlled by PCI Sync logic */
    PG2IOCONbits.DTCMPSEL = 0;
    /* PWM Generator Output Mode Selection bits
       00 = PWM Generator outputs operate in Complementary mode*/
    PG2IOCONbits.PMOD = 0;
    /* PWM2H Output Port Enable bit
       1 = PWM Generator controls the PWM2H output pin
       0 = PWM Generator does not control the PWM2H output pin */
    PG2IOCONbits.PENH = 1;
    /* PWM2L Output Port Enable bit
       1 = PWM Generator controls the PWM2L output pin
       0 = PWM Generator does not control the PWM2L output pin */
    PG2IOCONbits.PENL = 1;
    /* PWM2H Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG2IOCONbits.POLH = 0;
    /* PWM2L Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG2IOCONbits.POLL = 0;
    
    /* Initialize PWM GENERATOR 2 EVENT REGISTER LOW*/
    PG2EVT      = 0x0000;
    /* ADC Trigger 1 Post-scaler Selection bits
       00000 = 1:1 */
    PG2EVTbits.ADTR1PS = 0;
    /* ADC Trigger 1 Source is PG2TRIGC Compare Event Enable bit
       0 = PG2TRIGC register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG2EVTbits.ADTR1EN3  = 0;
#ifdef SINGLE_SHUNT
    /* ADC Trigger 1 Source is PG2TRIGB Compare Event Enable bit
       1 = PG2TRIGB register compare event is enabled as trigger source for 
           ADC Trigger 1 */
    PG2EVTbits.ADTR1EN2 = 1;
#else
    /* ADC Trigger 1 Source is PG2TRIGB Compare Event Enable bit
       0 = PG2TRIGB register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG2EVTbits.ADTR1EN2 = 0;
#endif
    /* ADC Trigger 1 Source is PG2TRIGA Compare Event Enable bit
       0 = PG2TRIGA register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG2EVTbits.ADTR1EN1 = 0;
    /* Update Trigger Select bits
       01 = A write of the PG2DC register automatically sets the UPDATE bit
       00 = User must set the UPDATE bit manually*/
    PG2EVTbits.UPDTRG = 1;
    /* PWM Generator Trigger Output Selection bits
       000 = EOC event is the PWM Generator trigger*/
    PG2EVTbits.PGTRGSEL = 0;
    
    /* Initialize PWM GENERATOR 2 EVENT REGISTER HIGH */
    /* FLTIEN: PCI Fault Interrupt Enable bit
       0 = Fault interrupt is disabled */
    PG2EVTbits.FLTIEN = 0;
    /* PCI Current Limit Interrupt Enable bit
       0 = Current limit interrupt is disabled */
    PG2EVTbits.CLIEN = 0;
    /* PCI Feed-Forward Interrupt Enable bit
       0 = Feed-forward interrupt is disabled */
    PG2EVTbits.FFIEN = 0;
    /* PCI Sync Interrupt Enable bit
       0 = Sync interrupt is disabled */
    PG2EVTbits.SIEN = 0;
    /* Interrupt Event Selection bits
       00 = Interrupts CPU at EOC
       01 = Interrupts CPU at TRIGA compare event
       10 = Interrupts CPU at ADC Trigger 1 event
       11 = Time base interrupts are disabled */
    PG2EVTbits.IEVTSEL = 3;
#ifdef SINGLE_SHUNT
    /* ADC Trigger 2 Source is PG2TRIGC Compare Event Enable bit
       1 = PG2TRIGC register compare event is enabled as 
           trigger source for ADC Trigger 2 */
    PG2EVTbits.ADTR2EN3 = 1;    
#else
    /* ADC Trigger 2 Source is PG2TRIGC Compare Event Enable bit
       0 = PG2TRIGC register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG2EVTbits.ADTR2EN3 = 0;
#endif
    /* ADC Trigger 2 Source is PG2TRIGB Compare Event Enable bit
       0 = PG2TRIGB register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG2EVTbits.ADTR2EN2 = 0;
    /* ADC Trigger 2 Source is PG2TRIGA Compare Event Enable bit
       0 = PG2TRIGA register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG2EVTbits.ADTR2EN1 = 0;
    /* ADC Trigger 1 Offset Selection bits
       00000 = No offset */
    PG2EVTbits.ADTR1OFS = 0;
    
#ifndef ENABLE_PWM_FAULT_PCI
    /* PWM GENERATOR 2 Fault PCI REGISTER */
    PG2FPCI     = 0x0000;
#else
       /* PWM GENERATOR 2 Fault PCI REGISTER */
    PG2FPCI     = 0x0000;
    /* Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG2FPCIbits.TSYNCDIS = 0;
    /* Termination Event Selection bits
       001 = Auto-Terminate: Terminate when PCI source transitions from 
             active to inactive */
    PG2FPCIbits.TERM = 1;
    /* Acceptance Qualifier Polarity Select bit: 0 = Not inverted 1 = Inverted*/
    PG2FPCIbits.AQPS = 0;
    /* Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to 0)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)        
       000 = No acceptance qualifier is used (qualifier forced to 1) */
    PG2FPCIbits.AQSS = 0;
    /* PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC*/
    PG2FPCIbits.PSYNC = 0;
    /* PCI Polarity Select bit 0 = Not inverted 1 = Inverted */
    PG2FPCIbits.PPS = 1;
    /* PCI Source Selection bits
       11111 = CLC1
       ? ?
       11101 Comparator 3 output
       ? ?
       01000 RPn input, PCI8R
       ? ?
       00001 = Internally connected to the output of PWMPCI[2:0] MUX
       00000 = Tied to ?0? */
    PG2FPCIbits.PSS = 0b11101;
    /* PCI Bypass Enable bit
       0 = PCI function is not bypassed */
    PG2FPCIbits.BPEN   = 0;
    /* PCI Bypass Source Selection bits(1)
       000 = PCI control is sourced from PG1 PCI logic when BPEN = 1 */
    PG2FPCIbits.BPSEL   = 0;
    /* PCI Termination Polarity Select bits 
       0 = Inverter, 1 = Non Inverted */
    PG2FPCIbits.TERMPS = 0;
    /* PCI Acceptance Criteria Selection bits
       101 = Latched any edge(2)
       100 = Latched rising edge
       011 = Latched
       010 = Any edge
       001 = Rising edge
       000 = Level-sensitive*/
    PG2FPCIbits.ACP   = 3;
    /* PCI SR Latch Mode bit
       1 = SR latch is Reset-dominant in Latched Acceptance modes
       0 = SR latch is Set-dominant in Latched Acceptance modes*/
    PG2FPCIbits.LATMOD  = 0;
    /* Termination Qualifier Polarity Select bit 1 = Inverted 0 = Not inverted*/
    PG2FPCIbits.TQPS   = 0;
    /* Termination Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to '0')(3)
       110 = Selects PCI Source #9 (pwm_pci[9] input port)
       101 = Selects PCI Source #8 (pwm_pci[8] input port)
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No termination qualifier used (qualifier forced to '1')(3)*/
    PG2FPCIbits.TQSS  = 3;
#endif  
    
    /* PWM GENERATOR 2 Current Limit PCI REGISTER LOW */
    PG2CLPCI    = 0x0000;
    /* PWM GENERATOR 2 Feed Forward PCI REGISTER LOW */
    PG2FFPCI    = 0x0000;
    /* PWM GENERATOR 2 Sync PCI REGISTER LOW */
    PG2SPCI     = 0x0000;
    
    /* Initialize PWM GENERATOR 2 LEADING-EDGE BLANKING REGISTER LOW */
    PG2LEB      = 0x0000;
    
    /* Initialize PWM GENERATOR 2 PHASE REGISTER */
    PG2PHASE     = MIN_DUTY;
    /* Initialize PWM GENERATOR 2 DUTY CYCLE REGISTER */
    PG2DC        = MIN_DUTY;
    /* Initialize PWM GENERATOR 2 DUTY CYCLE ADJUSTMENT REGISTER */
    PG2DCA       = 0x0000;
    /* Initialize PWM GENERATOR 2 PERIOD REGISTER */
    PG2PER       = 0x0000;
    /* Initialize PWM GENERATOR 2 DEAD-TIME REGISTER LOW */
    PG2DTbits.DTH       = DEADTIME;
    /* Initialize PWM GENERATOR 2 DEAD-TIME REGISTER HIGH */
    PG2DTbits.DTL       = DEADTIME;

    /* Initialize PWM GENERATOR 2 TRIGGER A REGISTER */
    PG2TRIGA     = 0x0000;
    /* Initialize PWM GENERATOR 2 TRIGGER B REGISTER */
    PG2TRIGB     = 0x0000;
    /* Initialize PWM GENERATOR 2 TRIGGER C REGISTER */
    PG2TRIGC     = 0x0000;
    
}
/**
* <B> Function: InitPWMGenerator3()    </B>
*
* @brief Function to configure PWM Module # 3
*        
* @param none.
* @return none.
* 
* @example
* <CODE> InitPWMGenerator3();     </CODE>
*
*/
void InitPWMGenerator3 (void)
{

    /* Initialize PWM GENERATOR 3 CONTROL REGISTER LOW */
    PG3CON      = 0x0000;
    /* PWM Generator 3 Enable bit : 1 = Is enabled, 0 = Is not enabled */
    /* PWM Generator is disabled prior to configuring module */
    PG3CONbits.ON = 0;
    /* Clock Selection bits
       0b01 = Macro uses Master clock selected by the PCLKCON.MCLKSEL bits*/
    PG3CONbits.CLKSEL = 1;
    /* PWM Mode Selection bits
     * 110 = Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
       100 = Center-Aligned PWM mode(interrupt/register update once per cycle)*/
#ifdef SINGLE_SHUNT
    PG3CONbits.MODSEL = 6;
#else
    PG3CONbits.MODSEL = 4;
#endif    
    /* Trigger Count Select bits
       000 = PWM Generator produces 1 PWM cycle after triggered */
    PG3CONbits.TRGCNT = 0;
    
    /* Initialize PWM GENERATOR 3 CONTROL REGISTER HIGH */
    /* Master Duty Cycle Register Select bit
       1 = Macro uses the MDC register instead of PG3DC
       0 = Macro uses the PG3DC register*/
    PG3CONbits.MDCSEL = 0;
    /* Master Period Register Select bit
       1 = Macro uses the MPER register instead of PG3PER
       0 = Macro uses the PG3PER register */
    PG3CONbits.MPERSEL = 1;
    /* MPHSEL: Master Phase Register Select bit
       1 = Macro uses the MPHASE register instead of PG3PHASE
       0 = Macro uses the PG3PHASE register */
    PG3CONbits.MPHSEL = 1;
    /* Master Update Enable bit
       1 = PWM Generator broadcasts software set/clear of UPDATE status bit and 
           EOC signal to other PWM Generators
       0 = PWM Generator does not broadcast UPDATE status bit or EOC signal */
    PG3CONbits.MSTEN = 0;
    /* PWM Buffer Update Mode Selection bits 
       0b010 = Slaved SOC Update Data registers at start of next cycle if a 
       master update request is received. A master update request will be 
       transmitted if MSTEN = 1 and UPDATE = 1 for the requesting PWM
       Generator.. */
	PG3CONbits.UPDMOD = 0b010;
    /* PWM Generator Trigger Mode Selection bits
       0b00 = PWM Generator operates in Single Trigger mode */
    PG3CONbits.TRGMOD = 0;
    /* Start of Cycle Selection bits
       0001 = PWM1 trigger o/p selected by PG1 PGTRGSEL<2:0> bits(PGxEVT<2:0>)*/
    PG3CONbits.SOCS = 0x1;
    
    /* Clear PWM GENERATOR 3 STATUS REGISTER*/
    PG3STAT      = 0x0000;
    /* Initialize PWM GENERATOR 3 I/O CONTROL REGISTER LOW */
    PG3IOCON    = 0x0000;

    /* Current Limit Mode Select bit
       0 = If PCI current limit is active, then the CLDAT<1:0> bits define 
       the PWM output levels */
    PG3IOCONbits.CLMOD = 0;
    /* Swap PWM Signals to PWM3H and PWM3L Device Pins bit 
       0 = PWM3H/L signals are mapped to their respective pins */
    PG3IOCONbits.SWAP = 0;
    /* User Override Enable for PWM3H Pin bit
       0 = PWM Generator provides data for the PWM3H pin*/
    PG3IOCONbits.OVRENH = 0;
    /* User Override Enable for PWM3L Pin bit
       0 = PWM Generator provides data for the PWM3L pin*/
    PG3IOCONbits.OVRENL = 0;
    /* Data for PWM3H/PWM3L Pins if Override is Enabled bits
       If OVERENH = 1, then OVRDAT<1> provides data for PWM3H.
       If OVERENL = 1, then OVRDAT<0> provides data for PWM3L */
    PG3IOCONbits.OVRDAT = 0;
    /* User Output Override Synchronization Control bits
       00 = User output overrides via the OVRENL/H and OVRDAT<1:0> bits are 
       synchronized to the local PWM time base (next start of cycle)*/
    PG3IOCONbits.OSYNC = 0;
    /* Data for PWM3H/PWM3L Pins if FLT Event is Active bits
       If Fault is active, then FLTDAT<1> provides data for PWM3H.
       If Fault is active, then FLTDAT<0> provides data for PWM3L.*/
    PG3IOCONbits.FLTDAT = 0;
    /* Data for PWM3H/PWM3L Pins if CLMT Event is Active bits
       If current limit is active, then CLDAT<1> provides data for PWM3H.
       If current limit is active, then CLDAT<0> provides data for PWM3L.*/
    PG3IOCONbits.CLDAT = 0;
    /* Data for PWM3H/PWM3L Pins if Feed-Forward Event is Active bits
       If feed-forward is active, then FFDAT<1> provides data for PWM3H.
       If feed-forward is active, then FFDAT<0> provides data for PWM3L.*/
    PG3IOCONbits.FFDAT = 0;
    /* Data for PWM3H/PWM3L Pins if Debug Mode is Active and PTFRZ = 1 bits
       If Debug mode is active and PTFRZ=1,then DBDAT<1> provides PWM3H data.
       If Debug mode is active and PTFRZ=1,then DBDAT<0> provides PWM3L data. */
    PG3IOCONbits.DBDAT = 0;
    
    /* Initialize PWM GENERATOR 3 I/O CONTROL REGISTER HIGH */    
    /* Time Base Capture Source Selection bits
       000 = No hardware source selected for time base capture ? software only*/
    PG3IOCONbits.CAPSRC = 0;
    /* Dead-Time Compensation Select bit 
       0 = Dead-time compensation is controlled by PCI Sync logic */
    PG3IOCONbits.DTCMPSEL = 0;
    /* PWM Generator Output Mode Selection bits
       00 = PWM Generator outputs operate in Complementary mode*/
    PG3IOCONbits.PMOD = 0;
    /* PWM3H Output Port Enable bit
       1 = PWM Generator controls the PWM3H output pin
       0 = PWM Generator does not control the PWM3H output pin */
    PG3IOCONbits.PENH = 1;
    /* PWM3L Output Port Enable bit
       1 = PWM Generator controls the PWM3L output pin
       0 = PWM Generator does not control the PWM3L output pin */
    PG3IOCONbits.PENL = 1;
    /* PWM3H Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG3IOCONbits.POLH = 0;
    /* PWM3L Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG3IOCONbits.POLL = 0;
    
    /* Initialize PWM GENERATOR 3 EVENT REGISTER LOW*/
    PG3EVT      = 0x0000;
    /* ADC Trigger 1 Post-scaler Selection bits
       00000 = 1:1 */
    PG3EVTbits.ADTR1PS = 0;
    /* ADC Trigger 1 Source is PG3TRIGC Compare Event Enable bit
       0 = PG3TRIGC register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG3EVTbits.ADTR1EN3  = 0;
    /* ADC Trigger 1 Source is PG3TRIGB Compare Event Enable bit
       0 = PG3TRIGB register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG3EVTbits.ADTR1EN2 = 0;
    /* ADC Trigger 1 Source is PG3TRIGA Compare Event Enable bit
       0 = PG3TRIGA register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG3EVTbits.ADTR1EN1 = 0;
    /* Update Trigger Select bits
       01 = A write of the PG3DC register automatically sets the UPDATE bit
       00 = User must set the UPDATE bit manually*/
    PG3EVTbits.UPDTRG = 1;
    /* PWM Generator Trigger Output Selection bits
       000 = EOC event is the PWM Generator trigger*/
    PG3EVTbits.PGTRGSEL = 0;
    
    /* Initialize PWM GENERATOR 3 EVENT REGISTER HIGH */
    /* FLTIEN: PCI Fault Interrupt Enable bit
       0 = Fault interrupt is disabled */
    PG3EVTbits.FLTIEN = 0;
    /* PCI Current Limit Interrupt Enable bit
       0 = Current limit interrupt is disabled */
    PG3EVTbits.CLIEN = 0;
    /* PCI Feed-Forward Interrupt Enable bit
       0 = Feed-forward interrupt is disabled */
    PG3EVTbits.FFIEN = 0;
    /* PCI Sync Interrupt Enable bit
       0 = Sync interrupt is disabled */
    PG3EVTbits.SIEN = 0;
    /* Interrupt Event Selection bits
       00 = Interrupts CPU at EOC
       01 = Interrupts CPU at TRIGA compare event
       10 = Interrupts CPU at ADC Trigger 1 event
       11 = Time base interrupts are disabled */
    PG3EVTbits.IEVTSEL = 3;
    /* ADC Trigger 3 Source is PG3TRIGC Compare Event Enable bit
       0 = PG3TRIGC register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG3EVTbits.ADTR2EN3 = 0;
    /* ADC Trigger 2 Source is PG3TRIGB Compare Event Enable bit
       0 = PG3TRIGB register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG3EVTbits.ADTR2EN2 = 0;
    /* ADC Trigger 2 Source is PG3TRIGA Compare Event Enable bit
       0 = PG3TRIGA register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG3EVTbits.ADTR2EN1 = 0;
    /* ADC Trigger 1 Offset Selection bits
       00000 = No offset */
    PG3EVTbits.ADTR1OFS = 0;
    
    /* PWM GENERATOR 3 Fault PCI REGISTER */
#ifndef ENABLE_PWM_FAULT_PCI
    /* PWM GENERATOR 3 Fault PCI REGISTER */
    PG3FPCI     = 0x0000;
#else
       /* PWM GENERATOR 3 Fault PCI REGISTER  */
    PG3FPCI     = 0x0000;
    /* Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG3FPCIbits.TSYNCDIS = 0;
    /* Termination Event Selection bits
       001 = Auto-Terminate: Terminate when PCI source transitions from 
             active to inactive */
    PG3FPCIbits.TERM = 1;
    /* Acceptance Qualifier Polarity Select bit: 0 = Not inverted 1 = Inverted*/
    PG3FPCIbits.AQPS = 0;
    /* Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to 0)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)        
       000 = No acceptance qualifier is used (qualifier forced to 1) */
    PG3FPCIbits.AQSS = 0;
    /* PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC*/
    PG3FPCIbits.PSYNC = 0;
    /* PCI Polarity Select bit 0 = Not inverted 1 = Inverted */
    PG3FPCIbits.PPS = 1;
    /* PCI Source Selection bits
       11111 = CLC1
       ? ?
       11101 Comparator 3 output
       ? ?
       01000 RPn input, PCI8R
       ? ?
       00001 = Internally connected to the output of PWMPCI[2:0] MUX
       00000 = Tied to ?0? */
    PG3FPCIbits.PSS = 0b11101;
    /* PCI Bypass Enable bit
       0 = PCI function is not bypassed */
    PG3FPCIbits.BPEN   = 0;
    /* PCI Bypass Source Selection bits(1)
       000 = PCI control is sourced from PG1 PCI logic when BPEN = 1 */
    PG3FPCIbits.BPSEL   = 0;
    /* PCI Termination Polarity Select bits 
       0 = Inverter, 1 = Non Inverted */
    PG3FPCIbits.TERMPS = 0;
    /* PCI Acceptance Criteria Selection bits
       101 = Latched any edge(2)
       100 = Latched rising edge
       011 = Latched
       010 = Any edge
       001 = Rising edge
       000 = Level-sensitive*/
    PG3FPCIbits.ACP   = 3;
    /* PCI SR Latch Mode bit
       1 = SR latch is Reset-dominant in Latched Acceptance modes
       0 = SR latch is Set-dominant in Latched Acceptance modes*/
    PG3FPCIbits.LATMOD  = 0;
    /* Termination Qualifier Polarity Select bit 1 = Inverted 0 = Not inverted*/
    PG3FPCIbits.TQPS   = 0;
    /* Termination Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to '0')(3)
       110 = Selects PCI Source #9 (pwm_pci[9] input port)
       101 = Selects PCI Source #8 (pwm_pci[8] input port)
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No termination qualifier used (qualifier forced to '1')(3)*/
    PG3FPCIbits.TQSS  = 3;
#endif  
    
    /* PWM GENERATOR 3 Current Limit PCI REGISTER LOW */
    PG3CLPCI    = 0x0000;
    /* PWM GENERATOR 3 Feed Forward PCI REGISTER LOW */
    PG3FFPCI    = 0x0000;
    /* PWM GENERATOR 3 Sync PCI REGISTER LOW */
    PG3SPCI     = 0x0000;
    
    /* Initialize PWM GENERATOR 3 LEADING-EDGE BLANKING REGISTER LOW */
    PG3LEB      = 0x0000;
    
    /* Initialize PWM GENERATOR 3 PHASE REGISTER */
    PG3PHASE     = MIN_DUTY;
    /* Initialize PWM GENERATOR 3 DUTY CYCLE REGISTER */
    PG3DC        = MIN_DUTY;
    /* Initialize PWM GENERATOR 3 DUTY CYCLE ADJUSTMENT REGISTER */
    PG3DCA       = 0x0000;
    /* Initialize PWM GENERATOR 3 PERIOD REGISTER */
    PG3PER       = 0x0000;
    /* Initialize PWM GENERATOR 3 DEAD-TIME REGISTER LOW */
    PG3DTbits.DTH       = DEADTIME;
    /* Initialize PWM GENERATOR 3 DEAD-TIME REGISTER HIGH */
    PG3DTbits.DTL      = DEADTIME;

    /* Initialize PWM GENERATOR 3 TRIGGER A REGISTER */
    PG3TRIGA     = 0x0000;
    /* Initialize PWM GENERATOR 3 TRIGGER B REGISTER */
    PG3TRIGB     = 0x0000;
    /* Initialize PWM GENERATOR 3 TRIGGER C REGISTER */
    PG3TRIGC     = 0x0000;
    
}

void InitPWMGenerator4 (void)
{

    /* Initialize PWM GENERATOR 3 CONTROL REGISTER LOW */
    PG4CON      = 0x0000;
    /* PWM Generator 3 Enable bit : 1 = Is enabled, 0 = Is not enabled */
    /* PWM Generator is disabled prior to configuring module */
    PG4CONbits.ON = 0;
    /* Clock Selection bits
       0b01 = Macro uses Master clock selected by the PCLKCON.MCLKSEL bits*/
    PG4CONbits.CLKSEL = 1;
    /* PWM Mode Selection bits
     * 110 = Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
       100 = Center-Aligned PWM mode(interrupt/register update once per cycle)*/
    PG4CONbits.MODSEL = 4;   
    /* Trigger Count Select bits
       000 = PWM Generator produces 1 PWM cycle after triggered */
    PG4CONbits.TRGCNT = 0;
    
    /* Initialize PWM GENERATOR 4 CONTROL REGISTER HIGH */
    /* Master Duty Cycle Register Select bit
       1 = Macro uses the MDC register instead of PG4DC
       0 = Macro uses the PG4DC register*/
    PG4CONbits.MDCSEL = 0;
    /* Master Period Register Select bit
       1 = Macro uses the MPER register instead of PG4PER
       0 = Macro uses the PG4PER register */
    PG4CONbits.MPERSEL = 0;
    /* MPHSEL: Master Phase Register Select bit
       1 = Macro uses the MPHASE register instead of PG4PHASE
       0 = Macro uses the PG4PHASE register */
    PG4CONbits.MPHSEL = 0;
    /* Master Update Enable bit
       1 = PWM Generator broadcasts software set/clear of UPDATE status bit and 
           EOC signal to other PWM Generators
       0 = PWM Generator does not broadcast UPDATE status bit or EOC signal */
    PG4CONbits.MSTEN = 0;
    /* PWM Buffer Update Mode Selection bits 
       0b010 = Slaved SOC Update Data registers at start of next cycle if a 
       master update request is received. A master update request will be 
       transmitted if MSTEN = 1 and UPDATE = 1 for the requesting PWM
       Generator.. */
	PG4CONbits.UPDMOD = 0b000;
    /* PWM Generator Trigger Mode Selection bits
       0b00 = PWM Generator operates in Single Trigger mode */
    PG4CONbits.TRGMOD = 0;
    /* Start of Cycle Selection bits
       0000 = Local EOC*/
    PG4CONbits.SOCS = 0;
    
    /* Clear PWM GENERATOR 3 STATUS REGISTER*/
    PG4STAT      = 0x0000;
    /* Initialize PWM GENERATOR 3 I/O CONTROL REGISTER LOW */
    PG4IOCON    = 0x0000;

    /* Current Limit Mode Select bit
       0 = If PCI current limit is active, then the CLDAT<1:0> bits define 
       the PWM output levels */
    PG4IOCONbits.CLMOD = 0;
    /* Swap PWM Signals to PWM3H and PWM3L Device Pins bit 
       0 = PWM3H/L signals are mapped to their respective pins */
    PG4IOCONbits.SWAP = 0;
    /* User Override Enable for PWM3H Pin bit
       0 = PWM Generator provides data for the PWM3H pin*/
    PG4IOCONbits.OVRENH = 0;
    /* User Override Enable for PWM3L Pin bit
       0 = PWM Generator provides data for the PWM3L pin*/
    PG4IOCONbits.OVRENL = 0;
    /* Data for PWM3H/PWM3L Pins if Override is Enabled bits
       If OVERENH = 1, then OVRDAT<1> provides data for PWM3H.
       If OVERENL = 1, then OVRDAT<0> provides data for PWM3L */
    PG4IOCONbits.OVRDAT = 0;
    /* User Output Override Synchronization Control bits
       00 = User output overrides via the OVRENL/H and OVRDAT<1:0> bits are 
       synchronized to the local PWM time base (next start of cycle)*/
    PG4IOCONbits.OSYNC = 0;
    /* Data for PWM3H/PWM3L Pins if FLT Event is Active bits
       If Fault is active, then FLTDAT<1> provides data for PWM3H.
       If Fault is active, then FLTDAT<0> provides data for PWM3L.*/
    PG4IOCONbits.FLTDAT = 0;
    /* Data for PWM3H/PWM3L Pins if CLMT Event is Active bits
       If current limit is active, then CLDAT<1> provides data for PWM3H.
       If current limit is active, then CLDAT<0> provides data for PWM3L.*/
    PG4IOCONbits.CLDAT = 0;
    /* Data for PWM3H/PWM3L Pins if Feed-Forward Event is Active bits
       If feed-forward is active, then FFDAT<1> provides data for PWM3H.
       If feed-forward is active, then FFDAT<0> provides data for PWM3L.*/
    PG4IOCONbits.FFDAT = 0;
    /* Data for PWM3H/PWM3L Pins if Debug Mode is Active and PTFRZ = 1 bits
       If Debug mode is active and PTFRZ=1,then DBDAT<1> provides PWM3H data.
       If Debug mode is active and PTFRZ=1,then DBDAT<0> provides PWM3L data. */
    PG4IOCONbits.DBDAT = 0;
    
    /* Initialize PWM GENERATOR 3 I/O CONTROL REGISTER HIGH */    
    /* Time Base Capture Source Selection bits
       000 = No hardware source selected for time base capture ? software only*/
    PG4IOCONbits.CAPSRC = 0;
    /* Dead-Time Compensation Select bit 
       0 = Dead-time compensation is controlled by PCI Sync logic */
    PG4IOCONbits.DTCMPSEL = 0;
    /* PWM Generator Output Mode Selection bits
       00 = PWM Generator outputs operate in Complementary mode*/
    PG4IOCONbits.PMOD = 1;
    /* PWM3H Output Port Enable bit
       1 = PWM Generator controls the PWM3H output pin
       0 = PWM Generator does not control the PWM3H output pin */
    PG4IOCONbits.PENH = 1;
    /* PWM3L Output Port Enable bit
       1 = PWM Generator controls the PWM3L output pin
       0 = PWM Generator does not control the PWM3L output pin */
    PG4IOCONbits.PENL = 0;
    /* PWM3H Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG4IOCONbits.POLH = 0;
    /* PWM3L Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG4IOCONbits.POLL = 0;
    
    /* Initialize PWM GENERATOR 3 EVENT REGISTER LOW*/
    PG4EVT      = 0x0000;
    /* ADC Trigger 1 Post-scaler Selection bits
       00000 = 1:1 */
    PG4EVTbits.ADTR1PS = 0b0011;
    /* ADC Trigger 1 Source is PG4TRIGC Compare Event Enable bit
       0 = PG4TRIGC register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG4EVTbits.ADTR1EN3  = 1;
    /* ADC Trigger 1 Source is PG4TRIGB Compare Event Enable bit
       0 = PG4TRIGB register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG4EVTbits.ADTR1EN2 = 0;
    /* ADC Trigger 1 Source is PG4TRIGA Compare Event Enable bit
       0 = PG4TRIGA register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG4EVTbits.ADTR1EN1 = 0;
    /* Update Trigger Select bits
       01 = A write of the PG4DC register automatically sets the UPDATE bit
       00 = User must set the UPDATE bit manually*/
    PG4EVTbits.UPDTRG = 1;
    /* PWM Generator Trigger Output Selection bits
       000 = EOC event is the PWM Generator trigger*/
    PG4EVTbits.PGTRGSEL = 0;
    
    /* Initialize PWM GENERATOR 3 EVENT REGISTER HIGH */
    /* FLTIEN: PCI Fault Interrupt Enable bit
       0 = Fault interrupt is disabled */
    PG4EVTbits.FLTIEN = 0;
    /* PCI Current Limit Interrupt Enable bit
       0 = Current limit interrupt is disabled */
    PG4EVTbits.CLIEN = 0;
    /* PCI Feed-Forward Interrupt Enable bit
       0 = Feed-forward interrupt is disabled */
    PG4EVTbits.FFIEN = 0;
    /* PCI Sync Interrupt Enable bit
       0 = Sync interrupt is disabled */
    PG4EVTbits.SIEN = 0;
    /* Interrupt Event Selection bits
       00 = Interrupts CPU at EOC
       01 = Interrupts CPU at TRIGA compare event
       10 = Interrupts CPU at ADC Trigger 1 event
       11 = Time base interrupts are disabled */
    PG4EVTbits.IEVTSEL = 3;
    /* ADC Trigger 3 Source is PG4TRIGC Compare Event Enable bit
       0 = PG4TRIGC register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG4EVTbits.ADTR2EN3 = 0;
    /* ADC Trigger 2 Source is PG4TRIGB Compare Event Enable bit
       0 = PG4TRIGB register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG4EVTbits.ADTR2EN2 = 0;
    /* ADC Trigger 2 Source is PG4TRIGA Compare Event Enable bit
       0 = PG4TRIGA register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG4EVTbits.ADTR2EN1 = 1;
    /* ADC Trigger 1 Offset Selection bits
       00000 = No offset */
    PG4EVTbits.ADTR1OFS = 0;
    
    /* PWM GENERATOR 3 Fault PCI REGISTER LOW */
#ifndef ENABLE_PWM_FAULT
    /* PWM GENERATOR 3 Fault PCI REGISTER LOW */
    PG4FPCI     = 0x0000;
#else
       /* PWM GENERATOR 3 Fault PCI REGISTER LOW */
    PG4FPCI     = 0x0000;
    /* Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG4FPCIbits.TSYNCDIS = 0;
    /* Termination Event Selection bits
       001 = Auto-Terminate: Terminate when PCI source transitions from 
             active to inactive */
    PG4FPCIbits.TERM = 1;
    /* Acceptance Qualifier Polarity Select bit: 0 = Not inverted 1 = Inverted*/
    PG4FPCIbits.AQPS = 0;
    /* Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to 0)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)        
       000 = No acceptance qualifier is used (qualifier forced to 1) */
    PG4FPCIbits.AQSS = 0;
    /* PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC*/
    PG4FPCIbits.PSYNC = 0;
    /* PCI Polarity Select bit 0 = Not inverted 1 = Inverted */
    PG4FPCIbits.PPS = 1;
    /* PCI Source Selection bits
       11111 = PCI Source #31
       ? ?
       00001 = PCI Source #1
       00000 = Software PCI control bit (SWPCI) only*/
    PG4FPCIbits.PSS = 9;
    /* PCI Bypass Enable bit
       0 = PCI function is not bypassed */
    PG4FPCIbits.BPEN   = 0;
    /* PCI Bypass Source Selection bits(1)
       000 = PCI control is sourced from PG1 PCI logic when BPEN = 1 */
    PG4FPCIbits.BPSEL   = 0;
    /* PCI Termination Polarity Select bits 
       0 = Inverter, 1 = Non Inverted */
    PG4FPCIbits.TERMPS = 0;
    /* PCI Acceptance Criteria Selection bits
       101 = Latched any edge(2)
       100 = Latched rising edge
       011 = Latched
       010 = Any edge
       001 = Rising edge
       000 = Level-sensitive*/
    PG4FPCIbits.ACP   = 3;
    /* PCI SR Latch Mode bit
       1 = SR latch is Reset-dominant in Latched Acceptance modes
       0 = SR latch is Set-dominant in Latched Acceptance modes*/
    PG4FPCIbits.LATMOD  = 0;
    /* Termination Qualifier Polarity Select bit 1 = Inverted 0 = Not inverted*/
    PG4FPCIbits.TQPS   = 0;
    /* Termination Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to '0')(3)
       110 = Selects PCI Source #9 (pwm_pci[9] input port)
       101 = Selects PCI Source #8 (pwm_pci[8] input port)
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No termination qualifier used (qualifier forced to '1')(3)*/
    PG4FPCIbits.TQSS  = 0;
#endif  
    
    /* PWM GENERATOR 3 Current Limit PCI REGISTER LOW */
    PG4CLPCI    = 0x0000;
    /* PWM GENERATOR 3 Feed Forward PCI REGISTER LOW */
    PG4FFPCI    = 0x0000;
    /* PWM GENERATOR 3 Sync PCI REGISTER LOW */
    PG4SPCI     = 0x0000;
    
    /* Initialize PWM GENERATOR 3 LEADING-EDGE BLANKING REGISTER LOW */
    PG4LEB      = 0x0000;
    
    /* Initialize PWM GENERATOR 3 PHASE REGISTER */
    PG4PHASE     = 0x0000;
    /* Initialize PWM GENERATOR 3 DUTY CYCLE REGISTER */
    PG4DC        = PFC_MIN_DUTY_COUNTS;
    /* Initialize PWM GENERATOR 3 DUTY CYCLE ADJUSTMENT REGISTER */
    PG4DCA       = 0x0000;
    /* Initialize PWM GENERATOR 3 PERIOD REGISTER */
    PG4PER       = PFC_LOOPTIME_TCY ;
    /* Initialize PWM GENERATOR 3 DEAD-TIME REGISTER LOW */
    PG4DTbits.DTH = 0x0000;
    /* Initialize PWM GENERATOR 3 DEAD-TIME REGISTER HIGH */
    PG4DTbits.DTL = 0x0000;

    /* Initialize PWM GENERATOR 3 TRIGGER A REGISTER */
    PG4TRIGAbits.CAHALF = 1;
    PG4TRIGAbits.TRIGA = PFC_ADC_SAMPLING_POINT;  
    
    /* Initialize PWM GENERATOR 3 TRIGGER B REGISTER */
    PG4TRIGB     = 0x0000;
    /* Initialize PWM GENERATOR 3 TRIGGER C REGISTER */
    PG4TRIGCbits.CAHALF = 0;
    PG4TRIGC     = PFC_Sync_MC_Value;  
}

// </editor-fold>