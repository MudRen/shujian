// Room : /d/wudang/clbinyuan2.c ���ֱ�Ե
// By lius 99/8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","���ֱ�Ե");
        set("long", @LONG
�������߳��˴��֣�ǰ����һ�����ʵ�ɽ�壬һ��Ϫ����ɽ������������
�ͱڣ��㲻����������Ĵ��ֺ���ǰ��ɽϪ���񣬲�֪��β����ҵ���ɽ��·
����
LONG                           
        );
        set("exits", ([               
                 "south" : __DIR__"conglin"+(random(4)+13),
                 "north" : __DIR__"conglin"+(random(4)+13),
                 "northeast" : __DIR__"conglin"+(random(4)+13),
                 "northwest" : __DIR__"conglin"+(random(4)+13),
        ]));
        set("outdoors", "�䵱");
        setup();
}

void init()
{
         add_action("do_tiao", ({"tiao","jump"}));
}

int do_tiao(string arg)
{
        object me;
        me = this_player(); 
        if (!arg || arg != "river" ) return 0;
 
        message_vision(WHT"$N������ԥ����������Ϫ����\n"NOR, me);
        me->move(__DIR__"shuizhong");
        call_out("swim", 5, me);
        return 1;
}

int swim(object me)
{
        message_vision("$Nֻ�����Ի������죬ˮ��̹ǣ�æ�������࿹��\n", me);
        if ((int)me->query_skill("force",1) < 100 ){
          tell_object(me, BLU"�������������һ��ǿ��һ�󣬽������ֿܵ�����֫��ʼ��ľ��\n"NOR);
          me->unconcious();
          me->move("/d/xiangyang/hanshui2");
          tell_room(environment(me), "һ�����δ����������е�"+me->name()+"���ϰ�����\n", ({ me }));
          return 1;
        }
        else
         me->move("/d/xiangyang/hanshui2");
        tell_object(me, HIY"���沨���������ڷ����˰��ߣ�����ʪ�����������˺�ˮ������\n"NOR);
        tell_room(environment(me), me->name() + "�����γ����������漴ʪ���������ϰ�����\n", ({ me }));
        return 1;
}
