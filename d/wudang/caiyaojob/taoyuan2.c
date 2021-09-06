// Room : /d/wudang/taoyuan2 ��԰
// By lius 99/8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","ɽ��");
        set("long", @LONG
������ɽ�������࣬���Ұ����������磬��򿪷��ŵİ׻���ӭ��ҡ
ҷ��һ�ж���������Ȼ�Ļ��������ô����Ȼ��Ұ�Ժ����ѡ�������һ����
�����׵�Ͽ�ȣ�ɽ���ܼ����ٴ��Ʊۣ������ٲ�һк���£�ɷ��׳�ۡ�
LONG                           
        );
        set("mahuang_count",500);
        
        set("exits", ([               
                 "east" : __DIR__"taoyuan1",
        ]));
        setup();
}

void init()
{
            add_action("do_wa", ({"wa","dig","��"}));
            add_action("do_hold", "hold");
            add_action("do_jump", ({"jump","tiao"}));        
}
 
int do_wa(string arg)
{ 
        object mahuang;
        object me;
        me = this_player();
        if (!( present("yao chu", this_player())))
        return notify_fail("��������֣������ڵ������٣�\n");
        if ( !arg || arg != "caoyao" )
        return notify_fail("����ʲ�᣿\n");
         if (!(int)me->query_temp("mark/wd_mission"))
         return notify_fail("��Ҫ��ʲ�᣿\n");
           if ( (int)me->query("jingli")<80) 
             { write("��̫���ˣ�\n");
         return 1;
            }
        if(random(5)!=3) {
        me->add("jingli",-30);
        return notify_fail("������ҩ�����������ȥ,ֻ�ڳ���һЩҰ�ݡ�\n"); 
         }
//        if (!(int)me->query("jingli") <65)
//        return notify_fail("����Ҫ�ʵ���Ϣһ���ˣ�\n");
        if (query("mahuang_count") > 0) 
       {
        message_vision("$N����ҩ������Ȼ���ڵ���һ����ơ�\n",me);
        add("mahuang_count", -1);
        mahuang=new(__DIR__"obj/mahuang");
        mahuang->move(me);
        me->add("jingli", -50);
        
        }
        else
       message_vision("$N���˰��쾢��ֻ�ڵ�һЩҰ�ݡ�\n", me);
        return 1;
}

int do_hold(string arg)
{
        object me;
        me=this_player();

        if (me->is_busy())
           return notify_fail ("�����ں�æ��\n");
        if (me->is_fighting())
           return notify_fail ("�㻹��ר��ս���ɡ���\n");        
        if ( arg != "teng" && arg != "ɽ��" )
           return notify_fail("����ץסʲô��\n");
        if ( me->query_temp("hold_teng"))
           return notify_fail ("����ץסɽ���ء�\n");
        write(HIY"�����˫�֣����ε�ץס��ɽ�١�\n"NOR);
        message("vision",me->name() + "ͻȻ���˫�֣����ε�ץסɽ�١�\n",
                environment(me), ({me}) );
        me->set_temp("hold_teng",1);
        return 1;
    }

int do_jump(string arg)
{
        object me = this_player();

        if (me->is_busy())
           return notify_fail ("�����ں�æ��\n");
        if (me->is_fighting())
           return notify_fail ("�㻹��ר��ս���ɡ���\n");
        if ( arg != "down" )
           return notify_fail ("��Ҫ������������\n");
        if ( !me->query_temp("hold_teng"))
           return notify_fail ("������ѽ��������\n");
        else
     {  message("vision", me->name() + "�����ʯ��˫�ֽ���ɽ�٣��������µ�ȥ��\n", environment(me), ({me}));
        if ( me->query_skill("dodge",1) > 100 && me->query_skill("hand",1) > 80 ){
                write(HIY"\n��˫�Ž����ᴥ��ʯ�������»�����������㣬���ȵ������˹ȵס�\n"NOR); 
                me->move("/d/wudang/gudi");
                me->delete_temp("hold_teng");
                return 1;
           }
        else
                write(WHT"\n��ŵ�ɽ�ң����ճ��٣�������ȵ׻�ȥ��\n"NOR);
                write(HIR"\n��ͻȻ��һ��˫����Ҳ���ܰѳ�ɽ�٣����ص�ˤ����ȥ��\n"NOR);
                me->move("/d/wudang/gudi");
                me->delete_temp("hold_teng");
                me->receive_damage("qi", me->query("max_qi")/2);
                me->receive_wound("qi", me->query("max_qi") / 2);
                me->unconcious();
                message("vision", me->name() + "������ˤ�����������ء���һ�����صص����˵��ϡ�\n", environment(me), ({me}));
                return 1;
        }
}