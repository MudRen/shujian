// /d/xiangyang/outnroad3.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ڶ���ԥ�������·�ϣ�ż��������������ҴҶ�����������������
�����ڣ�����������Ͼ��ڡ��ϱ�ͨ�������ǣ�����Զ�������Ϻӿ��ˡ�
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("objects", ([
		__DIR__"npc/heiyi-dadao" : 1,
	]) );
	set("exits", ([
		"northwest" : __DIR__"shanxiroad1",
		"northeast" : __DIR__"henanroad1",
		"south" : __DIR__"outnroad2",
		"west" : __DIR__"hanshui1",
	]));

	setup();
}
int valid_leave(object me, string dir)
 {
     mapping exits = query("exits");
     if (!load_object(exits[dir])->query("xyjob") 
     && me->query_temp("xyjob"))
             return notify_fail("������������ô��\n");
     return ::valid_leave(me, dir);
 }	
