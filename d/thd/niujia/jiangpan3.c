// Room: /u/jpei/thd/jiangpan3.c

inherit ROOM;
#include "nadir.c"

void create()
{
	set("short", "����");
	set("long", @LONG
һ���󽭺�ب����ǰ����ˮ�ƺƣ�����ҹҹ�������ݵر���󺣡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","ţ�Ҵ�");

	set("exits", ([
		"west": __DIR__"jiangpan2.c",
        "east": __THD__"haibin.c",
	]) );

	setup();
}

