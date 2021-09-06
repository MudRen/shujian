// Room: /d/shaolin/lhtang.c
// Date: by zqb

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"�޺���"NOR);
    set("long", @LONG
����ǰ��һ���ܴ��Ժ�䣬��Χ�ø�ǽΧס��Ժ���Ҷ���д�š��޺���
���������֡����������ֵ�����ϰ���Ż����书�����ڡ��кܶ������ɮ��
����������Ժ�ڴ����������������������
LONG
    );

    set("exits", ([
        "east" : __DIR__"stoneroad4",
        "west" : __DIR__"lwc",
    ]));

    set("outdoors", "shaolin");
    set("objects",([
        CLASS_D("shaolin") + "/xuan-ku" : 1,
        __DIR__"npc/xiao-ku" : 1
    ]));
      setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "������") && dir == "west" &&
            objectp(present("xuanku dashi", environment(me))))
	   return notify_fail("����ȵ����޺����˱��ɵ���ϰ��֮������Ǳ��ɵ��ӣ��������ڡ�\n");
		
        return ::valid_leave(me, dir);
}
