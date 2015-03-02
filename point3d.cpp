#include "point3d.h"
#include <math>

Point3d::Point3d(){
	x = 0;
	y = 0;
	z = 0;
}	
Point3d::Point3d(float newx, float newy, float newz){
	x = newx;
	y = newy;
	z = newz;
}
Point3d::~Point3d(){
}

float Point3d::GetAbsis(){
	return x;
}
float Point3d::GetOrdinat(){
	return y;
}
float Point3d::GetZ(){
	return z;
}

void Point3d::SetAbsis(float newx){
	this->x = newx;
}
void Point3d::SetOrdinat(float newy){
	this->y = newy;
}
void Point3d::SetZ(float newz){
	this->z = newz;
}

int Point3d::IsOrigin(){
	if (x == 0 && y ==0 && z == 0){
		return 1;
	} else (return 0);
}

int Point3d::IsEqual(Point3d P){
	if (this->x == P.GetAbsis() && this->y == P.GetOrdinat() && this->z = P.getZ()){
		return 1;
	} else (return 0);
}

float Point3d::AntarPoint(Point3d P1, Point3d P2){
	float hasil = sqrt(pow((P2.GetAbsis() - P1.GetAbsis()),2) + pow((P2.GetOrdinat() - P1.GetOrdinat()),2) + pow((P2.GetZ() - P1.GetZ()),2));
	return hasil;
}
	