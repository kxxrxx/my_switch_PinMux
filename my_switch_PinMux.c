#define user_button1                         GPIO_PORTF_DATA0_bit
#define user_button2                         GPIO_PORTF_DATA4_bit
#define red_LED                                 GPIO_PORTF_DATA1_bit
#define blue_LED                               GPIO_PORTF_DATA2_bit
#define green_LED                             GPIO_PORTF_DATA3_bit

void setup_GPIOs();
void main()
{
     signed char s = 0;
     setup_GPIOs();
     while(1)
     {
          if(user_button1 == 0)
          {
              while(user_button1 == 0);
              s++;
          }
          if(s > 7)
          {
              s = 0;
          }
          if(user_button2 == 0)
          {
              while(user_button2 == 0);
              s--;
          }
          if(s < 0)
          {
              s = 7;
          }
          switch(s)
          {
              case 1:
              {
                  red_LED = 1;
                  green_LED = 0;
                  blue_LED = 0;
                  break;
              }
              case 2:
              {
                  red_LED = 0;
                  green_LED = 1;
                  blue_LED = 0;
                  break;

              }

              case 3:

              {

                  red_LED = 0;
                  green_LED = 0;
                  blue_LED = 1;
                  break;
              }
              case 4:
              {
                  red_LED = 1;
                  green_LED = 1;
                  blue_LED = 0;
                  break;
              }
              case 5:
              {
                  red_LED = 1;
                  green_LED = 0;
                  blue_LED = 1;
                  break;
              }
              case 6:
              {
                  red_LED = 0;
                  green_LED = 1;
                  blue_LED = 1;
                  break;
              }
              case 7:
              {
                  red_LED = 0;
                  green_LED = 0;
                  blue_LED = 0;
                  break;
              }
              default:
              {
                  red_LED = 1;
                  green_LED = 1;
                  blue_LED = 1;
                  break;
              }
          }
     }
}

void setup_GPIOs()
{
     delay_ms(2000);
     
     GPIO_Clk_Enable(&GPIO_PORTF);
     
     GPIO_Unlock(_GPIO_COMMIT_PIN_F0);
     
     GPIO_Config(&GPIO_PORTF,
                 (_GPIO_PINMASK_0 | _GPIO_PINMASK_4),
                 _GPIO_DIR_INPUT,
                 (_GPIO_CFG_PULL_UP | _GPIO_CFG_DIGITAL_ENABLE),
                 _GPIO_PINCODE_NONE);
     
     GPIO_Config(&GPIO_PORTF,
                 (_GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3),
                 _GPIO_DIR_OUTPUT,
                 (_GPIO_CFG_DIGITAL_ENABLE | _GPIO_CFG_DRIVE_8mA),
                 _GPIO_PINCODE_NONE);
}
