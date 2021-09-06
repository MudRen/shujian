// Write by Yanyang@SJ 2000.9.23
// jintan.c  ���̳

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(YEL"���̳"NOR, ({"da jiutan", "jiutan", "tan"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����̳��������������С���ﵹ��(daojiu)��\n");
                set("unit", "ֻ");
                set("value", 300);
                set("max_liquid",400);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": "�ϵȵ�Ů����",
                "remaining": 400,
                "drunk_apply": 200,
        ]));
}

void init()
{
	add_action("do_daojiu","daojiu");
	add_action("do_drink","drink");
}

int do_drink(string arg)
{
	object me=this_player();
	object ob=this_object();
        if(!objectp(present(ob, me)) ) return 0;
        if(ob->query("liquid/name")!="�ϵȵ�Ů����") return 0;
	if (arg=="da jiutan" || arg=="jiutan" || arg=="tan"){
		message_vision("$N�ƺ�������С�𱭲���񫣬��������"YEL"���̳"NOR"һ�󺣺ȣ�\n",me);
		me->add("water",-50);
		}
}        

int do_daojiu()
{
	object me=this_player();
	object ob=this_object();
	object obj=(present("xiao jinbei",me));
        if (ob->query("liquid/name")!="�ϵȵ�Ů����") return notify_fail("����̳Ҳ���Ǿư���\n");
	if (!obj) return notify_fail("������û��С�𱭣�׼����ʲô������ʢװ���ϵȵ�Ů���죿\n");
	if (obj->query("liquid/remaining")>0) return notify_fail("С�����Ѿ��������ˣ�\n");
	message_vision("$N��"YEL"���̳"NOR"��"HIY"С��"NOR"�������ϵȵ�Ů���죡\n",me);
        ob->add("liquid/remaining", -1);
        obj->add("liquid/remaining",1);
        return 1;
}


