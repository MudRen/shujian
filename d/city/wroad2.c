// /d/city/wroad2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�����
����������밲�վ��ڡ�����ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "����");
	set("objects", ([
		__DIR__"npc/caihuazei" : 1,
	]) );
	set("exits", ([
		"east" : __DIR__"wroad1",
                "west" : __DIR__"wroad3",
	]));
	setup();
}
