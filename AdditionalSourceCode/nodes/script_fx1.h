#pragma once

#include "Multiply_12_34.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace script_fx1_impl
{
// ==============================| Node & Parameter type declarations |==============================

struct matrix_t_matrix: public routing::static_matrix<4, matrix_t_matrix, false>
{
	static constexpr int channels[4] =
	{
		2, 3, 0, 1
	};
};
using sidechain_signal_t = wrap::data<analyse::oscilloscope, 
                                      data::external::displaybuffer<1>>;
using stereo_cable = cable::block<2>;

using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, sidechain_signal_t>, 
                                  routing::send<stereo_cable>>;

using original3_t = container::chain<parameter::empty, 
                                     wrap::fix<2, core::empty>>;

using original4_t = container::chain<parameter::empty, 
                                     wrap::fix<2, routing::receive<stereo_cable>>>;

using multi5_t = container::multi<parameter::empty, 
                                  wrap::fix<2, original3_t>, 
                                  wrap::fix<2, original4_t>>;
using comp1_t = wrap::no_data<dynamics::comp>;

using sidechain2_t_ = container::chain<parameter::empty, 
                                       wrap::fix<4, multi5_t>, 
                                       comp1_t>;

using sidechain2_t = wrap::sidechain<sidechain2_t_>;

using original1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, sidechain2_t>>;
namespace custom
{

struct expr
{
	static float op(float input, float value)
	{
		return Math.abs(input) * (-1.0);;
	}
};
}

template <int NV>
using original2_t = container::chain<parameter::empty, 
                                     wrap::fix<2, routing::receive<stereo_cable>>, 
                                     math::expr<NV, custom::expr>>;

template <int NV>
using multi4_t = container::multi<parameter::empty, 
                                  wrap::fix<2, original1_t>, 
                                  wrap::fix<2, original2_t<NV>>>;
using oscilloscope2_t = wrap::data<analyse::oscilloscope, 
                                   data::external::displaybuffer<0>>;

struct matrix2_t_matrix: public routing::static_matrix<4, matrix2_t_matrix, false>
{
	static constexpr int channels[4] =
	{
		0, 1, -1, -1
	};
};

template <int NV>
using sidechain1_t_ = container::chain<parameter::empty, 
                                       wrap::fix<4, multi4_t<NV>>, 
                                       project::Multiply_12_34<NV>, 
                                       oscilloscope2_t, 
                                       routing::matrix<matrix2_t_matrix>>;

template <int NV>
using sidechain1_t = wrap::sidechain<sidechain1_t_<NV>>;

template <int NV>
using multi3_t = container::multi<parameter::empty, 
                                  wrap::fix<2, chain3_t>, 
                                  wrap::fix<2, sidechain1_t<NV>>>;

struct matrix1_t_matrix: public routing::static_matrix<4, matrix1_t_matrix, false>
{
	static constexpr int channels[4] =
	{
		2, 3, 0, 1
	};
};

namespace script_fx1_t_parameters
{
// Parameter list for script_fx1_impl::script_fx1_t ------------------------------------------------

using Threshold = parameter::plain<script_fx1_impl::comp1_t, 
                                   0>;
using Attack = parameter::plain<script_fx1_impl::comp1_t, 
                                1>;
using Release = parameter::plain<script_fx1_impl::comp1_t, 
                                 2>;
using Ratio = parameter::plain<script_fx1_impl::comp1_t, 
                               3>;
using RingMod = parameter::plain<routing::receive<stereo_cable>, 
                                 0>;
using _0 = parameter::empty;
using _0 = _0;
using script_fx1_t_plist = parameter::list<Threshold, 
                                           Attack, 
                                           Release, 
                                           Ratio, 
                                           RingMod, 
                                           _0, 
                                           _0>;
}

template <int NV>
using script_fx1_t_ = container::chain<script_fx1_t_parameters::script_fx1_t_plist, 
                                       wrap::fix<4, routing::matrix<matrix_t_matrix>>, 
                                       multi3_t<NV>, 
                                       routing::matrix<matrix1_t_matrix>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public script_fx1_impl::script_fx1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 2;
		
		SNEX_METADATA_ID(script_fx1);
		SNEX_METADATA_NUM_CHANNELS(4);
		SNEX_METADATA_ENCODED_PARAMETERS(112)
		{
			0x005B, 0x0000, 0x5400, 0x7268, 0x7365, 0x6F68, 0x646C, 0x0000, 
            0xC800, 0x00C2, 0x0000, 0xFF00, 0x3FFF, 0x3EC1, 0xAD83, 0xCD40, 
            0xCCCC, 0x5B3D, 0x0001, 0x0000, 0x7441, 0x6174, 0x6B63, 0x0000, 
            0x0000, 0x0000, 0x7A00, 0x0043, 0x0000, 0xA300, 0xDC81, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x0002, 0x0000, 0x6552, 0x656C, 0x7361, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x437A, 0x0000, 0x4080, 0x81A3, 0x3EDC, 
            0xCCCD, 0x3DCC, 0x035B, 0x0000, 0x5200, 0x7461, 0x6F69, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0042, 0x0000, 0x9D42, 0x97F6, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x0004, 0x0000, 0x6952, 0x676E, 0x6F4D, 0x0064, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x055B, 0x0000, 0x5F00, 0x0030, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x209B, 0x3E9A, 0x0000, 0x0000, 
            0x065B, 0x0000, 0x5F00, 0x0030, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& matrix = this->getT(0);                                                    // routing::matrix<matrix_t_matrix>
		auto& multi3 = this->getT(1);                                                    // script_fx1_impl::multi3_t<NV>
		auto& chain3 = this->getT(1).getT(0);                                            // script_fx1_impl::chain3_t
		auto& sidechain_signal = this->getT(1).getT(0).getT(0);                          // script_fx1_impl::sidechain_signal_t
		auto& send1 = this->getT(1).getT(0).getT(1);                                     // routing::send<stereo_cable>
		auto& sidechain1 = this->getT(1).getT(1);                                        // script_fx1_impl::sidechain1_t<NV>
		auto& multi4 = this->getT(1).getT(1).getT(0);                                    // script_fx1_impl::multi4_t<NV>
		auto& original1 = this->getT(1).getT(1).getT(0).getT(0);                         // script_fx1_impl::original1_t
		auto& sidechain2 = this->getT(1).getT(1).getT(0).getT(0).getT(0);                // script_fx1_impl::sidechain2_t
		auto& multi5 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);            // script_fx1_impl::multi5_t
		auto& original3 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0); // script_fx1_impl::original3_t
		auto& original4 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(0).getT(1); // script_fx1_impl::original4_t
		auto& receive2 = this->getT(1).getT(1).getT(0).getT(0).                          // routing::receive<stereo_cable>
                         getT(0).getT(0).getT(1).getT(0);
		auto& comp1 = this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1); // script_fx1_impl::comp1_t
		auto& original2 = this->getT(1).getT(1).getT(0).getT(1);             // script_fx1_impl::original2_t<NV>
		auto& receive1 = this->getT(1).getT(1).getT(0).getT(1).getT(0);      // routing::receive<stereo_cable>
		auto& expr = this->getT(1).getT(1).getT(0).getT(1).getT(1);          // math::expr<NV, custom::expr>
		auto& Multiply_12_34 = this->getT(1).getT(1).getT(1);                // project::Multiply_12_34<NV>
		auto& oscilloscope2 = this->getT(1).getT(1).getT(2);                 // script_fx1_impl::oscilloscope2_t
		auto& matrix2 = this->getT(1).getT(1).getT(3);                       // routing::matrix<matrix2_t_matrix>
		auto& matrix1 = this->getT(2);                                       // routing::matrix<matrix1_t_matrix>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, comp1); // Threshold -> comp1::Threshhold
		
		this->getParameterT(1).connectT(0, comp1); // Attack -> comp1::Attack
		
		this->getParameterT(2).connectT(0, comp1); // Release -> comp1::Release
		
		this->getParameterT(3).connectT(0, comp1); // Ratio -> comp1::Ratio
		
		this->getParameterT(4).connectT(0, receive1); // RingMod -> receive1::Feedback
		
		// Send Connections ------------------------------------------------------------------------
		
		send1.connect(receive1);
		send1.connect(receive2);
		
		// Default Values --------------------------------------------------------------------------
		
		receive2.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                           // comp1::Threshhold is automated
		;                           // comp1::Attack is automated
		;                           // comp1::Release is automated
		;                           // comp1::Ratio is automated
		comp1.setParameterT(4, 2.); // dynamics::comp::Sidechain
		
		; // receive1::Feedback is automated
		
		expr.setParameterT(0, 1.); // math::expr::Value
		
		Multiply_12_34.setParameterT(0, 0.5); // project::Multiply_12_34::MyParameter
		
		this->setParameterT(0, -11.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 4);
		this->setParameterT(3, 32.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(0).getT(0).setExternalData(b, index);                         // script_fx1_impl::sidechain_signal_t
		this->getT(1).getT(1).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index); // script_fx1_impl::comp1_t
		this->getT(1).getT(1).getT(2).setExternalData(b, index);                         // script_fx1_impl::oscilloscope2_t
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using script_fx1 = wrap::node<script_fx1_impl::instance<NV>>;
}


