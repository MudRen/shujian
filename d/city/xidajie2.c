// Room: /d/city/xidajie2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣����������������������
�Ҽ������ַǳ����Ӷ��治ʱ�ش���Ц��ݺ�裬�������ˣ�������������һ
������������ϱ������������ݴ����£����߾������������ˡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
	        "east" : __DIR__"xidajie3",
	        "west" : __DIR__"xidajie1",
		"north" : __DIR__"hubian",
		"south" : __DIR__"damingsi",
	]));

	set("objects", ([
		__DIR__"npc/liumangtou": 1,
		__DIR__"npc/liumang": 1,
	]) );
	setup();
}
