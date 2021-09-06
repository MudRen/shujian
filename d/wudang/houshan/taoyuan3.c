// /u/dubei/wudang/taoyuan3

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","ɽ��");
        set("long", @LONG
������ɽ�嶥�������һ��С�£�����Ҳ���Ӳ��ܲ������Ӳ�֮����Լ��
һЩ�����ֲ��ϱ���һ��֦��Ҷï�����֡����ֺ��������һ��é�ݡ�
LONG                           
        );
        set("xionghuang_count",500);

        set("outdoors","�䵱");        

        set("exits", ([               
                 "west" : __DIR__"taoyuan1",
        ]));
        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));
        add_action("do_zuan", ({"zuan","zuan"}));       
}
 
int do_wa(string arg)
{ 
        object xionghuang;
        object me;
        me = this_player();

        if (!( present("yao chu", this_player())))
             return notify_fail("��������֣������ڵ������٣�\n");

        if ( !arg || arg != "caoyao" )
             return notify_fail("����ʲ�᣿\n");

        if (!(int)me->query_temp("mark/wd_mission"))
             return notify_fail("��Ҫ��ʲ�᣿\n");

        if ( (int)me->query("jingli")<80) 
             return notify_fail("��̫���ˣ�\n");

        if(random(5)!=3) {
           me->add("jingli",-30);
           return notify_fail("������ҩ�����������ȥ,ֻ�ڳ���һЩҰ�ݡ�\n"); 
        }

        if (query("xionghuang_count") > 0){
          message_vision("$N����ҩ������Ȼ���ڵ���һ���ۻơ�\n",me);
          add("xionghuang_count", -1);
          xionghuang = new(MEDICINE_D("wudang/xionghuang"));
          xionghuang->move(me);
          me->add("jingli", -50);
        }
        else  message_vision("$N���˰��쾢��ֻ�ڵ�һЩҰ�ݡ�\n", me);
        return 1;
}

int do_zuan(string arg)
{
        object me;
        me = this_player(); 
        if ( arg != "shulin" ) return 0;
        if ( !arg ) return 0;

        if (!me->query_temp("marks/taohua"))
            return notify_fail("������������ɣ�\n");
          
        message_vision("$N������֦��һ���������˽�ȥ��\n", me);
        me->move(__DIR__"maowu");
        tell_room(environment(me), me->name() + "�����������˽�����\n", ({ me }));
        me->delete_temp("marks/taohua");
        return 1;
}
