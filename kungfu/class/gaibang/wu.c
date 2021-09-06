// wu.c by snowman@SJ ؤ���ⳤ��
// Modify by Looklove@SJ 2000/8/30
// Last change by Looklove add a log_file 2000/9/1
// add by tangfeng@SJ 2004

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

string ask_job(string arg);
string ask_fangqi();
string ask_gonglao(object who);
int ask_jiuyuan();
int ask_xiaofeng();
int ask_jingbian();
int ask_buzhu();
void change_jobtime(string arg, object me);
void create()
{
	set_name("�ⳤ��", ({"wu zhanglao", "wu", "zhanglao"}));
        set("title", HIW"ؤ��Ŵ�����"NOR);
        set("gb/bags",9);
        set("gender", "����");
        set_max_encumbrance(1000000);
        set("age", 55);
        set("long", "����ؤ��������֮һ,��ʹһ�ѹ�ͷ����\n");
        set("attitude", "friendly");
        set("no_get", "�ⳤ�϶������̫���ˡ�\n");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("job_npc", 1);
	      set("unique", 1);
        set("no_bark",1);
        set("per", 21);

        set("qi", 2600);
        set("max_qi", 2600);
        set("jing", 1400);
        set("max_jing", 1400);
        set("eff_jingli", 2400);
        set("neili", 2600);
        set("max_neili", 2600);
        set("jiali", 100);

        set("combat_exp", 600000);

        set_skill("force", 120); // �����ڹ�
        set_skill("checking",120);
        set_skill("huntian-qigong", 120); // ��������
        set_skill("dodge", 120); // ��������
        set_skill("xiaoyaoyou", 120); // ǧ������
        set_skill("parry", 120); // �����м�
        set_skill("blade", 120);
        set_skill("liuhe-daofa",120);
        set_skill("begging", 90);
        set_skill("suohou-shou",140);
        set_skill("hand",130);

        map_skill("blade","liuhe-daofa");
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry","liuhe-daofa");
        map_skill("hand","suohou-shou");
        prepare_skill("hand","suohou-shou");

        create_family("ؤ��", 18, "�Ŵ�����");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "��ͷ���" : "���ﲻ�Ǻ���ᣬûʲô��ͷ��磡\n",
                "����" : "�����������֣�\n",
                "���߹�" : "��ָ��ؤ�����˼���������ؤ�������\n",
                "����" : "���ڰ�������ָ��ؤ���߹���\n",
                "name" : "�����ⳤ�硣\n",
                "job"  : (: ask_job :),
                "����"  : (: ask_gonglao :),
                "������"  : (: ask_fangqi :),
                "fangqi"  : (: ask_fangqi :),
                "����"  : (: ask_fangqi :),
				"����"  : (: ask_buzhu :),//for hs dizi ����gb job ����
		            "��Ԯ����" : (: ask_jiuyuan :),
		            "�������" : (: ask_jiuyuan :),
		            "Ԯ������" : (: ask_jiuyuan :),
	            
		            "��Ԯ" : (: ask_jiuyuan :),
		            "���" : (: ask_jiuyuan :),
		            "Ԯ��" : (: ask_jiuyuan :),
		            "����" : (: ask_xiaofeng :),
		            "���־���" : (: ask_jingbian :),
		            "ؤ������" : (: ask_jingbian :),
		            "ؤ�ﾪ��" : (: ask_jingbian :),

                "��������" : "�����ҵ�С���ӣ����𿼺����ĺú���\n",
        ]));
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object("/kungfu/class/gaibang/obj/gb_budai9")->wear();
}

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
		reincarnate();
}
int ask_buzhu()
{
	object me = this_player();
	int i = me->query("job_time/ؤ��");    
    if(!me->query("from_site")||me->query("from_site")!="LN")
	{
		command("shake");
		command("say �㲻��LNվת�����ģ��������ܷ���");
		return 1;
	}
	if(me->query("family/family_name")!="��ɽ��")
	{
		command("smile");
		command("say ֻ����ɽ�ɵ�GG MM�����ӵ����������");
		command("pat "+me->query("id"));
		return 1;
	}
	if(me->query("combat_exp")<2000000)
	{
		command("shrug");
		command("say �㻹�Ǽӽ�����ȥ�ɡ�");
		command("pat "+me->query("id"));
		return 1;
	}
	if(me->query("job_time/add_gbjob_for_ln")>=3)
	{
		command("shake");
		command("say �����ֻ��ѯ���������Ρ�");
		message_vision(HIR"$N�߾�˫�ִ�ȣ��񰡣�\n"NOR+
                 "\n" HIW
                 "�Ⱦ��Ұɣ�һ������\n"
                 "\n" BLU
                 "         --------\n" HIC
                 "               /\n"
                 "              /\n"
                 "             /\n"
                 "             ----\n"
                 "                /\n"
                 "               /\n"
                 "              /\n"NOR+		
			    "��������$n�����ϣ�\n"NOR,this_object(),me);
		command("hehe "+me->query("id"));
		return 1;
	}
	command("nod");
	if(!i)	message_vision(CYN"$N�ͳ�һ�����ӷ��˷�����ֵؿ��˿�$n��ָ�������ī����$n˵�����㾹Ȼһ�μǹ�Ҳû�С�\n"NOR,this_object(),me);
	else message_vision(CYN"$N�ͳ�һ�����ӷ��˷���ָ�������ī����$n˵������Ŀǰ�Ѽǹ�" + chinese_number(i) + "�Ρ�\n"NOR,this_object(),me);
	if(!me->query("job_time/add_gbjob_for_ln"))
	{
		command("hehe");
		command("say "+HIR"�㾹Ȼ��������վת�����ģ��͸������ӵ�ɡ���һѯ�ʿ����������һ�ٴ�ؤ�����������"NOR);
	}
	else if(me->query("job_time/add_gbjob_for_ln")==1)
	{
		command("say �㻹��Ҫ���ӣ��ð�");
		command("say "+HIR"����Ҫע����ǣ���Ȼ����ѯ�ʿ��Ը���������ʮ��ؤ�������������Ҳͬʱ��ʧ��ʮ��㾭��ֵ��"NOR);
	}
	else
	{
		command("oh");
		command("say �㻹��Ҫ���ӣ��ð�");
		command("say "+HIR"����Ҫע����ǣ���Ȼ����ѯ�ʿ��Ը���������ʮ��ؤ�������������Ҳͬʱ��ʧ��ʮ��㾭��ֵ��"NOR);
	}
	command("say "+HIW"��Ҫ��ȷ�Ͼ�ѡ��Yes��Y�� Ҫ�Ƿ���ѡ��No��N�� --------"NOR);
	input_to( (: change_jobtime :), me );
	return 1;
}
void change_jobtime(string arg, object me)
{
	int i = me->query("job_time/ؤ��");    
	if( arg == "N" || arg == "n" )    
	{
		command("hehe");
		command("say ���Ұ�˵......");
		command("shrug");
		return;
	}
	if(arg != "Y"  && arg != "y" ) 
	{
	   command("?");
	   if(!me->query("job_time/add_gbjob_for_ln"))
	   {
		   command("say "+HIR"��һѯ�ʿ����������һ�ٴ�ؤ�����������"NOR);
	   }
	   else if(me->query("job_time/add_gbjob_for_ln")==1)
	   {
		   command("say "+HIR"��Ȼ����ѯ�ʿ��Ը���������ʮ��ؤ�������������Ҳͬʱ��ʧ��ʮ��㾭��ֵ��"NOR);
	   }
	   else
	   {
		   command("say "+HIR"��Ȼ����ѯ�ʿ��Ը���������ʮ��ؤ�������������Ҳͬʱ��ʧ��ʮ��㾭��ֵ��"NOR);
	   }
	   command("say "+HIW"��Ҫ��ȷ�Ͼ�ѡ��Yes��Y�� Ҫ�Ƿ���ѡ��No��N�� --------"NOR);
	   input_to( (: change_jobtime :), me );
	   return;
	}
 
 	if(!me->query("job_time/add_gbjob_for_ln"))
	{
		command("nod");
		i=i+100;
		message_vision(CYN"$N���˿���ĭ��Ĩȥԭ���ĺۼ�������һ������ˮ�ʣ�һ��дһ�߶�$n˵������Ŀǰ�Ѽǹ�" + chinese_number(i) + "���ˡ�\n"NOR,this_object(),me);
		command("hehe");
		
		command("say ��Ҫ��Ը�⣬������ѯ�ʵģ���������Ҫ���������....");
		log_file("job/add_gbjob", sprintf("%s(%s)��һ������ؤ����������100�Ρ����飺%d��\n", me->name(1),me->query("id"),me->query("combat_exp")) ); 
	}
	else if(me->query("job_time/add_gbjob_for_ln")==1)
	{
		i=i+50;
		message_vision(HIY"$N�߾�˫�ִ�ȣ��񰡣�\n"NOR+
                 "\n" HIW
                 "�Ⱦ��Ұɣ�һ������\n"
                 "\n" BLU
                 "         --------\n" HIC
                 "               /\n"
                 "              /\n"
                 "             /\n"
                 "             ----\n"
                 "                /\n"
                 "               /\n"
                 "              /\n"NOR+		
			    "��������$n�����ϣ�\n"NOR,this_object(),me);
		message_vision(HIY"$n����ð��˿˿���̣������ܸо����Ǻ������\n"NOR,this_object(),me);
		me->add("combat_exp",-200000);//200K�Ĵ���?
		message_vision(CYN"$N�ٺ����������˿���ĭ��Ĩȥԭ���ĺۼ���һ��дһ�߶�$n˵�������˺��ˣ���Ŀǰ�Ѽǹ�" + chinese_number(i) + "���ˡ�\n"NOR,this_object(),me);
		command("hehe");
		command("say ���Ѿ���ʧ200K���飬��Ҫ��Ը�⣬������ѯ�ʵģ���������Ҫ���������....");
		log_file("job/add_gbjob", sprintf("%s(%s)�ڶ�������ؤ����������50�Σ������پ���200K����ǰ���飺%d��\n", me->name(1),me->query("id"),me->query("combat_exp")) ); 
	}
	else
	{
		i=i+60;
		message_vision(HIR"$N�߾�˫�ִ�ȣ��񰡣�\n"NOR+
                 "\n" HIW
                 "�Ⱦ��Ұɣ�һ������\n"
                 "\n" BLU
                 "         --------\n" HIC
                 "               /\n"
                 "              /\n"
                 "             /\n"
                 "             ----\n"
                 "                /\n"
                 "               /\n"
                 "              /\n"NOR+		
			    "��������$n�����ϣ�\n"NOR,this_object(),me);
		message_vision(HIR"$n����ð��˿˿���̣������ܸо����Ǻ������\n"NOR,this_object(),me);
		me->add("combat_exp",-300000);//300K�Ĵ���?
		message_vision(CYN"$N�ٺ����������˿���ĭ��Ĩȥԭ���ĺۼ���һ��дһ�߶�$n˵�������˺��ˣ���Ŀǰ�Ѽǹ�" + chinese_number(i) + "���ˡ�\n"NOR,this_object(),me);
		command("hehe");
		log_file("job/add_gbjob", sprintf("%s(%s)����������ؤ����������60�Σ������پ���300K����ǰ���飺%d��\n", me->name(1),me->query("id"),me->query("combat_exp")) ); 
	}
	me->add("job_time/add_gbjob_for_ln",1);
	me->set("job_time/ؤ��",i);
	return;
}
string ask_job(string arg)
{
	object player, me;
	mapping quest;

	player = this_player();
	me = this_object();

	if (!player->query("gb_pass"))
		return "��û��ͨ���������ӵĿ��飬�ҿɲ������㡣";

	if(player->query("job_time/ؤ��") > 10000)
		return "���Ѿ�Ϊ��ؤ�����������ô��Σ�����ʵ�ڲ����ķ��������ˡ�";

	if(player->query("combat_exp") < 100000 && player->query("family/family_name")!="ؤ��" )
		return "���ʵս����̫�ͣ�������Ŭ��һ����������ѡ�";

	if(player->query("combat_exp") > 4000000)
		return "������ô�ߵ����֣�Ҫ����������ʧ������ݣ��������˰ɡ�";

	if(player->query("job_name") =="ؤ��")
		return "����������û�и����������ȥ�����ط������ɣ�";

	if(player->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
		return "����������û�и���������㻹���ȴ����������������˵�ɡ�";

	//if(player->query("shen") < 1000)
	//	return RANK_D->query_respect(player) + "�����������������޷������������������";

	if( player->query_temp("gb_wait_job") >= 5 ){
		command("say ������ǲ�����ţ�����Ȼ�����ǵȻ����");
		command("kick "+player->query("id"));
		tell_room(environment(), "\n�ⳤ�Ϸ���һ�ţ���"+ player->name()+ "�߷ɳ�ȥ��\n"NOR, ({ player }));
		player->move("/d/fuzhou/yuchuan5");
		tell_room(environment(player), "\nֻ��"+ player->name()+ "���һ���ɹ�����ˤ�˸�����ʺ��\n"NOR, ({ player }));
		player->start_busy(3);
		player->delete_temp("gb_wait_job");
		return "������ľͷ���������˰���";
	}

	if( me->is_busy()) {
		player->add_temp("gb_wait_job", 1);
		return "û��������æ����,���һ�ᡣ";
	}

	if ((int)player->query_condition("gb_busy")){
		player->add_temp("gb_wait_job", 1);
		return "�����ϸ�����ȥ������ȥ�������ҽ��İɣ��Ȼ�������";
	}

        // now all jobs use this condition.
	if ((int)player->query_condition("job_busy")) {
		if( player->query_temp("quest/id") && player->query_temp("quest/family") == "ؤ��")
			return "��������ȥ"+HIY+player->query_temp("quest/place")+CYN+"ɱ"+HIG+player->query_temp("quest/name")+CYN+"������ô�������\n";
		if( player->query_temp("quest/family") == "ؤ��")
			return "����������㻹û�����ô���ܻ����ˣ�";
		else
			return "�����ҿ�û�и�������񣬵Ȼ������ɣ�";
	}

	if ((string)player->query_temp("quest/family") == "������"){
		player->add("job_time/ؤ��", -player->query("job_time/ؤ��")/10);
		player->delete_temp("quest");
		return "����ȥΪ���Ϲ�Ч�����۵������ؤ�����������һ�ɣ�";
	}

	if(!mapp(quest= TASK_D->get_quest(player, 1, "ɱ", "ؤ��")))
		return "�����ҿ�û�и�������񣬵Ȼ���ô����";

	me->start_busy(random(2));
	player->delete_temp("gb_wait_job");
	player->set_temp("quest", quest);
	player->apply_condition("job_busy", 30);
	player->apply_condition("gb_busy", 30);
	player->set_temp("gb_job", 1);
	player->start_busy(random(2));
	command ("say �ðɣ������"+ HIG + quest["name"]+CYN"��һֱ����ؤ�����ԣ���ǰȥ�跨�����˳�����");
	return "����������" + HIY + quest["place"]+CYN"һ���������"+TASK_D->get_time(quest["time"])+"֮ǰ�ϻ�����\n";
}

int accept_object(object who, object ob, object me)
{
        int type;
        me = this_object();

        if( me->is_busy() ){
                command("say ��������æ���أ����Ե�һ�°ɡ�");
                return 0;
        }
        if ( !who->query("gb_pass")) return 0;
        if ( !who->query_temp("gb_job")){
                command("say �Һ���û�и��������񰡣�");
                return 0;
        }
        if( ob->query("id")!="corpse" && ob->query("id")!="shouji") return 0;
                who->start_busy(1);

        if (who->query_temp("quest/family") == "������"){
                command("chat "+ who->name(1)+"͵͵Ϊ������Ч�������ڰ��������ؤ�\n");
                command("chat "+ who->name(1)+"������ְ��࣬���˵ö���֮!!!\n");
                who->delete("gb_pass");
                return 0;
        }

        // check job.
        type = TASK_D->is_target(ob, who);

        switch (type){
            case 0: command("say �ⶫ����Ҫ��û�á�");
                    return 0;
            case -2:command("say �ٺ١���������ɱ�����ˡ�");
                    return 0;
            case -3:command("say �ţ���ô�òŰ��꣬���ʲôȥ�ˣ����ҹ�һ��ȥ��");
                    who->apply_condition("job_busy", 9);
                    return 0;
            case -4:command("say " + RANK_D->query_rude(who) + "����Ȼ����ƭ�����ϣ��������ѣ�");
                    call_out("killing_object",1, who);
                    return 0;
            default:call_out("destroy", 1, ob);
                    me->start_busy(2);
                    call_out("ok", 1, who);
                    return 1;
        }
        return 0;
}

void ok(object apper)
{
	int job_time,pot,exp;
	if (!apper) return;
	if ( apper->query("family/family_name") == "ؤ��"
	 && apper->query_skill("huntian-qigong")){
		apper->improve_skill("huntian-qigong",apper->query("int")*5);
	}

	command("thumb " + apper->query("id"));
	command("say ��Ϊؤ�������˹��ͣ����Ǿ����������ġ�");

	job_time = (int)apper->query("job_time/ؤ��")/800;
	if (job_time <1) job_time = 0;

	tell_room(environment(),HIY "�ⳤ����"+ apper->name()+ "�Ķ��ߵ����ƺ��ڽ�����ʲ�ᣬһ���"+ apper->name() +"��ס��ͷ�����ϲɫ��\n"NOR, ({ apper }));
	tell_object(apper, "�ⳤ�Ϸ��������������ָ������һЩ�书Ҫ��...\n");
	//void give_reward(object me, mapping quest, int shen, int extra,mixed giver,string job)
	TASK_D->give_reward(apper, apper->query_temp("quest"), 1, job_time,this_object(),"ؤ��");
	
	
	apper->clear_condition("job_busy");
	apper->clear_condition("gb_busy");
        apper->set("job_name", "ؤ��");
        this_object()->start_busy(random(2));    
        apper->delete_temp("gb_job");
        pot= apper->query_temp("quest/pot_reward");
        exp= apper->query_temp("quest/exp_reward");
        apper->delete_temp("quest");
	log_file("job/gaibang",sprintf("%8s%-10s��%5d��ؤ�������%3d�㾭�飬%2d��Ǳ�ܣ����飺%d\n",
		apper->name(),"("+apper->query("id")+")",apper->query("job_time/ؤ��"),exp,pot,apper->query("combat_exp")),apper);
        return;
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name")
        && ob->query("family/family_name") != "ؤ��") {
                command("say �㻹��ȥ������ɿ����ɡ�");
                return;
        }
        if ((int)ob->query("gb/bags") >= 2
        && ob->query("family/family_name") != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                command("kill "+ob->query("id"));
                return;
        }

	if( ob->query_skill("huntian-qigong", 1) < 50){
		command("say "+RANK_D->query_respect(ob) +"�Ļ��������ǲ��ǻ�������");
		return;
	}

        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        command("recruit " + ob->query("id"));

        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        ob->set("title",sprintf("ؤ�����ֶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","����ֶ�");
        ob->set("class","beggar");
}

void killing_object(object who)
{
        object me = this_object();
        if(!who || environment(who)!=environment(me)) return;
        me->kill_ob(who);
        who->unconcious();
}

string ask_fangqi()
{
        object me;
        int exp, i;

        me = this_player();
        exp = me->query("combat_exp");
        if(!me->query("gb_pass"))
              return "�����ؤ��Ӣ��,������Ϲ����ʲ��?";
        if(!me->query_temp("quest") || me->query_temp("quest/family") != "ؤ��")
              return "��û��������,������Ϲ����ʲ��?";
        if(me->query("job_time/ؤ��") < 1 ){
              me->set("job_time/ؤ��", 0);
              return "���û�кú���ɹ�����������Ϲ����ʲ�᣿";
        }
        me->delete_temp("gb_wait_job");

	i = 30 - me->query_condition("gb_busy");
	if ( i >= 9 )
		me->apply_condition("job_busy", 1);
	else
		me->apply_condition("job_busy", 9 - i);

	me->clear_condition("gb_busy");
        me->add("combat_exp",-(30+random(40)));
  //      me->add("job_time/ؤ��", -1);
        me->start_busy(random(2));
        me->delete_temp("quest");
        me->delete_temp("gb_job");
        return "��Ȼ��ɲ���Ҳû��ϵ,��ȥ�̿�������,�Ժ�����Ϊؤ�����!";
}

void destroy(object obj)
{
        if (obj) destruct(obj);
}

string ask_gonglao(object who)
{
        object me;
        int i;

        me = this_player();
        if(!intp(i = me->query("job_time/ؤ��")))
               return "��ûΪ��ؤ������κ�����������ʲô������?";
        message_vision(CYN"$N�ͳ�һ�����ӷ��˷���ָ�������ī����$n˵������Ŀǰ�Ѽǹ�" + chinese_number(i) + "�Ρ�\n"NOR,who,me);
        return "��ؤ�������ͷ�����������Ŭ���ɣ����ֽ����Ͳ����뻳�С�";
}

//����������quest
int ask_jiuyuan()
{
	object room,me = this_player();
	object *obj;
	int x;
 	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   command("say "+RANK_D->query_respect(me) +"����С��ͨ���ɣ�");
	   return 1;
	}
	if(me->query(QUESTDIR3+"bad") )
	{
		command("heng");
		command("say �ѵ����ǵ���ǿ�������߳���ԭ��������������㣿");
		return 1;
	}
	if(me->query(QUESTDIR3+"good") && !me->query_temp(QUESTDIR4+"dagouzhen")&& !me->query(QUESTDIR4+"start"))
	{
		if(!me->query_temp(QUESTDIR4+"askwu"))
		{
			message_vision(HIC"�㼱�������������ԣ�����Ϊ��������֮ս���ܾ��ɺ�����ֱ�Ͷ������֮�С�\n"NOR,me);
			command("ah "+me->query("id"));
		}
		//����ʱ��;���������
		//ʱ��һ�죬����500K
		if(!me->query_temp(QUESTDIR4+"shaolinzhen") && me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
		{
			command("say �����æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�");
			return 1;
		}
		if(!me->query_temp(QUESTDIR4+"shaolinzhen") && me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000)
		{
			command("say ��"+RANK_D->query_respect(me) +"Ŀǰ�ľ������Ŀǰ�������Ҳ�ﲻ��ʲôæ������ץ�������ɣ�");
			return 1;
		}
		//ֻ��һ������
		obj = users();
		x = sizeof(obj);
		while(x--) {
			if ( obj[x]->query_temp(QUESTDIR4+"askwu") && obj[x]!=me) 
			{
				command("nod "+me->query("id"));
				command("say ��Ҳ��˵�����飬�Ѿ���"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"ǰ������Ӫ��ȥ�ˣ�"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�书��ǿ������Ҳ�޴󰭣�");	
				return 1;
			}
		}
               
		if(!me->query_temp(QUESTDIR4+"askwu"))
		{
			command("whisper "+me->query("id")+" ������棬ؤ���Ե�����������ؤ������������Ķ࣬��Ҳ������ԭ���������һ��������\n"NOR);
			command("whisper "+me->query("id")+" ֻ�ǣ�������ε�֪��һ��Ϣ��"NOR);
			message_vision(HIY"$N����˵�������ҸմӴ��ɹ�����Ҳ�գ����ս�����أ������书�Ͽ���һ�°ɡ�����\n"NOR,me);
			command("nod "+me->query("id"));
		}
		else command("whisper "+me->query("id")+" ����ʧ���ˣ�Ҳ�գ��ٸ���һ�λ��ᡣ\n"NOR);
		command("whisper "+me->query("id")+" �������ҽ������֮�С�");
		if (!(room = find_object("/d/gb/dagouzhen")))
			room = load_object("/d/gb/dagouzhen");
		if(!room)
		{ 
			tell_object(me,HIR"\n�Ͽ���wiz�ɣ���Ȼ���䲻����!!!\n");
			log_file("quest/TLBB", sprintf("%s(%s)Ӫ������ƪ�����ļ�ȱ�٣�\n", me->name(1),me->query("id")) );
		}
		else
		{
			tell_room(environment(me),HIC"$N���ⳤ�ϴҴҳ�ȥ�ˡ�\n"NOR, ({ me }));                       
			tell_object(me,HIR"�����ⳤ������һ��С��֮�У�ȴ���Ķ˷ֱ�վ��һ��ؤ����ӡ�\n");
			me->move(room);
			this_object()->move(room);
			"/cmds/std/look.c"->look_room(me,environment(me));  
			tell_object(me,HIY"\n�ⳤ��������˻��֣����˳�ȥ��\n"NOR);
			this_object()->move("/d/fuzhou/fenduo1");
			tell_room(environment(this_object()),HIC"�ⳤ�ϴҴһ����ˣ���ɫ���ǻ��š�\n"NOR, ({ this_object()}));                       
			log_file("quest/TLBB", sprintf("%s(%s)Ӫ������ƪ����ؤ���󷨡����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) ); 
			//�趨��־
			me->set(QUESTDIR+"time",time());
			me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
			me->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
			me->set_temp(QUESTDIR5+"askwu",1);
		}
		return 1;
	}

	if(me->query(QUESTDIR3+"good")&& !me->query(QUESTDIR4+"over") &&(me->query(QUESTDIR4+"start")|| me->query_temp(QUESTDIR5+"dagouzhen")))
	{
		command("addoil "+me->query("id"));
		command("say "+RANK_D->query_respect(me) +"ȴ���˵á���ĳ���������"+RANK_D->query_respect(me) +"���ִ�֡�");
		return 1;
	}	
	if(me->query(QUESTDIR3+"good") &&me->query(QUESTDIR4+"over"))
	{
		command("admire "+me->query("id"));
		return 1;
	}	
	if(random(2)) command("@@ "+me->query("id"));
	else command("laugh "+me->query("id"));
	return 1;
}
int ask_xiaofeng()
{
	object me = this_player();
	object *obj;
	int x;
 
 	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   command("say "+RANK_D->query_respect(me) +"����С��ͨ���ɣ�");
	   return 1;
	}
	if(me->query(QUESTDIR2+"over") && !me->query(QUESTDIR3+"over") )
	{
		if(!me->query(QUESTDIR3+"start"))
		{
			if(!me->query_temp(QUESTDIR3+"ask"))
			{
				command("sigh");
				message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ��ؤ���������϶��ڳ�������������������ʰɡ���\n"NOR,this_object());
				return 1;
			}
			if(!me->query_temp(QUESTDIR3+"ask_chen"))
			{
				command("sigh");
				message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���³���Ҳ�ڣ�������������ʰɡ���\n"NOR,this_object());
				return 1;
			}
			if(!me->query_temp(QUESTDIR3+"ask_song"))
			{
				command("sigh");
				message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���γ��϶��ڳ���������������ʰɡ���\n"NOR,this_object());
				return 1;
			}
			if(!me->query_temp(QUESTDIR3+"ask_liang"))
			{
				command("sigh");
				message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ�������϶��ڳ���������������ʰɡ���\n"NOR,this_object());
				return 1;
			}
			if(!me->query_temp(QUESTDIR3+"ask_bai"))
			{
				command("sigh");
				message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���׳��϶��ڳ���������������ʰɡ���\n"NOR,this_object());
				return 1;
			}
		}
		if(me->query_temp(QUESTDIR3+"start"))
		{
			command("sigh");
			command("say �������ȥһ�˾���ׯ��"+RANK_D->query_respect(me) +"һ��ȥ�ɡ�");
			message_vision(HIC"$N�����һ���ˣ�������$n������ȥ�ɣ��Һ��־͵�����\n"NOR,this_object(),me);
			return 1;
		}
	  //����ʱ��;���������
  	  //ʱ��һ�죬����500K
      message_vision(HIC"$N����¶��һ��ҧ���гݵ����ӡ�\n"NOR,this_object());
	  command("heng");
	  command("say �������������֣��������ú��ˣ���ʱ��δ����������������������²������ĳ��һ���������ˡ�"NOR);
      if(me->query_temp(QUESTDIR3+"start"))
	  {
		  command("say ��˵�ۺ��Ѿ�������������ׯ������˵�����徹ȻҲȥ�����������������أ����ʵ�����Թ�����"NOR);
		  return 1;
	  }
  	  if(me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
  	  {
  	  	command("say ���������æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�");
  	    return 1;
  	  }
  	  if(me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000)
  	  {
  	  	command("say ��������"+RANK_D->query_respect(me) +"Ŀǰ�ľ������Ŀǰ�������Ҳ�ﲻ��ʲôæ������ץ�������ɣ�");
  	  	return 1;
  	  }
	  //ֻ��һ������
	  command("say ��˵�ۺ��Ѿ�������������ׯ������˵�����徹ȻҲȥ�����������������أ����ʵ�����Թ�����"NOR);
	  obj = users();
	  x = sizeof(obj);
	  while(x--) {
		  if ( obj[x]->query_temp(QUESTDIR3+"start") && obj[x]!=me) 
		  {
			  command("hehe");
			  command("say �������Ѿ���"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�����ĸ���ȥ�ˣ�"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�书��ǿ���������϶��ܲ����ˣ�");	
			  return 1;
		  }
	  }
	  
	  command("say �������ȥһ�˾���ׯ��"+RANK_D->query_respect(me) +"һ��ȥ�ɡ�");
	  log_file("quest/TLBB", sprintf("%s(%s)׼��������ׯ���ش˼�¼�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) ); 
  	  //�趨��־
  	  me->set(QUESTDIR+"time",time());
  	  me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));    
	  me->set(QUESTDIR3+"start",1);
	  me->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
	  me->set_temp(QUESTDIR3+"start",1);
	  return 1;
	}	

	if(me->query(QUESTDIR3+"over"))
	{
		command("sigh");
		command("say ������Ҫ�ǻ������ǰ����ö��......"NOR);
		return 1;
	}	
	message_vision(HIC"$N��Ĭ��һ���ˣ�����������������ؤ�����ˡ���\n"NOR,this_object());
	return 1;
}
int ask_jingbian()
{
	object me = this_player();
	if(me->query(QUESTDIR2+"over") && !me->query(QUESTDIR3+"start"))
	{
		if(!me->query_temp(QUESTDIR3+"ask"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ��ؤ���������϶��ڳ�������������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_chen"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���³���Ҳ�ڣ�������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_song"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���γ��϶��ڳ���������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_liang"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ�������϶��ڳ���������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_bai"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���׳��϶��ڳ���������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ��ؤ���Ĵ��϶��ڳ���Ҳ����������Щ�ˡ���\n"NOR,this_object());
		return 1;
	}	
	if(me->query(QUESTDIR3+"start") &&!me->query(QUESTDIR3+"over"))
	{
		message_vision(HIC"$N����¶��һ��ҧ���гݵ����ӡ�\n"NOR,this_object());
		command("say �������������֣��������ú��ˣ���ʱ��δ����������������������²������ĳ��һ���������ˡ���"NOR);
		return 1;
	}	
	if(me->query(QUESTDIR3+"over"))
	{
		command("sigh");
		command("say ������Ҫ�ǻ������ǰ����ö��......"NOR);
		return 1;
	}	
	command("? "+me->query("id"));
	return 1;
}
