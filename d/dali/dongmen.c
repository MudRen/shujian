// Room: //dali/dongmen.c
// bbb 1997/06/11 
// Modify By River 98/12
inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š�����������֣���ǽ�����ż��Ź�
����ʾ���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ��
��������������졣�����ǽ��⣬��Լ�ɼ�һƬһ���޼ʵ����֣�����Ī�⡣
�����ǳ��
LONG
	);
	set("outdoors", "����"),

	set("exits", ([
		"east" : __DIR__"dalieast/shanlu7",
		"west" : __DIR__"dongjie4",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}
