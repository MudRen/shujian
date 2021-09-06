// Npc: /kungfu/class/shaolin/xuan-ci.c
// add by tangfeng@SJ 2004


inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int ask_job();
int ask_times();
int ask1();
int ask2();
int ask3();
int ask_xiaofeng();
int ask_yeerniang();
int ask_zhangxing();
int ask_xuzhu();
void zhangxing(object me,object ob);
int ask_zuinie();

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

void create()
{
	set_name("���ȴ�ʦ", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long", "����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);

	set("nickname", "�����·���");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("unique", 1);
	set("no_bark",1);

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 180);
	set("combat_exp", 1200000);
	set("score", 0);

	set_skill("force", 160);
	set_skill("yijin-jing",160);
	set_skill("dodge", 160);
	set_skill("shaolin-shenfa", 160);
	set_skill("finger", 160);
	set_skill("strike", 160);
	set_skill("hand", 160);
	set_skill("claw", 160);
	set_skill("parry", 160);
	set_skill("nianhua-zhi", 160);
	set_skill("sanhua-zhang", 160);
	set_skill("fengyun-shou", 160);
	set_skill("longzhua-gong", 160);
	set_skill("buddhism", 160);
	set_skill("literate", 160);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 36, "����");

	set("inquiry", ([
		"job" : (: ask_job :),
		"����": (: ask_times :),
//		"��Զɽ":  (: ask1 :),
//		"ɱ��":  (: ask2 :),
//		"������ҵ": (: ask3 :),
		"����" : "�����ӷ����ľ����������֡���֪��ʩ������������ν���¡�\n",
		"����" : "�����ӷ����ľ����������֡�",
		"����" : "������ؤ�������һ���书�Բ���˵���䵨ʶ�ǻ�Ҳ�ǽ���һ����ֻ��......",
		"��Զɽ" : "����һ�����£����Ѿ���ȥ����ʩ��������ɮ���",
		"������ɮ" : "��ɮ�������˼ң����ƴ�Ħת�����𷨳�Ⱥ��",
		"��ɮ" : "��ɮ�������˼ң����ƴ�Ħת�����𷨳�Ⱥ��",
		"����" : (: ask_xuzhu :),
		
		"����" : (: ask_zuinie :),
		"����" : (: ask_zuinie :),
		"����" : (: ask_zuinie :),

		"��Ԯ����" : (: ask_xiaofeng :),
		"�������" : (: ask_xiaofeng :),
		"Ԯ������" : (: ask_xiaofeng :),
		"��Ԯ" : (: ask_xiaofeng :),
		"���" : (: ask_xiaofeng :),
		"Ԯ��" : (: ask_xiaofeng :),
		"Ҷ����" : (: ask_yeerniang :),
		"˽����" : (: ask_yeerniang :),
		"�ͷ�" : (: ask_zhangxing :),
		"����" : (: ask_zhangxing :),
		"�ܷ�" : (: ask_zhangxing :),
	]));

	setup();

	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me;
	mapping ob_fam, my_fam;
	string name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������") {
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") {
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] ) {
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��") {
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}
	else {
		command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
	}
}

int accept_object(object apper, object ob)
{
	int lvl;
	object me = this_object();

	message_vision(sprintf("$N��$nһ%s%s��\n", ob->query("unit"), ob->name()), apper, me);
	if( ob->query("id") != "muou" || userp(ob)){
		command("say �ⶫ����Ҫ��û�á�");
		return 0;
	}

	notify_fail("");
	if (!apper->query_temp("lh_teacher")
	 || !apper->query_condition("lh_job")){
		message_vision("$Nһ�Ѷ��ľż��ŭ�����������͵����?\n", me);
		destruct(ob);
		return 0;
	}
	command("touch "+apper->query("id"));
	message_vision("$N�ж�������ӯ����˵�������������ؼ��������ر��ˣ�\n", me);
	command("thank "+apper->query("id"));
	lvl = 200 + random(50);
	apper->add("combat_exp", lvl);
	if (apper->add("potential", lvl/5+random(lvl/10)) >= apper->query("max_pot"))
		apper->set("potential", apper->query("max_pot"));
	apper->improve_skill("yijin-jing",random((int)apper->query("int"))* 2);

	log_file("job/muou", sprintf("%8s%-10s�õ�ľż���������ȣ��õ�������%3d���־��飺%d��\n",
		apper->query("name"), "("+apper->query("id")+")", lvl, apper->query("combat_exp") ),apper);

	destruct(ob);
	return 0;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if(ob->query_temp("job_name")!="�������ȷ���") return;
	command("pat "+ob->query("id"));
	command("say " + RANK_D->query_respect(ob)+ "��͸��Ұ�Ħһ�°�(massage ����)�ǺǺǡ�\n");
}

int ask_job()
{
	object me = this_player(), ob = this_object(),ob1;
	int lvl,exp;
	object *team, maxplayer, minplayer;
	int totalexp=0, maxexp, minexp;
	int size,i;
	int index;
	int y;

	string* file= ({ "/d/shaolin/lhtang", "/d/shaolin/brtang",
		"/d/shaolin/smdian", "/d/shaolin/zhlou7", "/d/shaolin/gulou7",
		"/d/shaolin/houdian", "/d/shaolin/zdyuan", "/d/shaolin/pingtai",
		"/d/shaolin/putiyuan", "/d/shaolin/yaowang", "/d/shaolin/xumidian",
		"/d/shaolin/liuzu","/d/shaolin/jnlwang","/d/shaolin/lxting",
		"/d/shaolin/qfdian","/d/shaolin/czan","/d/shaolin/bydian",
		"/d/shaolin/dzdian","/d/shaolin/xcping"
	});
	string* name= ({ "�޺���","������","ɽ�ŵ�","��¥","��¥","���",
                        "֤��Ժ","ƽ̨","����Ժ","ҩ��Ժ","���ֵ�",
                        "�����","����������","��ѩͤ","ǧ���","������",
                        "���µ�","�زص�","����ƺ"});
	string *name1=({ "������ʦ","�ռ���ʦ","���Ŵ�ʦ","���Ǵ�ʦ","���Դ�ʦ", });
	string *long=({
                "����һλ��İ�С������ɮ�ˣ�������������ɫ�Ⱥͣ�Ҳ�Ʋ����ж�����͡�\n",
                "����һ�������С������ɮ�ˣ���һ��ϴ�÷��׵��°�ɮ�¡�\n",
                "����ü�´���ֱ�������ϣ����Ƴ�ü�޺�һ�㡣\n",
                "��������ΰ��ò�����䡣\n",
                "��һ���Ŀ��࣬����´���\n",
	});
	int teams;
	string addr;

	if( me->query_condition("job_busy")
	|| me->query_condition("sljob")
	|| me->query_condition("sl_job_busy")
	|| me->query("job_name") == "��ɽ��Ԯ"){
		command("say ����������û��ʲô������㡣" );
		return 1;
	}

	if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
	{
		command("say ����������û�и���������㻹���ȴ����������������˵�ɡ�" );
		return 1;
	}

	if( me->query_temp("sljob/asked")
	 || me->query_temp("sljob/join")){
		command("say ��ղŲ����Ѿ��ʹ�����" );
		return 1;
	}

	if(!wizardp(me)&& me->query("combat_exp") >= me->query("slexp") && me->query("combat_exp") <= me->query("slexp") + 500){
		command("say ���书����Ҳ̫���ˣ�������ô��������ȥ�ɰ���");
		return 1;
	}

	y = sizeof(children(__DIR__"fang-zheng"));

	if( y > 2) {
		command("say �ţ��Ѿ������ڰ����ˣ��㻹��ȥæ����ʲô�ɡ�");
		return 1;
	}

	if( me->query("shen") < 1 ){
		command("heng");
		command("say ��λ" + RANK_D->query_respect(me)+"��¶�׹⣬�������������ɣ��ɲ��������ܡ�");
		return 1;
	}

	index = ob->query("index");

	command("say �ҽӵ����ɵ���ͨ����ħ�̽�������������������ڣ�\n"
             + "��Ѫϴ��ɽ�ɡ��䶨��ʦ̫��δ����������Ԯ�������ֲ������Ӻ�ɽ\n"
             + "����������"+ name1[index]+ "�����޺��úͰ����õ���ǰȥ��Ԯ��");

	//if (sizeof(me->query_team()) < 2 && me->  )
	if (sizeof(me->query_team()) < 2 && (me->query("family/family_name") != "������" || me->query("wxz"))) {
		command("say ��" + RANK_D->query_respect(me)+ "���书��Ϊ���ƺ���������������������" );
		return 1;
	}
	else {
		team = me->query_team();
		if (!sizeof(team)) team = ({ me });
		if(sizeof(team) > 4) {
			command("say ��ȥ��ɽ·;Σ�գ������˶���û�õġ�");
			return 1;
		}
		for (i=0;i<sizeof(team);i++){
			if (!team[i]) {
				command("say ��Ķ�����������⣬���ɢ�������齨��");
				return 1;
			}
			if (team[i] == me) continue;
			if (!present(team[i], environment(me))){
				command("say �ף���ô�����˲�ȫ����"+team[i]->query("name")+"��ôû����");
				return 1;
			}
			if (!interactive(team[i]) || query_ip_number(team[i]) == query_ip_number(me)) {
				command("say �㻹�ǽ�"+team[i]->query("name")+"���������˰ɡ�");
				return 1;
			}
		}
		maxexp=minexp=team[0]->query("combat_exp");
        	maxplayer=team[0];
		minplayer=team[0];
		for (i=0;i<sizeof(team);i++){
			if (team[i]->query("combat_exp") < 1000000) {
				command("say ��ȥ��ɽ·;Σ�գ��ҿ���λ"+RANK_D->query_respect(me)
					+"��Ҫһ���ô��");
				return 1;
			}
			if( team[i]->query_condition("job_busy")
			|| team[i]->query_condition("sljob")
			|| team[i]->query_condition("sl_job_busy")
			|| team[i]->query("job_name") == "��ɽ��Ԯ"){
				command("say ������е�"+team[i]->query("name")+"���������������ء�");
				return 1;
			}
			if( team[i]->query("combat_exp") - 500 <= team[i]->query("slexp")
			&& team[i]->query("sldeath")==team[i]->query("death_count")){
				command("say ������е�"+team[i]->query("name")+"�书����̫���������Ƿ�Ӧ����ѡһ������");
				return 1;
			}
			if (team[i]->query("shen") < 0) {
				command("whisper "+ me->query("id")+" ��ȥ��ɽ�����������£���������е�"+team[i]->query("name")+
					"��¶�׹⣬�������������������ļ�ϸ�ɣ�");
				return 1;
			}
			totalexp += team[i]->query("combat_exp");
			if(team[i]->query("combat_exp") > maxexp ){
				maxexp=team[i]->query("combat_exp");
				maxplayer=team[i];
			}
			else if(team[i]->query("combat_exp") < minexp){
				minexp=team[i]->query("combat_exp");
				minplayer=team[i];
			}
		}
		if (totalexp < 2000000 || maxexp-minexp > 1000000) {
	        	command("say ��ȥ��ɽ·;Σ�գ��ҿ���λ�ƺ��޴�������");
			return 1;
		}
		if (sizeof(team) != 0 && (team[0] != me)){
			command("say ֻ�ж������������������");
			return 1;
		}
		for (i=0;i<sizeof(team);i++){
			team[i]->delete_temp("sljob");
			team[i]->set_temp("sljob/join", 1);
			team[i]->set("slexp", team[i]->query("combat_exp"));
			team[i]->apply_condition("sljob",40);
			team[i]->apply_condition("job_busy",40);
			team[i]->set("sldeath",team[i]->query("death_count"));
	        }
	        teams=sizeof(team);
	}

	ob->set("index", (ob->query("index")+1)%5);
	size=sizeof(file);
	i=random(size);
	addr=file[i];

	command("say �����λ��ͬ"+name1[index]+"ǰȥ��ɽ��һ·С�ġ�");
	command("say "+name1[index]+"����"+name[i]+"��\n");
	log_file("job/husong", sprintf("%8s%-10s��Ԯ��%d��\n",
		me->query("name"),"("+me->query("id")+")", teams ),me);
	ob1=new(__DIR__"fang-zheng");
	ob1->move( file[i] );
	ob1->set("name",name1[index]);
	ob1->set("long",long[index]);
	ob1->set_temp("teams",teams);
	if(teams>3)
		ob1->set_temp("team4",team[3]);
	if(teams>2)
		ob1->set_temp("team3",team[2]);
	if(teams>1)
		ob1->set_temp("team2",team[1]);
	if(teams>0){
		if( me->query_team() )
			ob1->set_temp("team1",team[0]);
		else
			ob1->set_temp("team1",me);
	}

	if( maxplayer->query("max_pot")-20 > minplayer->query("max_pot"))
		lvl = minplayer->query("max_pot")-100-10;
	else
		lvl = maxplayer->query("max_pot")-100-30;

	exp = minplayer->query("combat_exp");
	ob1->set("combat_exp",exp);
	ob1->set("max_qi",5000+exp/1200);
	ob1->set("qi",ob1->query("max_qi"));
	ob1->set("eff_qi",ob1->query("max_qi"));
	ob1->set("jing",4000);
	ob1->set("max_neili",4000+exp/1500);
	ob1->set("neili",ob1->query("max_neili"));
	ob1->set("eff_jingli",3500);
	ob1->set_temp("lvl",lvl);
	ob1->set_skill("dodge",lvl);
	ob1->set_skill("force", lvl);
	ob1->set_skill("yijin-jing", lvl);
	ob1->set_skill("shaolin-shenfa", lvl);
	ob1->set_skill("parry", lvl);
	ob1->set_skill("finger",lvl);
	ob1->set_skill("yizhi-chan",lvl);
	ob1->set_skill("medicine",150);
	ob1->set_skill("buddhism", 200);
	ob1->set_skill("literate", 200);
	ob1->map_skill("force", "yijin-jing");
	ob1->map_skill("dodge", "shaolin-shenfa");
	ob1->map_skill("finger", "yizhi-chan");
	ob1->map_skill("parry", "yizhi-chan");
	ob1->set("jobleader",me);
	ob1->set("xuanci",ob);
	ob1->set("teams",teams);
	ob1->set("lvl",maxplayer->query("max_pot")-100);
	ob1->set_name(ob1->query("name"), ({ me->query("id")+"'s dashi" }));
	tell_room(environment(ob1), ob1->name() + "���з�ţ����������˹�����\n", ({ ob1 }));

	me->set_temp("sljob/asked",1);
	me->apply_condition("sljob",40);
	me->apply_condition("job_busy",40);
	return 1;
}

int ask_times()
{
	object me=this_player();
	command("say ���Ѿ�Ϊ��������"
		+ CHINESE_D->chinese_number( me->query("job_time/���־�Ԯ") )
		+ "�ι��ס�");
	command("addoil "+me->query("id"));
	return 1;
}

int ask1()
{
	object me;

	me=this_player();

	if( me->query("family/family_name")!="������" )
		return 0;
	if( me->query("family/generation")>36 )
		return 0;

	command( "say ���ĵ����������ԣ����������Ź����ɱ��ʩ��ȫ�ң�\n"
                + "��������ɱ��������������׷��ĩ����" );
	command( "sigh" );
	me->set_temp("sl/pks",1);
	return 1;
}

int ask2()
{
	object me = this_player();

	if( me->query_temp("sl/pks") < 1 )
		return 0;
	command( "say ���ĵ�֪����������Ļ����䣬�ҵñ���һλ��ɮ�㻯��������\n"
		+"��������ҵ����ʹ������ܣ���Ҳ����������ޡ�" );
	me->set_temp("sl/pks",2);
	return 1;
}

int ask3()
{
	object me = this_player();

	if( me->query_temp("sl/pks") < 2 )
		return 0;
	command( "whisper " + me->query("id") +
		" ��ʦ���д��ģ���ȥ�ؾ�����һλɨ�ص�������ɮ��" );
	command( "buddhi dashi" );
	me->set_temp("sl/pks",3);
	return 1;
}

//������quest����
int ask_xuzhu()
{
	object me = this_player();
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& (me->query_temp(QUESTDIR5+"son")||me->query(QUESTDIR5+"over")))
	{
	  message_vision(HIY"$N��¶��ʹ֮ɫ������û��˵����ֻ��̾Ϣһ����\n"NOR,this_object());
	  if(random(2)) command("sigh");
	  else command("say");
	  return 1;
	}	
	command("? "+me->query("id"));
	command("say ���񣬺��������ֵ���ʮ�Ŵ�����֮һ����֪��ʩ���������£�");
	return 1;
}

int ask_yeerniang()
{
	object me = this_player();
 	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   command("say "+RANK_D->query_respect(me) +"����С��ͨ���ɣ�");
	   return 1;
	}	
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& !me->query_temp(QUESTDIR5+"yeerniang")&& !me->query(QUESTDIR5+"over"))
	{
		command("? "+me->query("id"));
	  message_vision(HIC"$N��$n����һ����������Ҫ��װ�����׵����ӣ���ʮ��ǰ�����ѵ������ʲô�����ǵ���......\n"NOR,me,this_object());
	  command("consider");
	  message_vision(HIY"$N����������20��ǰ�㹴��Ҷ��ׯҶ����������ö˶˵Ĺ����ò���硣���Ǳ��������գ�ʧ�����㣬\n"
	                    "��Ϊ������һ�����ӣ�������ֻ�˵��Լ�������ǰ�̣�ȫ��������һ���������Ĺ��δ�����ӣ�������\n"
	                    "�εȵ���ҡ���ʮ�������֪���������Ҷ������������ڵ��Ĵ����Ҷ�����\n\n"NOR,me);
	  command("oh");
	  message_vision(HIG"\n$Nҡҡͷ��������֮��˭��˭�����˵�壬�����Ҵ���ʱ��Ҳ�����չˣ����ں��ӣ��ҵ��治֪��\n"NOR,this_object());
	  command("dunno "+me->query("id"));
		command("say �����û���ϵ�Ҷ������ǵ���Ҷ��ׯ��Ҷ���������������");
		me->set_temp(QUESTDIR5+"yeerniang",1);
		return 1;
	}	
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& (me->query_temp(QUESTDIR5+"yeerniang")||me->query(QUESTDIR5+"over")))
	{
		command("sigh");
		command("say �����û���ϵ�Ҷ������ǵ���Ҷ��ׯ��Ҷ���������������");
		return 1;
	}	
	command("say �����Ĵ���˵�Ҷ���");
	command("dunno "+me->query("id"));
	return 1;
}
int ask_zuinie()
{
	object me = this_player();
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& me->query_temp(QUESTDIR5+"yeerniang")
	   && !me->query_temp(QUESTDIR5+"zuinie")&& !me->query(QUESTDIR5+"over"))
	{
	  message_vision(HIY"$N����Ц�������Ե������Լ���������Ϊ�������֣��ѵ����е����������ֺųƷ���ʥ�أ�ȷ��˽���ӵĹ��¡�\n"NOR,me);
	  message_vision(HIG"$N������������ţ�����û��˵����ֻ��̾Ϣһ����\n"NOR,this_object());
		command("sigh");
		me->set_temp(QUESTDIR5+"zuinie",1);
		return 1;
	}	
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& (me->query_temp(QUESTDIR5+"yeerniang")||me->query(QUESTDIR5+"over")))
	{
		command("sigh");
		command("say �����û���ϵ�Ҷ������ǵ���Ҷ��ׯ��Ҷ���������������");
		return 1;
	}	
	command("say �����ӷ��ҷ�ȱ���");
	return 1;
}
int ask_zhangxing()
{
	object obj,me = this_player();
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& me->query_temp(QUESTDIR5+"yeerniang")&& me->query_temp(QUESTDIR5+"zuinie")&& !me->query_temp(QUESTDIR5+"zhangxing")&& !me->query(QUESTDIR5+"over"))
	{
	  message_vision(HIC"$N����һ���������ҷ����ڣ��¹���ڡ��벻���������־�Ȼ����������飬�����Ʒ����Ƶء�\n"NOR,me);
		command("sigh "+me->query("id"));
		command("nod "+me->query("id"));
		
	  message_vision(HIY"\n$N����˵�������������ķ��˷��Ŵ�䣬�����������������й��������мҹ档�����κ�����\n"
	                    "��ᣬ������Ժ���������в�Ф���ӡ���������֮��ȫ����������Զ���˷��棬�������°��ɳʹ�����\n"
	                    "�Լٽ衣�����½��ɣ����ȷ������䣬����Ϊ���ɣ����̼ӱ���ִ��ɮ����������ȶ��ٹ�����������\n"
	                    "�����أ�����ѭ˽��ס���˵�Ź���ڵأ�ңң���ŷ�������������ɮ�ۣ�¶��������\n"NOR,this_object());
	  command("sneer "+me->query("id"));
	  obj=new("/d/shaolin/npc/zjseng.c");
	  obj->move(environment(me));
    message_vision(WHT"$N�Ҵ������˹�����\n"NOR,obj);
	message_vision(HIY"$N��$nʩ�񣬵�������ţ���������һ�ߡ�\n"NOR,obj,this_object());
	  obj->command("bow "+this_object()->query("id"));
	  obj=new("/d/shaolin/npc/zjseng.c");
	  obj->move(environment(me));
    message_vision(WHT"$N�Ҵ������˹�����\n"NOR,obj);
	message_vision(HIY"$N��$nʩ�񣬵�������ţ���������һ�ߡ�\n"NOR,obj,this_object());
	  obj->command("bow "+this_object()->query("id"));
	  command("nod "+obj->query("id"));
	  message_vision(HIG"\n$N������������������ǧ����������ɻ������֣�ִ��ɮ�����̡���\n"NOR,this_object());
    remove_call_out("zhangxing");
    call_out("zhangxing",5,me,this_object());
		return 1;
	}	
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& (me->query_temp(QUESTDIR5+"zhangxing")||me->query(QUESTDIR5+"over")))
	{
	  message_vision(HIY"$N��������ţ���¶��ʹ֮ɫ��\n"NOR,this_object());
		command("say ����ȷʵ�����������ӷ�");
		return 1;
	}	
	command("? "+me->query("id"));
	return 1;
}
void zhangxing(object me,object ob)
{
  if(!me) return;
  if(!ob) return;
  if(environment(me)!=environment(ob))
  {
  	ob->command("sigh");
  	message_vision(HIY"$N�ƺ���ԥ��һ�£�����վ��������������ȥ���������\n"NOR,ob);
  	tell_object(me,HIY"���ʱ��Ȼ�߿�������Ľ�����µ����������ɣ�\n"NOR);
   	me->delete(QUESTDIR5+"start");
   	me->delete_temp("quest/�����˲�");
	me->delete_temp("quest/busy");//�����ͻ��־ȡ��
  	return;
  }
	if(me->query(QUESTDIR3+"bad") && me->query(QUESTDIR5+"start")&& me->query_temp(QUESTDIR5+"yeerniang")&& !me->query_temp(QUESTDIR5+"zhangxing")&& !me->query(QUESTDIR5+"over"))
	{
	  message_vision(HIC"��ɮ֪���������̣������ܵĻ��ǵ������裬����Ƥ��֮�࣬�����������飬���������˳������»�����\n"
	                    "��ô�����ⷬ���跴����Ϊ���޽���ˣ�����һ��������ȥ������������Ƭ�̼�㽫���ȱ��ϡ����ϴ�\n"
	                    "�������Ⱥۣ�Ѫ��ɮ�¡������ִ���һ�����ȣ�$N֧�ֲ�ס�����ڵ��µ�˫��һ�����״���������\n"NOR,this_object());
    message_vision(WHT"\n$N������Ц���������Ҳ�ɱ�㣬�����Դ�����һ��Ϳ�ء���������ʮ�Ȳ���Ҳ�ա���\n"NOR,me);
		me->set_temp(QUESTDIR5+"zhangxing",1);
	if(me->query("family"))
	  command("chat "+me->query("family/master_name")+"Ҳ����һ����ʦ��û���ϵ������"+me->name()+"��Ȼ������˶񶾣�");
	else command("faint "+me->query("id"));
	command("inn "+me->query("id"));
    message_vision(WHT"\n$Nһʱ���������ģ���Ȼ���˹�ȥ��\n"NOR,this_object());
	command("faint");
	tell_object(me,HIY"\n�������Ц�������������ֻ��......����Ľ�ݵ�·�ϣ����¸���Σ�����ء�\n"NOR);
	this_object()->unconcious();
   }
   return;
}
		
int ask_xiaofeng()
{
	object room,me = this_player();
	object *obj;
	int x;
	if(me->query(QUESTDIR3+"bad") )
  {
  	command("heng");
  	command("say �ѵ����ǵ���ǿ�������߳���ԭ��������������㣿");
  	return 1;
  }
  	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   command("say "+RANK_D->query_respect(me) +"����С��ͨ���ɣ�");
	   return 1;
	}
	if(me->query(QUESTDIR3+"good") &&!me->query_temp(QUESTDIR4+"shaolinzhen")&& !me->query(QUESTDIR4+"start"))
	{	  
		if(!me->query_temp(QUESTDIR4+"askxuanci"))
		{
			message_vision(HIC"�㼱�������������ԣ�����Ϊ��������֮ս���ܾ��ɺ�����ֱ�Ͷ������֮�С�\n"NOR,me);
			command("ah "+me->query("id"));
		}	
		//����ʱ��;���������
		//ʱ��һ�죬����500K
        if(!me->query_temp(QUESTDIR4+"dagouzhen") && me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
		{
			command("say �����æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�");
			return 1;
		}
        if(!me->query_temp(QUESTDIR4+"dagouzhen") && me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000)
		{
			command("say ��"+RANK_D->query_respect(me) +"Ŀǰ�ľ������Ŀǰ�������Ҳ�ﲻ��ʲôæ������ץ�������ɣ�");
			return 1;
		}
	//ֻ��һ������
	obj = users();
	x = sizeof(obj);
	while(x--) {
		  if ( obj[x]->query_temp(QUESTDIR4+"askxuanci") && obj[x]!=me) 
		  {
			  command("nod "+me->query("id"));
			  command("say ��Ҳ��˵�����飬�Ѿ���"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"ǰ������Ӫ��ȥ�ˣ�"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�书��ǿ������Ҳ�޴󰭣�");	
			  return 1;
		  }
	  }
  	
	if(!me->query_temp(QUESTDIR4+"askxuanci"))
	{
		command("whisper "+me->query("id")+" ������棬�����Ե�������������������������Ķ࣬��Ҳ������ԭ���������һ��������\n"NOR);
		command("whisper "+me->query("id")+" ֻ�ǣ�������ε�֪��һ��Ϣ��"NOR);
		message_vision(HIY"$N����˵�������ҸմӴ��ɹ�����Ҳ�գ����ս�����أ������书�Ͽ���һ�°ɡ�����\n"NOR,me);
		command("nod "+me->query("id"));
	}
    else command("whisper "+me->query("id")+" ����ʧ���ˣ�Ҳ�գ��ٸ���һ�λ��ᡣ\n"NOR);
	command("whisper "+me->query("id")+" �������ҽ���������֮�С�");
	if (!(room = find_object("/d/shaolin/shaolinzhen")))
		room = load_object("/d/shaolin/shaolinzhen");
	if(!room)
	{ 
      	tell_object(me,HIR"\n�Ͽ���wiz�ɣ���Ȼ���䲻����!!!\n");
        log_file("quest/TLBB", sprintf("%s(%s)Ӫ������ƪ�������ļ�ȱ�٣�\n", me->name(1),me->query("id")) );
    }
    else
    {
      tell_room(environment(me),HIC""+me->query("name")+"���������ִҴҳ�ȥ�ˡ�\n"NOR, ({ me }));        
		  tell_object(me,HIR"����������������һ��С��֮�У�ȴ���Ķ˷ֱ�վ��һ�����ֵ��ӡ�\n");
		  //�趨��־
		  me->set(QUESTDIR+"time",time());
		  me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
		  me->move(room);
		  this_object()->move(room);
		  tell_object(me,HIY"\n��������������˻��֣����˳�ȥ��\n"NOR);
		  this_object()->move("/d/shaolin/fzjs2");

		  tell_room(environment(this_object()),HIC"�������ִҴһ����ˣ���ɫ���ǻ��š�\n"NOR, ({ this_object()}));    
		  log_file("quest/TLBB", sprintf("%s(%s)Ӫ������ƪ���������󷨡����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );                  
		  me->set_temp(QUESTDIR5+"askxuanci",1);
		  me->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
    }
    return 1;
	}	
	if(me->query(QUESTDIR3+"good")&& !me->query(QUESTDIR4+"over") &&(me->query(QUESTDIR4+"start")|| me->query_temp(QUESTDIR5+"dagouzhen")))
	{
		command("addoil "+me->query("id"));
		command("say "+RANK_D->query_respect(me) +"ȴ���˵á��������������"+RANK_D->query_respect(me) +"���ִ�֡�");
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
