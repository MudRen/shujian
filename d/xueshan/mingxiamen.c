// Room: mingxiamen.c

inherit ROOM;

void create()
{
	set("short", "��ϼ��");
	set("long", @LONG
��������ެ���ʳǵ����ţ���ެ�Ǳ���С�������������Ӿ����Ƿ�����ǽ��
���ü�ʵ������������ԭ��������Ҳ����ѷɫ���˿̳��ŵ������£��ɳ��Ŷ���
������������������������ò��ɫ������ڸ����۾ӵ��������塣
LONG
	);

	set("exits", ([
        "north" : __DIR__"jiedao1",
        "east" : __DIR__"tulu3",
	]));
        set("outdoors", "ѩɽ");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 2,]));

	set("coor/x",-220);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}
