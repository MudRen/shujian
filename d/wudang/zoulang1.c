// xilang.c ��������
// by shang 97/6

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ϣ�������һ��ҩ������������һ��������, ����������
����������䵱����, �ǳ�����, ��һ�䵱���ӿ����š�
LONG
        );

        set("exits", ([
                "west" : __DIR__"zoulang3",
                "east" : __DIR__"zoulang2",
                "north" : __DIR__"lgfang",
                "south" : __DIR__"sanqing",

        ]));

        set("objects", ([
                CLASS_D("wudang")+ "/xi" : 1
        ]));
 
        setup();
} 

int valid_leave(object me, string dir)
{
	object obj;
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "�䵱��")
         && dir != "south"
         && objectp( obj = present("zhang songxi", environment(me)))
         && living(obj))    
          return notify_fail(CYN"����Ϫ�ȵ����䵱�صأ����˲������ڡ�\n"NOR);
               
        return ::valid_leave(me, dir);
}
