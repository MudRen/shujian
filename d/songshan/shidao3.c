// Room: shidao3.c
// Created by Numa 1999-11-21

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ��ͨ������̨���ϵ�ʯש�̵�ʮ�����룬��Ȼ����ɽ�����޹��ġ�
���Ը�������������ɰء�
LONG);
	set("exits", ([ 
            "southdown" : __DIR__"junji-dian",
            "northup" : __DIR__"peitian-fang",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",350);
   set("coor/z",130);
   setup();
}
