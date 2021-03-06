// MUCH THANKS TO IllidanS4 & kurta999 FOR YSF.inc, one of the best memory hacking plugins
// written in 2020 December, (c) Y_Less, IllidanS4, iReplay & ionchyAdv

#include <YSI_Coding\y_hooks>

//#include <YSF> // include this for SA:MP version
#include <ysfomp> //include this for OMP version

hook OnGameModeInit()
{
	AllowNickNameCharacter('+', true);
	AllowNickNameCharacter(' ', true);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
	new playerName[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playerName, sizeof playerName);

	for(new ichar; ichar <= strlen(playerName); ichar++)
	{
		if(playerName[ichar] == ' ' || playerName[ichar] == '+')
		{
			Kick(playerid); // kicked for having invalid nickname
			break;
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

forward stock SendDeathMessageToPlayerEx(playerid, killer, assister, killee, weapon);
stock SendDeathMessageToPlayerEx(playerid, killer, assister, killee, weapon)
{
	new returnKillerName[MAX_PLAYER_NAME], returnAssisterName[MAX_PLAYER_NAME],
		feedText[MAX_PLAYER_NAME];

	GetPlayerName(killer, returnKillerName, sizeof returnKillerName);
	GetPlayerName(assister, returnAssisterName, sizeof returnAssisterName);

	format(feedText, sizeof feedText, "%s + %s", returnKillerName, returnAssisterName);
	SetPlayerName(killer, feedText);

	SendDeathMessageToPlayer(playerid, killer, killee, weapon);
	return SetPlayerName(killer, returnKillerName);
}

forward stock SendDeathMessageEx(killer, killee, assister, weapon);
stock SendDeathMessageEx(killer, killee, assister, weapon)
{
	new returnKillerName[MAX_PLAYER_NAME], returnAssisterName[MAX_PLAYER_NAME],
		feedText[MAX_PLAYER_NAME];

	GetPlayerName(killer, returnKillerName, sizeof returnKillerName);
	GetPlayerName(assister, returnAssisterName, sizeof returnAssisterName);

	format(feedText, sizeof feedText, "%s + %s", returnKillerName, returnAssisterName);
	SetPlayerName(killer, feedText);

	SendDeathMessage(killer, killee, weapon);
	return SetPlayerName(killer, returnKillerName);
}

/*
	SendDeathMessageToPlayerEx(playerid, killer, assister, killee, weapon)
	SendDeathMessageEx(killer, killee, assister, weapon)
*/
