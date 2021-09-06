// Room: /d/city/chmiao.c
// Modify by Lklv 2001.10.16

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ݳǱ��ĳ���������ƽ�����ϡ�٣���������ڡ�����ڻ�����
���ʱ�򣬲Ż���Щ������з���һ��������������������˻ҳ���ǽ��
���и���֩��������ֻ֩�����ĵض������档
LONG    );
        set("exits", ([
                "east" : __DIR__"beidajie1",
               "up" : __DIR__"qipaishi",
                "northwest" : "/d/wizard/guest_room",
        ]));
        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("objects", ([
                __DIR__"npc/ymonk" : 1,
                __DIR__"obj/box" : 1
        ]));
        setup();
        "/clone/board/wizto_b"->foo();
}

void init()
{
        object me = this_player();
        if (me->query("qiankun/qi") && me->query("qiankun/neili")) {
                 me->set("max_qi",me->query("qiankun/qi"));
                 me->set("max_neili",me->query("qiankun/neili"));
                 me->delete("qiankun/qi");
                 me->delete("qiankun/neili");
        }

        me->delete_temp("die_record");

        //�Խ�ɽׯϴ��״̬�ָ�
        if(me->query("no_pk_recover")){
            tell_object(me,BLINK + HIC"���뿪���Խ�ɽׯ��ϵͳ�Զ��ָ�������ϴ��״̬��\n"NOR);
            me->set("no_pk",me->query("no_pk_recover"));
            me->delete("no_pk_recover");
        }
        me->clear_condition("sjsz_time");
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
     mapping exits = query("exits");
     if (!load_object(exits[dir])->query("xyjob") 
     && me->query_temp("xyjob"))
             return notify_fail("����ս�½������㻹�Ǳ�ȥ�����ˣ���\n");
     return ::valid_leave(me, dir);
 }
