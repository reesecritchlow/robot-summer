#include <Wire.h>
#include "Adafruit_SSD1306.h"
#include "tape-navigator.h"
#include "drivetrain.h"
#include "infrared-navigator.h"
#include "config.h"
#include "encoder-navigator.h"
#include "pid-system.h"
#include "state-machine.h"

namespace Display {
	Adafruit_SSD1306 display_handler(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

	void displayTapeMetrics() {
	display_handler.clearDisplay();
	display_handler.setCursor(0, 0);

	display_handler.println("Tape Following");

	display_handler.print(Tape::left_reflectance);
	display_handler.print(" ");
	display_handler.print(Tape::middle_reflectance);
	display_handler.print(" ");
	display_handler.println(Tape::right_reflectance);
	display_handler.print(PID::kp);
	display_handler.print(" ");
    display_handler.print(PID::ki);
    display_handler.print(" ");
	display_handler.println(PID::kd);
	display_handler.print(Tape::last_pid_multiplier);
	display_handler.print(" ");
	display_handler.print(Drivetrain::left_speed);
	display_handler.print(" ");
	display_handler.println(Drivetrain::right_speed);
	display_handler.println(Tape::transformed_PID);

	display_handler.print(Infrared::left_signal);
	display_handler.print(" ");
	display_handler.println(Infrared::right_signal);

	display_handler.print(Encoders::left_count);
	display_handler.print(" ");
	display_handler.print(Encoders::right_count);


	if (Drivetrain::left_direction) {
		display_handler.print("fwd");
	} else {
		display_handler.print("rev");
	}

	display_handler.print(" ");

	if (Drivetrain::right_direction) {
		display_handler.println("fwd");
	} else {
		display_handler.println("rev");
	}

	display_handler.display();
	}

	void displayInfraredMetrics() {
	
	display_handler.clearDisplay();
	display_handler.setCursor(0, 0);

	display_handler.print(Infrared::left_signal);
	display_handler.print(" ");
	display_handler.println(Infrared::right_signal);
	display_handler.print("P,D: ");
	display_handler.print(PID::kp);
	display_handler.print(" ");
	display_handler.println(PID::kd);
	display_handler.print(Tape::last_pid_multiplier);

	


	display_handler.display();
	}

	void displayEncoderMetrics() {
		display_handler.clearDisplay();
		display_handler.setCursor(0, 0);

		display_handler.println("encoder");

		display_handler.print(Encoders::left_destination_count);
		display_handler.print(" ");
		display_handler.println(Encoders::right_destination_count);

		display_handler.print(Encoders::left_count);
		display_handler.print(" ");
		display_handler.println(Encoders::right_count);

		display_handler.print(Encoders::left_direction);
		display_handler.print(" ");
		display_handler.println(Encoders::right_direction);
		
		display_handler.print(Drivetrain::left_speed);
		display_handler.print(" ");
		display_handler.println(Drivetrain::right_speed);

		if (Drivetrain::left_direction) {
			display_handler.print("fwd");
		} else {
			display_handler.print("rev");
		}

		display_handler.print(" ");

		if (Drivetrain::right_direction) {
			display_handler.println("fwd");
		} else {
			display_handler.println("rev");
		}

        display_handler.print(StateMachine::search_direction);
		display_handler.display();
	}

	const unsigned char epd_bitmap_Bitmap [] PROGMEM = {
		// 'ab6761610000e5eb35f91df1e1a8703f27132550, 128x64px
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa8, 0xad, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0xff, 0xff, 0xfe, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xe3, 0xff, 0xbb, 0xcf, 0xff, 0xff, 0x3f, 0xf3, 0xff, 0xff, 0xcf, 0xbf, 0xff, 0xf1, 0xff, 
		0xff, 0xc0, 0x00, 0x27, 0x3f, 0xff, 0xff, 0xcf, 0x8f, 0xff, 0xff, 0xf3, 0xb8, 0x00, 0x00, 0xff, 
		0xff, 0xc0, 0x00, 0x2e, 0x7f, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xf9, 0xe0, 0x00, 0x00, 0xff, 
		0xff, 0x80, 0x00, 0x0c, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xfc, 0xc0, 0x00, 0x00, 0x7f, 
		0xff, 0x80, 0x00, 0x09, 0xff, 0xf8, 0x07, 0xf8, 0x7f, 0xc0, 0x7f, 0xfe, 0x40, 0x00, 0x00, 0x7f, 
		0xff, 0xc0, 0x00, 0x09, 0xff, 0xf0, 0x03, 0xf8, 0x7f, 0x80, 0x3f, 0xfe, 0xc8, 0x00, 0x00, 0xff, 
		0xff, 0xe8, 0x00, 0x09, 0xff, 0xf0, 0x03, 0xf8, 0x7f, 0xa0, 0x3f, 0xfe, 0x40, 0x00, 0x0f, 0xff, 
		0xff, 0xdf, 0xe0, 0x09, 0xff, 0xfa, 0x3f, 0xf8, 0x7f, 0xc1, 0x7f, 0xfe, 0x40, 0x07, 0xff, 0xff, 
		0xff, 0xf7, 0xff, 0x04, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xfc, 0xc1, 0xff, 0xff, 0xff, 
		0xff, 0xef, 0xff, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xfd, 0x83, 0xff, 0xff, 0xff, 
		0xff, 0xbf, 0xff, 0xd0, 0x7f, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xfb, 0x3f, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x8c, 0x07, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xfc, 0x07, 0xff, 0xfe, 0x30, 0x01, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xe0, 0x04, 0x00, 0x1f, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
		0xfe, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5f, 
		0xf0, 0x03, 0xff, 0xff, 0xff, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x07, 
		0xf0, 0x00, 0x7f, 0xe0, 0x1f, 0xc6, 0x7f, 0x87, 0xe7, 0xfc, 0x7b, 0xe0, 0x1f, 0xff, 0xc0, 0x07, 
		0xf0, 0x00, 0x1f, 0xc0, 0x07, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x07, 0xfe, 0x00, 0x03, 
		0xfc, 0x00, 0x07, 0x80, 0x07, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x00, 0x01, 0xf0, 0x00, 0x77, 
		0xff, 0x80, 0x01, 0x00, 0x01, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0x00, 0x01, 0xe0, 0x03, 0xff, 
		0xfd, 0xf8, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x80, 0x1f, 0xff, 
		0xfd, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0xff, 
		0xfd, 0xff, 0x80, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 
		0xfd, 0xff, 0xc0, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x03, 0xff, 0xff, 
		0xfd, 0xfe, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 
		0xff, 0xff, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xdf, 0xff, 
		0xfe, 0xff, 0xff, 0xe0, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
		0xfe, 0x7f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
		0xff, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 
		0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0xdf, 0xff, 0xff, 0xc0, 0x80, 0x00, 0x00, 0x77, 0xff, 0xff, 
		0xff, 0x90, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x80, 0x00, 0x00, 0x7c, 0x3f, 0x7f, 
		0xff, 0xda, 0x01, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x80, 0x00, 0x00, 0x7f, 0xff, 0xff, 
		0xff, 0xff, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x7f, 0xff, 0xff, 
		0xff, 0x87, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x80, 0x7f, 0xff, 0xff, 
		0xff, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x7f, 0xfc, 0xff, 
		0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x78, 0x00, 0x00, 0x00, 0x00, 0x41, 0xff, 
		0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x43, 0xff
	};

	// 'le_monke', 128x64px
	const unsigned char epd_bitmap_le_monke [] PROGMEM = {
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x04, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x03, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0x80, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0x80, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0x87, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0x1f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7d, 0x7e, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x08, 0x30, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x04, 0x18, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x0c, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x08, 0x70, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0x80, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x06, 0x1f, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x7e, 0x0f, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xfd, 0x07, 0xf0, 0x00, 0x1f, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xfb, 0x07, 0xf0, 0x00, 0x07, 0xe4, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xe0, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0x80, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xfe, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xfe, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xf8, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xf8, 0x00, 0x3f, 0xfe, 0x60, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 
		0xff, 0xff, 0xe0, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 
		0xff, 0xff, 0xc0, 0x00, 0x07, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 
		0xff, 0xff, 0xc0, 0x00, 0x03, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 
		0xff, 0xff, 0x80, 0x00, 0x00, 0x3c, 0x0f, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xf8, 0x3f, 0xff, 0xff, 
		0xff, 0xff, 0x80, 0x00, 0x00, 0x18, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x07, 0xfc, 0x1f, 0xff, 0xff, 
		0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xf0, 0x1f, 0xff, 0xff, 
		0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0xff, 0x80, 0x00, 0x00, 0x30, 0x0f, 0xff, 0xff, 
		0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 
		0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 
		0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 
		0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x03, 0xff, 0xff, 
		0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0xff, 0xff, 
		0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xe0, 0x00, 0x78, 0x00, 
		0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x07, 0xff, 0xf0, 0x00, 0x78, 0x03, 
		0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x7f, 0xff, 0xf8, 0x00, 0x73, 0xf0, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x70, 0x20, 
		0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x30, 0x00, 
		0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x38, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3c, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xbf, 0xff, 0xff, 0xfe, 0x00, 0x1e, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xfe, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0xff, 0xff, 0x01, 0xfc, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0x0f, 0xff, 0xff, 0x03, 0xfe, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x03, 0xfe, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x03, 0xfe, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x03, 0xff, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x07, 0xff, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x0f, 0xff, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x0f, 0xff, 0x80
	};

	// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)
	const int epd_bitmap_allArray_LEN = 1;
	const unsigned char* epd_bitmap_allArray[1] = {
		epd_bitmap_le_monke
	};


	void setupDisplay() {
        // Set pins
        Wire.setSCL(PB10);
        Wire.setSDA(PB11);

        display_handler.begin(SSD1306_SWITCHCAPVCC, 0x3C);

        display_handler.clearDisplay();
        display_handler.drawBitmap(0, 0, epd_bitmap_Bitmap, 128, 64, WHITE);
        display_handler.display();

        delay(2000);

        display_handler.clearDisplay();
        display_handler.drawBitmap(0, 0, epd_bitmap_le_monke, 128, 64, WHITE);
        display_handler.display();

        delay(2000);

        display_handler.clearDisplay();
        display_handler.setTextSize(1);
        display_handler.setTextColor(SSD1306_WHITE);
        display_handler.setCursor(0, 0);
        display_handler.println("monkeOS");
        display_handler.display();

        delay(500);
	}

    void displayTuners(double counter, double tuner1, double tuner2) {
        display_handler.clearDisplay();
        display_handler.setCursor(0, 0);
        display_handler.println(counter);
        display_handler.print("kp");
        display_handler.print(": ");
        display_handler.println(tuner1);
        display_handler.print("secondary");
        display_handler.print(": ");
        display_handler.println(tuner2);
        display_handler.display();
    }

    void displayState() {
        display_handler.clearDisplay();
        display_handler.setCursor(0, 0);
        display_handler.println("chicken wire");
        display_handler.println(Tape::tapeLost);
        display_handler.display();
    }
}



