// Obj: /d/tianshan/obj/bag.c
// By Linux
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"����"NOR, ({ "bu dai", "bag", "dai" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Ѱ���Ĳ������������ƺ�װ��ʲô������\n");
                set("value", 100);
		set("no_get","�����������̫���ˡ�\n");
                set("no_drop","�㲻�ܶ�������������\n");
		set("no_sell","�����˷��Ӱ���\n");
                set("treasure",1);
                set("location", 1);
        }
}

void init()
{
        add_action("do_open", ({"open", "dakai"}));
}

int do_open(string arg)
{
        object me = this_player(),ob,ob2 = this_object();

        if( (!arg) || !((arg == "bu dai") || (arg == "����") || (arg == "dai") || (arg == "��")))
		return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");

	if (ob2->query("opened"))
		return notify_fail("�����Ѿ��⿪�ˡ�\n");

	if (ob2->query_temp("owner") != me->query("id"))
		return notify_fail("������Ӳ�����ġ�\n");

	if (!me->query_temp("tonglao/pass3"))
		return notify_fail("��ֻ�����Լ��ֽű�׾����ô��Ҳ�ⲻ��������ӡ�\n");

        message_vision(YEL"$N�����򿪲����ڣ�����һ�˳�����\n\n"NOR, me);
	message_vision(CYN"Ůͯ˵���������˳���Ҳ���������û��ء�����������������й�����\n"+
			"��һ�����������Ĺ�������\n"NOR, me);
	ob2->set("opened",1);
        ob = new("/d/tianshan/npc/nvtong");
	ob->move(environment(me));
	call_out("do_destruct", 4, ob2);
	return 1;
}

void do_destruct(object ob2)
{
	if (!ob2) return;
	message_vision("һ��紵�����Ѳ��������ˡ�\n", ob2);
	destruct(ob2);
}
