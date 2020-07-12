//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_ILOGGER_H
#define SPECTRALHOOK_ILOGGER_H


class ILogger {
public:
    ILogger() = default;
    virtual void info(const char* format, ...) = 0;
    virtual void debug(const char* format, ...) = 0;
    virtual void err(const char* format, ...) = 0;
};


#endif //SPECTRALHOOK_ILOGGER_H
