// miehuo2.h Cht@SJ 2000-3-12 ÐÞ¸Ä
#include <ansi.h>
int do_miehuo(string arg)
{
        object me, ob;
        object *inv;
        me = this_object();
        ob = this_player();
        inv = deep_inventory(me);
        if( ob->is_busy())
                return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");
        if( ob->is_fighting())
                return notify_fail("ÄãÕýÔÚÕ½¶·¡£\n");
        if( !sizeof(inv))
                return notify_fail("Â¯×ÓÀïÃæÃ»ÓÐ¶«Î÷¡£\n");
        if( me->query("marks/open") )
                return notify_fail("Â¯×ÓÕý¿ª×ÅÄØ£¬Ï¹ÃðÊ²Ã´»ð£¿\n");
        if( !me->query("marks/doing") && !me->query("marks/fired") )
                return notify_fail("Â¯×Ó»¹Ã»µã»ð£¡\n");
        if( !ob->query_temp("doing", 1) )
                return notify_fail("ÄãÃ»ÔÚ°¾Ò©¡£\n");
        if( ob->query_temp("doing", 1) && !ob->query_temp("done", 1) )
                return notify_fail("Äã»¹Ã»°¾ÍêÒ©ÄØ£¡\n");

        message_vision("\n$N°Ñµ¤Â¯ÄÚµÄ²ñ»ð½¥½¥µØÏ¨ÃðÁË¡£\n", ob);
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
                        if( inv[i]->name() == HIC"´¨±´"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"ÉúµØ"NOR)
                        {
                                b = b+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ½ð´´Ò©
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
                        
                        if( inv[i]->name() == HIR"²Øºì»¨"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIY"öèµ¨"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"ÌïÆß"NOR)
                        {
                                c = c+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ÌïÆßöèµ¨É¢
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
                        
            if( inv[i]->name() == GRN"ºÎÊ×ÎÚ"NOR)
                        {
                                a = a+1;
                         }
            if( inv[i]->name() == HIW"¾Õ¹£"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"ÌïÆß"NOR)
                        {
                                c = c+1;
                         }
            if( inv[i]->name() == YEL"ÐÛ»Æ"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ÐøÃü°Ëµ¤
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
                        
                        if( inv[i]->name() == HIR"²Øºì»¨"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIC"·À·ç"NOR)
                        {
                                b = b+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// °Ù²Ýµ¤
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
                        if( inv[i]->name() == HIR"²Øºì»¨"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIG"ºÉÒ¶"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIW"Ñ©Á«×Ó"NOR)
                        {
                                c = c+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ¾Å»¨ÓñÂ¶Íè
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
                        if( inv[i]->name() == HIW"»¢¹Ç"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"Ñ©Á«×Ó"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"ÜòÜß"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIW"°×ÜÆ"NOR)
                        {
                                d = d+1;
                         }
                        if( inv[i]->name() == HIG"ÈË²Î"NOR)
                        {
                                e = e+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// °×»¢¶áÃüµ¤
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
                        if( inv[i]->name() == HIG"ºÉÒ¶"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIB"²õÍÉ"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIG"ÈË²Î"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == GRN"ºÎÊ×ÎÚ"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ¾Å×ª½áÆøÍè
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
                        if( inv[i]->name() == HIG"ÄÛÖñÒ¶"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"²ñºú"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == YEL"Ä¾¹Ï"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIY"»ÆÜÎ"NOR)
                        {
                                d = d+1;
                         }

                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ÑÓÄê¾Û¾«µ¤
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
                        if( inv[i]->name() == HIG"ºÉÒ¶"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"Ñ©Á«×Ó"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"ÜòÜß"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIC"´¨±´"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ÓñÂ¶ÇåÐÂÉ¢
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
                        if( inv[i]->name() == CYN"µ±¹é"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == HIW"½ðÒø»¨"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIW"°×Þ±"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIC"·À·ç"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ¹éÔªµ¤
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
                        if( inv[i]->name() == HIG"ºÉÒ¶"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == CYN"µ±¹é"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIW"Ìì»¨·Û"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIC"Þ½Ïã"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// ´ó»¹µ¤
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
                        if( inv[i]->name() == HIW"Ìì»¨·Û"NOR)
                        {
                                a = a+1;
                         }
                        if( inv[i]->name() == CYN"µ±¹é"NOR)
                        {
                                b = b+1;
                         }
                        if( inv[i]->name() == HIC"Þ½Ïã"NOR)
                        {
                                c = c+1;
                         }
                        if( inv[i]->name() == HIG"É£Ò¶"NOR)
                        {
                                d = d+1;
                         }
                         if( (int)ob->query_temp("done", 1) == 1)
                         {
                                z = 1;
                         }
                }

// Ð¡»¹µ¤
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
                message_vision(HIR"\nÓÉÓÚÒ©·½´íÎó£¬$NÁ¶µ¤Ê§°ÜÁË¡£\n"NOR,ob);
                ob->delete_temp("doing");
                if( userp(ob) ) log_file("LIAN_DAN",
                sprintf("%s %s(%s) ÒòÎªÒ©·½´íÎóÁ¶µ¤Ê§°Ü ÓÚ %s\n", ob->query("title"), ob->name(1), geteuid(ob), ctime(time())[4..19] ) );
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
        sprintf("%s %s(%s)Á¶ÖÆ%s(%s) ÓÚ %s\n", ob->query("title"), ob->name(1), geteuid(ob), obj->name(1), obj->query("id"), ctime(time())[4..19] ) );

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
