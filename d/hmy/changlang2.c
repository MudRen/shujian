// /d/hmy/changlang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�������Ĺ������������Զ���ǽ��ÿ�������ɣ�ǽ�϶�����һ֧���λ�
�ľ���
LONG
	);
	set("exits", ([ 
          "east" : __DIR__"qqiudian",
          "south" : __DIR__"cddian",
          "west" : __DIR__"qlongtang",
	]));
	setup();
}
