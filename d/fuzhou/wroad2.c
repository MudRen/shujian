// Room: /d/fuzhou/wroad2.c
// Lklv 2001.9.10

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�����������һ��С·��ʱֵ���գ�·�Ե�ɽ���ϵ��������˽��ɫ����
�˻���һ����ɽ�紵�����������������Ͳ˻�����ζ��������������븣��
����ɽ����·���и�С�ƹݣ��ƹ���ǰ�Ŀյ����м�ƥ���ڳԲݡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"shanpo",
		"west" : __DIR__"wjiuguan",
		"southwest" : __DIR__"wroad3",
		"southeast" : __DIR__"wroad",
	]));

	set("outdoors", "����");
	setup();
}
