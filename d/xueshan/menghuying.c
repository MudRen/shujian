// Room: menghuying.c

inherit ROOM;

void create()
{
	set("short", "�ͻ�Ӫ");
	set("long", @LONG
����פ��������ެ���ʼҵ��ױ����ӣ�����ʳ�����ķ���Ӫ���м���һ
���ƽ���Ľ�������һ���������ݵĽ���������ߺ����ѵ��һС��ʿ����Ӫ����
�׵�ǽ��������΢΢���Ƶĸ�ʾ(gaoshi)��
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiedao1",
	]));

        set("item_desc",([
           "gaoshi" : 
		"
		 ���ڿ������㣬��������ͣ�������ѱ���������Ӧ����

                 ������䴦����ϸ������
                 �����Ϸ���ϸ����ٱ��������ͣ�֪�鲻����ͬ�\n",

           ]));
        set("outdoors", "ѩɽ");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 6,]));

	set("coor/x",-230);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}
