// Room: /u/zqb/tiezhang/shanmen.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ǽ������ŷ�ɥ���ġ����ư���Դӡ����Ƽߺ�ɽ��һ�۽���ɽ
�ɴ��һ�겻��֮�󣬰�������ˮ��Ư����ͷ���𽭺��������ǽ�ɽ�ıؾ�֮
·������С·ͨ��ɽ�·��һ������һ������(paizi)�����Ե������ڲ�ʱ
����һЩ�������ƺ������ڰ��м��ӡ�
LONG
	);

        set("outdoors", "tiezhang");
	set("exits", ([
"northup" : __DIR__"shanlu-1",
"southdown" : __DIR__"shanjiao",
"east": __DIR__"zhaigou3",
"west": __DIR__"zhaigou1",
]));
    set("objects", ([ 
__DIR__"npc/heiyi" : 2,
]));
	set("item_desc", ([ 
"paizi" : "��������--����",
]));

	set("no_clean_up", 0);

	set("coor/x",-330);
  set("coor/y",-290);
   set("coor/z",-10);
   setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

	if (dir == "northup" && is_wanted(me))
		return 0;
          if ((!myfam || myfam["family_name"] != "���ư�") && dir == "northup" && (int)me->query("combat_exp", 1) >= 10000 &&
                objectp(present("heiyi bangzhong", environment(me))))
        return notify_fail("���°��ڳ鵶��ס���ȥ·��˵�������㲻�����ư���ӣ�������ɽ��\n");

        return ::valid_leave(me, dir);
}
