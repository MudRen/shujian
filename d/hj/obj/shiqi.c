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
        switch(random(7)) {
        case 0 : set_name("ţ����Ĺ����ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 1 : set_name("������Ż���ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 2 : set_name("���Ի���ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 3 : set_name("��ͷ��ս����ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 4 : set_name("���޻���ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 5 : set_name("����ɱ��ʿ����ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 6 : set_name("���仭��ʯ", ({ "xiang shi", "shi", "stone"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("weight", 1000);
		set("long", "���Ƕ���ʯ�����е�һ��������������ɽ��������һ����\n");
		set("material", "stone");
                set("unique", 4);
//                set("no_get",(:no_get:));
		set("no_drop",(:no_drop:));
        }
	setup();
}
