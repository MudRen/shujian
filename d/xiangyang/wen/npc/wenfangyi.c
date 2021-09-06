// /d/city/npc/wenfangyi

inherit NPC;
 
void create()
{
	set_name("�·���", ({ "wen fangyi", "wen", "fangyi" }));
	set("title", "�¼�����");
	set("long", 
        "�������¼����ϵ��϶��·��塣\n"
        "һ����ʮ��������ߣ�һ˫�۾�͸�����⡣\n");
	set("gender", "����");
	set("age", 56);
	set("attitude", "friendly");
	set("shen", -9000);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2000);
	set("max_jing", 1800);
	set("eff_jingli", 1800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 900000);
	 

	set_skill("force", 140);
	set_skill("yijin-jing", 140);
	set_skill("dodge", 150);

	set_skill("shaolin-shenfa", 140);
	set_skill("cuff", 150);
	set_skill("wenjia-daofa", 130);
	set_skill("parry", 150);
	set_skill("blade", 120);
	set_skill("wenjia-quan", 150);
	set_skill("literate", 110);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "wenjia-quan");
	map_skill("parry", "wenjia-quan");
	map_skill("blade", "wenjia-daofa");
	prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
	carry_object(ARMOR_D("cloth"))->wear();
}
