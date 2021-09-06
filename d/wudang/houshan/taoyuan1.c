// /u/dubei/wudang/taoyuan1

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","�嶥");
        set("long", @LONG
�������䵱��ɽ�ķ嶥��������ľ��䣬�һ����š���������಻֪����
�ݱ�ֲ��ݺύ��һЩ�����۵�ֲ����������ɫ�ļ����
LONG                           
        );
        set("tenghuang_count",500);

        set("outdoors","�䵱");        

        set("exits", ([
                 "down" : __DIR__"hsxl1",
                 "west" : __DIR__"taoyuan2",
                 "east" : __DIR__"taoyuan3",
        ]));
        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));      
}
 
int do_wa(string arg)
{ 
        object tenghuang;
        object me;
        me = this_player();

        if (!( present("yao chu", this_player())))
             return notify_fail("��������֣������ڵ������٣�\n");

        if ( !arg || arg != "caoyao" )
             return notify_fail("����ʲ�᣿\n");

        if (!(int)me->query_temp("mark/wd_mission"))
             return notify_fail("��Ҫ��ʲ�᣿\n");

        if( me->is_busy() || me->is_fighting())
             return notify_fail("����æ���ء�\n");

        if ((int)me->query("jingli") < 80) 
             return notify_fail("��̫���ˣ�\n");

        if( random(5) != 3){
           me->add("jingli",-40);
           return notify_fail("������ҩ�����������ȥ,ֻ�ڳ���һЩҰ�ݡ�\n"); 
        }

        if (query("tenghuang_count") > 0 && random(10) > 1) {
          message_vision("$N����ҩ������Ȼ���ڵ���һ���ٻơ�\n",me);
          add("tenghuang_count", -1);
          tenghuang = new(MEDICINE_D("wudang/tenghuang"));
          tenghuang->move(me);
          me->start_busy(1);
          me->add("jingli", -60);
        }
        else  message_vision("$N���˰��쾢��ֻ�ڵ�һЩҰ�ݡ�\n", me);
        return 1;
}
