// xln.c С��Ů
// By River@SJ 99.05
// ���� ��������Quest By River@SJ 9.25.2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_suo(); 
string ask_zhen();
string ask_shoutao();
string ask_yueyin();
int pfm_yufeng();
int pfm_hebi();
int ask_hubo();

void create()
{
	object ob;
	set_name("С��Ů", ({ "xiao longnv", "xiao", "longnv" }));
	set("title",HIW"��Ĺ����"NOR);
	set("nickname",HIC"�������"NOR);
	set("long","ӯӯ��վ��һλ�������׵�Ů�ӣ�����������һ��Ѫɫ���Եò԰��쳣��\n"+
		"����һϮ��ɴ��İ��£����������������\n");
	set("gender", "Ů��");
	set("age", 39);
	set("attitude", "friendly");
	set("no_bark",1);

	set("per", 48);
	set("str", 24);
	set("dex", 40);
	set("con", 25);
	set("int", 40);

	set("gmsanwu", 1);
	set("yueyin", 1);
	set("double_attack", 1);
	set_temp("double_attack", 1);
	set("shen", 10000);

	set("combat_exp", 4000000);
	set("max_qi", 9500);
	set("max_jing", 7600);
	set("eff_jingli", 6000);
	set("max_neili", 16000);
	set("neili", 17000);
	set("jiali", 50);
	set("unique", 1);

	set_skill("parry", 340);
        set_skill("hand", 340);
        set_skill("tianluo-diwang", 340);
	set_skill("force", 300);
	set_skill("dodge", 340);
	set_skill("sword", 340);
	set_skill("throwing", 340);
	set_skill("whip", 340);
	set_skill("meinu-quanfa", 340);
	set_skill("cuff", 340);
	set_skill("yunu-shenfa", 370);
	set_skill("yinsuo-jinling", 340);
	set_skill("yunu-jianfa", 340);
	set_skill("quanzhen-jianfa", 340);
	set_skill("yunu-xinjing", 350);
	set_skill("literate", 170);

	map_skill("force", "yunu-xinjing");
        map_skill("hand", "tianluo-diwang");
	map_skill("dodge", "yunu-shenfa");
	map_skill("cuff", "meinu-quanfa");
	map_skill("sword", "yunu-jianfa");
	map_skill("whip", "yinsuo-jinling");
	map_skill("parry","yinsuo-jinling");
	prepare_skill("cuff", "meinu-quanfa");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "xinjing" :),
		(: perform_action, "whip.yueyin" :),
		(: perform_action, "whip.sanwu" :),
		(: pfm_yufeng :),
	}));

	create_family("��Ĺ��", 3, "Ů����");

	set("inquiry", ([
		"���" : "�������ҷ������֪�����ܰ��ң���һֱ���������������ơ�",
		"Կ��" : "��....���ҿɼǲ�����������Ƿ��ڹ�Ĺ�����˰ɡ�",
		"������" : (: ask_suo :),
		"�����" : (: ask_zhen :),
		"����" : (: ask_shoutao :),
		"�׽�����" : (: ask_shoutao :),
		"����" : (: ask_yueyin :),
		"��������" : (: ask_yueyin :),
		"yueyin" : (: ask_yueyin :),
		"�ܲ�ͨ" : (: ask_hubo :),
			
	]));

	set_temp("apply/damage", 80);
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/armor", 80);
        
	setup();
	if (clonep()){
		ob = unew("/d/gumu/obj/shoutao");
		if (ob) {
			ob->move(this_object());
			ob->wear();        
		}
	}
	carry_object(BINGQI_D("changbian"))->wield();
	carry_object(BINGQI_D("changjian"));
	carry_object("/d/gumu/obj/yfzhen");
	carry_object("/d/gumu/obj/buxue1")->wear();
	carry_object("/d/gumu/obj/qun1")->wear(); 
}

void reset()
{
	object ob;

	if (clonep() && (ob = unew("/d/gumu/obj/shoutao"))) {
		ob->move(this_object());
		command("wear baijin shoutao");
	}
}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
	if (!fam || fam["family_name"] != "��Ĺ��"){
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if( ob->query("gender") != "Ů��") {
		command("wanfu " + ob->query("id"));
		command("say �ҿ�ֻ��Ůͽ����ȥ���ҷ�����԰ɡ�");
		return;
	}
	if((int)ob->query_skill("yunu-xinjing", 1) < 120) {
		command("say �ҹ�Ĺ�书�ڹ��ǻ�����"); 
		command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
		return;
	}
	if((int)ob->query_skill("sword", 1) < 100) {
		command("say �㽣����ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
		command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
		return;
	}
	if((int)ob->query_int() < 32) {
		command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say ��λ"+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	if((int)ob->query("shen") < 10000){
		command("say �ҹ�Ĺ�������߽����У�һ���������塣");
		command("say ��λ" + RANK_D->query_respect(ob)+"����������ȥ������������º������ɣ�");
		return;
	}
	command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("recruit " + ob->query("id"));
	ob->set("title",HIW"��Ĺ��������´���"NOR);
}

string ask_suo()
{
	object ob = this_player();
	mapping fam = ob->query("family");
	if (!fam || fam["family_name"] != "��Ĺ��" )
		return RANK_D->query_respect(ob)+"�����Ѿ�����δ�ý������ˣ�Ҳ��֪�����ںδ��ˡ�";
	if (ob->query_skill("yinsuo-jinling", 1) < 100)
		return "��λ"+ RANK_D->query_respect(ob) +"������������쳣�����Ƿ�Ӧ�ð��书����Щ��";
	ob->set_temp("marks/����", 1);
	command("nod " + ob->query("id"));
	return "�����������ͷ��ڴ����У����Ը����Ұɡ�";       
}

int pfm_yufeng()
{
	object me,weapon;
	me = this_object();
	weapon = present("changbian",me);
	if( me->is_busy()) return 0;
	if( me->query_temp("hebi")) return 0;
	if( objectp(weapon)){
		set("jiali", 1);
		command("wield bian");
		command("perform yufeng");
		if(random(10) > 5){
			set("jiali", 50);
			command("unwield bian");
		}
		return 1;
	}
	else {
		if(present("changbian", environment(me)))
		command("get bian");
		else new(BINGQI_D("whip"))->move(me);
		command("wield bian");
		set("jiali", 1);
		command("wield bian");
		command("perform yufeng");
		if(random(10) > 5){
			set("jiali", 50);
			command("unwield bian");
		}
		return 1;
	}
	return 1;
}

string ask_zhen()
{
	object me = this_player();
	object *list;
	int i, j=0;

	if (me->query("family/family_name") != "��Ĺ��")
		return "�㲻���ҹ�Ĺ�ɴ��ˣ���Ҫ���������ã�";

	if( me->query("family/generation") > 4 )
		return "�����ڻ��ò�������롣";

	if (present("yufeng zhen",me))
		return "�����ϻ�������룬��ô����Ҫ��";

	if ( me->query_temp("yfzhen"))
		return "�㲻�Ǹ�Ҫ�����������ô����Ҫ��ô̰�İ���";

	list = filter_array(objects(), (: $1->query("id") == "yufeng zhen":));

	i =  sizeof(list);
	while (i--)
		j += list[i]->query_amount();

	if ( j > 61)
		return "��Ӵ��������Ѿ������ˣ���Ȼ���Ҫ�ɡ�";

	new("/d/gumu/obj/yfzhen")->move(this_object());
	command("give 10 yufeng zhen to " + me->query("id"));
	me->set_temp("yfzhen", 1);
	return "��Щ�����������ȥ�ðɣ�";
}

string ask_shoutao()
{
	object me = this_player();

	if (me->query("family/master_name")!="С��Ů")
		return ("���������ҹ�Ĺ�ɵı���㲢���ҵĴ��ˣ����ܸ��㣡");

	if (present("baijin shoutao",this_object())) {
		command("give baijin shoutao to " + me->query("id"));
		return("�����׾͸����ˣ����Ҫ���Ʊ��ܺã�");
	}
	else return ("�������ˣ������Ѿ��������������ˡ�");
}

string ask_yueyin()
{
	object me = this_player();
	mapping fam = me->query("family");
	object *dest;
	int i, j = 0;

	if (!fam || fam["family_name"] != "��Ĺ��")
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

	if(me->query_skill("yunu-xinjing", 1) < 150 )
		return "�����Ů�ľ��ȼ��������޷��������磬����������! ";

	if(me->query_skill("yinsuo-jinling", 1) < 150 )
		return "�����������ȼ�������������������ʽ��˵�ɡ� ";

	if(me->query("yueyin")) {
		command("? "+me->query("id"));
		return RANK_D->query_respect(me)+"�����Ѿ�����������������ô��";
	}

	if ( me->query_temp("yueyin/ask"))
		return "�㻹����ȥ������";

	dest = users();
	i = sizeof(dest);
	while(i--) {
		if (userp(dest[i]) && !wizardp(dest[i]) && dest[i]->query_temp("yueyin/ask"))
		j++;
	}
	if(j >= 1)
		return "�ţ������ڱȽ�æ����Ȼ��������ɡ�";

	command("say �ţ������������ǽ����������似�У�������������ʹ�ô˼��ɣ���������Ҫ�����ϰ��");
	me->set_temp("yueyin/ask", 1);
	return "��������Ƭ���ԣ��Ƚ��ʺ���������ר��ȥ�����ɣ��ɲ�Ҫ���Ǵ�һ������Ŷ��";
}

void kill_ob(object me)
{
	command("heng");
	command("throw yufeng zhen at " + me->query("id"));
	::kill_ob(me);
}


int ask_hubo()
{
	object me= this_player();

	if(!me->query_temp("marks/askzhou")|| me->query("gmhb"))	{
			command("say ����ͯ��һ�ƴ�ʦ�����������򻨹������ӣ������ֲˣ�ݪ��������õ�Ҳ��ң���ڡ�");
	  	command("say ���пյ�ʱ�����ҵ�����������ȥ����̽����һ�°ɡ�");  
	  	 return 1;
	    }

  if( me->query_temp("marks/askzhou") ){
  	
  	command("say �ҹ�Ĺ����Ů�ľ������ı�������������������������������һ���֮�����ؼ�����ȫ�ڡ����Ķ��á����֣�������һ���ĵؿ����� ");
  	command("say ����������������Ĭ���������ʹ��Ů����������ʹȫ�潣����˫���������У���Ȼ��Ȼ��ͨ�� ");
 
    me->delete_temp("marks/askzhou");
    me->set_temp("tryhb",1);
    return 1;
  	}

	command("pat " + me->query("id"));

  return 1;	
	
}
