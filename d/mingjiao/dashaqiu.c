// dashaqiu.c  ��ɳ��
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", YEL"��ɳ��"NOR);
	set("long", "����һ���ܴ��ɳ��ɳ�����м����˵Ĺ�ͷ��\n");
	set("exits", ([
	        "west" : __DIR__"shejing",
                "east" : __DIR__"htping",
        ]));
        set("outdoors", "���̹�����");
	set("coor/x",-330);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-330);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}
