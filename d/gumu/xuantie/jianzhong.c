// jianzhong.c
// By River 98.08.29
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"��ڣ"NOR);
        set("long", @LONG
�Ὺڣ��ʯ�飬¶���������������������ڵ�һ���ڶ����ѽ�֮�䣬����
һ�鳤��ʯƬ����������ʯƬ�����һ�����ʯ֮�ϡ�  
LONG
        );
        set("item_desc", ([        
           "shipian" : "��ޱ������ʮ��ǰ���ã������岻�飬����֮��ȡ�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_ti", "ti");
        add_action("do_ti", "na");
        add_action("do_tui", "tui");               
}

int do_ti(string arg)
{
        object me,sword,ob;
        int i;
        me = this_player();
        if (!arg ) return 0;         
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if(!present("fire", me))
                return notify_fail("������û�е��֮����������ʲô��\n");
        if ( arg == "gangjian" ){
           ob = unew(BINGQI_D("sword/wuming-jian"));
           if(!clonep(ob))
              return notify_fail(HIR"�������ˣ����������Ѿ�����ȡ���ˡ�\n"NOR);              
           if(clonep(ob) && ob->violate_unique()){
              destruct(ob);
              return notify_fail(HIR"�������ˣ����������Ѿ�����ȡ���ˡ�\n"NOR);
           }
           tell_object(me,HIY"���������׵�һ������ֻ�����µ�ʯ�Ͽ�������С�֣�\n"+
                             "���������ͣ��޼᲻�ݣ�����ǰ��֮���˷Ⱥ�����档��\n"NOR);
           tell_room(environment(me), me->name() + "���������������������׵�һ������\n"NOR, ({ me }));
           ob->move(me);
           return 1;
        }
        else
        if ( arg == "xuantiejian" ){
           if (!me->query("ygpass")){
             if (me->query_str() < 35 )
                  return notify_fail("�����������������������������ġ�\n");
           }
           else if (me->query_str() < 32 )
                  return notify_fail("�����������������������������ġ�\n");
           if (me->query("max_neili") < 2000 ){
                tell_object(me,HIY"��������ȥ��ڶ�������ֻ�������ߣ�Ǻ�һ������Ȼ���ֵ��£���ʯ��һ����\n"+
                                  "���Ľ�������������һ����\n"NOR);
                tell_room(environment(me), me->name() + "������ȥ��ڶ�������ֻ�������ߣ�Ǻ�һ������Ȼ���ֵ��¡�\n"NOR, ({ me }));
                return 1;
            }
            sword= unew(BINGQI_D("sword/xuantiejian"));
            if(!clonep(sword))
                return notify_fail(HIR"�������ˣ��������Ѿ�����ȡ���ˡ�\n"NOR);
            if(clonep(sword) && sword->violate_unique()){
                destruct(sword);
                return notify_fail(HIR"�������ˣ��������Ѿ�����ȡ���ˡ�\n"NOR);
            } 
            if(me->query("neili") >= 300 )
                me->add("neili", -300);
            else
                me->set("neili", 0);
                me->delete_temp("sword");
                tell_object(me,HIY"������ٸ�����������˷����������߰�ʮ����������ǲ���һ���¡�����\n"+
                                  "�����߽��涼�Ƕۿڣ������ԲԲ�����Ǹ����򡣿����µ�ʯ��ʱ��������С\n"+
                                  "�ֵ������ؽ��޷棬���ɲ�������ʮ��ǰ��֮�������¡���\n"NOR);
                tell_room(environment(me), me->name() + "���˿�������������ڶ�������\n"NOR, ({ me }));
                sword->move(me);
                return 1;
        }
        else if( arg == "mujian") {
                tell_object(me,HIY"���������ȥȡ������������֪��������ȴ��ƮƮ�Ļ����������һ����ԭ\n"+
                                  "���Ǳ�ľ���������վã����������Ѹ��࣬�������µ�ʯ�̵�������ʮ���ᣬ\n"+
                                  "��������ľ��ʯ����Ϊ�����Դ˾��ޣ�������޽�ʤ�н�֮������\n"NOR);

                if(me->query_temp("quest/wuzhao/over")){
                
                i = me->query_temp("quest/wuzhao/over");
                
                
                 if(me->query_skill("dugu-jiujian",1)>=451
                                   && me->query("int")>35
                                   &&random(me->query("kar"))>=28
                                   &&random(15-i)==10
                                   &&!me->query("quest/pass/dugu-jiujian/wuzhao")
                       || me->query("id")=="master"){
                tell_object(me,HBMAG"�����ʯ���µ��ֳ�Ĭ���ã�������������\n"+
                                  MAG"���¾Ž����������У�����ʽ֮�⣬������ʽ֮�Ρ������¾Ž�����΢�������\n"+
                                   "���㣬���Ͼ�һ��һʽ�����м���Ѱ�������ٽ���������ʤ���С��Ľ��������\n"+
                                   "�ã��Ǿ͸��ӵĿ���Ʈ���������޴�׽������������ֻ��һ�У���Ҳֻ��һ�У�\n"+
                                   "������ǧ�����У���Ҳ��ǧ�����У������֮������ȻӦ�ӡ�\n"+
                                  HBRED"��ϲ����ɹ��������˶��¾Ž����޽�ʤ�н�������ʤ���У����İ��ؾ��壡����\n"NOR);               
                                 me->set("quest/pass/dugu-jiujian/wuzhao",1);
                                 me->delete_temp("quest/wuzhao");
                                 
                                 
                if( !me->query("quest/pass/dugu-jiujian/wuzhao"))
                       log_file("quest/wuzhao", 
                                  sprintf("%-18s�ڽ�ڣ����������ʽ������%d����%d��\n",
                                           me->name(1)+"("+capitalize(getuid(me))+")",
                                         me->query("kar"), 
                                           me->query("int") 
                                   ), me
                            );                                
                                 
                                   }
                 else me->delete_temp("quest/wuzhao");
                }
          
                return 1;
              }
}

int do_tui(string arg)
{
        object me;
        me = this_player();
        if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ���ģ�\n");
        if ( !arg || arg !="shi" )
             return notify_fail("��Ҫ��ʲô��\n");
          message_vision(YEL"$N��������˿����������ƶ���ʯ��\n"NOR,me);
          write(HIG"\n�����ʯ�ƿ���¶���˽�ڣ�ĳ��ڡ�\n"NOR);
          set("exits/out", __DIR__"pingtai");
          remove_call_out("close");
          call_out("close", 5, this_object());
          return 1; 
}      

void close(object room)
{
        message("vision",HIY"��ʯ�����ƻ���ԭλ���ֵ�ס�˳��ڡ�\n"NOR, room);
        room->delete("exits/out");
}

