#pragma once
#include <LiquidCrystal_I2C.h>

void lcd_init();
void lcd_update(int speedPercent, int pwmValue); 