// /d/xiangyang/ncx3.c �ϳ���
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
����һ��������С�����������������������һֱ�����ߣ�����ͨ��
�������ڽ֡�����������һ�Ҵ�լԺ�����ȴ��ų����š������Ա�վ��������
����·�����Ǹ���Ӫ��һЩ��������������
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"east"  : __DIR__"ncx4",
		"west"  : __DIR__"ncx2",
		"north"  : __DIR__"bingying",
		"south" : __DIR__"wen/damen",
	]));

	set("incity",1);
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
