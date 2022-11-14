
LCD I2C example in Zephyr
######

Overview
********

This sample shows how to interface an I2C LCD display, the type tha have an adapter board with a I2C GPIO expander from NXO , the PCF8574T.  The exmaple has a submodule dpeemdency on the lcd_i2c_criver found here https://github.com/TrevorHeyl/Zephyr_ESP32_LCD_I2C/edit/master/README.rst

Requirements
************

#. ESP32 Devkit C
#. lcd_i2c_driver submodule (will be automatically pulled in)
#. Zephyr OS and West installed

Building and Running
********************
Initially and everytine you start a shell please run:
<br>
$>source ~/zephyrproject/zephyr/zephyr-env.sh

Build and flash as follows:
<br>
For the first build: 

For esp_custom board 

$> west build -p -b esp_custom


For subsequent builds:

$> west build


To Flash:

$> west flash


After flashing, optinally view the printk output on a terminal emnulator @ 115200, no handshaking

$> west flash ; minicom

