// Room: /dali/chahuayuan5.c
// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"�軨԰"NOR);
      	set("long", @LONG
������һ��Сɽ���ϣ����ﵽ������ʢ�����ʻ������е��ۻ������ˣ���
�������⻨԰�У������泩��ࡣ 
LONG
        );
        set("exits", ([ 
              "southwest" : __DIR__"chyuan3",
        ]));
        set("outdoors","����");

        set("objects", ([
              __DIR__"obj/chahua1" : 1,
              __DIR__"obj/chahua" : 1,
        ]) );
	setup();
}
