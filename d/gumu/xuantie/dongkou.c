// By River@sj 99.5.24
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
      set("short", YEL"����"NOR);
      set("long", @LONG
����һ����᫵�ɽ·��·���ϼ�����һЩ��ɳ�����߳���һЩҰ�ݣ�����
����Ұ��Ʈ�������㡣���³�����ϥ��һƬ�ž�������ɽʯ�ݴ�֮��������
�ã�����һ����ɽ��ǰ��
LONG
    );

     set("exits", ([
        "southeast" : __DIR__"xiaolu3",
        "enter" : __DIR__"shandong",
     ]));

     set("objects",([
           "/d/gumu/npc/diao" : 1,
     ]));

     set("outdoors", "����");

     setup();
}

int valid_leave(object me, string dir)
{
        if ( ! me->query("ygpass")
         && dir == "enter"
         && objectp(present("shen diao", environment(me))))
           return notify_fail("�����������ס���ȥ·���������ӵĿ����㡣\n");
           return ::valid_leave(me, dir);
}
