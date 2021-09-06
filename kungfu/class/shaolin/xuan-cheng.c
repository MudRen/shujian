// Npc: /kungfu/class/shaolin/xuan-cheng.c
// Date: YZC 96/01/19

inherit NPC;
string ask_me();

void create()
{
	set_name("���δ�ʦ", ({
		"xuancheng dashi",
		"xuancheng",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ĸߴ�\n"
		"���ֹ�ϥ��˫Ŀ������գ�ȴ��ʱ���һ�ƾ��⡣\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("buddhism", 160);
	set("chat_chance",15);
        set("chat_msg",({
      "���δ�ʦ������ƶɮֻ��̰ͼ��ѧ������Ϊ���㣬ǿ�Զ�ѧ�ϳ��书������������ϡ���\n",
      "���δ�ʦ����������ǧ��������������ɮ���������ϵ�������Ϊ��һҪ�񡣡�\n",
      "���δ�ʦ������ƶɮ�����޷������书�������ղ�������Ħڭɮڮ�ɣ����޷𷨣��ɴ˿��򡣡�\n",                              
        }) );
        set("inquiry", ([
		"Ħڭɮڮ��" :    (: ask_me :),
 ]));
        set("book_count",1);
	create_family("������", 36, "����");

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present("moheseng diyu", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ������Ȿ������������Ҫ�ˣ� ��ȥ�ú��ж��ɣ�";

	if (query("book_count") < 1) return "�Բ���Ħڭɮڮ���Ѿ�����Ҫ���ˣ�";

	ob = new("/d/shaolin/npc/obj/fojing3");
	ob->move(this_player());

	add("book_count", -1);

	message_vision("���δ�ʦ�ӻ���ȡ��һ���齻����$N��\n",this_player());
	return "�ðɣ���ס��һ��Ҫ�����ж����飬��������";

}