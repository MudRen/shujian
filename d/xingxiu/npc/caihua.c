// 2004.12.28 lane add dls ����

#include <ansi.h>
inherit NPC;
int ask_gold();

void create()
{
	set_name("�ɻ���", ({ "caihua zi", "caihua", "zi" }) );
	set("gender", "����" );
	set("nickname", "������");
	set("age", 28);
	set("long", 
             "�ɻ����������ɵ�һ��ħ��������а���书�ܲ"
             "�����������޺���Χ�ĸ�Ů, ��������ء�\n");
	set("env/wimpy", 40);
	set("str", 25);
	set("dex", 30);
	set("con", 17);
	set("int", 15);
	set("per", 20);
	set("shen", -300);

	set_skill("unarmed", 60);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("zhaixingshu", 60);
	map_skill("dodge","zhaixingshu");

        set("combat_exp", 25000);

	set("max_qi", 500);
	set("max_jing", 500);

	create_family("������", 2, "����");

	set("attitude", "peaceful");
	set("inquiry", ([
		"name" : "��ү�������ر��ǡ�",
		"�ɻ�" : (: ask_gold :),
	]));

	setup();
	carry_object(ARMOR_D("pink_cloth"))->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	mapping myfam;

	if (!me) return;
	myfam = (mapping)me->query("family");
	if (myfam && myfam["family_name"] == "������"
	 && (me->query("gender")=="����"))
		command("say �������ɽ����׽�˸�С�����������һҹ����ү��ˬ���ˣ����ȥ���԰ɡ�");
	me->set_temp("marks/��",0);
}

void attempt_apprentice(object ob)
{
	command("hehe");
	command("say ����ɻ����������ģ������ܶ���");
	return;
}

int accept_object(object me, object obj)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (!myfam || myfam["family_name"] != "������") {
		command("say �ٸ����׽�����");
		return 0;
	}
	else {
		if (userp(obj)) {
			command("smile " + me->query("id"));
			me->set_temp("last_damage_from", "�޶�������");
			me->die();
			return 0;
		}
		if( obj->is_character() 
		&& ! obj->is_corpse()
		&& obj->query_temp("last_damage_from") == me 
		&& obj->query("gender") == "Ů��"
		&& obj->query("combat_exp") > me->query("combat_exp")/2
		&& me->query("shen") > -80000
		&& !obj->query("no_quest"))
			me->add("shen", -(200+random(300)));
		if (me->query("gender")=="Ů��") {
			command("kiss " + me->query("id"));
			command("say �벻��ʦ��Ҳ��������á�");
		}
		else {
			command("bow " + me->query("id"));
			command("say ��лʦ�֡�");
		}
		command("say �Բ�����С��������ϱ���֪���ĸ��쵰�����ˣ���������Խ���˯һ����");
		me->set_temp("marks/��", 1);
        }
	if (obj->query("money_id")) return 1;
	destruct(obj);
	return notify_fail("");
}

int ask_gold()
{
	object me;
	int skill, gold;
	mapping myfam;
	me = this_player();
	skill = me->query_skill("huagong-dafa", 1);
	myfam = (mapping)me->query("family");

	if( !myfam || myfam["family_name"] != "������" ) {
		command("sneer "+(string)me->query("id"));
		command("say �ٺ٣���������ţ������˷��ˣ�");
		return 1;
	}

	if( (int)me->query("xx_given") >= (int)me->query("age") ) {
		command("? "+(string)me->query("id"));
		command("say �������"+ RANK_D->query_respect(me) +"���£���֪����û�н������");
		return 1;
	}

        if( skill < 216 ) {
		command("interest");
		command("say "+ RANK_D->query_respect(me) +"��ͻ��ᣬ������������ɻ���Ҳ���������ģ�\n");
		return 1;
	}

	gold = 300000 + skill * 5000;
	if( 100 >= skill ) gold += gold/2;
	me->add("balance", gold);
	me->set("xx_given", (int)me->query("age"));
	command("say ʦ�ֹ����£��м�����Ҫ�鷳���£�");
	command("whisper "+(string)me->query("id")+" �ҽ���" + MONEY_D->money_str(gold) + "�������Ǯׯ���鷳ʦ��ȥ��ɽ����ץ��С������ðɣ�");
	return 1;
}
