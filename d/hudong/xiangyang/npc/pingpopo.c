
inherit NPC;

void create()
{
	set_name("ƽ����", ({"ping popo", "popo", "ping"}));
	set("long", "���������Ƿ��֣�����͹�������������߰˸�������һ�㣬ͷ�����ף�
�������⣬˵��������Ѱ�����ӻ����˼��֣���������������\n");
	set("gender", "Ů��");
	set("attitude", "friendly");
	set("age", 60);
	set("shen_type", -1);
	set("score", 400000);
	set("str", 31);
	set("int", 26);
	set("con", 30);
	set("dex", 32);
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiaji", 30);
	set("combat_exp", 600000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed", 100);
	set_skill("blade", 100);
	set_skill("parry", 180);
       	set_skill("kunlun-shenfa", 150);
       	set_skill("cuff", 100);
       	set_skill("wenjia-quan", 100);
       	set_skill("murong-daofa", 100);
       	set_skill("shenyuan-gong", 100);
       	map_skill("force", "shenyuan-gong");
       	map_skill("dodge", "kunlun-shnfa");
       	map_skill("blade", "murong-daofa");
       	map_skill("cuff", "wenjia-quan");
       	map_skill("parry", "wenjia-quan");
        prepare_skill("cuff", "wenjia-quan");

     	set("chat_chance", 20);
	set("chat_msg", ({
		"ƽ���Ż��������еĸֵ��ȵ����������ûһ�����ˣ�������ɱ��\n",
		}) );

	setup();
	add_money("gold", random(2));
	carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
