// yanshang2.c ����ͷ��
//Yanqi 08/11/2k
//������160k������@yeju

#include <ansi.h>
inherit NPC;
int ask_job();

void create()
{
        set_name("����", ({ "yanshang touzi", "touzi", "yanshang" }));
        set("gender", "����");
        set("age", 32+random(20));
        set("long", "�����������̵�ͷ�ӣ��������й��оأ����Ǳ�������ŷ���˽�εĹ�����\n");
        set("combat_exp", 3000);        
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 30);
        set_skill("dodge", 20);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("inquiry", ([
                "job": (: ask_job :)
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
                "���̲�ͣ����������͢���û�䣬���ҵȰ���������棿\n",
        }) );
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
        setup();        
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int ask_job()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if( exp1 < 30000 || exp1 > 160000 )
        {
                command("say ����ǹٸ������Ե׵İɣ�һ�ߴ���ȥ��");
                return 1;
        }
        
        if (me->query_condition("job_busy")) 
        {
                command("say ����æ������������أ�");
                return 1;
        }
                
        me->delete_temp("newbiejob2");       
        me->apply_condition("job_busy",5 + random(5));
        me->set_temp("newbiejob2/start",1);
        
        command("whisper "+me->query("id")+" ����ȥ̩ɽ���µĺ����Ⱥ��ҵĴ�����");
        return 1;
}

void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
       if(ob->query_temp("newbiejob2/start")
        && ob->query_temp("newbiejob2/over")
        && ob->query_temp("newbiejob2/middle"))
       { 
           command("nod " +ob->query("id"));
           command("whisper "+ob->query("id")+" �������ˣ����Ը��Ҹ�����give yanshang yan����! ");
           return;
       }
}

int accept_object(object me, object yan)
{
        int pot,exp;
        
        if (!(me->query_temp("newbiejob2/start")))
                return notify_fail("��û����������Ҫ����ѽ��\n");
                
        if (!(me->query_temp("newbiejob2/middle")))
                return notify_fail("����ô��û��ȥ��̲��\n");

        if ( yan->query("id") != "yan ba") 
                return notify_fail("�����������𰡣�");

        if (me->query_temp("newbiejob2/over"))
        {
                pot =30 + random(15);
                exp = pot*3+random(me->query("age",1));
                pot = exp/5 + random(exp/10);
                me->add("potential",pot);
                me->add("job_time/����",1);
                if(me->query("potential") > me->query("max_pot"))
                        me->set("potential", me->query("max_pot"));
                me->add("combat_exp",exp);
                me->delete_temp("newbiejob2");
                call_out("destroying", 1, yan);
                tell_object(me,HIW"�㱻�����ˣ�"+chinese_number(exp)+"�㾭���"+chinese_number(pot)+"��Ǳ�ܡ�\n"NOR);
                return 1;
        }
        else
        {
                message_vision("����ѽ�����"+me->query("name")+"����ʹ��һ�٣�Ҳ������������ү�ҵ����š�\n",me);
                message_vision("ֻ�����������µĴ����˹�����һ��ȭ�Ŵ��$N���˹�ȥ��\n"NOR,me);
                me->delete_temp("newbiejob2");
                me->apply_condition("job_busy", 4);
                call_out("destroying", 1, yan);
                me->unconcious();
                return 1;
        }
}

void destroying(object yan)
{
        if(!yan) return;
        destruct(yan);
}
