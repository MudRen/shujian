// yaocai.c
// by augx@sj	2/26/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("Ò©²Ä", ({ "yaocai" }));
	set_weight(1000+random(1000));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "·Ý");
		set("long", "ÕâÊÇÒ»ÖÖÒ©²Ä¡£\n");
		set("value", 200);
	}
	set("mode",1);
	setup();
}

int set_type(string type)
{
	if( query("mode")!=1 ) return -1;

	set("animal",0);
	set("shengcai",1);

	switch (type) {
		case "bai wei":
			set_name(HIW"°×Þ±"NOR, ({"bai wei"}));
			set("need_lvl",1);
			break;
		case "he ye":
			set_name(HIG"ºÉÒ¶"NOR, ({"he ye"}));
			set("need_lvl",1);
			break;
		case "ju geng":
			set_name(HIW"¾Õ¹£"NOR, ({"ju geng"}));
			set("need_lvl",1);
			break;
		case "mu gua":
			set_name(YEL"Ä¾¹Ï"NOR, ({"mu gua"}));
			set("need_lvl",1);
			break;
		case "sang ye":
			set_name(HIG"É£Ò¶"NOR, ({"sang ye"}));
			set("need_lvl",1);
			break;
		case "tian qi":
			set_name(HIC"ÌïÆß"NOR, ({"tian qi"}));
			set("need_lvl",1);
			break;
		case "zhu ye":
			set_name(HIG"ÄÛÖñÒ¶"NOR, ({"zhu ye"}));
			set("need_lvl",1);
			break;
		case "xiong huang":
			set_name(YEL"ÐÛ»Æ"NOR, ({"xiong huang"}));
			set("need_lvl",1);
			break;

		case "bai zhi":
			set_name(HIW"°×ÜÆ"NOR, ({"bai zhi"}));
			set("need_lvl",80);
			break;
		case "chai hu":
			set_name(HIW"²ñºú"NOR, ({"chai hu"}));
			set("need_lvl",80);
			break;
		case "fang feng":
			set_name(HIC"·À·ç"NOR, ({"fang feng"}));
			set("need_lvl",80);
			break;
		case "gou qi":
			set_name(HIR"èÛè½"NOR, ({"gou qi"}));
			set("need_lvl",80);
			break;

		case "chan tui":
			set_name(HIB"²õÍÉ"NOR, ({"chan tui"}));
			set("need_lvl",160);
			set("animal",1);
			break;
		case "chuan bei":
			set_name(HIC"´¨±´"NOR, ({"chuan bei"}));
			set("need_lvl",160);
			break;
		case "dang gui":
			set_name(CYN"µ±¹é"NOR, ({"dang gui"}));
			set("need_lvl",160);
			break;
		case "fu ling":
			set_name(HIC"ÜòÜß"NOR, ({"fu ling"}));
			set("need_lvl",160);
			break;

		case "jinyin hua":
			set_name(HIW"½ðÒø»¨"NOR, ({"jinyin hua"}));
			set("need_lvl",240);
			break;
		case "huang qi":
			set_name(HIY"»ÆÜÎ"NOR, ({"huang qi"}));
			set("need_lvl",240);
			break;
		case "niu huang":
			set_name(HIY"Å£»Æ"NOR, ({"niu huang"}));
			set("need_lvl",240);
			set("animal",1);
			break;
		case "tianhua fen":
			set_name(HIW"Ìì»¨·Û"NOR, ({"tianhua fen"}));
			set("need_lvl",240);
			break;

		case "bao tai":
			set_name(MAG"±ªÌ¥"NOR, ({"bao tai"}));
			set("need_lvl",320);
			set("animal",1);
			break;
		case "hu gu":
			set_name(HIW"»¢¹Ç"NOR, ({"hu gu"}));
			set("need_lvl",320);
			set("animal",1);
			break;
		case "huo xiang":
			set_name(HIC"Þ½Ïã"NOR, ({"huo xiang"}));
			set("need_lvl",320);
			set("animal",1);
			break;
		case "he shouwu":
			set_name(GRN"ºÎÊ×ÎÚ"NOR, ({"he shouwu"}));
			set("need_lvl",320);
			break;

		case "ren shen":
			set_name(HIG"ÈË²Î"NOR, ({"ren shen"}));
			set("need_lvl",360);
			break;
		case "zang honghua":
			set_name(HIR"²Øºì»¨"NOR, ({"zang honghua"}));
			set("need_lvl",360);
			break;

		case "sha dan":
			set_name(HIY"öèµ¨"NOR, ({"sha dan"}));
			set("need_lvl",390);
			set("animal",1);
			break;
		case "xuelian zi":
			set_name(HIW"Ñ©Á«×Ó"NOR, ({"xuelian zi"}));
			set("need_lvl",390);
			break;

		default:
			return 0;
	}

	set("oid",query("id"));
	set_name( query("name")+"Éú²Ä" , ({ replace_string(query("id")," ","")+" shengcai","shengcai" }));
	set("value", query("value") * (query("need_lvl")*8+100)/100 );

	return 1;
}

void set_level(int i)
{
	set("level",i);
}

int query_level()
{
	return query("level");
}

void change_state()
{
	string name = query("name");
	set("shengcai",0);
	set("yaocai",1);
	set("value",query("value") * 40/10);
	set_name( name[0..strlen(name)-5], ({ query("oid") }) );
}
