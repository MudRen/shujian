// Room: shanlu1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ǰ��һ��ʯ�����Ѷ��ϣ��ڷ�����ʱ��ʱ�֣�ֱû��ɽ���ƶ�֮�С����ǣ�
    ��������һ���أ�·��ǧ������С�
    һ������ѩ��������ĺ����
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"shanlu2",
		"east" : __DIR__"tianhu",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-260);
  set("coor/y",140);
   set("coor/z",0);
   setup();
}
