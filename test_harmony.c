#include <assert.h>
#include "pad_harmony.h"

int main(void) {
    uint8_t notes[4];

    /* Do mayor: Do, Sol, Mi, Do. */
    assert(pad_notes(0, PAD_MAJOR, PAD_TRIAD, notes));
    assert(notes[0] == 48 && notes[1] == 55);
    assert(notes[2] == 64 && notes[3] == 72);

    /* Do menor: la tercera cambia de Mi a Mi bemol. */
    assert(pad_notes(0, PAD_MINOR, PAD_TRIAD, notes));
    assert(notes[2] == 63);

    /* Do sus2 y Do sus4. */
    assert(pad_notes(0, PAD_MAJOR, PAD_SUS2, notes));
    assert(notes[2] == 62);

    assert(pad_notes(0, PAD_MAJOR, PAD_SUS4, notes));
    assert(notes[2] == 65);

    /* Una tonalidad fuera del rango debe rechazarse. */
    assert(!pad_notes(12, PAD_MAJOR, PAD_TRIAD, notes));

    return 0;
}
