// Room: /d/city/nandajie2.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ��Ǽ���԰�֣�����ͨ��
�����ģ�������һ�ҹ˿��ڶ�Ĳ�ݣ����̾�����ʿ��������̸��˵�ء�����
���ǹٸ�����������ξ֡�
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"yanju",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"chaguan",
		"north" : __DIR__"nandajie3",
	]));

	set("objects", ([
		CLASS_D("shaolin") + "/tuoboseng" : 1,
	]));
	set("incity",1);
	setup();
}

