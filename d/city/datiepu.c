// Room: /d/city/datiepu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬
��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤�ĺ�δ�깤�Ĳ˵�����������
����ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־���ڴ�������
����һ����(paizi)��
LONG
	);

	set("exits", ([
"east" : __DIR__"bqp",
		"north" : __DIR__"dongdajie1",
	]));

        set("objects", ([
__DIR__"npc/tiejiang1" : 1,
        ]));
        set("item_desc", ([ /* sizeof() == 1 */
		"paizi" : "������д������������ǽ�Ƕ��š�\n"]));
        set("no_clean_up", 0);

	set("coor/x",120);
  set("coor/y",-20);
   set("coor/z",0);
   setup();
}

