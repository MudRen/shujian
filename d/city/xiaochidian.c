// Room: /d/city/xiaochidian.c

inherit ROOM;

void create()
{
	set("short", "С�Ե�");
	set("long", @LONG
����һ��С�꣬���⵹��ͦ��¡�ģ���λ���������ģ�����Щ����վ�ŵ�
�����������Ҳ�����棬���������ӡ����ȡ���Ѽ���׾Ƹ�·�ɡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"beidajie1",
	]));

	set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
	]));

	set("coor/x",130);
  set("coor/y",20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

