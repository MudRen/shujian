#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "С·");
	set("long", @LONG
������ɽ·�ľ�ͷ��ǰ����һ���վ���ɽ�塣�ͱ��ϳ��������������ɽ
���ϴ���һЩһ��������ľ׮���ƺ����Բ���ľ׮��(pa)��ȥ��
LONG	);
	set("exits", ([ 
                 "northdown" : __DIR__"hsxl2",
        ]));
	set("objects",([
                CLASS_D("wudang") + "/chenggao" : 1,
        ]));
        
        set("outdoors", "�䵱");
        setup();
}

void init()
{
        add_action("do_pa","pa");
}

int do_pa(string arg)
{
        object me;
        me=this_player();
        
        if ((int)me->query_skill("dodge", 1) < 20)
            return notify_fail("����Ṧ�������޷�����ȥ��\n");
        if (arg =="up"){
           write("�����ľ׮��С�������������ȥ��\n");
           message("vision",me->name() + "����һ��ͻȻ�����ˡ�\n",environment(me), ({me}) );
           message("vision", me->name() + "����������\n",environment(me), ({me}) );
           me->move(__DIR__"taoyuan1");
           return 1;
        }
       return notify_fail("��Ҫ���Ķ�����\n");
}
