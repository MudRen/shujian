inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���϶����������ס������һ������������������ϸ������ǽ������һ��
���ң����顰����������ĸ���������Ĵ��֡�֪���������İ����������飬
ʦү�����ں�
LONG
	);
        
	set("exits", ([
		"east" : __DIR__"dongting",
		"west" : __DIR__"xiting",
		"north" : __DIR__"neizhai",
		"south" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/zhao" : 1,
		__DIR__"npc/shiye" : 1,
	]));
	set("incity",1);
	setup();
}
