#ifndef COMMONENUM_H
#define COMMONENUM_H
#include <QObject>

class FreeCANEnum :public QObject
{
    Q_OBJECT
public:
    enum NUM_FORMART{
        BIN=2,
        DEC=10,
        HEX=16
    };
    Q_ENUMS(NUM_FORMART)
    enum SIGNAL_VALUE_TYPE{
        TYPE_BOOL=0,
        TYPE_INT,
        TYPE_UINT
    };
    Q_ENUMS(SIGNAL_VALUE_TYPE)
    enum SIGNAL_ORDER_TYPE{
        TYPE_INTEL=0,
        TYPE_MOTOROLA
    };
    Q_ENUMS(SIGNAL_ORDER_TYPE)
};



#endif // COMMONENUM_H
