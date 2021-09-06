// Npc: /kungfu/class/shaolin/qing-fa.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
	set_name("�巨����", ({
		"qingfa biqiu",
		"qingfa",
		"biqiu",
	}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ������û���������ȫ���ƺ��̺�\n"
		"�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("inquiry",([
		"���"	: (: ask_for_join :),
		"����"	: (: ask_for_join :),
	]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("yijin-jing", 30);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("luohan-quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 40, "����");

	setup();

	 carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("family/family_name")!="������")
		return RANK_D->query_respect(me) + "�����ڿ���Ц�ɡ�\n";
	if (me->query("class")=="bonze"
	|| me->query("class")=="huanxi")
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";

	if( (string)me->query("gender") != "����" )
		return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ��ɽ�����ܽ䡣\n";

	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();

	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N˫�ֺ�ʮ�����������ع���������\n"
		"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n",
		me, this_object() );
	name = me->query("name");
	new_name = "��" + name[<2..<1];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);
	if (me->query("family/family_name") == "������")
		me->set("title", "�����ɵ�"+chinese_number(me->query("family/generation"))+"������");

	return 1;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	ob_fam = ob->query("family");
	if( (string)ob->query("gender") != "����" ) {
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}
	if(ob_fam && ob_fam["family_name"] == "������" &&  ob_fam["generation"] <= my_fam["generation"]) {
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}
	
	if (ob->query("class")!="bonze")
		command ("say �����ӷ�ƶɮ�����������׼ҵ����ˡ�");
	command("say �����ӷ����գ����գ�");
	command("recruit " + ob->query("id"));
	if (ob->query("class")!="bonze") {
		ob->set("title", "�����׼ҵ���");
		command("party "+ob->query("name")+"���ռ������֣�����λʦ�ֶ��ָ�㡣");
	}
}
