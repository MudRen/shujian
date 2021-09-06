// /kungfu/class/emei/jing-feng.c
// Make by jackie 98.2

inherit NPC;
string ask_sword();
string ask_sword1();
string ask_drug();
string ask_yaodai(); 
void create()
{
	set_name("����ʦ̫", ({
		"jingfeng shitai",
		"jingfeng",
		"shitai",
	}));
	set("long",
		"�����ڻ��������е�ʦ̫��ƽʱ�ڴ���䷢�Ŷ����ɵ�����������ҩƷ��\n"
	);


	set("gender", "Ů��");
	set("attitude", "friendly");
         set("unique", 1);
	set("class", "bonze");

	set("age", 45);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 35);
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 550000);
	set("score", 100);

	set_skill("dacheng-fofa", 120);
	set_skill("linji-zhuang", 120);
	set_skill("huifeng-jian", 120);
	set_skill("sword", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("force", 120);
	set_skill("anying-fuxiang", 120);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
       	set("inquiry", 
                ([
			"����" : (: ask_sword :),
                        "Ƥ����" : (: ask_yaodai :),
                        "��" : (: ask_sword1 :),
                        "���������" : (: ask_drug :)
]));
       	set("drug_count", 5);
       	set("sword_count",5);
        set("sword1_count" ,4);
	set("yaodai_count", 4);
	create_family("������", 4, "����");

	setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}

string ask_sword()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (  present("changjian", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����г��������ô����Ҫ�ˣ� ����̰�����У�";

	if (query("sword_count") < 1) return "�Բ��𣬳����Ѿ�������Ҫ���ˡ�";

	ob = new("/d/emei/obj/changjian");
	ob->move(this_player());

	add("sword_count", -1);

	message_vision("$N�õ�һ��������\n",this_player());
	return "��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ��ɱ�����顣";

}

string ask_sword1()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (  present("ruan jian", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ������������ô����Ҫ�ˣ� ����̰�����У�";

	if (query("sword1_count") < 1) return "�Բ������Ѿ�������Ҫ���ˡ�";

	ob = new("/d/emei/obj/ruanjian");
	ob->move(this_player());

	add("sword1_count", -1);

	message_vision("$N�õ�һ������\n",this_player());
	return "��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ��ɱ�����顣";

}

string ask_drug()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

    if (present("tianxiang duanxugao", this_player()))
        return RANK_D->query_respect(this_player()) + 
        "������������";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("tianxiang duanxugao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (query("drug_count") < 1) return "�Բ�������������Ѿ�������";

	ob = new("/d/emei/obj/duanxu-gao");
	ob->move(this_player());

	add("drug_count", -1);

	message_vision("$N���һ����������ࡣ\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}

string ask_yaodai()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (  present("yao dai", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ�����Ƥ���������ô����Ҫ�ˣ� ����̰�����У�";

	if (query("yaodai_count") < 1) return "�Բ���Ƥ�����Ѿ�������Ҫ���ˡ�";

	ob = new("/d/emei/obj/yaodai");
	ob->move(this_player());

	add("yaodai_count", -1);

	message_vision("$N�õ�һ��Ƥ������\n",this_player());
	return "��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ�˷������ˡ�";
}
