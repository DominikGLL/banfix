#if defined _banfix_included
	#endinput
#endif
#define _banfix_included

native B_Kick(playerid) = Kick;
native B_Ban(playerid) = Ban;
native B_BanEx(playerid,const reason[]) = BanEx;

forward kickplayer(playerid);
forward banplayer(playerid);
forward banexplayer(playerid,const reason[]);

stock FIX_Kick(playerid) return SetTimerEx("kickplayer",100,0,"d",playerid);

stock FIX_Ban(playerid) return SetTimerEx("banplayer",100,0,"d",playerid);

stock Fix_BanEx(playerid,const reason[]) return SetTimerEx("banexplayer",100,0,"ds",playerid,reason);

public kickplayer(playerid) return B_Kick(playerid);

public banplayer(playerid) return B_Ban(playerid);
	
public banexplayer(playerid,const reason[]) return B_BanEx(playerid,reason);
	
#if defined _ALS_Kick
	#undef Kick
#else
	#define _ALS_Kick
#endif
#define Kick FIX_Kick

#if defined _ALS_Ban
	#undef Ban
#else
	#define _ALS_Ban
#endif
#define Ban FIX_Ban

#if defined _ALS_BanEx
	#undef BanEx
#else
	#define _ALS_BanEx
#endif
#define BanEx FIX_BanEx
