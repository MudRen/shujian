// Room: /d/city/mingyufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ݳ����Ժ��е������ˣ���Ϊ�������������ߣ���������
�����ˡ��ο����ﲻ�������������ݵ�����֣�������һ����Ժ�ӡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"lichunyuan",
                "south" : __DIR__"xidajie3",
	]));

/*	set("objects", ([
                __DIR__"npc/yanxiao" : 1,
	]));*/

	set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("incity",1);
	setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("hooker") && dir == "south")
        return notify_fail("���Ѿ�������Ժ�����ˣ�����������Ͻ֡�\n");
        return ::valid_leave(me, dir);
}
