// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/changjie1.c

inherit ROOM;
#include <room.h>

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�������Ľ֣�һ��������ͷ����֪��ͨ�����
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"changjie1",
                "west"   : __DIR__"changjie1",
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        me->add_temp("ca_chj",1);
  
        if( dir =="east") {
        if( me->query_temp("ca_chj") > 5 + random(5) ) {
                me->move(__DIR__"changjie2");
                me->delete_temp("ca_chj");
                return notify_fail("���۵ð����������������ⳤ���Ľ֡�\n");
                }
        }
        if( dir =="west") {
        if( me->query_temp("ca_chj") > 5 + random(5) ) {
                me->move(__DIR__"southjie3");
                me->delete_temp("ca_chj");
                return notify_fail("���۵ð����������������ⳤ���Ľ֡�\n");
                }
        }
        return ::valid_leave(me,dir);
}
