// Modify by YUJ@SJ 2000-11-12
// Modify by LOOKLOVE@SJ 2001-1-8
// ��ӳ�Ѷȹ��� �ӳ�����ʱ��  ˳��fix����bug Ciwei@SJ
#include <ansi.h>
#include <job_mul.h>

inherit NPC;

int ask_job();

void create()
{
	set_name("������ʦ", ({ "da shi", }));
	set("long", "����һλ��İ�С������ɮ�ˣ�������������ɫ�Ⱥͣ�\n"
		"Ҳ�Ʋ����ж�����͡�\n");
	set("nickname", "���ֳ���");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("muren_winner",1);
	set("no_get","����������������������");
	set("no_ansuan",1);
	
	set("age", 60+random(20));
	set("shen", 1);
	set("str", 20);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 6500);
	set("max_jing", 3000);
	set("eff_jingli",5000);
	set("max_neili", 8000);
	set("jiali", 40);
	set("combat_exp", 2000000);

	set_skill("force", 180);
	set_skill("yijin-jing", 180);
	set_skill("dodge", 220);
	set_skill("shaolin-shenfa", 180);
	set_skill("parry", 180);
	set_skill("finger",180);
	set_skill("yizhi-chan",190);
	set_skill("buddhism", 180);
	set_skill("literate", 100);
	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("parry", "yizhi-chan");
	set_temp("sljob", 1);

	prepare_skill("finger", "yizhi-chan");
	create_family("������", 35, "����");

	set("inquiry", ([
		"��Ԯ" : (: ask_job :),
	]));

	setup();

	carry_object("/d/shaolin/obj/xuan-cloth")->wear();

	if (clonep()) call_out("remove_ob",2000);
}

void remove_ob()
{
	//������Щ�����Ҳ�����dashi����ȥaskjob ��ֹ�����ʧ ����Ͳ�delete_temp��
	/*
	object me;
	int teams;
	teams=query("teams");
	for(int i=1;i<=teams;i++) {
			me = query_temp("team" + i);
			if(!me) continue;
			me->delete_temp("sljob");
	}
	*/
	message_vision(HIR "$N���ͷ���˵����ô��ô�û�������ɽ�������Լ���ȥ�ˡ�\n" NOR, this_object());
	destruct(this_object());
}

void init()
{
	object me = this_player();

	::init();
	if (me==query("jobleader")) {
		me->add_busy(1+random(2));
		call_out("init2", 2, me);
	}
}

void init2(object me)
{
	object ob=this_object();
	object ob1,ob2;
	int i,teams;
	int exp,pot;
	int killed;
	mapping exits;
	string *dirs;
	object env;
	int j;
	int k,m,n;
	object *envs;
	object *envs2;

	if (!me) return;
	if (me==query("jobleader")
	&& file_name(environment()) == "/d/hengshan/baiyunan") {
		if( !me->query_temp("sljob") ) {
			log_file( "job/husong", sprintf("%8s%-10s�����֡���Ԯ��ɽ���������BUG��\n",
				me->query("name"), "("+me->query("id")+")" ),me);
			call_out("remove_obj",1);
			return;
		}
		command("say ���ˣ��������գ����ڵ��˺�ɽ��");
		command("say �����Ȼ�ȥ���߷��ɣ��ҺͶ���ʦ̫һ��ֿ�ħ�̵Ľ�����");
		CHANNEL_D->do_channel(ob, "rumor", sprintf("%s"HIR"���ʹ�ʦ"NOR"˳�������ɽ�ˣ�", me->query("name")));
		teams=query("teams");
		for(i=1;i<=teams;i++) {
			ob1 = query_temp("team" + i);
			if(ob1 && present(ob1)) {
				exp = 1000/teams + 500;
				killed = ob1->query_temp("sljob/killed");
				if (killed > 6) killed = 6;
				exp += killed * 100+random(killed*50);
				if (query_temp("sljob/total") - ob1->query_temp("sljob/killed") > 0) {
					exp -= (query_temp("sljob/total")-ob1->query_temp("sljob/killed"))*100;
					if (exp < 100) exp=100+random(100);
				}
				if (exp > 1500) exp = 1400 + random(100);
                                                       exp= exp * 2;
				if (!ob1->query_temp("sljob/killed")) exp = 100 + random(50);
				if ( ob1->query("sl_job") > 1000 && teams < 2 ) exp /= 5;
								
				exp = ob1->add_exp_combat(exp,this_object(),"���־�Ԯ");
				//ob1->add("combat_exp", exp);
				//GIFT_D->check_count(ob1,this_object(),"���־�Ԯ");
				//ob1->add("job_time/���־�Ԯ",1);
				pot = exp/6+random(exp/10);
				
				ob1->add("potential", pot);
				if (ob1->query("potential") > ob1->query("max_pot"))
					ob1->set("potential", ob1->query("max_pot"));
				ob1->add("job_time/����",1);				
				
				ob1->apply_condition("sljob", exp/60 + random(7));
                                ob1->set("job_name", "��ɽ��Ԯ");
                                ob1->apply_condition("sl_job_busy", 60);
				ob1->apply_condition("job_busy",2);
				tell_object(ob1,HIW"�ã�������ɣ���õ���" 
					+ CHINESE_D->chinese_number( exp ) 
					+ "��ʵս�����" 
					+ CHINESE_D->chinese_number( pot )
					+ "��Ǳ�ܡ�\n" NOR);
				
				log_file( "job/husong", sprintf("%8s%-10s"
					+"����%5d�Σ�%2d��ɱ�֣���%2d����"
					+ "����%4d�㣬Ŀǰ���飺%d\n", ob1->query("name"),"("+ob1->query("id")+")",
					ob1->query("job_time/����"),query_temp("sljob/total"),
					ob1->query_temp("sljob/killed"),exp, ob1->query("combat_exp")),ob1);
				ob1->delete_temp("sljob");
				// add for sl wuxiang-zhi's quest
				if (ob1->query("family/family_name")=="������" 
				&& ob1->query("job_time/���־�Ԯ") > 1000
				&& ob1->query("combat_exp") > 2000000
				&& random(ob1->query("combat_exp")) > 1500000
				&& random(ob1->query_skill("shaolin-shenfa",1)) > 200
				&& ob1->query_skill("buddhism",1) > 180
				&& random(ob1->query_skill("buddhism",1)) < 20
				&& !ob1->query_temp("wxz/quest")
				&& ob1->query("wxz/quest") < 2) {
					command("whisper "+ob1->query("id")+" �ղ�����������ʦ�ܣ����ƺ���һЩ"
						+"���������似���뷨Ҫ�����㣬��������ȥ������һ�ˡ�");
					ob1->set_temp("wxz/quest",1);
					ob1->set("wxz/quest",1);
					log_file("quest/wuxiang", sprintf("%8s%-18s��%5d�λ�������ʱ�����ѧϰ�����ָ�Ļ��ᡣ\n",
						ob1->query("name"), "("+ob1->query("id")+")", ob1->query("job_time/����")), ob1);
				}
			}
		}
		call_out("remove_obj",1);

		i=random(teams+1);
		ob1=query_temp("team"+i);
		if (ob1 && present(ob1) && random(10)> 8 ) {
			tell_object(ob1,HIG"���"+query("name")
				+"����õ���һ��������������\n" NOR);
			ob2=new("/clone/medicine/neili/liuyang-dan.c");
			if( ob2 ) {
				ob2->set("owner",ob1->query("id"));
				ob2->move(ob1);
			}
			log_file("quest/neili", sprintf("%-18s��������������õ�������������\n",
				 ob1->query("name")+"("+ob1->query("id")+")" ), ob1);
		}
		return;
	}

	if(me==query("jobleader") && me->query_temp("sljob/asked")>=2
	&& !environment(me)->query("no_fight")) {
		if (add("neili",-(query("max_qi")-query("eff_qi"))/2) >= 0) {
			set("eff_qi",query("max_qi"));
			set("qi",query("max_qi"));
		}
		if ((add_temp("sljob/go", 1) > 5 && !random(5))
		|| query_temp("sljob/go") > 8) {
			set_temp("sljob/go",0);
			set_heart_beat(0);
			set_heart_beat(1);
			ob1=new("/d/shaolin/npc/killer");
			message_vision(HIR "ͻȻ��·�߳��һ��ħ�̽�ͽ��һ�����Ե���"
				+query("name")+"��ȥ��\n"NOR, ob);
			ob1->set("lvl",query("lvl"));
			ob1->set("dashi",ob);
			ob1->set("int", me->query_int());
			ob1->set_name(ob1->query("name"), ({ me->query("id") + "'s jiaotu" }));
			ob1->move(environment(me));
			ob1->set_leader(ob);
			add_temp("sljob/total",1);
			if (!random(20)) {
				message_vision(HIY"" + query("name")+"�ߺ�һ��������������ҳ��ˣ����ڻ���\n"NOR,me);
				envs=({file_name(environment(me))});
				for(m=0;m<2;m++) {
					envs2=envs;
					for(n=0;n<sizeof(envs);n++) {
						exits=envs[n]->query("exits");
						dirs=keys(exits);
						for(k=0;k<sizeof(dirs);k++) {
							env=envs[n]->query("exits/"+dirs[k]);
							if(env&&!env->query("no_fight")&&!env->query("sleep_room")) {
								for(j=0;j<sizeof(envs2);j++) if(envs2[j]==env) break; 
								if(j==sizeof(envs2)) envs2=envs2+({env});
							}
						}
					}
					envs=envs2;
				}
				me->set_temp("env",envs);
				env=envs[random(sizeof(envs))];
				move(env);
				ob1->move(env);
			}
		}
	}
}

void remove_obj()
{
	destruct(this_object());
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();

	if( query("jobleader")!=me) return 0;

	if( me->query_temp("sljob/asked")==0 ) return 0;

	if( me->query_temp("sljob/asked")>1) {
		command( "say ��ղŲ����ʹ����𣿿�ȥ�ɡ�");
		return 1;
	}
	command("say �õģ�������λ" + RANK_D->query_respect(me) + "��ǰ���·��ǰȥ��ɽ��" );
	message_vision("$N��������$nһ���ж���\n",ob,me);
	set_leader(me);
	set("sljob/leader",me);
	me->set_temp("sljob/asked",2);
	return 1;
}

void attempt_apprentice(object ob)
{
	command("say �Բ����������ڲ���ͽ��");
}

void unconcious()
{
	object me;
	
	me = query_temp("last_damage_from");

	if (!objectp(me)) {
		::unconcious();
		return;
	}

	if (userp(me)) {
		reincarnate(); 
		return;
	}
	::unconcious();
}

void die()
{
	object me;
	int teams;
	
	teams=query("teams");
	for(int i=1;i<=teams;i++) {
			me = query_temp("team" + i);
			if(!me) continue;
			me->delete_temp("sljob");
	}
	me=query("jobleader");
	if( !me ) {
		::die();
		return;
	}
	tell_object( me, HIY""+query("name")+"����������������ʧ�ܡ�\n"NOR);
	log_file("job/husong", sprintf("%8s%-10s����ʧ�ܡ�\n", me->query("name"),"("+me->query("id")+")"), me);
	me->apply_condition("sljob",10);
	me->apply_condition("job_busy", 10);
	me->delete_temp("sljob");
	::die();
}

void kill_ob(object ob)
{
	if (userp(ob))
	{
		ob->remove_killer(this_object());
		remove_killer(ob);
		message_vision("$N���к�Ȼ���ã����Լ���ô��ô�޳ܣ���Ȼ�������¸����صĴ�ʦ�´˶��֣���\n", ob);
	}
}