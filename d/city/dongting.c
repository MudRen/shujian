// /d/city/dongting.c
// this is made by beyond
// update 1997.7.4
inherit ROOM;     

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ŷ�������֪�����͵����ڡ����а���һ��ɼľԲ��ͼ�����ӣ�
������һ�׾��µ����˴�����ǽ�Ϲ���һ�����ã������ǰ��񳯷�ͼ��������
һ����֪���������ֱʡ�
LONG);
	set("no_fight", 1);
	
	set("exits", ([
		"west" : __DIR__"ymzhengting",
	]));

	set("objects", ([
        __DIR__"npc/zhang" : 1,
	]));

	set("incity",1);
	setup();
}

