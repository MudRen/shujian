// /u/cool/tls/zhaitang.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������ի��");
        set("long", @LONG
���������µ�ի�á���������Ʈ������ζ��һЩ�����ڲ�ͣ��æ�ţ�����
һ�Ƿ��źö��ժ��������ˣ��㲻�ɵ�������ͣ�����������Ķ��ӡ�����
�����Ľ���������
LONG
        );

        set("exits", ([
		"east"  : __DIR__"zt1",
	]));
        set("objects",([
		__DIR__"obj/rice" : 1,
		__DIR__"obj/dawan" : 1,
	]) );
set("no_fight",1);
        set("coor/x",-370);
  set("coor/y",-350);
   set("coor/z",20);
   setup();
}

