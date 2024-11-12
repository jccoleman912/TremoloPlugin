/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TremoloPluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener,
public juce::Button::Listener,
public juce::ComboBox::Listener
{
public:
    TremoloPluginAudioProcessorEditor (TremoloPluginAudioProcessor&);
    ~TremoloPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider *slider) override;
    void buttonClicked (juce::Button *button) override;
    void comboBoxChanged (juce::ComboBox* comboBox) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TremoloPluginAudioProcessor& audioProcessor;
    
    /*
     Initializing the parameters that will be controlled with knobs/sliders.
     */
    juce::Slider depthSlider;
    juce::Slider rateSlider;
    juce::Slider tempoSlider;
    juce::Slider mixSlider;
    
    /*
     Initializing the parameters that will be controlled with buttons.
     */
    juce::ToggleButton bypassButton;
    juce::ToggleButton tripletButton;
    juce::ToggleButton dottedButton;
    juce::ToggleButton syncButton;
    juce::ToggleButton rateSelectorButton;
    juce::ToggleButton tempoSelectorButton;
    
    
    /*
     Initializing the parameters that will be controlled with a combo box.
     */
    juce::ComboBox noteSelector;
    
    /*
     Initializing the labels used to signify which knob affects which parameter.
     */
    juce::Label depthLabel;
    juce::Label rateLabel;
    juce::Label tempoLabel;
    juce::Label mixLabel;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoloPluginAudioProcessorEditor)
};
