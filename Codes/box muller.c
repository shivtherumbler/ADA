#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

const float two_pi = 2*M_PI;

void basic_box_muller(float *retval);
void polar_box_muller(float *retval);
int main (int nargs, char **args) {
	if (nargs < 2) {
		fprintf (stdout, "Usage: %s <num_samples>\n", args[0]);
		exit(0);
	}
	int n = atoi(args[1]);
	FILE *basic_file = fopen ("basic_data.txt", "w");
	FILE *polar_file = fopen ("polar_data.txt", "w");
	int i;
	float buf[2];
	for (i = 0; i < n/2; ++i) {
		basic_box_muller (buf);
		fprintf (basic_file, "%f\n%f\n", buf[0], buf[1]);
		polar_box_muller (buf);
		fprintf (polar_file, "%f\n%f\n", buf[0], buf[1]);
	}
	fclose (basic_file); fclose (polar_file);
}

void basic_box_muller (float *retval) {
	float u1 = (float) rand() / RAND_MAX;
	float u2 = (float) rand() / RAND_MAX;
	float factor = sqrt ( -2 * log (u1) );
	float trig_arg = two_pi * u2;
	retval[0] = factor * cos (trig_arg);
	retval[1] = factor * sin (trig_arg);
}

void polar_box_muller (float *retval) {
	float u, v, s;
	do {
		u = ((float) rand() / RAND_MAX) * 2 - 1;
		v = ((float) rand() / RAND_MAX) * 2 - 1;
		s = u*u + v*v;
	} while (s >= 1 || s == 0);
	float factor = sqrt ( -2 * log(s) / s );
	retval[0] = u * factor;
	retval[1] = v * factor;
}
