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
        set_name(HIC"��ѩʱ����"NOR, ({ "kuaixueshiqing tie", "tie"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("unique", 1);
                set("weight", 300);
		set("long", "���ǽ�����֮��д֮����ֽ�᱾���ݶ����磬��һ�Ĵ硣\n");
		set("material", "paper");
//                set("no_get",(:no_get:));
		set("no_drop",(:no_drop:));
		}
	setup();
}
