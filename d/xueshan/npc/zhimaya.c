// zhimaya.c ֧��Ѽ
// by iceland
inherit NPC;

void create()
{
	set_name("֧��Ѽ", ({ "zhima ya","zhimaya","ya"}) );
	set("long","һֻ�����͵�Ѽ�ӣ��ܲ����ۣ�������ѩɽ���ز������ǿ������ġ�\n");
	set("race", "Ұ��");
	set("age", 3);

	set("max_jing",200);
	set("max_qi", 500);
	set("max_neili", 1);

	set("str", 20);
	set("dex", 15);
	set("con", 15);
	set("int", 20);

	set("limbs", ({ "ͷ��", "����", "����","���"}) );
	set("verbs", ({ "poke"}) );
	set_temp("apply/attack", 20);
	set_temp("apply/dodge", 15);
	set("unique", 1);

	set("combat_exp", 2000);
        set("chat_chance", 3);
	set("chat_msg", ({
(: this_object(), "random_move" :),
"֧��Ѽ�¸µĽ���������Ų�����ȱ�׾�����˼����������ڵ����������¡�\n",
"֧��Ѽ������Ľż��£�����������Ȥ�������������߿��ˡ�\n"
}) );
        setup();
	set("race", "����");
}

void die()
{
	object ob;
	message_vision("$N�Ĳ�������Ĵ��ڵ��ϣ�һ�������ˡ�\n", this_object());
    ob = new(FOOD_D("yasui"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
