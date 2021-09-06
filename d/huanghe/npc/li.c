//Yanqi 08/10/2k
#include <ansi.h>
inherit NPC;

int ask_job();

void create()
{
        set_name("���", ({ "li gonggong", "li", "gonggong" }) );
        set("gender", "����" );
        set("age", 60);
        set("long", "�����ǻ�����ߵ��������������ɫ��̫�ã�����������Ƚϲ��͡�\n");
        set("nickname","�ղ��");
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("shen_type", -1);

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("huashan-jianfa" ,50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 5);
        set_temp("apply/attack", 5); 
        set_temp("apply/defense", 5);
        set("combat_exp", 80000);

        set("attitude", "peaceful");

        set("inquiry", ([
                "job": (: ask_job :)
        ]));

        set("chat_chance", 3);
        set("chat_msg", ({
                "�����ͣ�شߴ��ţ���㣬��㣬�����˳�͢�Ĵ��£�һ��Ҳ�ܲ��ˡ�\n",
                "�������ŭ������˷�����㻹��ϰ��֮�ˣ�\n",
                "�����ͣ��������������˻����������Ͳ��ò��ִ��£�\n",
                }) );
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
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
        add_action("do_task","task"); 
}

int ask_job()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if (me->query_condition("job_busy")){
           command("say ����æ����?");
           return 1;
        }
    
        if( exp1 > 50000 )
        {
                command("consider "+me->query("id"));
                return 1;
        }
    
        if (present("shi kuai", me))
        {
                command("angry "+me->query("id"));
                command("say �������û����ɣ���ô���������");
                return 1;
        }


        if (random(10) > 4 || me->query_temp("newbiejob1/over"))
        {
                message_vision(CYN"�����ݺݵض�$N˵�ĵ���������ҽ��µ����ʯͷ�ᵽ����Ǳ߸������á���ȥ����\n"NOR,me);
                message_vision(HIM"ֻ������׳������һ���ʯ������$N�����ϡ�\n"NOR,me);
                tell_object(me,HIR"��е�˫��һ�������ɵ���������һ������\n"NOR);

                new(__DIR__"obj/shi")->move(me);
                if((me->query("qi")<10) || (me->query("jingli")<20))
                me->unconcious();
                else {
                  me->add("jingli",-10);
                  me->add("qi",-5);
                }
                me->set_temp("newbiejob1/start",1);
                me->start_busy(2+random(6));
                return 1;
        }
        else
        {
                message_vision(CYN"�����Ǹ�ض�$N˵������������ʱû�й����ˣ��ȵȰɡ�\n"NOR,me);
                return 1;
        }
}

void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
       if(ob->query_temp("newbiejob1/start")
        && ob->query_temp("newbiejob1/over") > 7 ){ 
           command("nod " +ob->query("id"));
           command("whisper "+ob->query("id")+" �������ˣ����Ը��Ҹ�����task ok����! ");
           return;
       }
}

int do_task(string arg)
{
        object me;
        int pot,exp,sil;
        
        me=this_player();
        
       if(!( arg || arg=="ok")) return 0;
        
        if (me->query_temp("newbiejob1/start")){ 
            if( me->query_temp("newbiejob1/over") > 4 + random(4)){
                exp = 80+random(me->query_skill("force"))/2;
                pot = exp/5 + random(exp/6);
		sil = me->query_skill("force")/10+random(5);
                me->add("potential",pot);
                if(me->query("potential") > me->query("max_pot"))
                        me->set("potential", me->query("max_pot"));
                me->add("combat_exp",exp);
                me->apply_condition("job_busy",random(4)+3);
                me->delete_temp("newbiejob1");
                tell_object(me,HIW"�㱻�����ˣ�"+chinese_number(exp)+"�㾭���"+chinese_number(pot)+"��Ǳ�ܡ�\n"NOR);
		this_object()->add_money("silver", sil);
		command("give "+me->query("id")+" "+sil+" silver");
                return 1;
            }
            else {
                command("say ��Ű���"+chinese_number(me->query_temp("newbiejob1/over"))+"�ξ���Ҫ���������ٸ��Ҹɻ�ȥ��");
                return 1;
            }
        }
        else {
                command("kick3 "+me->query("id"));
                command("say ����ѽ�����"+me->query("name")+"����ʹ��һ�٣�");
                message_vision(HIR"ֻ������׳�����˹�����һ�ٹ������$N��ͷʹ�ޣ�\n"NOR,me);
                me->delete_temp("newbiejob1");
                me->apply_condition("job_busy",random(4)+3+me->query_condition("job_busy"));
                me->unconcious();
                return 1;
        }
}
