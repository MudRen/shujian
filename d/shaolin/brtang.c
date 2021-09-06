// Room: /d/shaolin/brtang.c
// Date: by zqb

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"������"NOR);
    set("long", @LONG
����ǰ��һ���ܴ��Ժ�䣬��Χ�ø�ǽΧס��Ժ���Ҷ���д�š�������
���������֡����������ֵ��Ӿ������¸��Ҹ����书�����ڡ��кܶ������
ɮ�˽���������Ժ�ڴ����������������������
LONG
    );

    set("exits", ([
        "west" : __DIR__"stoneroad3",
        "east" : __DIR__"lwc16",
    ]));

    set("outdoors", "shaolin");
    set("objects",([
        CLASS_D("shaolin") + "/xuan-nan" : 1,
        __DIR__"npc/xiao-ku" : 1
    ]));
      set("coor/x",70);
  set("coor/y",270);
   set("coor/z",110);
   setup();
}

/*
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "������") && dir == "east" &&
               objectp(present("xuannan dashi", environment(me))))
	   return notify_fail("���Ѻȵ����������˱��ɵ���ϰ��֮������Ǳ��ɵ��ӣ��������ڡ�\n");
		
        return ::valid_leave(me, dir);
}
*/
