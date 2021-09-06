// yaocai.c
// by augx@sj	2/26/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ҩ��", ({ "yaocai" }));
	set_weight(1000+random(1000));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ҩ�ġ�\n");
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
			set_name(HIW"��ޱ"NOR, ({"bai wei"}));
			set("need_lvl",1);
			break;
		case "he ye":
			set_name(HIG"��Ҷ"NOR, ({"he ye"}));
			set("need_lvl",1);
			break;
		case "ju geng":
			set_name(HIW"�չ�"NOR, ({"ju geng"}));
			set("need_lvl",1);
			break;
		case "mu gua":
			set_name(YEL"ľ��"NOR, ({"mu gua"}));
			set("need_lvl",1);
			break;
		case "sang ye":
			set_name(HIG"ɣҶ"NOR, ({"sang ye"}));
			set("need_lvl",1);
			break;
		case "tian qi":
			set_name(HIC"����"NOR, ({"tian qi"}));
			set("need_lvl",1);
			break;
		case "zhu ye":
			set_name(HIG"����Ҷ"NOR, ({"zhu ye"}));
			set("need_lvl",1);
			break;
		case "xiong huang":
			set_name(YEL"�ۻ�"NOR, ({"xiong huang"}));
			set("need_lvl",1);
			break;

		case "bai zhi":
			set_name(HIW"����"NOR, ({"bai zhi"}));
			set("need_lvl",80);
			break;
		case "chai hu":
			set_name(HIW"���"NOR, ({"chai hu"}));
			set("need_lvl",80);
			break;
		case "fang feng":
			set_name(HIC"����"NOR, ({"fang feng"}));
			set("need_lvl",80);
			break;
		case "gou qi":
			set_name(HIR"���"NOR, ({"gou qi"}));
			set("need_lvl",80);
			break;

		case "chan tui":
			set_name(HIB"����"NOR, ({"chan tui"}));
			set("need_lvl",160);
			set("animal",1);
			break;
		case "chuan bei":
			set_name(HIC"����"NOR, ({"chuan bei"}));
			set("need_lvl",160);
			break;
		case "dang gui":
			set_name(CYN"����"NOR, ({"dang gui"}));
			set("need_lvl",160);
			break;
		case "fu ling":
			set_name(HIC"����"NOR, ({"fu ling"}));
			set("need_lvl",160);
			break;

		case "jinyin hua":
			set_name(HIW"������"NOR, ({"jinyin hua"}));
			set("need_lvl",240);
			break;
		case "huang qi":
			set_name(HIY"����"NOR, ({"huang qi"}));
			set("need_lvl",240);
			break;
		case "niu huang":
			set_name(HIY"ţ��"NOR, ({"niu huang"}));
			set("need_lvl",240);
			set("animal",1);
			break;
		case "tianhua fen":
			set_name(HIW"�컨��"NOR, ({"tianhua fen"}));
			set("need_lvl",240);
			break;

		case "bao tai":
			set_name(MAG"��̥"NOR, ({"bao tai"}));
			set("need_lvl",320);
			set("animal",1);
			break;
		case "hu gu":
			set_name(HIW"����"NOR, ({"hu gu"}));
			set("need_lvl",320);
			set("animal",1);
			break;
		case "huo xiang":
			set_name(HIC"޽��"NOR, ({"huo xiang"}));
			set("need_lvl",320);
			set("animal",1);
			break;
		case "he shouwu":
			set_name(GRN"������"NOR, ({"he shouwu"}));
			set("need_lvl",320);
			break;

		case "ren shen":
			set_name(HIG"�˲�"NOR, ({"ren shen"}));
			set("need_lvl",360);
			break;
		case "zang honghua":
			set_name(HIR"�غ컨"NOR, ({"zang honghua"}));
			set("need_lvl",360);
			break;

		case "sha dan":
			set_name(HIY"�赨"NOR, ({"sha dan"}));
			set("need_lvl",390);
			set("animal",1);
			break;
		case "xuelian zi":
			set_name(HIW"ѩ����"NOR, ({"xuelian zi"}));
			set("need_lvl",390);
			break;

		default:
			return 0;
	}

	set("oid",query("id"));
	set_name( query("name")+"����" , ({ replace_string(query("id")," ","")+" shengcai","shengcai" }));
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
