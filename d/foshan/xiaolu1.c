//xiaolu1.c 

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����ɽ��С·�������������ɽ���ˡ�����������������������
���洫������ľ������������о�������������
LONG
	);
	set("outdoors", "��ɽ");

	set("objects",([
		NPC_D("poorman") : 1,
	]));

	set("exits", ([
		"northup" : __DIR__"xiaolu2",
		"south" : __DIR__"lingnan",
		"northeast" : __DIR__"fenchang",
		"northwest" : __DIR__"zumiao",
	]));
	setup();
}
