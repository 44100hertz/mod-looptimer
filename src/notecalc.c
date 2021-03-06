/* calculate note and tuning adjustments *
 * for timing loops in tracker programs  *
 * ssaammp at gmail dot com 2014-11-20   */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define C4SPEED 8363 /* ancient magic number used in .mod, .xm, others */

int main(int argc, char **argv)
{
	if (argc<3) {
		puts(
                        "Usage: notecalc [bpm] [length] (beats)\n"
                        "  BPM is beats per minute\n"
                        "  Length is in samples\n"
                        "  Beats (optional, default 4)"
                        );
		return 1;
        }

	int bpm = atoi(argv[1]);
	int length = atoi(argv[2]);
        double beats = 4.0;
	if (argc>3)
		beats = atof(argv[3]);

        /* Midi note is used */
	double preciseNote = 12 * log2(bpm * length / 60.0 / C4SPEED / beats);
	int midinote = roundf(preciseNote);
	int finetune = 128 * (preciseNote - midinote);
	printf("Note:%+d\nFinetune:%+d\n", midinote, finetune);

	return 0;
}
