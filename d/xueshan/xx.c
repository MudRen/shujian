// Room: xuegu.c

inherit ROOM;

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
������Ⱥɽ�����е�һ��ɽ�ȣ��˼��������������Ͽ�������ɽ��������ƣ�
�����ű�ѩ����Χããѩԭ��������Ұ�޵��㼣����������
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"shanlu2",
	]));

	setup();

}
