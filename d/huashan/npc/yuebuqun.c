// NPC: /d/huashan/npc/yuebuqun.c
// Date: Look 99/03/25
// Modify by Looklove 2000,12,15
// By Spdierii@ty ��Ҫnpc.ɱ����
// by lsxk@hsbbs  ͳһ�����㷨 2007/1/10

inherit NPC;
inherit F_MASTER;

#include <job_mul.h>
#include <ansi.h>
string ask_zhengqi();
string ask_zixia();
string ask_me1();
string ask_me2();
string ask_pay();
string ask_fail();
string ask_qizong();

void create()
{
	set_name("����Ⱥ",({"yue buqun", "yue", "buqun" }));
	set("title","��ɽ�ɵ�ʮ����������");
	set("nickname","���ӽ�");
	set("long", "������ڽ���������Զ����������𣬻�ɽ�������ˡ�\n");
	set("age", 40);
	set("attitude", "friendly");
	set("no_bark",1);
	set("shen_type", 1);
	set("job_npc", 1);
	set("no_get", 1);

	set("per", 25);
	set("pur", 10);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi",3800);
	set("qi", 3800);
	set("max_jing", 2400);
	set("jing",2400);
	set("eff_jingli", 2700);
	set("jingli", 2700);
	set("max_neili", 5500);
	set("neili", 5500);
	set("jiali", 50);
	set("combat_exp", 2400000);
	set("score", 30000);
	set("chat_chance_combat",100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yangwu" :),
		(: perform_action, "sword.feijian" :),
		(: perform_action, "sword.junzi" :),
		(: exert_function, "zixia" :),
		(: perform_action, "sword.kuaijian" :),
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "sword.sanqing" :),
		(: perform_action, "cuff.leidong" :),
		(: exert_function, "zixia" :),
	}));

	set_skill("poyu-quan", 180);
	set_skill("cuff", 180);
	set_skill("sword",  180);
	set_skill("dodge",  180);
	set_skill("force",  180);
	set_skill("parry",  180);
	set_skill("literate",100);
        set_skill("zixia-gong", 380);
        set_skill("huashan-qigong", 180);
   set_skill("huashan-qigong", 180);
	set_skill("huashan-jianfa",  180);
	set_skill("huashan-shenfa",  180);
	set_skill("zhengqi-jue", 180);
    set_skill("hunyuan-zhang", 180);
    set_skill("strike", 180);
    map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");
	map_skill("force","zixia-gong");
	map_skill("sword","huashan-jianfa");
	map_skill("parry","huashan-jianfa");
	map_skill("cuff","poyu-quan");
	prepare_skill("cuff","poyu-quan");
	create_family("��ɽ��",13,"����");

	set("inquiry", ([
		"��ϼ�ؼ�"	: (: ask_zixia :),
		"zixia"		: (: ask_zixia :),
		"miji"		: (: ask_zixia :),
		"ʧ��"		: (: ask_fail :),
		"fail"		: (: ask_fail :),
		"�Ͷ�����"	: (: ask_me1 :),
		"job"		: (: ask_me1 :),
		"����"		: (: ask_me2 :),
		"���"		: (: ask_me2 :),
		"finish"	: (: ask_me2 :),
		"������"	: (: ask_zhengqi :),
		"zhengqi-jue"	: (: ask_zhengqi :),
//                   "����֮��"      : (: ask_qizong :),
	]));

	setup();
	carry_object(BINGQI_D("sword"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
		reincarnate();
}

void init()
{
	object ob;
	::init();
	ob = this_player();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	int shen;
	if(!me) return;

	if ( file_name(environment(this_object())) != this_object()->query("startroom")) return;

	shen = me->query("shen");
        if(shen <= -200000 && me->query("family/family_name") == "��ɽ��" && me->query("quest/huashan")=="����"){
		command("disapp "+me->query("id"));
		command("say ���������������а�����ӽ������㲻���ǻ�ɽ�����ˣ�");
 command("expell " + me->query("id"));
me->delete("quest/huashan","����");
	}
	if(shen <0 && shen > -200000 && me->query("family/family_name") == "��ɽ��"){
		command("sigh "+me->query("id"));
		command("say �ҿ����������������а��������ǲ�������������ʲô���£�");
		command("say ������Ҳ鵽�����������һ�ɽ�������£��Ҷ������㣡");
	}
}

void attempt_apprentice(object ob)
{
	mapping fam;
	if ( mapp(fam=ob->query("family"))
	 && (string)fam["family_name"] != "��ɽ��"
	 && (int)ob->query("is/huashan")==1 ) {
		message_vision(CYN "$N���������ɽ�ɵ���ͽ��������ʲô ������\n"NOR, ob );
		command("kick "+ob->query("id"));
		return;
	}
if ( ob->query("fengset") && !ob->query("relife/relifed")) {
		command("say �㲻���Ѿ����˽��ڵ�ǰ��Ϊʦ��ô��");
		return;
	}
/*
        if(ob->query("quest/huashan")=="����"){
    command("heng");
    command("say �ߺߣ����ڵ��������뿪��ɽ�������ǻ�ɽ�ɵ��ӣ�����������ѵ���������������֮λ��");
    return;
        }
*/

	if ( ob->query("gender") != "����" ){
		command("say ��ֻ����ͽ��" + RANK_D->query_respect(ob) + "��ذɡ�");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) + "�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ��Ҿ���������,���ҪΪ���ǻ�ɽ����������");
	command("recruit " + ob->query("id"));
	ob->set("title",HIW"��ɽ�������״�����"NOR);
  ob->set("quest/huashan","����");
}

string ask_qizong()
{
    object me;
    mapping fam;
    me=this_player();

   if ( mapp(fam=me->query("family"))
    && (string)fam["family_name"] != "��ɽ��"){
    command("? "+me->query("id"));
    return "��Ϊ" + RANK_D->query_respect(me) + "����������ҥ����\n";
    }

   if (me->query("quest/huashan")=="����")
       return "���꽣��֮����������������ɽ���֣����Ҫ�ú����������ɽ�ɰ���\n";

   if (me->query("quest/huashan")=="����")
       return "�ߺߣ����ڵ��������뿪��ɽ�������ǻ�ɽ�ɵ��ӣ�����������ѵ���������������֮λ��\n";

   if ((int)me->query("combat_exp")<1000000)
       return "��������ɽ�ɲ��Ұ�����Щ��������㻹����������\n";

   if(me->query_temp("quest/huashan/asked")){
       add_action("do_choose","answer");
       return "��ô�����������ظ�˵һ�㣿�㵱��ͯ�����°���";
   }
   command("say �һ�ɽ�ɵ�ȷ�н���֮�֣����껪ɽ��Ů��һս��ͬ���ֵ�ȴ�໥˺ɱ���Ҳ��̶ð���");
   command("cry "+me->query("id"));
   command("say �����ڵ����˽���������Ԧ����������ν������������ľ��Ϊ��������Ϊ�أ���Ϊ����\n"+
   "�ڹ�һ���гɣ�����������Ȼ��ͬһ�ն���ټ��ϱ������������ġ���ϼ�񹦡���\n"+
   "������ʮ�أ�������Щֻ�Ứ�ν��У��ڹ�ƽƽ�Ľ��ڵ��ӿɱȵģ�");

   add_action("do_choose","answer");
   me->set_temp("quest/huashan/asked",1);
   return me->name(1)+"�����Ҫ�ӱ���������ʼ������ѭ��������а���";
}

int do_choose(string arg)
{
    object me=this_player();
    if(!me->query_temp("quest/huashan/asked")) return 0;

    if(!arg) return notify_fail("����ش�ʲô��\n");

    if(arg!="��" && arg !="yes") return notify_fail("��ش��ǡ�����ʾ��ͬ������\n");
    if(arg=="��" && !me->query("quest/huashan")){
        me->set("quest/huashan","����");
        message_vision(HIM"$N���˵�ͷ�������ơ��ǣ�ʦ������\n"NOR,me);
        return 1;
    }
    return 0;
}

string ask_me1()
{
	int i;
	object ob, me, name1, ling;
	me=this_player();
	ob = this_object();
	ling = present("ling pai", me);
	name1 = me->query("id");
	i = me->query("shen");
if(me->query_temp("mb")) 
           return "�㻹����ȥ˼�������˼��ȥ�ɡ� ";
	if (!wizardp(me) && me->query("shen") < 10000)
		return "����¶�׹�, ����ȥ�Ͷ�����? ";

	if (!wizardp(me) && me->query_temp("hs/jobji"))
		return "�㲻�ܹ�˵ѽ������������ɼ����ҿ�����\n";

	if (!wizardp(me) && (int)me->query("combat_exp") < 100000)
		return "���书δ�ɣ���ôΣ�յ������Ǳ����ˣ�\n";

	if (me->query("job_name") == "�Ͷ�����" && !wizardp(me))
		return "����û����˵�ж���Ϊ�����գ����Լ�ȥ��ϰ�书ȥ�ɣ�";

	if(!wizardp(me) && me->query_condition("job_busy"))
		return "��������æ�������������أ�";

	if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
		return "����������û�и���������㻹���ȴ����������������˵�ɡ�";


	ob = new(__DIR__"obj/ling");
	ob->set("ever_owner",getuid(me));
	me->set_temp("hs/jobji",1);
	command("nod "+me->query("id"));
	ob->move(me);
	ob->set_temp("hsjob", name1);
	me->apply_condition("hs_job", 30 + random(5));
	me->apply_condition("job_busy", 30);
	me->set_temp("hs_time", uptime());
	tell_object(me, "����Ⱥ������һ�����ơ�\n");
	return "��˵���ڻ�ɽ������������һЩ������ɧ�Ű��գ���ȥѲ��һ�£��������˲�������\n";
}

string ask_zhengqi()
{
	mapping fam;
	object me, ob;
	int shen, exp, i;
	me = this_player();
	ob = this_object();
	shen = (int)me->query("shen", 1);
	exp = (int)me->query("combat_exp", 1);
	i = (shen - exp);
	fam = me->query("family");

	if (!fam || fam["family_name"] !="��ɽ��")
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��\n";
	if( i < 1000 )
		return "�������֮����������ν���ָ�������������\n";
	if( (int)me->query_skill("zhengqi-jue", 1) < 150 )
		return "���������δ����򣬿������޷�ָ���㡣\n";
	if( (int)me->query_skill("zhengqi-jue", 1) >= 200 )
		return "����������ѵ���򣬿������޷�ָ���㡣";
	if( (int)me->query("jing", 1) < 100 )
		return "����������״��̫���ˣ����޷������������ľ���֮����\n";
	if( (int)me->query("potential", 1) < 2 )
		return "������Ǳ�ܲ��㣬���޷�ָ���������������\n";
	me->improve_skill("zhengqi-jue", 100 + random(100));
	me->add("shen", -1000);
	me->add("potential", -1);
	me->receive_damage("jing", random(100));
	tell_object(me, HIC"��е����м���������������\n"NOR);
	return  "�ðɣ���Ȼ�����������������Ҿ�ָ����һ�¡�\n" ;
}

string ask_me2()
{
	return "��������أ�";
}

int accept_object(object me, object ling)
{
	object name1;
	int getshen, total_job_times, done,gold,gold2,total_job_times2, tb,i,j ;
object* ppl;	
name1 = me->query("id");



	if( ling->query("id") != "ling pai")
		return notify_fail("����Ⱥ˵��������ѽ����ɽ�ɾ�Ȼ������������ƭ�ӣ�\n");
	if( ling->query_temp("mmr") != name1 && !wizardp(me)){
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/��ɽ",1));
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("����Ⱥ˵��������ô��ôû�ã�û��ȥ�ҵ�������\n");
	}
	if( ling->query_temp("hsjob") != name1 && !wizardp(me)) {
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/��ɽ",1) * 5);
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("����Ⱥ˵���������������ô��\n");
	}
	done = (int)ling->query_temp("done", 1);
	if( done < 2 && !(done==1 && me->query_temp("hs/robot")) )
		return notify_fail("����Ⱥ˵�����㻹û���ʦ���������ء�\n");
	if ( !me->query_temp("hs/jobji") && !wizardp(me)){
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/��ɽ",1) * 5);
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("����Ⱥ˵����������ƴ�����͵���ģ�\n");
	}
	if ( !me->query_condition("hs_job") && !wizardp(me)){
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/��ɽ",1) * 5);
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("����Ⱥ˵��������ôȥ����ô��ʱ�䣿\n");
	}
	write("����Ⱥ���˿�������ơ�\n", me);
	command("thumb "+ me->query("id"));
	command("say ����" + RANK_D->query_respect(me) + "�պ�������£����кñ���\n");
   getshen = 1;
	if( me->query("family") && me->query("family/family_name") =="�һ���") getshen = 0;


   if(done!=2)
       TASKREWARD_D->get_reward(me,"��ɽ",getshen,0,0,random(2)+1,0,0,0,this_object());
   
else 
       TASKREWARD_D->get_reward(me,"��ɽ",getshen,0,0,5-random(2),0,0,0,this_object());

	

	me->delete_temp("hs_time");
	me->clear_condition("hs_job");
	me->clear_condition("job_busy");
	me->set("job_name","�Ͷ�����");
              gold= 2000+random(1000);
      
        gold2=gold/5000+random(gold/5000);
              me->add("balance", gold);

	me->delete_temp("hs/jobji");
	me->delete_temp("hs/have");

	me->delete_temp("hs/power");
	me->delete_temp("hs/robot");
	me->delete_temp("mb");
	call_out("destroying", 1, ling);



	// ������ quest ����
	// ����ֵ���� 2M �� ��ɽ�����ţ�ؤ�������������� 400
	// ��ɽ�����ţ�ؤ�����֮��Ϊ 50 �ı���
	// ��Ե��������� 25
	// me->query("mianbi") < me->query("mianbi")/100000 + 1
	// by mxzhao 2004/05/07


	total_job_times = me->query("job_time/��ɽ") + me->query("job_time/����") + me->query("job_time/ؤ��");
	total_job_times2 = me->query("job_time/��ɽ") + me->query("job_time/�䵱");


if(me->query("family/family_name")=="��ɽ��"&& !me->query("fengset"))
{
ppl=users();
i=sizeof(ppl);

while(i--){
if( userp(ppl[i])&& !wizardp(ppl[i])&&!ppl[i]->query("no_pk")&& ppl[i]->query("fengset"))
        j++;
          }
	if (random(me->query("job_time/��ɽ")) >400
		&& random(me->query("job_time/����")) >400
                &&( (me->query_temp("sj_credit/quest/hs/jiujian") && random(me->query("kar")) >= 24 )|| random(me->query("kar")) >= 26) 
                &&( random(me->query("job_time/ؤ��")) >100 || random(me->query("combat_exp"))>2000000 )
		&& !me->query("fengset")
		&& !me->query_temp("mb")
//              && !me->query("quest/hsjf/fengyi4_time")
		&& (me->query("mianbi") < me->query("combat_exp")/500000 + 1)
		&& total_job_times % 50 == 0 
                && (     ( !me->query("buyvip")&& (j<=9 ||random(j+1)>=j ))  || me->query("buyvip"))
                 ) 
	{
		me->set_temp("mb", time());
		me->add("mianbi", 1);
		log_file("quest/jiujian",sprintf("%8s%-10s��%4d�λ�ɽ����ʱ����˼������ڣ����ţ�%4d��ؤ��%4d������%2d���Σ�%d��\n",
			me->name(1),"("+capitalize(me->query("id"))+")",me->query("job_time/��ɽ"), me->query("job_time/����"),
			me->query("job_time/ؤ��"), me->query("kar"), me->query("mianbi")),me);
		command("say "+me->query("name")+"��ɱ�˲��ٶ��ˣ�δ��ɱ�����ز�����˼���������ڰɡ�\n");
	}
}


if (wizardp(me)||random(me->query("job_time/��ɽ")) >400
		&&( random(me->query("job_time/�䵱")) >400 || random(me->query("combat_exp"))>5000000 )
                && random(me->query("kar")) >= 28
		&& !me->query_temp("mz_entrance")
		&& !me->query("quest/xxdf/pass")
//		&& me->query("family/family_name")=="�������"
		&& total_job_times2 % 50 == 0 ) 
	{
		me->set_temp("mz_entrance", 1);
		command("say "+me->query("name")+"����˵ħ�̽��������ں����������ף���ȥ����ɱ�ˣ��Ҿ��������������ɡ�\n");
		log_file("quest/xixing",sprintf("%8s%-10s��ɽ����ʱ��ȥ÷ׯ����ɽ��%4d���䵱��%4d������%2d��\n",
			me->name(1),"("+capitalize(me->query("id"))+")",me->query("job_time/��ɽ"), 
			me->query("job_time/�䵱"), me->query("kar")),me);
	}
	return 1;
}

string ask_zixia()
{
	mapping fam;
	object me;
  int time;
	
	me = this_player();
	fam = me->query("family");
 
 time= time()-me->query("quest/zixia/time");
 
	if (!fam || fam["family_name"] !="��ɽ��")
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";
	
	
	if((int)me->query_skill("huashan-jianfa", 1) < 451 )
		return "�����⴫���������ɾ�����ϼ��������������ǳ������δ��Ϊʱ���硣";

if( me->query_temp("hs/askzixia") || time<86400 )

        return  "�Ҳ��Ǹ������������֮���������⣬�㻹���Ͻ�ȥ�ң�" ;

	me->set_temp("hs/askzixia",1);
        return  "��ϼ�ؼ����һ�ɽ������ǰ��ʱ�䲻֪������δ��ˡ�" ;
}

string ask_fail()
{
	object me,ling;
	me = this_player();
	ling = present("ling pai", me);
	if(! me->query_temp("hs/jobji"))
		return "����û������񣬺�νʧ�ܰ���";
	if( ling && ling->query_temp("hsjob") == me->query("id"))
		destruct(ling);
	me->delete_temp("hs/jobji");
	me->delete_temp("hs/have");
	me->delete_temp("hs/power");
	me->delete_temp("hs/robot");
	me->clear_condition("hs_job");
	me->apply_condition("job_busy", 3+random(4));
	me->add("combat_exp", -(40+random(30)));
	return "��Ȼ��ˣ�Ҳ������ǿ����������°ɡ�";
}

void destroying(object ling)
{
	if (ling) destruct(ling);
}
void die()
{
	object ob;
	if (!query_temp("living"))
	{
		ob = new("/d/huashan/npc/yuebuqun");
		ob->move("/d/huashan/zhengqi");
	}
	::die();
}


