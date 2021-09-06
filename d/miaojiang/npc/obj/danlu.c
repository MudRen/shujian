//danlu.c ��¯ 
//��Ϊ��quest�����ģ��޷���������ҩ��
//��¯����ҩ����ˮ����¯������ȷ硢��ҩ�����ȡҩ
//�ɹ���100%

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
int do_hehe(object me, object obj, object dest);
int do_haha(object ob, object obj);

void create()
{
       set_name(HIR"��¯"NOR, ({ "dan lu", "lu", "yao lu" }) );
       set_weight(3000000);
       set_max_encumbrance(2000);

       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "��");
               set("no_get", "��¯������˵̫���ˡ�\n");
               set("no_get_from", 1);
               set("long", "����һ������������ҩ�ĵ�¯��\n"NOR);
               set("value", 100000000);
               set("no_get",1);                 
               set("no_give",1);
               set("no_put",1);
               set("no_drop",1);           
               set("max_liquid", 100);
               set("material", "iron");
               set("marks/open", 0);
       }
       setup();
}
                   
int is_container() { return 1; }

void init()
{
        add_action("do_open", "open"); // open lid
        add_action("do_add",   "add"); // add xxx in lu
        add_action("do_pour", "pour"); // pour water
        add_action("do_close", "close"); // clone lid
        add_action("do_fire", "dianhuo"); // fire
        add_action("do_burn", "burn"); // burn coal  
        add_action("do_aoyao", "aoyao"); // aoyao
        add_action("do_miehuo", "miehuo"); // mie huo
        add_action("do_qu", "qu"); // qu yao from lu
        add_action("do_action", "put"); //forbid these two commands
}

int do_action(string arg)
{
        write("����(add ҩ���� in lu)������¯�����ҩ�ġ�\n");
        write("����(qu ҩ���� from lu)����ӵ�¯���ó�ҩ�ġ�\n");
        return 1;
}
int do_open(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();
        
        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���С�\n");
        if( !arg || arg == "" || arg != "lu")
                return notify_fail("��Ҫ��ʲô��\n");

        if( me->query("marks/open") )           // �жϵ�¯���Ӵ򿪻��ǹ��ϵġ�
                return notify_fail("��¯�ĸ����Ѿ��Ǵ򿪵��ˡ�\n");

        if( me->query("marks/doing") 
         || me->query("marks/aoyao")
         || me->query("marks/fired"))           // ��������������������ܿ����ӡ�
              {
                message_vision(RED"\n$NͻȻ�ּ�һ���ʹ����ָ��������һ�¡�\n"NOR,ob);
                return 1;
              }

    if( arg == "lu" )
        {
                message_vision("$N�ѵ�¯�ĸ��Ӵ򿪡�\n", ob);
                me->set("marks/open", 1);       // ����򿪸��ӼӴ˱�ǡ�
                return 1;
        }

}
int do_add(string arg)
{
        string arg1, arg2;
        object obj, dest, *inv, obj2;
        object ob = this_player();
        object me = this_object();
        int i, amount;
        dest = present("dan lu", environment(ob));

        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���У�\n");

        if(!arg || sscanf(arg, "%s in %s", arg1, arg2)!=2)
                return notify_fail("����<add ҩ���� in lu>������Ʒ�Ž���¯��\n");

        if (arg2!="lu")
                return notify_fail("����<add ҩ���� in lu>������Ʒ�Ž���¯��\n");

        if( !me->query("marks/open") )   return notify_fail("��¯�ĸ���û�д򿪡�\n");

        if( objectp(obj = present(arg1, ob)) && !obj->query("make/drug") ) // �������Ʒû��make/drug�����ԣ����ܷŽ���¯
                return notify_fail(obj->name()+"����������Ϊ��ҩ��ԭ�ϡ�\n");

        if( !dest || living(dest) )
                return notify_fail("����û������������\n");

        if(sscanf(arg1, "%d %s", amount, arg1)==2) {
                if( !objectp(obj = present(arg1, ob)) )
                        return notify_fail("������û������������\n");
                if( objectp(obj = present(arg1, ob)) && !obj->query("make/drug", 1) )
                        return notify_fail("���ֶ�������������Ϊ��ҩ��ԭ�ϡ�\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ���\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û����ô���" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() )
                        return do_hehe(ob, obj, dest);
                else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if (do_hehe(ob, obj2, dest)) return 1;
                        obj2->move(ob);
                        return 0;
                }
        }

        if(arg1=="all") {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest || !(inv[i]->query("make/drug", 1)) )
                                return notify_fail("���ֶ�������������Ϊ��ҩ��ԭ�ϡ�\n");
                        do_hehe(ob, inv[i], dest);
                write("Ok.\n");
                return 1;
        }
        if(!objectp(obj = present(arg1, ob)))
                return notify_fail("������û������������\n");

        return do_hehe(ob, obj, dest);
}

int do_hehe(object ob, object obj, object dest)
{
        object me;
        me = present("dan lu", environment(ob));

        if (obj == dest) return notify_fail("����Ž�������壿\n");
        if( obj->move(dest) ) {
                message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        ob );
                return 1;
        }
        return 0;
}
int do_pour(string arg)
{
        string hehe, what;
        object me, ob, obj;
        me = this_object();
        ob = this_player();
        if( !arg
        ||  sscanf(arg, "%s to %s", hehe, what) != 2)
                return notify_fail("����<pour ���� to lu>����ˮ�Ž���¯��\n");

        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���У�\n");

        if( !me->query("marks/open") )
                return notify_fail("��¯�ĸ���û�д򿪡�\n");

        if( !objectp( obj = present(hehe, ob)))   // ��������ϵ���Ʒ��ID���ԣ���������¯���ˮ��
                return notify_fail("������û��"+hehe+"���������¯���ˮ��\n");
                
        if( !obj->query("liquid/type"))           // ��������ϵ���Ʒ����ʢˮ�����󣬲�������¯���ˮ��
                return notify_fail(obj->name()+"����ʢˮ������\n");

        if( !obj->query("liquid/remaining") )     // �ж�������ʢˮ���������Ƿ���ˮ��
                return notify_fail(obj->name() + "�����Ѿ�һ�β�ʣ�ˡ�\n");

        message_vision("$N��һЩ"+ obj->query("liquid/name") +"��"+ obj->name() +"������¯��\n", ob);
        obj->add("liquid/remaining", -1);
        me->add("liquid/remaining", 1);
        me->set("liquid/name", obj->query("liquid/name"));
        return 1;
}
int do_close(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();
        
        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���С�\n");

        if( !arg || arg == "" || arg != "lu")
                return notify_fail("��Ҫ��ʲô��\n");

        if( !me->query("marks/open") )      // �жϴ�ʱ��¯�ĸ����Ǵ򿪻��ǹ��ϵ�
                return notify_fail("��¯�ĸ���û�д򿪡�\n");

    if( arg == "lu" )
        {
          message_vision("$N������ŵĽ���¯�ĸ��Ӹ��ϡ�\n", ob);
          me->delete("marks/open");           // ������˰ѵ�¯�ĸ��ӹ��ϣ���ôȥ���˱�ǡ�
          return 1;
        }

}
int do_fire(string arg)
{
        object obj;
        object me = this_object();
        object ob = this_player();
        object *inv;
        inv = deep_inventory(me);

        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���С�\n");

        if( me->query("marks/open") )
                return notify_fail("��¯�ĸ���û�и��ϡ�\n");
        
        if( !objectp( obj = present("fire", ob)))   // �ж���������Ƿ��л��ۡ�
                return notify_fail("����Ҫһ�����ۡ�\n");
                
        if( (int)ob->query("neili")  <= 1000 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");           
                
        if( (int)ob->query("max_neili")  <= 1500 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");                           

        if( me->query("marks/fired"))
                return notify_fail("����Ѿ��������ˡ�\n");   
                
        if( !me->query("liquid/name") )
                return notify_fail("��¯��û��ˮ��\n");  
                
        if( !sizeof(inv)) 
                return notify_fail("��¯����ʲô��û�С�\n");
                
        message_vision(HIR"\n$N��ȼһ�Ѳ�𣬻��罥���ش���������\n"NOR, ob);
        //destruct(obj);
        me->set("marks/fired", 1);
        me->set("marks/doing", 1);  
        //ob->set_temp("doing", 1);
        remove_call_out("do_check");
        call_out("do_check", 300);//û�в���ob,ҩ�ɹ����ɹ�������޹�
        return 1;
}

void do_check()
{
        object me = this_object();
        if ( (int)me->query("marks/doing") > 0) 
        {
           remove_call_out("do_failed");
           call_out("do_failed",0);
        }
        return;
}

int do_burn(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();

        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���С�\n");

        if( me->query("marks/open") )
                return notify_fail("��¯�ĸ���û�и��ϡ�\n");

        if( !me->query("marks/fired") )
                return notify_fail("��¯�ڻ�û����������ô�ܹ�ʹ���ȼ��������\n");

        if( me->query("marks/burned"))
                return notify_fail("��¯��Ļ����Ѿ��ܴ��ˣ������ټӴ�����ˡ�\n");

        if( !arg || arg =="" || arg != "lu")
                return notify_fail("��Ҫȼ��ʲô������\n"); 
                
        if( (int)ob->query("neili")  <= 1000 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");           
                
        if( (int)ob->query("max_neili")  <= 1500 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");                           

        message_vision(HIC"\n$Nʹ�����������䣬��¯��ð���������̡�\n"NOR, ob);
        remove_call_out("do_ready");
        call_out("do_ready", 2);
        me->set("marks/burned", 1);
        ob->add("neili", -1000);
        ob->add("jingli", -500);
        ob->start_busy(3);
        return 1;
}

void do_ready()
{
        object me = this_object();
        message_vision(HIW"\n���ƽ�������������һ��Ũ�صĲ�ҩζ���˱Ƕ�����Ӧ�ð�ҩ�ˡ�\n"NOR, me);
        remove_call_out("do_confirm");
        call_out("do_confirm", 15);
        return;
}

void do_confirm()
{
        object me = this_object();

        if( me->query("marks/aoyao") ) 
        {
                remove_call_out("confirm");
                remove_call_out("ready");
                message_vision(HIR"\nҩ�찾���ˣ��Ͻ����ɣ�\n"NOR, me);
                remove_call_out("do_check");
                call_out("do_check", 70);
                me->set("marks/aoyao_done", 1);
        }
        else 
        {
                message_vision(HIY"һ�ɽ���ζ���˱Ƕ�����\n"NOR, me);
                remove_call_out("do_failed"); 
                call_out("do_failed", 1);
        }
        return;
}
void do_failed()
{
        object me = this_object();
        object *obj;
        int i;
        obj = deep_inventory(me);
        if( !sizeof(obj) )      return;
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        message_vision("��¯����һƬ���ڣ�$Nʲô��ҩҲû��������\n", me);
        remove_call_out("do_ready");
        remove_call_out("do_confirm");
        me->delete("marks/aoyao_done");
        me->delete("marks/aoyao");
        me->delete("marks/open");
        me->delete("marks/fired");
        me->delete("marks/doing");
        me->delete("liquid/remaining");
        me->delete("liquid/name");
        me->delete("marks/burned");
        return;
}

int do_aoyao(string arg)
{
    object me, ob;
    me = this_object();
    ob = this_player();

    if( ob->is_busy() ) 
            return notify_fail("����æ���ء�\n");

    if( ob->is_fighting() )
            return notify_fail("������ս���С�\n");

    if( me->query("marks/open")) 
            return notify_fail("��¯�ĸ���û�иǺá�\n");

    if( !me->query("marks/burned") ) 
            return notify_fail("���ƻ�����ʢ��\n");               

    message_vision(HIY"\n$Nʹ��ȫ������������ϵĽ��赤¯�ڵ�ҩ�����۵������Ǻ���\n"NOR, ob);
    me->set("marks/aoyao", 1);
    ob->start_busy(2);
    return 1;
}

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
        if( !me->query("marks/aoyao_done") )
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
        ob->start_busy(4);
        return 1;

}

void do_drug()
{
        int a, b, i, c, d, e;
        object *inv;
        object me = this_object();
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
                        if( inv[i]->query("id") == "qixing haitang")
                        {
                                a = a+1;
                         }
                        if( inv[i]->query("id") == "lanse yaohua")
                        {
                                b = b+1;
                         }
                        if( inv[i]->query("id") == "zang honghua")
                        {
                                c = c+1;
                         }
                        if( inv[i]->query("id") == "jinyin hua")
                        {
                                d = d+1;
                         }
                        if( inv[i]->query("id") == "ren shen")
                        {
                                e = e+1;
                         }
                }

// ok
                if( a>= 1   
                && b >= 1
                && c >= 1
                && d >= 1
                && e >= 1 )
                {
                 remove_call_out("do_ok");
                 call_out("do_ok", 0);
                }
                else
                {
                remove_call_out("do_failed"); 
                call_out("do_failed", 1);
                }
        }
        return;
}

void do_ok()
{       
        object me = this_object();
        object jieyao;
        object *obj;
        int i;
        obj = deep_inventory(me);
        if( !sizeof(obj) )      return;
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        me->delete("liquid/remaining");
        me->delete("liquid/name");   
        jieyao=new("/d/miaojiang/npc/obj/jieyao");
        jieyao->move(me);
        return;
}
int do_qu(string arg)
{
        string arg1, arg2;
        object obj, *inv, env, obj2;
        object me = this_object();
        object ob = this_player();
        int i, amount;
        if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
                return notify_fail("����û������������\n");

        if (arg2!="lu")
                return notify_fail("����û������������\n");

        if( !me->query("marks/open") )
        return notify_fail("��¯�ĸ���û�д򿪡�\n");
                
        if( ob->is_busy() )
                return notify_fail("������æ��\n");

        if( sscanf(arg, "%s from %s", arg, arg1)==2 ) {
                env = present(arg1, ob);
                if(!env) env = present(arg1, environment(ob));
                if(!env) return notify_fail("���Ҳ��� " + arg1 + " ����������\n");
                if(living(env) && (wiz_level(me) <= wiz_level(env)))
                        return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
        } else env = environment(ob);
        if (!wizardp(me) && env->query("no_get_arg1"))
                return notify_fail("���컯�յ������ٰ���\n");

        if(sscanf(arg, "%d %s", amount, arg1)==2) {
                if( !objectp(obj = present(arg1, env)) )
                        return notify_fail("����û������������\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
                if( amount < 1 )
                        return notify_fail("�����ĸ���������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("����û����ô���" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() ) {
                        return do_haha(ob, obj);
                } else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount( obj->query_amount() - amount);
                        obj->set_amount( amount );

                        if( ob->is_fighting() ) ob->start_busy(3);
                        if (do_haha(ob, obj)) {
                                obj2->move(env);
                                return 1;
                        }
                        obj2->move(env);
                        return 0;
                }
        }

        if(arg=="all") {
                if( ob->is_fighting() ) return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
                if( !env->query_max_encumbrance() )     return notify_fail("�ǲ���������\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("������û���κζ�����\n");

                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        do_haha(ob, inv[i]);
                }
                write("Ok��\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || living(obj) )
                return notify_fail("�㸽��û������������\n");

        if( !wizardp(ob) && obj->query("no_get") && obj->query("id")!="jie yao") {
                if (stringp(obj->query("no_get")))
                        return notify_fail(obj->query("no_get"));
                return notify_fail("��������ò�������\n");
        }
        
        return do_haha(ob, obj);
}
        
int do_haha(object ob, object obj)
{
        object old_env;
        int equipped;

        if( !obj ) return 0;
        old_env = environment(obj);

        if( obj->is_character() ) {
                if( living(obj) ) return 0;
        } else {
                if( !wizardp(ob) && obj->query("no_get") && obj->query("id")!="jie yao") return 0;
        }

        if( obj->query("equipped") ) equipped = 1;
        if( obj->move(ob) ) {
                if( ob->is_fighting() ) ob->start_busy(1);
                if( obj->is_character() )
                        message_vision( "$N��$n�����������ڱ��ϡ�\n", ob, obj );
                else
                        message_vision( sprintf("$N%sһ%s$n��\n", 
                                old_env==environment(ob)? "����":
                                        (old_env->is_character() ?
                                                "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"):
                                                "��" + old_env->name() + "���ó�"),
                                obj->query("unit")), ob, obj);
                ob->start_busy(9);
                  if(obj->query("id")=="jie yao") obj->set("owner",ob->query("id"));
                return 1;
        }
        else return 0;
}
