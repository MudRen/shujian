// Room: sblu-3.c
// by bren

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
һ����ʯ�̳ɵ�С·�����������������������Ѷ�ȥ��ʯ·�Ͼ��ް��
����������������������ɨ��·���������Ǵ��̵�������΢��������ҡ
ҷ��ɳɳ���졣�������ܽ�Ľ�̳��
LONG
	);

	set("exits", ([
		"south" : __DIR__"sblu-2",
                "northwest" : __DIR__"jietan1",
                "northeast" : __DIR__"jietan2",
		]));
         

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",380);
   set("coor/z",130);
   set("coor/x",50);
 set("coor/y",380);
   set("coor/z",130);
   setup();
}



