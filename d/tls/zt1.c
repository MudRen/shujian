#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������ի��");
        set("long", @LONG
���������µ�ի�á���������Ʈ������ζ��һЩ�����ڲ�ͣ��æ
µ�ţ������и�ʽ���زˡ��ؾƣ�����һ�Ƿ��źö��ժ��������ˣ�
�㲻�ɵ�������ͣ�����������Ķ��ӡ����������Ľ���������
LONG);
        set("no_fight",1);
        set("exits", ([
                "west"  : __DIR__"chufang",
                "south"  : __DIR__"yz1",
                "north"  : __DIR__"zhonglou",
        ]));
set("objects",([
		__DIR__"obj/rice" : 1,
		__DIR__"obj/dawan" : 1,
		__DIR__"obj/qingcai" : 2,
	]));

	set("no_fight", 1);

        set("coor/x",-360);
  set("coor/y",-350);
   set("coor/z",20);
   setup();
}
