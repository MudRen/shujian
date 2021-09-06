#include <ansi.h>

inherit ITEM;

string no_get()
{
	object me = this_player();
	if(!me) return 0;
	if(me->query("combat_exp")<750000)
		return "�㽭���������㣬�µô˱���Ҳ���ô���\n";
	if(me->query("drop_hj_uniqe") && ( me->query("mud_time")-me->query("drop_hj_uniqe"))<172800)
		return "�㱩������߲�����ӭ�㡣\n";
	return 0;
}

int no_drop()
{
	object me = this_player();
	if(!me) return 0;
	me->set("drop_hj_uniqe",me->query("mud_time"));
	return 0;
}

void remove(string id)
{
	object me = environment();
	if(me && objectp(me) && userp(me))
		me->set("drop_hj_uniqe",me->query("mud_time"));
}

void create()
{
        switch(random(13)) {
        case 0 : set_name(GRN"����ͷ��"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 1 : set_name(HIY"����������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 2 : set_name(HIW"����������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 3 : set_name(MAG"����"NOR, ({"yu pei", "yu", "pei"})); break;
        case 4 : set_name(YEL"������������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 5 : set_name(WHT"���"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 6 : set_name(WHT"��������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 7 : set_name(YEL"��������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 8 : set_name(GRN"��������ʯ��"NOR, ({"yu pei", "yu", "pei"})); break;
        case 9 : set_name(HIY"��ʽ����"NOR, ({"yu pei", "yu", "pei"})); break;
        case 10 : set_name(CYN"��������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 11 : set_name(CYN"��"NOR, ({"yu pei", "yu", "pei"})); break;
        case 12 : set_name(MAG"���"NOR, ({"yu pei", "yu", "pei"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("weight", 1000);
		set("long", "���Ƕ�����ʯ��Ʒ�е�һ��������������ɽ��������һ����\n");
		set("material", "stone");
                set("unique", 4);
//                set("no_get",(:no_get:));
		set("no_drop",(:no_drop:));
        }
	setup();
}
