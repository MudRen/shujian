#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short","ʯͤ");
       set("long", @LONG
��������ص��µİ���ɫ��ʯͤ�����ǳ����޹�͸�룬һ�ж��Եİ���
ģ����һյ����������͵ƣ����������Ű���ɫ�ĵ��棬һ�����ޱ��飬
��������ʯ�ˣ�ľȻ��վ�����
LONG
     );
	set("exits", ([
                "north" : __DIR__"shiting5",
                "south" : __DIR__"shiting3",
                 ]));
       set("objects",([
                __DIR__"obj/kongchan" : 1,
                    ]));            
        setup();
}
      
