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
L Connector:AudioPlug4 J?
U 1 1 5EE230F1
P 4100 3250
F 0 "J?" H 3570 3157 50  0000 R CNN
F 1 "Android Smartphone Plug" H 4550 2950 50  0000 R CNN
F 2 "" H 4450 3150 50  0001 C CNN
F 3 "~" H 4450 3150 50  0001 C CNN
	1    4100 3250
	1    0    0    1   
$EndComp
$Comp
L Connector:AudioPlug2 J?
U 1 1 5EE23765
P 5950 3800
F 0 "J?" H 5421 3847 50  0000 R CNN
F 1 "Microphone / Audio In" H 6450 3550 50  0000 R CNN
F 2 "" H 6300 3750 50  0001 C CNN
F 3 "~" H 6300 3750 50  0001 C CNN
	1    5950 3800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EE249DC
P 5350 3350
F 0 "#PWR?" H 5350 3100 50  0001 C CNN
F 1 "GND" H 5355 3175 50  0000 C CNN
F 2 "" H 5350 3350 50  0001 C CNN
F 3 "" H 5350 3350 50  0001 C CNN
	1    5350 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3050 5350 3050
Wire Wire Line
	5350 3250 5350 3350
Wire Wire Line
	5350 3150 4700 3150
Wire Wire Line
	4700 3250 5200 3250
Wire Wire Line
	5350 3700 5200 3700
Wire Wire Line
	5200 3700 5200 3250
Connection ~ 5200 3250
Wire Wire Line
	5200 3250 5350 3250
$Comp
L Device:R R?
U 1 1 5EE2926A
P 4850 3500
F 0 "R?" H 4920 3547 50  0000 L CNN
F 1 "2.2k" H 4920 3454 50  0000 L CNN
F 2 "" V 4780 3500 50  0001 C CNN
F 3 "~" H 4850 3500 50  0001 C CNN
	1    4850 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3350 4850 3350
Wire Wire Line
	4850 3650 4850 3700
Wire Wire Line
	4850 3700 5200 3700
Connection ~ 5200 3700
$Comp
L Device:CP1_Small C?
U 1 1 5EE2A90C
P 4700 3550
F 0 "C?" H 4610 3503 50  0000 R CNN
F 1 "3.3µ" H 4610 3596 50  0000 R CNN
F 2 "" H 4700 3550 50  0001 C CNN
F 3 "~" H 4700 3550 50  0001 C CNN
	1    4700 3550
	1    0    0    1   
$EndComp
Wire Wire Line
	4700 3450 4700 3350
Connection ~ 4700 3350
Wire Wire Line
	4700 3650 4700 3900
Wire Wire Line
	4700 3900 5350 3900
$Comp
L Connector:AudioJack3 J?
U 1 1 5EE2C8F0
P 5550 3150
F 0 "J?" H 5270 3177 50  0000 R CNN
F 1 "Headphone / Audio Out" H 5650 3400 50  0000 R CNN
F 2 "" H 5550 3150 50  0001 C CNN
F 3 "~" H 5550 3150 50  0001 C CNN
	1    5550 3150
	-1   0    0    -1  
$EndComp
Connection ~ 5350 3250
$EndSCHEMATC
