// Room: /d/dali/ydxxxxx.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ķ��ˣ������������СС������ʯ���е�׳���絹�ҵı������ƽ�
�ǽӣ��������̣��е��㲦��·��ͱڣ�ͻأ��ɣ���崶��ˣ��е��������
��ʯ��ͦ�㣬����Ⱥ����
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"down" : __DIR__"ydxxxx",
		"east" : __DIR__"ydxxxxxx",
	]));

	setup();
}
