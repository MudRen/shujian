// Room: menlang.c ����

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ŵ����ȣ�����ƽ��ûʲô�ˣ����԰ڷ�������ྲ�ر��ƣ���
��֪���ճ������õ����̡������м����ӣ�����ż����������˵������������
ʲô�������졣
LONG
	);

	set("exits", ([
		"east" : __DIR__"banfang",
		"south" : __DIR__"yamen",
		"north" : __DIR__"ymzhengting",
		
	]));
	set("objects", ([
        	__DIR__"npc/yayi" : 2,
	]));

	set("incity",1);
	setup();
}