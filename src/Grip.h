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


#ifndef GRIP_H
#define GRIP_H

#include "SharedData.h"
#include "Body.h"

class Grip
{
public:
	Grip(SharedData *sharedDataNew, Body &bodyNew);

	void setGripParam(float pointCenter[3], float interspace, float angle);

	void calcPoints();

	void setPose(float gaitPhi);

	void setLegWorkspace();

	void resetWorkspace();

	Body *body;

	SharedData *sharedData;

	float pointCenter[3], point0[3], point1[3];
	float angle;
	float interspace;
};
#endif
