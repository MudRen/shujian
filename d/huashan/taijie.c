// Room: /d/huashan/taijie.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "̨��");
        set("long", @LONG
������ɽʯ�����ʯ�ף���Ϊ�������˲��࣬���沽������̦���������
��ɽ�ɵ��������ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shanlu2",
		"southup" : __DIR__"qianting",
	]));

	set("objects",([
		__DIR__"npc/liangfa" : 1,
]));

        set("outdoors", "��ɽ" );

        set("coor/x",80);
  set("coor/y",0);
   set("coor/z",70);
   setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" && me->query("family/family_name") != "��ɽ��" && objectp(present("liang fa", environment(me))))
         return notify_fail("�����ȵ��������Ǳ��ɵ����ݵ����ϰ벽��\n");
        if (dir == "northwest" && me->query("family/family_name") != "��ɽ��" && objectp(present("liang fa", environment(me))))
         return notify_fail("�����ȵ��������Ǳ��ɵ����ݵ����ϰ벽��\n");
        return ::valid_leave(me, dir);
}
