// gu.c ������
// by pishou and zqb :)
// Updated by Jpei

#include <ansi.h>
inherit NPC;

string ask_jiannan();
string ask_degree();
string ask_prise();
void create()
{
	set_name("������", ({ "gu yanwu", "gu" }));
	set("long", "�����������䣬��ͤ�֣�������ɽ��ʿ��
�������ǵ������壬����֮�����˹��䣬���Ӳ��ˡ�
���ָ����ݣ���Ŀ��ڡ�\n");
	set("gender", "����");
	set("age", 55);
	set("per", 24);

	set("no_get","�����������˵̫���ˡ�\n");
        set_skill("literate", 500);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);

	set("combat_exp", 500);
	set("shen_type", 1);
	setup();

	set("inquiry", ([
		"��" : "���Ƕ�հ�����ĵ��ࡣ",
		"��հ" : "�����ǵ���һλ�󻭼ҡ�",
		"��ʿ��" : "��հ������λ�����������ǣ�����ⳡ����ʷ�����С�",
		"���" : "�����, Ҳ���ǲ����, �������������, ���ﲻ����",
		"����" : "���������˹㶫�ᶽ�����潫����",
		"��������" : "���������˹㶫�ᶽ�����潫����",
		"������" : "�����潭�����˳���ؤ�����Ǹ���Ӣ�ۡ�",
		"��ػ�" : "��ػ���̨�����ү��ƽ����֣�ɹ�����ı��������������",
		"������" : "�����������������ֵܣ��ؿ����̰��ֱ��ǻ���Ŀںš�",
		"�½���" : "������ػ��ܶ������������������Ե�����ƽ����ʶ�½��ϣ����Ӣ��Ҳ��Ȼ����",
		"���帴��" : "��ҲҪѧһѧ���������¾��ұ���, �����Ծ�����? ",
		"������" : "���������������٣��˿����������һ���ñ����񡣾�˵������������һ���������飬���м�������һ���������ĵı���Ҫ����",
		"��������" : "�ⲿ���������ղ��ڻʹ�֮�У�����˵���ư�����Ϲٽ����ʰ��и��֣�������͵�ߣ���֪�����Ǽ١�",
		"�Ϲٽ���" : (: ask_jiannan :),
		"ѧλ" : (:ask_degree:),
		"�ƾ�" : (:ask_degree:),
		"ѧ��" : (:ask_prise:),
	]) );
	set("chat_chance", 2);
	set("chat_msg", ({
		"����������ʵ��������ϸ�Ѵ��ң����ºγ������ˣ� ���Ǿ����� \n",
		"�����������˽�ɽ�������ĵҡ��ұ�����������͵����䣬ʵ���˱������ߡ�\n",
		"�������������һ��������²�����Ҵ󺺺�ɽ����֮ͽ�㱯�ߣ�����������׳��\n",
		"�������������֮������������Դ����������Ҳ���ܶ�������ȥ����������\n",
	}));
	carry_object(ARMOR_D("changshan"))->wear();
	carry_object(ARMOR_D("ruanxue"))->wear();
}

void init()
{
	add_action("do_yes","yes");
	add_action("do_no","no");
	::init();
}

string ask_jiannan()
{
	object me = this_object();
	object ob = this_player();

	if (present("zitie", ob)) return "����������Ҳ����Ѿ���������ô����ô���ʣ�\n";
	command("say ��λ�Ϲٰ�������һλ����֮ʿ�����ư��������κ��������٣�������
��֮�£������������ƴ����ڽ�������Ѱ�ѿ����뱱����ؤ���ͥ�����ˡ�ֻ�Ǻ�����
Ȼ�����伣����֪�����ˡ��������ҵ��������飬�����ҵ��Ϲٰ������У�\n");
	command("look " + ob->query("id"));
	command("say ����" + RANK_D->query_respect(ob) + "Ҳ���ұ����ˣ�����������һ�������͸��㣬ϣ����
�ܲ���������²�����Һ�ɽ��־��");
	new("/d/tiezhang/obj/zitie")->move(ob);
	message_vision("$N����$nһ��������\n", me, ob);
	return "";
}

string ask_prise()
{
	int money, level;
	int rate;
	/*
	��ҵ�literate�ȼ�����80ʱ��ѧϰ���ã�GOLD������Ϊԭ����50%��
	��ҵ�literate�ȼ�����80ʱ��ѧϰ���ã�GOLD���ָ��������㹫ʽ��
	��ҵ�literate�ȼ�����250ʱ��ѧϰ���ã�GOLD������Ϊԭ����150%��
	*/

	money = 50;
	level = this_player()->query_skill("literate", 1);

	rate=1;
	if(level > 80) rate=2;
	if(level > 250) rate=3;
        if(level > 300) rate=10;
        if(level > 400) rate=30;
        if(level > 450) rate=50;
	
	if (level > 29) money = 100*rate/2;
	if (level > 59) money = 200*rate/2;
	if (level > 89) money = 500*rate/2;
	if (level > 119) money = 1000*rate/2;
	if (level > 149) money = 2000*rate/2;

	return "�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "���뱸����Ǯ��";
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 50, level = ob->query_skill("literate", 1);

	if (level >= ob->query("int")*10){
		message_vision(CYN"\n$N����$n������һ�������������������ƣ����޷��ٽ��޸������ѧ���ˡ���\n"NOR, this_object(), ob);
		message_vision(CYN"$N�ֵ��˵�ͷ����"+ask_degree()+"��\n\n"NOR, this_object());
		return 0;
	}

	if (level > 29) money = 100;
	if (level > 59) money = 200;
	if (level > 89) money = 500;
	if (level > 119) money = 1000;
	if (level > 149) money = 2000;
	if (level > 250) money = 3000;
	if (level > 300) money = 10000;
	if (level > 320) money = 15000;
	if (level > 400) money = 30000;
	if (level > 450) money = 50000;

	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			ob->delete_temp("mark/literate");
			return notify_fail("������ѧϰһ������Ҫ�ķ�����"+MONEY_D->money_str(money)+"�������ϴ�����Ǯ�����ˡ�\n");
	}
	ob->set_temp("mark/literate", 1);
	return 1;
}

void kill_ob(object ob)
{
	if(!is_killing(ob->query("id")))
		command("chat* !!!");
	ob->start_busy(2);
	::kill_ob(ob);
}

int accept_object(object who, object ob)
{
	object me = this_object();


	if (!who || environment(who) != environment()) return 0;
	if (!objectp(ob) ) return 0;
	if (!present(ob, who)) return notify_fail("��û�����������");

	if (userp(ob)){
		command("fear "+(string)who->query("id"));
		command("say ������ˣ���ô�������������");
		return 0;
	}

	if (ob->query("id") == "tu juan") {
		command("ah " + who->query("id"));
		command("say �����벻��������Ȼ�ܼ���" + ob->query("name") + "�漣��\n");
		message_vision("$N����$n��ϸ�������š�\n", me, ob);
		who->set_temp("gu_gold", 150);
		remove_call_out("destroying");
		call_out("destroying", 1, ob);
		remove_call_out("ask");
		call_out("ask", 4, me, ob, who);
		return 1;
	}
	else if (ob->query("id") == "xiang shi") {
		command("ah");
		command("say ��������ʯ�����Ǵ�����㵽�ģ�\n");
		message_vision("$N����$n��ϸ�������š�\n", me, ob);
		who->set_temp("gu_gold", 100);
		remove_call_out("ask");
		call_out("ask", 4, me, ob, who);
		return 1;
	}
	else if (ob->query("id") == "kuaixueshiqing tie") {
		command("fly");
		command("say ��ѩʱ����������֮���漣����\n");
		message_vision("$N����$n��ϸ�������š�\n", me, ob);
		who->set_temp("gu_gold", 400);
		remove_call_out("ask");
		call_out("ask", 2, me, ob, who);
		return 1;
	}
	else if (ob->id("xi shan xing lv tu")) {
		command("jump " + who->query("id"));
		command("say �����Ϫɽ����ͼ���������þ��ˣ���\n");
		message_vision("$N����$n��ϸ�������š�\n", me, ob);
		message_vision("$N�����˰��죬̾������ϧ��ϧ�������޼�֮�����Ϸ��Ѿ������ˡ�\n", me);
	}
	else if (ob->id("ou xie pu")) {
		command("nod " + who->query("id"));
		command("say �Ϸ�Ҳ��ͨ������������һ�źܸ�������ף������ȥ��ʶ�����ˡ�\n");
	}
	else if (ob->id("guang ling san")) {
		command("nod " + who->query("id"));
		command("say �Ϸ�Ҳ��ͨ���ɣ������Ȿ���׸���Ī�⣬�㻹��ȥ��ʶ�����˰ɡ�\n");
	}
	return 0;
}

void ask(object ob, object obj, object me)
{
	if(!me || environment(me) != environment()){
		command("say �ף����أ�");
		destruct(obj);
		return;
	}
	command("hmm "+me->query("id"));
	message_vision(HIY"$N˵�������¼���ϲ����" + obj->query("name") + HIY"����֪��λ" + RANK_D->query_respect(me) + "��(yes)����(no)��ʹ��أ�\n"NOR, ob, me);
	me->set_temp("gu_answer", 1);
	destruct(obj);
}

int do_yes()
{
	object me = this_player();

	if (!me->query_temp("gu_answer")) return 0;
	message_vision(CYN"$N��æ��$nһ�Ϲ��������������Ȼϲ�����Ǿ͵����͸�����������ɡ�\n"NOR,me, this_object());
	me->set_temp("gu_yes", 1);
	me->delete_temp("gu_answer");
	remove_call_out("answer");
	call_out("answer", 3, me);
	return 1;
}

int do_no()
{
	object me = this_player();

	if (!me->query_temp("gu_answer")) return 0;
	message_vision(CYN"$N������ɫ������������\n"NOR, me);
	me->delete_temp("gu_answer");
	remove_call_out("answer");
	call_out("answer", 4, me);
	return 1;
}

int answer(object me)
{
	int amount;
	object n_money, ob = this_object();

	if (!me->query_temp("gu_yes")) {
		command("pat "+me->query("id"));
		command("say ��������֪��Ҳ�᲻�á������ɣ��͵��������㣬���ٸ�˫����Ǯ��");
		message_vision("˵��$N����$n��˵������$n�����ƽ𣬾��ý�������ȥ�ˡ�\n", ob, me);
		n_money = new("/clone/money/gold");
		n_money->move(me);
		amount = me->query_temp("gu_gold");
		n_money->set_amount(amount);
		me->delete_temp("gu_gold");
	}
	else {
		command("haha");
		command("say �ã����ҾͶ�л���ˣ�");
		me->delete_temp("gu_yes", 1);
		me->delete_temp("gu_gold");
		return 1;
	}
}

void die()
{
	object killer;

	if (objectp(killer = query_temp("last_damage_from")) ){
		killer->add("shen", -5000);
		killer->add_condition("killer", 30);
		command("chat "+killer->name()+"��թ�ն񣬾�Ȼ�����ҳ���Ͷ����͢...");
	}
	::die();
}


string ask_degree()
{
	object me = this_player();

	string newtitle;
	int level;

	level = me->query_skill("literate",1);
	if (!level || level < 1 )
		newtitle = "��ä";
	else if (level < 10)
		newtitle = "ѧͯ";
	else if (level < 20)
		newtitle = "ͯ��";
	else if (level < 30)
		newtitle = "����";
	else if (level < 40)
		newtitle = "���";
	else if (level < 50)
		newtitle = "����";
	else if (level < 60)
		newtitle = "��Ԫ";
	else if (level < 70)
		newtitle = "��ʿ";
	else if (level < 80)
		newtitle = "��Ԫ";
	else if (level < 100)
		newtitle = "��ʿ";
	else if (level < 120)
		newtitle = "����ʿ";
	else if (level < 130)
		newtitle = "����";
	else if (level < 140)
		newtitle = "̽��";
	else if (level < 150)
		newtitle = "����";
	else if (level < 160)
		newtitle = "״Ԫ";
	else if (level < 170)
		newtitle = "����";
	else if (level < 180)
		newtitle = "ѧʿ";
	else if (level < 200)
		newtitle = "�ڸ��ѧʿ";
	else if (level < 230)
		newtitle = "�ڸ��׸�";
	else if (level < 250)
		newtitle = "��̳����";
	else if (level < 270)
		newtitle = "��ѧ����ʦ";
   else if (level < 300)
            newtitle = "��ʥ";
   else if (level < 400)
            newtitle = "��ʥ";
    else newtitle = "���侪���꣬ʫ��������";

	me->set_temp("title", newtitle);

        return "ƾ���µ�ѧʶ�����Ϸ򿴣�����"+newtitle+"֮�š�";
}
