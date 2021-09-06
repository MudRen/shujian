// ÓÃÓÚÂôÇ®µÄÎäÆ÷£¬¸Ä±äSJ½ğÈÚ×´¿ö£¬´ó²¿·ÖÔ­ÂëÀ´×ÔSnowman dazao ÏµÍ³ 
#include <ansi.h>
string s_good(int i)
{
	switch(i){
		case 10..20:	return "ÎŞ±È";	
		case 9:		return "ÎŞ±È";	
		case 8:		return "¼«Æä";	
		case 7:		return "¾ø¶Ô";	
		case 6:		return "¼«Îª";	
		case 5:		return "Ïàµ±";	
		case 4:		return "Ê®·Ö";	
		case 3:		return "·Ç³£";	
		case 2:		return "±È½Ï";	
		case 1:		return "»¹Ëã";	
		case -1:	return "²»ÔõÃ´";	
		case -2:	return "ºÜ²»";	
		case -3:	return "¼«²»";	
		default:	return "Ò»°ã";	
	}
}

string s_power(int i)
{
	if( i >= 300 )	return HIR"»ÙÌìÃğµØ"NOR;
	if( i >= 280 )	return HIR"¿ªÔª´´ÊÀ"NOR;	
	if( i >= 250 )	return HIR"ÌìÏÂÎŞË«"NOR;	
	if( i >= 220 )	return HIM"¾øÊÀº±¼û"NOR;	
	if( i >= 200 )	return HIY"¾ÙÊÀÎŞÆ¥"NOR;
	if( i >= 180 )	return HIG"¿ªÌìÅüµØ"NOR;
	if( i >= 160 )	return HIB"ÒĞÌìÍÀÁú"NOR;
	if( i >= 140 )	return HIC"Õ¶Ñı·üÄ§"NOR;
	if( i >= 120 )	return RED"ÎŞÓëÂ×±È"NOR;
	if( i >= 100 )	return MAG"¼«Æä¿ÉÅÂ"NOR;
	if( i >= 80 )	return YEL"ºÜ¸ß"NOR;
	if( i >= 60 )	return GRN"Ë®×¼ÒÔÉÏ"NOR;
	if( i >= 40 )	return BLU"²»´í"NOR;
	if( i >	20 )	return CYN"²»Ğ¡"NOR;
	if( i <= 0 )	return "¼«²î";
	if( i <= -20 )	return "µÍÁÓ";
	return "Ò»°ã";
}

inherit EQUIP;
#include <mudlib.h>
#define PRICE 50 //¶¨ÒåÎäÆ÷³öÊÛµÄ¼Û¸ñ±¶Êı

int weapon_setup(mapping mp);

void create()
{
	//set_name("³¤½£", ({ "chang jian","sword","jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		//set("value", 200);
		set("material", "steel");
		set("wield_msg", "$NÄÃ³ö$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N·ÅÏÂÊÖÖĞµÄ$n¡£\n");
		set("wield_maxneili", 100);
		set("wield_neili", 10);
		set("wield_str", 20);		
	}
	set("flag", 4);
	set("verbs", ({ "slash", "hack", "slice", "thrust" }) );
	set("weapon_prop/damage", 1);
	set("skill_type", "sword");
	set("weapon_mp",
([ /* sizeof() == 23 */
  "wield_msg" : "$N½«$nÎÕÔÚÊÖÖĞ¡£
",
  "b_id" : "chui",
  "wield_str" : 17,
  "weapon_prop/damage" : 11,
  "value" : 89100,
  "wield_neili" : 25,
  "basic_name" : "¶¤Í·",
  "rigidity" : 1,
  "wield_maxneili" : 500,
  "no_sell" : 1,
  "material" : "steel",
  "imbued" : 1,
  "id" : ({ /* sizeof() == 4 */
      "normal hammer",
      "normal",
      "chui",
      "hammer"
    }),
  "skill_type" : "hammer",
  "hammer_count" : 5,
  "flag" : 1,
  "unwield_msg" : "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£
",
  "name" : "¶¤Í·´¸[0;0m",
  "name_st" : ({ /* sizeof() == 1 */
      "ÄÚÁ¦ÒªÇó¼õ°ë"
    }),
  "weight" : 22559,
  "verbs" : ({ /* sizeof() == 3 */
      "bash",
      "crush",
      "slam"
    }),
  "unit" : "±ú",
  "long" : "",
])
);
	set_name(query("weapon_mp")["name"], query("weapon_mp")["id"]);
	/*if (INTERMUD_MUD_NAME != "SJ")
	set("value",(query("weapon_mp")["value"]* PRICE ) > 15000000 ? 15000000 : query("weapon_mp")["value"] * PRICE );
	else
	set("value",(query("weapon_mp")["value"]* 2 ) > 15000000 ? 15000000 : query("weapon_mp")["value"] * 2 );
	*/
	//ÎªÊ²Ã´Òª°ÑÒç³öµÄ×¢ÊÍ£¿
	set("value",(query("weapon_mp")["value"]* PRICE ) > 15000000 ? 15000000 : query("weapon_mp")["value"] * PRICE );

	//set("value",query("weapon_mp")["value"]* PRICE );
	//Éè¶¨valueµÄ×î´óÖµ£¬ÔÙ¶àÒªÒç³öÁË
	weapon_setup(query("weapon_mp"));
	setup();
}

int weapon_setup(mapping mp)
{
	string *vb;
	int i;
	mapping w_mp;
	string str = "";
	int p;
	int w;
	string st;
	
	
	if( !clonep(this_object()) )
		return 0;
	if( !mapp(mp) ) return 0;
	
	vb = keys(mp);
	
	for( i = 0; i < sizeof(vb); i++ )
		set(vb[i], mp[vb[i]]);
	
	set_name(mp["name"], mp["id"]);
	set_weight(mp["weight"]);
	set("actions", (: call_other, WEAPON_D, "query_action" :) );
	
	w_mp = query("weapon_mp");	
	
	
	if( stringp(w_mp["long2"]) )
		str = w_mp["long2"];
	str += "ÕâÊÇÒ»"+w_mp["unit"]+"ÓÉ" + s_good(w_mp["rigidity"]) + "¼áÓ²µÄ";

	switch(w_mp["material"]){
		case "xuantie":	str += BLU"ĞşÌú"NOR; break;
		case "supersteel": str += "ÍòÄêÉñÌú"; break;
		case "greatsteel": str += "Á÷»¨¸Ö"; break;
		case "softsteel": str += "ÈíÌú"; break;
		case "bamboo": str += "°ßÖñ"; break;
		case "wood": str += "Ì´Ä¾"; break;
		default: str +=	"¾«¸Ö";	break;
	}
	w = w_mp["weight"];
	str +=	"ÖÆ³É£¬ÖØ"+sprintf("%s", chinese_number(w/500)+"½ï"+chinese_number((w%500)/50)+"Á½"+chinese_number((w%50)/5)+"Ç®")+"µÄ"+w_mp["name"]+"¡£\n";

	//mm = w_mp;
	if( intp( w_mp["weapon_prop/damage"] ) )
		p = w_mp["weapon_prop/damage"];
	else if( intp(w_mp["weapon_prop"]["damage"]) )
		p = w_mp["weapon_prop"]["damage"];
	else p = 0;
	
	str += "¿´ÆğÀ´"	+ ( w_mp["flag"]==4?s_good(w_mp["sharpness"])+"·æÀû£¬":"" ) + "¾ßÓĞ"+ s_power(p) + "µÄÍşÁ¦£¡\n";
	str += "ÉÏÃæ¿ÌÁËÈı¸öÊı×Ö£º¡¾"
		+ chinese_number(w_mp["wield_str"]) + "£¬"
		+ chinese_number(w_mp["wield_maxneili"]) + "£¬"
		+ chinese_number(w_mp["wield_neili"]) +	"¡¿\n";

	if( w_mp["name_st"] ){
		if( stringp(w_mp["name_st"]) )
			str += "ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ "HIG +	w_mp["name_st"]	+ NOR" ¡¿\n\n";
		else if( sizeof(w_mp["name_st"]) > 0	){
			st = implode(w_mp["name_st"][0..<1], "¡¢");
			str += "ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ "HIG +	st + NOR" ¡¿\n\n";
		}
	}
	set("long",str);
	delete("imbued");
	//¼Û¸ñ¿ÉÒÔµ÷Õû¡­¡­
	
	return 1;
}

int move(mixed dest, int silently)
{
			
	return ::move(dest, silently);
}

int weapon_fix()
{	
	delete("weapon_mp/broken");
	delete("broken");	
}
