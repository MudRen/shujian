// Update by Lklv 2001.10.18

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("�º���", ({"guhong zi", "zi", "guhong"}));
	set("long","�����Ƕ����ɵ�ǰ�������˹º��ӡ�\n"
		"����Ȼ�������ڣ�������һ�����ϣ�ֻ�ǲ��ϵ�����ʱʱ¶����������ɫ��\n"
	);
	set("gender", "����");
	set("attitude", "friendly");
	set("unique", 1);
	set("age", 75);
	set("shen", 20000);
	set("str", 32);
	set("int", 25);
	set("con", 30);
	set("dex", 28);
	set("max_qi", 5500);
	set("max_jingli", 4000);
	set("max_jing", 2500);
	set("neili", 8500);
	set("max_neili", 8500);
	set("jiali", 80);
	set("combat_exp", 2300000);

	set_skill("dacheng-fofa", 200);
        set_skill("linji-zhuang", 280);
	set_skill("jieshou-jiushi", 240);
	set_skill("huifeng-jian", 240);
	set_skill("sixiang-zhang", 240);
	set_skill("yanxing-daofa", 240);
	set_skill("hand", 240);
	set_skill("literate", 240);
	set_skill("strike", 240);
	set_skill("linji-jianzhen", 200);
	set_skill("sword", 240);
	set_skill("blade", 240);
	set_skill("parry", 240);
	set_skill("dodge", 240);
        set_skill("force", 240);
	set_skill("anying-fuxiang", 240);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-daofa");
	map_skill("parry", "yanxing-daofa");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "sixiang-zhang");
	map_skill("hand", "jieshou-jiushi");

	prepare_skill("hand", "jieshou-jiushi");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "blade.huanying" :),
		(: perform_action, "hand.foguang" :)
	}));
	create_family("������", 2, "ǰ����");
	setup();
	set_temp("apply/dodge", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/armor", 40);
	carry_object(BINGQI_D("blade"))->wield();
	UPDATE_D->get_cloth(this_object());
}

void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	mapping myfam;
//	mapping lrn;
	int shen;
//	int lvl;
	myfam = (mapping)me->query("family");
	if (!myfam) return;
	shen = me->query("shen");
	if (shen < -200000 && myfam["master_name"] == "�º���"){
		command("say ���������������а�����ٲ�˼�ڸģ���Ҫ���㿪��ʦ�ţ�");
	}
/*
        if ( me->query("class") != "bonze" && myfam["family_name"] == "������"){
		lvl = (int)me->query_skill("linji-zhuang", 1);
		lrn = me->query_learned();
		if( !mapp(lrn) ) return;
		if( (int)lvl/10 == 14 && (int)me->query("emsujia")<1 ) {
			command("say �ټ�ׯ��Ҫ�и���ķ��ศ��������ͻ�ǰ��������");
			command("say �����׼ҵ������ײ�������������ŵ�������Ǳ�����");
			command("say ����ڹ���Ϊ��˵�ѵ���һ����Σ����������Ҫ����ɽ����һ�¡�");
			tell_object(me, "������ʦ���Ļ�,�������\n");
		}
		if( (int)lvl/10 == 16 && (int)me->query("emsujia")<2 ) {
			command("say �ټ�ׯ��Ҫ�и���ķ��ศ��������ͻ�ǰ��������");
			command("say �����׼ҵ������ײ�������������ŵ�������Ǳ�����");
			command("say ����ڹ���Ϊ��˵�ѵ���һ����Σ����������Ҫ����ɽ����һ�¡�");
			tell_object(me, "������ʦ���Ļ�,�������\n");
		}
		if( (int)lvl/10 == 17 && (int)me->query("emsujia")<3 ) {
			command("say ͽ������Ĺ����Ѿ�������Ϸ��ˡ�Ϊʦ��һ׮��Ը���Ǿ�����Ϊʦ������֮���ܹ��ٿ�һ��(show)���콣��");
		}
	}
*/
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
	if ((int)ob->query_skill("linji-zhuang",1) < 75) {
		command("say " + RANK_D->query_respect(ob) + "������ټ�ʮ��ׯ��Ϊ���������ܰ���Ϊʦ��");
		return;
	}
        if (!ob->query("luohan_winner") ) {
		command("say " + RANK_D->query_respect(ob) + "�������ѧ��Ϊ���������ܰ���Ϊʦ��");
		return;
        }
	if (ob->query("class") == "bonze" ) {
		command("say " + RANK_D->query_respect(ob) + "����ֻ���׼ҵ��ӡ�");
		return;
        }
	command("chat* haha");
	command("say �Ϸ���֮�꣬�յõ�һ���²����ˣ����ǿ�ϲ�ɺ� !");
	command("recruit " + ob->query("id"));
	return;
}

int accept_object(object who, object ob)
{
	mapping myfam = (mapping)who->query("family");
	if(myfam["family_name"] != "������"){
		command("say " + RANK_D->query_respect(who) + "�뱾��������������֪�˻��Ӻ�̸��");
		return 0;
	}
	if (ob->id("yitian jian") && !this_object()->query("jian"))  {
		command("say �⡣������ǵ��걻ħ�̶��˶��ߵ����콣����");
		command("say �Ϸ�����֮�����ٿ�����ѽ���������Ҳ�Ŀ�ˡ�");
		command("say �����������ܹ�����������⡣");
		message_vision(HBGRN"�º��Ӷ�$N�̵���һ����$N�о���������һ��������\n"NOR,who);
		who->set_temp("emei/jianjue",1);
        	who->add("shen",5000);
		call_out("dest", 1, ob);
        	set("jian",1);
		call_out("delete", 900, "jian");
        	return 1;
	}
        return 0;
}

void dest(object ob)
{
	if (ob) destruct(ob);
}
