// Room: /d/fuzhou/xixiang2.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݳ�������Աߵ�һ��С��������·�ܿ��������������
��խ���˶��٣����߿���һЩС���ӡ�������������������ߺ����������ľ�
������Ҫ�ȳǶ���ԣ��·�����ŵ�Ů���Ƕ����Ļ�֦��չ��
LONG
	);

	set("exits", ([
                "west" : __DIR__"yaopu",
                "south" : __DIR__"xijie2",
                "north" : __DIR__"xixiang",
	]));

	set("outdoors", "����");
	setup();
}
