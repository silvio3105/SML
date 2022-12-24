
// ----- INCLUDE FILES
#include "main.h"
#include <stdint.h>
#include <sStd.h>


// ----- STM32 STUFF
UART_HandleTypeDef huart1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);


// ----- FUNCTION DECLARATIONS
void UARTout(const char* buffer, const uint16_t len);
void UARTLogger(const char* buffer, const uint16_t len);


// ----- SSTD OBJECTS
sStd::Logger<256> Serial = sStd::Logger<256>(UARTout);
sStd::Logger<128> Log = sStd::Logger<128>(UARTLogger, "[LOGGER] ");


// ----- FUNCTION DEFINITIONS
void UARTout(const char* buffer, const uint16_t len)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	HAL_UART_Transmit(&huart1, (uint8_t*)&buffer[0], len, 500);
}

void UARTLogger(const char* buffer, const uint16_t len)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	HAL_UART_Transmit(&huart1, (uint8_t*)&buffer[0], len, 500);
}


int main(void)
{
	// STM32 STUFF
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_USART1_UART_Init();

	// SSTD EXAMPLE
	Serial.print("Simple standard library example\n\n");

	// LOGGER
	Log.print("Example uses built-in logger object.\n", 37);
	Log.printf("Logger status is: %d\n", Serial.status());
	Log.status(sStd::LOG_OFF);
	Log.print("This will not be printed!\n");
	Log.status(sStd::LOG_ON);
	Log.print("Logger is back online!\n\n----- MACROS\n");

	// ARRAY SIZE
	uint8_t array8[6];
	uint32_t array32[5];
	Serial.printf("array8 has %d members\n", SSTD_ARRAY(array8));
	Serial.printf("array32 has %d members\n", SSTD_ARRAY(array32));

	// SCALE
	uint8_t x = 50;
	Serial.printf("scale x 0-100 range to 0-250 range: x = %d -> x' = %d\n", x, SSTD_SCALE(x, 0, 100, 0, 250));

	// ABS VALUE
	int8_t y = -10;
	y = SSTD_ABS(y);
	Serial.printf("|500| = %d; |-690| = %d; |y| = %d\n", SSTD_ABS(500), SSTD_ABS(-690), y);

	// MIN AND MAX
	Serial.printf("min(10, 5) = %d; max(10, 5) = %d\n", MIN2(10, 5), MAX2(10, 5));
	Serial.printf("min(10, 5, 100) = %d; max(10, 5, 100) = %d\n", MIN3(10, 5, 100), MAX3(10, 5, 100));

	// BBIT AND BIT
	x = 0b01100010; // 98
	Serial.printf("bit 5 = %d; bit 4 = %d\n", BBIT(x, 5), BBIT(x, 4));
	Serial.printf("bit 5 = %d; bit 4 = %d; bit 1 = %d\n", BIT(x, 5), BIT(x, 4), BIT(x, 1));

	// BIT SET, CLEAR AND TOGGLE
	Serial.printf("x value after clearing bit 5 = %d\n", BCLEAR(x, 5));
	Serial.printf("x value after setting bit 7 = %d\n", BSET(x, 7));
	Serial.printf("x value after toggling bit 2 = %d\n", BTOGGLE(x, 2));

	// SCALE
	x = 132;
	Serial.printf("\n----- FUNCTIONS\nscale x 0-255 range to 0-100 range: x = %d -> x' = %d\n", x, sStd::scale<uint8_t>(x, 0, 255, 0, 100));	

	// ABS
	Serial.printf("|420| = %d; |-69| = %d\n", sStd::abs<uint16_t>(420), sStd::abs<int8_t>(-69));

	// MIN AND MAX
	Serial.printf("min(100, 500) = %d; max(100, 500) = %d\n", sStd::min<uint16_t>(100, 500), sStd::max<uint16_t>(100, 500));
	Serial.printf("min(100, 50, 1000) = %d; max(100, 50, 1000) = %d\n", sStd::min<uint16_t>(100, 50, 1000), sStd::max<uint16_t>(100, 50, 1000));

	// SUM ALL DIGITS
	Serial.printf("sum of all digits from number 12345678: %d\n", sStd::sumDigits<uint32_t>(12345678));

	// LENGTH
	char str[] = "Hello World!";
	char* str1 = nullptr;
	char str2[] = "Hello";
	char str3[] = "Hellio";
 
	// LENGTH
	Serial.printf("\n----- STRING MANIPULATIONS\nlength until NULL: %d\nlength until space: %d\n", sStd::len(str), sStd::len(str, ' '));

	// COUNT
	Serial.printf("number of Ls in string: %d\nnumber of Ls in string before space: %d\n", sStd::count(str, 'l'), sStd::count(str, 'l', ' '));

	// TOKENIZE
	str1 = sStd::tok(str, ' ');
	Serial.printf("tok: '%s'  -  '%s'\n", str, str1);

	// COMPARE
	Serial.printf("%s and %s are %d\n%s and %s are %d\n", str, str2, sStd::cmp(str, str2), str, str1, sStd::cmp(str, str1));
	Serial.printf("%s and %s are %d\n%s and %s until first L are %d\n", str2, str3, sStd::cmp(str2, str3), str2, str3, sStd::cmp(str2, str3, 'l'));

	// DATA OBJECT
	uint32_t d[] = { 10, 20, 30, 40, 50 };
	uint32_t anotherD[] = { 1000, 10, 1 };
	sStd::Data<uint32_t> testData(d, 5);

	Serial.print("\n ----- DATA OBJECT\ndata from data object: ");
	for (uint8_t i = 0; i < 5; i++) Serial.printf("%d ", testData.get()[i]);

	testData.set(anotherD, SSTD_ARRAY(anotherD));
	Serial.print("\ndata from data object with new values: ");
	for (uint8_t i = 0; i < 3; i++) Serial.printf("%d ", testData.get()[i]);
	Serial.print("\n", 1);

	// SCAN FOR SINGLE PARAMETER
	char inputStr[] = "Word1,Word2-Word3.Word4/Word5";
	sStd::Data<char>out;

	sStd::sscan(inputStr, ',', 0, '-', 0, out);
	Serial.printf("\n----- STRING SCAN\nbegin of 'Word2': '%s'\n", out.get());

	sStd::sscan(inputStr, ',', 0, '-', 0, out, 1);
	Serial.printf("same scan with modify on: '%s'\n", out.get());

	char in[] = "Word1,Word2,Word3";
	sStd::scanData scanList[] = {
		{
			.sepEnd = ',',
			.sepCntEnd = 0
		},

		{
			.sepEnd = ',',
			.sepCntEnd = 0
		},

		{
			.sepEnd = ',',
			.sepCntEnd = 0
		}				
	};

	sStd::sscan(in, scanList, SSTD_ARRAY(scanList), 0, 1);
	Serial.printf("sorted multi scan without modify on: '%s' - '%s' - '%s'\n", scanList[0].output.get(), scanList[1].output.get(), scanList[2].output.get());

	sStd::sscan(in, scanList, SSTD_ARRAY(scanList), 1, 1);
	Serial.printf("sorted multi scan with modify on: '%s' - '%s' - '%s'\n", scanList[0].output.get(), scanList[1].output.get(), scanList[2].output.get());	

	char in2[] = "Word1,Word2,Word3.Word4,Word5";
	sStd::scanData scan[] = {
		{ // OUTPUT: Word2,Word3.Word4
			.sepEnd = ',',
			.sepCntEnd = 1,
			.sepBegin = ',',
			.sepCntBegin = 0
		},

		{ // OUTPUT: Word3.Word4,Word5
			.sepEnd = '\0',
			.sepCntEnd = 0,
			.sepBegin = ',',
			.sepCntBegin = 1
		}				
	};	

	sStd::sscan(in2, scan, AL(scan));
	Serial.print("unsorted multi scan without modify on: '");

	for (uint8_t i = 0; i < scan[0].output.len(); i++) Serial.printf("%c", scan[0].output.get()[i]);
	Serial.print("' - '");
	for (uint8_t i = 0; i < scan[1].output.len(); i++) Serial.printf("%c", scan[1].output.get()[i]);
	Serial.print("'\n");

	// RING BUFFER
	sStd::RingBuffer<char, 64> ring; // 64 chars ring buffer
	char rb[] = "ello World!";
	char rbout[32] = { '\0' };

	Serial.printf("\n----- RING BUFFER\nring buffer size: %d\nnum of free data: %d\nnum of used data: %d\n", ring.size(), ring.free(), ring.used());

	// Write single data
	ring.write('H');

	// Write multiple data - -1 to prevent \0 going into ring buffer
	ring.write(rb, AL(rb) - 1);
	Serial.printf("num of free data after writing: %d\nnum of used data after writing: %d\n", ring.free(), ring.used());

	// Read single data
	ring.read(rbout[0]);
	Serial.printf("read single data: '%s'\n", rbout);

	// Read multiple data from ring buffer
	ring.read(&rbout[1], AL(rbout));
	Serial.printf("read multiple data: '%s'\n", rbout);

	if (ring.isFull()) Serial.print("ring buffer is full\n");
		else Serial.print("ring buffer is not full\n");

	// Flush ring buffer
	ring.flush();

	// SPEED TEST
	uint32_t a = 0, b = 0;
	uint16_t lenRes = 0;
	(void)lenRes;

	Serial.print("\n\n----- SPEED TEST:\n");

	// LENGTH
	char lenStr[] = "Hello, World!";

	a = HAL_GetTick();
	for (uint16_t i = 0; i < 1000; i++) lenRes = sStd::len(lenStr);
	b = HAL_GetTick();
	Serial.printf("len() x1000: %dms\n", b - a);

	// COMPARE
	a = HAL_GetTick();
	for (uint16_t i = 0; i < 1000; i++) lenRes = sStd::cmp(lenStr, lenStr);
	b = HAL_GetTick();
	Serial.printf("cmp() x1000: %dms\n", b - a);

	// SSCAN
	char sscanStr[] = "Word1,Word2-Word3.Word4/Word5";

	a = HAL_GetTick();
	for (uint16_t i = 0; i < 1000; i++) sStd::sscan(sscanStr, ',', 0, '-', 0, out);
	b = HAL_GetTick();
	Serial.printf("sscan() x1000: %dms\n", b - a);

	while (1)
	{
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		HAL_Delay(250);
	}
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
															|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

static void MX_USART1_UART_Init(void)
{
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}
}

static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin : LED_Pin */
	GPIO_InitStruct.Pin = LED_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : PC14 PC15 */
	GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : PD0 PD1 */
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
													|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
													|GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
													|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
													|GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
													|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure peripheral I/O remapping */
	__HAL_AFIO_REMAP_PD01_ENABLE();

}


void Error_Handler(void)
{
	__disable_irq();
	while (1)
	{
	}
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif /* USE_FULL_ASSERT */
