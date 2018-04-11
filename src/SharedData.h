/*

This file is part of STEMI hexapod library.

Copyright (C) 2017 STEMI d.o.o.
Authors: Luka Fucek, et al.
Contact: info@stemi.education
Web: https://www.stemi.education/

STEMI hexapod library is free software exclusively
for non-commercial activities.

In case of developing any comercial activities involving STEMI
hexapod library please contact stemi.education for providing custom
license at: info@stemi.education.

For non-commercial activities you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License,
or (at your option) any later version.

STEMI hexapod library is
distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with STEMI hexapod library.
If not, see http://www.gnu.org/licenses/.

For additional information please check http://www.stemi.education.

*/


#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class SharedData {
public:
	SharedData();

	int a = 12; //just for testing purposes

	//control parameters:
	struct MoveCtrl
	{
		float linearVelocity = 0;
		float direction = PI / 2;
		float angularVelocity = 0;
		double poseVector[6] = { 4, 0, 0, 0, 0, 0 }; //initial translation and rotation vector of roots pose
		uint8_t timer = 0;
	} moveCtrll;

	struct Ctrl
	{
		float joy1u[2] = { 0, 0 }; //r, fi
		float ax1u[2] = { 0, 0 };
		float joy2u[2] = { 0, 0 }; //r, fi
		float ax2u[2] = { 0, 0 };
		//float roboHightu = 4;
		int gaitID = 1;
		boolean buttons[2] = { 0, 0 }; // up, down, full rotation, part rotation (moving) 
		float trXYu[2] = { 0, 0 }; //robot tilt
		float stepHight = 2;

		bool linMode = 0; //state, if robot is in calibration mode
		bool running = 1; //state, if the robot is ready for control (power on-off)

		int nMove = 0; //how many times will current command execute (0 = home)
		int nMoveMax = 100; //max number nMove (watchdog timer)
		double tr[6] = { 4, 0, 0, 0, 0, 0 }; //initial translation and rotation vector
	} moveCtrl;

	struct Parameters
	{
		double a[3] = { 1.11,4.82,6.04 }; //dimensions of one leg
		double dim[3] = { 3, 5.4, 7.2 }; //coordinates of the robots hips
		double freq = 100; //frequency of the algorithm
		double ts = 1.0 / freq;
	} param;
};



#endif
