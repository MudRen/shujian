// liefuyu.c �Ѹ���
// by iceland
inherit NPC;

void create()
{
	set_name("�Ѹ���", ({ "liefu yu","liefuyu","yu"}) );
	set("long",
"һ����͸����С�㣬����ģģ�����Ŀ��������ڵĹ�����ֻ�����ں����ˮ
���˵�����������������ҿ����������塣
LONG
        ");
	set("race", "Ұ��");
	set("age", 5);

	set("eff_jing", 200);
	set("max_jing",200);
	set("max_qi", 300);

	set("str", 10);
	set("dex", 45);
	set("con", 15);
	set("int", 20);
	set("unique", 2);

	set("limbs", ({ "ͷ��", "����", "β��"}) );
	set("verbs", ({ "bite"}) );
	set_temp("apply/attack", 20);
	set_temp("apply/dodge", 45);

	set("combat_exp", 3000);
        set("chat_chance", 2);
        set("chat_msg", ({
"�Ѹ����ι�������Ŀ��˿��㣬�������ˡ�\n",
"�Ѹ����ι��������������㣬����������ġ�\n",
}) );
        setup();
}
void die()
{
	object ob;
	message_vision("$N������Ť���˼��£���Ƥ���������ˡ�\n", this_object());
	ob = new(FOOD_D("yuyou"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
