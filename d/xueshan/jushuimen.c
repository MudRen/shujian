// Room: jushuimen.c

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
��������ެ���ʳǵı��ţ���ެ�Ǳ���С�������������Ӿ����Ƿ�����ǽ��
���ü�ʵ������������ԭ��������Ҳ����ѷɫ�����˳��ž����������ˡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"tianyunmc",
		"south" : __DIR__"jiedao3",
	]));
        set("outdoors", "ѩɽ");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 2,]));
	set("coor/x",-220);
  set("coor/y",140);
   set("coor/z",0);
   setup();
}
