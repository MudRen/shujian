// Lottery_paper.c �ҽ�ȯ

#include <ansi.h>
inherit ITEM;

string do_look();

void create()
{
        set_name(HIW"�ҽ�ȯ"NOR, ({"duijiang quan", "quan"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_give", 1);
                set("no_get", 1);
                set("no_drop", 1);
                set("material", "paper");
	}
	set("long", (: do_look :));
	setup();
}

string do_look()
{
	object me = this_player();
	string str = me->query("lottery/number");

	if ( ! str )
		return "����һ������ͨͨ�Ķҽ�ȯ��������Щ���֣������Ѿ�ģ�������ˡ�\n";
	else {
		me->set_temp("lottery_look", 1);
		return "һ����ͨ�Ķҽ�ȯ������Ŀ��λ������һ�����֣��������Ƕҽ��õĺ��룺\n"+
			CHINESE_D->font(str)+"\n";
	}
}
