// Npc: /kungfu/class/shaolin/xu-tong.c

inherit NPC;

void create()
{
	set_name("��ͨ", ({
		"xu tong",
		"xu",
		"tong",
	}));
	set("long",
		"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n"
	);


	set("nickname", "֪��ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 2000);
	set("score", 100);

	set_skill("force", 20);
	set_skill("yijin-jing", 20);
	set_skill("dodge", 20);
	set_skill("shaolin-shenfa", 20);
	set_skill("strike", 20);
	set_skill("banruo-zhang", 20);
	set_skill("parry", 20);
	set_skill("sword", 20);
	set_skill("damo-jian", 20);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("������", 41, "����");

	setup();

        carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

int accept_object(object who, object ob,object me)
{
        mapping fam; 
        me=this_object();

        if (!(fam = this_player()->query("family"))|| fam["family_name"] != "������"){
                command("hehe "+who->query("id"));
                command("say ����Ҷ�����ʲô��ͼ����");
        	return 0;
        }
	if(!who->query_temp("lunzhi")){
		command("say ��������������ģ���ֵ����õ����޴�ʦ������");
		return 0;
	}
	if(!userp(ob) && ob->query("name") == "��ֵ��"){
	       	command("say �ðɣ����Ȼ�л��޴�ʦ�����ƣ�����������������һ�������ɡ�");
		who->apply_condition("sl_lunzhi",random(4)+7);
		who->set_temp("lunzhied",1);
		call_out("dest", 1, ob);
		return 1;
	}
	return 1;
}

void dest(object ob)
{
	if( !ob) return;
	destruct(ob);
}
