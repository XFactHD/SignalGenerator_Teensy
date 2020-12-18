EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Custom:NHD-2.8-240320AF-CSXP-F U1
U 1 1 5E239A1A
P 4300 2100
F 0 "U1" H 4300 2150 50  0000 C CNN
F 1 "NHD-2.8-240320AF-CSXP-F" H 4300 2050 50  0000 C CNN
F 2 "Custom:NHD-2.8-240320AF-CSXP-F" H 4300 2100 50  0001 C CNN
F 3 "" H 4300 2100 50  0001 C CNN
	1    4300 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J1
U 1 1 5E23E863
P 4550 5600
F 0 "J1" V 4600 6650 50  0000 R CNN
F 1 "Conn_02x20_Odd_Even" V 4600 6000 50  0000 R CNN
F 2 "Custom:HARTING_15150402601000" H 4550 5600 50  0001 C CNN
F 3 "~" H 4550 5600 50  0001 C CNN
	1    4550 5600
	0    -1   -1   0   
$EndComp
Text GLabel 5550 5250 1    50   Input ~ 0
3.3V
Text GLabel 4450 5250 1    50   Input ~ 0
GND
Text GLabel 5550 5850 3    50   Input ~ 0
GND
Text GLabel 5250 5850 3    50   Input ~ 0
LCD_D1
Text GLabel 5150 5850 3    50   Input ~ 0
LCD_D3
Text GLabel 5050 5850 3    50   Input ~ 0
LCD_D5
Text GLabel 4950 5850 3    50   Input ~ 0
LCD_D7
Text GLabel 4850 5850 3    50   Input ~ 0
LCD_D9
Text GLabel 4750 5850 3    50   Input ~ 0
LCD_D11
Text GLabel 4650 5850 3    50   Input ~ 0
LCD_D13
Text GLabel 4550 5850 3    50   Input ~ 0
LCD_D15
Text GLabel 5350 5850 3    50   Input ~ 0
~LCD_WR
Text GLabel 5450 5850 3    50   Input ~ 0
~LCD_CS
Text GLabel 4650 5250 1    50   Input ~ 0
LCD_D14
Wire Wire Line
	5550 5250 5550 5300
Wire Wire Line
	5450 5850 5450 5800
Wire Wire Line
	5350 5850 5350 5800
Wire Wire Line
	4650 5250 4650 5300
Wire Wire Line
	4450 5300 4450 5250
Wire Wire Line
	5250 5800 5250 5850
Wire Wire Line
	5150 5800 5150 5850
Wire Wire Line
	5050 5800 5050 5850
Wire Wire Line
	4950 5800 4950 5850
Wire Wire Line
	4850 5800 4850 5850
Wire Wire Line
	4750 5800 4750 5850
Wire Wire Line
	4650 5800 4650 5850
Wire Wire Line
	4550 5800 4550 5850
Wire Wire Line
	5550 5800 5550 5850
Text GLabel 5350 1450 2    50   Input ~ 0
LCD_D1
Text GLabel 5350 1650 2    50   Input ~ 0
LCD_D3
Text GLabel 5350 1850 2    50   Input ~ 0
LCD_D5
Text GLabel 5350 2050 2    50   Input ~ 0
LCD_D7
Text GLabel 5350 2250 2    50   Input ~ 0
LCD_D9
Text GLabel 5350 2450 2    50   Input ~ 0
LCD_D11
Text GLabel 5350 2650 2    50   Input ~ 0
LCD_D13
Text GLabel 5350 2850 2    50   Input ~ 0
LCD_D15
Text GLabel 5350 2550 2    50   Input ~ 0
LCD_D12
Text GLabel 5350 2350 2    50   Input ~ 0
LCD_D10
Text GLabel 5350 2150 2    50   Input ~ 0
LCD_D8
Text GLabel 5350 1750 2    50   Input ~ 0
LCD_D4
Text GLabel 5350 1550 2    50   Input ~ 0
LCD_D2
Text GLabel 5350 1350 2    50   Input ~ 0
LCD_D0
Text GLabel 5350 2750 2    50   Input ~ 0
LCD_D14
Text GLabel 5350 1950 2    50   Input ~ 0
LCD_D6
Text GLabel 4250 1050 1    50   Input ~ 0
3.3V
Text GLabel 4350 1050 1    50   Input ~ 0
3.3V
Text GLabel 4200 3150 3    50   Input ~ 0
GND
Text GLabel 4300 3150 3    50   Input ~ 0
GND
Text GLabel 4400 3150 3    50   Input ~ 0
GND
Text GLabel 2900 2650 0    50   Input ~ 0
5V
$Comp
L Device:R R1
U 1 1 5E258A36
P 3100 2650
F 0 "R1" V 3200 2650 50  0000 C CNN
F 1 "100" V 3100 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3030 2650 50  0001 C CNN
F 3 "~" H 3100 2650 50  0001 C CNN
	1    3100 2650
	0    1    1    0   
$EndComp
Text GLabel 3250 2250 0    50   Input ~ 0
GND
Text GLabel 3250 2350 0    50   Input ~ 0
GND
Text GLabel 3250 2450 0    50   Input ~ 0
GND
Text GLabel 3250 2550 0    50   Input ~ 0
GND
Text GLabel 3250 1550 0    50   Input ~ 0
~LCD_CS
Text GLabel 3250 1750 0    50   Input ~ 0
~LCD_WR
Text GLabel 3250 1950 0    50   Input ~ 0
~LCD_RESET
Text GLabel 3250 1650 0    50   Input ~ 0
LCD_DC
Wire Wire Line
	3250 1550 3300 1550
Wire Wire Line
	3250 1650 3300 1650
Wire Wire Line
	3250 1750 3300 1750
Wire Wire Line
	3250 1950 3300 1950
Wire Wire Line
	3250 2250 3300 2250
Wire Wire Line
	3250 2350 3300 2350
Wire Wire Line
	3250 2450 3300 2450
Wire Wire Line
	3250 2550 3300 2550
Wire Wire Line
	3250 2650 3300 2650
Wire Wire Line
	2900 2650 2950 2650
Wire Wire Line
	4200 3100 4200 3150
Wire Wire Line
	4300 3100 4300 3150
Wire Wire Line
	4400 3100 4400 3150
Wire Wire Line
	4250 1050 4250 1100
Wire Wire Line
	4350 1050 4350 1100
Wire Wire Line
	5300 1350 5350 1350
Wire Wire Line
	5300 1450 5350 1450
Wire Wire Line
	5300 1550 5350 1550
Wire Wire Line
	5300 1650 5350 1650
Wire Wire Line
	5300 1750 5350 1750
Wire Wire Line
	5300 1850 5350 1850
Wire Wire Line
	5300 1950 5350 1950
Wire Wire Line
	5300 2050 5350 2050
Wire Wire Line
	5300 2150 5350 2150
Wire Wire Line
	5300 2250 5350 2250
Wire Wire Line
	5300 2350 5350 2350
Wire Wire Line
	5300 2450 5350 2450
Wire Wire Line
	5300 2550 5350 2550
Wire Wire Line
	5300 2650 5350 2650
Wire Wire Line
	5300 2750 5350 2750
Wire Wire Line
	5300 2850 5350 2850
Text GLabel 3250 1850 0    50   Input ~ 0
3.3V
Wire Wire Line
	3250 1850 3300 1850
Text GLabel 9750 2150 1    50   Input ~ 0
GND
Wire Wire Line
	9750 2150 9750 2200
Wire Wire Line
	3750 5850 3750 5800
Wire Wire Line
	3850 5850 3850 5800
Wire Wire Line
	3950 5850 3950 5800
Wire Wire Line
	4450 5800 4450 5850
Wire Wire Line
	5450 5300 5450 5250
Wire Wire Line
	4550 5250 4550 5300
Wire Wire Line
	4750 5250 4750 5300
Wire Wire Line
	4850 5250 4850 5300
Wire Wire Line
	4950 5250 4950 5300
Wire Wire Line
	5050 5250 5050 5300
Wire Wire Line
	5150 5250 5150 5300
Wire Wire Line
	5250 5250 5250 5300
Wire Wire Line
	5350 5250 5350 5300
Text GLabel 4550 5250 1    50   Input ~ 0
~LCD_RESET
Text GLabel 5350 5250 1    50   Input ~ 0
LCD_D0
Text GLabel 5250 5250 1    50   Input ~ 0
LCD_D2
Text GLabel 5150 5250 1    50   Input ~ 0
LCD_D4
Text GLabel 5050 5250 1    50   Input ~ 0
LCD_D6
Text GLabel 4950 5250 1    50   Input ~ 0
LCD_D8
Text GLabel 4850 5250 1    50   Input ~ 0
LCD_D10
Text GLabel 4750 5250 1    50   Input ~ 0
LCD_D12
Text GLabel 5450 5250 1    50   Input ~ 0
LCD_DC
Text GLabel 4450 5850 3    50   Input ~ 0
5V
$Comp
L Device:C C1
U 1 1 5E973CDC
P 5950 2100
F 0 "C1" H 6065 2146 50  0000 L CNN
F 1 "100n" H 6065 2055 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5988 1950 50  0001 C CNN
F 3 "~" H 5950 2100 50  0001 C CNN
	1    5950 2100
	1    0    0    -1  
$EndComp
Text GLabel 5950 1900 1    50   Input ~ 0
3.3V
Text GLabel 5950 2300 3    50   Input ~ 0
GND
Wire Wire Line
	5950 1900 5950 1950
Wire Wire Line
	5950 2250 5950 2300
$Comp
L Device:C C2
U 1 1 5E97A2ED
P 6400 2100
F 0 "C2" H 6515 2146 50  0000 L CNN
F 1 "10u" H 6515 2055 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6438 1950 50  0001 C CNN
F 3 "~" H 6400 2100 50  0001 C CNN
	1    6400 2100
	1    0    0    -1  
$EndComp
Text GLabel 6400 1900 1    50   Input ~ 0
3.3V
Text GLabel 6400 2300 3    50   Input ~ 0
GND
Wire Wire Line
	6400 1900 6400 1950
Wire Wire Line
	6400 2250 6400 2300
Text GLabel 9750 2750 3    50   Input ~ 0
GND
Text GLabel 8950 2750 3    50   Input ~ 0
BTN_1
Text GLabel 9050 2750 3    50   Input ~ 0
BTN_2
Wire Wire Line
	9750 2750 9750 2700
Text GLabel 4350 5850 3    50   Input ~ 0
BTN_1
Text GLabel 4250 5850 3    50   Input ~ 0
BTN_2
Text GLabel 4150 5850 3    50   Input ~ 0
BTN_3
Wire Wire Line
	4050 5800 4050 5850
Wire Wire Line
	4150 5800 4150 5850
Wire Wire Line
	4250 5800 4250 5850
Wire Wire Line
	4350 5800 4350 5850
Text GLabel 4050 5850 3    50   Input ~ 0
BTN_4
Text GLabel 3950 5850 3    50   Input ~ 0
BTN_5
Text GLabel 3850 5850 3    50   Input ~ 0
BTN_6
Text GLabel 3750 5850 3    50   Input ~ 0
BTN_7
Text GLabel 4350 5250 1    50   Input ~ 0
LED_1
Text GLabel 4250 5250 1    50   Input ~ 0
LED_2
Text GLabel 4150 5250 1    50   Input ~ 0
LED_3
Text GLabel 4050 5250 1    50   Input ~ 0
LED_4
Text GLabel 3950 5250 1    50   Input ~ 0
LED_5
Text GLabel 3850 5250 1    50   Input ~ 0
LED_6
Text GLabel 3750 5250 1    50   Input ~ 0
LED_7
Wire Wire Line
	3750 5250 3750 5300
Wire Wire Line
	3850 5250 3850 5300
Wire Wire Line
	3950 5250 3950 5300
Wire Wire Line
	4050 5250 4050 5300
Wire Wire Line
	4150 5250 4150 5300
Wire Wire Line
	4250 5250 4250 5300
Wire Wire Line
	4350 5250 4350 5300
Text GLabel 3650 5250 1    50   Input ~ 0
LED_8
Text GLabel 3650 5850 3    50   Input ~ 0
BTN_8
Wire Wire Line
	3650 5250 3650 5300
Wire Wire Line
	3650 5800 3650 5850
$Comp
L 74xx:74HCT541 U2
U 1 1 5EB14AAC
P 7150 5300
F 0 "U2" H 7150 5550 50  0000 C CNN
F 1 "74LVC541" H 7150 5000 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-20_4.4x6.5mm_Pitch0.65mm" H 7150 5300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HCT541" H 7150 5300 50  0001 C CNN
	1    7150 5300
	1    0    0    -1  
$EndComp
Text GLabel 7150 6150 3    50   Input ~ 0
GND
Text GLabel 7150 4450 1    50   Input ~ 0
5V
Wire Wire Line
	7150 4450 7150 4500
Wire Wire Line
	7150 6100 7150 6150
Text GLabel 6600 5500 0    50   Input ~ 0
LED_1
Text GLabel 6600 5400 0    50   Input ~ 0
LED_2
Text GLabel 6600 5300 0    50   Input ~ 0
LED_3
Text GLabel 6600 5200 0    50   Input ~ 0
LED_4
Text GLabel 6600 5100 0    50   Input ~ 0
LED_5
Text GLabel 6600 5000 0    50   Input ~ 0
LED_6
Text GLabel 6600 4900 0    50   Input ~ 0
LED_7
Text GLabel 6600 4800 0    50   Input ~ 0
LED_8
Wire Wire Line
	6600 4800 6650 4800
Wire Wire Line
	6600 4900 6650 4900
Wire Wire Line
	6600 5000 6650 5000
Wire Wire Line
	6600 5100 6650 5100
Wire Wire Line
	6600 5200 6650 5200
Wire Wire Line
	6600 5300 6650 5300
Wire Wire Line
	6600 5400 6650 5400
Wire Wire Line
	6600 5500 6650 5500
Text GLabel 6600 5700 0    50   Input ~ 0
GND
Text GLabel 6600 5800 0    50   Input ~ 0
GND
Wire Wire Line
	6600 5700 6650 5700
Wire Wire Line
	6600 5800 6650 5800
$Comp
L Connector_Generic:Conn_02x09_Odd_Even J2
U 1 1 5EB34197
P 9350 2500
F 0 "J2" H 9400 3000 50  0000 C CNN
F 1 "Conn_02x09_Odd_Even" V 9400 2500 50  0000 C CNN
F 2 "Custom:Hirose_DF11GZ-18DP-2V20" H 9350 2500 50  0001 C CNN
F 3 "~" H 9350 2500 50  0001 C CNN
	1    9350 2500
	0    -1   -1   0   
$EndComp
Text GLabel 9150 2750 3    50   Input ~ 0
BTN_3
Text GLabel 9250 2750 3    50   Input ~ 0
BTN_4
Text GLabel 9350 2750 3    50   Input ~ 0
BTN_5
Text GLabel 9450 2750 3    50   Input ~ 0
BTN_6
Text GLabel 9550 2750 3    50   Input ~ 0
BTN_7
Text GLabel 9650 2750 3    50   Input ~ 0
BTN_8
Text GLabel 7700 5500 2    50   Input ~ 0
LED_OUT_1
Text GLabel 7700 5400 2    50   Input ~ 0
LED_OUT_2
Text GLabel 7700 5300 2    50   Input ~ 0
LED_OUT_3
Text GLabel 7700 5200 2    50   Input ~ 0
LED_OUT_4
Text GLabel 7700 5100 2    50   Input ~ 0
LED_OUT_5
Text GLabel 7700 5000 2    50   Input ~ 0
LED_OUT_6
Text GLabel 7700 4900 2    50   Input ~ 0
LED_OUT_7
Text GLabel 7700 4800 2    50   Input ~ 0
LED_OUT_8
Wire Wire Line
	7650 4800 7700 4800
Wire Wire Line
	7650 4900 7700 4900
Wire Wire Line
	7650 5000 7700 5000
Wire Wire Line
	7650 5100 7700 5100
Wire Wire Line
	7650 5200 7700 5200
Wire Wire Line
	7650 5300 7700 5300
Wire Wire Line
	7650 5400 7700 5400
Wire Wire Line
	7650 5500 7700 5500
Text GLabel 8950 2150 1    50   Input ~ 0
LED_OUT_1
Text GLabel 9050 2150 1    50   Input ~ 0
LED_OUT_2
Text GLabel 9150 2150 1    50   Input ~ 0
LED_OUT_3
Text GLabel 9250 2150 1    50   Input ~ 0
LED_OUT_4
Text GLabel 9350 2150 1    50   Input ~ 0
LED_OUT_5
Text GLabel 9450 2150 1    50   Input ~ 0
LED_OUT_6
Text GLabel 9550 2150 1    50   Input ~ 0
LED_OUT_7
Text GLabel 9650 2150 1    50   Input ~ 0
LED_OUT_8
Wire Wire Line
	8950 2150 8950 2200
Wire Wire Line
	9050 2150 9050 2200
Wire Wire Line
	9150 2150 9150 2200
Wire Wire Line
	9250 2150 9250 2200
Wire Wire Line
	9350 2150 9350 2200
Wire Wire Line
	9450 2150 9450 2200
Wire Wire Line
	9550 2150 9550 2200
Wire Wire Line
	9650 2150 9650 2200
Wire Wire Line
	8950 2700 8950 2750
Wire Wire Line
	9050 2700 9050 2750
Wire Wire Line
	9150 2700 9150 2750
Wire Wire Line
	9250 2700 9250 2750
Wire Wire Line
	9350 2700 9350 2750
Wire Wire Line
	9450 2700 9450 2750
Wire Wire Line
	9550 2700 9550 2750
Wire Wire Line
	9650 2700 9650 2750
$Comp
L Device:C C3
U 1 1 5EBB4BD7
P 8350 5150
F 0 "C3" H 8465 5196 50  0000 L CNN
F 1 "100n" H 8465 5105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8388 5000 50  0001 C CNN
F 3 "~" H 8350 5150 50  0001 C CNN
	1    8350 5150
	1    0    0    -1  
$EndComp
Text GLabel 8350 4950 1    50   Input ~ 0
5V
Text GLabel 8350 5350 3    50   Input ~ 0
GND
Wire Wire Line
	8350 4950 8350 5000
Wire Wire Line
	8350 5300 8350 5350
$EndSCHEMATC
