/*
	MicroView Arduino Image Generator Demo
	Copyright (C) 2015 NoelChan

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <MicroView.h>

const unsigned char logo [] = { 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x1F, 0x1F, 0xFF, 
0xFF, 0xFF, 0xFF, 0x3F, 0x03, 0x00, 0x00, 0xC0, 0xF0, 0x80, 0x00, 0x01, 0x0F, 0x7F, 0xFF, 0xFF, 
0x3F, 0x01, 0x00, 0x00, 0xE0, 0xFE, 0xFF, 0x7F, 0x1F, 0x0F, 0x0F, 0x87, 0xC7, 0xC7, 0xE7, 0xC7, 
0xC7, 0x07, 0x07, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x0F, 0x87, 0xC7, 0xC7, 0xE7, 
0xC7, 0xC7, 0x07, 0x0F, 0x0F, 0x3F, 0xFF, 0xFF, 0xFF, 0x7F, 0x03, 0x00, 0x00, 0xC0, 0xFE, 0xFF, 
0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFE, 0xF0, 0xC0, 0x00, 0x01, 0x07, 
0x00, 0x00, 0x80, 0xFC, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x08, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F, 
0x1F, 0x03, 0x00, 0x80, 0xE0, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x18, 0x39, 0x79, 0x79, 0x79, 
0x39, 0x19, 0x18, 0x18, 0xD8, 0xF8, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x80, 0xF8, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 
0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 
0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xFC, 
0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF 
};


void setup() {
	uView.begin();
	uView.clear(PAGE);
}

void loop() {
	unsigned char i,j;
	for (i=0; i<6; i++) {
		uView.setPageAddress(i);
		uView.setColumnAddress(0);
		for (j=0;j<64;j++) {
			uView.data(logo[i*64+j]);
		}
	}
}
