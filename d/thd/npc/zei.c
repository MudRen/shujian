// NPC: daomu-one.c
// Created by Numa 19990914

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"
#include "r_obj.h"

void create()
{
        object armor;
        set_name("��Ĺ��", ({ "daomu zei", "daomu", "zei" }) );
        set("gender", "����");
        set("age", 25+random(15));
        set("long","��һ�յ�Ĺ�ɹ�,�۵���ͷ��,�����β�ס��Ĺ�ɹ���ϲ�á�\n");
        set("shen", -100);
        set("str", 25+random(5));
        set("int",30+random(5));
        set("con",30+random(5));
        set("dex",30+random(5));
        set("combat_exp", 1500000);

        set("shen_type", -1);
        set("attitude", "peaceful");
        set("max_qi",8200);
        set("max_jing",8200);
        set("neili",8000);
        set("eff_jingli", 3000);
        set("jiali", 100);
        set("max_neili",8000);
        set("score", 10000);
	set("no_quest", 1);
	
	set_skill("force", 100); 
        set_skill("dodge", 100);
        set_skill("parry", 100);

        setup();
        if (clonep()){
		armor = new(ARMOR_D("cloth"));
		armor->move(this_object());
		armor->wear();
        }
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
        
        if (ob->query_temp("thd/dojob"))
        {
// �ж� player
        if (me->query_temp("target")!=ob->query("id"))
                {
                        command("look " + ob->query("id"));
                        say( "��Ĺ���޺޵����: �ղ���С��������ȥ�ˣ�!\n");
                        say( "��Ĺ������ææ�뿪�ˡ�\n");
                        destruct(me);
                        return;
                }
                if (!me->query_temp("skillset"))
                {
                        say( "��Ĺ�������㡸�ٺ١�Ц������,˵���������" + RANK_D->query_rude(ob)
                                        + "����Ȼ���㷢����,���ҾͲ������ˡ�\n");
                        ob->start_busy(random(2));
                        remove_call_out("dest");
                        call_out("dest",300, ob);
                        remove_call_out("do_kill");
                        call_out("do_kill", 0, me, ob);
                }
                else
                {
                        say ( "��Ĺ���ݺݵĵ����㣬��У����ܣ����У�\n");
                        remove_call_out("dest");
                        call_out("dest",300, ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 0, ob);
                }
        }
        else
        {
                command("look " + ob->query("id"));
                say( "��Ĺ���޺޵����: ��Ȼ����������,ֻ���´�������!\n");
                destruct(me);
        }
}

int do_kill(object me,object ob)
{
        object clone_obj;
        mapping killerskill1;
        int number,number_t,k_qi,k_neili,k_jing, j, k;
        string t_force,t_dodge,t_obj;
        number = (int)ob->query("max_pot");
        number = number - 100;
        k_qi = (int)ob->query("max_qi") + random((int)ob->query("max_qi") / 20 + 20);
        k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili") + random((int)ob->query("max_qi") / 20 + 20);
        j = (int)ob->query("dex");
        k = (int)ob->query("str");

        killerskill1 = skill2[random(sizeof(skill2))];
        number = (int)(number + random(5) - random(10));

//add log to /log/thdjob
        if (number > ((int)ob->query("max_pot")-100))   
	log_file("job/taohua",sprintf("%8s%-10s��Ĺ���񣬵�Ĺ���ȼ���%3d�����˵ȼ���%3d��\n",
		ob->name(1), "("+ob->query("id")+")",number,(int)ob->query("max_pot")-100), ob);

//add by river 
        if( ob->query("thdjob") < 200 ){
		me->set("dex", ob->query("dex"));
		me->set("str", ob->query("str"));
		me->set("con", ob->query("con"));
        }

//set killer's skill
        t_force = k_force[random(sizeof(k_force))];
        t_dodge = k_dodge[random(sizeof(k_dodge))];       
        me->set_skill("force",number_t + random(5));
        me->set_skill("dodge",number_t + random(5));
        me->set_skill("parry",number_t + random(5));
        me->set_skill(t_force,number_t + random(5));
        me->set_skill(t_dodge,number_t + random(5));
        me->set_skill(killerskill1["t_skill"],number_t + random(5));
        me->set_skill(killerskill1["b_skill"],number_t + random(5));
// set killer's  skill maps
        me->map_skill("force",t_force);
        me->map_skill("dodge",t_dodge);
        me->map_skill("parry",killerskill1["t_skill"]);
        me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
// set killer's skill prepares
        me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
// copy entire dbase values
        me->set("max_qi",k_qi);
        me->set("eff_qi",k_qi);
        me->set("qi",k_qi);
        me->set("max_jing",k_jing);
        me->set("eff_jing",k_jing);
        me->set("jing",k_jing);
        me->set("max_neili",k_neili);
        me->set("neili",k_neili);
        me->set("jiali", k_neili / 40);
        me->set("combat_exp",ob->query("combat_exp")* 7/6);
        me->set_temp("skillset",1);
// call random object in Npc
        t_obj = r_obj[random(sizeof(r_obj))];
        clone_obj = new(__DIR__"obj/" + t_obj );
        clone_obj->set_temp("thdjob",ob->query("id"));
        clone_obj->move(me);
        
// kill player        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, ob);
        return 1;
}

void dest(object ob)
{
        object me;
        me = this_object();
	if (ob) {
		tell_object(ob, me->query("name")+"ͻȻ�����µ�����ѽ�������������ﶷ�ˣ��������а���˿ɾͲ������ˣ�\n");  
		tell_object(ob, me->query("name")+"����ææ�뿪�ˡ�\n");
		ob->delete_temp("thd/dojob");
	}
        destruct(me);
}
