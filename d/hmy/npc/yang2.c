// yang.c 
// Modified by Numa 19991024

#include <ansi.h>
inherit NPC;
#include "hmy_def.c"

void create()
{
        set_name("����ͤ", ({ "yang lianting", "yang",}));
        set("long", "�������ο��࣬�������룬��ò��Ϊ�۽�
���䣬�������鸡�����������ڹ���\n");
        set("title",HIY"�������  �ܹ�"NOR);
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 22);
        set("con", 21);
        set("dex", 19);
        
        set("max_qi", 1800);
	set("qi", 1800);
	set("jing", 1300);
        set("max_jing", 1300);
        set("neili", 2000);
        set("max_neili", 2000);
	set("eff_jingli", 1200);
	set("jingli", 1200);

        set("jiali", 50);
        set("combat_exp", 600000);
        set("shen", -5000);

	set_temp("apply/attack", 40);
	set_temp("apply/strength", 40);
	set_temp("apply/defence", 40);
	set_temp("apply/dexerity", 40);

        set_skill("tianmo-jian",170);
	set_skill("parry", 170);
	set_skill("sword", 170);
        set_skill("dodge",170);
	set_skill("ding-dodge", 170);
	set_skill("force", 170);
	set_skill("tianmo-gong", 170);

        map_skill("sword", "tianmo-jian");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
	map_skill("parry", "tianmo-jian");
        setup();
 
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();        

}

void init()
{
        object ob;
        
        ::init();
        
        if( interactive(ob = this_player()) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object me = this_object();
        
        if (!ob || !present(ob, environment())) return;
// �ж� player        
        if (ob->query("hostage/totwo")
        &&  me->query_temp("target") == ob->query("id"))
        {
                message_vision(CYN"$n����$N�󺰣���"+ RANK_D->query_rude(ob) +"�����������ʲô����\n"NOR,ob,me);
                command("look " + ob->query("id"));
                ob->start_busy(random(2));
                remove_call_out("do_kill");
                call_out("do_kill", 0, me, ob);
        }
        else if (ob->query("hostage/totwo")
        &&  me->query_temp("target2") == ob->query("id"))
        {
                command("look " + ob->query("id"));
                command("shout " + ob->query("id"));
                ob->start_busy(random(2));
                remove_call_out("do_kill2");
                call_out("do_kill2", 0, me, ob);
        }
}

int do_kill(object me,object ob)
{
// kill player        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, ob);
        return 1;
}

int do_kill2(object me,object ob)
{
// kill player        
        remove_call_out("kill_ob");
        call_out("checking",1,me,ob);
        call_out("kill_ob", 0, ob);
        return 1;
}

int checking(object me, object ob)
{
	object room,npc;
        int my_max_qi,his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");
        if (me->is_fighting())
        {
                call_out("checking",1, me, ob);
                return 1;
        }
        if ( !present(ob, environment()) )
        	return 1; 
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
		tell_room(environment(me),"����ͤһ����ͷ���ԣ�ת���������ߵ�С���·��ȥ��\n");
		message_vision("$NҲ����׷����ȥ��\n",ob);
            	if (me->query("block_msg/all")>0)
            	{
            		me->remove_call_out("revive");
            		me->revive();
            		me->reincarnate();
            	}
         	room = load_object(__HMY__"xiaoshe");
         	me->move(room);
         	ob->move(room);
         	tell_room(room,CYN"�������ܼ������������ܣ��㡭���㡭����ô�ˣ���������������𣿡�\n"NOR);
         	tell_room(room,"�������ܴ��������һ���̳�����������������ͤ��ȥ��ͷ�ĺ�ˮ�����ۡ�\n");
         	tell_room(room,CYN"����ͤŭ��������е�ǰ���������������������ô�����ܴ򷢵��˵��ˣ��ٸ������Ȳ��١���\n"NOR);
         	tell_room(room,CYN"��������΢Ц�������ǣ��ǣ��������������ʹ���������ǲ��ǣ���������ۡ���\n"NOR);
         	call_other(npc,(: do_kill :),npc,ob);
            	return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                message_vision(CYN"$N���˿�$n��˵������Ĺ���ϡ��ƽ������Ȼ���ҵ���ľ������Ұ��\n"NOR, me,ob);
                return 1;
        }
        return 1;
}

int accept_fight(object ob)
{
        command("say " + RANK_D->query_rude(ob) + "���������Ұ��¡�");
        return 0;
}

void die()
{
        object ob = this_object(),me;
        object obj;
        
        me = query_temp("last_damage_from");

        if (me->query("id") != ob->query_temp("target"))
        {
                ob->revive(1);
                command("say �ã���Ȼ����" + me->name(1) + "���㣬ɱ���ң���Ҳ�ò���Կ���ˣ�");
                destruct(ob);
                return;
        }
        else
        {
        	ob->revive(1);
        	command("say �㲻ɱ�ң������Կ�׿��Ը��㣬���ǽ�����");
		obj = new(__HMY__"obj/key");
		obj->set_temp("owner",me->query("id"));
		obj->move(ob);
		command("give key to " + me->query("id"));
        	command("escape");
       		destruct(ob);
       		return;
	}
	        
        ::die();
}
