#pragma once

/// <summary>
/// Performs a search based on color, splitting the image in three channels
/// H (hue), S (saturation) and V(value) and comparing them to the image
/// to be found using Euclidean distance.
/// </summary>
ref class ColorEngine
{
public:
	/// Class constructor.
	ColorEngine();

	/// Class destructor.
	virtual ~ColorEngine();
};

