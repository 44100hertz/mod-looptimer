/* calculate note and tuning adjustments *
 * for timing loops in tracker programs  *
 * ssaammp at gmail dot com 2014-11-20   */

#include <stdio.h>
#include <math.h>

#define C4SPEED 8363 /* ancient magic number used in .mod, .xm, others */

int main(int argc, char **argv)
{
	int bpm, length, midinote, beats;
	double freq, preciseNote, finetune;

	if (argc<3) {
		puts("Usage: notecalc [bpm] [length] (beats)\n"
		"  BPM is beats per minute\n"
		"  Length is in samples\n"
		"  Beats (optional, default 4)");
		return 1;
        }

	bpm = atoi(argv[1]);
	length = atoi(argv[2]);

	if (argc<4)
		beats=4; /* default 4 beats per measure */
	else
		beats=atoi(argv[3]);

        /* find the midi note number */
	preciseNote = 12 * log2(bpm * length / 60.0 / C4SPEED / beats);

	midinote = roundf(preciseNote);
	finetune = preciseNote - midinote;
	printf("Note:%d\nFinetune:%f\n", midinote, finetune * 128);

	return 0;
}
