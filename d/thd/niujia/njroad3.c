//Created by Redhat@Sjmud 2009/4/7

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·��·����һ���񷿣�����ܾ�û����ס�����ӡ��ϱ�����
С·ͨ�򽭱ߡ�
LONG
	);
	set("outdoors","ţ�Ҵ�");

	set("exits", ([
		"west": __DIR__"njroad2.c",
		"east": __DIR__"njeast.c",
		"north": __DIR__"qianyuan.c",
		"south": __DIR__"njroad4.c",
	]) );

	setup();
}

