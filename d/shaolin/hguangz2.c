//hguangz2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡���ɴ���ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ�������
ǰ�и���ʩչ�ڹ���������ӡ�ǡ�����ͨ���󱯵
LONG
	);
    set("outdoors", "����");
    set("no_fight", 1);
	set("exits", ([
		      "east" : __DIR__ "hguangz3",
                      "west" : __DIR__ "hguangz1",
                      "south" : __DIR__ "dabeidia",
        ]));
        set("objects",([
		CLASS_D("shaolin") + "/dao-jue" : 1,
	]));
	set("coor/x",50);
  set("coor/y",330);
   set("coor/z",120);
   set("no_quit", 1);
   setup();
}

void init()
{
        add_action("do_quit", "quit");
}
int do_quit()
{
        write("���ﲻ׼�˳���\n");
        return 1;
}