#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ȫ԰��������ʱϵ԰����ʹ���������Ϊ���ŷ�������ȡ�ڡ�
ʫ��������ʽ���������ö����䡱���˴�����Ϊԧ������״���߳���������
�ڳ��踻�����¡�
LONG
);
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));
	set("exits", ([
	"west" : __DIR__"shizilin",
	"southeast" :__DIR__"zhenquting",
        ]));
 	set("outdoors", "suzhou");
	set("coor/x",130);
  set("coor/y",-240);
   set("coor/z",0);
   set("incity",1);
	setup();
}


