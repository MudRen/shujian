// Room: jiedao3.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
��ެ���ʳǵĽֵ�������ԭ�����ҪխСЩ��Ҳ������ࡣ��ʯ���̵�·��
���Ѿ���ѹ����������ĳ��ޡ�ѹ�����ʯ������¶�����������ֳ�������ĺ�
ɫ��������Ӳ���ġ�������ެ�������մ�����Ӿ����������������Ǹ������̡�
�����Ǳ���Ψһ�������ӻ���
LONG
	);

	set("exits", ([
		"north" : __DIR__"jushuimen",
		"south" : __DIR__"zanpugc",
		"east" : __DIR__"wangdali",
		"west" : __DIR__"laifu",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-220);
  set("coor/y",130);
   set("coor/z",0);
   setup();
}
