// Room: /u/swl/songshan/shidao1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ��ͨ����Ժǰ������̨�����ϵ�ʯש�̵�ʮ�����룬��Ȼ����ɽ
�����޹��ġ����Ը�������������ɰء�
LONG);
	set("exits", ([ 
            "north" : __DIR__"yaocan-ting",
            "south" : __DIR__"chanyuan",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",290);
   set("coor/z",110);
   setup();
}
