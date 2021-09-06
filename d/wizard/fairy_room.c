
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", "��������ʦ��С������Ϣ�ĵط��������԰�����ʦ����ܶ����顣\n");

        set("exits", ([
                "out": __DIR__"guest_room",
        ]));
        set("no_fight", 1);
        set("sleep_room", 1);
        set("no_sleep_room", 1);

        set("objects", ([
                "/d/wizard/npc/fairy.c" : 1,
        ]));

        set("coor/x",100);
        set("coor/y",30);
        set("coor/z",0);
        setup();
}

void init()
{
        add_action("action", ({
                "dazuo",
                "du",
                "exercise",
                "lian",
                "practice",
                "respirate",
                "study",
                "tuna"
        }));
}
int action()
{
        write("���޷���������������\n");
        return 1;
}
int valid_leave(object me, string dir)
{
        if(me->query("gift_changed") && me->query_temp("gift_change"))
        {
                if (!me->query_temp("confirm")) 
                {
                        me->set_temp("confirm", 1);
                        me->start_busy(2);
                        return notify_fail(HIR"��ȷ���Ѿ������Ե�������𣿳�ȥ�Ժ�Ͳ������ٵ��������ˣ�\n"NOR);
                }
                me->delete_temp("confirm");
                me->delete_temp("gift_change");
        }
        return ::valid_leave(me, dir);
}
