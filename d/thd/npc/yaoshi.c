// yaoshi.c
// Modified by Numa 19990917
// Modified by Darken@SJ for taohua quest
// pk river wenmang
// Modified by mxzhao 2004/05/12 for shen restrict to exp/10

#include <ansi.h>
#include "nadir.c"
#include "combat.h"

inherit NPC;
inherit F_MASTER;

int ask_leave();
int ask_jia();
int ask_marry();
int ask_xiao();
int ask_test1();
int ask_test2();
int ask_test3();
int ask_yuxiao();
int ask_dongxiao();
int ask_shenjian();
int ask_kuangfeng();
int ask_lingxi();
int ask_huayu();
int ask_nvxu();
int ask_jiuyin();
int ask_bagua();
int ask_teaching();
int ask_quest();
int perexert();
void cont_per(object me, object weapon);
int ask_reward();
#include "nvxu.h"
#include "perform.h"

void create()
{
	set_name("��ҩʦ", ({ "huang yaoshi", "huang", "yaoshi" }) );
	set("nickname", "�һ�����");
	set("long",
		"�������һ����ĵ���������������������ɫ�Ķ�а��ҩʦ��\n"
		"����һ����ɫ���ۣ�������б����һֻ���\n"
		"��������񳣬������ˬ���������٣�տȻ����\n");
	set("gender", "����" );
	set("rank_info/rude", "����а");
	set("age", 50);
	set("attitude", "peaceful");
	set("apprentice",1);
	set("str", 30);
	set("int", 50);
	set("con", 35);
	set("dex", 40);
	set("per", 30);
	set("unique",1);
	
	set("max_qi", 12000);
	set("max_jing", 7500);
	set("eff_jingli", 8500);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 150);
	set("combat_exp", 4900000);
	set("score", 20000);
	
	set_temp("apply/damage", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/parry", 50);
	set_temp("apply/defence", 100);
	set_temp("apply/armor", 90);
	
	set("thd/perform", 7);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perexert :),
	}));
	
	set_skill("force", 380);
	set_skill("bihai-chaosheng", 380);
	set_skill("dodge", 370);
	set_skill("suibo-zhuliu", 370);
	set_skill("parry", 390);
	set_skill("strike", 360);
	set_skill("luoying-zhang", 360);
	set_skill("leg", 360);
	set_skill("xuanfeng-tui", 360);
	set_skill("hand", 370);
	set_skill("lanhua-shou", 370);
	set_skill("finger", 360);
	set_skill("taoism", 200);
	set_skill("throwing", 390);
	set_skill("qimen-baguazhen", 200);
	set_skill("tanzhi-shentong", 390);
	set_skill("sword", 360);
	set_skill("yuxiao-jian", 360);
	set_skill("literate", 300);
	set_skill("qimen-bagua", 200);
	
	map_skill("force", "bihai-chaosheng");
	map_skill("dodge", "suibo-zhuliu");
	map_skill("strike", "luoying-zhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("throwing", "tanzhi-shentong");
	map_skill("leg", "xuanfeng-tui");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-tui");
	
	set("rank_info/respect", "�һ�����");
	set("shen_type",0);
	create_family("�һ���", 1, "����");
	set("class", "fighter");
	
	set("inquiry", ([
		"name": "�ѵ�����¾�û��֪���Ҷ�а��ҩʦ����������",
		"rumors": "��˵ȫ����ǰ�ţ�����ڵ������ܲ�ͨ���ߣ�",
		"here": "��������һ����ˡ������Ǹ�С������������������ģ�������������ܲ�����ȫ�ˡ�",
		"��а": "�Ƕ��ǽ������ǰ�����������µļһ������Ĵºš�",
		"����": "��ǰ��������ŷ������ֻ����󡣬���˻�ˣ�������⣬ûʲô�湦��",
		"ŷ����": "��ֻ����󡣬���˻�ˣ�������⣬ûʲô�湦��",
		"�ϵ�": "��ǰ���ϵ��Ǵ������ү�����ˣ����ڳ��������У��Ľ�һ������",
		"һ��": "��ǰ�Ǵ������ү�����ˣ����ڳ��������У��Ľ�һ������",
		"������": "��ǰ�Ǵ������ү�����ڳ��������У��Ľ�һ������",
		"��ؤ": "��ǰ�ı�ؤ�Ǻ��߹��Ǹ��Ͻл������ֽ�ʲôʮ���Ƶ���ʹ�á�",
		"���߹�": "�Ǹ��Ͻл���ؤ����������ֽ�ʲôʮ���Ƶ���ʹ�á�",
		"����ͨ": "��ǰ������ͨ��ȫ��̵ĳ���ʿ��������Ҫ�����Ϸ�һʱʧ�֣����ֵ�һ�ĳƺ�Ҳ���ᱻ�����ߡ�",
		"������": "��ȫ��̵ĳ���ʿ��Ҫ�����Ϸ�һʱʧ�֣����ֵ�һ�ĳƺ�Ҳ���ᱻ�����ߡ�",
		"�ܲ�ͨ": (: ask_jiuyin :),
		"����ͯ": "�����ɵ�ϣ�����ƭ�˶���֪������������������ٺٺ�....",
		"����": "������С�Ͷ���������������������Ƥ���ԣ���Ҳû�취�ˡ�",
		"�ض�": "������С�Ͷ���������������������Ƥ���ԣ���Ҳû�취�ˡ�",
		"����": "���������ɵŮ���ˡ�",
		"Ů��": (: ask_nvxu :),
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"�һ���": "��������һ����ˡ������Ǹ�С������������������ģ�������������ܲ�����ȫ�ˡ�",
		"�˷�": "���ҵ��ĵ��ӣ�����ס�ڹ���ׯ��",
		"�һ�Ӱ�����" : (: ask_shenjian :),
		"�̺�����������" : (: ask_yuxiao :),
		"���" : (: ask_kuangfeng :),
		"������" : (: ask_kuangfeng :),
		"��Ϭָ" : (: ask_lingxi :),
		"��Ϭһָ" : (: ask_lingxi :),
		"���컨��" : (: ask_huayu :),
		"½�˷�": "���ҵ��ĵ��ӣ�����ס�ڹ���ׯ��",
		"��ҩʦ": "�����Ϸ��ҡ���ô������������������",
		"�Ź�": "�Ź�֮�壬������ꡣ����Ϊ�磬����Ϊ�㣻�������ߣ�������һ������м䡣",
		"����": "Ǭ�����������Σ������飬�������������ۣ��޸��룻����ȱ�����¶ϡ�",
		"����": "����ˮ��ˮ��ľ��ľ���𣬻������������𡣽��ľ��ľ����������ˮ��ˮ�˻𣬻�˽�",
		"�׾�": "��һ�����������ʮ���Ե����飬һ�����ѵÿ�����",
		"����": "��һ�����������ʮ���Ե����飬һ�����ѵÿ�����",
		"�����澭": "����������ʲô����",
		"����": "�Ϸ��ҶԺ��о����Ʋ��ߣ�",
		"�뿪": (: ask_leave :),
		"�뵺": (: ask_leave :),
		"��ȥ": (: ask_leave :),
		"leave": (: ask_leave :),
		"���": (: ask_marry :),
		"��һ��": (: ask_test1 :),
		"test1": (: ask_test1 :),
		"�ڶ���": (: ask_test2 :),
		"��⬼�": (: ask_jia :),
		"test2": (: ask_test2 :),
		"������": (: ask_test3 :),
		"test3": (: ask_test3 :),
		// add for jiugong tu
		"���Ű���": (: ask_bagua :),
		// add for taohua quest
		"÷����": (: ask_quest :),
		"������": (: ask_quest :),
		"����" : (: ask_dongxiao :),
		"������" : (: ask_xiao :),
		"����": (: ask_reward :),
		"�̻�": (: ask_teaching :),
        ]) );
	
	setup();
	
	if(clonep())
	{
		object ob = unew(ARMOR_D("rwj"));
		if(!ob) ob=new("/d/thd/obj/grn-cloth");
		ob->move(this_object());
		ob->wear();
	}
	
	if (clonep(this_object()))
	{
		object ob;
		if (ob = carry_object(BINGQI_D("sword/dongxiao")))
			ob->wield();
	}
	
}

/*void init()
{
	object ob = this_player();
	
	add_action("do_answer","answer");
	add_action("do_answer","huida");
	add_action("do_kill","kill");
	::init();
	
	if ( file_name(environment(this_object())) != this_object()->query("startroom")) return;
	
	if (ob->query("family/family_name") == "�һ���") 
	{
		if ((int)ob->query("shen") < -ob->query("combat_exp")/10
			&& (int)ob->query("shen") < -200000) 
		{
			message_vision("��ҩʦ��$N�ȵ����������ˣ��������������������ң���\n", ob);
			message_vision("��ҩʦ��$N�ȵ����ӽ���������Ҳ�����һ����ĵ����ˣ�\n", ob);
			command("expell " + ob->query("id"));
			ob->set("title", "�һ�����ͽ");
		}
		else if ((int)ob->query("shen") > ob->query("combat_exp")/10
			&& (int)ob->query("shen") > 200000) 
		{
			message_vision("��ҩʦ��$N�ȵ������Ǵ����������˵���������α���ӡ�������ͽ�ܣ��ͱ����������\n", ob);
			message_vision("��ҩʦ��$N�ȵ����ӽ���������Ҳ�����һ����ĵ����ˣ�\n", ob);
			command("expell " + ob->query("id"));
			ob->set("title", "�һ�����ͽ");
		}
	}
}
*/
void reset()
{
	object ob, jia;
	
	if (clonep() && (ob = unew(BINGQI_D("sword/dongxiao")))) {
		ob->move(this_object());
		command("wield dongxiao");
	}
	
	if (clonep() && (jia = unew(ARMOR_D("rwj")))) {
		jia->move(this_object());
		command("wear ruanwei jia");
	}
}

int ask_jiuyin()
{
	object me;
	me = this_player();
	if (me->query_temp("jyquest") >0 ) {
		command("say ���Ǹ�������ô��������ʲô��");
		command("kick "+ me->query("id"));
		return 1;
	}
	
	command("say ��һ��о����澭���Ͼ�������Ҳ���Ͻ�������");
	command("sneer");
	command("say �ҽ������ڵ��ϣ������ܳŵ���ʱ��");
	me->set_temp("jyquest",1);
	return 1;
}

int ask_xiao()
{
	object me;
	me = this_player();
	
	if (present("biyu xiao", me)){
		command("say �㲻������ô��");
		command("crazy");
		return 1;
	}
	if (me->query("job_time/�һ���") < 200) {
		command("say ��Ϊ�һ�����ʲô�ˣ�");
		command("sneer");
		return 1;
	}
	command("say �ðɣ�����Լ�ȥ���Ұɡ�");
	message_vision(HIY"$N���ҩʦ���˸����߽���һ��С���䡣\n"NOR, me);
	me->move(__THD__"room");
	return 1;
}

int ask_dongxiao()
{
	object me, xiao;
	me = this_player();
	
	if (present("dongxiao", me)){
		command("say �㲻������ô��");
		command("crazy");
		return 1;
	}
	if (me->query("job_time/�һ���") < 400) {
		command("say ��Ϊ�һ�����ʲô�ˣ�");
		command("sneer");
		return 1;
	}
	
	xiao = present("dongxiao",this_object());
	
	if (xiao) {
		command("say �ðɣ������ȥ�ɡ�");
		xiao->move(me);
		return 1;
	}
	else {
		command("say �������ˣ��Ѿ����������ˡ�");
		return 1;
	}
	return 1;
}

int ask_jia()
{
	object me = this_player();
	object jia;
	if( me->query("combat_exp") < 1000000
		|| me->query("family/family_name") != "�һ���") {
		command("say ����ʲô������Ҳ��Ҫ�ҵ���⬼�?");
		return 1;
	}
	
	jia = present("ruanwei jia",this_object());
	
	if (jia) {
		command("say �ðɣ������ȥ�ɡ�");
		jia->move(me);
		return 1;
	}
	else {
		command("say �������ˣ��Ѿ����������ˡ�");
		return 1;
	}
	return 1;
}

int ask_teaching()
{
	object me = this_player();
	mapping fam;
	
	object ob = this_player();
	if (!(fam = ob->query("family"))
		|| fam["family_name"] != "�һ���")
		return notify_fail("�㲻�Ǳ��ɵ��ӣ�����Ϲ����ʲô��\n");
	
	if (me->query("shen") > 0) {
		command("say �ߣ���������ľ�����������֮�ˣ�");
		command("say �����������Ϊ�ұ����裿");
		message_vision(HIY"$N����ҩʦһ�ٽ�ѵ�����°�������֮������\n"NOR, me);
		me->add_busy(10);
		me->set("shen", 1000);
		return 1;
	}
	if (me->query("shen") < 0) {
		command("say ���˲������������������ˣ�");
		command("say �����Щ����һ��ô��");
		message_vision(HIR"$N����ҩʦһ�ٽ�ѵ������û�˶��\n"NOR, me);
		me->add_busy(10);
		me->set("shen",-1000);
		return 1;
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	string old_name, new_name;
	
	if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
		command("say �㲻�в�Ů����ʲô�����������");
		return;
	}
	if (ob->query("shen") <= -200000) {
		command("say ����ƽ�����������ˣ����������޶�����аħ���������һ���ߣ�");
		return;
	}
	if (ob->query("shen") >= 200000) {
		command("say ����ƽ�����������ˣ������������������Ĺ�������֮ͽ������һ���ߣ�");
		return;
	}
	if (ob->query_int() < 28) {
		command("say �����⸱ģ����������ɵŮ���������������Ϊʦ��");
		return;
	}
	if (!ob->query_skill("literate")) {
		command("say �������äҲ����ѧ������ȥѧ���Ļ��ɡ�");
		return;
	}
	if (ob->query("class") == "bonze") {
		if (ob->query("family/family_name") == "������")
			command("say �������������书�����֣����������С���ɲ������㡣");
		else
			command("say �Ҷ�а��������У�������ͷ����������������á�����һ�𶼲��ա�");
		return;
	}
	if (ob->query("family/family_name") == "�һ���") {
		if (ob->query("family/generation") < 2 )
		{
			command("say ���һ����书�����" + RANK_D->query_respect(ob) + "�����Ȱѻ�������ʵ�ɣ�");
			return;
		}
		if ((int)ob->query_skill("bihai-chaosheng", 1) < 130)
		{
			command("say ���һ���һ���书��̥�ڵ��̣��������ڹ��ķ���");
			command("say " + RANK_D->query_respect(ob) +
				"�Ƿ�Ӧ���ڱ̺��������϶��µ㹦��");
			return;
		}
		if (ob->query_int() < 32)
		{
			command("say �����⸱ģ����������ɵŮ���������������Ϊʦ��");
			return;
		}
/*
                if ( (int)ob->query("job_time/�һ���") <= 100 )
		{
			command("angry " + ob->query("id"));
			command("say ��Ϊ�һ�������ʲô�����ˣ��������ѧ����");
			return;
}
*/
		command("chat ����������������");
		command("chat �벻���Ҷ�а�������֮�󣬻��ܵô��������ʣ����ǿ�ϲ�ɺء�");
		command("recruit " + ob->query("id"));
		old_name = ob->query("name");
		new_name = old_name[0..3] + "��";
		ob->set("name", new_name);
		ob->set("title",HIC "�һ�������ǰ����" NOR);
		say(old_name + "�����ҩʦ���£�λ�ж������ӡ��硱�ֱ�������Ϊ" + new_name + "��\n");
		return;
	}
	if (ob->query("expell/family_name") == "�һ���"
		&& ob->query("expell/master_name") =="��ҩʦ") {
		command("recruit " + ob->query("id"));
		ob->set("title",HIC "�һ�������ǰ����" NOR);
		old_name = ob->query("name");
		new_name = old_name[0..3] + "��";
		ob->set("name", new_name);
		say(old_name + "�����ҩʦ���£�λ�ж������ӡ��硱�ֱ�������Ϊ" + new_name + "��\n");
		return;
	}
}

int recognize_apprentice(object ob)
{
	object nvxu;
	
	if (ob->query("gender") == "����") {
		if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
			nvxu = load_object("/clone/npc/huang-son-in-law");
		if (nvxu->query("winner") == ob->query("id") && nvxu->query("death_count") == ob->query("death_count"))
			return 1;
	}
	if (ob->query("thd/quest1")>3)
		return 1;
		/*      if (ob->query("age") * 12 + ob->query("month") - ob->query("thd/marry_age") < 12)
	return 1;*/
	return notify_fail("������Ѩ���˻Ƶ����Ҵ���ѧ���������ա�\n");
}

int prevent_learn(object ob, string skill)

{
	if (recognize_apprentice(ob)) {
		if (skill == "lanhua-shou")
			return 0;
		if (ob->is_apprentice_of(this_object()))
			return 0;
		notify_fail("��ֻ����Ƶ������������Ѩ�����żҴ�����\n");
		return 1;
	}
	return 0;
}

void kill_ob(object me)
{
	if (!is_killing(me->query("id")))
		command("chat* crazy " + me->query("id"));
	::kill_ob(me);
}

void unconcious()
{
	command("chat* ��̾һ�������ݺὭ����ʮ�أ�����������а������ɥ����û�뵽Ҳ�н��죡");
	::unconcious();
}


int accept_object(object who, object ob)
{
	if (ob->id("art"))
	{
		message_vision(HIY"��ҩʦ����"+ob->query("name")+HIY"��ϸ�����š�\n"NOR, who);
		command("ah");
		command("say ������" + ob->query("name") + "��");
		command("thank " +who->query("id"));
		command("consider");
		command("say �Ҿ͸���һЩ�ر��ɡ�");
		who->set("potential",who->query("max_pot"));
		message_vision(HIY"��ҩʦ��$Nָ����һ����$N�����Լ��з��Ӳ���Ǳ�ܣ�\n"NOR, who);
		return 1;
	}
	if ((ob->id("skin"))&&(who->query_temp("thd/onquest")>7))
	{
		message_vision(HIY"��ҩʦ������Ƥϸϸ�鿴��\n"NOR, who);
		command("ah");
		command("say ������̵����Ǿ����澭��");
		command("haha");
		command("say �ߣ�����ʿ�ǣ���һ������������澭�Ͼ���ķ���");
		command("say ���ܰ����һ��⾭�飬����Ҳ���㲻��");
		command("say �ҵ�������Ѩ����Ȼ�������ԣ����������ɡ�");
		who->set("thd/finish",1);
		who->delete_temp("thd/onquest");
		destruct(ob);
		return 1;
	}
	
	if (ob->id("qulingfeng tiepai"))
	{
		command("sigh");
		say("��ҩʦ�������ƣ���ˮ������£�������˵��������磬�Ҹ���̫�࣡��\n");
		if (!present("zhangfa tujie", who)) {
			if (query_temp("zhangfa_give") >= 3) {
				tell_object(who, "��ҩʦ����˵��������ϧ�ҵġ���Ӣ����ͼ�⡷�������˱��ˣ���Ȼ��������" + RANK_D->query_respect(who) + "���Ȿ�Ʒ��������֮Ů��Ҳ����ȴ��һ����Ը����\n");
			}
			else {
				tell_object(who, "��ҩʦ����˵��������˵��������һ��Ů�������ෳ" + RANK_D->query_respect(who) + "���Ȿ�Ʒ���������Ҳ����ȴ��һ����Ը��\n");
				tell_object(who, "��ҩʦ����һ������Ӣ����ͼ�⡷��\n");
				new_ob("../obj/zhangfa.c")->move(who);
				add_temp("zhangfa_give", 1);
			}
		}
		else
		{
			tell_object(who, "��ҩʦ����˵���������������ϴ����ҵġ���Ӣ����ͼ�⡷�����ෳ" + RANK_D->query_respect(who) + "���Ȿ�Ʒ��������֮Ů��Ҳ����ȴ��һ����Ը����\n");
		}
		return 1;
	}
	
	// ������
	if (ob->id("recommend letter"))
	{
		if (who->query("thd/receive")==1)
		{
			command("angry " + who->query("id"));
			command("say �Ҽ��ѽ�����˷�ѧ����" + RANK_D->query_respect(ob) + "������������ʲô��");
			return 0;
		}
		if (ob->query("owner") == who->query("id"))
			message_vision("��ҩʦ���˵�ͷ����$N˵�������ǳ˷���ױ��ţ���������������ơ���\n", who);
		else
		{
			message_vision("��ҩʦ˫üһ������$N�ȵ������˷��Ƽ��Ĳ����㣡����θ�����ƭ�Ϸ򣿿������\n", who);
			return 0;
		}
		command("nod" + who->query("id"));
		command("say �ţ���Ȼ�˷翴�����㣬��͸�����ѧ����ɡ�");
		who->set("thd/receive", 1);
		return 1;
	}
}

int ask_leave()
{
	object nvxu;
	object ob = this_player();
	
	if (ob->query("family/master_name") == "��ҩʦ") {
		message_vision("$N���Ż�ҩʦ����˵��������Ҫ�뵺�ˣ�ʦ����ʲô�̻壿��\n", ob);
		message_vision("��ҩʦ��$N�������������ȥ��ԭ��Ҫһ·С�ģ�ĪҪ�����Ҷ�а����������\n", ob);
		message_vision("$N���˵�ͷ�����������ӽ������ģ���\n", ob);
		say("��ҩʦһ���֣�����һ������������" + ob->name() + "��½�ء�\n");
		write("�����ʦ�����˻��֣�����С����������������½�ء�\n");
		write("��������˳�磬������ƣ������ڱ㵽���ˡ�\n");
		tell_room(__THD__"haibin",
			"����Զ����Ȼ�ֳ�һ��С�������ŷ��ƣ���һ��͵����ˣ�" + ob->name() + "�Ӵ���һ�������˳�����\n", ({}));
		ob->move(__THD__"haibin");
		return 1;
	}
	if (ob->query("family/family_name") == "�һ���") {
		if (ob->query("gender") == "����")
			message_vision("$N���Ż�ҩʦ����˵����ͽ��Ҫ�뵺�ˣ�̫ʦ����ʲô�̻壿��\n", ob);
		else
			message_vision("$N���Ż�ҩʦ����˵����ͽ��ŮҪ�뵺�ˣ�̫ʦ����ʲô�̻壿��\n", ob);
		message_vision("��ҩʦ��$N�������������ȥ��ԭ��Ҫһ·С�ģ�ĪҪ�����Ҷ�а����������\n", ob);
		message_vision("$N���˵�ͷ�����������ӽ������ģ���\n", ob);
		say("��ҩʦһ���֣�����һ������������" + ob->name() + "��½�ء�\n");
		write("�����̫ʦ�����˻��֣�����С����������������½�ء�\n");
		write("��������˳�磬������ƣ������ڱ㵽���ˡ�\n");
		tell_room(__THD__"haibin",
			"����Զ����Ȼ�ֳ�һ��С�������ŷ��ƣ���һ��͵����ˣ�" + ob->name() + "�Ӵ���һ�������˳�����\n", ({}));
		ob->move(__THD__"haibin");
		return 1;
	}
	if (ob->query("gender") == "����") {
		if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
			nvxu = load_object("/clone/npc/huang-son-in-law");
		if (nvxu->query("winner") == ob->query("id")
			&& nvxu->query("death_count") == ob->query("death_count")) {
			/*      if (ob->query("age") * 12 + ob->query("month") - ob->query("thd/marry_age") < 12) {*/
			message_vision("$N���Ż�ҩʦ����˵��������Ҫ�뵺�ˣ�������ʲô�̻壿��\n", ob);
			message_vision("��ҩʦ��$N�������������ȥ��ԭ��Ҫһ·С�ģ�ĪҪ�����Ҷ�а����������\n", ob);
			message_vision("$N���˵�ͷ�������������������ģ���\n", ob);
			say("��ҩʦһ���֣�����һ������������" + ob->name() + "��½�ء�\n");
			write("����Ż�ҩʦ���˻��֣�����С����������������½�ء�\n");
			write("��������˳�磬������ƣ������ڱ㵽���ˡ�\n");
			tell_room(__THD__"haibin",
				"����Զ����Ȼ�ֳ�һ��С�������ŷ��ƣ���һ��͵����ˣ�" + ob->name() + "�Ӵ���һ�������˳�����\n", ({}));
			ob->move(__THD__"haibin");
			return 1;
		}
	}
	if (__NIU__"boat.c"->query_temp("busy"))
		command("say С���Ѿ��ͱ�Ŀ����ˣ�" + RANK_D->query_respect(ob) + "�ٵ�һ����ɡ�\n");
	else {
		say("��ҩʦһ���֣�����һ��������������λ" + RANK_D->query_respect(ob) + "��½�ء�\n");
		ob->set_temp("thd_target", "bay");
		ob->move(__THD__"haibin");
	}
	return 1;
}

int do_kill(string arg)
{
	object ob, nvxu;
	object me = this_player();
	
	if (!arg) return 0;
	ob = present(arg, environment(me));
	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;
	
	if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
		nvxu = load_object("/clone/npc/huang-son-in-law");
	if (nvxu->query("winner") == ob->query("id") && nvxu->query("death_count") == ob->query("death_count")) {
		if (me->query("family/family_name") == "�һ���") {
			message_vision("��ҩʦ��$N�ȵ���Сū�ţ�Ҫ�췴�����ҵ�Ů������ɱ����\n", me);
		}
		else {
			message_vision("��ҩʦ��$N�ȵ����󵨿�ͽ���������һ�����Ұ����\n", me);
			message_vision("��ҩʦ��$N˵����Ů���˺���������ʰ���" + RANK_D->query_rude(me) + "��\n", ob);
			kill_ob(me);
		}
		me->set("vendetta/�һ���", 1);
		return 1;
	}
	if (ob->query("family/family_name") == "�һ���") {
		if (me->query("family/family_name") == "�һ���") {
			message_vision("��ҩʦ��$N�ȵ���Сū�ţ�Ҫ�췴�����Լ���ͬ�Ŷ�ɱ����\n", me);
		}
		else {
			message_vision("��ҩʦ��$N�ȵ����󵨿�ͽ���������һ�����Ұ����\n", me);
			message_vision("��ҩʦ��$N˵���������ÿ�����������ʰ���" + RANK_D->query_rude(me) + "��\n", ob);
			kill_ob(me);
		}
		me->set("vendetta/�һ���", 1);
		return 1;
	}
	return 0;
}


int ask_bagua()
{
	object ob = this_player();
	mapping fam;
	
	if (!(fam = ob->query("family"))
		|| fam["family_name"] != "�һ���")
		return notify_fail(RANK_D->query_respect(ob) + "���Ǳ��ɵ��ӣ�����Ϲ����ʲô��\n");
	
	command( "say �Ҽǵ���һ�����������ʮ���Ե����飬�����ܶ�" + RANK_D->query_respect(ob) + "����������\n");
	command( "say �Ұ��������鷿�ˣ����Լ�ȥ���ҿ��ɡ�\n");
	ob->set_temp("thd/tupu",1);
	return 1;
}

int ask_quest()
{
	object ob = this_player();
	
	if (ob->query_temp("thd/onquest")>0)
		return notify_fail("���Ǹ�������ô��");
	
	if (ob->query("thd/finish")>0)
		return notify_fail("�Ϸ�ö�л����ǡ�");
	
	command( "heng");
	command( "say ��������ͽ����Ȼ͵���ҵľ����澭���ˡ�");
	command( "say �������ҵ����ǣ�˳�ְ��ҽ����ǳ�ȥ�˰ɡ�");
	command( "consider");
	command( "say �����书Ҳ�㲻������Ů��Ҫ�㶫������ɡ�");
	ob->set_temp("thd/onquest",1);
	return 1;
}

int ask_reward()
{
	object me = this_player();
	mapping fam;
	if (!(fam = me->query("family"))
		|| fam["family_name"] != "�һ���")
		return notify_fail("�㲻�Ǳ��ɵ��ӣ�����Ϲ����ʲô��\n");
	
	if ((me->query("thd/finish")==1)&&(me->query("thd/quest1")<4))
	{
		message_vision(HIW"��ҩʦһ�����漴������Ц������\n"NOR, me);
		command("say �ã��ã������װģ������α���ӣ�������ֱˬ��������⡣\n");
		message_vision(HIY"��ҩʦ��������ٵв��֮��������������ˣ�\n"NOR, me);
		me->set("thd/quest1",4);
		return 1;
	}
	return 1;
}
int perexert()
{
	object weapon, me;
	me = this_object();
	weapon = me->query_temp("weapon");
	if(me->is_busy()) return 0;
	call_out("cont_per", 2, me, weapon);
	return 1;
}

void cont_per(object me, object weapon)
{
	int i;
	if (!me->is_fighting()) return;
	if(!me->query_temp("thd/is_fast")) {
		command("exert maze");
		command("perform dodge.wuzhuan");
		return;
	} else {
		switch(random(5)) {
        case 0:
			if (!weapon) command("wield xiao");
			else command("perform qimen");
			break;
        case 1:
			if (!weapon) command("wield xiao");
			else command("perform feiying");
			break;
        case 2:
			if (weapon) weapon->unwield();
			me->prepare_skill("finger");
			me->prepare_skill("hand");
			me->prepare_skill("strike", "luoying-zhang");
			me->prepare_skill("leg","xuanfeng-tui");
			i = me->query_temp("thd/is_fast");
			me->delete_temp("thd/is_fast");
			command("perform kuangfeng");
			me->set_temp("thd/is_fast",i);
			if (weapon) weapon->wield();
			break;
        case 3:
			if (weapon) weapon->unwield();
			me->prepare_skill("leg");
			me->prepare_skill("strike");
			me->prepare_skill("finger","tanzhi-shentong");
			command("perfor huayu");
			break;
        case 4:
			if (weapon) weapon->unwield();
			me->prepare_skill("finger");
			me->prepare_skill("hand");
			me->prepare_skill("leg", "xuanfeng-tui");
			me->prepare_skill("strike","luoying-zhang");
			command("perform pikong");
			if (weapon) weapon->wield();
			break;
	}}
	call_out("cont_per", 2, me, weapon);
}
