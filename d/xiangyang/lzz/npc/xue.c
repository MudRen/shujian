// xuemuhua.c ѦĽ��
// Creat By Looklove for a quest y2k 4.20
// Looklove fix hubei at 2000.8.23
// Looklove Modify at 2000.10.8

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int ask_me();
int ask_quest();
int ask_help(object);
int ask_teach();
int do_teach(string arg);

void create()
{
	set_name("ѦĽ��", ({ "xue muhua", "xue" }));
	set("long", 
		"�����Ǻų������е���ҽ����ѦĽ������˵����ͨҽ����������������\n");
	set("gender", "����");
	set("nickname",HIC"������"NOR);
	set("title",HIG"���Ȱ���"NOR);
	set("attitude","friendly");
	set("age", 42);
	set("str", 30);
	set("int", 30);
	set("con", 25);
	set("dex", 30);
	set("shen_type", 1);
	set("unique",1);
	set("no_get","Ѧ��ҽ̫���ˣ��㱳��������\n");

	set("vendor_goods", ({
		([ "name":MEDICINE_D("huiyang"), "number": 3 ]),
		([ "name":MEDICINE_D("jinchuang"), "number": 5 ]),
		([ "name":MEDICINE_D("jingmai/jingmai-book2"), "number": 1 ])
	}));

	set("max_jing", 1700);
	set("eff_jing",1700);
	set("max_jingli",2000);
	set("eff_jingli",2000);
        set("jiali", 100);
set("env/no_teach",1);
	set("max_qi", 3500);
	set("neili", 8000);
	set("max_neili", 5000);
	set("combat_exp", 1200000);

	set_skill("force", 229);
	set_skill("dodge", 229);
	set_skill("hand",229);
	set_skill("strike",229);
	set_skill("parry", 229);
	set_skill("lingbo-weibu",229);
	set_skill("beiming-shengong",229);
	set_skill("zhemei-shou",229);
	set_skill("liuyang-zhang",229);
	set_skill("literate",240);
	set_skill("jingmai-xue",180);
	set_skill("medicine",180);
	set_skill("art",180);
		
	map_skill("force", "beiming-shengong");
	map_skill("parry", "zhemei-shou");
	map_skill("dodge", "lingbo-weibu");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	
	prepare_skill("hand", "zhemei-shou");

	set("inquiry", ([
		"���": "��ĵ�ѧ�ʿ��Ǻ���°���",
		"����" : (:ask_me:),
		"ѧ��" : (:ask_quest:),
		"�书" : (:ask_teach:),
		"����" : (:ask_help:),
	]) );

	setup();
	add_money("gold", 1);
	carry_object(ARMOR_D("cloth"))->wear();
}

int ask_me()
{
	object ob;
	ob=this_player();

      if ( ob->query("family/family_name")== "��ң��"
           && (ob->query("eff_qi") < ob->query("max_qi")
	   || ob->query("eff_jing") <= ob->query("max_jing"))
          ){
	command("touch "+ob->query("id"));
	command("say û�뵽����������ͬ��ʦ�ֵܣ�\n");
     	command("say ��ң��ʦ�������˼�����ɺã���\n"); 
message_vision("Ѧ��ҽ�ó�һ��������������$N���˲�λ������Ѩ����$N�о�������ˡ�\n", ob);
	call_out("recover", 5, ob);
	ob->start_busy(3);
        return 1; 
        }


	if (ob->query("xue/teach")<5) {
	    command("hehe");
	    command("say �����书�Ƿ���ָ����һЩ��");
	    return 1;
	}
	if (ob->query("eff_qi") >= ob->query("max_qi")
	&& ob->query("eff_jing") >= ob->query("max_jing"))
	{
		command("? "+ob->query("id"));     
		command("say �����û���ˣ������������ң�\n");
		command("knock "+ob->query("id"));
		return 1;
	}
	else
	{
		message_vision("Ѧ��ҽ�ó�һ��������������$N���˲�λ������Ѩ����$N�о�������ˡ�\n", ob);
		ob->start_busy(3);
		call_out("recover", 5, ob);
		ob->delete("xue/teach");
		return 1;
	}
}

void recover(object ob)
{
	if (!ob || !present(ob)) return;
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("һ����Ĺ����ȥ�ˣ�$N���������Ѿ�����Ȭ���ˡ�\n",ob);
	command("say �����ն�,��С�ĵĻ����´����û��ô�����ˡ�\n");
	command("pat "+ob->query("id"));
}

int ask_teach()
{
	object me = this_player();
	
	if (me->query("combat_exp")<500000) {
	   command("say ��Ĺ���̫��ҿ�û��Ȥ��");
	   return 1;
	} else {
	   command("thank");
	   command("say ��л���һ�úñ���ġ���ʹ�� teach xue <skill> ��ָ���ҡ�");
	   return 1;
	}
}

int ask_quest()
{
	object me = this_player();
	
	if (me->query("combat_exp")<500000) {
		command("say ��Ĺ���̫���ˡ�");
		return 1;
	}
	if (me->query_int() < 30) {
		command("say �㻹�Ǻú�����ѧ�ʰɣ���ѧ�ʿɲ��Ǽ����׵��¡�");
		return 1;}
	if (me->query_skill("jingmai-xue",1)>150) {
		command("say ��������Ҳ�Ǹ�ҽ�����֣��ҵ�������ֽ̡�");
		return 1;}
	if (me->query("xue/teach")<20) {
		command("say ��˵�����书��������");
		command("wink");
		return 1;}
	if (me->query_skill("jingmai-xue",1)>=140) {
		command("say ѧҽ��Ҫ���ε�֮�ģ����Ƿ�Ը�����ȥ�ȸ��ˣ�");
		return 1;}
	if (me->query_skill("jingmai-xue",1)<120) {
		command("say �ҿ��������֣����������ڵľ���ѧ��Ϊ�Ѿ������ˡ�");
		return 1;}
	else {
		command("say ��ȥ�ú��о��ɡ�");
		command("addoil");
		message_vision(HIY"Ѧ��ҽ��$Nһ����ĸ��ۡ�\n"NOR, me);
		new(MEDICINE_D("jingmai/jingmai-book4"))->move(me);
	return 1;
    } 
}

int ask_help(object me)
{
   	int i;
    	object *list;
    	object where, target;
    	object potion;
	
	if (this_player()) me = this_player();
	if (!me) return 0;
    	if (me->query_temp("count")>10) {
		command("say �����ƺ�ûʲô����Ҫ��Ԯ��");
		me->delete_temp("count");
		return 1;
	}
    	if (me->query("combat_exp")< 500000 ) {
		command("say �㾭��̫�ͣ�ѧ��Ҳû�á�");
		return 1;
	}
    	if (me->query_skill("jingmai-xue",1)<140) {
		command("say �㾭��ѧ����̫�͡�");
		return 1;
	}
    	if (me->query_skill("jingmai-xue",1)>=150) {
		command("say ��ʵϰ�Ĺ����ˣ�Ӧ����ȥ�������һ���о���");
		return 1;
	}
    	if (query("waiting")) {
		command("say ��ȵȰɣ����ڵ����ء�"); 
		return 1;
	}
    	list = filter_array(users(), (: $1->query("combat_exp")>=500000 :));
    	target = list[random(sizeof(list))];
    	i = target->query("combat_exp")/5;
    	where = environment(target);
    	
    	if ((!environment(target)) ||
	(wizardp(target) || target->query("env/invisibility")) ||
	(!interactive(target)) ||
	(target->query("combat_exp")<me->query("combat_exp")-i*2) ||
	(target->query("combat_exp")>me->query("combat_exp")+i*2) ||
	(query_idle(target) > 2000) ||
	(target->query("id") == me->query("id"))){
		me->add_temp("count",1);
		call_out("ask_help", 1, me);
		return 1;
	} 
	else {
		command("say ��˵���˱������ɵĶ����������Զ�ҩ���Լ�ȴ��֪��");
		command("say ���ҵ�"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+CYN"��");
		command("say ��ȥ"+HIG+where->query("short")+CYN+"���ҿ���");
		command("thank");
		command("say ����ƿҩˮ��heal <"+target->query("id")+"> �Ϳ����ˡ�");
		potion = new(__DIR__"obj/potion");
		potion->set("target",target->query("id"));
		potion->move(me);
		set("waiting",1);
		return 1;
    	}
}

int do_teach(string arg)
{
	object me = this_player();
	string ob, skill;
	object target;

	if (me->query("combat_exp")<500000) {
		command("say ��Ĺ���̫���ˡ�");
		return 1;
	}
	if(!arg || sscanf(arg,"%s %s",ob,skill)!=2)
		return notify_fail("��Ҫ��ʲô��\n"); 
	target = present(ob);
	if (!target) return notify_fail("����û������ˡ�\n");
	if (target != this_object())
		return notify_fail("�������� BUG ô��\n");
	if (me->query_skill(skill,1)<100)
		return notify_fail("����������̫���ˣ�Ѧ��ҽ��û��Ȥ��\n");
        if (target->query_skill(skill,1)>=100)
		return notify_fail("Ѧ��ҽ����������Ѿ������ٽ����ˡ�\n");
	target->set_skill(skill, target->query_skill(skill, 1)+10);
	message_vision("$N��$n��ϸ�ؽ�˵��\n",me, target);
	me->add("xue/teach",1);
	return 1;
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_teach","teach");
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment()) return;
	if(ob->query_temp("xue_finish")) {
		command("ah");
		command("say ����û����Щ���޵Ķ����óѡ�");
		command("thank");
		command("say ���Ȿ�زص���������ȥ�о��о��ɣ�");
		message_vision(HIY"ѦĻ������$Nһ����˼��ǧ�﷽��\n"NOR, ob);
		new(MEDICINE_D("jingmai/jingmai-book5"))->move(ob);
		ob->delete_temp("xue_finish");
		delete("waiting");
		return; 
	}
	command("say ��λ"+RANK_D->query_respect(ob)+"���ˣ�������ʲô��ô��");
}
