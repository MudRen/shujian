// miehuo2.h Cht@SJ 2000-3-12 �޸�
#include <ansi.h>
int do_miehuo(string arg)
{
        object me, ob;
        object *inv;
        me = this_object();
        ob = this_player();
        inv = deep_inventory(me);
        if( ob->is_busy())
                return notify_fail("����æ���ء�\n");
        if( ob->is_fighting())
                return notify_fail("������ս����\n");
        if( !sizeof(inv))
                return notify_fail("¯������û�ж�����\n");
        if( me->query("marks/open") )
                return notify_fail("¯���������أ�Ϲ��ʲô��\n");
        if( !me->query("marks/doing") && !me->query("marks/fired") )
                return notify_fail("¯�ӻ�û���\n");
        if( !ob->query_temp("doing", 1) )
                return notify_fail("��û�ڰ�ҩ��\n");
        if( ob->query_temp("doing", 1) && !ob->query_temp("done", 1) )
                return notify_fail("�㻹û����ҩ�أ�\n");

        message_vision("\n$N�ѵ�¯�ڵĲ�𽥽���Ϩ���ˡ�\n", ob);
        remove_call_out("do_drug");
        remove_call_out("do_check");
        remove_call_out("do_ready");
        remove_call_out("do_confirm");
        remove_call_out("do_failed");
        call_out("do_drug", 3 , me);
        me->delete("marks/aoyao");
        me->delete("marks/fired");
        me->delete("marks/burned");
        me->delete("marks/doing");
        ob->delete_temp("doing");
        ob->start_busy(14);
        return 1;

}

void do_drug()
{
        int a, b, i, x, y, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        x = 0;
        y = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"����"NOR)
                        {
                                b = b+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ��ҩ
                if(  sizeof(inv) != 3
                ||  a != 2
                ||  b != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug1");
                 call_out("do_drug1", 0, me);
                }

                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/jinchuang");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug1()
{
        int a, b, c, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        
                        if( inv[i]->name() == HIR"�غ컨"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIY"�赨"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                c = c+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// �����赨ɢ
                if(  sizeof(inv) != 3
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug2");
                 call_out("do_drug2", 0, me);
                }
                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/shadansan");
                obj->move(me);                                                                 
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug2()
{
        int a, b, c, d, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        
            if( inv[i]->name() == GRN"������"NOR)
                        {
                                a = a+1;
                         }
            if( inv[i]->name() == HIW"�չ�"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                c = c+1;
                         }
            if( inv[i]->name() == YEL"�ۻ�"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// �����˵�
                if(  sizeof(inv) != 4
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug3");
                 call_out("do_drug3", 0, me);
                }
                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/badan");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug3()
{
        int a, b, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;

        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        
                        if( inv[i]->name() == HIR"�غ컨"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                b = b+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// �ٲݵ�
                if(  sizeof(inv) != 3
                ||  a != 2
                ||  b != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug4");
                 call_out("do_drug4", 0, me);
                }

                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/baicao");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug4()
{
        int a, b, c, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIR"�غ컨"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIG"��Ҷ"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIW"ѩ����"NOR)
                        {
                                c = c+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// �Ż���¶��
                if(  sizeof(inv) != 5
                ||  a != 1
                ||  b != 3
                ||  c != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug5");
                 call_out("do_drug5", 0, me);
                }

                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/jiuhuawan");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug5()
{
        int a, b, c, d, e, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIW"����"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"ѩ����"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIW"����"NOR)
                        {
                                d = d+1;
                         }
                        if( inv[i]->name() == HIG"�˲�"NOR)
                        {
                                e = e+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// �׻�������
                if(  sizeof(inv) != 5
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  e != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug6");
                 call_out("do_drug6", 0, me);
                }

                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/duoming-dan");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug6()
{
        int a, b, c, d, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIG"��Ҷ"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIB"����"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIG"�˲�"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == GRN"������"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ��ת������
                if(  sizeof(inv) != 4
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug7");
                 call_out("do_drug7", 0, me);
                }

                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/jieqi-wan");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug7()
{
        int a, b, c, d, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIG"����Ҷ"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"���"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == YEL"ľ��"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIY"����"NOR)
                        {
                                d = d+1;
                         }

                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ����۾���
                if(  sizeof(inv) != 4
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug8");
                 call_out("do_drug8", 0, me);
                }

                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/jujing-dan.c");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug8()
{
        int a, b, c, d, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIG"��Ҷ"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"ѩ����"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ��¶����ɢ
                if(  sizeof(inv) != 4
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug9");
                 call_out("do_drug9", 0, me);
                }
                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/qingxin-san");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug9()
{
        int a, b, c, d, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == CYN"����"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"������"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIW"��ޱ"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIC"����"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ��Ԫ��
                if(  sizeof(inv) != 4
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug10");
                 call_out("do_drug10", 0, me);
                }
                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/guiyuan-dan");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}

void do_drug10()
{
        int a, b, c, d, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIG"��Ҷ"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == CYN"����"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIW"�컨��"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIC"޽��"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// �󻹵�
                if(  sizeof(inv) != 4
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug11");
                 call_out("do_drug11", 0, me);
                }
                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
          obj=new("/clone/medicine/dahuan-dan");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}


void do_drug11()
{
        int a, b, c, d, i, z;
        object obj, *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->name() == HIW"�컨��"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == CYN"����"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"޽��"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIG"ɣҶ"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// С����
                if(  sizeof(inv) != 4
                ||  a != 1
                ||  b != 1
                ||  c != 1
                ||  d != 1
                ||  z != 1)
                {
                 remove_call_out("do_drug12");
                 call_out("do_drug12", 0, me);
                }
                else
                {
                        for(i=0; i<sizeof(inv); i++)
                        {      destruct(inv[i]);   }
                obj=new("/clone/medicine/xiaohuan-dan");
                obj->move(me);
                remove_call_out("do_over");
                call_out("do_over", 0, obj);
                }
        }
        return;
}


void do_drug12()
{
        int i;
        object *inv;
        object me = this_object();
        object ob = this_player();
        inv = deep_inventory(me);

        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        destruct(inv[i]);
                }
                message_vision(HIR"\n����ҩ������$N����ʧ���ˡ�\n"NOR,ob);
                ob->delete_temp("doing");
                if( userp(ob) ) log_file("LIAN_DAN",
                sprintf("%s %s(%s) ��Ϊҩ����������ʧ�� �� %s\n", ob->query("title"), ob->name(1), geteuid(ob), ctime(time())[4..19] ) );
                me->delete("liquid/remaining");
                me->delete("liquid/name");
        }
        return;
}

void do_over(object obj)
{       
        object me = this_object();
        object ob = this_player();

        ob->delete_temp("done");
        me->delete("liquid/remaining");
        me->delete("liquid/name");   

        if( userp(ob) ) log_file("LIAN_DAN",
        sprintf("%s %s(%s)����%s(%s) �� %s\n", ob->query("title"), ob->name(1), geteuid(ob), obj->name(1), obj->query("id"), ctime(time())[4..19] ) );

        if( ((int)ob->query("potential", 1)+30) < (int)ob->query("max_pot", 1))
        {
                ob->add("potential", 10+random(10));
        }
        if( ((int)ob->query("potential", 1)+30) >= (int)ob->query("max_pot", 1))
        {
                ob->set("potential", (int)ob->query("max_pot", 1));
        }
        return;
}
