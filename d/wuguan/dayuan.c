//dayuan.c
inherit ROOM;

void create()
{
	set("short", "���ǰԺ");
	set("long", @LONG
��ǰ�������Ϳ��������Ժ���ˣ��������߶������䳡��������������ϰ
��ǿ������ܳ����Һ��ģ��㲻ʱ�����п��Ŷ����ģ�����ˮ�ĴҴҶ�����
��������̨�׾�����ݴ����ˡ�
LONG
	);

	set("exits", ([
		"south"   : __DIR__"qianting",
		"northup" : __DIR__"dating",
		"east"    : __DIR__"shilu4",
		"west"    : __DIR__"shilu3",
	]));

	set("outdoors","���");

	set("objects", ([
                __DIR__"npc/diyun" : 1,
//                 __DIR__"npc/newshizhe" : 1,

	]));
         
	setup();
	call_other("/clone/board/wuguan_b","???");
}

int valid_leave(object me, string dir)
{
	if (dir != "enter" && me->query_temp("wgmeet"))
                return notify_fail("���Ȼش��˷�̹���������뿪Ҳ���ٰ���\n");
	if (dir != "enter" && me->query_temp("wgquestion"))
                return notify_fail("���Ȼش��˷�̹���������뿪Ҳ���ٰ���\n");
	return ::valid_leave(me, dir);
}
