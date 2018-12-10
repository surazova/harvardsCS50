// Helper functions for music
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{

    //int numerator = fraction[0] - '0';
    //int denominator = fraction[2] - '0';

    // changes the numerator to the number of eighths
    //return ((numerator * 8) / denominator);

    // return ((8/denominator) * numerator);
    // TODO: Find best solution for duration from top examples

    // Another way to calculate fractions
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    int duration = ((8/denominator)*numerator);
    return duration;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Switch operator is much faster for multi-way branching
    int octave = note[strlen(note) - 1];
    octave -= 48;  // ASCII value representing 0

    double freq = 0.0;

    switch(note[0])
    {
        // TODO: hertz or freq as variable?
        case 'C':
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D':
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E':
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F':
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G':
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default :
            return 0;
    }

    // Octave changes
    if(octave > 4)
    {
        for(int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if(octave < 4)
    {
        for(int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }

    // Accidentals (flats or sharps)
    if(note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if(note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    // Return frequency value as an int
    int ret = round(freq);
    return ret;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // if s is a rest, then return true (a rest is represented by a new line)
    // otherwise, return false
    if(s[0] == '\0')
    {
       return true;
    }
    return false;
}



