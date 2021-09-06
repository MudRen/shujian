// Npc: wuming-laoseng

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "wuming.h"

void create()
{
	set_name("������ɮ", ({	"wuming laoseng", "wuming", "laoseng",}));
	set("long",
		"����һλ�����۵Ŀ���ɮ�ˣ���Ĳ��ߡ�\n"
		"���������Ѯ���⣬ϡϡ����ļ���������Ȼȫ�ס�\n"
	);

	set("nickname", "������ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("no_bark",1);
	set("no_quest", 1);

	set("age", 70);
	set("shen", 32000);
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 12000);
	set("max_jing", 10000);
	set("eff_jingli", 9000);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 150);
	set("combat_exp", 6400000);

	set_skill("force", 400);
	set_skill("yijin-jing", 400);
	set_skill("dodge", 400);
	set_skill("shaolin-shenfa", 400);
	set_skill("fumoquan-zhen", 200);
        set_skill("claw", 400);
        set_skill("sanhua-zhang", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("club", 400);
	set_skill("blade", 400);
	set_skill("ranmu-daofa", 400);
	set_skill("finger", 400);
	set_skill("strike", 400);
	set_skill("buddhism", 200);
	set_skill("riyue-bian", 400);
	set_skill("whip", 400);
	set_skill("yizhi-chan", 400);
	set_skill("literate", 250);
	set_skill("jingang-quan", 400);
	set_skill("hand", 400);
	set_skill("leg", 400);
	set_skill("ruying-suixingtui", 400);
	set_skill("banruo-zhang", 400);
	set_skill("qianye-shou", 400);
	set_skill("longzhua-gong", 400);
	set_skill("weituo-chu", 400);
	set_skill("zui-gun", 400);
	set_skill("club", 400);
	set_skill("nianhua-zhi",400);
	set_skill("xiuluo-dao",400);

	map_skill("blade","ranmu-daofa");
	map_skill("club","weituo-chu");
	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("cuff","jingang-quan");
	map_skill("leg","ruying-suixingtui");
	map_skill("hand","qianye-shou");
	map_skill("claw","longzhua-gong");
	map_skill("whip","riyue-bian");
	map_skill("strike","banruo-zhang");
	prepare_skill("finger", "yizhi-chan");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "jingang" :),
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.wofo" :),
	}));
	create_family("������", 34, "����");
	set("inquiry", ([
		"��": (: ask_fofa :),
		"������ҵ": (: ask_reset_skill :),
		"Τ����": (: ask_wtc :),
		"ɢ��": (: ask_sangong :),
		"����":"��ɮ����ʩ�������ྴ��Ψ��Ӣ���ܱ�ɫ����ʩ����֮������",
		"����ʮ����":"����ʮ���ƣ���Ȼ���µ�һ��",
	]));

	setup();

	set_temp("apply/damage", 80);
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 80);
	set_temp("apply/armor", 90);
	UPDATE_D->get_cloth(this_object());
}

void kill_ob(object me)
{
	command("yun jingang");
	::kill_ob(me);
}

void attempt_apprentice(object ob)
{
	string new_name;
		if (!ob->query_temp("laoseng_pass",)){
		command("say �Բ����������ڲ���ͽ��");
		return;
	}
	command("recruit " + ob->query("id"));
	new_name=ob->query("name");
	new_name[0..1] = "��";
	ob->set("name", new_name);
	command("say �ӽ��Ժ���ķ�������" + new_name + "�����������������ַ𷨰ɣ�\n");
	ob->set("title",HIY "������������ɮ������ɮ" NOR);
}

int accept_object(object who, object ob)
{
	mapping my_fam  = who->query("family");
	if ((string)ob->query("id") != "fanwen jing"){
		command(":)");
		return 0;
	}

	if (!(my_fam) || my_fam["family_name"] !="������"
	 || my_fam["generation"] != 36 || who->query_skill("yijin-jing",1) <180
	 || who->query_skill("buddhism",1) <160
	 || who->query_skill("literate",1) <150
	 || !who->query_temp("sl_bookget")) {
		command(":)");
		command("say "+RANK_D->query_respect(who)+"��������Ѿ����͸������֣����Ĵ����ɽ���л����\n");
		command("say �ռ��ǻã��ü��ǿա�\n");
		who->delete_temp("sl_bookget");
		call_out("destroying", 1, ob);
		return 1;
	}
	command("say "+RANK_D->query_respect(who)+"��������Ѿ����һأ���ȴ������Ը�����գ����ա�\n");
	command("look "+(string)who->query("id"));
	command("say "+RANK_D->query_respect(who)+"��Ը������Ϊʦ��\n");
	who->delete_temp("sl_bookget");
	who->set_temp("laoseng_pass",1);
	call_out("destroying", 1, ob);
	return 1;
}

void destroying(object obj)
{
        destruct(obj);
        return;
}
