#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "С·");
	set("long", @LONG
������ɽ·�ľ�ͷ��ǰ����һ���վ���ɽ�塣�ͱ��ϳ��������������ɽ��
�ϴ���һЩһ��������ľ׮���ƺ����Բ���ľ׮��(pa)��ȥ��
LONG	);
	set("exits", ([ 
                 "southdown" : __DIR__"hsxl2",
])); 
          set("outdoors", "�䵱");
	  set("coor/x",-20);
  set("coor/y",-100);
   set("coor/z",130);
   setup();
}

void init()
{
     add_action("do_pa","pa");
}

int do_pa(string arg)
{
//  mapping fam;
        object me;
        me=this_player();
        
    if ( (int)me->query_skill("dodge", 1) < 20)
            return notify_fail("����Ṧ�������޷�����ȥ��\n");

//    if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
//        return notify_fail("���䵱���Ӳ�����ɽ��\n");

    
    if (arg =="up")
    {
	if (me->is_busy()) return notify_fail("����æ���ء�\n");
        write("�����ľ׮��С�������������ȥ��\n");
        message("vision",me->name() + "����һ��ͻȻ�����ˡ�\n",
                environment(me), ({me}) );
      
        message("vision", me->name() + "����������\n",
        environment(me), ({me}) );
//        this_player()->delete_temp("marks/��ҩ");

        me->move(__DIR__"taoyuan1");
        return 1;
    }
    return notify_fail("��Ҫ���Ķ�����\n");
}
