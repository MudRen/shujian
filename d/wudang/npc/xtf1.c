// xiao_louluo.c

inherit NPC;

void create()
{
        set_name("С���", ({"xiao louluo","xiao", "louluo"}) );
        set("gender", "����" );
        set("age", 18);
        set("long", "����һ����Ͳ����С��ޣ������������ᡣ\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 1500);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","aggressive");

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 10);
}
