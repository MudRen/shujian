// Room: /d/huashan/lianwu2.c
// Date: Look 99/03/25

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
���ǻ�ɽ�ɵ����䳡������ʯǽ�ϴ���һ�������ƺۼ�����ש�ѱ��ȳ�
һ������ӡ��
LONG
        );
        set("no_sleep_room","1");

	 set("objects",([
		__DIR__"npc/shidaizi" : 1,
	 ]));
        set("exits",([
		"south" : __DIR__"wuqiku",
		"west" : __DIR__"celang2",
	 ]));
	 set("outdoors", "��ɽ" );
        set("coor/x",100);
  set("coor/y",-10);
   set("coor/z",80);
   setup();
}
