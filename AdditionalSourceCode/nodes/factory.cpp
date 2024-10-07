/** Autogenerated Main.cpp. */

// =================================| Include only the DSP files  |=================================

#include <AppConfig.h>
#include <hi_dsp_library/hi_dsp_library.h>
#include <hi_faust/hi_faust.h>
#include "includes.h"
// ===========================| Now we can add the rest of the codebase |===========================

#include <JuceHeader.h>

#if !JUCE_WINDOWS
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif

// =======================================| Project Factory |=======================================

namespace project
{

struct Factory: public scriptnode::dll::StaticLibraryHostFactory
{
	Factory()
	{
		TempoSyncer::initTempoData();
		// Node registrations ----------------------------------------------------------------------
		
		registerPolyNode<project::Multiply_12_34<1>, project::Multiply_12_34<NUM_POLYPHONIC_VOICES>>();
		registerPolyNode<project::script_fx1<1>, wrap::illegal_poly<project::script_fx1<1>>>();
		registerDataNode<project::_networkdata>();
	}
};
}

scriptnode::dll::FactoryBase* scriptnode::DspNetwork::createStaticFactory()
{
	return new project::Factory();
}

#if !JUCE_WINDOWS
#pragma clang diagnostic pop
#endif


