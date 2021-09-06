// Npc: /d/shaolin/npc/seng-bing1.c
// Date: YZC 96/01/19

inherit NPC;
void create()
{
	set_name("ɮ��", ({"seng ren", "sengren", "seng"}));
	set("long", "����һλ��ĸߴ��ɮ�ˣ����۴�׳��������Բ���ƺ���һ�����ա�\n");

	set("gender", "����");

	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 25000);
	set("score", 1);

	set_skill("force", 60);
	set_skill("hunyuan-yiqi", 60);
	set_skill("dodge", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("strike", 60);
	set_skill("banruo-zhang", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("cibei-dao", 60);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "cibei-dao");
	map_skill("blade", "cibei-dao");
	prepare_skill("strike", "banruo-zhang");
	setup();

	carry_object("/d/shaolin/obj/cloth")->wear();
}
