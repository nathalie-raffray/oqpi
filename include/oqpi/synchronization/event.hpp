#pragma once

#include "oqpi/platform.hpp"

namespace oqpi {

    //----------------------------------------------------------------------------------------------
    enum class event_creation_options
    {
        create_if_nonexistent,
        open_existing,
        open_or_create,
    };

}

// Thread interface
#include "oqpi/synchronization/interface/interface_event.hpp"
// Platform specific implementations
#if OQPI_PLATFORM_WIN
#	include "oqpi/synchronization/win/win_event.hpp"
#else
#	error No event implementation defined for the current platform
#endif

namespace oqpi {

    //----------------------------------------------------------------------------------------------
    template<template<typename> typename _Layer = empty_layer>
    using auto_reset_event_interface    = itfc::event<event_impl<event_auto_reset_policy_impl>,     _Layer>;

    //----------------------------------------------------------------------------------------------
    template<template<typename> typename _Layer = empty_layer>
    using manual_reset_event_interface  = itfc::event<event_impl<event_manual_reset_policy_impl>,   _Layer>;


#ifdef OQPI_USE_DEFAULT
    //----------------------------------------------------------------------------------------------
    using auto_reset_event          = auto_reset_event_interface<itfc::local_event>;
    using manual_reset_event        = manual_reset_event_interface<itfc::local_event>;
    //----------------------------------------------------------------------------------------------
    using global_auto_reset_event   = auto_reset_event_interface<itfc::global_event>;
    using global_manual_reset_event = manual_reset_event_interface<itfc::global_event>;
#endif

}
