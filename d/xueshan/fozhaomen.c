// Room: fozhaomen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ެ���ʳǵ����ţ���ެ�Ǳ���С�������������Ӿ����Ƿ�����ǽ��
���ü�ʵ������������ԭ��������Ҳ����ѷɫ�����˳�����ͨ���ѩɽ�ĵ�·��
LONG
	);

	set("exits", ([
		"east" : __DIR__"zanpugc",
		"west" : __DIR__"xiaolu3",
	]));
        set("outdoors", "ѩɽ");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 2,]));

	set("coor/x",-230);
  set("coor/y",120);
   set("coor/z",0);
   setup();
}
