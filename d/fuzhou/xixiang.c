// Room: /d/fuzhou/xixiang.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݳ�������Աߵ�һ��С��������·�ܿ��������������
��խ���˶��٣����߿���һЩС���ӡ�������һ���ӻ��̣�ר��һЩŮ�˼���
�Ķ���������������ȥ���
LONG
	);

	set("exits", ([
                "east" : __DIR__"zahuopu",
                "west" : __DIR__"minzhai",
                "south" : __DIR__"xixiang2",
	]));

	set("outdoors", "����");
	setup();
}
