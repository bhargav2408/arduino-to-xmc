/*******************************************************************************
**  DAVE App Name : NVIC_SR101       App Version: 1.0.2               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[NVIC_SR101.c]*/

/*******************************************************************************
 Copyright (c) 2012, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without** 
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC1000 Series   			                          **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : $Author:                                                          **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Feb 19,2013                                            **
**                                                                            **
*******************************************************************************/
/**
 * 
 * @App Version NVIC_SR101_C <1.0.2>
 * 
 * @file   NVIC_SR101.c
 *
 * @brief  NVIC_SR101 App
 *
 */

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PAE        App Developer                                                   **
*******************************************************************************/
/* Revision History */
/* 19-12-12 v0.1.0 Inital version
 * 28-01-13 v0.1.1 Implemented event listener functions
 * 04-02-13 v0.1.3 Review comments are fixed
 * 19-02-13 v1.0.0 renamed the event listener name
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
/** Inclusion of header file */

#include <DAVE3.h>

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/** This sets the maximum number of listeners per event */
#define MAX_CALLBACKS	   1

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
NVIC_SR101_HandleType NVIC_SR101_Handle0;

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
void NVIC_SR101_CallEventListener(NVIC_SR101_InterruptType IntID);
void SCU_1_IRQHandler(void);

uint32_t NVIC_SR101_FreeCbkSlot[NVIC_SR101_MAX] = {0};


/*  Function to configure SCU SR1 Interrupts based on  user configuration.
 * 
 */
void NVIC_SR101_Init()
{
	  
	  NVIC_SetPriority(1,3);  
	  
	  
}

/**
* @brief  Function to enable service request event 
* @note   -  
* @param  NVIC_SR101_InterruptType
* @retval None
*/
void NVIC_SR101_EnableEvent(NVIC_SR101_InterruptType IntID)
{
	/* Enable SBYCLKFI Event */	
	if(NVIC_SR101_SBYCLKFI == IntID){
	   SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_SBYCLKFI_Pos);
	}
	/* Enable VDDP Pre Warning Event */
	else if(NVIC_SR101_VDDPI == IntID){ 
	   SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_VDDPI_Pos);
	}
    /* Enable VDROP Event */
	else if(NVIC_SR101_VDROPI == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_VDROPI_Pos );
	}
	/* Enable VCLIP Event */
	else if(NVIC_SR101_VCLIPI == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_VCLIPI_Pos);
	}
	/* Enable TSE DONE Event */
	else if(NVIC_SR101_TSE_DONE == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_TSE_DONE_Pos);
	}
	/* Enable TSE HIGH Event */
	else if(NVIC_SR101_TSE_HIGH == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_TSE_HIGH_Pos);
	}
	/* Enable TSE LOW Event */
	else if(NVIC_SR101_TSE_LOW == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_TSE_LOW_Pos);
	}
	/* Enable WDT Pre Warning Event */
	else if(NVIC_SR101_PRWARN == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_PRWARN_Pos);
	}
	/* Enable RTC Control Event */
	else if(NVIC_SR101_RTC_CTR == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_CTR_Pos);
	}
	/* Enable RTC ATIM0 Event */
	else if(NVIC_SR101_RTC_ATIM0 == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_ATIM0_Pos);
	}
	/* Enable RTC ATIM1 Event */
	else if(NVIC_SR101_RTC_ATIM1 == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_ATIM1_Pos);
	} 
	/* Enable RTC TIM0 Event */
	else if(NVIC_SR101_RTC_TIM0 == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_TIM0_Pos);
	} 
	/* Enable RTC TIM1 Event */
	else if(NVIC_SR101_RTC_TIM1 == IntID){
	  SET_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_TIM1_Pos);
	}
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
/**
* @brief  Function to disable service request event 
* @note   -  
* @param  NVIC_SR101_InterruptType
* @retval None
*/
void NVIC_SR101_DisableEvent(NVIC_SR101_InterruptType IntID)
{
	/* Disable SBYCLKFI Event */	
	if(NVIC_SR101_SBYCLKFI == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_SBYCLKFI_Pos);
	}
	/* Disable VDDP Pre Warning Event */
	else if(NVIC_SR101_VDDPI == IntID){ 
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_VDDPI_Pos);
	}
    /* Disable VDROP Event */
	else if(NVIC_SR101_VDROPI == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_VDROPI_Pos );
	}
	/* Disable VCLIP Event */
	else if(NVIC_SR101_VCLIPI == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_VCLIPI_Pos);
	}
	/* Disable TSE DONE Event */
	else if(NVIC_SR101_TSE_DONE == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_TSE_DONE_Pos);
	}
	/* Disable TSE HIGH Event */
	else if(NVIC_SR101_TSE_HIGH == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_TSE_HIGH_Pos);
	}
	/* Disable TSE LOW Event */
	else if(NVIC_SR101_TSE_LOW == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_TSE_LOW_Pos);
	}
	/* Disable WDT Pre Warning Event */
	else if(NVIC_SR101_PRWARN == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_PRWARN_Pos);
	}
	/* Disable RTC Control Event */
	else if(NVIC_SR101_RTC_CTR == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_CTR_Pos);
	}
	/* Disable RTC ATIM0 Event */
	else if(NVIC_SR101_RTC_ATIM0 == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_ATIM0_Pos);
	}
	/* Disable RTC ATIM1 Event */
	else if(NVIC_SR101_RTC_ATIM1 == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_ATIM1_Pos);
	} 
	/* Disable RTC TIM0 Event */
	else if(NVIC_SR101_RTC_TIM0 == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_TIM0_Pos);
	} 
	/* Disable RTC TIM1 Event */
	else if(NVIC_SR101_RTC_TIM1 == IntID){
		CLR_BIT(SCU_INTERRUPT->SRMSK,SCU_INTERRUPT_SRMSK_RTC_TIM1_Pos);
	}

}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */

/**
  * @brief  Utility function to register Event Handler for a given event.
  * @note   -  
  * @param  NVIC_SR101_InterruptType
  * @param  NVIC_SR101_CallbackType
  * @param  CbArgs
  * @retval NVIC_SR101_RegisterCbStatusType
  */
NVIC_SR101_RegisterCbStatusType NVIC_SR101_RegisterCallback
 (
  NVIC_SR101_InterruptType IntID,
  NVIC_SR101_CallbackType userFunction,
  uint32_t CbArgs
 )
{
  /*<<<DD_NVIC_SR101_API_2>>>*/
	 uint32_t Status;
	 Status=NVIC_SR101_REGISTER_FAIL;
	
  NVIC_SR101_HandleType* Handle = &NVIC_SR101_Handle0;

  if(NVIC_SR101_FreeCbkSlot[IntID] < MAX_CALLBACKS)
  {
    Handle->SCU[IntID].CbListener[NVIC_SR101_FreeCbkSlot[IntID]] = userFunction;
    Handle->SCU[IntID].CbArg[NVIC_SR101_FreeCbkSlot[IntID]] = CbArgs;
    NVIC_SR101_FreeCbkSlot[IntID]++;
    Status=NVIC_SR101_REGISTER_SUCCESS;
  }
 
  return Status;
}

/*  SCU Interrupt Handler.
 * 
 */
void SCU_1_IRQHandler(void)
{
  uint32_t IrqActive= 0;
  /* read the SCU Raw Service Request Register */
  IrqActive = SCU_INTERRUPT->SRRAW;
 
  /* Standby Clock Failure Event */
  if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_SBYCLKFI_Msk, SCU_INTERRUPT_SRRAW_SBYCLKFI_Pos))
  {
      /* clear the interrupt */
      SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_SBYCLKFI_Msk;
      NVIC_SR101_CallEventListener(NVIC_SR101_SBYCLKFI);
  }
  /* VDDP Pre-warning Event */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_VDDPI_Msk, SCU_INTERRUPT_SRRAW_VDDPI_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_VDDPI_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_VDDPI);
  }
  /* VDROP Event */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_VDROPI_Msk, SCU_INTERRUPT_SRRAW_VDROPI_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_VDROPI_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_VDROPI);
  }
  /* VCLIP Event */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_VCLIPI_Msk, SCU_INTERRUPT_SRRAW_VCLIPI_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_VCLIPI_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_VCLIPI);
  }
  /* TSE Done Event */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_TSE_DONE_Msk, SCU_INTERRUPT_SRRAW_TSE_DONE_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_TSE_DONE_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_TSE_DONE);
  }
  /* TSE Compare High Event */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_TSE_HIGH_Msk, SCU_INTERRUPT_SRRAW_TSE_HIGH_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_TSE_HIGH_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_TSE_HIGH);
  }
  /* TSE Compare Low Event */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_TSE_LOW_Msk, SCU_INTERRUPT_SRRAW_TSE_LOW_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_TSE_LOW_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_TSE_LOW);
  }
  /* WDT pre-warning */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_PRWARN_Msk, SCU_INTERRUPT_SRRAW_PRWARN_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_PRWARN_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_PRWARN);
  }
  /* RTC Alarm */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_AI_Msk, SCU_INTERRUPT_SRRAW_AI_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_AI_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_AI);
  }  
  /* RTC Periodic Event */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_PI_Msk, SCU_INTERRUPT_SRRAW_PI_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_PI_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_PI);
  }
  /*  RTC CTR Mirror Register Updated */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_RTC_CTR_Msk, SCU_INTERRUPT_SRRAW_RTC_CTR_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_CTR_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_RTC_CTR);
  }
  /*  RTC ATIM0 Mirror Register Updated */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_RTC_ATIM0_Msk, SCU_INTERRUPT_SRRAW_RTC_ATIM0_Pos))
  {
	  /* clear the interrupt */
	  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_ATIM0_Msk;
	  NVIC_SR101_CallEventListener(NVIC_SR101_RTC_ATIM0);
  }
  /*  RTC ATIM1 Mirror Register Updated */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_RTC_ATIM1_Msk, SCU_INTERRUPT_SRRAW_RTC_ATIM1_Pos))
  {
 	 /* clear the interrupt */
	 SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_ATIM1_Msk;
	 NVIC_SR101_CallEventListener(NVIC_SR101_RTC_ATIM1);
  }
  /*  RTC TIM0 Mirror Register Updated */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_RTC_TIM0_Msk, SCU_INTERRUPT_SRRAW_RTC_TIM0_Pos))
  {
	 /* clear the interrupt */
	 SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_TIM0_Msk;
	 NVIC_SR101_CallEventListener(NVIC_SR101_RTC_TIM0);
  }
  /*  RTC TIM1 Mirror Register Updated */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRRAW_RTC_TIM1_Msk, SCU_INTERRUPT_SRRAW_RTC_TIM1_Pos))
  {
    /* clear the interrupt */
    SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_TIM1_Msk;
    NVIC_SR101_CallEventListener(NVIC_SR101_RTC_TIM1);
  }
  else
  {
	   /* If we've reached this point, either the enabling and
		* disabling of SCU interrupts is not being handled
		* properly or this function is being called unnecessarily.
		*/
  }
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */ 

/**
  * @brief  Call Listener Function for Enabled Events 
  * @note   -  
  * @param  NVIC_SR101_InterruptType
  * @retval None
  */
void NVIC_SR101_CallEventListener(NVIC_SR101_InterruptType IntID)
{
	  NVIC_SR101_CallbackType NVIC_SR101_UserCallback;
	  NVIC_SR101_HandleType* Handle = &NVIC_SR101_Handle0;
	  uint32_t CallbackArg = 0;
	  uint32_t i = 0;
	    
	      for(i = 0; i<NVIC_SR101_FreeCbkSlot[IntID]; i++)
	      {
	    	  NVIC_SR101_UserCallback = Handle->SCU[IntID].CbListener[i];
	    	  CallbackArg = Handle->SCU[IntID].CbArg[i];
	    	  NVIC_SR101_UserCallback(CallbackArg);
	      }
}
/*CODE_BLOCK_END*/

