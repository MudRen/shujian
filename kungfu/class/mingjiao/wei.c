// NPC wei.c ΤһЦ
// Modify By River@SJ 99.06
// been job_npc
// Update By lsxk@hsbbs 2007/7/18   ���ӵ�����߽��������

#include <ansi.h>
#include <job_mul.h>

inherit NPC;
inherit F_MASTER;
string *drugs = ({
	MEDICINE_D("sanhuang"),
	MEDICINE_D("huiyang"),
	MEDICINE_D("yuling"),
	MEDICINE_D("yuzhen"),
	MEDICINE_D("tianwang"),
});

void destroy(object ob);
void create()
{
	set_name("ΤһЦ",({"wei yixiao","wei","yixiao"}));
	set("title","���̻��̷���");
	set("nickname",GRN"��������"NOR);
	set("long", "�������̵��Ĵ󻤷�֮һ������������\n"+
		"����ĸߴ�������ˣ�����һ����Ṧ��\n");
	set("age", 51);
	set("attitude", "peaceful");
	set("shen", -12000);
	set("str", 26);
	set("int", 26);
	set("con", 25);
	set("dex", 45);        

	set("max_qi", 3000);
	set("max_jing", 2400);
	set("eff_jingli", 2000);
	set("jiali", 70);
	set("combat_exp", 1200000);
	set("unique", 1);
	
	set("job_npc",1);

	set_skill("strike",180); 
	set_skill("literate",110);
	set_skill("dodge",190);
	set_skill("force", 150);
	set_skill("piaoyi-shenfa", 190);
	set_skill("hanbing-mianzhang",180);
	set_skill("shenghuo-shengong", 140);
	set_skill("parry", 150);
	map_skill("force", "shenghuo-shengong");
	map_skill("dodge", "piaoyi-shenfa");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("parry", "hanbing-mianzhang");
	prepare_skill("strike","hanbing-mianzhang");

	create_family("����", 36, "����");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "strike.xixue":),
	}));
	setup();
	carry_object("/d/mingjiao/obj/yel-cloth")->wear();
}

void init()
{
	::init();
        add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
}
void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping fam = ob->query("family");
        mapping my_fam = me->query("family");
        if(!fam || fam["family_name"] != "����"){
                command("say "+RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }
        if(fam["master_name"] == "���޼�"){
                command("haha");
                command("say "+RANK_D->query_respect(ob)+"���ǽ����״����ӣ�"+RANK_D->query_self(me)+"����������Ϊͽ��"); 
                return;
        }
        if (fam["generation"] == my_fam["generation"]){
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"�Ѱݹ���ʹΪʦ��"+RANK_D->query_self(me)+"����������Ϊͽ��");
                return;
        }        
        if ((int)ob->query_skill("shenghuo-shengong", 1) < 100) {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }        
        if ((int)ob->query_skill("dodge",1) < 100) {
                command("say ��ѧ�ҵ��Ṧ����������һ�����Ṧ������");
                command("say ���Ṧ���棬" + RANK_D->query_respect(ob)+"�Ƿ����ò�����");
                return;
        }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", GRN"���������������½���"NOR);
}

int accept_object(object who, object ob,object me)
{
   int exp,job,pot,bonus,gold, i, j =0, k, x, p;
	object* ppl;

	me = this_object();
	if(ob->query("name") != "Ѳ����" || ob->query("id") != "xunluo ling") {
		command("? "+who->query("id"));  
		return 0;
	}
	if(ob->query("owner") != who->query("id") && ! wizardp(who)){
		command("say �ߣ������Ǵ���͵���ģ�");
		call_out("destroy", 1, ob);  
		return 1;
	}
	if(!ob->query("task_ok") && ! wizardp(who)){
		command("say �������㻹�����ø�����»�ɡ�");
		command("pat "+who->query("id"));  
		return 0;
	}
	if(!who->query_condition("mj_xunluo") && ! wizardp(who)){
		command("say ��ô��ʱ�䣬�㶼����ȥ�ˣ�");
		command("disapp "+who->query("id"));
		call_out("destroy", 1, ob);  
		return 1;
	}
	command("nod");
	command("say Ը�������������е��Ӷ�����ڷ����ϣ�");
	bonus = who->query_temp("mj/attacker1");
	if(bonus > 7) bonus = 7;
        exp = 1200 + random(200) + bonus * 100;
	job = who->query("job_time/����");
	if(job< (who->query("job_time/����Ѳ��")+who->query("job_time/��������")) ){
		who->set("job_time/����",(who->query("job_time/����Ѳ��")+who->query("job_time/��������")));
		job = who->query("job_time/����");
	}
	//������ԭ����  ����Ҫ�����
	//job = who->query("job_time/����Ѳ��");
	gold = job/50 + random(job/50);

	if( gold < 1) gold = 1;
	if( gold > 15) gold = 14 + random(3);

	if (who->query("combat_exp") > 2000000)	exp = random(100) + bonus * 40 + 80;//��΢��һ��
	
	exp = who->add_exp_combat(exp,this_object(),"����Ѳ��");	
	//who->add("job_time/����Ѳ��", 1);
	//GIFT_D->check_count(who,this_object(),"����Ѳ��");
	//who->add("combat_exp", exp);
	
	if (who->query("combat_exp") > 2000000)
		pot = 100 + random(60);
	else
		pot= exp/5 + random(exp/10);

	who->add("potential", pot);
	p = who->query("mingjiao_job");
	if ( p > 0 ) {
		who->add("job_time/����", p);
		who->delete("mingjiao_job");
	}
	who->add("job_time/����", 1);	
	who->delete_temp("mj/attacker1");
	who->delete_temp("mj/over");
	if(who->query("potential") > who->query("max_pot")) 
		who->set("potential", who->query("max_pot"));
	MONEY_D->pay_player(who, gold * 10000);
	message_vision("\n$N����$nһЩ"HIY"�ƽ�"NOR"��\n"NOR,this_object(),who);
	command("whisper "+who->query("id")+" �������ˣ���Щ������ȥ�úÿ��һ���ɡ�");
	job += 1;
	tell_object(who,"���Ѿ�Ϊ�������"+chinese_number(job)+"�ι����ˣ��ٺú�Ŭ���ɡ�\n");
	log_file("job/xunshan",sprintf("%8s%-10s��%4d����������������%4d��Ǳ��%3d�����ھ���%d��\n",
		who->name(1),"("+who->query("id")+")",job,exp,pot,who->query("combat_exp")), who);
	call_out("destroy", 1, ob);
ppl=users();
	i = sizeof(ppl);
	while(i--) {
		if (userp(ppl[i]) && !wizardp(ppl[i]) && ppl[i]->query("jiuyang/wei"))
		j++;
	}
   if ( who->query("combat_exp",1 ) > 2000000 && job > 400) //Update By lsxk ������������������û��ô������skills�ֵ������ˣ����Խ���Ҫ��
		x = job%20;
	else 
		x = job%50;

	if ( wizardp(who))
		tell_object(who,sprintf("x = %d\n", x ));

   if(who->query_temp("sj_credit/quest/mj/jiuyang")){
       k=20;
       who->delete_temp("sj_credit/quest/mj/jiuyang");
   }
   else k=30;

	if( random(job) > 300
    && x == 0
    && random(who->query_int()) >= k
    && random(who->query_dex()) >= k
    && random(who->query("kar")+ who->query("pur")+ who->query("per")) >= k
    &&(( !who->query("buyvip") &&(j < 10|| random(j+1)>=j))|| who->query("buyvip"))
    && !who->query("jiuyang/wei")){
		command("whisper "+who->query("id")+" ���ȥ�Ž�������һ�Σ���������ʲô����Ҫ�����㡣");
		who->set("jiuyang/wei", 1);
		log_file("quest/jiuyang",sprintf("%s(%s)���������%d�ε�ʱ�򣬴�ΤһЦ���������йؾ����񹦵Ĵ��š�����%d��\n",
			who->name(1), capitalize(who->query("id")), job, j));
	}


	return 1;
}

void destroy(object ob)
{
	destruct(ob);
	return;
}

int do_kill(string arg)
{
	object ob,ob2; 
	object me = this_player();
	ob2 = this_object();

	if (!arg) return 0;
	ob = present(arg, environment(me));
	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;
        
	if (userp(ob)&& ob->query("family/family_name") == "����") {
		if (me->query("family/family_name") == "����") { 
		        message_vision(ob2->name()+"��$N�ȵ�����Ϊ���̵��ӣ���Ȼɱ�Լ���ͬ�ţ��������㣡\n", me);
                }
                else {
                        message_vision(ob2->name()+"��$N�ȵ����󵨿�ͽ����Ȼ����������Ұ��\n", me);
                        kill_ob(me);
                }
                me->set("vendetta/����", 1);
                return 1;
        }
        return 0;
}
