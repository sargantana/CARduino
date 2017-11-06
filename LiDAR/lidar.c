int IRinput = "X-Axis coordinate of tracked point";
float n; //indicator for obtuse or acute aqngles
int pixel = 1023 - IRinput;
double pi = 3.14159265358979323846; // obviously pi
double px4deg = 25.6; // horizontal resolution of the pixart camera is 1024px, angle is 40° -> 25.6px/°
double deg2rad = pi/180; // conversion factor degrees to radians
double angle_laser = 69*deg2rad; //angle of laser relative to camera axis with scaling factor
double angle_camera; //this is what we measure/calculate 
double angle_point;  //we use this to calculate the distance with sin()
double distance; //this is what we actually want, the measured distance to the object
double distance_laser2camera = 50; //this is arbitrary, depends on desired range @50
if (pixel > 512) {n = 1;} else {n = -1;} //check for obtuse or acute triangle and set n as indicator
angle_camera = (90+n*(n*pixel-n*512)/px4deg)*deg2rad  //acute triangle substract pixel
angle_point = pi - (angle_camera+angle_laser);
distance = (distance_laser2camera*sin(angle_laser)/sin(angle_point);
Serial.Print(distance);