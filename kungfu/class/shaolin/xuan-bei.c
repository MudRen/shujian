// Npc: /kungfu/class/shaolin/xuan-bei.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������ʦ", ({
		"xuanbei dashi",
		"xuanbei",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ���������ߣ�\n"
		"��������񣬶��Ÿ��ʣ�˫ĿտȻ����\n"
	);

set("no_get",1);
	set("nickname", "��ĦԺ����");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1800);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 150);
	set_skill("yijin-jing", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
	set_skill("hand", 150);
	set_skill("claw", 150);
	set_skill("blade", 150);
	set_skill("sword", 150);
	set_skill("parry", 150);
	set_skill("qianye-shou", 150);
	set_skill("longzhua-gong", 150);
	set_skill("cibei-dao", 150);
	set_skill("damo-jian", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 150);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("blade", "cibei-dao");
	map_skill("sword", "damo-jian");
	map_skill("parry", "cibei-dao");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");

	create_family("������", 36, "����");

	set("inquiry", ([
		"������": (:ask_me:)
	]));

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void du1(object ob)
{
	object du;

	say("�����ǰһ����һ����С����Ӱ���˽�����\n");
du=new("/kungfu/class/shaolin/du-nan2");
	du->move(environment());
	EMOTE_D->do_emote(du, "buddhi", query("id"));
	command("buddhi " + du->query("id"));
}
 
void charse_du(object ob)
{
	new("/d/shaolin/npc/xiao-bei")->move(environment());
	say("Сɳ�����˽�����\nСɳ�ֶ���������ʦ˵�������ѳ���������Ѷ���Ͼ͵���\n");
	call_out("du1", 20, ob);
}

string ask_me()
{
	mapping skill;
	string *skl;
	object ob = this_player(), tmp;
	int i;

	if (present("du nan", environment())) {
		command("? " + ob->query("id"));
		return "���ѳ��ϲ�����������";
	}
	if (ob->query_temp("pending/waitdu"))
		return "��ʦ�����ĵȺ�Ƭ�̡�";

	if (ob->query("family/family_name") != "������") {
		command("sneer " + ob->query("id"));
		return "��֪����";
	}

    if (ob->query("pass_xin"))
        return "�㲻���Ѿ�ͨ���������ϵĿ�������";
	if (ob->query("passdu"))
		return "�㲻���Ѿ�ͨ���˶��Ѵ�ʦ�Ŀ�������\n";

	if (ob->query("family/generation") != 37) {
		return "�������ڽ�շ�ħȦ������ޡ�";
	}
	skill = ob->query_skills();
    if (!skill) return RANK_D->query_respect(ob) + "���书��ǿ���⣬������ǿ�Լ���";
	skl = keys(skill);
	i = sizeof(skl);
    if (i < 8) return RANK_D->query_respect(ob) + "���书��ǿ���⣬������ǿ�Լ���";
	while (i--) {
		if (skill[skl[i]] < 120 && skl[i] != "medicine")
			return RANK_D->query_respect(ob) + "�Ƿ���" + CHINESE_D->chinese(skl[i]) + "�϶���Щ����";
	}
	if ((tmp = present("xiao shami", environment()))) {
		ob->set_temp("pending/waitdu", 1);
		command("nod");
		say("������ʦ�������Сɳ�ֶ��Ｘ�䡣\nСɳ�ֿ첽���˳�ȥ��\n");
		destruct(tmp);
		call_out("charse_du", 20, ob);
		return "�ðɣ�" + RANK_D->query_respect(ob) + "�����Ժ�һ�ᡣ";
	}
	return "�����ӷ�Сɳ�ֲ��ڣ������ʱ�������ɡ�";
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}
/*
	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}
*/
	if ( ob_fam["generation"] <= (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
		return;
	}

	return;
}
