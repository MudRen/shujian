// Room: sblu-2.c
// by bren

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
һ����ʯ�̳ɵ�С·�����������������������Ѷ�ȥ��ʯ·�Ͼ��ް��
����������������������ɨ��·���������Ǵ��̵�������΢��������ҡ
ҷ��ɳɳ���졣�����ƺ�����΢��ˮ����������Ķ��С�
LONG
	);

	set("exits", ([
                "west" : __DIR__"xiaolu5",
		"east" : __DIR__"xiaolu1",
                "south" : __DIR__"lxting",
                "north" : __DIR__"sblu-3",
		]));
         

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",370);
   set("coor/z",130);
   set("coor/x",50);
 set("coor/y",370);
   set("coor/z",130);
   setup();
}



