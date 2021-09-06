// Room: zdyuan.c
// Date: zqb

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"֤��Ժ"NOR);
	set("long", @LONG
�������ȣ�ǰ�����һƬ������Ժ�䡣Ժ�ŵ��Ҷ���д�š�֤��Ժ����
�����֣���������ɮ�����ճ���з𣬲��������ĵط���Ժ�������˴���
���Եü����ľ�������Χ�������в��ϴ���������󳪺�ľ���û���������
LONG
	);

	set("exits", ([
		"west" : __DIR__"chanfang-1",
                "east" : __DIR__"celang-2",
	]));
         set("objects",([
//          CLASS_D("shaolin") + "/hui-kong" : 1,
          CLASS_D("shaolin") + "/xuan-sheng" : 1,
           __DIR__"npc/xiao-ku" : 1
      ]));

//	set("objects",([
//		__DIR__"obj/muchui" : 1,
//	]));
        set("outdoors", "shaolin");

	set("coor/x",30);
  set("coor/y",240);
   set("coor/z",110);
   setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "������") && dir == "west" &&
               objectp(present("xuansheng dashi", environment(me))))
           return notify_fail("�����ȵ���֤��Ժ�˱��µ�������֮������Ǳ��µ��ӣ��������ڡ�\n");
                
        return ::valid_leave(me, dir);
}


