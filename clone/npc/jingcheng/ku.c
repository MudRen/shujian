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
        if (sizeof(team) > 3)
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
//         CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HBMAG+HIW"%s��ӿ�ʼ����Ӫ������", me->name(1)));
        reset_room(sizeof(team));
        for (i = 0;i < sizeof(team);i ++)
        {
                team[i]->delete_temp("was_job");
                team[i]->set_temp("was_job/asked", 1);
                team[i]->set_temp("was_job/num", sizeof(team));
                team[i]->apply_condition("job_busy", 20);
                team[i]->apply_condition("was_job", 90);
                team[i]->apply_condition("was_check",90);
                team[i]->set("job_name", "���¾���");
                team[i]->move("/d/jingcheng/wanan-si/wanan-siyuan");
                tell_object(team[i], HIR"����������ǰ�����ֱ����Ѿ���𣬾�������ü�ޣ�\n"NOR);
        }
        return "ϣ������һ��˳����\n";
}

string ask_finish()
{
        object me = this_player(), *team = me->query_team();
        object xy_letter;
        int i,j,z,exp,shen,pot,SJCredit,gold,gold2,dbexp,ext;
        
        if (!me->query_temp("was_job/asked"))
                        return "��û��ȡ������,��Ҫ�����ҡ�\n";

        if (sizeof(team) != 0 && (team[0]!=me))
		  return "ֻ�ж��������ſ����������\n";

        if (!check_ip(team))
                return "��Ķ��������⣬�����޷��������\n";

        if( !me->query_team() )
{ 
	
              me->delete_temp("was_job");           
	            me->clear_condition("was_check");
	           return "����Լ��Ķ��Ѷ����ˣ����������ʽ�����\n";
             
}
                 
       
        for (i = 0;i < sizeof(team);i ++)
        {
                if (!team[i])
                        continue;
                if (!present(team[i]))
                        return "��ô�����˲�ȫ����" + team[i]->query("name") + "��ôû����\n";
                if (!interactive(team[i]))
                        return "����" + team[i]->query("name") + "�����⣬�������޷��������\n";
                     }
                     
        z = (int)me->query_temp("was_job/num");
        z = 100-z*5;
    if(sizeof(team) != 0){
        if(sizeof(team)==(int)me->query_temp("was_job/num")&&!random(8)){
            write(HIR"\nͻȻ����ͷ�����ĵ�����һ���Ÿ��㣬Ҳ��֪�������ʲô������\n"NOR);
            xy_letter=new("/clone/gift/xyjobletter");
            xy_letter->move(me);
            log_file("job/was", sprintf(HIG"%s(%s)%d������Ӫ������õ��������������ܺ���"NOR,me->name(1),me->query("id"),me->query("job_time/����Ӫ��")));
        }
        for (i = 0;i < sizeof(team);i ++)
        {         
                if (team[i] && team[i]->query_temp("was_job/asked"))
                {	   
		          j = team[i]->query_temp("was_job/floor");
                        exp = (j*450 + (j-1)*j*120 + random(100))*z/250;
                     if(wizardp(me)){
                         write("��ʼ��j="+j+",exp = "+exp+" !\n"NOR);
                     }
                     team[i]->add("combat_exp",exp);
                     pot = exp/4;
		          SJCredit =( j/z+j*4) /10 ;
                     if((int)team[i]->query_temp("was_job/floor")>6)
                         SJCredit = SJCredit;
		          shen = exp/2 + pot/2;
		          gold=80000+random(100000);
		          gold2=gold/10000;
		          team[i]->add("balance",gold);
		          team[i]->apply_condition("job_busy", 5);
		          team[i]->apply_condition("was_job", 30);
		          team[i]->clear_condition("was_check");
		          
		          team[i]->add("job_time/����Ӫ��",1); // �޸�д������ǰ��me->
		          team[i]->set("job_name", "����Ӫ��");
                        tell_object(team[i],sprintf("[43;1m������"+CHINESE_D->chinese_number(exp)+                      
                        "��[1;32m����[43;1m��"+ CHINESE_D->chinese_number(pot)+
                        "��[1;34mǱ��[43;1m�Ľ�����\n"NOR, team[i]));
                        tell_object(team[i],"[43;1m������" + CHINESE_D->chinese_number(gold2) + "���ƽ��[0m\n\n");
			    		team[i]->add( "potential", pot );
		    			team[i]->add("shen", shen );
		    		//	team[i]->add("SJ_Credit", SJCredit );


        if( team[i]->query_condition("db_exp") )     {
		  dbexp = exp/2 + random(exp/2);
     	          team[i]->add("combat_exp", dbexp );
                                                       }
		 

 	if( team[i]->query("relife/exp_ext") ){ 
			ext = team[i]->query("relife/exp_ext");
			team[i]->add("combat_exp", exp* ext /20 );
			                                          }

	
       if( team[i]->query("relife/exp_ext") )     
               tell_object(team[i],HBGRN"����ϸ����������Ӫ�ȵĹ��̣��ֶ���������"+chinese_number(exp*ext/20)+"��ʵս���飡\n"NOR);


	if( team[i]->query_condition("db_exp") )     
		
               tell_object(team[i],HBGRN"˫�����齱���ڼ䣬������������"+chinese_number(dbexp)+"��ʵս���飡\n"NOR);





                                   log_file("job/was", sprintf("%s %s(%s)%d������Ӫ������%d��,�õ�����%d��Ǳ��%d��\n",
                                  ctime(time())[4..19],team[i]->name(1),team[i]->query("id"),(int)team[i]->query("job_time/����Ӫ��"),j,exp,pot));
        }
                                  team[i]->delete_temp("was_job");
			    		
                }
    }
    else{
                if (me->query_temp("was_job/asked")){
                     j = me->query_temp("was_job/floor");
                     exp = (j*300 + (j-1)*j*80 + random(100))*z/250; //update by lsxk@hsbbs 2007/8/14
                     exp=exp/3+random(exp/3+1);
                     me->add("combat_exp",exp);
                     pot = exp/4;
                     SJCredit =1+ random(2);
                     shen = exp/2 + pot/2;
                     me->apply_condition("job_busy", 5);
                     me->apply_condition("was_job", 30);
                     me->clear_condition("was_check");
                     me->add("job_time/����Ӫ��",1); // �޸�д������ǰ��me->
                     me->set("job_name", "����Ӫ��");
                     tell_object(me,sprintf(HIW"������"+CHINESE_D->chinese_number(exp)+
                        "�㾭�飬"+ CHINESE_D->chinese_number(pot)+
                        "��Ǳ�ܵĽ�����\n"NOR, me));
                                   me->add( "potential", pot );
                                   me->add("shen", shen );
                           //        me->add("SJ_Credit", SJCredit );



if( me->query_condition("db_exp") )    { 
		  dbexp = exp/2 + random(exp/2);
     	me->add("combat_exp", dbexp );
               tell_object(me,HBGRN"����ϸ����������Ӫ�ȵĹ��̣��ֶ���������"+chinese_number(exp*ext/20)+"��ʵս���飡\n"NOR);
}
		 

 	if( me->query("relife/exp_ext") ){ 
			ext = me->query("relife/exp_ext");
			me->add("combat_exp", exp* ext /20 );
               tell_object(team[i],HBGRN"˫�����齱���ڼ䣬������������"+chinese_number(dbexp)+"��ʵս���飡\n"NOR);
			                                          }


		




                                   log_file("job/was", sprintf("%s %s(%s)%d������Ӫ������õ�����%d��Ǳ��%d��\n",
                                  ctime(time())[4..19],me->name(1),me->query("id"),(int)me->query("job_time/����Ӫ��"),j,exp,pot));
                                  me->delete_temp("was_job");

                    if(random(4)){
                        write(HIR"\nͻȻ����ͷ�����ĵ�����һ���Ÿ��㣬Ҳ��֪�������ʲô������\n"NOR);
                        xy_letter=new("/clone/gift/xyjobletter");
                        xy_letter->move(me);
                        log_file("job/was", sprintf(HIG"%s(%s)%d������Ӫ������õ��������������ܺ���"NOR,me->name(1),me->query("id"),me->query("job_time/����Ӫ��")));
                    }
          }
    }
        return "��λ�����ˣ��˴������Ѿ���ɣ���ȥ��Ϣ�ɡ�\n";
}

