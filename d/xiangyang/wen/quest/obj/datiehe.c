// Room: /d/huashan/jinshe/obj/datiehe.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("������" , ({ "tie he", "box" }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������ߵ������ӣ�����������������\n");
                set("value", 1000);
                set("material", "steel");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
                }
        setup();
}

int is_container() { return 1; }

void init()
{
        add_action("do_open", "open");
        add_action("do_move", "move");
}

int do_open(string arg)
{
        object me = this_player();
        object ob;

    if (me->query_temp("open") && geteuid(me) != "yueying")
          return notify_fail("���Ѿ��򿪺�����\n");   
    if (!arg || (arg != "box" && arg != "tie he"))
       {
        return notify_fail("�����ʲô��\n");
        return 1;
       }
    else
    {  
    if (!present("jia xin",me) && me->query("quest/jinshe2/xin"))
    {
          ob=unew(__DIR__"jiaxin");
          if (random(20)< 15 || random (5)< 3){
                        write("������У���������տյ�ʲôҲû�С�\n");
                        write(HIG"���������Ѿ�ȡ��������Ķ���,�㻹�Ǹ���������.\n"NOR);
                  return 1;
                 }
        ob->move(me);
        write(HIC"���Ὺ��ϻ����������ƽƽ��������һ������,����æ����������\n"NOR);
        
        me->set_temp("open",1);
        return 1;       
      }
    if (!present("xin jian",me))
       {
        write("���Ὺ��ϻ��ͻȻ������һ���ż㣬�㼱æ��������\n");
        ob=new(__DIR__"xinjian1");
        me->set_temp("mark/open",1);
        me->set_temp("open",1);
        ob->move(me);
        return 1;
       }
        write("������У���������տյ�ʲôҲû�С�\n");
        return 1;
    }
}
int do_move(string arg)
{
        object me = this_player();
        object ob;
        if ( !arg || arg != "anceng" )
        return notify_fail("��Ҫ��ʲ�᣿\n");
        if (!(int)me->query_temp("mark/open") && !(int)me->query_temp("mark/xin"))
         return notify_fail("��Ҫ��ʲ�᣿\n");
        
                write("��С������򿪰���.......\n");
                if (random(10) > 8 || me->query("env/debug")){
                                          ob=unew(__DIR__"jinshezhui");
                                          if ( ob ){
                                                         ob->move(me);
                                                         me->delete_temp("mark/open");
                                                         me->delete_temp("mark/xin");
                                                         write(HIY"��Ȼ����,һ���������������׶��������,��������ֵǮ������,�㿪�ļ���,��æ������������\n"NOR);
                                          
                                                     return 1;
                                                    }
                                          else return 1;
                                          }          
                          
        message_vision(RED"$NͻȻ���������������棬���һ����һ��鴤��\n"NOR, me);
        me->delete_temp("mark/open"); 
        me->unconcious();
        return 1;
}

