// some song information
#include "Synth.h"
#define INCLUDE_NODES
#include "64k2Patch.h"
#include "64k2Song.h"

#include <stdio.h>

#define SAMPLE_RATE 44100
#define SAMPLE_TYPE float
SAMPLE_TYPE lpSoundBuffer[MAX_SAMPLES*2 + 44100*60]; // add safety buffer for 60s 

#define STR_(s) # s
#define STR(s) STR_(s)

int main(int argc, const char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s output.raw\n", argv[0]);
		return 1;
	}

	_64klang_Init(SynthStream, SynthNodes, SynthMonoConstantOffset, SynthStereoConstantOffset, SynthMaxOffset);
	fprintf(stderr, "Generating %d stereo samples of type " STR(SAMPLE_TYPE) " into file %s...\n", MAX_SAMPLES, argv[1]);
	_64klang_Render(lpSoundBuffer);

	FILE *f = fopen(argv[1], "w");
	fwrite(lpSoundBuffer, 2 * sizeof(SAMPLE_TYPE), MAX_SAMPLES * 2, f);
	fclose(f);

	return 0;
}
