// Room: /d/taishan/.c

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�������������ķ嶥���������ʯ������һ�𣬾�˵�������Ĵ���⣬
��������ʯʱʯ��㲻�ᶯҡ����֮��ҡ����ֹ��
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));

	set("outdoors", "̩ɽ");
	setup();
}

