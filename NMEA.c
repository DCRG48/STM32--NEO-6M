/*
 * NMEA.c
 *
 *  Created on: Jan 3, 2025
 *      Author: doudz
 */


#include "NMEA.h"

extern UART_HandleTypeDef huart1;



void GPS_getLocation(char* sentence)

{

    char *token;

    char* latitude = 0;
    char* longitude = 0;
    float dilution = 0;
    float Min = 0;
    int8_t Deg = 0;
    float LAT = 0;


    token = strtok(sentence, ",");
    int8_t i = 1;

while (token != NULL)
	{

	switch (i) {

		case 3:

			latitude = token;

			break;

		case 5:
			longitude = token;

			break;

		case 9:

			dilution = strtof(token, NULL);

				token = strtok(NULL, ",");


//				ptr_1 = De;
//				ptr_2 = &longitude;
//				ptr_3 = &dilution;

			break;

		default:

			break;
			}

	token = strtok(NULL, ",");
	i++;


	}

	Deg = Convert_to_Deg(latitude);
	Min = Convert_to_Min(latitude);
	LAT = Deg+Min;

}


float Convert_to_Min (char* location)
{
	int8_t  i = 0;
	char* val = location;
	float sec = 0;
	int min = 0;
	float x = 0;

	val = strtok(location, ".");

	while (i != 2)
	{
		switch (i)
		{

			case 0:
				min = (atoi(val));
				min = min%100;

				break;

			case 1:

				sec = (strtof(val,NULL))/1000;
				break;

			default:
				break;

		}

		val = strtok(NULL, ",");
		i++;

	}

	x = sec/3600;
	x = ((float)min/60)+ x;

	return x;
}

int8_t Convert_to_Deg(char* location)
{
	int deg = 0;

	deg = (strtof(location,NULL))/100;

	return deg;
}

