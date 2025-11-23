	/* USER CODE BEGIN Header */
	/**
	  ******************************************************************************
	  * @file           : main.c
	  * @brief          : Main program body
	  ******************************************************************************
	  * @attention
	  *
	  * Copyright (c) 2025 STMicroelectronics.
	  * All rights reserved.
	  *
	  * This software is licensed under terms that can be found in the LICENSE file
	  * in the root directory of this software component.
	  * If no LICENSE file comes with this software, it is provided AS-IS.
	  *
	  ******************************************************************************
	  */
	/* USER CODE END Header */
	/* Includes ------------------------------------------------------------------*/
	#include "main.h"
	#include "usb_device.h"

	/* Private includes ----------------------------------------------------------*/
	/* USER CODE BEGIN Includes */

	/* USER CODE END Includes */

	/* Private typedef -----------------------------------------------------------*/
	/* USER CODE BEGIN PTD */

	/* USER CODE END PTD */

	/* Private define ------------------------------------------------------------*/
	/* USER CODE BEGIN PD */

	/* USER CODE END PD */

	/* Private macro -------------------------------------------------------------*/
	/* USER CODE BEGIN PM */

	/* USER CODE END PM */

	/* Private variables ---------------------------------------------------------*/

	/* USER CODE BEGIN PV */
	extern USBD_HandleTypeDef hUsbDeviceFS;

	typedef struct
	{
		uint8_t MODIFIER;
		uint8_t RESERVED;
		uint8_t KEYCODE1;
		uint8_t KEYCODE2;
		uint8_t KEYCODE3;
		uint8_t KEYCODE4;
		uint8_t KEYCODE5;
		uint8_t KEYCODE6;
	}subKeyBoard;

	subKeyBoard keyBoardHIDsub = {0,0,0,0,0,0,0,0};

	/* USER CODE END PV */

	/* Private function prototypes -----------------------------------------------*/
	void SystemClock_Config(void);
	static void MX_GPIO_Init(void);
	/* USER CODE BEGIN PFP */

	/* USER CODE END PFP */

	/* Private user code ---------------------------------------------------------*/
	/* USER CODE BEGIN 0 */

	void typeOnKeyboard(char cmd[]){

		for(int i = 0; i < strlen(cmd); i++) {
			char charToType = cmd[i];
			uint8_t KEYCODE = 0x00;
			uint8_t MODIFIER = 0x00;

			switch(charToType) {
				case 'A': KEYCODE = 0x04; MODIFIER=0x02; break;
				case 'B': KEYCODE = 0x05; MODIFIER=0x02; break;
				case 'C': KEYCODE = 0x06; MODIFIER=0x02; break;
				case 'D': KEYCODE = 0x07; MODIFIER=0x02; break;
				//case 'E': KEYCODE = 0x08; MODIFIER=0x02; break;
				case 'F': KEYCODE = 0x09; MODIFIER=0x02; break;
				case 'G': KEYCODE = 0x0A; MODIFIER=0x02; break;
				case 'H': KEYCODE = 0x0B; MODIFIER=0x02; break;
				case 'I': KEYCODE = 0x0C; MODIFIER=0x02; break;
				case 'J': KEYCODE = 0x0D; MODIFIER=0x02; break;
				case 'K': KEYCODE = 0x0E; MODIFIER=0x02; break;
				case 'L': KEYCODE = 0x0F; MODIFIER=0x02; break;
				case 'M': KEYCODE = 0x10; MODIFIER=0x02; break;
				//case 'N': KEYCODE = 0x11; MODIFIER=0x02; break;
				case 'O': KEYCODE = 0x12; MODIFIER=0x02; break;
				case 'P': KEYCODE = 0x13; MODIFIER=0x02; break;
				case 'Q': KEYCODE = 0x14; MODIFIER=0x02; break;
				case 'R': KEYCODE = 0x15; MODIFIER=0x02; break;
				case 'S': KEYCODE = 0x16; MODIFIER=0x02; break;
				case 'T': KEYCODE = 0x17; MODIFIER=0x02; break;
				case 'U': KEYCODE = 0x18; MODIFIER=0x02; break;
				case 'V': KEYCODE = 0x19; MODIFIER=0x02; break;
				case 'W': KEYCODE = 0x1A; MODIFIER=0x02; break;
				case 'X': KEYCODE = 0x1B; MODIFIER=0x02; break;
				case 'Y': KEYCODE = 0x1C; MODIFIER=0x02; break;
				case 'Z': KEYCODE = 0x1D; MODIFIER=0x02; break;
				case 'a': KEYCODE = 0x04; break;
				case 'b': KEYCODE = 0x05; break;
				case 'c': KEYCODE = 0x06; break;
				case 'd': KEYCODE = 0x07; break;
				case 'e': KEYCODE = 0x08; break;
				case 'f': KEYCODE = 0x09; break;
				case 'g': KEYCODE = 0x0A; break;
				case 'h': KEYCODE = 0x0B; break;
				case 'i': KEYCODE = 0x0C; break;
				case 'j': KEYCODE = 0x0D; break;
				case 'k': KEYCODE = 0x0E; break;
				case 'l': KEYCODE = 0x0F; break;
				case 'm': KEYCODE = 0x10; break;
				case 'n': KEYCODE = 0x11; break;
				case 'o': KEYCODE = 0x12; break;
				case 'p': KEYCODE = 0x13; break;
				case 'q': KEYCODE = 0x14; break;
				case 'r': KEYCODE = 0x15; break;
				case 's': KEYCODE = 0x16; break;
				case 't': KEYCODE = 0x17; break;
				case 'u': KEYCODE = 0x18; break;
				case 'v': KEYCODE = 0x19; break;
				case 'w': KEYCODE = 0x1A; break;
				case 'x': KEYCODE = 0x1B; break;
				case 'y': KEYCODE = 0x1C; break;
				case 'z': KEYCODE = 0x1D; break;
				case ' ': KEYCODE = 0x2C; break;
				case ';': KEYCODE = 0x33; break; // semi-colon
				case ':': KEYCODE = 0x33; MODIFIER=0x02; break; // colon
				case '\'': KEYCODE = 0x34; break; // single quote
				case '\"': KEYCODE = 0x34; MODIFIER=0x02; break; // double quote
				case 'N': KEYCODE = 0x53; break;//numb lock     apartir daqui é o teclaod numerico
				case '-': KEYCODE = 0x56; break;
				case '+': KEYCODE = 0x57; break;
				case 'E': KEYCODE = 0x58; break; //Enter
				case '1': KEYCODE = 0x59; break;
				case '2': KEYCODE = 0x5A; break;
				case '3': KEYCODE = 0x5B; break;
				case '4': KEYCODE = 0x5C; break;
				case '5': KEYCODE = 0x5D; break;
				case '6': KEYCODE = 0x5E; break;
				case '7': KEYCODE = 0x5F; break;
				case '8': KEYCODE = 0x60; break;
				case '9': KEYCODE = 0x61; break;
				case '0': KEYCODE = 0x62; break;
				case ',': KEYCODE = 0x63; break;//aqui acaba o que vamos usar
				case '/': KEYCODE = 0x38; break; // slash
				case '.': KEYCODE = 0x37; break; // slash
				default: KEYCODE = 0x00; break; // Default case for undefined characters
			}


			 keyBoardHIDsub.MODIFIER=MODIFIER;  // To press shift key
			 keyBoardHIDsub.KEYCODE1=KEYCODE;

			 USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
			 HAL_Delay(25);

			 keyBoardHIDsub.MODIFIER=0x00;
			 keyBoardHIDsub.KEYCODE1=0x00;

			 USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
			 HAL_Delay(25);
		}

	}

	void keyPressRelease(uint8_t KEYCODE){
	    keyBoardHIDsub.MODIFIER = 0x00;   // sempre sem shift
	    keyBoardHIDsub.KEYCODE1 = KEYCODE;

	    USBD_HID_SendReport(&hUsbDeviceFS, &keyBoardHIDsub, sizeof(keyBoardHIDsub));
	    HAL_Delay(25);

	    keyBoardHIDsub.MODIFIER = 0x00;
	    keyBoardHIDsub.KEYCODE1 = 0x00;

	    USBD_HID_SendReport(&hUsbDeviceFS, &keyBoardHIDsub, sizeof(keyBoardHIDsub));
	    HAL_Delay(25);
	}


	/* USER CODE END 0 */

	/**
	  * @brief  The application entry point.
	  * @retval int
	  */
	int main(void)
	{

	  /* USER CODE BEGIN 1 */

	  /* USER CODE END 1 */

	  /* MCU Configuration--------------------------------------------------------*/

	  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	  HAL_Init();

	  /* USER CODE BEGIN Init */

	  /* USER CODE END Init */

	  /* Configure the system clock */
	  SystemClock_Config();

	  /* USER CODE BEGIN SysInit */

	  /* USER CODE END SysInit */

	  /* Initialize all configured peripherals */
	  MX_GPIO_Init();
	  MX_USB_DEVICE_Init();
	  /* USER CODE BEGIN 2 */

	  /* USER CODE END 2 */

	  /* Infinite loop */
	  /* USER CODE BEGIN WHILE */
	  while (1)
	  {
		/* USER CODE END WHILE */
		  // ---- COLUNA 1 (PB12) ----
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);  // ativa coluna 1

			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3) == GPIO_PIN_SET) {
				 keyPressRelease(0x62); //0
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_SET) {
				 keyPressRelease(0x59); //1
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET) {
				 keyPressRelease(0x5C); //4
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_SET) {
				 keyPressRelease(0x5F); //7
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_SET) {
				 keyPressRelease(0x56); //-
			 }

			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); // desliga coluna 1
			 HAL_Delay(1);

			 // ---- COLUNA 2 (PB13) ----
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);

			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3) == GPIO_PIN_SET) {
				 keyPressRelease(0x63);//,
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_SET) {
				 keyPressRelease(0x5A);//2
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET) {
				 keyPressRelease(0x5D);//5
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_SET) {
				 keyPressRelease(0x60);//8
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_SET) {
				 keyPressRelease(0x57);//+
			 }

			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			 HAL_Delay(1);

			 // ---- COLUNA 3 (PB14) ----
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);

			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3) == GPIO_PIN_SET) {
				 keyPressRelease(0x58); //enter
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_SET) {
				 keyPressRelease(0x5B); //3
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET) {
				 keyPressRelease(0x5E); //6
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_SET) {
				 keyPressRelease(0x61); //9
			 }
			 if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_SET) {
				 keyPressRelease(0x53); //numb lock
			 }

			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			 HAL_Delay(1);
		/* USER CODE BEGIN 3 */
	  }
	  /* USER CODE END 3 */
	}

	/**
	  * @brief System Clock Configuration
	  * @retval None
	  */
	void SystemClock_Config(void)
	{
	  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

	  /** Initializes the RCC Oscillators according to the specified parameters
	  * in the RCC_OscInitTypeDef structure.
	  */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	  {
		Error_Handler();
	  }

	  /** Initializes the CPU, AHB and APB buses clocks
	  */
	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
								  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
	  {
		Error_Handler();
	  }
	  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
	  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
	  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
	  {
		Error_Handler();
	  }
	}

	/**
	  * @brief GPIO Initialization Function
	  * @param None
	  * @retval None
	  */
	static void MX_GPIO_Init(void)
	{
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  /* USER CODE BEGIN MX_GPIO_Init_1 */

	  /* USER CODE END MX_GPIO_Init_1 */

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOD_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);

	  /*Configure GPIO pins : PA3 PA4 PA5 PA6
							   PA7 */
	  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
							  |GPIO_PIN_7;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  /*Configure GPIO pins : PB12 PB13 PB14 */
	  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  /* USER CODE BEGIN MX_GPIO_Init_2 */

	  /* USER CODE END MX_GPIO_Init_2 */
	}

	/* USER CODE BEGIN 4 */

	/* USER CODE END 4 */

	/**
	  * @brief  This function is executed in case of error occurrence.
	  * @retval None
	  */
	void Error_Handler(void)
	{
	  /* USER CODE BEGIN Error_Handler_Debug */
	  /* User can add his own implementation to report the HAL error return state */
	  __disable_irq();
	  while (1)
	  {
	  }
	  /* USER CODE END Error_Handler_Debug */
	}
	#ifdef USE_FULL_ASSERT
	/**
	  * @brief  Reports the name of the source file and the source line number
	  *         where the assert_param error has occurred.
	  * @param  file: pointer to the source file name
	  * @param  line: assert_param error line source number
	  * @retval None
	  */
	void assert_failed(uint8_t *file, uint32_t line)
	{
	  /* USER CODE BEGIN 6 */
	  /* User can add his own implementation to report the file name and line number,
		 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	  /* USER CODE END 6 */
	}
	#endif /* USE_FULL_ASSERT */
