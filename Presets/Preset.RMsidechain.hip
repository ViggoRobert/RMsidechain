Processor 
Type SynthChain ID Preset.RMsidechain Bypassed Gain 	      �?Balance 	        VoiceLimit 	      P@KillFadeTime 	      4@IconColour 0 packageName  BuildVersion �  EditorStates BodyShown 0 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type ScriptProcessor ID Interface Bypassed Script iContent.makeFrontInterface(800, 300);


const var dp = Synth.getDisplayBufferSource("HardcodedMasterFX1");

const var rb = dp.getDisplayBuffer(0);

const var rb2 = dp.getDisplayBuffer(1);

const var BUFFER_LENGTH = 1024;

const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 1
};

rb.setRingBufferProperties(properties);

rb2.setRingBufferProperties(properties);

const var P1 = Content.addPanel("P1", 0, 0);


P1.setTimerCallback(function()
{
	this.data.buffer = rb.createPath(this.getLocalBounds(0), [0, BUFFER_LENGTH, 0, 1.0], 0.0);
	this.data.buffer2 = rb2.createPath(this.getLocalBounds(0), [0, BUFFER_LENGTH, 0, 1.0], 0.0);
	this.repaint();
});

P1.startTimer(30);

P1.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(Colours.withAlpha(Colours.white, 0.7));
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
	g.setColour(Colours.withAlpha(Colours.orange, 0.7));
	g.fillPath(this.data.buffer2, this.getLocalBounds(0));
});

function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content  Control type ScriptSlider id ScriptSlider1 value 	   ���'� Control type ScriptSlider id ScriptSlider2 value 	         Control type ScriptSlider id ScriptSlider3 value 	      @ Control type ScriptSlider id ScriptSlider4 value 	      @@ Control type ScriptSlider id ScriptSlider5 value 	      �? UIData  ContentProperties DeviceType 	Desktop Component type ScriptPanel id P1 x     y     width 	     ��@height 	     �r@opaque popupOnRightClick  Component 	type ScriptImage id ScriptImage1 x 	        y 	        width 	      �@height 	     �r@fileName #{PROJECT_FOLDER}uiscreenlayer.png alpha 	      �?popupOnRightClick  Component type ScriptImage id ScriptImage2 x 	        y 	        width 	      �@height 	     �r@fileName #{PROJECT_FOLDER}RMsidechainui.png popupOnRightClick  Component type ScriptSlider id ScriptSlider1 x 	     �@y 	      4@width 	      N@height 	      N@text Threshold numStrips 	      `@showTextBox showValuePopup Below middlePosition 	      (�processorId HardcodedMasterFX1 parameterId Threshold min 	      Y�max 	        defaultValue 	      (�scaleFactor 	   `���?filmstripImage 7{PROJECT_FOLDER}RMsidechainKnobs/Blue - filmstrip.png stepSize 	   ����? Component 
type ScriptLabel id ScriptLabel1 x 	     �@y 	      T@width 	      N@height 	      4@fontName Open Sans fontStyle Bold text Threshold editable  Component type ScriptSlider id ScriptSlider2 x 	     �@y 	     �[@width 	      N@height 	      N@text Attack numStrips 	      `@showTextBox showValuePopup Below middlePosition 	      $@processorId HardcodedMasterFX1 parameterId Attack max 	     @o@scaleFactor 	   `���?filmstripImage 8{PROJECT_FOLDER}RMsidechainKnobs/Green - filmstrip.png stepSize 	   ����? Component 
type ScriptLabel id ScriptLabel2 x 	     �@y 	     @e@width 	      N@height 	      4@fontName Open Sans fontStyle Bold text Attack editable  Component type ScriptSlider id ScriptSlider3 x 	     �@y 	      i@width 	      N@height 	      N@text 	Release numStrips 	      `@showTextBox showValuePopup Below middlePosition 	      $@processorId HardcodedMasterFX1 parameterId 	Release max 	     @o@defaultValue 	      @scaleFactor 	   `���?filmstripImage 6{PROJECT_FOLDER}RMsidechainKnobs/Red - filmstrip.png stepSize 	   ����? Component 
type ScriptLabel id ScriptLabel3 x 	     �@y 	     @p@width 	      N@height 	      4@fontName Open Sans fontStyle Bold text 	Release editable  Component type ScriptSlider id ScriptSlider4 x 	     ��@y 	      4@width 	      N@height 	      N@text Ratio numStrips 	      `@showTextBox showValuePopup Below middlePosition 	      0@processorId HardcodedMasterFX1 parameterId Ratio max 	      @@defaultValue 	      @@scaleFactor 	   `���?filmstripImage 9{PROJECT_FOLDER}RMsidechainKnobs/Yellow - filmstrip.png stepSize 0.1  Component 
type ScriptLabel id ScriptLabel4 x 	     ��@y 	      T@width 	      N@height 	      4@fontName Open Sans fontStyle Bold text Ratio editable  Component type ScriptSlider id ScriptSlider5 x 	     ��@y 	     �[@width 	      N@height 	      N@text Ring Mod SC numStrips 	      `@showTextBox showValuePopup Below middlePosition 	      �?processorId HardcodedMasterFX1 parameterId 	RingMod scaleFactor 	   `���?filmstripImage 5{PROJECT_FOLDER}RMsidechainKnobs/RM - filmstrip.png defaultValue 	      �? Component 
type ScriptLabel id ScriptLabel5 x 	     ��@y 	     @e@width 	      N@height 	      4@fontName Open Sans fontStyle Bold text Ring Mod SC editable  Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor 
Type Hardcoded Master FX ID HardcodedMasterFX1 Bypassed Network script_fx1 Threshold 	   ���'�Attack 	        Release 	      @Ratio 	      @@RingMod 	      �?_0 	        EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix 	NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ����Channel2    Send2 ����Channel3    Send3 ���� RoutingMatrix 	NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ����Channel2 ����Send2 ����Channel3 ����Send3 ���� macro_controls  macro name 	Macro 1 value 	        midi_cc ���� macro name 	Macro 2 value 	        midi_cc ���� macro name 	Macro 3 value 	        midi_cc ���� macro name 	Macro 4 value 	        midi_cc ���� macro name 	Macro 5 value 	        midi_cc ���� macro name 	Macro 6 value 	        midi_cc ���� macro name 	Macro 7 value 	        midi_cc ���� macro name 	Macro 8 value 	        midi_cc ���� MidiAutomation   MPEData Enabled  