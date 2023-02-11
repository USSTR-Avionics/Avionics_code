#include "debug_macros.h"
#include "sensor_fram.h"
#include <Arduino.h>
#include <cstdint>
#include <stdint.h>

#define ERR_READING 0
int fram_cursor         = 0x10;

const float upper_bound = 100.0F;
const float lower_bound = -100.0F;


void dump_fram_to_serial()
	{
	// TODO: build csv string and dump to USB serial
	}

auto write_temperature_to_fram(float temp) -> int
	{
	// TODO: test and work

	float upper_bound = 127.0f;
	float lower_bound = -128.0f;

	if (temp > upper_bound || temp < lower_bound)
		{
		write_to_fram(ERR_READING, fram_cursor);
		fram_cursor += 1;
		return EXIT_FAILURE;
		}

	temp += 128;
	uint8_t whole_part   = (uint8_t)temp;
	uint8_t decimal_part = (uint8_t)((temp - whole_part) * 100);
	write_to_fram(whole_part, fram_cursor);


	auto whole_part   = (uint8_t)temp;
	auto decimal_part = (uint8_t)((temp - whole_part) * 1000);
	whole_part += 101;

	write_to_fram(fram_cursor, whole_part);
	fram_cursor += 1;
	write_to_fram(decimal_part, fram_cursor);
	fram_cursor += 1;

	return EXIT_SUCCESS;
	}

auto read_temperature_from_fram(int where) -> float
	{
	// TODO:
	uint8_t whole = read_from_fram(where);
	where++; // read the next byte
	uint8_t decimal   = read_from_fram(where);
	float temperature = ((float)whole - 128.0f) + ((float)decimal / 100.0f);

	return temperature;
	}

/**
 * @brief Writes the accelerometer data to the FRAM.
 * @param accel The accelerometer data to write to the FRAM.
 * @return EXIT_SUCCESS if the write succeeded, EXIT_FAILURE otherwise.
 */
auto write_acceleration_to_fram(float accel) -> int
	{
	// TODO: test and work
	// handle negative accelation values

	float upper_bound = 127.0f;
	float lower_bound = -128.0f;

	if (accel > upper_bound || accel < lower_bound)
		{
		write_to_fram(ERR_READING, fram_cursor);
		fram_cursor += 1;
		return EXIT_FAILURE;
		}
	uint8_t whole_part   = (uint8_t)accel;
	uint8_t decimal_part = (uint8_t)((accel - whole_part) * 100);

	whole_part += 101;

	write_to_fram(whole_part, fram_cursor);
	fram_cursor += 1;
	write_to_fram(decimal_part, fram_cursor);
	fram_cursor += 1;

	return EXIT_SUCCESS;
	}

auto read_acceleration_from_fram(int where) -> float
	{
	// TODO:
	where = 0;
	return 0.0F;
	}