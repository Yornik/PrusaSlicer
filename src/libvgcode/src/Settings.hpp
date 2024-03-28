///|/ Copyright (c) Prusa Research 2023 Enrico Turri @enricoturri1966, Pavel Mikuš @Godrak
///|/
///|/ libvgcode is released under the terms of the AGPLv3 or higher
///|/
#ifndef VGCODE_SETTINGS_HPP
#define VGCODE_SETTINGS_HPP

#include "../include/Types.hpp"

#include <map>

namespace libvgcode {

struct Settings
{
		//
	  // Visualization parameters
		//
		EViewType view_type{ EViewType::FeatureType };
		ETimeMode time_mode{ ETimeMode::Normal };
		bool top_layer_only_view_range{ false };
		bool spiral_vase_mode{ false };
		//
		// Required update flags
		//
		bool update_view_full_range{ true };
		bool update_enabled_entities{ true };
		bool update_colors{ true };

		//
		// Visibility maps
		//
		std::map<EOptionType, bool> options_visibility{ {
				{ EOptionType::Travels,         false },
				{ EOptionType::Wipes,           false },
				{ EOptionType::Retractions,     false },
				{ EOptionType::Unretractions,   false },
				{ EOptionType::Seams,           false },
				{ EOptionType::ToolChanges,     false },
				{ EOptionType::ColorChanges,    false },
				{ EOptionType::PausePrints,     false },
				{ EOptionType::CustomGCodes,    false },
#if VGCODE_ENABLE_COG_AND_TOOL_MARKERS
				{ EOptionType::CenterOfGravity, false },
				{ EOptionType::ToolMarker,      true }
#endif // VGCODE_ENABLE_COG_AND_TOOL_MARKERS
		} };

		std::map<EGCodeExtrusionRole, bool> extrusion_roles_visibility{ {
				{ EGCodeExtrusionRole::None,                     true },
				{ EGCodeExtrusionRole::Perimeter,                true },
				{ EGCodeExtrusionRole::ExternalPerimeter,        true },
				{ EGCodeExtrusionRole::OverhangPerimeter,        true },
				{ EGCodeExtrusionRole::InternalInfill,           true },
				{ EGCodeExtrusionRole::SolidInfill,              true },
				{ EGCodeExtrusionRole::TopSolidInfill,           true },
				{ EGCodeExtrusionRole::Ironing,                  true },
				{ EGCodeExtrusionRole::BridgeInfill,             true },
				{ EGCodeExtrusionRole::GapFill,                  true },
				{ EGCodeExtrusionRole::Skirt,                    true },
				{ EGCodeExtrusionRole::SupportMaterial,          true },
				{ EGCodeExtrusionRole::SupportMaterialInterface, true },
				{ EGCodeExtrusionRole::WipeTower,                true },
				{ EGCodeExtrusionRole::Custom,                   true }
		} };
};

} // namespace libvgcode

#endif // VGCODE_SETTINGS_HPP