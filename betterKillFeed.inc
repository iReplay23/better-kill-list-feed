// MUCH THANKS TO IllidanS4 & kurta999 FOR YSF.inc, one of the best memory hacking plugin
// written in 2020 December, (c) Y_Less, IllidanS4, iReplay & ionchyAdv

#include <YSI_Coding\y_hooks>

//#include <YSF> // include this for samp03  version
#include <ysfomp> //include this for omp version

hook OnPlayerConnect(playerid)
{
	AllowNickNameCharacter('+', true);
	AllowNickNameCharacter(' ', true);

	new playerName[MAX_PLAYER_NAME], ichar = -1;
	GetPlayerName(playerid, playerName, sizeof playerName);

	for(;playerName[ichar ++];)
	{
		if(playerName[ichar] == ' ' || playerName[ichar] == '+')
		{
			Kick(playerid); // kicked for having invalid nickname
			break;
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

forward stock SendAssistDeathMessageToPlayer(playerid, killer, assister, killee, weapon);
stock SendAssistDeathMessageToPlayer(playerid, killer, assister, killee, weapon)
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

forward stock SendAssistDeathMessage(killer, killee, assister, weapon);
stock SendAssistDeathMessage(killer, killee, assister, weapon)
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
	SendAssistDeathMessageToPlayer(playerid, killer, assister, killee, weapon)
	SendAssistDeathMessage(killer, killee, assister, weapon)
*/