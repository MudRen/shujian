// Room: jiedao1.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
��ެ���ʳǵĽֵ�������ԭ�����ҪխСЩ��Ҳ������ࡣ��ʯ���̵�·��
���Ѿ���ѹ����������ĳ��ޡ�ѹ�����ʯ������¶�����������ֳ�������ĺ�
ɫ��������Ӳ���ġ�������ެ�������մ�����Ӿ����������������ǼҴ󳵵꣬
�в�����������������Ъ�š������Ǹ���Ӫ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"jiedao2",
		"south" : __DIR__"mingxiamen",
		"east" : __DIR__"dachedian",
		"west" : __DIR__"menghuying",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-220);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}
