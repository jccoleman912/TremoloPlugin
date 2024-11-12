/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoloPluginAudioProcessorEditor::TremoloPluginAudioProcessorEditor (TremoloPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (700, 600);
    
    
    
    
    depthSlider.setBounds(100,100,100,100);
    depthSlider.setRange(0.f,100.f,0.1f); // (min, max, interval)
    depthSlider.setValue(0.f); // initial value
    depthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    depthSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    depthSlider.addListener(this);
    addAndMakeVisible(depthSlider);
    
    depthLabel.setText("Depth (%)", juce::dontSendNotification);
    depthLabel.attachToComponent(&depthSlider, false);
    depthLabel.setJustificationType(juce::Justification::centredTop);
    depthLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(depthLabel);
    
    
    rateSlider.setBounds(500,100,100,100);
    rateSlider.setRange(0.f,30.f,0.1f); // (min, max, interval)
    rateSlider.setValue(0.f); // initial value
    rateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    rateSlider.addListener(this);
    addAndMakeVisible(rateSlider);
    
    rateLabel.setText("Rate (Hz)", juce::dontSendNotification);
    rateLabel.attachToComponent(&rateSlider, false);
    rateLabel.setJustificationType(juce::Justification::centredTop);
    rateLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(rateLabel);
    
    
    
    tempoSlider.setBounds(50,400,200,60);
    tempoSlider.setRange(40.f,240.f,0.1f); // (min, max, interval)
    tempoSlider.setValue(120.f); // initial value
    tempoSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    tempoSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    tempoSlider.addListener(this);
    addAndMakeVisible(tempoSlider);
    
    tempoLabel.setText("Tempo (BPM)", juce::dontSendNotification);
    tempoLabel.attachToComponent(&tempoSlider, false);
    tempoLabel.setJustificationType(juce::Justification::centredTop);
    tempoLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(tempoLabel);
    
    
    
    
    
}

TremoloPluginAudioProcessorEditor::~TremoloPluginAudioProcessorEditor()
{
}

//==============================================================================
void TremoloPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::slategrey);

}

void TremoloPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}



void TremoloPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider) {
    
    
}


void TremoloPluginAudioProcessorEditor::buttonClicked (juce::Button *button) {
    
    
}

void TremoloPluginAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBox) {
    
}
