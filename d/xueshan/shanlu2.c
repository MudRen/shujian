// Room: shanlu2.c

inherit ROOM;

void create()
{
	set("short", "ǧ����");
	set("long", @LONG
����ɽ��ƽ����ʰ�׶��ϲ���������ǰ��ɽ���˵��һǧ���Ϳ�Խ�������ǣ�
    ǧ��ϳ���ɽ�ŵ������׸߳������á�
    ���ľ��ã���ʱ�������ࡣ
LONG
	);

	set("exits", ([
		"westup" : __DIR__"shanlu3",
		"southeast" : __DIR__"shanlu1",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-270);
  set("coor/y",150);
   set("coor/z",0);
   setup();
}
