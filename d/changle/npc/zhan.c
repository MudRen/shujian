// zhan.c չ��
// By River 2003.2.26
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("չ��",({"zhan fei", "zhan", "fei"}));
	set("title", "���ְﱪ��������");
	set("long", "�����ǳ��ְﱪ��������չ�ɡ�\n");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen", 1000);
	set("str", 26);
	set("int", 29);
	set("con", 27);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 2200);
	set("eff_jingli", 2500);
	set("jiali", 80);
	set("combat_exp", 1000000); 
	set("unique", 1);

	set_skill("dodge",150);
	set_skill("force", 150);
	set_skill("sword",150);
	set_skill("literate",150);
	set_skill("cuff",150);
	set_skill("kunlun-shenfa", 150);
	set_skill("shenzhao-jing", 150);
	set_skill("liehuo-jian",150);
	set_skill("taizu-quan", 150);
	set_skill("parry", 150);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "liehuo-jian");
	map_skill("sword", "liehuo-jian");
	map_skill("cuff", "taizu-quan");
	prepare_skill("cuff","taizu-quan");

	setup();
	carry_object(BINGQI_D("sword"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}
