/*
  ==============================================================================

    TremoloProcessing.cpp
    Created: 16 May 2024 11:08:29am
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "TremoloProcessing.h"

#include <cmath>

float TremoloProcessing::processSample(float x, const int c){
    
    LFO = sin(2 * M_PI * 1.f * currentTimeInSeconds);
    
    y = x * LFO;
    
    return y;
    
}

void TremoloProcessing::setFrequency(float frequencyHZ) {
    rate = frequencyHZ;
}

void TremoloProcessing::setCurrentTime(juce::Optional<double> timeInSeconds) {
    if(timeInSeconds.hasValue()) {
        currentTimeInSeconds = *timeInSeconds;
    } else {
        currentTimeInSeconds = 0.0;
    }
}

void TremoloProcessing::setDepth(float intDepthPercentage) {
    depth = intDepthPercentage;
}

void TremoloProcessing::setGain(float inGain) {
    gain = inGain;
}
