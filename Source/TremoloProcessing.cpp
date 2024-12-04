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
    
    y = gain * x;
    
    return y;
    
}

void TremoloProcessing::setFrequency(float frequencyHZ) {
    rate = frequencyHZ;
}

void TremoloProcessing::setCurrentSample(int intCurrentSample) {
    currentSample = intCurrentSample;
}

void TremoloProcessing::setDepth(float intDepthPercentage) {
    depth = intDepthPercentage;
}

void TremoloProcessing::setGain(float inGain) {
    gain = inGain;
}
