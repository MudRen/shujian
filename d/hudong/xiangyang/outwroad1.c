// /d/xiangyang/outwroad1.c ��ʯ���
// Lklv Modify 2001.9.22

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һ����ֱ����ʯ�����·�����������ǳ���æ����ʱ����������Ҵ�
������·������С·ͨ��һ��ɽ�𡣴Ӵ��������ƹ󴨵ķ��򣬶���ԶԶ�Ŀ�
������һ����¥����������������ˡ�
LONG
	);
	set("outdoors", "����");
	set("xyjob", "1"); 
	set("exits", ([
		"east" : __DIR__"baihumen",
		"west" : __DIR__"tanxi",
		"south" : __DIR__"shanlu1",
		"north" : "/d/gumu/jqg/shanlu3",
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
