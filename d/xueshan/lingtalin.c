// Room: lingtalin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������������������������ߡ��ˣ�ʮ���㲻�ȣ�������������ΰ��ʵ��
�����Խ�Ƥ������������Ƕ�������á�
LONG
	);

	set("exits", ([
		"east" : __DIR__"fotang",
		"westup" : __DIR__"xuelu1",
		"enter" : __DIR__"baota1"
	]));
        set("outdoors", "ѩɽ");

	setup();
}
