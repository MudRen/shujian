// /d/xiangyang/outsroad2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�����
������Ͻ�����Ͼ��ڡ�����ͨ�������ǡ�
LONG
	);
        set("outdoors", "����");
	set("xyjob", "1"); 
	set("exits", ([
		"south" : __DIR__"outsroad3",
		"north" : __DIR__"outsroad1",
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
