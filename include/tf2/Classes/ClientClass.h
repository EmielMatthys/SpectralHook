//
// Created by emiel on 9/07/20.
//

#ifndef SPECTRALHOOK_CLIENTCLASS_H
#define SPECTRALHOOK_CLIENTCLASS_H

#include "RecvTable.h"

class ClientClass {
private:
    char _chPadding[8];
public:
    char* m_chName;
    RecvTable* m_recvTable;
    ClientClass* m_pNext;
    int m_iCLassID;
};

#endif //SPECTRALHOOK_CLIENTCLASS_H
