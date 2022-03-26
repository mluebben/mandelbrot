#include "region.h"
#include <QDataStream>
#include <QDebug>

QDataStream & regionDump(QDataStream& stream, const Region& region)
{
    stream << "(" << region.xMin() << ", " << region.yMin() << ")-(" << region.xMax() << ", " << region.yMax() << ")";
    return stream;
}

QDataStream & operator<< (QDataStream& stream, const Region& region)
{
    return regionDump(stream, region);
}


QDataStream & operator>> (QDataStream& stream, Region& region)
{
    return regionDump(stream, region);
}




QDebug operator<<(QDebug debug, const Region& region)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "(" << region.xMin() << ", " << region.yMin() << ")-(" << region.xMax() << ", " << region.yMax() << ")";

    return debug;
}
