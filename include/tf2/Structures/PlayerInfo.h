//
// Created by emiel on 9/07/20.
//

#ifndef SPECTRALHOOK_PLAYERINFO_H
#define SPECTRALHOOK_PLAYERINFO_H

typedef struct player_info_s {
    char			name[32];
    int				userID;
    char			guid[33];
    unsigned long	friendsID;
    char			friendsName[32];
    bool			fakeplayer;
    bool			ishltv;
    unsigned long	customFiles[4];
    unsigned char	filesDownloaded;
} player_info_t;

#endif //SPECTRALHOOK_PLAYERINFO_H
