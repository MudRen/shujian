// Room: /d/nanyang/yidao2.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
�����������е�һ��ʯ��·���ֵ����Ǻܿ�������������������·��
���������ˣ��м�����װ�������ƺ����������ˡ�����һ������ɫ�ҴҴ�����
�߾����������ߵĲ����ȥ������Щ���Ŵ󳵵�����е������Ҳ�׷׹���
���򶫵Ĳ�������ߵĲ��ͨ����Ҽ���
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"south" : __DIR__"yidao1",
		"east" : __DIR__"xiaolu",
		"north" : __DIR__"nanyang",
	]));
	setup();
}
