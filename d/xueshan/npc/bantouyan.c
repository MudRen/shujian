// bantouyan.c ��ͷ��
// by iceland
inherit NPC;

void create()
{
	set_name("��ͷ��", ({ "bantou yan","bantouyan","yan"}) );
	set("long","һֻ���Ĵ�Ѱ��ʳ��Ĵ��㣬ͷ���ͱ����ϵ���ë���кÿ��İߵ㡣\n");
	set("race", "Ұ��");
	set("age", 3);

	set("eff_jing", 200);
	set("max_jing",200);
	set("max_qi", 500);

	set("str", 20);
	set("dex", 25);
	set("con", 15);
	set("int", 20);

	set("limbs", ({ "ͷ��", "����", "����","���"}) );
	set("verbs", ({ "poke"}) );
	set_temp("apply/attack", 20);
	set_temp("apply/dodge", 25);

	set("combat_exp", 5000);
        set("chat_chance", 3);
	set("chat_msg", ({
(: this_object(), "random_move" :),
"��ͷ�㰺���ӣ������˼��³�򣬾�������������ܡ�\n",
"��ͷ����ɵĿ����㣬��Զ���߿��˼�����\n",
}) );
        setup();
	set("race", "����");
}

void die()
{
	object ob;
	message_vision("$N�������Ĵ��˼��³��һͷ���ڵ������ˡ�\n", this_object());
    ob = new(ARMOR_D("yanling"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
