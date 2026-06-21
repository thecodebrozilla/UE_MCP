# Copyright Epic Games, Inc. All Rights Reserved.

# [5.7 port] INFEASIBLE on UE 5.7 -- this plugin is DISABLED in the .uproject.
#
# This toolset is a thin Python wrapper over the MovieSceneAnimMixerScripting module
# (UMovieSceneAnimMixerTrackExtensions / *LayerExtensions / *TransitionExtensions /
# UMovieSceneDecorationContainerExtensions) and over the layer/transition/decoration
# UCLASSes (UMovieSceneAnimationMixerLayer, UMovieSceneAnimTransitionSectionBase,
# UMovieSceneDecorationContainerObject). All of those are new in UE 5.8.
#
# UE 5.7 ships a much earlier MovieSceneAnimMixer plugin that has ONLY the
# MovieSceneAnimMixer + MovieSceneAnimMixerEditor modules -- there is no
# MovieSceneAnimMixerScripting module, and the layer/transition/decoration classes do
# not exist in 5.7 source at all. Every tool in mixer.py both (a) calls a 5.8-only
# scripting method and (b) annotates its parameters/returns with 5.8-only reflected
# `unreal.*` types, so importing the toolset raises AttributeError on the missing
# `unreal.MovieSceneAnimationMixerLayer` etc. and aborts registration.
#
# Making this work on 5.7 requires an engine-level back-port of the entire
# MovieSceneAnimMixerScripting module plus several UCLASSes -- out of scope for a
# per-toolset port. Re-enable only once 5.7's MovieSceneAnimMixer gains the scripting
# API (or the engine module is back-ported). The "python-only" note in the original
# handoff was a mischaracterization: the toolset being content-only is not the problem;
# the missing 5.8 engine scripting surface is.
