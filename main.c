#include "main.h"
#include "ssd1306.h"
#include "fonts.h"
#include <string.h>

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

/* USER CODE BEGIN 0 */
void Display_Message(char *msg)
{
    SSD1306_Clear();
    SSD1306_GotoXY(10, 20);
    SSD1306_Puts(msg, &Font_7x10, 1);
    SSD1306_UpdateScreen();
}
/* USER CODE END 0 */

int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_I2C1_Init();

  /* USER CODE BEGIN 2 */
  SSD1306_Init();
  Display_Message("System Ready");
  HAL_Delay(1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  while (1)
  {
    /* USER CODE BEGIN WHILE */

    GPIO_PinState ir_state =
        HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);   // IR sensor

    if(ir_state == GPIO_PIN_SET)   // Object detected
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); // Buzzer ON
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); // LED ON

        Display_Message("Object Detected");

        // Button to silence buzzer
        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3) == GPIO_PIN_SET)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
        }
    }
    else   // No object
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);

        Display_Message("No Object");
    }

    HAL_Delay(100);   // small delay for stability

    /* USER CODE END WHILE */
  }
}
