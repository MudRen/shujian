// /u/beyond/hz/baidi.c �׵�
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIW"�׵�"NOR);
        set("long", @LONG
�׵������������������ҳ��ơ���ůʱ�ڣ���˿���࣬������������
���ޣ�������Ŀ��һ·��ɣ��������Ʈ����������ɽ��ˮ����ɫ�ɲͣ���
������䣬���������������ԡ��������ƽ�����¡�������һ�����������
�����������������ң����ɽ����������Ƕ��š�
LONG
        );
set("objects",([
__DIR__"npc/you" : 2,
	"/d/meizhuang/npc/renwoxing": 1,
]));
    set("outdoors", "����");
        set("exits", ([
            "west" : __DIR__"pinghu",
            "north" : __DIR__"qsddao1",
            "northeast" : __DIR__"hubian",
            "southeast" : __DIR__"yuemiao",
            "southwest" : __DIR__"gushan",
            "northwest" : __DIR__"duanqiao",
]));
        set("coor/x",80);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}
