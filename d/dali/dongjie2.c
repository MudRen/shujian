// Room: /dali/dongjie2.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ��ֵ��ϻ��ݺ���ľ�����дУ��������󣬷��м���һ˿
˿�ӱ���ҩ���ﴫ������ҩζ���ֵ�ƽ����ϴ��͸����ľ������Կ���������
һ���������������Ͼ���̫�Ͷ����ˡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"yaopu",
		"west" : __DIR__"doufufang",
		"north" : __DIR__"dongjie1",
		"south" : __DIR__"dongjie3",
	]));
	set("incity", 1);
	setup();
}
