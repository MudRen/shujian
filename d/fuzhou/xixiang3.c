// Room: /d/fuzhou/xixiang3.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݳ�������Աߵ�һ��С��������·�ܿ��������������
��խ���˶��٣����߿���һЩС���ӡ�����������������һ���㡣��ʱ�м�
������Ĺ�������������ӵ��š���������м������Ӻ����֡�
LONG
	);

	set("exits", ([
                "west" : __DIR__"huadian",
                "north" : __DIR__"xijie2",
                "south" : __DIR__"xixiang4",
	]));

	set("outdoors", "����");
	setup();
}
