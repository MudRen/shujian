#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������ի��");
        set("long", @LONG
���������µ�ի�á���������Ʈ������ζ��һЩ�����ڲ�ͣ��æ
µ�ţ������и�ʽ���زˡ��ؾƣ�����һ�Ƿ��źö��ժ��������ˣ�
һ����ˮͰ�����Աߣ�����װ������ˮ���㲻�ɵ�������ͣ�
����������Ķ��ӡ����������Ľ���������
LONG);
        set("no_fight",1);
         set("exits", ([
                "south"  : __DIR__"yz2",
                "north"  : __DIR__"gulou",
        ]));
        set("resource/water", 1);
set("objects",([
		__DIR__"obj/rice" : 1,
		__DIR__"obj/dawan" : 1,
		__DIR__"obj/qingcai" : 2,
	]));

	set("no_fight", 1);

        set("coor/x",-340);
  set("coor/y",-350);
   set("coor/z",30);
   setup();
}
