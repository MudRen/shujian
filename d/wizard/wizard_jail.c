// /d/wizard/wizard_jail.c
// bbb 99.1.25
// Modify By Look 991021
// Modify by Looklove 2000/8/26  because food& water

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","����");
       set("long", @LONG
�����Ǽ������ǹ�Ѻ���̷��ĵط������涼��ʯ�ڣ���Ҫ�����ӳ�ȥ��
�����ܵġ�����ʮ�ֳ�ʪ����������ʱ��һ�ñص��ز���ʯ�����õ��ӿ���
һЩ��ڵĻ���....����Ӧ���������񣬲���Υ����Ϸ���������ܴ˻�
������
LONG
     );
        set("no_fight",1);
	set("no_update", 1);
        set("valid_startroom", 1);
        set("no_get",1);
        set("objects", ([ __DIR__"npc/yuzu" : 1, ]));
        setup();
}

void init()
{
	object me = this_player();
        me->set("food",100);
        me->set("water",100);
	if (userp(me) && !wiz_level(me) && !me->query_condition("killer"))
		me->apply_condition("killer", 1);
        add_action("do_kill", "");
}

int do_kill(string arg)
{
        string action = query_verb();
        switch (action) {
        case "kill":
        case "hit":
        case "throw":
        case "fight":
        case "perform":
        case "dazuo":
        case "exercise":
        case "tuna":
        case "lian":
        case "practice":
        case "du":
        case "study":
        case "respirate":
        write("���Ѿ�������ط��ˣ�������Щ������ʲô��\n");
        return 1;
        }
return 0;
}
