// Room: shufang.c
// Created by Numa 1999-11-21

inherit ROOM;

void create()
{
	set("short", "�����鷿");
	set("long", @LONG
������������ƽʱ����ĵط�������������һ����Ⱦ��һ�Ź��ⰻ
Ȼ���鰸�ڷ��ڷ�������У����ϰ��ż��������˵���װ�鼮��
LONG);
	set("exits", ([ 
            "east" : __DIR__"yushu-lou",
        ]));
    set("indoors", "��ɽ");
	set("coor/x",10);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
