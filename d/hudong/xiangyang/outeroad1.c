// /d/xiangyang/outeroad1.c

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���������������һ����ʯ��������������ǳ���æ����ʱ�����������
�Ҷ���������������밲�վ��ڡ�����ͨ�������Ƕ��棬�����š�
LONG
	);
	set("outdoors", "����");
        set("xyjob", 1);
	set("objects", ([
		__DIR__"npc/duxingxia" : 1,
	]) );
	set("exits", ([
		"east"  : "/d/city/wroad3",
		"west" : __DIR__"qinglongmen",
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
