//
// Copyright (c) 2013 Danny Havenith
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
/**
 * Demonstration of the ws2811 code for low-ram devices such as the attiny13
 */
#define WS2811_PORT PORTB

#include <avr/io.h>
#include "color_cycle.hpp"
#include "ws2811.h"

using namespace ws2811;

namespace {
	/// transmit on bit 4
	const uint8_t channel = 4;

	/// where in a low-ram situation, limit the number of leds
	/// to 15 (=45 bytes)
	const uint16_t led_count = 15;

	rgb leds[led_count];

	/// color sequence to cycle (additional 12 bytes)
	const rgb sequence[] = {
			rgb( 128, 40, 0),
			rgb( 0, 128, 40),
			rgb( 40, 0, 128),
			rgb( 50, 50, 50)
	};
}

int main()
{
    DDRB = _BV(channel);
	color_cycle::color_cycle( sequence, leds, channel);
}