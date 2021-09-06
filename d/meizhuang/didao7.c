// didao7.c
inherit ROOM;
#include <wanted.h>

void create()
{
        set("short", "÷ׯ�ܵ�");
        set("long", @LONG
����һ���谵��ʪ�ĵص����ص��ܳ������ߵ���������̫������
��ѣ��ص����Ե�ǽ���ϻ��źܶ಻֪�����Ժ���֮�ֵıڻ�������
�����൱�ѿ���������һ�����ţ��������Ѿ����������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"didao6",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

void init()
{
        add_action("do_kai", "kai");
        if (present("ling tuisi", environment(this_player())))
                delete("exits/north");
}
int do_kai(string arg)
{
        object ob;
        if (query("exits/north"))
                return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
                
        if (!arg || (arg != "men" && arg != "north"))
                return notify_fail("��Ҫ��ʲô��\n");
        if (!(ob = present("hongyu yaoshi", this_player())))
                return notify_fail("���ò�֪������������ת�˼���,������ôҲ�򲻿���\n");
        set("exits/north", __DIR__"jianyu");        
        message_vision("$N�Ѻ���Կ�ײ�����һ���׿ף�ת�˼�ת�������ƶ���\nֻ�����������죬һ��ʯ�Ż������ˡ�\n", this_player());
        message_vision("ֻ��������ડ�һ���������Ǻ���Կ�׶ϵ��ˡ�\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
        return ::valid_leave(me, dir);
}