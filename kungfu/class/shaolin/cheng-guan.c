// Npc: /kungfu/class/shaolin/cheng-guan.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_murenxiang();

void create()
{
	set_name("�ι�", ({
		"chengguan luohan",
		"chengguan",
		"xianglong",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);


	set("nickname", "�����޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 600000);
	set("score", 5000);

	set_skill("force", 100);
    set_skill("yijin-jing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("hand", 100);
	set_skill("fengyun-shou", 100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

    map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "fengyun-shou");

	prepare_skill("hand", "fengyun-shou");

	create_family("������", 37, "����");

        set("inquiry",([
		"ľ����"   : (: ask_murenxiang :),
	]));

	setup();

        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


void init()
{
	::init();

	add_action("do_yes", "yes");
	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin4", ob) ) 
	{
		command("say �������������ҵ��Ƽ���ȥ��ʦ���� ?");
		return 0;
	}

	if((obj->query("id") == "damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok4",1);
	        command("say �ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
	if (obj->query("id") == "tuijian xin3" 
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say �ã�" + ob->query("name") + "����Ը�����Ϊʦ��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok4") ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	ob->delete_temp("fight_ok4");
	
	return 1;
}

int checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",1, me, ob);
                return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say ������ʤ����������������µļѵ��� ! ��ϲ���� !\n");
		message_vision("$N����$nһ���Ƽ��š�\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/shaolin/obj/tuijianxin-4");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������������������г���ͷ�� !\n");
		return 1;
	}

	return 1;  
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say ��" + ob_fam["master_name"] + "���������ҵİɣ������� !");
			command("say ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			new_name = "��" + name[2..3];
			ob->set("name", new_name);
	
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɻ��ֱ����� !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û���Ƽ��ţ�����Խ����ʦ��");
			return;
		}
	}

	return;
}

string ask_murenxiang()
{
// object ob;
       mapping fam;

       if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

       if ((int)this_player()->query("muren_winner")) 
                return RANK_D->query_respect(this_player()) + 
		"�����Ѿ�����ľ������ô���ɲ�Ҫ�����Ŀ������Ц��";

       if ((int)this_player()->query("combat_exp", 1) < 10000)
                return RANK_D->query_respect(this_player()) + 
		"�Ĺ������������ǲ�Ҫ��ľ����Ϊ�ã�"; 

       command("look " + this_player()->query("id"));
       command("nod");

       this_player()->set_temp("ask_muren", 1);
       
       return "ľ��������������Ϊ���յ�ȥ��֮һ�����б鲼�ֳ�������ľ�ˣ�\n"
           "������ֻ����ǰ�ߣ����޷���֮·������һ����Ҫͣ��̫��ʱ��\n"
           "����������Ѷ����͸�����(yes)��";
}

int do_yes()
{
	object me = this_player();

        if( !me->query_temp("ask_muren") )
		return 0;
	message_vision(
		"$nת������ƿ����ķ��񣬺���¶��һ��С�ţ�\n\n"
		"$n�������$N��һ�ƣ���$N�ƽ����ڣ�\n\n"
                "$n�������ƻ�ԭλ��\n\n",
                me, this_object() );
        me->move("/d/shaolin/entrance");
        return 1;
}
