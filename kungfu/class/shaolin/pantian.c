// pantiangeng.c �����

inherit NPC;

void create()
{
	set_name("�����", ({ "pan tiangeng","pan","tiangeng" }) );
	set("gender", "����" );
	set("age", 64);
	set("long", "���������òƽƽ���棬ֻ����ɫ���ƣ�΢�����ݡ���˵һ��
��ħ���������޳����ҡ�/n");
	set("attitude", "peaceful");
	set("nickname", "�������ֳ���");
	set("class", "bonze");
	set("str", 35);
	set("con", 35);
	set("int", 25);
	set("dex", 35);


	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 300);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", 1);
	set("startroom","/d/shaolin/shijie8");
	set("unique", 1);

	set("combat_exp", 1200000);

	set_skill("force", 150);
	set_skill("finger", 150);
	set_skill("sword", 160);
	set_skill("dodge", 150);
	set_skill("parry", 160);
	set_skill("shaolin-shenfa", 150);
	set_skill("literate", 150);
	set_skill("yizhi-chan", 140);
        set_skill("fumo-jian", 170);
	set_skill("yijin-jing", 150);
	set_skill("buddhism", 150);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "yizhi-chan");
        map_skill("parry", "fumo-jian");
        map_skill("sword", "fumo-jian");
        prepare_skill("finger", "yizhi-chan");

	create_family("��������", 19, "����");

	set("chat_chance", 20);
	set("chat_msg", ({
		"�����˵�������������������ַ�֧�����⹦�ĸ���ȴ�ж���֮����\n",
		"�����˵�������������ɱ����������ħȴҲ���ҷ��⡣\n",
                 (: random_move :)
	}) );

	setup();
         carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void kill_ob(object me)
{
        set("combat_exp", 1200000);
        set("max_qi", 3000);
        set("max_neili", 3000);
        set("neili", 3000);
        set("jiali", 100);
        set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "finger.wofo" :)
        }));
        ::kill_ob(me);
}
