// SPDX-License-Identifier: GPL-3.0-or-later
//
// Copyright 2022 Matthias Lübben <ml81@gmx.de>
//

#ifndef REGION_H
#define REGION_H

class Region {
public:
    Region(float xMin, float yMin, float xMax, float yMax)
        : _xMin(xMin), _yMin(yMin), _xMax(xMax), _yMax(yMax)
    {
        // Nothing to do
    }

    float xMin() const { return _xMin; }
    float yMin() const { return _yMin; }
    float xMax() const { return _xMax; }
    float yMax() const { return _yMax; }

    float xRange() const { return _xMax - _xMin; }
    float yRange() const { return _yMax - _yMin; }

    bool operator==(const Region& other)
    {
        return _xMax == other._xMax && _xMin == other._xMin && _yMax == other._yMax && _yMin == other._yMin;
    }

    bool operator!=(const Region& other)
    {
        return !this->operator==(other);
    }

    /*
    void operator=(const Region& other)
    {
        _xMax = other._xMax;
        _xMin = other._xMin;
        _yMax = other._yMax;
        _yMin = other._yMin;
    }
    */

    Region zoomed(float scale) const
    {
        // Determine width and heigt
        const float xRange = _xMax - _xMin;
        const float yRange = _yMax - _yMin;

        // Determine center point
        const float xCenter = xRange / 2 + _xMin;
        const float yCenter = yRange / 2 + _yMin;

        // Determine new edges
        const float xMin = xCenter - (xRange * scale) / 2;
        const float xMax = xCenter + (xRange * scale) / 2;
        const float yMin = yCenter - (yRange * scale) / 2;
        const float yMax = yCenter + (yRange * scale) / 2;

        return Region(xMin, yMin, xMax, yMax);
    }

    Region translated(float dx, float dy)
    {
        const float xMin = _xMin + dx;
        const float yMin = _yMin + dy;
        const float xMax = _xMax + dx;
        const float yMax = _yMax + dy;

        return Region(xMin, yMin, xMax, yMax);
    }

private:
    float _xMin;
    float _yMin;
    float _xMax;
    float _yMax;
};

class QDataStream;
QDataStream & operator<< (QDataStream& stream, const Region& image);
QDataStream & operator>> (QDataStream& stream, Region& image);

class QDebug;
QDebug operator<<(QDebug debug, const Region& region);

#endif // REGION_H
