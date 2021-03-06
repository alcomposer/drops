
#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

#define DISTRHO_PLUGIN_BRAND "Clearly Broken Software"
#define DISTRHO_PLUGIN_NAME "Drops"
#define DISTRHO_PLUGIN_URI "http://github.com/clearly-broken-software/drops"

#define DISTRHO_PLUGIN_IS_SYNTH 1
#define DISTRHO_PLUGIN_HAS_UI 1 
#define DISTRHO_PLUGIN_IS_RT_SAFE 1
#define DISTRHO_PLUGIN_NUM_INPUTS 0
#define DISTRHO_PLUGIN_NUM_OUTPUTS 2
#define DISTRHO_PLUGIN_WANT_TIMEPOS 0
#define DISTRHO_PLUGIN_WANT_STATE 1
#define DISTRHO_PLUGIN_WANT_FULL_STATE 1
#define DISTRHO_UI_USE_NANOVG 1 
#define DISTRHO_PLUGIN_WANT_MIDI_INPUT 1
#define DISTRHO_PLUGIN_WANT_DIRECT_ACCESS 0

#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:InstrumentPlugin"

/*    line comments are opcodes        */
/*    https://sfzformat.com/opcodes/   */
enum Parameters
{
   /*    common     */
   kPitchBendDepth, // bend_down, bend_up
   kPolyphony,      // polyphony
   kGain,           // volume

   /*    display     */
   kSampleIn,        // offset
   kSampleOut,       // end
   kSampleLoopStart, // loop_start
   kSampleLoopEnd,   // loop_end

   /*    sample tab    */
   kSampleXFade,          // loop_crossfade (not implemented)
   kSampleNormalize,      // amplitude or volume
   kSamplePitchKeyCenter, // pitch_keycenter
   kSampleTune,          // tune
   kSamplePlayMode,      // loopmode
   kSamplePlayDirection, // direction
   /*    amp tab */
   kAmpEGAttack,  // ampeg_attack
   kAmpEgDecay,   // ampeg_decay
   kAmpEgSustain, // ampeg_sustain
   kAmpEgRelease, // ampeg_release
   kAmpLFOType,   // lfoN_wave
   kAmpLFOFreq,   // lfoN_freq
   kAmpLFODepth,  // lfoN_amplitude
   kAmpLFOSync,   //

   /*  pitch tab */
   kPitchEGAttack,  // pitcheg_attack
   kPitchEgDecay,   // pitcheg_decay
   kPitchEgSustain, // pitcheg_sustain
   kPitchEgRelease, // pitcheg_release
   kPitchEgDepth,   // pitcheg_depth
   kPitchLFOType,   // lfoN_wave
   kPitchLFOFreq,   // lfoN_freq
   kPitchLFODepth,  // lfoN_pitch
   kPitchLFOSync,

   /*      filter tab  */
   kFilterType,      // fil_type
   kFilterCutOff,    // cutoff , cutoff_oncc200
   kFilterResonance, // resonance
   kFilterEGAttack,  // fileg_attack
   kFilterEgDecay,   // fileg_decay
   kFilterEgSustain, // fileg_sustain
   kFilterEgRelease, // fileg_release
   kFilterEgDepth,   // fileg_depth
   kFilterLFOType,   // lfoN_wave
   kFilterLFOFreq,   // lofN_freq
   kFilterLFODepth,  // lfoN_filter
   kFilterLFOSync,

   kParameterCount
};

#endif
