// Room: jiedao2.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
��ެ���ʳǵĽֵ�������ԭ�����ҪխСЩ��Ҳ������ࡣ��ʯ���̵�·��
���Ѿ���ѹ����������ĳ��ޡ�ѹ�����ʯ������¶�����������ֳ�������ĺ�
ɫ��������Ӳ���ġ�������ެ�������մ�����Ӿ���������������Ư��һ���
�㣬�����мҾƹݡ�������֯��������
LONG
	);

	set("exits", ([
		"north" : __DIR__"zanpugc",
		"south" : __DIR__"jiedao1",
		"east" : __DIR__"yixianglou",
		"west" : __DIR__"zuofang",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-220);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
