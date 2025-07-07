#include "lcd_display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcd_init() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Speed: 0%      ");
  lcd.setCursor(0, 1);
  lcd.print("PWM: 0         ");
}

void lcd_update(int speedPercent, int pwmValue) {
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.print(speedPercent);
  lcd.print("%   ");
  lcd.setCursor(0, 1);
  lcd.print("PWM: ");
  lcd.print(pwmValue);
  lcd.print("    ");
} 