// hsroad2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��ϱ���Լ�ɼ������ݳǵĳ�ǽ��������ͨ������
�����������һ����·ͨ��ƺ�����
LONG
	);
        set("outdoors", "̩ɽ");

	set("objects", ([
		NPC_D("dadao") : 1,
	]) );
	set("exits", ([
		"west" : "/d/huanghe/tiandi4",
		"east" : __DIR__"yidao2",
	]));
	setup();
}
