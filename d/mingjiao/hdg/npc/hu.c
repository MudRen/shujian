#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int ask_me();
int ask_quest();

void create()
{
	set_name("����ţ", ({"hu qingniu", "hu"}));
	set("long", 
		"�����ǽ����������ĵ���ҽ�ɺ���ţ��\n"
		"����������������̵��ӣ����ǲ�����εģ����\n"
		"���С��������ȡ�����š�\n");
	set("title",HIW"����ҽ��"NOR);
	set("nickname",HIB"��������"NOR);
	set("rank_info/rude", "��������");
	set("attitude","peaceful");
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("per", 20);
	set("gender", "����");
	set("age", 37);
	set("shen_type", 0);
	
	set("unique", 1); 
	set("no_get","��̫���ˡ�\n");
	set("vendor_goods", ({
    (["name":MEDICINE_D("huiyang"),"number": 10]),
    (["name": MEDICINE_D("jinchuang"),"number": 10]),
    (["name": MEDICINE_D("qingxin-san"),"number": 10]),
    (["name": MEDICINE_D("huxin-dan"),"number": 10]),
    (["name": MEDICINE_D("heishi"),"number": 10]),
    (["name": MEDICINE_D("sanhuang"),"number": 10]),
    (["name": MEDICINE_D("baicao"),"number": 10]),
    (["name": MEDICINE_D("yaocao"),"number": 10]),
    (["name": MEDICINE_D("yuling"),"number": 10]),
    (["name": MEDICINE_D("yuzhen"),"number": 10]),
	    }));
	set("combat_exp", 500000);

	set("max_qi", 2000);
	set("max_jing", 2000);
	set("eff_jingli",2000);
	set("max_jingli",2000);
	set("eff_jing",2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",50);
	
	set_skill("dodge",100);
	set_skill("force", 100);
	set_skill("literate",200);
	set_skill("hand",100);
	set_skill("strike",100);
	set_skill("hanbing-mianzhang",100);
	set_skill("yingzhua-shou",100);
	set_skill("piaoyi-shenfa", 100);
	set_skill("shenghuo-shengong", 100);
	set_skill("parry", 100);

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
		"���": "��ĵ�ѧ�ʿ��Ǻ���°���",
		"����" : (:ask_me:),
		"����" : (:ask_me:),
		"�ⶾ" : (:ask_me:),
		"����ѧ" : (:ask_quest:),
	]));

	set("book9",1);
	set("book10",1);
	
	setup();
	
	carry_object(ARMOR_D("thd_cloth1"))->wear();
}


void init()
{       
	object ob;
	::init();
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
       if(!ob || environment(ob) != environment()) return;
       command("say ��λ"+RANK_D->query_respect(ob)+"����������ʲô��ô��");
}


int ask_me()
{
	object ob;
	ob=this_player();

	if (ob->query("family/family_name")!="����") {
	    command("sneer");
	    command("say �㲻�����̵��ӣ�����Ҫ�����ˡ�");
	    return 1; }
	if (ob->query("eff_qi") >= ob->query("max_qi")
	&& ob->query("eff_jing") >= ob->query("max_jing")
	) {
		command("? "+ob->query("id"));     
		command("say �����û���ˣ������������ң�");
		command("knock "+ob->query("id"));
		return 1;
	}
	if (sizeof(ob->query_conditions_by_type("poison"))) {
		command("say ���еĶ�������Ϊ����������������ɡ�");
		return 1;
	}
	message_vision(HIW"����ţ����$N���ϵ�Ѩ������ʩ���롣$N�о�������ˡ�\n", ob);
	ob->start_busy(3);
	remove_call_out("recover");
	call_out("recover",5,ob);
	return 1;
}

void recover(object ob)
{
	if (!ob) return;
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("eff_jing", ob->query("max_jing"));  
	message_vision("����һ�����$N����������ȫ�ظ��ˣ�\n",ob);
	command("hehe "+ob->query("id"));
}

int ask_quest()
{
	object me = this_player();
	object book;
	if (me->query_int() < 40) {
		command("say �㿴��һ��������������ѧ�ҵľ���ѧ��");
		return 1;}
	if (me->query_skill("jingmai-xue",1)<170) {
		  command("laugh "+me->query("id"));
		command("say ���Ⱥúô�û����ɡ�");
		return 1;}
	if (present("jingmai book",me)) {
		command("say һ�ζ�̫���鲻�ð���");
		return 1;}
	if (me->query_skill("jingmai-xue",1)<180) {
		command("say �ðɣ������ȥ�ú��о��ɡ�");
		message_vision(HIG"����ţ��$Nһ��������ͼ��\n"NOR, me);
		new("/clone/medicine/jingmai/jingmai-book8")->move(me);
		return 1;} else
	if (me->query_skill("jingmai-xue",1)<190) {
	   if (me->query_temp("hu/quest1") == 3 && query("book9") > 0) {
		command("ah");
		command("say ԭ���޼��Ѿ����ұ����ˣ���л���������һ�ˡ�");
		command("say �Ȿ����������ȥ�ú��о�һ�°ɡ�");
		  book = new(MEDICINE_D("jingmai/jingmai-book9"))->move(me);
		  add("book9",-1);
		return 1;}
		command("say �������ǿ��������ӣ�����ɽ�Ǽһ����");
		command("say ��ϧ���书ʵ�ڲ��硣");
		command("sigh");
		me->set_temp("hu/quest1",1);
		return 1;} else
	if (me->query_skill("jingmai-xue",1)<200) {
	   if (present("tieyan ling",me) && query("book10") > 0) {
		command("oh");
		command("say ��Ȼ��ʵ���޷�����ǰ����Ҳ�Ͱ��ˡ�");
		command("say ��Ҫ�Ҵ���ҽ����");
		command("ok hu");
		command("say �Ȿ������ľ�����һ����Ѫ���ģ���ú��о��ɡ�");
		  destruct(present("tieyan ling",me));
		  book = new(MEDICINE_D("jingmai/jingmai-book10"))->move(me);
		  add("book10",-1);
		return 1;}
		command("say �޼��Ǻ���ɱ������ͨ�������ҵĴ��");
		command("say ��˵���Ѿ���Ϊ���̽����ˡ���ʵ���������һ�氡��");
		command("hmm");
		me->set_temp("hu/quest2",1);
		return 1;}
}
