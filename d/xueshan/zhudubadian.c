// Room: zhudubadian.c

inherit ROOM;

void create()
{
	set("short", "�鶼�͵�");
	set("long", @LONG
���������䣬�������䡣��������Ъɽ�������Ҽ�����Ӳɽ�������ڹ���
ʮ������ľ�����������������ʽ�������о�ɷ��������������£��г��ŵ�ľ
����޺�ʨ���������ʰ�Բ����
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"xiekemen",
		"eastdown" : __DIR__"huilang8",
		"westdown" : __DIR__"huilang7",
		"south" : __DIR__"queridian",
	]));
        set("objects", ([__DIR__"npc/wenwoer" : 1,
	]));
	setup();
}
