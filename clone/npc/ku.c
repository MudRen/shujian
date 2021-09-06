#include <ansi.h>
#include <job_mul.h>
inherit NPC;
string ask_job();
string ask_finish();
void create()
{
        set_name("��ͷ��",({"ku toutuo", "ku"}));
        set("long", "һ�����������ͷ�ӣ���Ŀ�ΰ������������˵Ķ��ǵ��̣�������ò��ȫ���ɱ档\n");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -10000);
        set("str", 26);
        set("per", 28);
        set("int", 29);
        set("con", 27);
        set("dex", 30);
        set("max_qi", 3500);
        set("max_jing", 2200);
        set("eff_jingli", 2500);
        set("jiali", 80);
        set("combat_exp", 1500000);
        set("unique", 1);

        set_skill("sword",170);
        set_skill("dodge",170);
        set_skill("force", 170);
        set_skill("blade",170);
        set_skill("literate",150);
        set_skill("hand",170);
        set_skill("strike",170);
        set_skill("hanbing-mianzhang",170);
        set_skill("yingzhua-shou",170);
        set_skill("piaoyi-shenfa", 170);
        set_skill("shenghuo-shengong", 170);
        set_skill("lieyan-dao",170);
        set_skill("liehuo-jian",170);
        set_skill("parry", 170);

        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("sword", "liehuo-jian");
        map_skill("parry", "liehuo-jian");
        map_skill("blade", "lieyan-dao");
        map_skill("hand", "yingzhua-shou");
        map_skill("strike", "hanbing-mianzhang");
        prepare_skill("strike", "hanbing-mianzhang");
        prepare_skill("hand","yingzhua-shou");

        set("inquiry", ([
                 "Ӫ��" : (: ask_job :),
                 "����" : (: ask_finish :),
        ]));
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object("/d/mingjiao/obj/white-cloth")->wear();
}

int check_ip(object *team)
{
        int i, j;
        for (i = 0;i < sizeof(team);i ++)
                for (j = i + 1;j < sizeof(team);j ++)
                        if (team[i] && query_ip_number(team[i]) == query_ip_number(team[j]))
                                return 0;
        return 1;
}
void reset_room(int num)
{
        int i;
        for (i = 1;i <= 13;i ++)
        {
                "/cmds/app/update"->main(this_object(), "/d/jingcheng/wanan-si/baota-" + i);
                ("/d/jingcheng/wanan-si/baota-" + i)->setup_shouwei(num + random(3));
        }
}

string ask_job()
{
        object me = this_player(), *team = me->query_team();
        int i, max, min, total = 0;
        object ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
        
        foreach (object user in ob_list)
                if (user->query_temp("was_job"))
                        return "�������������ھ��ˣ����ʹ���ˡ�\n";
        if (sizeof(team) < 2)
                return "����֮��ʮ��Σ�գ���ƾһ��֮�����²���ʤ�Ρ�\n";
        if (sizeof(team) > 5)
                return "�����ڷ��ؼ������ܣ�����̫������ױ�¶��\n";
        if (team[0] != me) 
                return "ֻ�ж��������ſ��Դ��Ӿ��ˡ�\n";
        if (!check_ip(team))
                return "��Ķ��������⣬�޷���������\n";
                
        max = min = me->query("combat_exp");
        for (i = 0;i < sizeof(team);i ++)
        {
                if (!team[i])
                        return "��Ķ�����������⣬���ɢ�������齨��";
                if (!present(team[i]))
                        return "��ô�����˲�ȫ����" + team[i]->query("name") + "��ôû����\n";
                if (team[i]->query("combat_exp") < 2000000)
                        return "����֮��ʮ��Σ�գ�" + team[i]->query("name") + "���²���ʤ�Ρ�\n";
                if (team[i]->query_condition("was_job"))
                        return "������е�" + team[i]->query("name") + "�Ѿ�ʮ�����࣬�������˰ɡ�\n";
                if (me == team[i])
                        continue;
                if (!interactive(team[i]))
                        return "�㻹�ǽ�" + team[i]->query("name") + "���������˰ɡ�\n";
                total += team[i]->query("combat_exp");
                if (team[i]->query("combat_exp") > max)
                        max = team[i]->query("combat_exp"); 
                if (team[i]->query("combat_exp") < min)
                        min = team[i]->query("combat_exp");
        }
        if ((total < 1000000))
                return "����֮��ʮ��Σ�գ��������ǲ���ʤ�Ρ�\n";
        if (min / (max / 100) < 80)
                return "����֮��ʮ��Σ�գ����ǵĲ��̫���ˡ�\n";
        
        command("say ����ʮ��Σ�գ����С�ģ�");
        reset_room(sizeof(team));
        for (i = 0;i < sizeof(team);i ++)
        {
                team[i]->delete_temp("was_job");
                team[i]->set_temp("was_job/asked", 1);
                team[i]->set_temp("was_job/num", sizeof(team));
                team[i]->apply_condition("job_busy", 20);
                team[i]->apply_condition("was_job", 20);
                team[i]->set("job_name", "���¾���");
                team[i]->move("/d/jingcheng/wanan-si/wanan-siyuan");
                tell_object(team[i], HIR"����������ǰ�����ֱ����Ѿ���𣬾�������ü�ޣ�\n"NOR);
        }
        return "ϣ������һ��˳����\n";
}

string ask_finish()
{
        object me = this_player(), *team = me->query_team();
        int i,j,z,exp,shen,pot,SJCredit;
        
        if (team[0] != me) 
                return "ֻ�ж��������ſ����������\n";
                
        if (!check_ip(team))
                return "��Ķ��������⣬�����޷��������\n";
       
        for (i = 0;i < sizeof(team);i ++)
        {
                if (!team[i])
                        continue;
                if (!present(team[i]))
                        return "��ô�����˲�ȫ����" + team[i]->query("name") + "��ôû����\n";
                if (!interactive(team[i]))
                        return "����" + team[i]->query("name") + "�����⣬�������޷��������\n";
        }
        for (i = 0;i < sizeof(team);i ++)
        {         

                if (team[i] && team[i]->query_temp("was_job/asked"))
                {	   
		          j = team[i]->query_temp("was_job/floor");
		          z = sizeof(team);
		          exp = j*200/z; // ����npc�����͡���߽���
		          exp = team[i]->add_exp_combat(exp,"��ͷ��","����Ӫ��");
		          pot = exp/3+random(exp/10);
		          SJCredit = 0;
		          shen = exp/2 + pot/2;
		          team[i]->apply_condition("job_busy", 5);
		          team[i]->apply_condition("was_job", 90);
		          team[i]->add("job_time/����Ӫ��",1); // �޸�д������ǰ��me->
		          team[i]->set("job_name", "����Ӫ��");
                        tell_object(team[i],sprintf(HIW"������"+CHINESE_D->chinese_number(exp)+                      
                        "�㾭�飬"+ CHINESE_D->chinese_number(pot)+
                        "��Ǳ�ܵĽ�����\n"NOR, team[i]));

			    		team[i]->add( "potential", pot );
		    			team[i]->add("shen", shen );
		   			team[i]->add("SJ_Credit", SJCredit );
		    			log_file("job/was", sprintf("%s %s(%s)%d������Ӫ������õ�����%d��Ǳ��%d��ͨ��%d��\n",
                                  ctime(time())[4..19],team[i]->name(1),team[i]->query("id"),(int)team[i]->query("job_time/����Ӫ��"),exp,pot,SJCredit));
        }
                                  team[i]->delete_temp("was_job");
			    		
                }
        return "��λ�����ˣ��˴������Ѿ���ɣ���ȥ��Ϣ�ɡ�\n";
}

