// /d/city/wroad3.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�ϣ�ż������ƥ��������ó��������Ϊ�ؽ����գ���
�Կ��ܻ���ɽ����û�������ͽ��밲�վ����ˡ�����ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"wroad2",
       		"west" : "/d/xiangyang/outeroad1",
//                "north" : "/data/group/zongtan",
                "north" : "/d/mingjiao/hdg/shanbi",
	]));
        
        set("objects", ([
                  "clone/npc/jianjie" : 1,
              ]));
	set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("incity",1);
	setup();
}
/*
int valid_leave(object me, string dir)
{
        if (!me->query("g_title") && dir == "north")
        return notify_fail("�����ǰ��ɵĵ��̣��㻹�Ǳ�ȥ�ˡ�\n");
        return ::valid_leave(me, dir);
}*/
