// Room: gudi.c �ȵ�
// Created by Numa 1999-12-04

#include <ansi.h>
inherit ROOM;

string do_zb1();

void create()
{
        set("short", HIW"�ȵ�"NOR);
        set("long", @LONG
���ڹ�ʯ��ᾣ���û��һ���·��Ѱ���˴����Ϻ���Ѱ���ط��ɱȣ�
���������ƺ������ϵ��к��紵���������쳣��
LONG);
        set("item_desc",([
                "��ʯ": (: do_zb1 :),
                "ʯ":   (: do_zb1 :),
                "stone":(: do_zb1 :),
        ]));
        set("outdoors", "��ɽ");
        setup();
}

string do_zb1()
{
        object me = this_player();
        
        if (!me->query_temp("ss/zsb_4"))
                return "������֮�����ǹ�ʯ�����޴���Ķ��ڹ��С�\n";
        me->delete_temp("ss/zsb_4");
        me->set_temp("ss/zsb_end",1);
        return "������֮�����ǹ�ʯ�����޴���Ķ��ڹ��С�������һ��ʯͷ���ƺ��ж�������˸��\n";
}



void init()
{
        object ob = this_player();
        if (userp(ob))
        {
                if (ob->query_skill("hanbing-zhenqi",1) < 200)
                {
                        message_vision(HIW"$N���¹ȣ����ȫ���飬���ŵ�˳���������˻�ȥ��\n"NOR,ob);
                        ob->move(__DIR__"dtlxia");
                        message_vision(BLU"$N��ɫ���࣬��Ļ���ֱ���¡�\n"NOR,ob);
                        return;
                }
                else if (ob->query_skill("hanbing-zhenqi",1) > 220)
                        message_vision(HIW"$N˳������������������û��ʲô�����ĸо���\n"NOR,ob);
                else
                {
                        ob->set_temp("ss/get_cold",1);
                        message_vision(HIW"$N���¹ȣ�ֻ�о����������²�󣬲��ɵô��˸������\n"NOR,ob);
                }
        }
        add_action("do_back",({"climb","pa"}));
        add_action("do_resist",({"resist","diyu","kangheng"}));
        add_action("do_move",({"fan","move"}));
}

int do_back(string arg)
{
        object me = this_player();
        
        if (!arg)
                return notify_fail("ʲô��\n");
        if (arg != "up" && arg != "back")
                return notify_fail("��Ҫ����������\n");

        if(me->query_encumbrance() * 100 / me->query_max_encumbrance() > 20)
                return notify_fail("�㱳��ô�ණ�������µ�������\n");
        
        message_vision("$N���˴��֣�һ������˳��ɽ��������ȥ��\n",me);
        me->add("jingli",100);
        me->add("neili",200);
        me->delete_temp("ss");
        me->move(__DIR__"dtlxia");
        tell_room(environment(me),me->name(1)+"�ӹȵ������������۵�����������\n",({me}));
        return 1;
}

int do_move(string arg)
{
        object me = this_player();
        object ob, *clone;
        int i, j;
        
        if (!arg)
                return 0;
        if (arg != "stone" && arg != "ʯͷ" && arg != "��ʯ")
                return 0;
        if (!me->query_temp("ss/zsb_end"))
                return notify_fail("û�±��Ұ�ʯͷ���Ա��˳ŵģ�\n");

        if (me->query("neili") < 2000)
        {
                message_vision("$N�þ�ȫ����Ҫ�Ὺʯͷ��û�뵽һ������ʯͷ�������Լ����ϡ�\n",me);
                me->unconcious();
                return 1;
        }
        me->add("neili",-1000);
        message_vision("$N�þ�ȫ�������һ����ʯͷ���˿�����\n",me);

        ob = unew(__DIR__"obj/ice");
        if(!clonep(ob))
                return notify_fail("�㷢������ʲô��û�С�\n");
        i = ob->query("unique");
        clone = filter_array(children(base_name(ob)), (: clonep :));
        j = sizeof(clone);
        while (j--)
                if (!clone[j]->query("clone_by_wizard"))
                        i--; 
        if(clonep(ob) && i < 0)
        {
                destruct(ob);
                return notify_fail("�㷢������ʲô��û�С�\n");
        }

        tell_object(me,"�㷢��ʯͷ�о�Ȼ��һ���������м��ƺ�����ʲô������\n");
        ob->set_temp("find_by",me->query("id"));
        ob->move(this_object());
        me->delete_temp("ss/zsb_end");
        me->set_temp("ss/zsb_get",1);
        return 1;
}
        
int do_resist(string arg)
{
        object me = this_player();
        object ob = this_object();
        
        if (!arg)
                return 0;
        if (arg == "hanfeng" || arg == "cold" || arg == "hanleng")
        {
                if (!me->query("ss/hb_improve"))
                        return 0;
                if (!me->query_temp("ss/get_cold"))
                        return notify_fail("��Ҫ��ʲô��\n");
        
                if (me->query_skill("hanbing-zhenqi",1) < 200
                ||  me->query("max_neili") < 3000)
                        return notify_fail("����ڹ���Ϊ���֮�ǿ���뺮���࿹����»�������Σ�ա�\n");

                if (me->is_busy() || me->is_fighting())
                        return notify_fail("����æ���أ�\n");
        
                if (me->query("jingli")<50)
                        return notify_fail("������̫���ˣ�������Ϣһ�°ɣ�\n");

                if (me->query("neili")<100)
                        return notify_fail("������̫���ˣ�������Ϣһ�°ɣ�\n");

                if (me->query("jing")<50)
                        return notify_fail("������̫���ˣ�������Ϣһ�°ɣ�\n");
                
//              me->delete_temp("ss/get_cold");
                tell_object(me,BLU"�㾲�����ȶ������������ں������������ĺ����࿹�⡣\n"NOR);
                tell_room(ob,HIW + me->name(1) + "���ȶ���������һ�ɰ��������š�\n"NOR,({me}));
                me->start_busy(5);
                remove_call_out("hb_improving");
                call_out("hb_improving",4,me);
                return 1;
        }
        else
                return notify_fail("��Ҫ��ʲô�࿹�⣿\n");
}

int hb_improving(object me)
{
        int i;
/*      
        if (!me)
        {
                remove_call_out("hb_improving");
                return 1;
        }
*/      
        if (!me->query("songshan_point"))
                i = 100;
        else
                i = me->query("songshan_point")/3;
        if (i<100)
                i = 100;
        if (i>600)
                i = 600;
        
        me->receive_damage("jingli",30);
        me->receive_damage("neili",50);
        if (random(5)>3)
        {
                tell_object(me,"ͻȻһ��ǿ�紵������Ҳ���ɵô��˸������\n");
                me->receive_damage("jing",30);
        }
        i += (400 - me->query_skill("hanbing-zhenqi",1))*2;
        if (i>800)
                i = 800;
  me->improve_skill("hanbing-zhenqi", i*2/3 + random(i));
        tell_object(me,"�����뺮��Ŀ��⵱�к�����������ΪҲ���������\n");
        return 1;
}
