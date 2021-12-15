#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Add the slider to the main window
    addAndMakeVisible(freqSlider);
    // Set the range of the slider
    freqSlider.setRange(50.0, 1000.0);
    
    // Set the size of the component
    setSize (600, 100);

    // Specify the number of input and output channels that we want to open
    setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // Update Sample Rate
    currentSampleRate = sampleRate;
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Define the amplitude of the output
    double amplitude = 0.1;
    // Get the output buffers
    float* leftBuffer = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
    float* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);
    
    /*
     Your code here
     
     Use a for loop to process each audio sample in the block. In the loop, you should:
        1. Calculate the value for each sample using function std::sin()
        2. Calculate the change of angle for each sample
        3. Update the current angle for each sample
        4. Update the output buffer for both channels
    */
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    freqSlider.setBounds(10, 10, 580, 20);
}
